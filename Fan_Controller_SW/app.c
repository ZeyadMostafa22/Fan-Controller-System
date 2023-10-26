/*
 * app.c
 *
 *  Created on: Oct 12, 2023
 *      Author: Zeyad Mostafa
 */

#include <avr\io.h>
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "DC_motor.h"

int main(void)
{

	uint8 temp;
	ADC_ConfigType ADC_Configurations = {INTERNAL,F_CPU_8};
	/* Enable interrupts by setting I-bit */
	//SREG  |= (1<<7);
	                     /* initialize LCD driver */

	LCD_init();
	DcMotor_Init();/* initialize ADC driver */
	ADC_init(&ADC_Configurations);
	//LCD_displayString("FAN IS OFF");
    LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");

	while(1)
	{
		temp = LM35_getTemperature();


		if(temp < 30 )
		{   LCD_moveCursor(0,0);
			LCD_displayString("FAN IS OFF");
			DcMotor_Rotate(STOP,0);
		}
		else if(temp >= 30 && temp<60 )
		{
			LCD_moveCursor(0,0);
		    LCD_displayString("FAN IS ON");
		    LCD_displayCharacter(' ');
			DcMotor_Rotate(	CW ,75);
		}

		else if(temp >= 60 && temp <90 )
		{
			LCD_moveCursor(0,0);
		    LCD_displayString("FAN IS ON");
		    LCD_displayCharacter(' ');
			DcMotor_Rotate(	CW ,120);
		}
		else if(temp >= 90 && temp < 120 )
		{
			LCD_moveCursor(0,0);
		    LCD_displayString("FAN IS ON");
		    LCD_displayCharacter(' ');
			DcMotor_Rotate(	CW ,190);
		}
		else
		{
			LCD_moveCursor(0,0);
		    LCD_displayString("FAN IS ON");
		    LCD_displayCharacter(' ');
			DcMotor_Rotate(	CW ,255);
		}

		LCD_moveCursor(1,7);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_displayCharacter(' ');
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */

		}



	}


}
