/*
 * DOOR.h
 *
 *  Created on: Sep 22, 2022
 *      Author: Mo Salah
 */

#ifndef HAL_DOOR_DOOR_H_
#define HAL_DOOR_DOOR_H_

#define	SERVO_PIN	PIN5
#define SERVO_PORT	DIO_PORTD

void Servo_Init();

void Door_Open();

void Door_Close();

#endif /* HAL_DOOR_DOOR_H_ */
