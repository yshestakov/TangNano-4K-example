################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UCOSIII/BSP/bsp.c 

OBJS += \
./UCOSIII/BSP/bsp.o 

C_DEPS += \
./UCOSIII/BSP/bsp.d 


# Each subdirectory must supply rules for building sources it contributes
UCOSIII/BSP/%.o: ../UCOSIII/BSP/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ucos_iii\CORE" -I"C:\GMD\workspace\cm3_ucos_iii\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_ucos_iii\SYSTEM" -I"C:\GMD\workspace\cm3_ucos_iii\USER" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\BSP" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB\Ports\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Source" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Ports\ARM-Cortex-M3\Generic\GNU" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


