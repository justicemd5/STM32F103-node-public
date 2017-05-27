#ifndef UART_H_
#define UART_H_

#include "stm32f10x_conf.h"

typedef enum
{
	UART_ERROR_NO_ERROR = 0,
	UART_ERROR_UNSPECIFIED_UART,
	UART_ERROR_NO_DATA

}UART_ERROR;

UART_ERROR uart_open(USART_TypeDef* uart_reg, const uint32_t baud_rate);
UART_ERROR uart_write(USART_TypeDef *uart_reg, const uint8_t* data, const uint16_t data_length);

UART_ERROR uart_read(USART_TypeDef const *const uart_reg,
		uint8_t* data,
		uint16_t *const data_length,
		const uint16_t start_timeout_ms,
		const uint16_t end_timeout_ms);
#endif
