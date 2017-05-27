#ifndef LIGHT_SENSOR_H_
#define LIGHT_SENSOR_H_

#include "adc.h"

#define ADC_PERIPH  (ADC_TypeDef *) ADC1
#define ADC_CHANNEL_LIGHT_SENSOR (uint16_t)4
#define GPIO_PORT_LIGHT_SENSOR (GPIO_TypeDef *)GPIOA
#define GPIO_PIN_LIGHT_SENSOR (uint16_t)GPIO_Pin_4

typedef struct
{
	uint8_t decimal;
	uint8_t fractional;
	uint16_t adc_value;
}light_sensor_t;

typedef enum
{
	LIGHT_SENSOR_ERR_NO_ERR = 0,
}LIGHT_SENSOR_ERR;

void light_sensor_init();
LIGHT_SENSOR_ERR light_sensor_value_get(light_sensor_t *light_sensor);


#endif
