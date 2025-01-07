/*
 * T_Led.h
 *
 *  Created on: Jan 6, 2025
 *      Author: Mahmoud
 */

#ifndef APP_TRAFFIC_LED_T_LED_H_
#define APP_TRAFFIC_LED_T_LED_H_
typedef enum
{
	false,
	true
}bool_t;

/*
 * in this function set all pin direction for led
 * used in traffic led project As OUTPUT
 */
void vSetUp_TrafficLed_Direction();

/*
 * in this function set all pin direction for Button
 * used in traffic led project As INPUT
 * and PULLUP RESISTORS
 *
 */
void vSetUp_TrafficButton_Direction();
/*
 * control in North_South led Output valve
 * to Enable turn on
 */
void North_South_GreenEnable();

/*
 * control in North_South led Output valve
 * to Disable turn off
 */
void North_South_GreenDisable();


/*
 * control in Yellow (waiting) led Output valve
 * to enable turn on
 */
void Yellow_Enable();


/*
 * control in Yellow (waiting) led Output valve
 * to disable turn off
 */
void Yellow_Disable();


/*
 * control in EAST_WEST led Output valve
 * to enable turn on
 */
void EAST_WEST_GREENEnable();


/*
 * control in EAST_WEST led Output valve
 * to disable turn off
 */
void EAST_WEST_GREENDisable();



#endif /* APP_TRAFFIC_LED_T_LED_H_ */
