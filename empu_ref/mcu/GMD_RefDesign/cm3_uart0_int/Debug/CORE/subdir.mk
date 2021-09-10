################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CORE/core_cm3.c 

OBJS += \
./CORE/core_cm3.o 

C_DEPS += \
./CORE/core_cm3.d 


# Each subdirectory must supply rules for building sources it contributes
CORE/%.o: ../CORE/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"D:\Downloads\sipeed-nano-4k\Gowin EDA\Gowin_EMPU(GW1NS-4C)_V1.1.2\ref_design\MCU_RefDesign\GMD_RefDesign\cm3_uart0_int\CORE" -I"D:\Downloads\sipeed-nano-4k\Gowin EDA\Gowin_EMPU(GW1NS-4C)_V1.1.2\ref_design\MCU_RefDesign\GMD_RefDesign\cm3_uart0_int\PERIPHERAL\Includes" -I"D:\Downloads\sipeed-nano-4k\Gowin EDA\Gowin_EMPU(GW1NS-4C)_V1.1.2\ref_design\MCU_RefDesign\GMD_RefDesign\cm3_uart0_int\SYSTEM" -I"D:\Downloads\sipeed-nano-4k\Gowin EDA\Gowin_EMPU(GW1NS-4C)_V1.1.2\ref_design\MCU_RefDesign\GMD_RefDesign\cm3_uart0_int\USER" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


