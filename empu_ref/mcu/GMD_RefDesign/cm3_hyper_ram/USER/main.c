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
#include <stdio.h>
#include "hyper_ram.h"

/* Includes ------------------------------------------------------------------*/
void UartInit(void);

/* Macros ------------------------------------------------------------------*/
#define TEST_NUM 0x2000

/* Variables ------------------------------------------------------------------*/
uint32_t rec_temp[4];
uint32_t temp[4] = { 0x00};

/* Functions ------------------------------------------------------------------*/
int main()
{
	SystemInit();	//Initializes system
	UartInit();		//Initializes UART0
	
	printf("\r\n---------------------------------------------------------------------\r\n");
	printf("       GowinSemiconductor Gowin_EMPU(GW1NS-4C) HyperRAM Application      \r\n");
	printf("---------------------------------------------------------------------\r\n\r\n");
	
	printf("System Initialized Successfully!\r\n");
	printf("UART0 Initialized Successfully!\r\n");
	
	//Check and wait HyperRAM initialization finished
	while(HPRAM_Check_Init_Status()!=1);
	
	printf("HyperRAM Initialized Successfully!\r\n");
	
	//Write data into HyperRAM
	printf("\r\nWrite Data Into HyprRAM : \r\n");
	for(uint32_t i = 0; i < TEST_NUM; i = i+8)
	{
		for(uint16_t j = 0; j < 4; j++)
		{
			temp[j] = i;
			
			printf("The Address 0x%x : Write Data %x.\r\n",i,temp[j]);
		}
		
		HPRAM_Write_Data_Buff(temp,i);
	}
	
	//Read Data From HyperRAM
	printf("\r\nRead Data From HyperRAM : \r\n");
	for(uint32_t i = 0; i < TEST_NUM; i = i+8)
	{
		HPRAM_Read_Data_Buff(rec_temp,i);
		
		for(uint16_t j = 0; j < 4; j++)
		{
			printf("The Address 0x%x : Read Data %x.\r\n",i,rec_temp[j]);
		}
	}
	
	printf("\r\nGowin_EMPU(GW1NS-4C) HyperRAM Application Finished!\r\n");

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
