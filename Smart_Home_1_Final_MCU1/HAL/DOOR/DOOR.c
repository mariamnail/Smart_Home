/*
 * DOOR.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mo Salah
 */

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/Timer/TIMER1_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "DOOR.h"

#include <util/delay.h>


void Servo_Init()
{
	DIO_voidSetPinDirection(SERVO_PORT , SERVO_PIN , OUTPUT_PIN);
	Timer1_voidInit();
	_delay_ms(1);
}

void Door_Open()
{
	for(u16 Local_u16Index = 751 ; Local_u16Index <= 2000 ; Local_u16Index++)
	{
		Timer1_voidSetCompareMatchValueChannalA(Local_u16Index);
		_delay_ms(1);
	}
}

void Door_Close()
{
	for(u16 Local_u16Index = 2000 ; Local_u16Index >= 750 ; Local_u16Index--)
	{
		Timer1_voidSetCompareMatchValueChannalA(Local_u16Index);
		_delay_ms(1);
	}
}
