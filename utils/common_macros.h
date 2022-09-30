/*******************************************************************************
 *
 *  [   Module  ]: common macros
 *
 *  [ File Name ]: common_macros.h
 *
 *  [Description]: Macros That Commonly Used .
 *
 *  [Author]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_UTILS_COMMON_MACROS_H_
#define SRC_UTILS_COMMON_MACROS_H_

/* [Description]: Writer One at specific place in register  */
#define SET_BIT(REG,BIT)         (REG |= (1<<BIT))

/* [Description]: Writer Zero at specific place in register  */
#define CLEAR_BIT(REG,BIT)       (REG &= (~(1<<BIT)))

/* [Description]: Change The Value at specific place in register
 * [Example]: Toggle Bit number 5
 *                        _______________
 *     REGISTER      ==> |0|0|1|1|1|0|1|0|
 *                        _______________
 *     After toggle  ==> |0|0|1|0|1|0|1|0|
 */
#define TOGGLE_BIT(REG,BIT)      (REG ^= (1<<BIT))

/* [Description]: Check if a specific bit is one or zero
 * [Return]: ONE(TRUE) if the already the bit is set(1)
 *           ZERO(FALSE) if the bit is clear(0)
 */
#define BIT_IS_SET(REG,BIT)      (REG & (1<<BIT))

/* [Description]: Check if a specific bit is one or zero
 * [Return]: ONE(TRUE) if the already the bit is clear(0)
 *           ZERO(FALSE) if the bit is set(1)
 */
#define BIT_IS_CLEAR(REG,BIT)    (!(REG & (1<<BIT)))

/* [Description]: Rotate Right a specific bits in Register
 * [Example]: Rotate Right bit number 3
 *                        _______________
 *     REGISTER      ==> |0|0|1|1|1|0|1|0|
 *                        _______________
 *     After Rotate  ==> |0|1|0|0|0|1|1|1|
 */
#define ROR(REG,BTIT)            (REG=(REG>>BIT) | (REG<<(8-BIT)))

/* [Description]: Rotate Left a specific bits in Register
 * [Example]: Rotate Left bit number 3
 *                        _______________
 *     REGISTER      ==> |0|0|1|1|1|0|1|0|
 *                        _______________
 *     After Rotate  ==> |1|1|0|1|0|0|0|1|
 */
#define ROL(REG,BIT)             (REG=(REG<<BIT) | (REG>>(8-BIT)))

#endif /* SRC_UTILS_COMMON_MACROS_H_ */
