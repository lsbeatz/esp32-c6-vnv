#include <stdbool.h>

#include <aspace.h>

#include "uart_regs.h"
#include "uart.h"

static bool initialized = false;

static uintptr_t uart_bases[NR_UART_CH] = {
	UART0_BASE,
	UART1_BASE,
};

static void wait_for_update(int ch)
{
	volatile union UART_REG_UPDATE REG_UPDATE;

	do {
		REG_UPDATE.raw = *(uint32_t *)(UART_REG_UPDATE_REG(uart_bases[ch]));
	} while (REG_UPDATE.UPDATE);
}

int uart_init(int ch)
{
	wait_for_update(ch);

	initialized = true;

	return 0;
}

int uart_exit(int ch)
{
	initialized = false;

	return 0;
}

int uart_tx_char(int ch, char c)
{
	volatile union UART_FIFO	FIFO;
	volatile union UART_INT_ENA INT_ENA;
	volatile union UART_INT_CLR INT_CLR;
	volatile union UART_INT_ST	INT_ST;

	wait_for_update(ch);

	INT_ENA.raw							= *(uint32_t *)(UART_INT_ENA_REG(uart_bases[ch]));
	INT_ENA.TXFIFO_EMPTY_INT_ENA		= 0;
	*(uint32_t *)(UART_INT_ENA_REG(uart_bases[ch])) = INT_ENA.raw;

	FIFO.RXFIFO_RD_BYTE				 = (c & 0xFF);
	*(uint32_t *)(UART_FIFO_REG(uart_bases[ch])) = FIFO.raw;

	INT_CLR.raw							= *(uint32_t *)(UART_INT_CLR_REG(uart_bases[ch]));
	INT_CLR.TXFIFO_EMPTY_INT_CLR		= 0;
	*(uint32_t *)(UART_INT_CLR_REG(uart_bases[ch])) = INT_CLR.raw;

	INT_ENA.raw							= *(uint32_t *)(UART_INT_ENA_REG(uart_bases[ch]));
	INT_ENA.TXFIFO_EMPTY_INT_ENA		= 1;
	*(uint32_t *)(UART_INT_ENA_REG(uart_bases[ch])) = INT_ENA.raw;

	do {
		INT_ST.raw = *(uint32_t *)(UART_INT_ST_REG(uart_bases[ch]));
	} while (INT_ST.TXFIFO_EMPTY_INT_ST);

	return 0;
}
