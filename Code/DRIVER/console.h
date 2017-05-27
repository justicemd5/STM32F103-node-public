#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "uart.h"
#include "gpio.h"

#define CONSOLE_BAUD					115200UL
#define CONSOLE_USART 					USART1

#define CONSOLE_USART_GPIO_PORT        GPIOA
#define CONSOLE_USART_TX_PIN                    GPIO_Pin_9
#define CONSOLE_USART_RX_PIN                    GPIO_Pin_10


void console_open();

#endif
