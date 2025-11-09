/*	$NetBSD$	*/

/*
 * MC68681 Dual UART Register Definitions
 * Motorola/Freescale MC68681 DUART
 */

#ifndef _RE86K_MC68681REG_H_
#define _RE86K_MC68681REG_H_

/* Register offsets (byte-wide registers) */
#define MC68681_MRA		0x00	/* Mode Register A */
#define MC68681_SRA		0x01	/* Status Register A */
#define MC68681_CSRA		0x01	/* Clock Select Register A (write) */
#define MC68681_CRA		0x02	/* Command Register A */
#define MC68681_RBA		0x03	/* Receive Buffer A (read) */
#define MC68681_TBA		0x03	/* Transmit Buffer A (write) */
#define MC68681_IPCR		0x04	/* Input Port Change Register */
#define MC68681_ACR		0x04	/* Auxiliary Control Register (write) */
#define MC68681_ISR		0x05	/* Interrupt Status Register */
#define MC68681_IMR		0x05	/* Interrupt Mask Register (write) */
#define MC68681_CTU		0x06	/* Counter/Timer Upper */
#define MC68681_CTPU		0x06	/* Counter/Timer Preset Upper (write) */
#define MC68681_CTL		0x07	/* Counter/Timer Lower */
#define MC68681_CTPL		0x07	/* Counter/Timer Preset Lower (write) */

#define MC68681_MRB		0x08	/* Mode Register B */
#define MC68681_SRB		0x09	/* Status Register B */
#define MC68681_CSRB		0x09	/* Clock Select Register B (write) */
#define MC68681_CRB		0x0A	/* Command Register B */
#define MC68681_RBB		0x0B	/* Receive Buffer B (read) */
#define MC68681_TBB		0x0B	/* Transmit Buffer B (write) */
#define MC68681_IVR		0x0C	/* Interrupt Vector Register */
#define MC68681_IP		0x0D	/* Input Port */
#define MC68681_OPCR		0x0D	/* Output Port Configuration (write) */
#define MC68681_STARTC		0x0E	/* Start Counter command */
#define MC68681_SETOP		0x0E	/* Set Output Port bits (write) */
#define MC68681_STOPC		0x0F	/* Stop Counter command */
#define MC68681_RESETOP		0x0F	/* Reset Output Port bits (write) */

/* Status Register bits (SRA, SRB) */
#define MC68681_SR_RXRDY	0x01	/* Receiver Ready */
#define MC68681_SR_FFULL	0x02	/* FIFO Full */
#define MC68681_SR_TXRDY	0x04	/* Transmitter Ready */
#define MC68681_SR_TXEMT	0x08	/* Transmitter Empty */
#define MC68681_SR_OERR		0x10	/* Overrun Error */
#define MC68681_SR_PERR		0x20	/* Parity Error */
#define MC68681_SR_FERR		0x40	/* Framing Error */
#define MC68681_SR_RB		0x80	/* Received Break */

/* Command Register bits (CRA, CRB) */
#define MC68681_CR_RXCMD_MASK	0x03	/* Receiver command mask */
#define MC68681_CR_RX_ENA	0x01	/* Enable Receiver */
#define MC68681_CR_RX_DIS	0x02	/* Disable Receiver */
#define MC68681_CR_TXCMD_MASK	0x0C	/* Transmitter command mask */
#define MC68681_CR_TX_ENA	0x04	/* Enable Transmitter */
#define MC68681_CR_TX_DIS	0x08	/* Disable Transmitter */
#define MC68681_CR_MISC_MASK	0x70	/* Misc command mask */
#define MC68681_CR_RESET_MR	0x10	/* Reset MR pointer */
#define MC68681_CR_RESET_RX	0x20	/* Reset Receiver */
#define MC68681_CR_RESET_TX	0x30	/* Reset Transmitter */
#define MC68681_CR_RESET_ERR	0x40	/* Reset Error Status */
#define MC68681_CR_RESET_BRK	0x50	/* Reset Break Change Int */
#define MC68681_CR_START_BRK	0x60	/* Start Break */
#define MC68681_CR_STOP_BRK	0x70	/* Stop Break */

