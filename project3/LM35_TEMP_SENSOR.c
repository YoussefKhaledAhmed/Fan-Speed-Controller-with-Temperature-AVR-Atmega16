/*-------------------------------------------------------
 * [FILE NAME]: LM35_TEMP_SENSOR.c
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 10/10/2021
 *
 * [DESCRIPTION]: Source file for LM35_TEMP_SENSOR
 -------------------------------------------------------*/

#include "LM35_TEMP_SENSOR.h"
#include "adc.h"
#include "std_types.h"

/*
 * function arguments: none
 * output: the value of the current temperature
 * Description:
 * it initializes the ADC by passing the defined structure by address which contains the configuration data
 * it also, takes the value that the ADC read then applying the following equation:
 *       (adc_value * SENSOR_MAX_TEMPERATURE * reference_volt)/(1023 * SENSOR_MAX_VOLT_VALUE)
 * then saving the result in "temp_value" and returning it.
 */
uint8 LM35_getTemperature (void)
{
	uint8 temp_value = 0;/* to save the final calculated temperature value */
	uint16 adc_value = 0;/* to save the value read by the ADC */

	/* the following is a structure that contains :
	 * the required mode of the reference voltage & the pre-scaler */
	ADC_ConfigType CONFIGURATION = {INTERNAL_REFERENCE_VOLTAGE , FCPU_8};

	/* initializing the ADC by passing the configuration data through the structure explained above */
	ADC_init(&CONFIGURATION);

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value * SENSOR_MAX_TEMPERATURE * 2.56)/(1023 * SENSOR_MAX_VOLT_VALUE));

	return temp_value ;
}

