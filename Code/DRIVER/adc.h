#ifndef ADC_H_
#include "stm32f10x_conf.h"

uint16_t adc_readADC(ADC_TypeDef *adc, uint8_t channel);
void adc_init(uint16_t pin, GPIO_TypeDef *GPIOx, ADC_TypeDef *ADC);

#endif
