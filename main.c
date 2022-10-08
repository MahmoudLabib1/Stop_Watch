#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "utils/std_types.h"
#include "MCAL/TIMER/timer.h"
#include "MCAL/EX_INTERRUPT/ex_interrupt.h"
#include "EHAL/7-Segment/seven_segment.h"
#include "APP/stopwatch.h"
#include "EHAL/Button/Button.h"

int main()
{
	sevenSegmentInit();
	TIMER_Init();
	Ex_INT0_SetCallBack(&checkButton);
	Ex_INT2_SetCallBack(&checkButton);
	buttonInit();
	sei();

	while(1){

		stopWatchStart();
	}


}


