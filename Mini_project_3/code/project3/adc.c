/*
 * adc.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Mina sobhy
 *      description: function to initialize ADC and read the data from specific channel
 */

#include "avr/io.h"
#include <avr/interrupt.h>
#include "adc.h"
#include "common_macros.h"



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * REFS1:0 = 11 to choose to use the internal 2.56 Volt reference voltage
	 * ADLAR   = 0 right adjusted
	 */
	ADMUX = ( ADMUX & (0x3F) ) | ( (Config_Ptr->ref_volt)<<6 );

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = 011 to choose ADC_Clock=F_CPU/8=1Mhz/8=125Khz --> ADC must operate in range 50-200Khz
	 * depending on what the user will choose
	 */
	ADCSRA |= (1<<ADEN) ;
	ADCSRA = (ADCSRA & (0xF8)) | (Config_Ptr->prescaler);
}

uint16 ADC_readChannel(uint8 a_channelNum)
{
		/* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
		 * then write the correct channel number by setting the channel number in MUX2:0 bits
		 * and clear the rest*/
		ADMUX = (ADMUX & 0XE0) | (a_channelNum & 0X07);
		 /* Start conversion write '1' to ADSC */
		SET_BIT(ADCSRA,ADSC);
		/* Wait for conversion to complete, ADIF becomes '1' */
		while(BIT_IS_CLEAR(ADCSRA,ADIF));
		/* Clear ADIF by write '1' to it :) */
		SET_BIT(ADCSRA,ADIF);
		/* Read the digital value from the data register */
		return ADC;

}
