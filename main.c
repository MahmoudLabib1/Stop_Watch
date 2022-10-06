#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "utils/std_types.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "EHAL/7-Segment/seven_segment.h"
#include "APP/stopwatch.h"


extern uint8 volatile pauseFlag;
extern uint8 volatile continuFlag;
uint8 volatile pressCount=0;

void pauseButton(void)
{
	if(pauseFlag == TRUE ){
		_delay_ms(30);
		if(pauseFlag == TRUE )
		{
			TIMER_Deinit();
			/*pressCount++;*/
			pauseFlag=FALSE;
		}
	}
}

void continuButton(void)
{
	if(continuFlag == TRUE )
	{
		_delay_ms(30);
		if(continuFlag == TRUE )
		{
			TIMER_Init();
			continuFlag=FALSE;
		}

	}
}


int main()
{
	sevenSegmentInit();
	TIMER_Init();
	Ex_INT0_SetCallBack(&pauseButton);
	Ex_INT2_SetCallBack(&continuButton);
	Ex_INT_Init();
	sei();

	while(1){

		stopWatchStart();
	}


}


