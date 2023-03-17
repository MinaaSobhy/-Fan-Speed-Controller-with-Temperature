/*
 * lm35.h
 *
 *  Created on: Oct 6, 2022
 *      Author: Mina sobhy
 *      description: Header file for the LM35 Temperature Sensor driver
 */

#ifndef LM35_H_
#define LM35_H_

#include "std_types.h"
#include "adc.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemp(void);

#endif /* LM35_H_ */
