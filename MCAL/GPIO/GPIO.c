/*******************************************************************************
 * [   Module  ]: General Purpose Input Output
 *
 * [ File Name ]: GPIO.c
 *
 * [Description]: Source File For ATmega16 micro-controller Channels.
 *
 * [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/
#include "GPIO.h"
#include "../../utils/common_macros.h"


/*------------------------------------------------------------------------------
 *                               FUNCTIONS IMPLEMENTATION
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
void  GPIO_SetPinDir(uint8 PORTn , uint8 PINn , GPIO_PinDirection Dir){

	if((PORTn >= NUM_OF_PORTS ) || (PINn >= NUM_OF_PINS_PER_PORT)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			if(Dir == pin_output){
				SET_BIT(DDRA,PINn);
			}
			else
			{
				CLEAR_BIT(DDRA,PINn);
			}
			break;
		case PORTB_ID:
			if(Dir == pin_output){
				SET_BIT(DDRB,PINn);
			}
			else
			{
				CLEAR_BIT(DDRB,PINn);
			}
			break;
		case PORTC_ID:
			if(Dir == pin_output){
				SET_BIT(DDRC,PINn);
			}
			else
			{
				CLEAR_BIT(DDRC,PINn);
			}
			break;
		case PORTD_ID:
			if(Dir == pin_output){
				SET_BIT(DDRD,PINn);
			}
			else
			{
				CLEAR_BIT(DDRD,PINn);
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPin
 [DISCRIPTION]:	This function is responsible to Read the value from a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [in] None
 [out] None
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPin(uint8 PORTn , uint8 PINn){
	uint8 data;
	if((PORTn >= NUM_OF_PORTS ) || (PINn >= NUM_OF_PINS_PER_PORT)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			if(BIT_IS_SET(PINA,PINn)){
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,PINn)){
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,PINn)){
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,PINn)){
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		}
	}
	return data;
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePin
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void  GPIO_WritePin(uint8 PORTn , uint8 PINn , STD_LevelType level){
	if((PORTn >= NUM_OF_PORTS ) || (PINn >= NUM_OF_PINS_PER_PORT)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			if(level == LOGIC_HIGH){
				SET_BIT(PORTA,PINn);
			}
			else
			{
				CLEAR_BIT(PORTA,PINn);
			}
			break;
		case PORTB_ID:
			if(level == LOGIC_HIGH){
				SET_BIT(PORTB,PINn);
			}
			else
			{
				CLEAR_BIT(PORTB,PINn);
			}
			break;
		case PORTC_ID:
			if(level == LOGIC_HIGH){
				SET_BIT(PORTC,PINn);
			}
			else
			{
				CLEAR_BIT(PORTC,PINn);
			}
			break;
		case PORTD_ID:
			if(level == LOGIC_HIGH){
				SET_BIT(PORTD,PINn);
			}
			else
			{
				CLEAR_BIT(PORTD,PINn);
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPin
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific pin .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 OR PINn >= 8 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPin(uint8 PORTn , uint8 PINn ){
	if((PORTn >= NUM_OF_PORTS) || (PINn >= NUM_OF_PINS_PER_PORT)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			TOGGLE_BIT(PORTA,PINn);
			break;
		case PORTB_ID:
			TOGGLE_BIT(PORTB,PINn);
			break;
		case PORTC_ID:
			TOGGLE_BIT(PORTC,PINn);
			break;
		case PORTD_ID:
			TOGGLE_BIT(PORTD,PINn);
			break;
		}
	}
}


/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_SetPortDir
 [DISCRIPTION]:	This function is responsible to Setting the direction of a specific Port .
 [Args]: PORTn_ID(n=A,B,C,D) and Direction (input_port or output_port)
 [in] None
 [out] None
 [RUTURN]: Void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_SetPortDir(uint8 PORTn , GPIO_PortDirection Dir){
	if((PORTn >= NUM_OF_PORTS)){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			if(Dir == port_output){
				DDRA = Dir;
			}
			else
			{
				DDRA = Dir;
			}
			break;
		case PORTB_ID:
			if(Dir == port_output){
				DDRB = Dir;
			}
			else
			{
				DDRB = Dir;
			}
			break;
		case PORTC_ID:
			if(Dir == port_output){
				DDRC = Dir;
			}
			else
			{
				DDRC = Dir;
			}
			break;
		case PORTD_ID:
			if(Dir == port_output){
				DDRD = Dir;
			}
			else
			{
				DDRD = Dir;
			}
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_ReadPort
 [DISCRIPTION]:	This function is responsible to Read the value from a specific PORT .
 [Args]: PORTn_ID(n=A,B,C,D)
 [in] None
 [out] None
 [RUTURN]: uint8
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
uint8 GPIO_ReadPort(uint8 PORTn){
	uint8 data;
	if(PORTn >= NUM_OF_PORTS){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			data=PINA;
			break;
		case PORTB_ID:
			data=PINB;
			break;
		case PORTC_ID:
			data=PINC;
			break;
		case PORTD_ID:
			data=PIND;
			break;
		}
	}
	return data;
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_WritePort
 [DISCRIPTION]:	This function is responsible to Write (1 or 0) on a specific port .
 [Args]: PORTn_ID(n=A,B,C,D) and PINn_ID(n =0...7) and Level (logic_low or logic_high)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_WritePort(uint8 PORTn, uint8 value ){
	if(PORTn >= NUM_OF_PORTS){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			PORTA= value;
			break;
		case PORTB_ID:
			PORTB= value;
			break;
		case PORTC_ID:
			PORTC= value;
			break;
		case PORTD_ID:
			PORTD= value;
			break;
		}
	}
}

/*--------------------------------------------------------------------------------------
 [FUNCTION NAME]: GPIO_FlipPort
 [DISCRIPTION]:	This function is responsible to Flipping the value of a specific port .
 [Args]: PORTn_ID(n=A,B,C,D)
 [in] None
 [out] None
 [RUTURN]: void
 [NOTE]: if Number of PORTn >= 4 the function will Do "nothing"
 ---------------------------------------------------------------------------------------*/
void GPIO_FlipPort(uint8 PORTn){
	if(PORTn >= NUM_OF_PORTS){
		/*WILL DO NOTHING Just Prevent The Else To Implement*/
	}
	else
	{
		switch(PORTn){
		case PORTA_ID:
			PORTA= ~PORTA;
			break;
		case PORTB_ID:
			PORTB=  ~PORTB;
			break;
		case PORTC_ID:
			PORTC=  ~PORTC;
			break;
		case PORTD_ID:
			PORTD=  ~PORTD;
			break;
		}
	}
}
