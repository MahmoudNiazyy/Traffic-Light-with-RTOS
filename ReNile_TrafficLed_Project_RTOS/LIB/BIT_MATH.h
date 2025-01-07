/*
 * BIT_MATH.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Mahmoud
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_

/* this macros make any bit select to be one
 by enter variable value and number of bit*/
#define SET_BIT(VAR,BITNO) (VAR|=(1<<BITNO))

/* this macros make any bit select to be Zero
 by enter variable value and number of bit*/
#define CLEAR_BIT(VAR,BITNO) (VAR&=(~(1<<BITNO)))

/* this macros make any bit select to be Toggle
 * if 1 be 0   or  0 be 1
 by enter variable value and number of bit*/
#define TOG_BIT(VAR,BITNO) (VAR^=(1<<BITNO))

/* this macros read any bit select
 by enter variable value and number of bit*/
#define GET_BIT(VAR,BITNO) ((VAR>>BITNO)&1)



#endif /* LIB_BIT_MATH_H_ */
