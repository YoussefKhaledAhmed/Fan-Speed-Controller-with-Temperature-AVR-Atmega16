/*-------------------------------------------------------
 * [FILE NAME]: adc.c
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 2/10/2021
 *
 * [DESCRIPTION]: source file for AVR ADC driver
 -------------------------------------------------------*/

#include "adc.h"
#include "common_macros.h"
#include <avr/io.h>


void ADC_init(const ADC_ConfigType * Config_Ptr)
{

	/*
	 *  initialization of ADMUX register
	 * the first #if is for choosing which mode of the reference voltage
	 * so, what should be done is to set in the adc.h the mode you want by one
	 */
	if ( Config_Ptr -> ref_volt == 3 )/* if the internal 2.65v reference voltage is set */
	{
		/*
		 * the second #if is for checking the ADC left adjust result
		 * so, it should be put by zero if no shift will be applied on the ADC register
		 * and one if shift is applied on the ADC register
		 */
#if ADC_LEFT_ADJUST_RESULT == OFF
		/* For turning off the "ADC left adjust result" ADLAR bit is cleared */
		/* REFS0 & REFS1 are set to 1 for enabling the internal 2.65v mode   */
		ADMUX = (1 << REFS0) | (1 << REFS1);
#else
		/* For turning on the "ADC left adjust result" ADLAR bit is set by 1 */
		ADMUX = (1<<ADLAR) | (1 << REFS0) | (1 << REFS1);
#endif
	}
	else if ((Config_Ptr -> ref_volt) == 1)/* AVCC with external capacitor at AREF pin */
	{
#if ADC_LEFT_ADJUST_RESULT == OFF
		/* For turning off the "ADC left adjust result" ADLAR bit is cleared */
		/* REFS0 is set to 1 & REFS1 is cleared for enabling the AVCC mode   */
		ADMUX = (1 << REFS0);
#else
		/* For turning on the "ADC left adjust result" ADLAR bit is set by 1 */
		ADMUX = (1<<ADLAR) | (1 << REFS0);
#endif
	}
	else if ((Config_Ptr -> ref_volt) == 0) /*turning off the internal reference voltage*/
	{
#if ADC_LEFT_ADJUST_RESULT == OFF
		/* For turning off the "ADC left adjust result" ADLAR bit is cleared */
		/* REFS0 & REFS1 are both cleared for Disabling the internal 2.65v mode   */
		ADMUX = 0 ;
#else
		/* For turning on the "ADC left adjust result" ADLAR bit is set by 1 */
		ADMUX = (1<<ADLAR);
#endif
	}
	else/* no action is taken */
	{
#if ADC_LEFT_ADJUST_RESULT == OFF
		/* For turning off the "ADC left adjust result" ADLAR bit is cleared */
		/* REFS0 is cleared & REFS1 is set by 1 for Reserved mode(i.e. no action is taken) */
		ADMUX = (1 << REFS1);
#else
		/* For turning on the "ADC left adjust result" ADLAR bit is set by 1 */
		ADMUX = (1<<ADLAR) | (1 << REFS1);
#endif
	}

		/*
		 * initializing ADC status and control register (ADCSRA)
		 * the first #if is for enabling or disabling ADC_AUTO_TRIGGER_ENABLE by 1 or 0 respectively
		 * the second #if is for enabling or disabling ADC_INTERRUPT by 1 or 0 respectively
		 */
#if ADC_AUTO_TRIGGER_ENABLE == OFF

	#if ADC_INTERRUPT_ENABLE == OFF
		/* setting the pre-scaler that is passed by address through the pointer to structure config_ptr  */
		ADCSRA = Config_Ptr -> prescaler | (1<<ADEN); /* ADEN is set to enable the ADC */
	#else
		/* ADIE is set here for enabling ADC interrupt */
		ADCSRA = Config_Ptr -> prescaler | (1<<ADEN) | (1<<ADIE);
	#endif

#else
		/* this for choosing the auto trigger mode by its number from 0:7 by changing it in the adc.h file*/
		SFIOR = (AUTO_TRIGGER_MODE << 4);
	#if ADC_INTERRUPT_ENABLE == OFF
		/* ADEN is set to enable the ADC */
		/* ADATE bit is for enabling the auto trigger mode */
		ADCSRA = Config_Ptr -> prescaler | (1<<ADEN) | (1<<ADATE);
	#else
		/* ADIE is set here for enabling ADC interrupt */
		ADCSRA = Config_Ptr -> prescaler | (1<<ADEN) | (1<<ADATE) | (1<<ADIE);
	#endif

#endif

}

uint16 ADC_readChannel(uint8 ch_num)
{
	/* ADMUX & 0xE0 to save the most significant 3 bits (REFS1 REFS0 ADLAR)  *
	 * then operating the " | " with the channel number to set which channel *
	 * of the 8 channels will work.											 */
	ADMUX = (ADMUX & 0xE0) | (ch_num & 0x07);

	/* ADSC bit is set for starting the conversion */
	SET_BIT(ADCSRA , ADSC);

	/* waiting till the conversion is done */
	while(!(ADCSRA & (1<<ADIF)));

	/* ADIF is the ADC interrupt flag which is cleared when the interrupt is done since    *
	 * we are working with pooling technique then we should clear it by ourselves through  *
	 * writing 1 in this bit.                                                              */
	SET_BIT(ADCSRA , ADIF);

	/* then after doing the conversion we need to return the converted data *
	 * which exists in the ADC register.                                    */
	return ADC ;
}













