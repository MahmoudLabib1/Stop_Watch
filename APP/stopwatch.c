/*
 * stopwatch.c
 *
 *  Created on: Oct 4, 2022
 *      Author: Mahmoud Labib
 */

#include "stopwatch.h"
#include "../EHAL/7-Segment/seven_segment.h"

#define DELAY 3
extern uint8 volatile interruptMilliSecondFlag;
uint8 volatile millisecondsCount=0;
uint8 volatile secondsCount=0;
uint8 volatile minutesCount=0;
uint8 volatile hoursCount=0;

EN_StopWatch_Error_t sevenSegmentMilliSecondsDisplay(void)
{

	if(interruptMilliSecondFlag == TRUE)
	{
		interruptMilliSecondFlag=FALSE;
		//Flag true mean that timer count 1sec
		millisecondsCount++;
		if(millisecondsCount == 60)
		{
			secondsCount++;
			millisecondsCount=0;
		}
		if(millisecondsCount > 60)
		{
			return STOP_WATCH_ERROR;
		}
	}

	//Display The seconds on 7segment

	PORTA = (PORTA & 0xF0) | (D1_EN);
	sevenSegmentOnesNum(millisecondsCount);
	_delay_ms(DELAY);

	PORTA = (PORTA & 0xF0) | (D2_EN);
	sevenSegmentTensNum(millisecondsCount);
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

	PORTA = (PORTA & 0xF0) | (D3_EN);
	sevenSegmentOnesNum(secondsCount);
	_delay_ms(DELAY);

	PORTA = (PORTA & 0xF0) | (D4_EN);
	sevenSegmentTensNum(secondsCount);
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

	PORTA = (PORTA & 0xF0) | (D1_EN);
	sevenSegmentOnesNum(minutesCount);
	_delay_ms(DELAY);

	PORTA = (PORTA & 0xF0) | (D2_EN);
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

	PORTA = (PORTA & 0xF0) | (D3_EN);
	sevenSegmentOnesNum(hoursCount);
	_delay_ms(DELAY);

	PORTA = (PORTA & 0xF0) | (D4_EN);
	sevenSegmentTensNum(hoursCount);
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}



void sevenSegmentOnesNum(uint8 num)
{
	switch((num % 10))
	{
	case 0:
		PORTC = (PORTC & 0x00) | (ZERO);
		break;
	case 1:
		PORTC = (PORTC & 0x00) | (ONE);
		break;
	case 2:
		PORTC = (PORTC & 0x00) | (TWO);
		break;
	case 3:
		PORTC = (PORTC & 0x00) | (THREE);
		break;
	case 4:
		PORTC = (PORTC & 0x00) | (FOUR);
		break;
	case 5:
		PORTC = (PORTC & 0x00) | (FIVE);
		break;
	case 6:
		PORTC = (PORTC & 0x00) | (SIX);
		break;
	case 7:
		PORTC = (PORTC & 0x00) | (SEVEN);
		break;
	case 8:
		PORTC = (PORTC & 0x00) | (EIGHT);
		break;
	case 9:
		PORTC = (PORTC & 0x00) | (NINE);
		break;
	}

}


void sevenSegmentTensNum(uint8 num)
{
	switch((num / 10))
	{
	case 0:
		PORTC = (PORTC & 0x00) | (ZERO);
		break;
	case 1:
		PORTC = (PORTC & 0x00) | (ONE);
		break;
	case 2:
		PORTC = (PORTC & 0x00) | (TWO);
		break;
	case 3:
		PORTC = (PORTC & 0x00) | (THREE);
		break;
	case 4:
		PORTC = (PORTC & 0x00) | (FOUR);
		break;
	case 5:
		PORTC = (PORTC & 0x00) | (FIVE);
		break;
	case 6:
		PORTC = (PORTC & 0x00) | (SIX);
		break;
	case 7:
		PORTC = (PORTC & 0x00) | (SEVEN);
		break;
	case 8:
		PORTC = (PORTC & 0x00) | (EIGHT);
		break;
	case 9:
		PORTC = (PORTC & 0x00) | (NINE);
		break;
	}
}
