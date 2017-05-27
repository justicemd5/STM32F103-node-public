#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f10x_conf.h"

void gpio_set_mode(GPIO_TypeDef *port, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, uint8_t defaultvalue);

#endif
