/*******************************************************************************
* [FILE NAME]:    seven_segment.h
*
* [DATE CREATED]: Oct 15, 2022
*
* [DISCRIPTION]:  Header file for Declaration and config the seven_segment Functionality.
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/

#ifndef EHAL_7_SEGMENT_SEVEN_SEGMENT_H_
#define EHAL_7_SEGMENT_SEVEN_SEGMENT_H_

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "../../utils/std_types.h"

/*------------------------------------------------------------------------------
 *                         DEFINITIONS AND CONFIG
 *------------------------------------------------------------------------------*/
#define COMMON_CATHODE         DISABLE
#define COMMON_ANODE           ENABLE

#define HARDWARE_BCD           ENABLE

#define DP_EN                  DISABLE

/*------------------------------------------------------------------------------
 *                                Error Type's
 *------------------------------------------------------------------------------*/
typedef enum
{
	DONE,ERROR
}EN_7Segment_Error_t;



/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmentInit
 [DISCRIPTION]:	This function is responsible to Initialized the 7-Segment pin's
 [Args]:void
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmentInit(void);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDisplay
 [DISCRIPTION]:	This function is responsible to display number on the 7-Segment
 [Args]: uint8
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmenDisplay(uint8 Num);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDn_EN
 [DISCRIPTION]:	This function's is responsible to Enable the specific 7-Segment
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void sevenSegmenD1_EN(void);

void sevenSegmenD2_EN(void);

void sevenSegmenD3_EN(void);

void sevenSegmenD4_EN(void);

void sevenSegmenD5_EN(void);

void sevenSegmenD6_EN(void);

void sevenSegmenD7_EN(void);

void sevenSegmenD8_EN(void);


#endif /* EHAL_7_SEGMENT_SEVEN_SEGMENT_H_ */
