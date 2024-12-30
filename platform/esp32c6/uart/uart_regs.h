#ifndef UART_REGS_H
#define UART_REGS_H

#include <stdint.h>

/* Offsets */
#define UART_FIFO_OFS				 (0x00)
#define UART_TOUT_CONF_SYNC_OFS		 (0x64)
#define UART_INT_RAW_OFS			 (0x04)
#define UART_INT_ST_OFS				 (0x08)
#define UART_INT_ENA_OFS			 (0x0C)
#define UART_INT_CLR_OFS			 (0x10)
#define UART_CLKDIV_SYNC_OFS		 (0x14)
#define UART_RX_FILT_OFS			 (0x18)
#define UART_CONF0_SYNC_OFS			 (0x20)
#define UART_CONF1_OFS				 (0x24)
#define UART_HWFC_CONF_SYNC_OFS		 (0x2C)
#define UART_SLEEP_CONF0_OFS		 (0x30)
#define UART_SLEEP_CONF1_OFS		 (0x34)
#define UART_SLEEP_CONF2_OFS		 (0x38)
#define UART_SWFC_CONF0_SYNC_OFS	 (0x3C)
#define UART_SWFC_CONF1_OFS			 (0x40)
#define UART_TXBRK_CONF_SYNC_OFS	 (0x44)
#define UART_IDLE_CONF_SYNC_OFS		 (0x48)
#define UART_RS485_CONF_SYNC_OFS	 (0x4C)
#define UART_CLK_CONF_OFS			 (0x88)
#define UART_REG_UPDATE_OFS			 (0x98)
#define UART_ID_OFS					 (0x9C)
#define UART_STATUS_OFS				 (0x1C)
#define UART_MEM_TX_STATUS_OFS		 (0x68)
#define UART_MEM_RX_STATUS_OFS		 (0x6C)
#define UART_FSM_STATUS_OFS			 (0x70)
#define UART_AFIFO_STATUS_OFS		 (0x90)
#define UART_AT_CMD_PRECNT_SYNC_OFS	 (0x50)
#define UART_AT_CMD_POSTCNT_SYNC_OFS (0x54)
#define UART_AT_CMD_GAPTOUT_SYNC_OFS (0x58)
#define UART_AT_CMD_CHAR_SYNC_OFS	 (0x5C)
#define UART_POSPULSE_OFS			 (0x74)
#define UART_NEGPULSE_OFS			 (0x78)
#define UART_LOWPULSE_OFS			 (0x7C)
#define UART_HIGHPULSE_OFS			 (0x80)
#define UART_RXD_CNT_OFS			 (0x84)
#define UART_DATE_OFS				 (0x8C)

