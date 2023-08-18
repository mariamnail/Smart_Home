/*
 * LDR.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mo Salah
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include "../LCD/LCD_config.h"
#include "../LCD/LCD_interface.h"

#include "LDR.h"

void LDR_void_LED_ConfigDir()
{
	DIO_voidSetPortDirection(DIO_PORTB, OUTPUT_PORT);
}

void LDR_void_LED_CTRL()
{
	u16 ADC_val = ADC_u16Read(ADC0);

	if (ADC_val >= 896)
	{
		DIO_voidSetPortValue(DIO_PORTB, 0xFF);

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('8');
	}

	else if (ADC_val >= 768 && ADC_val <= 896)
	{
		for(u8 i = 0; i<7; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN0 + i, HIGH);
		}
		DIO_voidSetPinValue(DIO_PORTB, PIN7, LOW);

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('7');

	}

	else if (ADC_val >= 640 && ADC_val <= 768)
	{
		for(u8 i = 0; i<6; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN0 + i, HIGH);
		}
		DIO_voidSetPinValue(DIO_PORTB, PIN6, LOW);
		DIO_voidSetPinValue(DIO_PORTB, PIN7, LOW);

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('6');

	}

	else if (ADC_val >= 512 && ADC_val <= 640)
	{
		for(u8 i = 0; i<5; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN0 + i, HIGH);
		}
		DIO_voidSetPinValue(DIO_PORTB, PIN5, LOW);
		DIO_voidSetPinValue(DIO_PORTB, PIN6, LOW);
		DIO_voidSetPinValue(DIO_PORTB, PIN7, LOW);

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('5');
	}

	else if (ADC_val >= 384 && ADC_val <= 512)
	{
		for(u8 i = 0; i<4; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN0 + i, HIGH);
		}

		for(u8 i = 0; i<4; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN4 + i, LOW);
		}

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('4');

	}

	else if (ADC_val >= 256 && ADC_val <= 384)
	{
		for(u8 i = 0; i<3; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN0 + i, HIGH);
		}

		for(u8 i = 0; i<5; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN3 + i, LOW);
		}

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('3');
	}

	else if (ADC_val >= 128 && ADC_val <= 256)
	{
		DIO_voidSetPinValue(DIO_PORTB, PIN0, HIGH);
		DIO_voidSetPinValue(DIO_PORTB, PIN1, HIGH);

		for(u8 i = 0; i<6; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN2 + i, LOW);
		}

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('2');
	}

	else if (ADC_val >= 64 && ADC_val <= 128)
	{
		DIO_voidSetPinValue(DIO_PORTB, PIN0, HIGH);
		for(u8 i = 0; i<7; i++)
		{
			DIO_voidSetPinValue(DIO_PORTB, PIN1 + i, LOW);
		}

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('1');
	}

	else
	{
		DIO_voidSetPortValue(DIO_PORTB, 0x00);

		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("ON-LEDs=");
		LCD_voidSendData('0');
	}
}
