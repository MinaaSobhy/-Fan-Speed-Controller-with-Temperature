################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../dcmotor.c \
../gpio.c \
../lcd.c \
../lm35.c \
../project3_main.c \
../pwm_timer0.c 

OBJS += \
./adc.o \
./dcmotor.o \
./gpio.o \
./lcd.o \
./lm35.o \
./project3_main.o \
./pwm_timer0.o 

C_DEPS += \
./adc.d \
./dcmotor.d \
./gpio.d \
./lcd.d \
./lm35.d \
./project3_main.d \
./pwm_timer0.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


