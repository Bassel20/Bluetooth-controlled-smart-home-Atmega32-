################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../3-MCAL/DIO/DIO_program.c 

OBJS += \
./3-MCAL/DIO/DIO_program.o 

C_DEPS += \
./3-MCAL/DIO/DIO_program.d 


# Each subdirectory must supply rules for building sources it contributes
3-MCAL/DIO/%.o: ../3-MCAL/DIO/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=10000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


