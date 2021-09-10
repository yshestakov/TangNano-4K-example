----------------------------------------------------------------------------------------------------
				Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.   
									All rights reserved.
----------------------------------------------------------------------------------------------------
							Gowin_EMPU(GW1NS-4C) GMD Reference Design
----------------------------------------------------------------------------------------------------
MCU IDE
	GMD V1.1
----------------------------------------------------------------------------------------------------
FLASH	Start	Size
		0x0		0x8000		--> FLASH instruction memory(32KB).
----------------------------------------------------------------------------------------------------		
SRAM	Start		Size
		0x20000000	0x4000	--> SRAM data memory(Default is 16KB).
----------------------------------------------------------------------------------------------------
Example
	cm3_apb2_exi				--> APB2 extension interface extends a multiple.
	cm3_ahb2_exi				--> AHB2 extension interface extends a multiple.
	cm3_free_rtos				--> OS FreeRTOS.
	cm3_i2c						--> I2C master bus Tx and Rx with slave.
	cm3_int_priority			--> Timer0, UART0 interrupt priority.
	cm3_keyscan					--> Key controls led with GPIO.
	cm3_led						--> GPIO0~3 output.
	cm3_mm						--> Dynamic memory allocate and free.
	cm3_retarget				--> Retarget UART0 printf and scanf.
	cm3_rtc						--> RTC.
	cm3_spi						--> SPI master bus Tx and Rx with slave.
	cm3_systick					--> Delay by systick timer.
	cm3_timer					--> Timer0.
	cm3_uart					--> UART0 Tx.
	cm3_uart0_int				--> UART0 interrupt.
	cm3_ucos_iii				--> OS UC/OS-III.
	cm3_wdog					--> Watch dog reset.
	cm3_psram					--> Embedded PSRAM Memory Interface.
	cm3_hyper_ram				--> Embedded HyperRAM Memory Interface.
	cm3_spi_nor_flash			--> Embedded SPI_Nor_Flash.
----------------------------------------------------------------------------------------------------