################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USER/gw1ns4c_it.c \
../USER/main.c \
../USER/retarget.c 

OBJS += \
./USER/gw1ns4c_it.o \
./USER/main.o \
./USER/retarget.o 

C_DEPS += \
./USER/gw1ns4c_it.d \
./USER/main.d \
./USER/retarget.d 


# Each subdirectory must supply rules for building sources it contributes
USER/%.o: ../USER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_int_priority\CORE" -I"C:\GMD\workspace\cm3_int_priority\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_int_priority\SYSTEM" -I"C:\GMD\workspace\cm3_int_priority\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


