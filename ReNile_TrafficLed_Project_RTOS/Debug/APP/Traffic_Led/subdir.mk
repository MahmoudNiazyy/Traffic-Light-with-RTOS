################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Traffic_Led/T_Led_Prohram.c 

OBJS += \
./APP/Traffic_Led/T_Led_Prohram.o 

C_DEPS += \
./APP/Traffic_Led/T_Led_Prohram.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Traffic_Led/%.o: ../APP/Traffic_Led/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


