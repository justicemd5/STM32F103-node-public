#include "sensors.h"


void sensors_init()
{
	soil_humidity_sensor_init();
	water_level_sensor_init();
	light_sensor_init();
}
