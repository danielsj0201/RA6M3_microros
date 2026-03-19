/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (9)
#endif
/* ISR prototypes */
void r_ptp_mint_isr(void);
void r_ptp_ipls_isr(void);
void edmac_eint_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_txi_isr(void);
void sci_uart_tei_isr(void);
void sci_uart_eri_isr(void);
void agt_int_isr(void);
void ether_eint_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_EPTPC_MINT ((IRQn_Type) 0) /* EPTPC MINT (SYNFP0/1 interrupt) */
#define EPTPC_MINT_IRQn          ((IRQn_Type) 0) /* EPTPC MINT (SYNFP0/1 interrupt) */
#define VECTOR_NUMBER_EPTPC_IPLS ((IRQn_Type) 1) /* EPTPC IPLS (STCA interrupt) */
#define EPTPC_IPLS_IRQn          ((IRQn_Type) 1) /* EPTPC IPLS (STCA interrupt) */
#define VECTOR_NUMBER_EPTPC_PINT ((IRQn_Type) 2) /* EPTPC PINT (PTPEDMAC interrupt) */
#define EPTPC_PINT_IRQn          ((IRQn_Type) 2) /* EPTPC PINT (PTPEDMAC interrupt) */
#define VECTOR_NUMBER_SCI0_RXI ((IRQn_Type) 3) /* SCI0 RXI (Receive data full) */
#define SCI0_RXI_IRQn          ((IRQn_Type) 3) /* SCI0 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI0_TXI ((IRQn_Type) 4) /* SCI0 TXI (Transmit data empty) */
#define SCI0_TXI_IRQn          ((IRQn_Type) 4) /* SCI0 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI0_TEI ((IRQn_Type) 5) /* SCI0 TEI (Transmit end) */
#define SCI0_TEI_IRQn          ((IRQn_Type) 5) /* SCI0 TEI (Transmit end) */
#define VECTOR_NUMBER_SCI0_ERI ((IRQn_Type) 6) /* SCI0 ERI (Receive error) */
#define SCI0_ERI_IRQn          ((IRQn_Type) 6) /* SCI0 ERI (Receive error) */
#define VECTOR_NUMBER_AGT0_INT ((IRQn_Type) 7) /* AGT0 INT (AGT interrupt) */
#define AGT0_INT_IRQn          ((IRQn_Type) 7) /* AGT0 INT (AGT interrupt) */
#define VECTOR_NUMBER_EDMAC0_EINT ((IRQn_Type) 8) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#define EDMAC0_EINT_IRQn          ((IRQn_Type) 8) /* EDMAC0 EINT (EDMAC 0 interrupt) */
#endif /* VECTOR_DATA_H */
