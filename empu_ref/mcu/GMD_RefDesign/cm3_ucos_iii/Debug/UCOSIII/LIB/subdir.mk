################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UCOSIII/LIB/lib_ascii.c \
../UCOSIII/LIB/lib_math.c \
../UCOSIII/LIB/lib_mem.c \
../UCOSIII/LIB/lib_str.c 

OBJS += \
./UCOSIII/LIB/lib_ascii.o \
./UCOSIII/LIB/lib_math.o \
./UCOSIII/LIB/lib_mem.o \
./UCOSIII/LIB/lib_str.o 

C_DEPS += \
./UCOSIII/LIB/lib_ascii.d \
./UCOSIII/LIB/lib_math.d \
./UCOSIII/LIB/lib_mem.d \
./UCOSIII/LIB/lib_str.d 


# Each subdirectory must supply rules for building sources it contributes
UCOSIII/LIB/%.o: ../UCOSIII/LIB/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ucos_iii\CORE" -I"C:\GMD\workspace\cm3_ucos_iii\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_ucos_iii\SYSTEM" -I"C:\GMD\workspace\cm3_ucos_iii\USER" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\BSP" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB\Ports\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Source" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Ports\ARM-Cortex-M3\Generic\GNU" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


