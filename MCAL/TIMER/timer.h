/*******************************************************************************
 *
 *  [   Module  ]: Timer's Modules
 *
 *  [ File Name ]: timer.h
 *
 *  [Description]: Header File for AVR_Timer Module
 *
 *  [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_TIMER_TIMER_H_
#define SRC_MCAL_TIMER_TIMER_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/* Enable The Timer's required */
/* NOTE : Timer0 and Timer1 share the same PreScaler Module */
#define TIMER0_Enable                            ENABLE
#define TIMER1_Enable                            ENABLE
#define TIMER2_Enable                            ENABLE


/* After you Enabled required Timer's
 * Start Configure :
 * --> [Mode]
 * --> [OCn Behavior]
 * --> [PreScaler]
 * --> [Interrupt]
 */

/*------------------------------------------------------------------------------
 *                             [TIMER0 Configurations]
 *------------------------------------------------------------------------------*/

/* [Description]: Easy to configure Timer0 mode just copy Mask of mode and past in Mode selector
 *
 * [Example]: #define TIMER0_Mode_Selector   TIMER0_Mode_Ctc_msk
 *            like this you configure Timer0 to work with CTC mode .
 *
 * [SELECT TIMER0 Mode's]:
 *
 * --> [TIMER0_Mode_Ovf_msk] -->  (Normal Mode)
 * --> [TIMER0_Mode_Pwm_PhaseCorrect_msk]
 * --> [TIMER0_Mode_Ctc_msk]
 * --> [TIMER0_Mode_FastPwm_msk]
 *
 */
#define TIMER0_Mode_Selector                 TIMER0_Mode_Ovf_msk

/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *----   [NOW Let's Go To Configure OC0 Pin Behavior Depend on Mode 🙂]   -----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to configure OC0 pin behavior in Timer0 just copy Mask of pin behavior
 *                And past in Behavior selector .
 *
 * [Example]:
 *           #define TIMER0_OC0_Behavior_Selector       TIMER0_OC0_CLR_msk
 *           like this you configure OC0 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER0 OC0 pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER0_OC0_TOGGLE_msk]    -->  (Toggle OC0 on compare match)
 * --> [TIMER0_OC0_CLR_msk]       -->  (Clear OC0 on compare match)
 * --> [TIMER0_OC0_SET_msk]       -->  ( Set OC0 on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER0_OC0_NON_INVERTING_msk]    --> (FAST_PWM          -> Clear OC0 on compare match, set OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Clear OC0 on compare match when count-up, set OC0 on compare match when count-down)
 * --> [TIMER0_OC0_INVERTING_msk]        --> (FAST_PWM          -> Set OC0 on compare match, clear OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Set OC0 on compare match when count-up, Clear OC0 on compare match when count-down)
 *
 * */
#define TIMER0_OC0_Behavior_Selector         TIMER0_OC0_INVERTING_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *----    [NOW Let's Go To Select The PreScaler required for TIMER0 🙂]    ----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to Configure PreScaler in Timer0 just copy Mask of
 *                required PreScaler and past it at PreScaler Selector .
 *
 * [Example]:
 *           #define TIMER0_PreScaler_Selector       TIMER0_Clk_With_8_PreScaler_msk
 *           like this you configure TIMER0 To work with PreScaler 8 .
 *
 * [Select the required TIMER0 PreScaler From]:
 *
 * --> [TIMER0_Clk_With_No_PreScaler_msk]
 * --> [TIMER0_Clk_With_8_PreScaler_msk]
 * --> [TIMER0_Clk_With_64_PreScaler_msk]
 * --> [TIMER0_Clk_With_256_PreScaler_msk]
 * --> [TIMER0_Clk_With_1024_PreScaler_msk]
 *
 * --> [TIMER0_External_Clk_With_Falling_Edge_msk]
 * --> [TIMER0_External_Clk_With_Rising_Edge_msk]
 *
 */
#define TIMER0_PreScaler_Selector                 TIMER0_Clk_With_1024_PreScaler_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *--- [NOW Let's Go To Enable The Type Of Interrupt Required for TIMER0 🙂] ---*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/


