#ifndef SOIL_HUMIDITY_H_
#define SOIL_HUMIDITY_H_

#include "adc.h"

#define ADC_PERIPH  (ADC_TypeDef *) ADC1
#define ADC_CHANNEL_SOIL_HUMIDITY (uint16_t)0
#define GPIO_PORT_SOIL_HUMIDITY (GPIO_TypeDef *)GPIOA
#define GPIO_PIN_SOIL_HUMIDITY (uint16_t)GPIO_Pin_0

typedef struct
{
	uint8_t decimal;
	uint8_t fractional;
	uint16_t adc_value;
}soil_humidity_t;

typedef enum
{
	SOIL_HUMIDITY_ERR_NO_ERR = 0,
}SOIL_HUMIDITY_ERR;

void soil_humidity_sensor_init();
SOIL_HUMIDITY_ERR soil_humidity_get(soil_humidity_t *soil_humidity);

#endif
