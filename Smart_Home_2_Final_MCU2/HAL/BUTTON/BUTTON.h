/*
 * BUTTON.h
 *
 *  Created on: Sep 23, 2022
 *      Author: Mo Salah
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

#define BUTTON_PORT		DIO_PORTD
#define BUTTON_PIN		PIN2

#define	BUTTON_PRESSED		0
#define	BUTTON_NOT_PRESSED	1

void Button_Init();

u8 Button_State();

#endif /* HAL_BUTTON_BUTTON_H_ */
