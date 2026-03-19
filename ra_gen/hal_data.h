/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_agt.h"
#include "r_timer_api.h"
#include "r_sci_uart.h"
#include "r_uart_api.h"

#include "r_ptp.h"
FSP_HEADER
/** AGT Timer Instance */
extern const timer_instance_t g_timer0;

/** Access the AGT instance using these structures when calling API functions directly (::p_api is not used). */
extern agt_instance_ctrl_t g_timer0_ctrl;
extern const timer_cfg_t g_timer0_cfg;

#ifndef micro_ros_timer_cb
void micro_ros_timer_cb(timer_callback_args_t *p_args);
#endif
/** UART on SCI Instance. */
extern const uart_instance_t g_uart0;

/** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
extern sci_uart_instance_ctrl_t g_uart0_ctrl;
extern const uart_cfg_t g_uart0_cfg;
extern const sci_uart_extended_cfg_t g_uart0_cfg_extend;

#ifndef user_uart_callback
void user_uart_callback(uart_callback_args_t *p_args);
#endif
extern void r_ptp_edmac_callback(edmac_callback_args_t *p_args);
extern edmac_instance_ctrl_t g_edmac0_ctrl;
extern const edmac_cfg_t g_edmac0_cfg;
extern edmac_instance_t g_edmac0;
extern void g_ptp0_callback(ptp_callback_args_t *p_args);
extern void ptp_edmac_callback(edmac_callback_args_t *p_args);

extern ptp_instance_ctrl_t g_ptp0_ctrl;
extern const ptp_cfg_t g_ptp0_cfg;
extern ptp_instance_t g_ptp0;
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
