################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_c.c 

S_UPPER_SRCS += \
../UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_a.S 

OBJS += \
./UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_a.o \
./UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_c.o 

S_UPPER_DEPS += \
./UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_a.d 

C_DEPS += \
./UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/os_cpu_c.d 


# Each subdirectory must supply rules for building sources it contributes
UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/%.o: ../UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -D__STARTUP_CLEAR_BSS -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/%.o: ../UCOSIII/OS/Ports/ARM-Cortex-M3/Generic/GNU/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ucos_iii\CORE" -I"C:\GMD\workspace\cm3_ucos_iii\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_ucos_iii\SYSTEM" -I"C:\GMD\workspace\cm3_ucos_iii\USER" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\BSP" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB\Ports\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Source" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Ports\ARM-Cortex-M3\Generic\GNU" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