/*
 * [Description]: Easy to Configure Interrupt in Timer0 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER0_OVF_INT_EN      ENABLE
 *
 * [TIMER0 Enterrupt's]:
 *
 * --> [TIMER0_OVF_INT_EN]
 * --> [TIMER0_COMP_INT_EN]
 *
 */
#define TIMER0_OVF_INT_EN               ENABLE
#define TIMER0_COMP_INT_EN              DISABLE


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *------  [NOW Let's Go To Initialize TIMER0 Value And Compare Value 🙂]  -----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/


/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to Enable more than one timer at the same time .
 */

#define TIMER0_Initial_Value                        0
#define TIMER0_Compare_Value                        0


/*------------------------------------------------------------------------------
 *                             [TIMER2 Configurations]
 *------------------------------------------------------------------------------*/

/* [Description]: Easy to configure Timer2 mode just copy Mask of mode and past in Mode selector .
 *
 * [Example]: #define TIMER2_Mode_Selector   TIMER2_Mode_Ctc_msk
 *            like this you configure Timer2 to work with CTC mode .
 *
 * [SELECT TIMER2 Mode's]:
 *
 * --> [TIMER2_Mode_Ovf_msk] -->  (Normal Mode)
 * --> [TIMER2_Mode_Pwm_PhaseCorrect_msk]
 * --> [TIMER2_Mode_Ctc_msk]
 * --> [TIMER2_Mode_FastPwm_msk]
 *
 */
#define TIMER2_Mode_Selector                 TIMER2_Mode_Ovf_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *----   [NOW Let's Go To Configure OC2 Pin Behavior Depend on Mode 🙂]   -----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to configure OC2 pin behavior in Timer2 just copy Mask of pin behavior
 *                And past in Behavior selector .
 *
 * [Example]:
 *           #define TIMER2_OC2_Behavior_Selector       TIMER2_OC2_CLR_msk
 *           like this you configure OC2 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER2 OC2 pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER2_OC2_TOGGLE_msk]    -->  (Toggle OC2 on compare match)
 * --> [TIMER2_OC2_CLR_msk]       -->  (Clear OC2 on compare match)
 * --> [TIMER2_OC2_SET_msk]       -->  ( Set OC2 on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER2_OC2_NON_INVERTING_msk]    --> (     FAST_PWM     -> Clear OC0 on compare match, set OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Clear OC0 on compare match when count-up, set OC0 on compare match when count-down)
 * --> [TIMER2_OC2_INVERTING_msk]        --> (     FAST_PWM     -> Set OC0 on compare match, clear OC0 at BOTTOM)
 *                                       --> (Phase Correct PWM -> Set OC0 on compare match when count-up, Clear OC0 on compare match when count-down)
 */
#define TIMER2_OC2_Behavior_Selector         TIMER2_OC2_NON_INVERTING_msk

