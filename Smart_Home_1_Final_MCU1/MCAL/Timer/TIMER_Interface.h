/*************************************************************
 * ****************** Author : Adel Khaled *******************
 * ****************** Date   : 9- 7-2022   *******************
 *************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void Timer_voidTimer0Init();

void GIE_voidGlobalEnable();

void Timer_voidSetPreload(u8 Copy_u8Preload);

void Timer_voidCallBackTimer0(void (*Copy_pvCallBack) (void));
void Timer_voidCTCInit();

#endif /* TIMER_INTERFACE_H_ */
