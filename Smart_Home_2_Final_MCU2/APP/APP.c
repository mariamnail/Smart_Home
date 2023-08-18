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

#include "../HAL/KeyPad/KeyPad_interface.h"

#include "APP.h"

void SendDataFromKeyPad()
{
	u8 key = KeyPad_u8GetPressed();

	if (key >= '0' && key <= '9')
	{
		UART_voidWriteData(key);
	}
}

