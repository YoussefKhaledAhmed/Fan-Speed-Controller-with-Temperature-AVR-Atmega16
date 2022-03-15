/*-------------------------------------------------------
 * [FILE NAME]: adc.h
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 2/10/2021
 *
 * [DESCRIPTION]: header file for the AVR ADC driver
 -------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"


/*-----------------------------------*
 *           DEFINITIONS             *
 *-----------------------------------*/

#define ADC_ReferenceVolatge uint8

#define OFF 0
#define ON  1

typedef enum {
	 FCPU_2 = 1 , FCPU_4 , FCPU_8 , FCPU_16 , FCPU_32 , FCPU_64 , FCPU_128
}ADC_Prescaler;

typedef enum {
	 TURN_OFF_INTERNAL_REFERENCE_VOLTAGE , AVCC_REFERENCE_VOLTAGE , RESERVED_MODE , INTERNAL_REFERENCE_VOLTAGE
}ADC_REF_VOLT;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/* Choosing which channel you need */

#define ADC_CHANNEL 0

/* ### this ADC_CHANNEL should be completed as there are more cases should be handled ### */

/* setting or clearing the ADC left adjust result, it should be put by zero if no shift   *
 * will be applied on the ADC register and one if shift is applied on the ADC register.   */
#define ADC_LEFT_ADJUST_RESULT OFF

/*
 * enable ADC Auto trigger by 1 or disable it by 0
 * also setting Auto trigger mode by picking a number from 0 to 7:
 * 0: free running mode
 * 1: analog comparator
 * 2: external interrupt request 0
 * 3: timer/counter0 compare match
 * 4: timer/counter0 overflow
 * 5: timer/counter1 compare match B
 * 6: timer/counter1 overflow
 * 7: timer/counter1 capture event
 */

#define ADC_AUTO_TRIGGER_ENABLE OFF
#define AUTO_TRIGGER_MODE 0

/* ADC interrupt enable by 1 or disable by 0 */

#define ADC_INTERRUPT_ENABLE OFF

/* ADC pre-scaler selection */

#define DEVISION_FACTOR 3


/*-----------------------------------*
 *        FUNCTION PROTOTYPE         *
 *-----------------------------------*/
void ADC_init(const ADC_ConfigType* config_ptr);
uint16 ADC_readChannel(uint8 ch_num);

#endif
