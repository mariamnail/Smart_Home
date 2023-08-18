/****************************************************************/
/*************     	Author : Adel Khaled     ********************/
/*************		Date   : 13-7-2022		 ********************/
/*************		Version: V.01            ********************/
/****************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "util/delay.h"
#include "../../MCAL/DIO/DIO_Interface.h"

#include "LCD_Config.h"
#include "LCD_Interface.h"

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_RS_PIN,LOW);

	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_RW_PIN,LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);

	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_E_PIN,LOW);
}

void LCD_voidSendData(u8 Copy_u8Data)
{
	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_RS_PIN,HIGH);

	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_RW_PIN,LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Data);

	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_E_PIN,HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CRTL_PORT,LCD_E_PIN,LOW);
}

void LCD_voidInit(void)
{
	_delay_ms(35);
	/*-----------Send Command function Call-----------*/
	/*-------2 Lines with size (5x8) 0b00111100----- */
	LCD_voidSendCommand(0x3C);
//	LCD_voidSendCommand(0b00111000);

	/*----------NO Cursor with NO blink 0b00001100---*/
	LCD_voidSendCommand(0x0C);
//	LCD_voidSendCommand(0b00001100);

	/*-------------------clear Display--0b00000001----*/
	LCD_voidSendCommand(0x01);
}

void LCD_voidConfigDir(void)
{
	DIO_voidSetPortDirection(DIO_PORTC,OUTPUT_PORT);
	DIO_voidSetPinDirection(DIO_PORTD,LCD_RS_PIN ,OUTPUT_PIN);
	DIO_voidSetPinDirection(DIO_PORTD,LCD_RW_PIN ,OUTPUT_PIN);
	DIO_voidSetPinDirection(DIO_PORTD,LCD_E_PIN ,OUTPUT_PIN);
}

void LCD_voidWriteString(u8 *Copy_u8String)
{
	u8 i=0;
	while(Copy_u8String[i] != '\0')
	{
		LCD_voidSendData(Copy_u8String[i]);
		i++;
	}
}

void LCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRAM_Address;
	if(Copy_u8YPos == 0)
	{
		Local_u8DDRAM_Address = Copy_u8XPos;
	}else if(Copy_u8YPos == 1)
	{
		Local_u8DDRAM_Address = Copy_u8XPos + 0x40;
	}
	// Local_u8DDRAM_Address = Copy_u8XPos*Copy_u8YPos + 0x40;
	Local_u8DDRAM_Address = Local_u8DDRAM_Address + 128;

	LCD_voidSendCommand(Local_u8DDRAM_Address);
}

void LCD_voidWriteSpecialCharacter(u8 *Copy_u8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAM_Address = Copy_u8PatternNumber * 8;

	LCD_voidSendCommand(Local_u8CGRAM_Address+64);

	for(u8 Local_u8Counter=0; Local_u8Counter <8 ; Local_u8Counter++)
	{
		LCD_voidSendData(Copy_u8Pattern[Local_u8Counter]);
	}

	LCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	LCD_voidSendData(Local_u8CGRAM_Address);

}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	/*if(Copy_u32Number !=0)
	{
		LCD_voidWriteNumber(Copy_u32Number/10);
		LCD_voidSendData((Copy_u32Number%10) + 48);
	}*/
	u8 Local_u8BaseNumbers[10]={0};

	u8 Local_u8Counter=9;

	if(Copy_u32Number == 0)
	{
		LCD_voidSendData(48);
	}

	while(Copy_u32Number !=0)
	{
		Local_u8BaseNumbers[Local_u8Counter]= Copy_u32Number % 10;

		Copy_u32Number /= 10;
		Local_u8Counter--;
	}

	for(Local_u8Counter++ ; Local_u8Counter <10 ; Local_u8Counter++ )
	{

			LCD_voidSendData(Local_u8BaseNumbers[Local_u8Counter]+48);
	}
}







