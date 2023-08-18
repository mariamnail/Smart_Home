/*
 * ADC_private.h
 *
 *  Created on: Sep 6, 2022
 *      Author: Omar Gamal
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADMUX		*((volatile u8*)0x27)
#define ADCSRA		*((volatile u8*)0x26)
#define ADCH		*((volatile u8*)0x25)
#define ADC_DATA	*((volatile u16*)0x24)

#define SFIOR		*((volatile u8*)0x50)

#endif /* ADC_PRIVATE_H_ */
