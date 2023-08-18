/*
 * APP.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mo Salah
 */

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/UART/UART_Interface.h"

#include "../HAL/LCD/LCD_Config.h"
#include "../HAL/LCD/LCD_Interface.h"

#include "APP.h"

#include <util/delay.h>
#include <stddef.h>

u8 USERNAME[] = {'1', '2', '3', '4'};
u8 PASSWORD[] = {'1', '2', '3', '4'};

u8 User()
{
	u8 USER[4] = {0};

	LCD_voidSendCommand(0x01);
	LCD_voidWriteString(" Enter USER:");

	for(u8 LocalCounter_Chars = 0; LocalCounter_Chars < 4; LocalCounter_Chars++)
	{
		USER[LocalCounter_Chars] = UART_u8ReadData();
		LCD_voidGoToXY(LocalCounter_Chars + 1 ,1);
		LCD_voidSendData(USER[LocalCounter_Chars]);
	}

	/*Check the user*/
	for(u8 LocalCounter_Chars = 0; LocalCounter_Chars < 4; LocalCounter_Chars++)
	{
		if( USER[LocalCounter_Chars] != USERNAME[LocalCounter_Chars] )
		{
			LCD_voidSendCommand(0x01);
			LCD_voidWriteString(" WRONG USER!");
			_delay_ms(2000);
			return WRONG_USER;
		}
	}
	return CORRECT_USER;
}

u8 Password()
{
	u8 PASS[4] = {0};

	LCD_voidSendCommand(0x01);
	LCD_voidWriteString(" Enter Password:");

	for(u8 LocalCounter_Chars = 0; LocalCounter_Chars < 4; LocalCounter_Chars++)
	{
	 PASS[LocalCounter_Chars] = UART_u8ReadData();

	 LCD_voidGoToXY(LocalCounter_Chars + 1,1);
	 LCD_voidSendData(PASS[LocalCounter_Chars]);
	 _delay_ms(1000);
	 LCD_voidGoToXY(LocalCounter_Chars + 1,1);
	 LCD_voidSendData('*');
	}

	/*Check the Password*/
	for(u8 LocalCounter_Chars = 0; LocalCounter_Chars < 4; LocalCounter_Chars++)
	{
		if( PASS[LocalCounter_Chars] != PASSWORD[LocalCounter_Chars] )
		{
			LCD_voidSendCommand(0x01);
			LCD_voidWriteString(" WRONG PASSWORD!");
			_delay_ms(2000);
			return WRONG_PASSWORD;
		}
	}

	return CORRECT_PASSWORD;
}
