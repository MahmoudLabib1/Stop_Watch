/*
 * Button.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Labib
 */

#include "Button.h"
#include "../../MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "../../MCAL/TIMER/timer.h"
#include <util/delay.h>

extern uint8 volatile pauseFlag;
extern uint8 volatile continuFlag;

void buttonInit(void)
{

#if EX_INT0 == ENABLE || EX_INT1 == ENABLE || EX_INT2 == ENABLE
	Ex_INT_Init();
#endif

}


EN_Button_State_t  checkButton(void)
{
#if EX_INT0 == ENABLE || EX_INT1 == ENABLE || EX_INT2 == ENABLE
	if(pauseFlag == TRUE )
	{
		_delay_ms(30);
		if(pauseFlag == TRUE )
		{
			TIMER_Deinit();
			pauseFlag=FALSE;
			return BUTTON_PRESSED;
		}
	}

	if(continuFlag == TRUE )
	{
		_delay_ms(30);
		if(continuFlag == TRUE )
		{
			TIMER_Init();
			continuFlag=FALSE;
			return BUTTON_PRESSED;
		}

	}
	return BUTTON_RELEASED;

#endif
}


