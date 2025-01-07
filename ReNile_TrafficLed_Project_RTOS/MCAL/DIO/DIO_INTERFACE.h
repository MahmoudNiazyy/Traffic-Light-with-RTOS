/*
 * DIO_INTERFACE.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_DIO_DIO_INTERFACE_H_
#define MCAL_DIO_DIO_INTERFACE_H_



// DIRECTION STATUS
#define INPUT    0  // It detect external volt (read)
#define OUTPUT   1  // it output 1 or 0        (write)


//I/O Hardware PINS
// any port in avr_32 have 8 pin
#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7



// I/O Hardware PORTS NAME
#define PORT_A   0
#define PORT_B   1
#define PORT_C   2
#define PORT_D   3

// OUTPUT STATUS of pin
#define LOW   0 // Active low -> no volt out -> out is 0 V
#define HIGH  1 // Active high -> 5 volt out


/* in this function setup the pin direction by make this pin
 * output or input , so the function have 3 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 * 2-  PIN_NUM : PIN_(0-7)
 * 3- DIRECTION : OUTPUT - INPUT
 */
void vSET_PIN_DIRECTION(u8 PORT_NUM , u8 PIN_NUM , u8 DIRECTION);



/* in this function setup the pin OUT value by make this pin
 * output high (5V) or output low (0V) ,
 *  so the function have 3 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 * 2-  PIN_NUM : PIN_(0-7)
 * 3- OUTPUT_VALUE : HIGH - LOW
 */
void vSET_PIN_OUTPUT_VALUE(u8 PORT_NUM,u8 PIN_NUM,u8 OUTPUT_VALUE);


/* in this function setup the pin in input direction
 *  to read the external volt it
 *  1-> 5v   OR     0 -> 0v
 *
 *  so the function have 2 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 * 2-  PIN_NUM : PIN_(0-7)
 * And return the read of pin
 * but the return have two value ( 1 , 0 )
 *
 */
u8 u8READ_PIN(u8 PORT_NUM,u8 PIN_NUM);



/* in this function setup the pin OUT value by make this pin
 *  change it current value
 *   if output high (5V) will be output low (0V) ,
 *   if output low (0V) will be output high (5V) ,
 *  so the function have 2 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 * 2-  PIN_NUM : PIN_(0-7)
 *
 */
void vToggel_PIN(u8 PORT_NUM,u8 PIN_NUM);





/* in this function setup the PORT direction by make this PORT
 * output or input , so the function have 2 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 *
 * 2- DIRECTION_value : Enter binary or hex or decimal value
 */
void vSET_PORT_DIRECTION(u8 PORT_NUM, u8 DIRECTION_value);





/* in this function setup the PORT Output value
 * by make all pin in PORT
 * output or input , so the function have 2 argument
 * 1 - PORT_NUM : PORT_A - PORT_B -PORT_C - PORT_D
 *
 * 2- OUTPUT_VALUE : Enter binary or hex or decimal value
 */
void vSET_PORT_OUTPUT_VALUE(u8 PORT_NUM,u8 OUTPUT_VALUE);


#endif /* MCAL_DIO_DIO_INTERFACE_H_ */
