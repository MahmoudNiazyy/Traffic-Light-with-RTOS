################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/GLOBAL_INTERRUPT/GI_PROGRAM.c 

OBJS += \
./MCAL/GLOBAL_INTERRUPT/GI_PROGRAM.o 

C_DEPS += \
./MCAL/GLOBAL_INTERRUPT/GI_PROGRAM.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/GLOBAL_INTERRUPT/%.o: ../MCAL/GLOBAL_INTERRUPT/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


