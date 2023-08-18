/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 05-09-2022   ******************
 *************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_Register.h"
#include "EXTI_Interface.h"


void EXTI_voidINT0Init()
{
	/*Set the sense control for falling edge for INT0 */
	CLR_BIT(MCUCR , MCUCR_ISC00);
	SET_BIT(MCUCR , MCUCR_ISC01);

	/*Enable INT0*/
	SET_BIT(GICR , GICR_INT0);
}

void EXTI_voidGlobalEnable()
{
	/*Enable the Global Interrupt*/
	SET_BIT(SREG , SREG_I);
}
void EXTI_voidGlobalDisable()
{
	/*Disable the Global Interrupt*/
	CLR_BIT(SREG , SREG_I);
}
