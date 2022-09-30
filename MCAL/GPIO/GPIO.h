/*******************************************************************************
 * [   Module  ]: General Purpose Input Output
 *
 * [ File Name ]: GPIO.h
 *
 * [Description]: Header File For ATmega16 micro-controller Channels.
 *
 * [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_GPIO_GPIO_H_
#define SRC_MCAL_GPIO_GPIO_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/
#include "../../utils/std_types.h"
#include <avr/io.h>

/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/
#define NUM_OF_PORTS            4  // I will used it to check validation the number of port passed to function
#define NUM_OF_PINS_PER_PORT    8  // I will used it to check validation of number of pin passed to function

#define PORTA_ID                0
#define PORTB_ID                1
#define PORTC_ID                2
#define PORTD_ID                3

#define PIN0_ID                 0
#define PIN1_ID                 1
#define PIN2_ID                 2
#define PIN3_ID                 3
#define PIN4_ID                 4
#define PIN5_ID                 5
#define PIN6_ID                 6
#define PIN7_ID                 7
/*------------------------------------------------------------------------------
 *                                    TYPES
 *------------------------------------------------------------------------------*/
typedef enum{
	pin_input,
	pin_output
}GPIO_PinDirection;

typedef enum{
	port_input,
	port_output=0xFF
}GPIO_PortDirection;


/*------------------------------------------------------------------------------
 *                               FUNCTIONS DECLARATION
 *------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_SetPinDir
 [DISCRIPTION]:	This function is responsible to Setting the direction of a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Direction (input_pin or output_pin)
 [in] None
 [out] None
 [RUTURN]: Void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void  GPIO_SetPinDir(uint8 PORTn , uint8 PINn , GPIO_PinDirection Dir);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPin
 [DISCRIPTION]:	This function is responsible to Read the value from a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [in] None
 [out] None
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPin(uint8 PORTn , uint8 PINn);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePin
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void  GPIO_WritePin(uint8 PORTn , uint8 PINn , STD_LevelType level);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPin
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPin(uint8 PORTn , uint8 PINn );


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_SetPortDir
 [DISCRIPTION]:	This function is responsible to Setting the direction of a specific Port .
 [Args]: PORTn_ID(n=A,B,C,D) and Direction (input_port or output_port)
 [in] None
 [out] None
 [RUTURN]: Void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_SetPortDir(uint8 PORTn , GPIO_PortDirection Dir);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPort
 [DISCRIPTION]:	This function is responsible to Read the value from a specific PORT .
 [Args]: PORTn_ID(n=A,B,C,D)
 [in] None
 [out] None
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPort(uint8 PORTn);

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePort
 [DISCRIPTION]:	This function is responsible to Write value (0...255) on a specific port .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WritePort(uint8 PORTn, uint8 value );

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPort
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific port .
 [Args]: PORTn_ID(n=A,B,C,D)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPort(uint8 PORTn);

#endif /* SRC_MCAL_GPIO_GPIO_H_ */
