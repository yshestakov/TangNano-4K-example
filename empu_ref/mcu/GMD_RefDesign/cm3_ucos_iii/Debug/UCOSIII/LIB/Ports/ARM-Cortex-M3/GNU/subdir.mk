################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../UCOSIII/LIB/Ports/ARM-Cortex-M3/GNU/lib_mem_a.S 

OBJS += \
./UCOSIII/LIB/Ports/ARM-Cortex-M3/GNU/lib_mem_a.o 

S_UPPER_DEPS += \
./UCOSIII/LIB/Ports/ARM-Cortex-M3/GNU/lib_mem_a.d 


# Each subdirectory must supply rules for building sources it contributes
UCOSIII/LIB/Ports/ARM-Cortex-M3/GNU/%.o: ../UCOSIII/LIB/Ports/ARM-Cortex-M3/GNU/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -D__STARTUP_CLEAR_BSS -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


