/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			uart_app.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/

/* Include-------------------------------------------------------------------------------- */
#include "gw1ns4c.h"
#include "uart_app.h"

/* Functions-------------------------------------------------------------------------------- */
void _putchar(char character)
{
	UART_SendChar(UART_CONSOLE, character);
}

//Initializes UART0
void uart_app_init(uint32_t baudrate)
{
	UART_InitTypeDef UART_InitStruct;

	UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
	UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
	UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;
	UART_InitStruct.UART_Int.UARTInt_Rx = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
	UART_InitStruct.UART_Hstm = DISABLE;
	UART_InitStruct.UART_BaudRate = baudrate;

	UART_Init(UART_CONSOLE, &UART_InitStruct);
}
