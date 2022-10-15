/*******************************************************************************
* [FILE NAME]:    seven_segment.c
*
* [DATE CREATED]: Oct 15, 2022
*
* [DISCRIPTION]:  Source file for implementing the seven_segment Functionality.
*
* [AUTHOR(S)]:    Mahmoud_Labib
*
********************************************************************************/

/*------------------------------------------------------------------------------
 *                                 INCLUDES
 *------------------------------------------------------------------------------*/
#include "seven_segment.h"
#include "../../utils/common_macros.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <avr/delay.h>

/*------------------------------------------------------------------------------
 *                               Private Definitions
 *------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------------
 *                               Private Array
 *------------------------------------------------------------------------------*/
// I create this mapping array to Write on specific pins on port
const uint8 NumMap[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};


/*------------------------------------------------------------------------------
 *                               Functions Definitions
 *------------------------------------------------------------------------------*/

 /*--------------------------------------------------------------------------------------
  [FUNCTION NAME]:sevenSegmentInit
  [DISCRIPTION]:	This function is responsible to Initialized the 7-Segment pin's
  [Args]:void
  [RUTURN]: EN_7Segment_Error_t
  ---------------------------------------------------------------------------------------*/
EN_7Segment_Error_t sevenSegmentInit(void)

{
#if (COMMON_CATHODE == ENABLE) && (HARDWARE_BCD == DISABLE)

	//PORTA for display Specific 7segment from 8 (7-segments).
	//I use 8*1 7segment so i set the direction for all PORTA for it
	GPIO_SetPortDir(PORTA_ID, port_output);
	// output 1 to OFF All 8 (7-Segments)
	PORTA |=0xFF;

	GPIO_SetPortDir(PORTC_ID, port_output);
	// output 0 to NOT Write at 7-Segments
	PORTC &=0x00;
	return DONE;
#endif

#if (COMMON_CATHODE == ENABLE) && (HARDWARE_BCD == ENABLE)

	//PORTA for display Specific 7segment from 8 (7-segments).
	//I use 8*1 7segment so i set the direction for all PORTA for it.
	GPIO_SetPortDir(PORTA_ID, port_output);
	// output 1 to ON All 8 (7-Segments)
	PORTA |=0x00;

	//Set direction of BCD pins and output LOW to display ZERO on 7segments
	GPIO_SetPinDir(PORTC_ID, PIN7_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN7_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN6_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN6_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN5_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN5_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN4_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN4_ID, LOGIC_LOW);

	return DONE;
#endif

#if (COMMON_ANODE == ENABLE) && (HARDWARE_BCD == DISABLE)
	GPIO_SetPortDir(PORTA_ID, port_output);
	// output 0 to OFF All 8 (7-Segments)
	PORTA |=0x00;

	GPIO_SetPortDir(PORTC_ID, port_output);
	// output 1 to NOT Write at 7-Segments
	PORTC &=0xFF;

	return DONE;
#endif

#if (COMMON_ANODE == ENABLE) && (HARDWARE_BCD == ENABLE)
	//PORTA for display Specific 7segment from 8 (7-segments).
	//I use 8*1 7segment so i set the direction for all PORTA for it.
	GPIO_SetPortDir(PORTA_ID, port_output);
	// output 1 to ON All 8 (7-Segments)
	PORTA |=0xFF;

	//Set direction of BCD pins and output LOW to display ZERO on 7segments
	GPIO_SetPinDir(PORTC_ID, PIN7_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN7_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN6_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN6_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN5_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN5_ID, LOGIC_LOW);

	GPIO_SetPinDir(PORTC_ID, PIN4_ID, pin_output);
	GPIO_WritePin(PORTC_ID, PIN4_ID, LOGIC_LOW);

	/*GPIO_SetPortDir(PORTC_ID, port_output);
	// output 1 to NOT Write at 7-Segments
	PORTC &=0xFF;*/
	return DONE;
#endif

	return ERROR;
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDisplay
 [DISCRIPTION]:	This function is responsible to display number on the 7-Segment
 [Args]: uint8
 [RUTURN]: EN_7Segment_Error_t
 ---------------------------------------------------------------------------------------*/

EN_7Segment_Error_t sevenSegmenDisplay(uint8 Num)
{
#if  HARDWARE_BCD == ENABLE

	//because we use BCD so just you need to write only One to display one on 7Segment
	// Convert the number to binary EX:4 -> 0100 to write it to BCD IC
	GPIO_WritePin(PORTC_ID, PIN7_ID, GET_BIT(Num,0));
	GPIO_WritePin(PORTC_ID, PIN6_ID, GET_BIT(Num,1));
	GPIO_WritePin(PORTC_ID, PIN5_ID, GET_BIT(Num,2));
	GPIO_WritePin(PORTC_ID, PIN4_ID, GET_BIT(Num,3));
	return DONE;
#endif

#if HARDWARE_BCD == DISABLE

	//because we NOT use BCD so we need to mapping the number to display on 7Segment.
	GPIO_WritePin(PORTC_ID, PIN0_ID, GET_BIT(NumMap[Num],0));
	GPIO_WritePin(PORTC_ID, PIN1_ID, GET_BIT(NumMap[Num],1));
	GPIO_WritePin(PORTC_ID, PIN2_ID, GET_BIT(NumMap[Num],2));
	GPIO_WritePin(PORTC_ID, PIN3_ID, GET_BIT(NumMap[Num],3));
	GPIO_WritePin(PORTC_ID, PIN4_ID, GET_BIT(NumMap[Num],4));
	GPIO_WritePin(PORTC_ID, PIN5_ID, GET_BIT(NumMap[Num],5));
	GPIO_WritePin(PORTC_ID, PIN6_ID, GET_BIT(NumMap[Num],6));
	GPIO_WritePin(PORTC_ID, PIN7_ID, GET_BIT(NumMap[Num],7));
	return DONE;
#endif

	return ERROR;
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]:sevenSegmenDn_EN
 [DISCRIPTION]:	This function's is responsible to Enable the specific 7-Segment
 [Args]:void
 [RUTURN]: Void
 ---------------------------------------------------------------------------------------*/
void sevenSegmenD1_EN(void)
{
	GPIO_WritePort(PORTA_ID, D1_EN);
}

void sevenSegmenD2_EN(void)
{
	GPIO_WritePort(PORTA_ID, D2_EN);
}

void sevenSegmenD3_EN(void)
{
	GPIO_WritePort(PORTA_ID, D3_EN);
}

void sevenSegmenD4_EN(void)
{
	GPIO_WritePort(PORTA_ID, D4_EN);
}

void sevenSegmenD5_EN(void)
{
	GPIO_WritePort(PORTA_ID, D5_EN);
}

void sevenSegmenD6_EN(void)
{
	GPIO_WritePort(PORTA_ID, D6_EN);
}

void sevenSegmenD7_EN(void)
{
	GPIO_WritePort(PORTA_ID, D7_EN);
}

void sevenSegmenD8_EN(void)
{
	GPIO_WritePort(PORTA_ID, D8_EN);
}

