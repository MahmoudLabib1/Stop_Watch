/*******************************************************************************
* [FILE NAME]:    stopwatch.c
*
* [DATE CREATED]: Oct 22, 2022
*
* [DISCRIPTION]:  Source file for implementing the StopWatch Functionality.
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "stopwatch.h"
#include "../EHAL/7-Segment/seven_segment.h"
#include <util/delay.h>

/*------------------------------------------------------------------------------
 *                          Definitions & Global Variable
 *------------------------------------------------------------------------------*/
#define DELAY 2
extern uint8 volatile interruptMilliSecondFlag;
uint8 volatile millisecondsCount=0;
uint8 volatile secondsCount=0;
uint8 volatile minutesCount=0;
uint8 volatile hoursCount=0;


/*------------------------------------------------------------------------------
 *                              Private Function's
 *------------------------------------------------------------------------------*/
static void sevenSegmentOnesNum(uint8 num);
static void sevenSegmentTensNum(uint8 num);

/*------------------------------------------------------------------------------
 *                             Functions Definitions
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:stopWatchStart
 [DISCRIPTION]:	This function is responsible to Start the StopWatch Application
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchStart(void)
{
	sevenSegmentMilliSecondsDisplay();
	sevenSegmentSecondsDisplay();
	sevenSegmentMinutsDisplay();
	sevenSegmentHoursDisplay();
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentMilliSecondsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the millisecond's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
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


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentSecondsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the second's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
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


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentMinutsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the minut's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void)
{
	if(minutesCount == 60)
	{
		hoursCount++;
		minutesCount=0;
	}

	//Display The seconds on 7segment


	sevenSegmentOnesNum(minutesCount);
	sevenSegmenD5_EN();
	_delay_ms(DELAY);


	sevenSegmentTensNum(minutesCount);
	sevenSegmenD6_EN();
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentHoursDisplay
 [DISCRIPTION]:	This function is responsible to count and display the hours on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentHoursDisplay(void)
{
	if(hoursCount == 24)
	{
		hoursCount=0;
	}

	//Display The seconds on 7segment


	sevenSegmentOnesNum(hoursCount);
	sevenSegmenD7_EN();
	_delay_ms(DELAY);


	sevenSegmentTensNum(hoursCount);
	sevenSegmenD8_EN();
	_delay_ms(DELAY);

	return STOP_WATCH_DONE;
}


/*-------------------------------Private Functions Definitions--------------------------------*/
void sevenSegmentOnesNum(uint8 num)
{
	switch((num%10))
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
	switch((num/10))
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
