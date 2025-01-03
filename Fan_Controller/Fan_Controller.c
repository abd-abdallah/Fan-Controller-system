/*
 * app.c
 *
 *  Created on: Oct 9, 2022
 *      Author: AbdElRuhman
 */

#include "Fan_Controller.h"

int main(void)
{
	uint8 temp;
	/* select the configuration of ADC
	 * voltage Reference  Selection
	 * prescaler Selection
	 */
	ADC_ConfigType config;
	config.ref_volt=Internal_2560mV;
	config.prescaler=pre8;


	LCD_init(); /* initialize LCD driver */
	ADC_init(&config); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor driver */


	LCD_displayString("FAN IS ON ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");
	while(1)
	{

		temp = LM35_getTemperature();

		if(temp >= 30)
		{
			LCD_displayStringRowColumn(0,7,"ON ");
			LCD_moveCursor(1,7);
			if(temp >= 120)
			{
				LCD_intgerToString(temp);
				DcMotor_Rotate(clockwise,255);
			}
			else if (temp>=90)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
				DcMotor_Rotate(clockwise,192);
			}
			else if (temp>=60)
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
				DcMotor_Rotate(clockwise,128);
			}
			else
			{
				LCD_intgerToString(temp);
				LCD_displayCharacter(' ');
				DcMotor_Rotate(clockwise,64);
			}

		}
		else
		{
			LCD_displayStringRowColumn(0,7,"OFF");
			LCD_moveCursor(1,7);
			LCD_intgerToString(temp);
			LCD_displayCharacter(' ');
			DcMotor_Rotate(off,0);
		}

	}
}



