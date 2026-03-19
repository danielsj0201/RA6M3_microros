#include "new_thread0.h"
#include "hal_data.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rcl/error_handling.h>
#include <rcutils/allocator.h>
#include <rmw_microros/rmw_microros.h>
#include <std_msgs/msg/int32.h>

#include "microros_allocators.h"
#include "microros_transports.h"

#define AGENT_IP   "192.168.0.50"
#define AGENT_PORT 5000

volatile bool g_uart_tx_done = false;
BaseType_t xNetworkUp = pdFALSE;
static void uart_print(const char * msg);
/* FreeRTOS+TCP hook: DHCP/hostname */
const char * pcApplicationHostnameHook(void)
{
    return "ra6m3-microros";
}

/* FreeRTOS+TCP hook: network up/down event */
void vApplicationIPNetworkEventHook(eIPCallbackEvent_t eNetworkEvent)
{
    if (eNetworkEvent == eNetworkUp)
    {
        xNetworkUp = pdTRUE;
        //uart_print("Network is UP\r\n");
    }
    else
    {
        xNetworkUp = pdFALSE;
        //uart_print("Network is DOWN\r\n");
    }
}

/* Some FreeRTOS ports/examples do not provide pvPortCalloc */
void * pvPortCalloc(size_t num, size_t size)
{
    size_t total = num * size;
    void * ptr = pvPortMalloc(total);
    if (ptr != NULL)
    {
        memset(ptr, 0, total);
    }
    return ptr;
}

/* local htons helper to avoid FreeRTOS_htons link issue */
static uint16_t local_htons(uint16_t x)
{
    return (uint16_t)(((x & 0x00ffU) << 8) | ((x & 0xff00U) >> 8));
}

/* UART callback */
void user_uart_callback(uart_callback_args_t * p_args)
{
    if ((NULL != p_args) && (p_args->event == UART_EVENT_TX_COMPLETE))
    {
        g_uart_tx_done = true;
    }
}

/* UART print */
static void uart_print(const char * msg)
{
    if (NULL == msg)
    {
        return;
    }

    g_uart_tx_done = false;
    R_SCI_UART_Write(&g_uart0_ctrl, (uint8_t *)msg, (uint32_t)strlen(msg));

    while (!g_uart_tx_done)
    {
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

static void error_loop(const char * msg)
{
    uart_print(msg);
    while (1)
    {
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
/*
void HardFault_Handler(void)
{
    __asm volatile("BKPT #0");
    while (1) {}
}

void MemManage_Handler(void)
{
    __asm volatile("BKPT #0");
    while (1) {}
}

void BusFault_Handler(void)
{
    __asm volatile("BKPT #0");
    while (1) {}
}

void UsageFault_Handler(void)
{
    __asm volatile("BKPT #0");
    while (1) {}
}
*/
void new_thread0_entry(void * pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);

    fsp_err_t fsp_err = R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);

    if (fsp_err != FSP_SUCCESS)
    {
        while (1){}
    }
    /* SCB->SHCSR |= SCB_SHCSR_USGFAULTENA_Msk
               |  SCB_SHCSR_BUSFAULTENA_Msk
               |  SCB_SHCSR_MEMFAULTENA_Msk; */
    //uart_print("micro-ROS thread start\r\n");
    uint8_t ucMACAddress[6] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55}; // 보드 고정 MAC
    uint8_t ucIPAddress[4] = {192, 168, 0, 10};
    uint8_t ucNetMask[4] = {255, 255, 255, 0};
    uint8_t ucGatewayAddress[4] = {192, 168, 0, 1};
    uint8_t ucDNSServerAddress[4] = {8, 8, 8, 8};

    FreeRTOS_IPInit(ucIPAddress, ucNetMask, ucGatewayAddress, ucDNSServerAddress, ucMACAddress);

    // 네트워크가 올라올 때까지 무한 대기 (이게 없어서 핑이 안 갔던 겁니다!)
    //uart_print("Waiting for Network Link...\r\n");
    while(xNetworkUp != pdTRUE){
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    //uart_print("Network is Ready!\r\n");

    /* micro-ROS allocator */
    rcutils_allocator_t allocator = rcutils_get_zero_initialized_allocator();
    allocator.allocate = microros_allocate;
    allocator.deallocate = microros_deallocate;
    allocator.reallocate = microros_reallocate;
    allocator.zero_allocate = microros_zero_allocate;

    if (!rcutils_set_default_allocator(&allocator))
    {
        error_loop("Allocator set failed\r\n");
    }

    /* Agent address for custom UDP transport */
    struct freertos_sockaddr remote_addr;
    memset(&remote_addr, 0, sizeof(remote_addr));
    remote_addr.sin_family = FREERTOS_AF_INET;
    remote_addr.sin_port   = local_htons((uint16_t)AGENT_PORT);
    remote_addr.sin_addr   = FreeRTOS_inet_addr(AGENT_IP);

    rmw_uros_set_custom_transport(
        false,
        (void *)&remote_addr,
        renesas_e2_transport_open,
        renesas_e2_transport_close,
        renesas_e2_transport_write,
        renesas_e2_transport_read);

    //uart_print("Transport configured\r\n");

    while (rmw_uros_ping_agent(1000, 1) != RMW_RET_OK)
    {
        //uart_print("Waiting for agent...\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }

    //uart_print("Agent reachable\r\n");

    rcl_allocator_t rcl_allocator = rcl_get_default_allocator();
    rclc_support_t support;
    rcl_ret_t rc = rclc_support_init(&support, 0, NULL, &rcl_allocator);
    if (rc != RCL_RET_OK)
    {
        error_loop("rclc_support_init failed\r\n");
    }

    rcl_node_t node = rcl_get_zero_initialized_node();
    rc = rclc_node_init_default(&node, "ra6m3_node", "", &support);
    if (rc != RCL_RET_OK)
    {
        error_loop("node init failed\r\n");
    }

    rcl_publisher_t publisher = rcl_get_zero_initialized_publisher();
    rc = rclc_publisher_init_default(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "ra6m3_counter");

    if (rc != RCL_RET_OK)
    {
        error_loop("publisher init failed\r\n");
    }

    //uart_print("Publisher created\r\n");

    std_msgs__msg__Int32 msg;
    msg.data = 0;

    char log_buf[64];

    while (1)
    {
        rc = rcl_publish(&publisher, &msg, NULL);

        if (rc == RCL_RET_OK)
        {
            //snprintf(log_buf, sizeof(log_buf), "publish: %ld\r\n", (long)msg.data);
            //uart_print(log_buf);
            msg.data++;
        }
        else
        {
            //uart_print("publish failed\r\n");
        }

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}
