################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-APP/Smart_Home_program.c \
../1-APP/main.c 

OBJS += \
./1-APP/Smart_Home_program.o \
./1-APP/main.o 

C_DEPS += \
./1-APP/Smart_Home_program.d \
./1-APP/main.d 


# Each subdirectory must supply rules for building sources it contributes
1-APP/%.o: ../1-APP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=10000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


