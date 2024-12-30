#include <uart/uart.h>

int main(void)
{
	char str[13] = "Hello World\n";

	uart_init(0);

	while (1) {
		for (int i = 0; i < 13; i++) {
			uart_tx_char(0, str[i]);
		}
	}

	uart_exit(0);

	return 0;
}
