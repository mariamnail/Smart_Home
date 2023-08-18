/*
 * main1.c
 *
 *  Created on: Sep 22, 2022
 *      Author: Mo Salah
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/UART/UART_Interface.h"

#include "HAL/LCD/LCD_Config.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/FAN/FAN.h"
#include "HAL/LDR/LDR.h"
#include "HAL/DOOR/DOOR.h"
#include "APP/APP.h"

#include <util/delay.h>

void main(void)
{
	UART_voidConfigDir();
	UART_voidInit();

	ADC_voidInit();

	LCD_voidConfigDir();
	LCD_voidInit();

	TEMPFAN_Init();
	LDR_void_LED_ConfigDir();
	Servo_Init();

	u8 u = 0;
	u8 P = 0;
	u8 Trials = 2;

	if(UART_u8ReadData() == 'S')
{
		LCD_voidWriteString("Welcome To Smart");
		LCD_voidGoToXY(0,1);
		LCD_voidWriteString("Home System ^_^ ");
		_delay_ms(5000);
		LCD_voidSendCommand(0x01);
		UART_voidWriteData(Trials + 1 + '0');
		u = User();

while(P != CORRECT_PASSWORD)
{
		if (u == WRONG_USER)
		{
			if(Trials == 0)
			{
				LCD_voidSendCommand(0x01);
				LCD_voidWriteString(" SYSTEM LOCKED");
				Door_Close();
				_delay_ms(3000);
				break;
			}

			else
			{
				Trials = Trials - 1;
				UART_voidWriteData( Trials + 1 + '0');
				u = User();
			}
		}

		else if (u == CORRECT_USER)
		{
			P = Password();

			if (P == WRONG_PASSWORD)
			{
				if(Trials == 0)
				{
					LCD_voidSendCommand(0x01);
					LCD_voidWriteString(" SYSTEM LOCKED");
					Door_Close();
					_delay_ms(3000);
					break;
				}

				else
				{
					Trials = Trials - 1;
					UART_voidWriteData( Trials + '0');
				}
			}
		}
}

if(Trials > 0)
	{
		LCD_voidSendCommand(0x01);
		LCD_voidWriteString(" DOOR OPENED");
		_delay_ms(3000);
		LCD_voidSendCommand(0x01);
		Door_Open();
		_delay_ms(1000);

		while(1)
		{
			LDR_void_LED_CTRL();
			_delay_ms(1000);
			TEMP_FAN();
			_delay_ms(1000);
		}
	}
}
}
