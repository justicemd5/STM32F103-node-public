#include "soil_humidity.h"

void soil_humidity_sensor_init()
{
	adc_init(GPIO_PIN_SOIL_HUMIDITY, GPIO_PORT_SOIL_HUMIDITY, ADC_PERIPH);
}


SOIL_HUMIDITY_ERR soil_humidity_get(soil_humidity_t *soil_humidity)
{

	SOIL_HUMIDITY_ERR err = 0;
	soil_humidity->adc_value = adc_readADC(ADC_PERIPH, ADC_CHANNEL_SOIL_HUMIDITY);

	//TODO conversion




	return err;
}
