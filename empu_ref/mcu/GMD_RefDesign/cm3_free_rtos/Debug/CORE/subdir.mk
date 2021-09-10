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
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_free_rtos\CORE" -I"C:\GMD\workspace\cm3_free_rtos\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_free_rtos\SYSTEM" -I"C:\GMD\workspace\cm3_free_rtos\USER" -I"C:\GMD\workspace\cm3_free_rtos\FreeRTOS\include" -I"C:\GMD\workspace\cm3_free_rtos\FreeRTOS\portable\GNU\ARM_CM3" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


