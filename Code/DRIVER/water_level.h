#ifndef WATER_LEVEL_H_
#define WATER_LEVEL_H_

#include "adc.h"

#define ADC_PERIPH  (ADC_TypeDef *) ADC1
#define ADC_CHANNEL_WATER_LEVEL (uint16_t)1
#define GPIO_PORT_WATER_LEVEL (GPIO_TypeDef *)GPIOA
#define GPIO_PIN_WATER_LEVEL (uint16_t)GPIO_Pin_1


typedef struct
{
	uint8_t decimal;
	uint8_t fractional;
	uint16_t adc_value;
}water_level_t;

typedef enum
{
	WATER_LEVEL_ERR_NO_ERR = 0,

}WATER_LEVEL_ERR;

void water_level_sensor_init();
WATER_LEVEL_ERR water_level_get(water_level_t *water_lvl);

#endif
