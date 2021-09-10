################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PERIPHER/Sources/gw1ns4c_gpio.c \
../PERIPHER/Sources/gw1ns4c_i2c.c \
../PERIPHER/Sources/gw1ns4c_misc.c \
../PERIPHER/Sources/gw1ns4c_rtc.c \
../PERIPHER/Sources/gw1ns4c_spi.c \
../PERIPHER/Sources/gw1ns4c_syscon.c \
../PERIPHER/Sources/gw1ns4c_timer.c \
../PERIPHER/Sources/gw1ns4c_uart.c \
../PERIPHER/Sources/gw1ns4c_wdog.c 

OBJS += \
./PERIPHER/Sources/gw1ns4c_gpio.o \
./PERIPHER/Sources/gw1ns4c_i2c.o \
./PERIPHER/Sources/gw1ns4c_misc.o \
./PERIPHER/Sources/gw1ns4c_rtc.o \
./PERIPHER/Sources/gw1ns4c_spi.o \
./PERIPHER/Sources/gw1ns4c_syscon.o \
./PERIPHER/Sources/gw1ns4c_timer.o \
./PERIPHER/Sources/gw1ns4c_uart.o \
./PERIPHER/Sources/gw1ns4c_wdog.o 

C_DEPS += \
./PERIPHER/Sources/gw1ns4c_gpio.d \
./PERIPHER/Sources/gw1ns4c_i2c.d \
./PERIPHER/Sources/gw1ns4c_misc.d \
./PERIPHER/Sources/gw1ns4c_rtc.d \
./PERIPHER/Sources/gw1ns4c_spi.d \
./PERIPHER/Sources/gw1ns4c_syscon.d \
./PERIPHER/Sources/gw1ns4c_timer.d \
./PERIPHER/Sources/gw1ns4c_uart.d \
./PERIPHER/Sources/gw1ns4c_wdog.d 


# Each subdirectory must supply rules for building sources it contributes
PERIPHER/Sources/%.o: ../PERIPHER/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ahb2_exi\CORE" -I"C:\GMD\workspace\cm3_ahb2_exi\PERIPHER\Includes" -I"C:\GMD\workspace\cm3_ahb2_exi\SYSTEM" -I"C:\GMD\workspace\cm3_ahb2_exi\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


