/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			main.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			Main function.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"
#include <stdio.h>

/* Declaraction --------------------------------------------------------------*/
void UartInit(void);

int main()
{   
	unsigned char Temp1[100];
	unsigned char receive1[100];
	uint32_t i;
	
	SystemInit();		//Initializes system
	UartInit();			//Initializes UART0
	I2C_Init(I2C,400);	//Initializes I2C
	
	for(i=0;i<100;i++)
	{
		Temp1[i] =i;
	}
	
	printf("\r\nI2C sends data :\r\n");
	for(i=0;i<30;i++)
	{
		printf("%d ",Temp1[i]);
	}
	printf("\r\n");
	
	//I2C send bytes
	I2C_SendBytes(I2C ,0x50,0x00,Temp1, 30);
	
	//I2C receive bytes
	I2C_ReadBytes(I2C,0x50,0x00,receive1,30);
	
	printf("\r\nI2C receives data :\r\n");
	for(i=0;i<30;i++)
	{
		printf("%d ",receive1[i]);
	}
	printf("\r\n");

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
