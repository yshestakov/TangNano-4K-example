/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      main.c
 * @author    Embedded Development Team
 * @version   V1.x.x
 * @date      2021-01-01 09:00:00
 * @brief     Main function.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"
#include <stdio.h>

/* Macros ------------------------------------------------------------------*/
#define N_PRINT 1000

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);

/* Functions ------------------------------------------------------------------*/
int main()
{ 
  SystemInit();	//Initializes system
  UartInit();		//Initializes UART0
	
	printf("/**************************************/\r\n");
	printf("         Gowin_EMPU(GW1NS-4C)           \r\n");
	printf("/**************************************/\r\n");
	
	for(int i = 0;i < N_PRINT;i++)
	{
		printf("Hi GowinSemiconductor!\r\n");
	}

  while(1);
}

//Initializes UART0
void UartInit(void)
{
  UART_InitTypeDef UART_InitStruct;
	
  UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
  UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
  UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;
  UART_InitStruct.UART_Int.UARTInt_Rx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
  UART_InitStruct.UART_Hstm = DISABLE;
  UART_InitStruct.UART_BaudRate = 115200;//Baud Rate
	
  UART_Init(UART0,&UART_InitStruct);
}
