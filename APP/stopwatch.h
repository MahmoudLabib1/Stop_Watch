/*******************************************************************************
* [FILE NAME]:    stopwatch.h
*
* [DATE CREATED]: Oct 22, 2022
*
* [DISCRIPTION]:  Header file for Declaration and config the StopWatch Functionality.
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/

#ifndef APP_STOPWATCH_H_
#define APP_STOPWATCH_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                                Error Type's
 *------------------------------------------------------------------------------*/
typedef enum
{
	STOP_WATCH_DONE,STOP_WATCH_ERROR
}EN_StopWatch_Error_t;


/*------------------------------------------------------------------------------
 *                             Functions Declaration
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:stopWatchStart
 [DISCRIPTION]:	This function is responsible to Start the StopWatch Application
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void stopWatchStart(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentMilliSecondsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the millisecond's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentMilliSecondsDisplay(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentSecondsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the second's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentSecondsDisplay(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentMinutsDisplay
 [DISCRIPTION]:	This function is responsible to count and display the minut's on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentMinutsDisplay(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentHoursDisplay
 [DISCRIPTION]:	This function is responsible to count and display the hours on 7-Segment's
 [Args]:void
 [RUTURN]: EN_StopWatch_Error_t
 ---------------------------------------------------------------------------------------*/
EN_StopWatch_Error_t sevenSegmentHoursDisplay(void);

#endif /* APP_STOPWATCH_H_ */
