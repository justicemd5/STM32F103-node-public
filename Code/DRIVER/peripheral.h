#ifndef PERIPHERAL_H_
#define PERIPHERAL_H_

#include "light_sensor.h"
#include "water_level.h"
#include "soil_humidity.h"

void peripheral_init();
uint8_t peripheral_device_on(uint16_t device);


#endif