/* Registers */
#define UART_FIFO_REG(base)				   (base + UART_FIFO_OFS)
#define UART_TOUT_CONF_SYNC_REG(base)	   (base + UART_TOUT_CONF_SYNC_OFS)
#define UART_INT_RAW_REG(base)			   (base + UART_INT_RAW_OFS)
#define UART_INT_ST_REG(base)			   (base + UART_INT_ST_OFS)
#define UART_INT_ENA_REG(base)			   (base + UART_INT_ENA_OFS)
#define UART_INT_CLR_REG(base)			   (base + UART_INT_CLR_OFS)
#define UART_CLKDIV_SYNC_REG(base)		   (base + UART_CLKDIV_SYNC_OFS)
#define UART_RX_FILT_REG(base)			   (base + UART_RX_FILT_OFS)
#define UART_CONF0_SYNC_REG(base)		   (base + UART_CONF0_SYNC_OFS)
#define UART_CONF1_REG(base)			   (base + UART_CONF1_OFS)
#define UART_HWFC_CONF_SYNC_REG(base)	   (base + UART_HWFC_CONF_SYNC_OFS)
#define UART_SLEEP_CONF0_REG(base)		   (base + UART_SLEEP_CONF0_OFS)
#define UART_SLEEP_CONF1_REG(base)		   (base + UART_SLEEP_CONF1_OFS)
#define UART_SLEEP_CONF2_REG(base)		   (base + UART_SLEEP_CONF2_OFS)
#define UART_SWFC_CONF0_SYNC_REG(base)	   (base + UART_SWFC_CONF0_SYNC_OFS)
#define UART_SWFC_CONF1_REG(base)		   (base + UART_SWFC_CONF1_OFS)
#define UART_TXBRK_CONF_SYNC_REG(base)	   (base + UART_TXBRK_CONF_SYNC_OFS)
#define UART_IDLE_CONF_SYNC_REG(base)	   (base + UART_IDLE_CONF_SYNC_OFS)
#define UART_RS485_CONF_SYNC_REG(base)	   (base + UART_RS485_CONF_SYNC_OFS)
#define UART_CLK_CONF_REG(base)			   (base + UART_CLK_CONF_OFS)
#define UART_REG_UPDATE_REG(base)		   (base + UART_REG_UPDATE_OFS)
#define UART_ID_REG(base)				   (base + UART_ID_OFS)
#define UART_STATUS_REG(base)			   (base + UART_STATUS_OFS)
#define UART_MEM_TX_STATUS_REG(base)	   (base + UART_MEM_TX_STATUS_OFS)
#define UART_MEM_RX_STATUS_REG(base)	   (base + UART_MEM_RX_STATUS_OFS)
#define UART_FSM_STATUS_REG(base)		   (base + UART_FSM_STATUS_OFS)
#define UART_AFIFO_STATUS_REG(base)		   (base + UART_AFIFO_STATUS_OFS)
#define UART_AT_CMD_PRECNT_SYNC_REG(base)  (base + UART_AT_CMD_PRECNT_SYNC_OFS)
#define UART_AT_CMD_POSTCNT_SYNC_REG(base) (base + UART_AT_CMD_POSTCNT_SYNC_OFS)
#define UART_AT_CMD_GAPTOUT_SYNC_REG(base) (base + UART_AT_CMD_GAPTOUT_SYNC_OFS)
#define UART_AT_CMD_CHAR_SYNC_REG(base)	   (base + UART_AT_CMD_CHAR_SYNC_OFS)
#define UART_POSPULSE_REG(base)			   (base + UART_POSPULSE_OFS)
#define UART_NEGPULSE_REG(base)			   (base + UART_NEGPULSE_OFS)
#define UART_LOWPULSE_REG(base)			   (base + UART_LOWPULSE_OFS)
#define UART_HIGHPULSE_REG(base)		   (base + UART_HIGHPULSE_OFS)
#define UART_RXD_CNT_REG(base)			   (base + UART_RXD_CNT_OFS)
#define UART_DATE_REG(base)				   (base + UART_DATE_OFS)

/* Structs */
#ifndef __ASSEMBLY__

union UART_FIFO {
	uint32_t raw;

	struct {
		uint32_t RXFIFO_RD_BYTE : 8;
		uint32_t RSVD0			: 24;
	};
};

union UART_INT_ST {
	uint32_t raw;

	struct {
		uint32_t RXFIFO_FULL_INT_ST		 : 1;
		uint32_t TXFIFO_EMPTY_INT_ST	 : 1;
		uint32_t PARITY_ERR_INT_ST		 : 1;
		uint32_t FRM_ERR_INT_ST			 : 1;
		uint32_t RXFIFO_OVF_INT_ST		 : 1;
		uint32_t DSR_CHG_INT_ST			 : 1;
		uint32_t CTS_CHG_INT_ST			 : 1;
		uint32_t BRK_DET_INT_ST			 : 1;
		uint32_t RXFIFO_TOUT_INT_ST		 : 1;
		uint32_t SW_XON_INT_ST			 : 1;
		uint32_t SW_XOFF_INT_ST			 : 1;
		uint32_t GLITCH_DET_INT_ST		 : 1;
		uint32_t TX_BRK_DONE_INT_ST		 : 1;
		uint32_t TX_BRK_IDLE_DONE_INT_ST : 1;
		uint32_t TX_DONE_INT_ST			 : 1;
		uint32_t RS485_PARITY_ERR_INT_ST : 1;
		uint32_t RS485_FRM_ERR_INT_ST	 : 1;
		uint32_t RS485_CLASH_INT_ST		 : 1;
		uint32_t AT_CMD_CHAR_DET_INT_ST	 : 1;
		uint32_t WAKEUP_INT_ST			 : 1;
		uint32_t RSVD0					 : 12;
	};
};

