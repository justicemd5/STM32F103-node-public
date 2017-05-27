#include "light_sensor.h"

void light_sensor_init()
{
	adc_init(GPIO_PIN_LIGHT_SENSOR, GPIO_PORT_LIGHT_SENSOR, ADC_PERIPH);
}

LIGHT_SENSOR_ERR light_sensor_value_get(light_sensor_t *light_sensor)
{
	LIGHT_SENSOR_ERR err = 0;
	light_sensor->adc_value = adc_readADC(ADC_PERIPH, ADC_CHANNEL_LIGHT_SENSOR);


	//TODO conversion

	return err;
}
