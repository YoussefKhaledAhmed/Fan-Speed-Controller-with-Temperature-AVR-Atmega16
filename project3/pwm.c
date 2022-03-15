/*-------------------------------------------------------
 * [FILE NAME]: pwm.c
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 14/10/2021
 *
 * [DESCRIPTION]: source file for PWM
 -------------------------------------------------------*/

#include "pwm.h"
#include <avr/io.h>

/*
 * function argument: Duty_cycle
 * return: void
 * Description:
 * it takes the Duty cycle that the generated analog signal should be with
 */
void PWM_Timer0_Start(uint8 set_duty_cycle)
{
	/* Set Timer Initial Value to 0 */
	TCNT0 = 0;

	/* Set Compare value */
	OCR0  = (255*set_duty_cycle)/100;

	/* Configure PB3/OC0 as output pin --> pin where the PWM signal is generated from MC */
	DDRB  = DDRB | (1<<PB3);

	/* Configure timer control register                                      *
	 * 1. Fast PWM mode FOC0=0                                               *
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1                                    *
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1  *
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0                               */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}
