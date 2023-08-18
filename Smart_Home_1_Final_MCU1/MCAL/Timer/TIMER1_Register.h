/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 9- 8-2022   *******************
 *************************************************************/

#ifndef TIMER1_REGISTER_H_
#define TIMER1_REGISTER_H_

#define TCCR1A            *((volatile u8*)0x4F)
#define TCCR1A_COM1A1     7
#define TCCR1A_COM1A0     6
#define TCCR1A_WGM11      1
#define TCCR1A_WgM10      0

#define TCCR1B            *((volatile u8*)0x4E)
#define TCCR1B_WGM13      4
#define TCCR1B_WGM12      3
#define TCCR1B_CS12       2
#define TCCR1B_CS11       1
#define TCCR1B_CS10       0

#define OCR1A             *((volatile u16*)0x4A)

#define ICR1              *((volatile u16*)0x46)

#endif /* TIMER1_REGISTER_H_ */
