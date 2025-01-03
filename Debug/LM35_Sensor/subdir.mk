################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LM35_Sensor/lm35_sensor.c 

OBJS += \
./LM35_Sensor/lm35_sensor.o 

C_DEPS += \
./LM35_Sensor/lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
LM35_Sensor/%.o: ../LM35_Sensor/%.c LM35_Sensor/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


