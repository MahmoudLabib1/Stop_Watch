/*
 * Button.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Mahmoud Labib
 */

#ifndef EHAL_BUTTON_BUTTON_H_
#define EHAL_BUTTON_BUTTON_H_
#include "../../utils/std_types.h"


typedef enum
{
	BUTTON_PRESSED,BUTTON_RELEASED
}EN_Button_State_t;



void buttonInit(void);
EN_Button_State_t  checkButton(void);

#endif /* EHAL_BUTTON_BUTTON_H_ */
