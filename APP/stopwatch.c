/*
 * stopwatch.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mahmoud Labib
 */

#include "stopwatch.h"
#include "../EHAL/7-Segment/seven_segment.h"
#include <util/delay.h>

#define DELAY 2
extern uint8 volatile interruptMilliSecondFlag;
uint8 millicounter=0;
uint8 volatile millisecondsCount=0;
uint8 volatile secondsCount=0;
uint8 volatile minutesCount=0;
uint8 volatile hoursCount=0;



static void sevenSegmentOnesNum(uint8 num);
static void sevenSegmentTensNum(uint8 num);


void stopWatchStart(void)
{
	sevenSegmentMilliSecondsDisplay();
	sevenSegmentSecondsDisplay();
	sevenSegmentMinutsDisplay();
	sevenSegmentHoursDisplay();
}






EN_StopWatch_Error_t sevenSegmentMilliSecondsDisplay(void)
{

	if(interruptMilliSecondFlag == TRUE)
	{
		interruptMilliSecondFlag=FALSE;
		//Flag true mean that timer count 1sec
		millisecondsCount++;
		if(millisecondsCount == 55 )
		{
			secondsCount++;
			millisecondsCount=0;
		}
		if(millisecondsCount > 55)
		{
			return STOP_WATCH_ERROR;
		}
	}

	//Display The seconds on 7segment

	sevenSegmentOnesNum(millisecondsCount);
	sevenSegmenD1_EN();
	_delay_ms(DELAY);


	sevenSegmentTensNum(millisecondsCount);
	sevenSegmenD2_EN();
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}

EN_StopWatch_Error_t sevenSegmentSecondsDisplay(void)
{
	if(secondsCount == 60)
	{
		minutesCount++;
		secondsCount=0;
	}

	//Display The seconds on 7segment


	sevenSegmentOnesNum(secondsCount);
	sevenSegmenD3_EN();
	_delay_ms(DELAY);


	sevenSegmentTensNum(secondsCount);
	sevenSegmenD4_EN();
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}




EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void)
{
	if(minutesCount == 60)
	{
		hoursCount++;
		minutesCount=0;
	}

	//Display The seconds on 7segment

	sevenSegmenD5_EN();
	sevenSegmentOnesNum(minutesCount);
	_delay_ms(DELAY);

	sevenSegmenD6_EN();
	sevenSegmentTensNum(minutesCount);
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}


EN_StopWatch_Error_t sevenSegmentHoursDisplay(void)
{
	if(hoursCount == 24)
	{
		hoursCount=0;
	}

	//Display The seconds on 7segment

	sevenSegmenD7_EN();
	sevenSegmentOnesNum(hoursCount);
	_delay_ms(DELAY);

	sevenSegmenD8_EN();
	sevenSegmentTensNum(hoursCount);
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}



void sevenSegmentOnesNum(uint8 num)
{
	switch((num % 10))
	{
	case 0:
		sevenSegmenDisplay(0);
		break;
	case 1:
		sevenSegmenDisplay(1);
		break;
	case 2:
		sevenSegmenDisplay(2);
		break;
	case 3:
		sevenSegmenDisplay(3);
		break;
	case 4:
		sevenSegmenDisplay(4);
		break;
	case 5:
		sevenSegmenDisplay(5);
		break;
	case 6:
		sevenSegmenDisplay(6);
		break;
	case 7:
		sevenSegmenDisplay(7);
		break;
	case 8:
		sevenSegmenDisplay(8);
		break;
	case 9:
		sevenSegmenDisplay(9);
		break;
	}

}


void sevenSegmentTensNum(uint8 num)
{
	switch((num / 10))
	{
	case 0:
		sevenSegmenDisplay(0);
		break;
	case 1:
		sevenSegmenDisplay(1);
		break;
	case 2:
		sevenSegmenDisplay(2);
		break;
	case 3:
		sevenSegmenDisplay(3);
		break;
	case 4:
		sevenSegmenDisplay(4);
		break;
	case 5:
		sevenSegmenDisplay(5);
		break;
	case 6:
		sevenSegmenDisplay(6);
		break;
	case 7:
		sevenSegmenDisplay(7);
		break;
	case 8:
		sevenSegmenDisplay(8);
		break;
	case 9:
		sevenSegmenDisplay(9);
		break;
	}
}
