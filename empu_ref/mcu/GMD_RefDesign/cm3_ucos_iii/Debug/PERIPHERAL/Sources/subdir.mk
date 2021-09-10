################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PERIPHERAL/Sources/gw1ns4c_gpio.c \
../PERIPHERAL/Sources/gw1ns4c_i2c.c \
../PERIPHERAL/Sources/gw1ns4c_misc.c \
../PERIPHERAL/Sources/gw1ns4c_rtc.c \
../PERIPHERAL/Sources/gw1ns4c_spi.c \
../PERIPHERAL/Sources/gw1ns4c_syscon.c \
../PERIPHERAL/Sources/gw1ns4c_timer.c \
../PERIPHERAL/Sources/gw1ns4c_uart.c \
../PERIPHERAL/Sources/gw1ns4c_wdog.c 

OBJS += \
./PERIPHERAL/Sources/gw1ns4c_gpio.o \
./PERIPHERAL/Sources/gw1ns4c_i2c.o \
./PERIPHERAL/Sources/gw1ns4c_misc.o \
./PERIPHERAL/Sources/gw1ns4c_rtc.o \
./PERIPHERAL/Sources/gw1ns4c_spi.o \
./PERIPHERAL/Sources/gw1ns4c_syscon.o \
./PERIPHERAL/Sources/gw1ns4c_timer.o \
./PERIPHERAL/Sources/gw1ns4c_uart.o \
./PERIPHERAL/Sources/gw1ns4c_wdog.o 

C_DEPS += \
./PERIPHERAL/Sources/gw1ns4c_gpio.d \
./PERIPHERAL/Sources/gw1ns4c_i2c.d \
./PERIPHERAL/Sources/gw1ns4c_misc.d \
./PERIPHERAL/Sources/gw1ns4c_rtc.d \
./PERIPHERAL/Sources/gw1ns4c_spi.d \
./PERIPHERAL/Sources/gw1ns4c_syscon.d \
./PERIPHERAL/Sources/gw1ns4c_timer.d \
./PERIPHERAL/Sources/gw1ns4c_uart.d \
./PERIPHERAL/Sources/gw1ns4c_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
PERIPHERAL/Sources/%.o: ../PERIPHERAL/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ucos_iii\CORE" -I"C:\GMD\workspace\cm3_ucos_iii\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_ucos_iii\SYSTEM" -I"C:\GMD\workspace\cm3_ucos_iii\USER" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\BSP" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB\Ports\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Source" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Ports\ARM-Cortex-M3\Generic\GNU" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


