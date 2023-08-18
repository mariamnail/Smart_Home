/*
 * FAN.c
 *
 *  Created on: Sep 20, 2022
 *      Author: Mo Salah
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/LCD/LCD_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#include <util/delay.h>

void TEMPFAN_Init()
{
	DIO_voidSetPinDirection(DIO_PORTA, PIN2, OUTPUT_PIN);
}

void TEMP_FAN()
{
	u16 ADC_val_1 = ADC_u16Read(ADC1);
	u32 Temp = (ADC_val_1 * 4.88) / 10;

	if(Temp > 26){
		DIO_voidSetPinValue(DIO_PORTA, PIN2, HIGH);
		LCD_voidGoToXY(15,0);
		LCD_voidSendData('M');}

	else{
		DIO_voidSetPinValue(DIO_PORTA, PIN2, LOW);
		LCD_voidGoToXY(15,0);
		LCD_voidSendData(' ');}

	_delay_ms(20);
//	LCD_voidSendCommand(0x01);
	LCD_voidGoToXY(0,0);
	LCD_voidWriteString("TEMP=");
	LCD_voidGoToXY(5,0);
	LCD_voidWriteNumber(Temp);
}
