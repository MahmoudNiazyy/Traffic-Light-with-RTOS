/*
 * GI_PROGRAM.c
 *
 *  Created on: Oct 5, 2024
 *      Author: Mahmoud
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPE.h"
#include "../../ROAD_MAP/ROAD_MAP.h"
#include "GI_INTERFACE.h"

void GI_ENABLE()
{
	SET_BIT(SREG,I);
}

void GI_DISABLE()
{
	CLEAR_BIT(SREG,I);
}
