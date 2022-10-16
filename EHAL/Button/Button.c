/*******************************************************************************
 * [FILE NAME]:    Button.c
 *
 * [DATE CREATED]: Oct 22, 2022
 *
 * [DISCRIPTION]:  Source file for implementing the Button Functionality.
 *
 * [AUTHOR(S)]:    Mahmoud_Labib
 *
 ********************************************************************************/
/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "Button.h"
#include "../../MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "../../MCAL/TIMER/timer.h"
#include "../../utils/common_macros.h"


/*------------------------------------------------------------------------------
 *                                  Global Variable
 *------------------------------------------------------------------------------*/
extern uint8 volatile pauseFlag;
extern uint8 volatile continuFlag;

/*------------------------------------------------------------------------------
 *                            Functions Definitions
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:buttonInit
 [DISCRIPTION]:	This function is responsible to Initialized the Button
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void buttonInit(void)
{

#if EX_INT0 == ENABLE || EX_INT1 == ENABLE || EX_INT2 == ENABLE
	Ex_INT_Init();
#endif

}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:checkButton
 [DISCRIPTION]:	This function is responsible to check if button Pressed or released
 [Args]:void
 [RUTURN]: EN_Button_State_t
 ---------------------------------------------------------------------------------------*/
EN_Button_State_t  checkButton(void)
{
#if EX_INT0 == ENABLE || EX_INT1 == ENABLE || EX_INT2 == ENABLE
	if(pauseFlag == TRUE )
	{
		if(pauseFlag == TRUE)
		{
			TIMER_Deinit();
			pauseFlag=FALSE;

			return BUTTON_PRESSED;
		}
	}

	if(continuFlag == TRUE )
	{
		while(continuFlag == TRUE )
		{
			TIMER_Init();
			continuFlag=FALSE;

			return BUTTON_PRESSED;
		}

	}
	return BUTTON_RELEASED;

#endif
}


