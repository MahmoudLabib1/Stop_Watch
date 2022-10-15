/*******************************************************************************
* [FILE NAME]:    main.c
*
* [DATE CREATED]: Oct 15, 2022
*
* [DISCRIPTION]:  Stop Watch system
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "utils/std_types.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "EHAL/7-Segment/seven_segment.h"
#include "APP/stopwatch.h"
#include "EHAL/Button/Button.h"

/*------------------------------------------------------------------------------
 *                                 Main Function
 *------------------------------------------------------------------------------*/
int main()
{
	sevenSegmentInit();
	buttonInit();
	Ex_INT0_SetCallBack((void *)&checkButton);
	Ex_INT2_SetCallBack((void *)&checkButton);
	TIMER_Init();
	sei();

	while(1){

		stopWatchStart();
	}


}


