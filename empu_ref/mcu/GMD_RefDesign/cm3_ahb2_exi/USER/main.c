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
#include "uart.h"
#include "multiple.h"
#include <stdio.h>

/* Functions ------------------------------------------------------------------*/
int main()
{
  SystemInit();		//Initializes system
  UartInit();			//Initializes UART0
	
	printf("/************GOWINSEMI*****************/\r\n");
	printf("          GOWIN_EMPU(GW1NS-4C)           \r\n");
	printf("/**************************************/\r\n");
	
	printf("System initialization finished.\r\n");
	printf("Uart initialization finished.\r\n");
	printf("Multiple initialization finished.\r\n");
	printf("Initialization Status : \r\n");
	printf("--MULTIPLIER = %d\r\n",getMultiplier());
	printf("--MULTIPLICAND = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());

	printf("Start first multiple\r\n");
	setMultiplier(20);
	setMultiplicand(40);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple first finished.\r\n");
	
	printf("Start second multiple\r\n");
	setMultiplier(30);
	setMultiplicand(50);
	startMultiple();
	printf("Compute Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	
	while(getFinishStatus()==FINISHED_STATUS);
	finishMultiple();
	
	printf("Finished Status : \r\n");
	printf("--Multiplier = %d\r\n",getMultiplier());
	printf("--Multiplicand = %d\r\n",getMultiplicand());
	printf("--CMD = %d\r\n",getMultipleCmd());
	printf("--RESULT = %d\r\n",getMultipleResult());
	printf("Multiple second finished.\r\n");

  while(1);
}
