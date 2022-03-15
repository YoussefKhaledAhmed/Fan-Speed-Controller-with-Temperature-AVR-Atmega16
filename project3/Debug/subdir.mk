################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LM35_TEMP_SENSOR.c \
../PROJECT_3.c \
../adc.c \
../dc_motor.c \
../gpio.c \
../lcd.c \
../pwm.c 

OBJS += \
./LM35_TEMP_SENSOR.o \
./PROJECT_3.o \
./adc.o \
./dc_motor.o \
./gpio.o \
./lcd.o \
./pwm.o 

C_DEPS += \
./LM35_TEMP_SENSOR.d \
./PROJECT_3.d \
./adc.d \
./dc_motor.d \
./gpio.d \
./lcd.d \
./pwm.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


