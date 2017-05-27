#include "water_level.h"

void water_level_sensor_init()
{
	adc_init(GPIO_PIN_WATER_LEVEL, GPIO_PORT_WATER_LEVEL, ADC_PERIPH);
}


WATER_LEVEL_ERR water_level_get(water_level_t *water_lvl)
{
	WATER_LEVEL_ERR err;

	water_lvl->adc_value = adc_readADC(ADC_PERIPH, ADC_CHANNEL_WATER_LEVEL);

	//TODO conversion

	return err;
}
