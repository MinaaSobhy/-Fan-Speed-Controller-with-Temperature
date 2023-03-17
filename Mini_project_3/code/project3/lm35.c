/*
 * lm35.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Mina sobhy
 *      description: source file for the LM35 Temperature Sensor driver
 */
#include "lm35.h"



/*
 * Description :
 * Calculate the temperature from the ADC digital value and return it to the user.
 */
uint8 LM35_getTemp(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */

	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);
	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}


