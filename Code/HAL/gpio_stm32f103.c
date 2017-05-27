#include "gpio.h"

void gpio_set_mode(GPIO_TypeDef *port, uint16_t pin, GPIOMode_TypeDef mode, GPIOSpeed_TypeDef speed, uint8_t defaultvalue)
{
	GPIO_InitTypeDef   GPIO_InitStructure;

	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = mode;
	GPIO_InitStructure.GPIO_Speed = speed;
	GPIO_Init(port, &GPIO_InitStructure);

//	if (mode == GPIO_OUTPUT_PP && defaultvalue)
//	{
//		GPIO_SetBits(port,pin);
//	}
//	else if (mode == GPIO_OUTPUT_PP && defaultvalue == 0)
//	{
//		GPIO_ResetBits(port,pin);
//	}
}
