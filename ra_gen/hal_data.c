/* generated HAL source file - do not edit */
#include "hal_data.h"
agt_instance_ctrl_t g_timer0_ctrl;
const agt_extended_cfg_t g_timer0_extend =
{ .count_source = AGT_CLOCK_PCLKB,
  .agto = AGT_PIN_CFG_DISABLED,
  .agtoa = AGT_PIN_CFG_DISABLED,
  .agtob = AGT_PIN_CFG_DISABLED,
  .measurement_mode = AGT_MEASURE_DISABLED,
  .agtio_filter = AGT_AGTIO_FILTER_NONE,
  .enable_pin = AGT_ENABLE_PIN_NOT_USED,
  .trigger_edge = AGT_TRIGGER_EDGE_RISING, };
const timer_cfg_t g_timer0_cfg =
{ .mode = TIMER_MODE_PERIODIC,
/* Actual period: 0.0010922666666666667 seconds. Actual duty: 50%. */.period_counts = (uint32_t) 0x10000,
  .duty_cycle_counts = 0x8000, .source_div = (timer_source_div_t) 0, .channel = 0, .p_callback = micro_ros_timer_cb,
  /** If NULL then do not add & */
#if defined(NULL)
    .p_context           = NULL,
#else
  .p_context = &NULL,
#endif
  .p_extend = &g_timer0_extend,
  .cycle_end_ipl = (12),
#if defined(VECTOR_NUMBER_AGT0_INT)
    .cycle_end_irq       = VECTOR_NUMBER_AGT0_INT,
#else
  .cycle_end_irq = FSP_INVALID_VECTOR,
#endif
        };
/* Instance structure to use this module. */
const timer_instance_t g_timer0 =
{ .p_ctrl = &g_timer0_ctrl, .p_cfg = &g_timer0_cfg, .p_api = &g_timer_on_agt };
sci_uart_instance_ctrl_t g_uart0_ctrl;

baud_setting_t g_uart0_baud_setting =
{
/* Baud rate calculated with 0.160% error. */.abcse = 0,
  .abcs = 0, .bgdm = 1, .cks = 0, .brr = 64, .mddr = (uint8_t) 256, .brme = false };

/** UART extended configuration for UARTonSCI HAL driver */
const sci_uart_extended_cfg_t g_uart0_cfg_extend =
{ .clock = SCI_UART_CLOCK_INT, .rx_edge_start = SCI_UART_START_BIT_FALLING_EDGE, .noise_cancel =
          SCI_UART_NOISE_CANCELLATION_DISABLE,
  .rx_fifo_trigger = SCI_UART_RX_FIFO_TRIGGER_MAX, .p_baud_setting = &g_uart0_baud_setting, .flow_control =
          SCI_UART_FLOW_CONTROL_RTS,
#if 0xFF != 0xFF
                .flow_control_pin       = BSP_IO_PORT_FF_PIN_0xFF,
                #else
  .flow_control_pin = (bsp_io_port_pin_t) UINT16_MAX,
#endif
        };

/** UART interface configuration */
const uart_cfg_t g_uart0_cfg =
{ .channel = 0, .data_bits = UART_DATA_BITS_8, .parity = UART_PARITY_OFF, .stop_bits = UART_STOP_BITS_1, .p_callback =
          user_uart_callback,
  .p_context = NULL, .p_extend = &g_uart0_cfg_extend,
#define RA_NOT_DEFINED (1)
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_tx = NULL,
#else
                .p_transfer_tx       = &RA_NOT_DEFINED,
#endif
#if (RA_NOT_DEFINED == RA_NOT_DEFINED)
  .p_transfer_rx = NULL,
#else
                .p_transfer_rx       = &RA_NOT_DEFINED,
#endif
#undef RA_NOT_DEFINED
  .rxi_ipl = (12),
  .txi_ipl = (12), .tei_ipl = (12), .eri_ipl = (12),
#if defined(VECTOR_NUMBER_SCI0_RXI)
                .rxi_irq             = VECTOR_NUMBER_SCI0_RXI,
#else
  .rxi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TXI)
                .txi_irq             = VECTOR_NUMBER_SCI0_TXI,
#else
  .txi_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_TEI)
                .tei_irq             = VECTOR_NUMBER_SCI0_TEI,
#else
  .tei_irq = FSP_INVALID_VECTOR,
#endif
#if defined(VECTOR_NUMBER_SCI0_ERI)
                .eri_irq             = VECTOR_NUMBER_SCI0_ERI,
#else
  .eri_irq = FSP_INVALID_VECTOR,
#endif
        };

/* Instance structure to use this module. */
const uart_instance_t g_uart0 =
{ .p_ctrl = &g_uart0_ctrl, .p_cfg = &g_uart0_cfg, .p_api = &g_uart_on_sci };
BSP_ALIGN_VARIABLE(16) edmac_desc_t g_edmac0_rx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;
BSP_ALIGN_VARIABLE(16) edmac_desc_t g_edmac0_tx_descriptors[4] ETHER_BUFFER_PLACE_IN_SECTION;

