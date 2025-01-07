/*
 * DIO_PROGRAM.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mahmoud
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"

#include <avr/io.h>
#include "DIO_INTERFACE.h"
//    EX                  PORT_A         PIN_5        INPUT
void vSET_PIN_DIRECTION(u8 PORT_NUM , u8 PIN_NUM , u8 DIRECTION)
{
	switch(DIRECTION)
	{
	case OUTPUT:

		switch(PORT_NUM)
		{
		case PORT_A: SET_BIT(DDRA,PIN_NUM); break;
		case PORT_B: SET_BIT(DDRB,PIN_NUM); break;
		case PORT_C: SET_BIT(DDRC,PIN_NUM); break;
		case PORT_D: SET_BIT(DDRD,PIN_NUM); break;
		}

		break;



		case INPUT:

			switch(PORT_NUM)
			{
			case PORT_A: CLEAR_BIT(DDRA,PIN_NUM); break;
			case PORT_B: CLEAR_BIT(DDRB,PIN_NUM); break;
			case PORT_C: CLEAR_BIT(DDRC,PIN_NUM); break;
			case PORT_D: CLEAR_BIT(DDRD,PIN_NUM); break;
			}
			break;



	}

}


//   EX                    PORT_A         PIN_5        LOW
void vSET_PIN_OUTPUT_VALUE(u8 PORT_NUM,u8 PIN_NUM,u8 OUTPUT_VALUE)
{
	switch(OUTPUT_VALUE)
	{
	case HIGH:
		switch(PORT_NUM)
		{
		case PORT_A : SET_BIT(PORTA,PIN_NUM);  break;
		case PORT_B : SET_BIT(PORTB,PIN_NUM);  break;
		case PORT_C : SET_BIT(PORTC,PIN_NUM);  break;
		case PORT_D : SET_BIT(PORTD,PIN_NUM);  break;

		}

		break;

		case LOW:

			switch(PORT_NUM)
			{
			case PORT_A : CLEAR_BIT(PORTA,PIN_NUM);  break;
			case PORT_B : CLEAR_BIT(PORTB,PIN_NUM);  break;
			case PORT_C : CLEAR_BIT(PORTC,PIN_NUM);  break;
			case PORT_D : CLEAR_BIT(PORTD,PIN_NUM);  break;

			}

			break;

	}
}



//   EX          PORT_A         PIN_5
u8 u8READ_PIN(u8 PORT_NUM,u8 PIN_NUM)
{
	u8 read=0;
	switch(PORT_NUM)
	{
	case PORT_A: read = GET_BIT(PINA,PIN_NUM); break;
	case PORT_B: read = GET_BIT(PINB,PIN_NUM);break;
	case PORT_C:read = GET_BIT(PINC,PIN_NUM); break;
	case PORT_D: read = GET_BIT(PIND,PIN_NUM);break;

	}
	return read ;
}


//   EX          PORT_A         PIN_5
void vToggel_PIN(u8 PORT_NUM,u8 PIN_NUM)
{
	switch(PORT_NUM)
	{
	case PORT_A: TOG_BIT(PORTA,PIN_NUM); break;
	case PORT_B:TOG_BIT(PORTB,PIN_NUM); break;
	case PORT_C: TOG_BIT(PORTC,PIN_NUM);break;
	case PORT_D:TOG_BIT(PORTD,PIN_NUM); break;

	}
}



//  EX                       PORT_A        0x0f|0xf0 | 36
void vSET_PORT_DIRECTION(u8 PORT_NUM, u8 DIRECTION_value)
{

	switch(PORT_NUM)
	{
	case PORT_A :    DDRA = DIRECTION_value; break;
	case PORT_B : 	 DDRB = DIRECTION_value; break;
	case PORT_C : 	 DDRC = DIRECTION_value;break;
	case PORT_D :	 DDRD = DIRECTION_value;  break;
	}

}


//   EX                       PORT_A       0x0f|0xf0 | 36
void vSET_PORT_OUTPUT_VALUE(u8 PORT_NUM,u8 OUTPUT_VALUE)
{
	switch(PORT_NUM)
	{
	case PORT_A :    PORTA = OUTPUT_VALUE; break;
	case PORT_B : 	 PORTB = OUTPUT_VALUE; break;
	case PORT_C : 	 PORTC = OUTPUT_VALUE;break;
	case PORT_D :	 PORTD = OUTPUT_VALUE;  break;
	}
}

