#include "uart.h"

UART_ERROR uart_open(USART_TypeDef* uart_reg, const uint32_t baud_rate)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

	if (uart_reg == USART1)
	{
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
	}

	else if (uart_reg == USART2)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);
	}

	else if (uart_reg == USART3)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	}


	else if (uart_reg == UART4)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
	}

	else if (uart_reg == UART5)
	{
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART5, ENABLE);
	}

	else
		return UART_ERROR_UNSPECIFIED_UART;

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = baud_rate;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(uart_reg, &USART_InitStructure);

	USART_Cmd(uart_reg, ENABLE);

	return 0;
}
