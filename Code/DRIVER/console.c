#include "console.h"

void console_open()
{
	gpio_set_mode(CONSOLE_USART_GPIO_PORT, CONSOLE_USART_TX_PIN,
			GPIO_Mode_AF_PP, GPIO_Speed_50MHz, 0);

	gpio_set_mode(CONSOLE_USART_GPIO_PORT, CONSOLE_USART_RX_PIN,
			GPIO_Mode_IN_FLOATING, GPIO_Speed_50MHz, 0);

	uart_open(CONSOLE_USART, CONSOLE_BAUD);
}
