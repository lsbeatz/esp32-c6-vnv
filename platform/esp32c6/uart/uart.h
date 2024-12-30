#ifndef UART_H
#define UART_H

#define NR_UART_CH (2)

int uart_init(int ch);
int uart_exit(int ch);
int uart_tx_char(int ch, char c);

#endif /* UART_H */
