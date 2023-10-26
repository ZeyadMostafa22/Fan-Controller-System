/*
 * DC_motor.c
 *
 *  Created on: Oct 13, 2023
 *      Author: Zeyad Mostafa
 */


#include "DC_motor.h"
#include "gpio.h"
#include "PWM.h"

void DcMotor_Init(void)
{
	/* setup the direction for the two motor pins */
  GPIO_setupPinDirection( PORTB_ID, PIN0_ID,PIN_OUTPUT);
  GPIO_setupPinDirection( PORTB_ID, PIN1_ID,PIN_OUTPUT);

   /*Stop the DC-Motor at the beginning*/
  GPIO_writePin( PORTB_ID, PIN0_ID,LOGIC_LOW);
  GPIO_writePin( PORTB_ID,  PIN1_ID, LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{

	if(state == STOP)
	{
		   /*Stop the DC-Motor*/
		  GPIO_writePin( PORTB_ID, PIN0_ID,LOGIC_LOW);
		  GPIO_writePin( PORTB_ID,  PIN1_ID, LOGIC_LOW);
	}
	else if(state == CW)
	{
		   /* the DC-Motor Rotate clockwise*/
		  GPIO_writePin( PORTB_ID, PIN0_ID,LOGIC_LOW);
		  GPIO_writePin( PORTB_ID,  PIN1_ID, LOGIC_HIGH);
	}
	else if(state == A_CW)
	{
		 /* the DC-Motor Rotate anti clockwise*/
		  GPIO_writePin( PORTB_ID, PIN0_ID,LOGIC_HIGH);
		  GPIO_writePin( PORTB_ID,  PIN1_ID, LOGIC_LOW);
	}

	/*send the speed to the pwm driver*/

		PWM_Timer0_Start(speed);



}
