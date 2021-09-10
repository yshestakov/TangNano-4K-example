################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../UCOSIII/OS/Source/os_cfg_app.c \
../UCOSIII/OS/Source/os_core.c \
../UCOSIII/OS/Source/os_dbg.c \
../UCOSIII/OS/Source/os_flag.c \
../UCOSIII/OS/Source/os_int.c \
../UCOSIII/OS/Source/os_mem.c \
../UCOSIII/OS/Source/os_msg.c \
../UCOSIII/OS/Source/os_mutex.c \
../UCOSIII/OS/Source/os_pend_multi.c \
../UCOSIII/OS/Source/os_prio.c \
../UCOSIII/OS/Source/os_q.c \
../UCOSIII/OS/Source/os_sem.c \
../UCOSIII/OS/Source/os_stat.c \
../UCOSIII/OS/Source/os_task.c \
../UCOSIII/OS/Source/os_tick.c \
../UCOSIII/OS/Source/os_time.c \
../UCOSIII/OS/Source/os_tmr.c \
../UCOSIII/OS/Source/os_var.c 

OBJS += \
./UCOSIII/OS/Source/os_cfg_app.o \
./UCOSIII/OS/Source/os_core.o \
./UCOSIII/OS/Source/os_dbg.o \
./UCOSIII/OS/Source/os_flag.o \
./UCOSIII/OS/Source/os_int.o \
./UCOSIII/OS/Source/os_mem.o \
./UCOSIII/OS/Source/os_msg.o \
./UCOSIII/OS/Source/os_mutex.o \
./UCOSIII/OS/Source/os_pend_multi.o \
./UCOSIII/OS/Source/os_prio.o \
./UCOSIII/OS/Source/os_q.o \
./UCOSIII/OS/Source/os_sem.o \
./UCOSIII/OS/Source/os_stat.o \
./UCOSIII/OS/Source/os_task.o \
./UCOSIII/OS/Source/os_tick.o \
./UCOSIII/OS/Source/os_time.o \
./UCOSIII/OS/Source/os_tmr.o \
./UCOSIII/OS/Source/os_var.o 

C_DEPS += \
./UCOSIII/OS/Source/os_cfg_app.d \
./UCOSIII/OS/Source/os_core.d \
./UCOSIII/OS/Source/os_dbg.d \
./UCOSIII/OS/Source/os_flag.d \
./UCOSIII/OS/Source/os_int.d \
./UCOSIII/OS/Source/os_mem.d \
./UCOSIII/OS/Source/os_msg.d \
./UCOSIII/OS/Source/os_mutex.d \
./UCOSIII/OS/Source/os_pend_multi.d \
./UCOSIII/OS/Source/os_prio.d \
./UCOSIII/OS/Source/os_q.d \
./UCOSIII/OS/Source/os_sem.d \
./UCOSIII/OS/Source/os_stat.d \
./UCOSIII/OS/Source/os_task.d \
./UCOSIII/OS/Source/os_tick.d \
./UCOSIII/OS/Source/os_time.d \
./UCOSIII/OS/Source/os_tmr.d \
./UCOSIII/OS/Source/os_var.d 


# Each subdirectory must supply rules for building sources it contributes
UCOSIII/OS/Source/%.o: ../UCOSIII/OS/Source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:\GMD\workspace\cm3_ucos_iii\CORE" -I"C:\GMD\workspace\cm3_ucos_iii\PERIPHERAL\Includes" -I"C:\GMD\workspace\cm3_ucos_iii\SYSTEM" -I"C:\GMD\workspace\cm3_ucos_iii\USER" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\BSP" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CONFIG" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\CPU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB\Ports\ARM-Cortex-M3\GNU" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\LIB" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Source" -I"C:\GMD\workspace\cm3_ucos_iii\UCOSIII\OS\Ports\ARM-Cortex-M3\Generic\GNU" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


