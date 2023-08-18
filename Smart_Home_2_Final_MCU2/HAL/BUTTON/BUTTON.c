/*
 * BUTTON.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mo Salah
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "BUTTON.h"

void Button_Init()
{
	/*	Activate Internal Pull Up Connection */
	DIO_voidSetPinDirection(BUTTON_PORT, BUTTON_PIN, INPUT_PIN);
	DIO_voidSetPinValue(BUTTON_PORT, BUTTON_PIN, HIGH);
}

u8 Button_State()
{
	if( DIO_u8GetPinValue(BUTTON_PORT, BUTTON_PIN) == HIGH)
	{
		return BUTTON_NOT_PRESSED;
	}

	else
	{
		return BUTTON_PRESSED;
	}
}