/* Mode Register 1 bits (MRA, MRB) */
#define MC68681_MR1_RXRTS	0x80	/* Receiver RTS control */
#define MC68681_MR1_RXINT	0x40	/* Receiver interrupt select */
#define MC68681_MR1_ERRMODE	0x20	/* Error mode */
#define MC68681_MR1_PARITY_MASK	0x18	/* Parity bits */
#define MC68681_MR1_PARITY_EVEN	0x00	/* Even parity */
#define MC68681_MR1_PARITY_ODD	0x08	/* Odd parity */
#define MC68681_MR1_PARITY_NONE	0x10	/* No parity */
#define MC68681_MR1_BITS_MASK	0x03	/* Bits per character */
#define MC68681_MR1_BITS_5	0x00	/* 5 bits */
#define MC68681_MR1_BITS_6	0x01	/* 6 bits */
#define MC68681_MR1_BITS_7	0x02	/* 7 bits */
#define MC68681_MR1_BITS_8	0x03	/* 8 bits */

/* Mode Register 2 bits (MRA, MRB) */
#define MC68681_MR2_MODE_MASK	0xC0	/* Channel mode */
#define MC68681_MR2_MODE_NORMAL	0x00	/* Normal */
#define MC68681_MR2_MODE_ECHO	0x40	/* Automatic echo */
#define MC68681_MR2_MODE_LOOP	0x80	/* Local loopback */
#define MC68681_MR2_MODE_RLOOP	0xC0	/* Remote loopback */
#define MC68681_MR2_TXRTS	0x20	/* Transmitter RTS control */
#define MC68681_MR2_TXCTS	0x10	/* Transmitter CTS enable */
#define MC68681_MR2_STOP_MASK	0x0F	/* Stop bit length */
#define MC68681_MR2_STOP_1	0x07	/* 1 stop bit */
#define MC68681_MR2_STOP_2	0x0F	/* 2 stop bits */

/* Interrupt Status/Mask Register bits (ISR, IMR) */
#define MC68681_INT_TXRDYA	0x01	/* Transmitter A Ready */
#define MC68681_INT_RXRDYA	0x02	/* Receiver A Ready/FIFO Full */
#define MC68681_INT_DELTAA	0x04	/* Change in Break A */
#define MC68681_INT_CNTRRDY	0x08	/* Counter Ready */
#define MC68681_INT_TXRDYB	0x10	/* Transmitter B Ready */
#define MC68681_INT_RXRDYB	0x20	/* Receiver B Ready/FIFO Full */
#define MC68681_INT_DELTAB	0x40	/* Change in Break B */
#define MC68681_INT_PORTCHG	0x80	/* Input Port Change */

/* Clock Select Register values (for 3.6864 MHz crystal) */
#define MC68681_CSR_50		0x00	/* 50 baud */
#define MC68681_CSR_110		0x11	/* 110 baud */
#define MC68681_CSR_134_5	0x22	/* 134.5 baud */
#define MC68681_CSR_200		0x33	/* 200 baud */
#define MC68681_CSR_300		0x44	/* 300 baud */
#define MC68681_CSR_600		0x55	/* 600 baud */
#define MC68681_CSR_1200	0x66	/* 1200 baud */
#define MC68681_CSR_2400	0x88	/* 2400 baud */
#define MC68681_CSR_4800	0x99	/* 4800 baud */
#define MC68681_CSR_9600	0xBB	/* 9600 baud */
#define MC68681_CSR_19200	0xCC	/* 19200 baud */
#define MC68681_CSR_38400	0xCC	/* 38400 baud (with ACR bit 7) */

/* Auxiliary Control Register bits */
#define MC68681_ACR_BRGSET	0x80	/* Baud Rate Generator Set */

#endif /* _RE86K_MC68681REG_H_ */
