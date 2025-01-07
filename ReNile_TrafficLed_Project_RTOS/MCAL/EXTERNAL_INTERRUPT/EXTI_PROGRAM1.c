/*
 * EXTI_PROGRAM1.c
 *
 *  Created on: Jan 6, 2025
 *      Author: Mahmoud
 */



#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "EXTI_INTRFACE1.h"

void (*PTR1)(void)=NULL;
void (*PTR2)(void)=NULL;
void (*PTR3)(void)=NULL;
//                       exti0         raising
//                       exti1         falling
void EXTI_SELECT_MODE(u8 EXTI_NAME, u8 EXTI_MODE)
{
	switch(EXTI_NAME)
	{

	case EXTI_0:
		switch(EXTI_MODE)
		{
		case LOW_LEVEL:
			CLEAR_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLEAR_BIT(MCUCR,ISC01);
			break;
		case FALLING_E:
			CLEAR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		case RAISING_E:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		break;

		case EXTI_1:
			switch(EXTI_MODE)
			{
			case LOW_LEVEL:
				CLEAR_BIT(MCUCR,ISC11);
				CLEAR_BIT(MCUCR,ISC10);
				break;
			case LOGIC_CHANGE:
				CLEAR_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			case FALLING_E:
				CLEAR_BIT(MCUCR,ISC10);
				SET_BIT(MCUCR,ISC11);
				break;
			case RAISING_E:
				SET_BIT(MCUCR,ISC11);
				SET_BIT(MCUCR,ISC10);
				break;
			}

			break;


			case EXTI_2:
				switch(EXTI_MODE)
				{

				case FALLING_E:  CLEAR_BIT(MCUCSR,ISC2);  break;

				case RAISING_E:  SET_BIT(MCUCSR,ISC2);   break;
				}
				break;
	}

}


void EXTI_SELECT_INTERRUBT_ENABLE(u8 EXTI_NAME)
{
	switch(EXTI_NAME)
	{
	case EXTI_0:  SET_BIT(GICR,INT0);  break;


	case EXTI_1: SET_BIT(GICR,INT1);  break;



	case EXTI_2: SET_BIT(GICR,INT2);   break;
	}

}

void EXTI_SELECT_INTERRUBT_DISABLE(u8 EXTI_NAME)
{
	switch(EXTI_NAME)
	{
	case EXTI_0:  CLEAR_BIT(GICR,INT0);  break;


	case EXTI_1: CLEAR_BIT(GICR,INT1);  break;



	case EXTI_2: CLEAR_BIT(GICR,INT2);   break;
	}
}




u8 EXTI_READ_FLAG(u8 EXTI_NAME)
{
	u8 read = 0;


	switch(EXTI_NAME)
	{
	case EXTI_0:   read= GET_BIT(GIFR,INTF0); break;


	case EXTI_1:  read= GET_BIT(GIFR,INTF1); break;



	case EXTI_2:  read= GET_BIT(GIFR,INTF2);  break;
	}

	return read;
}

void ISR_EXTI0(void (*FPTR)(void))
{
	PTR1=FPTR;
}


void ISR_EXTI1(void (*FPTR)(void))
{
	PTR2=FPTR;
}
void ISR_EXTI2(void (*FPTR)(void))
{
	PTR3=FPTR;
}


//void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
//void __vector_1 (void){
//	// TASK1
//	if(PTR1 !=NULL)
//	{
//		PTR1();
//	}
//
//}

//
//void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
//void __vector_2 (void){
//	// TASK1
//	if(PTR2 !=NULL)
//	{
//		PTR2();
//	}
//
//}



