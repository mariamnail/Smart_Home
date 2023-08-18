/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 9- 8-2022   *******************
 *************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER1_Register.h"
#include "TIMER1_Interface.h"

void Timer1_voidInit()
{
	/*Select fast PWM non inverted */
	CLR_BIT(TCCR1A , TCCR1A_COM1A0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);

	/*Select mode 14 */
	CLR_BIT(TCCR1A , TCCR1A_WgM10);
	SET_BIT(TCCR1A , TCCR1A_WGM11);

	SET_BIT(TCCR1B , TCCR1B_WGM12);
	SET_BIT(TCCR1B , TCCR1B_WGM13);

	/*Select prescaler 8 */
	CLR_BIT(TCCR1B , TCCR1B_CS10);
	SET_BIT(TCCR1B , TCCR1B_CS11);
	CLR_BIT(TCCR1B , TCCR1B_CS12);

	/*Set the number of the ticks for overflow 20000 */
	ICR1 = 20000;

	/*Set the number of the ticks for Compare match  750 */
	OCR1A = 750;
}

void Timer1_voidSetCompareMatchValueChannalA(u16 Copy_u16CompareValue)
{
	OCR1A = Copy_u16CompareValue;
}




