/*
 * led_config.h
 *
 * Created on: 02.06.2015
 * 		Author:Marko
 */

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#include "stm32f0xx_gpio.h"

/* LED Inteface GPIO pins */
#define LED_GPIO_CLK 	RCC_AHBPeriph_GPIOC
#define LED_GPIO_PORT	GPIOC
#define LED_GPIO_PIN 	GPIO_Pin_0

#define LED1_GPIO_CLK 	RCC_AHBPeriph_GPIOC
#define LED1_GPIO_PORT	GPIOC
#define LED1_GPIO_PIN 	GPIO_Pin_1


#define LED_RED_ON		GPIO_SetBits(LED_GPIO_PORT,LED_GPIO_PIN)
#define LED_RED_OFF		GPIO_ResetBits(LED_GPIO_PORT,LED_GPIO_PIN)

#define LED_WHITE_ON		GPIO_SetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)
#define LED_WHITE_OFF		GPIO_ResetBits(LED1_GPIO_PORT,LED1_GPIO_PIN)

#endif