edmac_instance_ctrl_t g_edmac0_ctrl;
const edmac_cfg_t g_edmac0_cfg =
{ .channel = PTPC_EDMAC_CHANNEL, .padding = EDMAC_PADDING_DISABLE, .padding_offset = 0, .num_tx_desc = 4, .num_rx_desc =
          4,
  .p_tx_descriptors = g_edmac0_tx_descriptors, .p_rx_descriptors = g_edmac0_rx_descriptors, .p_callback =
          r_ptp_edmac_callback,
  .edmac_ipl = (12), .edmac_irq = VECTOR_NUMBER_EPTPC_PINT, .p_context = &g_ptp0, .p_extend = NULL };
edmac_instance_t g_edmac0 =
{ .p_ctrl = &g_edmac0_ctrl, .p_cfg = &g_edmac0_cfg };
/* Array for storing transmit packets. */
uint8_t g_ptp0_transmit_buffers[4][1536];
uint8_t *g_ptp0_transmit_buffer_array[4] =
{ (uint8_t*) &g_ptp0_transmit_buffers[0][0],
  (uint8_t*) &g_ptp0_transmit_buffers[1][0],
  (uint8_t*) &g_ptp0_transmit_buffers[2][0],
  (uint8_t*) &g_ptp0_transmit_buffers[3][0], };

/* Array for storing received packets. */
BSP_ALIGN_VARIABLE(32) uint8_t g_ptp0_receive_buffers[4][1536];uint8_t *g_ptp0_receive_buffer_array[4] =
{ (uint8_t*) &g_ptp0_receive_buffers[0][0],
  (uint8_t*) &g_ptp0_receive_buffers[1][0],
  (uint8_t*) &g_ptp0_receive_buffers[2][0],
  (uint8_t*) &g_ptp0_receive_buffers[3][0], };

/* If IPv4 packets are not used then provide destination MAC addresses. */
#if !0
static uint8_t g_ptp0_primary_mac_addr[] =
{ 0x01, 0x1B, 0x19, 0x00, 0x00, 0x00 };
static uint8_t g_ptp0_pdelay_mac_addr[] =
{ 0x01, 0x80, 0xC2, 0x00, 0x00, 0x0E };
#endif

/* Any multicast addresses that match the multicast filter address are transferred to the ETHERC EDMAC. */
static uint8_t g_ptp0_multicast_filter_addr[] =
{ 0x01, 0x1B, 0x19, 0x00, 0x00, 0x00 };

ptp_instance_ctrl_t g_ptp0_ctrl;

const ptp_cfg_t g_ptp0_cfg =
        { .synfp =
        { .ethernet_phy_interface = PTP_ETHERNET_PHY_INTERFACE_RMII,
          .frame_format = PTP_FRAME_FORMAT_ETHERII,
          .frame_filter = PTP_FRAME_FILTER_MODE_EXT_PROMISCUOUS_MODE,
          .clock_domain = 0,
          .clock_domain_filter = PTP_ENABLE,
          .announce_interval = PTP_MESSAGE_INTERVAL_1,
          .sync_interval = PTP_MESSAGE_INTERVAL_1,
          .delay_req_interval = PTP_MESSAGE_INTERVAL_1,
          .message_timeout = 4000,
          .clock_properties =
          { .priority1 = 128, .cclass = 248, .accuracy = 0xFE, .variance = 0xFFFF, .priority2 = 128 },
          .timesource = 160,
          .p_multicast_addr_filter = g_ptp0_multicast_filter_addr,
          /* If IPv4 packets are used. */
#if 0
        .ipv4 = {
            .primary_ip_addr = ((224U << 24U) | (0U << 16U) | (1U << 8U) | (129U << 0U)),
            .pdelay_ip_addr = ((224U << 24U) | (0U << 16U) | (0U << 8U) | (107U << 0U)),
            .event_tos = 0,
            .general_tos = 0,
            .primary_ttl = 1,
            .pdelay_ttl = 1,
            .event_udp_port = 319,
            .general_udp_port = 320,
        }
#else
          .ether =
          { .p_primary_mac_addr = g_ptp0_primary_mac_addr, .p_pdelay_mac_addr = g_ptp0_pdelay_mac_addr }
#endif
                  },
          .stca =
          { .clock_freq = PTP_STCA_CLOCK_FREQ_20MHZ,
            .clock_sel = PTP_STCA_CLOCK_SEL_PCLKA_DIV_6,
            .clock_correction_mode = PTP_CLOCK_CORRECTION_MODE1,
            .gradient_worst10_interval = 32,
            .sync_threshold =
            { .threshold = 1000000, .count = 5, },
            .sync_loss_threshold =
            { .threshold = 10000000, .count = 5, } },

          .mint_irq = VECTOR_NUMBER_EPTPC_MINT,
          .ipls_irq = VECTOR_NUMBER_EPTPC_IPLS, .mint_ipl = (12), .ipls_ipl = (12), .buffer_size = 1536, .p_rx_buffers =
                  g_ptp0_receive_buffer_array,
          .p_tx_buffers = g_ptp0_transmit_buffer_array, .p_edmac_instance = &g_edmac0, .p_callback = g_ptp0_callback, .p_context =
                  NULL,
          .p_extend = NULL };

ptp_instance_t g_ptp0 =
{ .p_ctrl = &g_ptp0_ctrl, .p_cfg = &g_ptp0_cfg, .p_api = &g_ptp_api };
void g_hal_init(void)
{
    g_common_init ();
}
