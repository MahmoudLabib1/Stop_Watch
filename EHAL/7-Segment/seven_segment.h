/*
 * seven_segment.h
 *
 *  Created on: Sep 30, 2022
 *      Author: Mahmoud Labib
 */

#ifndef EHAL_7_SEGMENT_SEVEN_SEGMENT_H_
#define EHAL_7_SEGMENT_SEVEN_SEGMENT_H_

#include "../../utils/std_types.h"

/*==============================================================================
 *                                  DEFINITIONS
 *=============================================================================*/

#define COMMON_CATHODE         DISABLE
#define COMMON_ANODE           ENABLE

#define HARDWARE_BCD           DISABLE

#define DP_EN                  DISABLE


// Display Number In Config COMMON_CATHODE mode
#if COMMON_CATHODE == ENABLE
#if DP_EN == ENABLE

#define ZERO     0xBF
#define ONE      0x86
#define TWO      0xDB
#define THREE    0xCF
#define FOUR     0xE6
#define FIVE     0xED
#define SIX      0xFD
#define SEVEN    0x87
#define EIGHT    0xFF
#define NINE     0xEF

#elif DP_EN == DISABLE

#define ZERO     0x3F
#define ONE      0x06
#define TWO      0x5B
#define THREE    0x4F
#define FOUR     0x66
#define FIVE     0x6D
#define SIX      0x7D
#define SEVEN    0x07
#define EIGHT    0x7F
#define NINE     0x6F

#endif
#endif





// Display Number In Config COMMON_ANODE mode
#if COMMON_ANODE == ENABLE
#if DP_EN == ENABLE

#define ZERO     0x40
#define ONE      0x79
#define TWO      0x24
#define THREE    0x30
#define FOUR     0x19
#define FIVE     0x12
#define SIX      0x02
#define SEVEN    0x78
#define EIGHT    0x00
#define NINE     0x10

#elif DP_EN == DISABLE

#define ZERO     0xC0
#define ONE      0xF9
#define TWO      0xA4
#define THREE    0xB0
#define FOUR     0x99
#define FIVE     0x92
#define SIX      0x82
#define SEVEN    0xF8
#define EIGHT    0x80
#define NINE     0x90

#endif
#endif




#if COMMON_CATHODE == ENABLE
#define  D1_EN   0xFE
#define  D2_EN   0xFD
#define  D3_EN   0xFB
#define  D4_EN   0xF7
#define  D5_EN   0xEF
#define  D6_EN   0xDF
#define  D7_EN   0xBF
#define  D8_EN   0x7F

#elif  COMMON_ANODE == ENABLE

#define  D1_EN   0x01
#define  D2_EN   0x02
#define  D3_EN   0x04
#define  D4_EN   0x08
#define  D5_EN   0x10
#define  D6_EN   0x20
#define  D7_EN   0x40
#define  D8_EN   0x80

#endif


typedef enum
{
	DONE,ERROR
}EN_7Segment_Error_t;




EN_7Segment_Error_t sevenSegmentInit(void);

EN_7Segment_Error_t sevenSegmenDisplay(uint8 Num);

void sevenSegmenD1_EN(void);

void sevenSegmenD2_EN(void);

void sevenSegmenD3_EN(void);

void sevenSegmenD4_EN(void);

void sevenSegmenD5_EN(void);

void sevenSegmenD6_EN(void);

void sevenSegmenD7_EN(void);

void sevenSegmenD8_EN(void);


#endif /* EHAL_7_SEGMENT_SEVEN_SEGMENT_H_ */
