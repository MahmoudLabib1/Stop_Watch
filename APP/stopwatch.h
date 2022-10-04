/*
 * stopwatch.h
 *
 *  Created on: Oct 4, 2022
 *      Author: Mahmoud Labib
 */

#ifndef APP_STOPWATCH_H_
#define APP_STOPWATCH_H_

#include "../utils/std_types.h"

typedef enum
{
	STOP_WATCH_DONE,STOP_WATCH_ERROR
}EN_StopWatch_Error_t;


void stopWatchStart(void);
EN_StopWatch_Error_t sevenSegmentMilliSecondsDisplay(void);
EN_StopWatch_Error_t sevenSegmentSecondsDisplay(void);
EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void);
EN_StopWatch_Error_t sevenSegmentHoursDisplay(void);

/*void sevenSegmentOnesNum(uint8 num);
void sevenSegmentTensNum(uint8 num);*/

#endif /* APP_STOPWATCH_H_ */
