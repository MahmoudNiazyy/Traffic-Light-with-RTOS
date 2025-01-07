################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/SPI/subdir.mk
-include MCAL/GLOBAL_INTERRUPT/subdir.mk
-include MCAL/EXTERNAL_INTERRUPT/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include FREE_RTOS/subdir.mk
-include APP/Traffic_Led/subdir.mk
-include APP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ReNile_TrafficLed_Project_RTOS.lss \

FLASH_IMAGE += \
ReNile_TrafficLed_Project_RTOS.hex \

EEPROM_IMAGE += \
ReNile_TrafficLed_Project_RTOS.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ReNile_TrafficLed_Project_RTOS.elf secondary-outputs

# Tool invocations
ReNile_TrafficLed_Project_RTOS.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ReNile_TrafficLed_Project_RTOS.map -mmcu=atmega32 -o "ReNile_TrafficLed_Project_RTOS.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ReNile_TrafficLed_Project_RTOS.lss: ReNile_TrafficLed_Project_RTOS.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ReNile_TrafficLed_Project_RTOS.elf  >"ReNile_TrafficLed_Project_RTOS.lss"
	@echo 'Finished building: $@'
	@echo ' '

ReNile_TrafficLed_Project_RTOS.hex: ReNile_TrafficLed_Project_RTOS.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ReNile_TrafficLed_Project_RTOS.elf  "ReNile_TrafficLed_Project_RTOS.hex"
	@echo 'Finished building: $@'
	@echo ' '

ReNile_TrafficLed_Project_RTOS.eep: ReNile_TrafficLed_Project_RTOS.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ReNile_TrafficLed_Project_RTOS.elf  "ReNile_TrafficLed_Project_RTOS.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ReNile_TrafficLed_Project_RTOS.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ReNile_TrafficLed_Project_RTOS.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ReNile_TrafficLed_Project_RTOS.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
