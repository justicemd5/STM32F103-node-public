#include "peripheral.h"

#define NO_ERROR 0
#ifdef DEBUG
#include "stdio.h"
#endif

void peripheral_init()
{
	SystemInit();
	rcc_state_all_gpio_clock(true);

}

uint8_t peripheral_device_on(uint16_t device)
{
	uint8_t display_reset = 0;
	uint8_t err = NO_ERROR;

	//SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);

//	if(PERIPHERAL_DEVICE_RTC & device)
//	{
//		err = rtc_peripheral_test();
	if(PERIPHERAL_DEVICE_CONSOLE & device)
	{
		console_open();
#ifdef DEBUG
	setvbuf(stdout, 0, _IONBF, 0);
#endif
		//HANDLE_ERROR(err);
	}

	if(PERIPHERAL_DEVICE_LEDS & device)
	{
		led_init();
		//HANDLE_ERROR(err);
	}

	if(PERIPHERAL_DEVICE_DS18B20 & device)
	{
		//ds18b20_init();
		//HANDLE_ERROR(err);
	}

	return err;
}


