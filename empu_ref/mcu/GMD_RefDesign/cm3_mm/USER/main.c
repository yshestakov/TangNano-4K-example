/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			main.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			Main program body.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "malloc.h"

/* Macros ------------------------------------------------------------------*/
#define N_PRINT 100

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);

/* Functions ------------------------------------------------------------------*/
int main()
{
	char* buff;
	
	SystemInit(); //Initializes system
	UartInit();   //Initializes UART0
	mem_init();   //Initialize mm
	
  UART_SendString(UART0,"\r\nmemory management\r\n");
	
	buff = (char*)mymalloc(100);
	buff = "Hello World, GOWINSEMICONDUCTOR welcome you!\r\n";

  for(int i=0;i<N_PRINT;i++)
	{
		UART_SendString(UART0,buff);
	}
	
	myfree(buff);
	
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
