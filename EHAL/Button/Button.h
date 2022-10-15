/*******************************************************************************
* [FILE NAME]:    Button.h
*
* [DATE CREATED]: Oct 22, 2022
*
* [DISCRIPTION]:  Header file for Declaration and config the Button Functionality.
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/
#ifndef EHAL_BUTTON_BUTTON_H_
#define EHAL_BUTTON_BUTTON_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                Error Type's
 *------------------------------------------------------------------------------*/
typedef enum
{
	BUTTON_PRESSED,BUTTON_RELEASED
}EN_Button_State_t;


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:buttonInit
 [DISCRIPTION]:	This function is responsible to Initialized the Button
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void buttonInit(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:checkButton
 [DISCRIPTION]:	This function is responsible to check if button Pressed or released
 [Args]:void
 [RUTURN]: EN_Button_State_t
 ---------------------------------------------------------------------------------------*/
EN_Button_State_t  checkButton(void);

#endif /* EHAL_BUTTON_BUTTON_H_ */
