/*
 * ROAD_MAP.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mahmoud Niazy
 *
 *      Description : it Hardware addressing of register in
 *      Macro controller
 */

#ifndef ROAD_MAP_ROAD_MAP_H_
#define ROAD_MAP_ROAD_MAP_H_

/*********************DIO************************/


/*********************EXTernal Interrupt************************/

// SELECT MODE INT0 INT 1
#define MCUCR   *((volatile u8*)(0x55))
#define ISC11      3
#define ISC10      2

#define ISC01      1
#define ISC00      0


//// SELECT MODE  INT 2
#define MCUCSR  *((volatile u8*)(0x54))

#define ISC2        6

// ENBALE OR DISALE PIE0  PIE1  PIE2
#define  GICR   *((volatile u8*)(0x5B))

#define INT0      6
#define INT1      7
#define INT2      5
// PIF H.W FLAG
#define GIFR    *((volatile u8*)(0x5A))

#define INTF0      6
#define INTF1      7
#define INTF2      5

/*********************Global Interrupt************************/
#define SREG     *((volatile u8 *)0x5f)

#define  I      7



#endif /* ROAD_MAP_ROAD_MAP_H_ */
