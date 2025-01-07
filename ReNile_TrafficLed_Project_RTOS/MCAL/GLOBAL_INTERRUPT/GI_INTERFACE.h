/*
 * GI_INTERFACE.h
 *
 *  Created on: Oct 5, 2024
 *      Author: Mahmoud
 */

#ifndef MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_
#define MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_

/*
 * The Global Interrupt Enable bit must be set
 * for the interrupts to be enabled.
 * The individual interrupt enable control is then performed in separate control registers.
 * If the Global Interrupt Enable Register is cleared,
 * none of the interrupts are enabled independent of the individual interrupt
  enable settings.
   The I-bit is cleared by hardware after an interrupt has occurred,
    and is set by the RETI instruction to enable subsequent interrupts.
     The I-bit can also be set and cleared by the application with the SEI and CLI instructions,
      as described in the instruction set reference
 */
void GI_ENABLE();

void GI_DISABLE();

#endif /* MCAL_GLOBAL_INTERRUPT_GI_INTERFACE_H_ */
