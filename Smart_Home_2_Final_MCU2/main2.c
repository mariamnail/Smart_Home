/*
 * main2.c
 *
 *  Created on: Sep 23, 2022
 *      Author: Mo Salah
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/External_Interrupt/EXTI_Interface.h"
#include "MCAL/UART/UART_Interface.h"

#include "HAL/KeyPad/KeyPad_interface.h"
#include "HAL/Seven_Segment/SevenSegment.h"
#include "HAL/BUTTON/BUTTON.h"

#include <util/delay.h>

#include "APP/APP.h"

void main(void)
{
	UART_voidConfigDir();
	UART_voidInit();

	EXTI_voidGlobalEnable();
	EXTI_voidINT0Init();

	Button_Init();
	SevenSegment_Init();
	KeyPad_voidInit();

	static u8 num;

	while(1)
	{
		num = UART_u8ReadData();

		while(num)
		{
			if (num == '0')
			{
				SevenSegment_Number0();
			}

			else if (num == '1')
			{
				SevenSegment_Number1();
				SendDataFromKeyPad();
				_delay_ms(1500);
			}

			else if (num == '2')
			{
				SevenSegment_Number2();
				SendDataFromKeyPad();
				_delay_ms(1500);
			}

			else if (num == '3')
			{
				SevenSegment_Number3();
				SendDataFromKeyPad();
				_delay_ms(1500);
			}
		}

/***************************************************************/
/*		while (num == '0')
		{
			SevenSegment_Number0();
		}

		while (num == '1')
		{
			SevenSegment_Number1();
			SendDataFromKeyPad();
			_delay_ms(1500);
		}

		while (num == '2')
		{
			SevenSegment_Number2();
			SendDataFromKeyPad();
			_delay_ms(1500);
		}

		while (num == '3')
		{
			SevenSegment_Number3();
			SendDataFromKeyPad();
			_delay_ms(1500);
		}*/

/**************************************************************/
		/*		switch(num)
				{
				case '0':
					SevenSegment_Number0();
					break;

				case '1':
					SevenSegment_Number1();
					SendDataFromKeyPad();
					_delay_ms(1500);
					break;

				case '2':
					SevenSegment_Number2();
					SendDataFromKeyPad();
					_delay_ms(1500);
					break;

				case '3':
					SevenSegment_Number3();
					SendDataFromKeyPad();
					_delay_ms(1500);
					break;
				}*/

	}
}


void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	UART_voidWriteData('S');
}
