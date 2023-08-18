/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 9- 7-2022   *******************
 *************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0            *((volatile u8*)0x53)
#define TCCR0_WGM00      6
#define TCCR0_WGM01      3

#define TCNT0            *((volatile u8*)0x52)

#define TIMSK            *((volatile u8*)0x59)
#define TIMSK_TOIE0      0

#define SREG             *((volatile u8*)0x5F)
#define SREG_I           7

#define TIMSK_OCIE		 1

#define TCCR0_CS00		 0
#define TCCR0_CS01		 1
#define TCCR0_CS02		 2

#define OCR0             *((volatile u8*)0x5C)

#endif /* TIMER_REGISTER_H_ */
