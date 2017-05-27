#include "sensors.h"


int main(void)
{
	SystemInit();

	console_open();
	sensors_init();

    while(1)
    {

    	soil_humidity_t soil_humidity;
    	water_level_t water_level;
    	light_sensor_t light_intesity;

    	soil_humidity_get(&soil_humidity);
    	water_level_get(&water_level);
    	light_sensor_value_get(&light_intesity);

    	printf("Soil humidity adc value %d", soil_humidity.adc_value);
    	printf("Water level adc value %d", water_level.adc_value);
    	printf("Light intensity adc value %d", light_intesity.adc_value);

    	uint32_t pause = 0xFFFF;

    	while (pause) pause--;
    }
}
