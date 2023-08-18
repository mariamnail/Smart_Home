/*
 * KeyPad_program.c
 *
 *  Created on: Sep 1, 2022
 *      Author: Mo Salah
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KeyPad_interface.h"
#include "KeyPad_config.h"
#include "KeyPad_private.h"
#include <util/delay.h>

u8 Rows[4] = {KEYPAD_ROW1_PIN, KEYPAD_ROW2_PIN, KEYPAD_ROW3_PIN, KEYPAD_ROW4_PIN};
u8 Col[4]  = {KEYPAD_COL1_PIN, KEYPAD_COL2_PIN, KEYPAD_COL3_PIN, KEYPAD_COL4_PIN};

void KeyPad_voidInit(void)
{
	for(u8 RowCounter = 0; RowCounter<4; RowCounter++)
	{
		DIO_voidSetPinDirection(KEYPAD_PORT, Rows[RowCounter], OUTPUT_PIN);
		DIO_voidSetPinValue(KEYPAD_PORT, Rows[RowCounter], HIGH);
	}

	for(u8 ColCounter = 0; ColCounter<4; ColCounter++)
	{
		DIO_voidSetPinDirection(KEYPAD_PORT, Col[ColCounter], INPUT_PIN);
		DIO_voidSetPinValue(KEYPAD_PORT, Col[ColCounter], HIGH);
	}
}

u8 KeyPad_u8GetPressed(void)
{
	u8 Local_u8Col, x = KEYPAD_NOT_PRESSED;
	for(u8 RowCounter = 0; RowCounter<4; RowCounter++)
	{
		KeyPad_voidSelectLine(Rows[RowCounter]);
		Local_u8Col = KeyPad_u8ReadButton(Rows[RowCounter]);
		if(Local_u8Col != KEYPAD_NOT_PRESSED)
		{
			x = (RowCounter * 4) + Local_u8Col;
			_delay_ms(2);
			return KeyPad_Char[x];
		}
	}
	return KEYPAD_NOT_PRESSED;
}

u8 KeyPad_u8ReadButton(u8 Copy_u8Line)
{
	for(u8 ColCounter = 0; ColCounter<4; ColCounter++)
	{
		if(DIO_u8GetPinValue(KEYPAD_PORT, Col[ColCounter]) == LOW){
			DIO_voidSetPinValue(KEYPAD_PORT, Copy_u8Line, HIGH);
			return ColCounter;
		}
	}
			DIO_voidSetPinValue(KEYPAD_PORT, Copy_u8Line, HIGH);
			return KEYPAD_NOT_PRESSED;
}

void KeyPad_voidSelectLine(u8 Copy_u8Line)
{
	DIO_voidSetPinValue(KEYPAD_PORT, Copy_u8Line, LOW);
}