union UART_INT_ENA {
	uint32_t raw;

	struct {
		uint32_t RXFIFO_FULL_INT_ENA	  : 1;
		uint32_t TXFIFO_EMPTY_INT_ENA	  : 1;
		uint32_t PARITY_ERR_INT_ENA		  : 1;
		uint32_t FRM_ERR_INT_ENA		  : 1;
		uint32_t RXFIFO_OVF_INT_ENA		  : 1;
		uint32_t DSR_CHG_INT_ENA		  : 1;
		uint32_t CTS_CHG_INT_ENA		  : 1;
		uint32_t BRK_DET_INT_ENA		  : 1;
		uint32_t RXFIFO_TOUT_INT_ENA	  : 1;
		uint32_t SW_XON_INT_ENA			  : 1;
		uint32_t SW_XOFF_INT_ENA		  : 1;
		uint32_t GLITCH_DET_INT_ENA		  : 1;
		uint32_t TX_BRK_DONE_INT_ENA	  : 1;
		uint32_t TX_BRK_IDLE_DONE_INT_ENA : 1;
		uint32_t TX_DONE_INT_ENA		  : 1;
		uint32_t RS485_PARITY_ERR_INT_ENA : 1;
		uint32_t RS485_FRM_ERR_INT_ENA	  : 1;
		uint32_t RS485_CLASH_INT_ENA	  : 1;
		uint32_t AT_CMD_CHAR_DET_INT_ENA  : 1;
		uint32_t WAKEUP_INT_ENA			  : 1;
		uint32_t RSVD0					  : 12;
	};
};

union UART_INT_CLR {
	uint32_t raw;

	struct {
		uint32_t RXFIFO_FULL_INT_CLR	  : 1;
		uint32_t TXFIFO_EMPTY_INT_CLR	  : 1;
		uint32_t PARITY_ERR_INT_CLR		  : 1;
		uint32_t FRM_ERR_INT_CLR		  : 1;
		uint32_t RXFIFO_OVF_INT_CLR		  : 1;
		uint32_t DSR_CHG_INT_CLR		  : 1;
		uint32_t CTS_CHG_INT_CLR		  : 1;
		uint32_t BRK_DET_INT_CLR		  : 1;
		uint32_t RXFIFO_TOUT_INT_CLR	  : 1;
		uint32_t SW_XON_INT_CLR			  : 1;
		uint32_t SW_XOFF_INT_CLR		  : 1;
		uint32_t GLITCH_DET_INT_CLR		  : 1;
		uint32_t TX_BRK_DONE_INT_CLR	  : 1;
		uint32_t TX_BRK_IDLE_DONE_INT_CLR : 1;
		uint32_t TX_DONE_INT_CLR		  : 1;
		uint32_t RS485_PARITY_ERR_INT_CLR : 1;
		uint32_t RS485_FRM_ERR_INT_CLR	  : 1;
		uint32_t RS485_CLASH_INT_CLR	  : 1;
		uint32_t AT_CMD_CHAR_DET_INT_CLR  : 1;
		uint32_t WAKEUP_INT_CLR			  : 1;
		uint32_t RSVD0					  : 12;
	};
};

union UART_CONF1 {
	uint32_t raw;

	struct {
		uint32_t RXFIFO_FULL_THRHD : 8;
		uint32_t TXFIFO_FULL_THRHD : 8;
		uint32_t CTS_INV		   : 1;
		uint32_t DSR_INV		   : 1;
		uint32_t RTS_INV		   : 1;
		uint32_t DTR_INV		   : 1;
		uint32_t SW_DTR			   : 1;
		uint32_t CLK_EN			   : 1;
		uint32_t RSVD0			   : 10;
	};
};

union UART_REG_UPDATE {
	uint32_t raw;

	struct {
		uint32_t UPDATE : 1;
		uint32_t RSVD0	: 31;
	};
};

#endif /* __ASSEMBLY__ */

#endif /* ESP32C6_UART_REGS_H */