/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *----    [NOW Let's Go To Select The PreScaler required for TIMER2 🙂]    ----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to Configure PreScaler in Timer2 just copy Mask of
 *                required PreScaler and past it at PreScaler Selector .
 *
 * [Example]:
 *           #define TIMER2_PreScaler_Selector       TIMER2_Clk_With_8_PreScaler_msk
 *           like this you configure TIMER2 To work with PreScaler 8 .
 *
 * [Select the required TIMER2 PreScaler From]:
 *
 * --> [TIMER2_Clk_With_No_PreScaler_msk]
 * --> [TIMER2_Clk_With_8_PreScaler_msk]
 * --> [TIMER2_Clk_With_32_PreScaler_msk]
 * --> [TIMER2_Clk_With_64_PreScaler_msk]
 * --> [TIMER2_Clk_With_128_PreScaler_msk]
 * --> [TIMER2_Clk_With_256_PreScaler_msk]
 * --> [TIMER2_Clk_With_1024_PreScaler_msk]
 *
 */
#define TIMER2_PreScaler_Selector               TIMER2_Clk_With_1024_PreScaler_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *--- [NOW Let's Go To Enable The Type Of Interrupt Required for TIMER2 🙂] ---*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/


/*
 * [Description]: Easy to Configure Interrupt in Timer2 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER2_OVF_INT_EN      ENABLE
 *
 * [TIMER2 Enterrupt's]:
 *
 * --> [TIMER2_OVF_INT_EN]
 * --> [TIMER2_COMP_INT_EN]
 *
 */
#define TIMER2_OVF_INT_EN               ENABLE
#define TIMER2_COMP_INT_EN              DISABLE

/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to Enable more than one timer at the same time .
 */
#define TIMER2_Initial_Value                        0
#define TIMER2_Compare_Value                        0


/*------------------------------------------------------------------------------
 *                             [TIMER1 Configurations]
 *------------------------------------------------------------------------------*/

/* [Description]: Easy to configure Timer1 mode just copy Mask of mode and past in Mode selector .
 *
 * [Example]: #define TIMER1_Mode_Selector   TIMER1_Mode_Ctc_msk
 *            like this you configure Timer1 to work with CTC mode .
 *
 * [SELECT TIMER1 Mode's]:
 *
 * --> [TIMER1_Mode_Ovf_msk]  -->  (Normal Mode)
 * --> [TIMER1_Mode_Pwm_PhaseCorrect_8_bit_msk]
 * --> [TIMER1_Mode_Pwm_PhaseCorrect_9_bit_msk]
 * --> [TIMER1_Mode_Pwm_PhaseCorrect_10_bit_msk]
 * --> [TIMER1_Mode_Ctc_msk]
 * --> [TIMER1_Mode_FastPwm_8_bit_msk]
 * --> [TIMER1_Mode_FastPwm_9_bit_msk]
 * --> [TIMER1_Mode_FastPwm_10_bit_msk]
 * --> [TIMER1_Mode_Pwm_Phase_Frequency_Correct_msk]
 * --> [TIMER1_Mode_Pwm_Phase_Correct_msk]
 * --> [TIMER1_Mode_Fast_Pwm_msk]
 */
#define TIMER1_Mode_Selector                TIMER1_Mode_Ovf_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *--- [NOW Let's Go To Configure OC1A/OC1B Pin Behavior Depend on Mode 🙂] ----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to configure OC1A/OC1B pin behavior in Timer1 just copy Mask
 *                Of pin behavior and past in Behavior selector .
 *
 * [Example]:
 *           #define TIMER1_OC1_Behavior_Selector       TIMER1_OC1_CLR_msk
 *           like this you configure OC1 pin behavior to work depend on mode (non-pwm mode).
 *
 * [TIMER1 OC1A/OC1B pin behavior]:
 *
 * (non-PWM mode):
 * --> [TIMER1_OC1_TOGGLE_msk]                     -->  (Toggle OC1A/OC1B on compare match)
 * --> [TIMER1_OC1_CLR_msk]                        -->  (Clear OC1A/OC1B on compare match)
 * --> [TIMER1_OC1_SET_msk]                        -->  (Set OC1A/OC1B on compare match)
 *
 * (Fast PWM mode or Phase Correct PWM Mode ):
 * --> [TIMER1_OC1_NON_INVERTING_msk]              --> (Clear OC1A/OC1B on compare match, set OC1A/OC1B at BOTTOM)
 * --> [TIMER1_OC1_INVERTING_msk]                  --> (Set OC1A/OC1B on compare match, clear OC1A/OC1B at BOTTOM)
 *
 *
 * [Special TIMER1 OC1A/OC1B pin behavior]:
 *
 * (Fast PWM):
 * --> [TIMER1_OC1_SPECIAL_TOGGLE_FastPWM_msk]          --> (WGM13:0 = 15: Toggle OC1A on Compare Match,OC1B disconnected (normal port operation).)
 *                                                      --> (Other Value For WGM13:0 The OCnA/OCnB will be disconnected)
 * (Phase Correct and Phase and Frequency Correct PWM):
 * --> [TIMER1_OC1_SPECIAL_TOGGLE_Phase_Correct_msk]    --> (WGM13:0 = 9 or 14: Toggle OCnA on Compare Match, OCnB disconnected (normal port operation).)
 *                                                      --> (Other Value For WGM13:0 The OC1A/OC1B will be disconnected)
 */
#define TIMER1_OC1_Behavior_Selector         TIMER1_OC1_SET_msk

/* Now Enable Required OC1 Pins
 *
 * [TIMER1 OCn Pin's]:
 *
 * --> [TIMER1_OC1A_Select]
 * --> [TIMER1_OC1B_Select]
 *
 * [NOTE]: You Can Enable Two Output Compare Pins OC1A And OC1B
 */
#define TIMER1_OC1A_Select                   ENABLE
#define TIMER1_OC1B_Select                   ENABLE


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *----    [NOW Let's Go To Select The PreScaler required for TIMER1 🙂]    ----*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/

/*
 * [Description]: Easy to Configure PreScaler in Timer1 just copy Mask of
 *                required PreScaler and past it at PreScaler Selector .
 *
 * [Example]:
 *           #define TIMER1_PreScaler_Selector       TIMER1_Clk_With_8_PreScaler_msk
 *           like this you configure TIMER1 To work with PreScaler 8 .
 *
 * [Select the required TIMER1 PreScaler From]:
 *
 * --> [TIMER1_Clk_With_No_PreScaler_msk]
 * --> [TIMER1_Clk_With_8_PreScaler_msk]
 * --> [TIMER1_Clk_With_64_PreScaler_msk]
 * --> [TIMER1_Clk_With_256_PreScaler_msk]
 * --> [TIMER1_Clk_With_1024_PreScaler_msk]
 *
 * --> [TIMER1_External_Clk_With_Falling_Edge_msk]
 * --> [TIMER1_External_Clk_With_Rising_Edge_msk]
 *
 */
#define TIMER1_PreScaler_Selector                TIMER1_Clk_With_1024_PreScaler_msk


/*------------------                                         ------------------*
 *-------------                                                   -------------*
 *--------                                                             --------*
 *--- [NOW Let's Go To Enable The Type Of Interrupt Required for TIMER1 🙂] ---*
 *--------                                                             --------*
 *-------------                                                   -------------*
 *------------------                                         ------------------*/


/*
 * [Description]: Easy to Configure Interrupt in Timer1 just Write Enable at
 *                Required Interrupt Type .
 *
 * [Example]: #define TIMER1_OVF_INT_EN      ENABLE
 *
 * [TIMER1 Enterrupt's]:
 *
 * --> [TIMER1_OVF_INT_EN]
 * --> [TIMER1_COMPA_INT_EN]
 * --> [TIMER1_COMPB_INT_EN]
 *
 */
#define TIMER1_OVF_INT_EN               DISABLE
#define TIMER1_COMPA_INT_EN             ENABLE
#define TIMER1_COMPB_INT_EN             DISABLE

/*
 * Why do for every timer Initial and Compare value ?
 * - In case required to initialize more than one timer
 */

#define TIMER1_Initial_Value                        0
#define TIMER1_CompareA_Value                       0
#define TIMER1_CompareB_Value                       0


/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
 *******************************************************************************/

/*
 * [FUNCTION NAME]: TIMER_Init
 * [DISCRIPTION]  : This function is responsible to initialization one or more than one timer at
 *                  The same time from Configuration of timer .
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_Init(void);



/*
 * [FUNCTION NAME]: TIMER_Deinit
 * [DISCRIPTION]  : This function is responsible to De-initialization all Timers
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_Deinit(void);



/*
 * [FUNCTION NAME]: TIMER_SetCallBack
 * [DISCRIPTION]  : This function's is responsible to set the Call Back function address.
 *                  Every set callback function follow specific Timer.
 * [Args]  : Pointer To Function take void and return void
 * [RUTURN]: Void
 */
void TIMER0_SetCallBack(void (*Ptr_To_fun)(void));
void TIMER1_SetCallBack(void (*Ptr_To_fun)(void));
void TIMER2_SetCallBack(void (*Ptr_To_fun)(void));


/*
 * [FUNCTION NAME]: TIMER_EnableInterrupt
 * [DISCRIPTION]  : This function is responsible to Enable The required Type of Interrupt
 *                  Depend on Timer That you made it Enable.
 * [Args]  : void
 * [RUTURN]: Void
 */
void TIMER_EnableInterrupt(void);

#endif /* SRC_MCAL_TIMER_TIMER_H_ */
