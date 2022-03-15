/*-------------------------------------------------------
 * [FILE NAME]: PROJECT_3.c
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 14/10/2021
 *
 * [DESCRIPTION]: source file for the third project
 -------------------------------------------------------*/

#include "dc_motor.h"
#include "LM35_TEMP_SENSOR.h"
#include "lcd.h"

/*
 * Description:
 * it controls the fan speed according to the temperature value
 * and displays the fan status and the temperature on the LCD through the following sequence:
 *
 *	a. If the temperature is less than 30C turn off the fan.
 *
 *	b. If the temperature is greater than or equal 30C turn on the fan with 25% of its
 *	maximum speed.
 *
 *	c. If the temperature is greater than or equal 60C turn on the fan with 50% of its
 *	maximum speed.
 *
 *	d. If the temperature is greater than or equal 90C turn on the fan with 75% of its
 *	maximum speed.
 *
 *	e. If the temperature is greater than or equal 120C turn on the fan with 100% of its
 *	maximum speed.
 */

int main(void)
{
	uint8 temp = 0 ;/* a variable to save the value received from the LM35 sensor */

	/* initializing the LCD */
	LCD_init();

	/* initializing the DcMotor */
	DcMotor_Init();

	/* displaying the following sentence once as it won't be updated */
	LCD_displayStringRowColumn(1, 0, "Temp =     c");

	while(1)
	{
		/* getting the value measured by the LM35 sensor */
		temp = LM35_getTemperature();

		if(temp >= 120)
		{
			/* displaying the fan status according to the corresponding temperature */
			LCD_displayStringRowColumn(0, 0,"Fan is ON");

			/* moving the cursor to the position of displaying the temperature value */
			LCD_moveCursor(1 , 7);

			/* since we are displaying the temperature value which is number then we need the     *
			 * "LCD_intgerToString" function which converts the number to the corresponding char  *
			 * then displays it.                                                                  */
			LCD_intgerToString(temp);

			/* the following step is a precaution as if we reached a temperature value consisting of    *
			 * 3 digits then when we step down to reach a 2-digit value there will be a bit still from  *
			 * the previous 3-digit value so we need to over write a space on it.                       */
			LCD_displayCharacter(' ');

			/* calling the "DcMotor_Rotate" function which takes which state is required to set it up *
			 * and the required speed.                                                                */
			DcMotor_Rotate(CW , 100);
		}
		else if(temp >= 90)
		{
			/* displaying the fan status according to the corresponding temperature */
			LCD_displayStringRowColumn(0, 0,"Fan is ON ");

			/* moving the cursor to the position of displaying the temperature value */
			LCD_moveCursor(1 , 7);

			/* since we are displaying the temperature value which is number then we need the     *
			 * "LCD_intgerToString" function which converts the number to the corresponding char  *
			 * then displays it.                                                                  */
			LCD_intgerToString(temp);

			/* the following step is a precaution as if we reached a temperature value consisting of    *
			 * 3 digits then when we step down to reach a 2-digit value there will be a bit still from  *
			 * the previous 3-digit value so we need to over write a space on it.                       */
			LCD_displayCharacter(' ');

			/* calling the "DcMotor_Rotate" function which takes which state is required to set it up *
			 * and the required speed.                                                                */
			DcMotor_Rotate(CW , 75);
		}
		else if(temp >= 60)
		{
			/* displaying the fan status according to the corresponding temperature */
			LCD_displayStringRowColumn(0, 0,"Fan is ON ");

			/* moving the cursor to the position of displaying the temperature value */
			LCD_moveCursor(1 , 7);

			/* since we are displaying the temperature value which is number then we need the     *
			 * "LCD_intgerToString" function which converts the number to the corresponding char  *
			 * then displays it.                                                                  */
			LCD_intgerToString(temp);

			/* the following step is a precaution as if we reached a temperature value consisting of    *
			 * 3 digits then when we step down to reach a 2-digit value there will be a bit still from  *
			 * the previous 3-digit value so we need to over write a space on it.                       */
			LCD_displayCharacter(' ');

			/* calling the "DcMotor_Rotate" function which takes which state is required to set it up *
			 * and the required speed.                                                                */
			DcMotor_Rotate(CW , 50);
		}
		else if(temp >= 30)
		{
			/* displaying the fan status according to the corresponding temperature */
			LCD_displayStringRowColumn(0, 0,"Fan is ON ");

			/* moving the cursor to the position of displaying the temperature value */
			LCD_moveCursor(1 , 7);

			/* since we are displaying the temperature value which is number then we need the     *
			 * "LCD_intgerToString" function which converts the number to the corresponding char  *
			 * then displays it.                                                                  */
			LCD_intgerToString(temp);

			/* the following step is a precaution as if we reached a temperature value consisting of    *
			 * 3 digits then when we step down to reach a 2-digit value there will be a bit still from  *
			 * the previous 3-digit value so we need to over write a space on it.                       */
			LCD_displayCharacter(' ');

			/* calling the "DcMotor_Rotate" function which takes which state is required to set it up *
			 * and the required speed.                                                                */
			DcMotor_Rotate(CW , 25);
		}
		else
		{
			/* displaying the fan status according to the corresponding temperature */
			LCD_displayStringRowColumn(0 , 0,"Fan is OFF");

			/* moving the cursor to the position of displaying the temperature value */
			LCD_moveCursor(1 , 7);

			/* since we are displaying the temperature value which is number then we need the     *
			 * "LCD_intgerToString" function which converts the number to the corresponding char  *
			 * then displays it.                                                                  */
			LCD_intgerToString(temp);

			/* the following step is a precaution as if we reached a temperature value consisting of    *
			 * 3 digits then when we step down to reach a 2-digit value there will be a bit still from  *
			 * the previous 3-digit value so we need to over write a space on it.                       */
			LCD_displayCharacter(' ');

			/* calling the "DcMotor_Rotate" function which takes which state is required to set it up *
			 * and the required speed.                                                                */
			DcMotor_Rotate(STOP , 0);
		}
	}
}
