/*******************************************************************************
 *
 *  [   Module  ]: External Interrupts Modules
 *
 *  [ File Name ]: ex_interrupt.h
 *
 *  [Description]: Header File for configuration AVR_ATmega16 External Interrupts.
 *
 *  [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/
#ifndef SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_
#define SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include <avr/io.h>
#include "../../utils/std_types.h"
#include "../GPIO/GPIO.h"
/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/*[Description]: Write ENABLE/DISABLE To Configure Specific Ex_Interrupt
 *[  Example  ]: EX_INT0   ENABLE
 *               EX_INT1   DISABLE
 */
#define EX_INT0          ENABLE
#define EX_INT1          DISABLE
#define EX_INT2          DISABLE

/*[Description]: Choose the external Interrupt0 trigger sense
 *[INT0_Sense_Types]:
 *
 * --> [INT0_Sense_Low_Level_Mask]
 * --> [INT0_Sense_Any_Logical_change_Mask]
 * --> [INT0_Sense_Falling_Edge_Mask]
 * --> [INT0_Sense_Rising_Edge_Mask]
 *
 *[  Example  ]: INT0_Sense_Selector   INT0_Sense_Falling_Edge_Mask
 *
 */
#define INT0_Sense_Selector        INT0_Sense_Falling_Edge_Mask


/*[Description]: Choose the external Interrupt1 trigger sense
 *[INT1_Sense_Types]:
 *
 * --> [INT1_Sense_Low_Level_Mask]
 * --> [INT1_Sense_Any_Logical_change_Mask]
 * --> [INT1_Sense_Falling_Edge_Mask]
 * --> [INT1_Sense_Rising_Edge_Mask]
 *
 *[  Example  ]: INT1_Sense_Selector   INT1_Sense_Low_Level_Mask
 *
 */
#define INT1_Sense_Selector        INT1_Sense_Rising_Edge_Mask

/*[Description]: Choose the external Interrupt2 trigger sense
 *[INT2_Sense_Types]:
 *
 * --> [INT2_Sense_Falling_Edge_Mask]
 * --> [INT2_Sense_Rising_Edge_Mask]
 *
 *[  Example  ]: INT2_Sense_Selector   INT2_Sense_Falling_Edge_Mask
 *
 */
#define INT2_Sense_Selector        INT2_Sense_Falling_Edge_Mask
/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/
/*
 * [FUNCTION NAME]: Ex_INT_Init
 * [DISCRIPTION]  : This function is responsible to initialization one or more than one EXternal enterrupt at
 *                  The same time from Configuration of External interrupt .
 * [Args]  : void
 * [RUTURN]: Void
 */
void Ex_INT_Init(void);

/*
 * [FUNCTION NAME]: Ex_INT_SetCallBack
 * [DISCRIPTION]  : This function allow Applecation layer call function from
 *                  MCAL layer by interrupt called callback function.
 * [Args]  : Pointer To Function take void and return void
 * [RUTURN]: Void
 */
void Ex_INT0_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT1_SetCallBack(void (*ptr_To_function)(void));
void Ex_INT2_SetCallBack(void (*ptr_To_function)(void));
#endif /* SRC_MCAL_EX_INTERRUPT_EX_INTERRUPT_H_ */
