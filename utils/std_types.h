/*******************************************************************************
 *
 *  [Module]: Stander Types
 *
 *  [File Name]: std_types.h
 *
 *  [Description]: All common types That need it to use .
 *
 *  [Author]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_UTILS_STD_TYPES_H_
#define SRC_UTILS_STD_TYPES_H_
#include <stdbool.h>
/*------------------------------------------------------------------------------
 *                                 DEFINITIONS
 *------------------------------------------------------------------------------*/
#define NULL    ((void*)0)
#define FALSE        (0u)
#define TRUE         (1u)

#define DISABLE      (0u)
#define ENABLE       (1u)


#define LOGIC_LOW    (0u)
#define LOGIC_HIGH   (1u)

#define SUSPEND      (0u)
#define ACTIVE       (1u)

/*------------------------------------------------------------------------------
 *                                    TYPES
 *------------------------------------------------------------------------------*/
/* Boolean Data Type */
typedef unsigned char Boolean;

/* unsigned Data types */
typedef unsigned char uint8;         /*                   0..255                     */
typedef unsigned short uint16;       /*                  0..65535                    */
typedef unsigned long uint32;        /*                0..4294967295                 */
typedef unsigned long long uint64;   /*           0..1844674407370955                */

/* Signed Data types */
typedef signed char sint8;           /*                 -128 .. +127                 */
typedef signed short sint16;         /*               -32768 .. +3276                */
typedef signed long sint32;          /*          -2147483648 .. +2147483647          */
typedef signed long long sint64;     /* -9223372036854775808 .. +9223372036854775807 */

/* float types*/
typedef float float32;
typedef double float64;

typedef bool boolean;
typedef enum{
	logic_low,
	logic_high
}STD_LevelType;

/*------------------------------------------------------------------------------
 *                                REGISTER 8_BITS
 *------------------------------------------------------------------------------*/

/* Define register 8 bit */
typedef unsigned char byte;
typedef union{
	byte Data; /* Data is variable 8 bits size */
	struct{
		byte BIT0:1; /* 1 bit size */
		byte BIT1:1;
		byte BIT2:1;
		byte BIT3:1;
		byte BIT4:1;
		byte BIT5:1;
		byte BIT6:1;
		byte BIT7:1;
	}BITS;
}STD_Reg_8bits;
#endif /* SRC_UTILS_STD_TYPES_H_ */
