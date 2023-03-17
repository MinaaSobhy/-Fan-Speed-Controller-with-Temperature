/*
 * project3_main.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Mina sobhy
 *      description: Implementation of a Fan Controller using temperature sensor, ADC, DC Motor
 *      			 LCD, PWM signal on timer0
 */

#include "std_types.h"
#include "adc.h"
#include "lcd.h"
#include "lm35.h"
#include "dcmotor.h"


int main(void)
{
	// ADC For Temperature Sensor Configuration
	ADC_ConfigType ADC_Config = {INTERNAL_VOLTAGE, F_CPU_8};
	ADC_init (&ADC_Config);

	//LCD Initialization
	LCD_init();
	//start to print the titles
	LCD_displayString("   FAN is OFF   ");
	LCD_moveCursor(1,0);
	LCD_displayString("  Temp =     C  ");

	//DC motor Initialization
	DcMotor_init();

	//define variable to store the current temperature
	uint8 temp;

	for(;;)
	{
		//store the current temperature in the variabel
		temp = LM35_getTemp();

		//print the current temperature
		LCD_moveCursor(1,9);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}

		/* rotate the motor according to the current temperature */
		if (temp < 30)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP, 0);
		}
		else if (temp < 60 )
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 25);
		}
		else if (temp < 90 )
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 50);
		}
		else if (temp < 120 )
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 75);
		}
		else if (temp >=120 && temp <= 150)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("ON ");
			DcMotor_Rotate(CW, 100);
		}
	}

	return 0;
}

