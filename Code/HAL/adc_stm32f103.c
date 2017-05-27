#include "adc.h"

void adc_init(uint16_t pin, GPIO_TypeDef *GPIOx, ADC_TypeDef *ADC)
{

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_GPIOA, ENABLE);


	ADC_InitTypeDef  ADC_InitStructure;
	/* PCLK2 is the APB2 clock */
	/* ADCCLK = PCLK2/6 = 72/6 = 12MHz*/
	RCC_ADCCLKConfig(RCC_PCLK2_Div6);

	/* Enable adc clock so that we can talk to it */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);
	/* Put everything back to power-on defaults */
	ADC_DeInit(ADC);

	/* adc Configuration ------------------------------------------------------*/
	/* adc and ADC2 operate independently */
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	/* Disable the scan conversion so we do one at a time */
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	/* Don't do contimuous conversions - do them on demand */
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	/* Start conversin by software, not an external trigger */
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	/* Conversions are 12 bit - put them in the lower 12 bits of the result */
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	/* Say how many channels would be used by the sequencer */
	ADC_InitStructure.ADC_NbrOfChannel = 1;

	/* Now do the setup */
	ADC_Init(ADC, &ADC_InitStructure);
	/* Enable adc */
	ADC_Cmd(ADC, ENABLE);

	/* Enable adc reset calibaration register */
	ADC_ResetCalibration(ADC);
	/* Check the end of adc reset calibration register */
	while(ADC_GetResetCalibrationStatus(ADC));
	/* Start adc calibaration */
	ADC_StartCalibration(ADC);
	/* Check the end of adc calibration */
	while(ADC_GetCalibrationStatus(ADC));
}

uint16_t adc_readADC(ADC_TypeDef *adc, uint8_t channel)
{
	  ADC_RegularChannelConfig(adc, channel, 1, ADC_SampleTime_1Cycles5);
	  // Start the conversion
	  ADC_SoftwareStartConvCmd(adc, ENABLE);
	  // Wait until conversion completion
	  while(ADC_GetFlagStatus(adc, ADC_FLAG_EOC) == RESET);
	  // Get the conversion value
	  return ADC_GetConversionValue(adc);
}
