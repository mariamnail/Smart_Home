/*
 * SevenSegment.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mo Salah
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SevenSegment.h"

void SevenSegment_Init()
{
	DIO_voidSetPortDirection(DIO_PORTC, OUTPUT_PORT);
}

//seven segment Numbers
void SevenSegment_Number3(){
	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN4, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN5, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, LOW);
}
void SevenSegment_Number2(){
	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN5, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, LOW);
}

void SevenSegment_Number1(){
	DIO_voidSetPinValue(DIO_PORTC, PIN0, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN3, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN4, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN5, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, LOW);
}

void SevenSegment_Number0(){
	DIO_voidSetPinValue(DIO_PORTC, PIN0, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN1, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN2, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN3, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN4, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN5, HIGH);
	DIO_voidSetPinValue(DIO_PORTC, PIN6, LOW);
	DIO_voidSetPinValue(DIO_PORTC, PIN7, LOW);
}
