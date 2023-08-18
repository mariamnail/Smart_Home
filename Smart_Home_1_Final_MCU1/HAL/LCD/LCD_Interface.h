/*************************************************************
 ****************** Author : Adel Khaled *********************
 ****************** Date   : 20-7-2022   *********************
 *************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

void LCD_voidSendCommand(u8 Copy_u8Command);

void LCD_voidSendData(u8 Copy_u8Data);

void LCD_voidInit(void);

void LCD_voidConfigDir(void);

void LCD_voidWriteString(u8 * Copy_u8String);

void LCD_voidGoToXY(u8 Copy_u8X , u8 Copy_u8Y);

void LCD_voidWriteNumber(u32 Copy_u32Number);

void LCD_voidWriteSpecialCharacter(u8 * Copy_u8Pattern ,u8 Copy_u8NoPattern, u8 Copy_u8X , u8 Copy_u8Y);

#endif
