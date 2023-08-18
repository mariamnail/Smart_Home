/*
 * KeyPad_config.h
 *
 *  Created on: Sep 1, 2022
 *      Author: Mo Salah
 */

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_PORT			DIO_PORTA

#define KEYPAD_ROW1_PIN		0
#define KEYPAD_ROW2_PIN		1
#define KEYPAD_ROW3_PIN		2
#define KEYPAD_ROW4_PIN		3

#define KEYPAD_COL1_PIN		4
#define KEYPAD_COL2_PIN		5
#define KEYPAD_COL3_PIN		6
#define KEYPAD_COL4_PIN		7

const u8 KeyPad_Char [16] = {
		'7', '8', '9', '/',
		'4', '5', '6', '*',
		'1', '2', '3', '-',
		'C', '0', '=', '+'
};

#endif /* KEYPAD_CONFIG_H_ */
