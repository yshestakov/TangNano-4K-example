################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USER/gw1ns4c_it.c \
../USER/main.c \
../USER/malloc.c 

OBJS += \
./USER/gw1ns4c_it.o \
./USER/main.o \
./USER/malloc.o 

C_DEPS += \
./USER/gw1ns4c_it.d \
./USER/main.d \
./USER/malloc.d 


# Each subdirectory must supply rules for building sources it contributes
USER/%.o: ../USER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_mm\CORE" -I"C:\GMD\workspace\cm3_mm\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_mm\SYSTEM" -I"C:\GMD\workspace\cm3_mm\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


