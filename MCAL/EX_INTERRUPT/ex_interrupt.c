/*******************************************************************************
 *
 *  [   Module  ]: External Interrupts Modules
 *
 *  [ File Name ]: ex_interrupt.c
 *
 *  [Description]: Source File for implementation AVR_ATmega16 External Interrupts.
 *
 *  [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/
/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include "../../utils/common_macros.h"
#include "ex_interrupt.h"
#include <avr/interrupt.h>
/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/
/*
 * [Description]: This Pointer To Function Save the Address Of The function
 *                That will called when Event or interrupt occur .
 *
 *                AND Every Eternal interrupt have g_Pointer To Function .
 */
static volatile void(*g_Ptr_To_Fun_INT0)(void)=NULL;
static volatile void(*g_Ptr_To_Fun_INT1)(void)=NULL;
static volatile void(*g_Ptr_To_Fun_INT2)(void)=NULL;
uint8 volatile buttonFlag=FALSE;
/*******************************************************************************
 *                                 INT0_ISR
 *******************************************************************************/
/*
 * [Description]: Here The ISR's specific For EX_INT0
 */

ISR(INT0_vect){

	buttonFlag = TRUE;

	if(g_Ptr_To_Fun_INT0 != NULL){
		(*g_Ptr_To_Fun_INT0)();
	}
}
/*******************************************************************************
 *                                 INT1_ISR
 *******************************************************************************/
/*
 * [Description]: Here The ISR's specific For EX_INT1
 */

ISR(INT1_vect){
	if(g_Ptr_To_Fun_INT1 != NULL){
		(*g_Ptr_To_Fun_INT1)();
	}
}
/*******************************************************************************
 *                                 INT2_ISR
 *******************************************************************************/
/*
 * [Description]: Here The ISR's specific For EX_INT2
 */

ISR(INT2_vect){
	if(g_Ptr_To_Fun_INT2 != NULL){
		(*g_Ptr_To_Fun_INT2)();
	}
}
/*******************************************************************************
 *                                    MASK's
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                      [Masks For External Interrupt sense]
 * -----------------------------------------------------------------------------*/
/*INT0 Mask's*/
#define INT0_Sense_CLR_Mask                0xFC
#define INT0_Sense_Low_Level_Mask          0x00  //default
#define INT0_Sense_Any_Logical_change_Mask 0x01
#define INT0_Sense_Falling_Edge_Mask       0x02
#define INT0_Sense_Rising_Edge_Mask        0x03

/*INT1 Mask's*/
#define INT1_Sense_CLR_Mask                0xF3
#define INT1_Sense_Low_Level_Mask          0x00  //default
#define INT1_Sense_Any_Logical_change_Mask 0x04
#define INT1_Sense_Falling_Edge_Mask       0x08
#define INT1_Sense_Rising_Edge_Mask        0x0C

/*INT2 Mask's*/
#define INT2_Sense_CLR_Mask                0xBF
#define INT2_Sense_Falling_Edge_Mask       0x00
#define INT2_Sense_Rising_Edge_Mask        0x40

/*******************************************************************************
 *                         Implementation FUNCTIONS
 *******************************************************************************/
/*
 * [FUNCTION NAME]: Ex_INT_Init
 * [DISCRIPTION]  : This function is responsible to initialization one or more than one EXternal enterrupt at
 *                  The same time from Configuration of External interrupt .
 * [Args]  : void
 * [RUTURN]: Void
 */
void Ex_INT_Init(void){

#if EX_INT0 == ENABLE
	SET_BIT(GICR,INT0); //Enable External Enterrupt0
	GPIO_SetPinDir(PORTD_ID, PIN2_ID,pin_input );
	GPIO_WritePin(PORTD_ID, PIN2_ID, logic_high);//to activate pull up resistor
#if INT0_Sense_Selector == 	INT0_Sense_Low_Level_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	CLEAR_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);
#elif INT0_Sense_Selector == INT0_Sense_Any_Logical_change_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC10);
	CLEAR_BIT(MCUCR,ISC11);

#elif  INT0_Sense_Selector == INT0_Sense_Falling_Edge_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC11);
	CLEAR_BIT(MCUCR,ISC10);

#elif  INT0_Sense_Selector == INT0_Sense_Rising_Edge_Mask
	MCUCR =(MCUCR & INT0_Sense_CLR_Mask);
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#endif
#endif

#if EX_INT1 == ENABLE
	SET_BIT(GICR,INT1); //Enable External Enterrupt1
#if INT1_Sense_Selector == 	INT1_Sense_Low_Level_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
#elif INT1_Sense_Selector == INT1_Sense_Any_Logical_change_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR = (MCUCR | INT1_Sense_Any_Logical_change_Mask);

#elif  INT1_Sense_Selector == INT1_Sense_Falling_Edge_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR = (MCUCR | INT1_Sense_Falling_Edge_Mask);

#elif  INT1_Sense_Selector == INT1_Sense_Rising_Edge_Mask
	MCUCR =(MCUCR & INT1_Sense_CLR_Mask);
	MCUCR =(MCUCR | INT1_Sense_Rising_Edge_Mask);
#endif
#endif

#if EX_INT2 == ENABLE
	SET_BIT(GICR,INT2); //Enable External Enterrupt1
#if INT2_Sense_Selector == INT2_Sense_Falling_Edge_Mask
	MCUCSR =(MCUCSR & INT2_Sense_CLR_Mask);

#elif INT2_Sense_Selector == INT2_Sense_Rising_Edge_Mask
	MCUCSR =(MCUCSR & INT2_Sense_CLR_Mask);
	MCUCSR =(MCUCSR | INT2_Sense_Rising_Edge_Mask);
#endif
#endif
}


/*
 * [FUNCTION NAME]: Ex_INT_SetCallBack
 * [DISCRIPTION]  : This function allow Applecation layer call function from
 *                  MCAL layer by interrupt called callback function.
 * [Args]  : Pointer To Function take void and return void
 * [RUTURN]: Void
 */
void Ex_INT0_SetCallBack(void (*ptr_To_function)(void)){
	g_Ptr_To_Fun_INT0 = (volatile void *)ptr_To_function;
}

void Ex_INT1_SetCallBack(void (*ptr_To_function)(void)){
	g_Ptr_To_Fun_INT1 = (volatile void *)ptr_To_function;
}

void Ex_INT2_SetCallBack(void (*ptr_To_function)(void)){
	g_Ptr_To_Fun_INT2 = (volatile void *)ptr_To_function;
}
