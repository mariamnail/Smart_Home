/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 05-09-2022   ******************
 *************************************************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR             *((volatile u8*)0x55)
#define MCUCR_ISC00       0
#define MCUCR_ISC01       1
#define MCUCR_ISC10       2
#define MCUCR_ISC11       3

#define MCUCSR            *((volatile u8*)0x54)
#define MCUCSR_ISC2       6

#define GICR              *((volatile u8*)0x5B)
#define GICR_INT2         5
#define GICR_INT0         6
#define GICR_INT1         7

#define GIFR              *((volatile u8*)0x5A)
#define GIFR_INTF2        5
#define GIFR_INTF0        6
#define GIFR_INTF1        7

#define SREG              *((volatile u8*)0x5F)
#define SREG_I            7

#endif /* EXTI_REGISTER_H_ */
