/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 9- 7-2022   *******************
 *************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_Register.h"
#include "TIMER_Interface.h"
#include <stddef.h>

void (*Global_pvCallbackFuncTimer0) (void) = NULL;
void (*Global_pvCallbackFuncCTC0) (void) = NULL;

void Timer_voidTimer0Init()
{
	/*Select normal mode */
	CLR_BIT(TCCR0 , TCCR0_WGM00);
	CLR_BIT(TCCR0 , TCCR0_WGM01);

	/*Select prescaler 8 */
	TCCR0 &= 0b11111000;
	TCCR0 |= 0b00000010;

	/*Set preload value*/
	TCNT0 = 192;

	/*Enable Timer interrupt*/
	SET_BIT(TIMSK , TIMSK_TOIE0);
}

void Timer_voidSetPreload(u8 Copy_u8Preload)
{
	TCNT0 = Copy_u8Preload;
}

void Timer_voidCallBackTimer0(void (*Copy_pvCallBack) (void))
{
	Global_pvCallbackFuncTimer0 = Copy_pvCallBack;
}
void GIE_voidGlobalEnable()
{
	/*Enable the global Interrupt */
	SET_BIT(SREG , SREG_I);
}


void Timer_voidCTCInit()
{
	/*select normal mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00) ;
	SET_BIT(TCCR0, TCCR0_WGM01) ;

	/*Select PRE Scalep 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);

	/*set Compare values*/
	OCR0 = 200;

	/*Enable timer Interrupt*/
	SET_BIT (TIMSK, TIMSK_OCIE);
}

void Timer_voidCallBackCTC0(void(*Copy_pvCallBack)(void))
{
	Global_pvCallbackFuncCTC0 = Copy_pvCallBack;
}

void __vector_11 (void) __attribute__ ((signal));
void __vector_11 (void)
{
	if(Global_pvCallbackFuncTimer0 != NULL)
	{
		Global_pvCallbackFuncTimer0(); /*Calling*/
	}
}

void __vector_10 (void) __attribute__ ((signal));
void __vector_10 (void)
{
	if (Global_pvCallbackFuncCTC0 != NULL)
	{
		Global_pvCallbackFuncCTC0();
	}
}
