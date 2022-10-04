/*
 * seven_segment.c
 *
 *  Created on: Sep 30, 2022
 *      Author: Mahmoud Labib
 */

#include "seven_segment.h"
#include "../../utils/common_macros.h"
#include "../../MCAL/GPIO/GPIO.h"
#include <avr/delay.h>


// I create this mapping array to Write on specific pins on port
const uint8 NumMap[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

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



