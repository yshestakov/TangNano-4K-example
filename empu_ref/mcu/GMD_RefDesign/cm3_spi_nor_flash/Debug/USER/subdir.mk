################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../USER/gw1ns4c_it.c \
../USER/main.c \
../USER/retarget.c \
../USER/spi_nor_flash.c 

OBJS += \
./USER/gw1ns4c_it.o \
./USER/main.o \
./USER/retarget.o \
./USER/spi_nor_flash.o 

C_DEPS += \
./USER/gw1ns4c_it.d \
./USER/main.d \
./USER/retarget.d \
./USER/spi_nor_flash.d 


# Each subdirectory must supply rules for building sources it contributes
USER/%.o: ../USER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_spi_nor_flash\CORE" -I"C:\GMD\workspace\cm3_spi_nor_flash\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_spi_nor_flash\SYSTEM" -I"C:\GMD\workspace\cm3_spi_nor_flash\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


