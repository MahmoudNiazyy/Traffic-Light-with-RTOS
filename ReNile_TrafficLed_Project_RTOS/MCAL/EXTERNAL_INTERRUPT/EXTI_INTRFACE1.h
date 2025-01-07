
#ifndef MCAL_EXTERNAL_INTERRUPT_EXTI_INTRFACE1_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTI_INTRFACE1_H_

/**********************EXTI NAME***********************/

#define EXTI_0      0
#define EXTI_1      1
#define EXTI_2      2


/*************************SELECT MODE******************************/

#define LOW_LEVEL     0
#define LOGIC_CHANGE  1

#define FALLING_E     2
#define RAISING_E     3





/*
 * The External Interrupts are triggered by the INT0, INT1, and INT2 pins. Observe that, if enabled,
the interrupts will trigger even if the INT0..2 pins are configured as outputs. This feature provides
a way of generating a software interrupt. The external interrupts can be triggered by a falling or
rising edge or a low level (INT2 is only an edge triggered interrupt). This is set up as indicated in
the specification for the MCU Control Register – MCUCR – and MCU Control and Status Register – MCUCSR. When the external interrupt is enabled and is configured as level triggered (only
INT0/INT1), the interrupt will trigger as long as the pin is held low. Note that recognition of falling
or rising edge interrupts on INT0 and INT1 requires the presence of an I/O clock

 * in this function select (EXTI(0-2)) and
 * what you want to detect ?
 *  LOW_LEVEL
    LOGIC_CHANGE
    FALLING_E
    RAISING_E
 */
void EXTI_SELECT_MODE(u8 EXTI_NAME, u8 EXTI_MODE);

/*
 * When the INT(0-2) bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external pin interrupt is enabled. The Interrupt Sense Control0 bits 1/0 (ISC01 and ISC00) in the MCU
General Control Register (MCUCR) define whether the External Interrupt is activated on rising
and/or falling edge of the INT0 pin or level sensed. Activity on the pin will cause an interrupt
request even if INT0 is configured as an output. The corresponding interrupt of External Interrupt
Request 0 is executed from the INT0 interrupt vector.
 */

/*
 * in this function select (EXTI(0-2)) and be Enable
 */
void EXTI_SELECT_INTERRUBT_ENABLE(u8 EXTI_NAME);


/*
 * in this function select (EXTI(0-2)) and be Disable
 */
void EXTI_SELECT_INTERRUBT_DISABLE(u8 EXTI_NAME);


// hardware function execute by hardware ISR
void ISR_EXTI0(void (*FPTR)(void));
void ISR_EXTI1(void (*FPTR)(void));
void ISR_EXTI2(void (*FPTR)(void));



u8 EXTI_READ_FLAG(u8 EXTI_NAME);



#endif /* MCAL_EXTERNAL_INTERRUPT_EXTI_INTRFACE1_H_ */
