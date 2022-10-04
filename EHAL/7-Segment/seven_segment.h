/*
 * seven_segment.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mahmoud Labib
 */

#ifndef EHAL_7_SEGMENT_SEVEN_SEGMENT_H_
#define EHAL_7_SEGMENT_SEVEN_SEGMENT_H_

#include "../../utils/std_types.h"

typedef struct
{
	uint8 Segment_id;
    uint8 num;

}ST_7Segment_t;

typedef enum
{
	DONE,ERROR
}EN_7Segment_Error_t;



EN_7Segment_Error_t sevenSegmentDisplay(ST_7Segment_t *sevenSegment);

#endif /* EHAL_7_SEGMENT_SEVEN_SEGMENT_H_ */
