
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
#include "gw1ns4c.h"

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);
void watchdog_set(unsigned int cycle);
void watchdog_init(unsigned int cycle, int type);
																									/* Program watchdog: 		*/
																									/* type = 0 : No action */
																									/* type = 1 : Interrupt */
																									/* type = 2 : Reset 		*/

/* Functions ------------------------------------------------------------------*/
int main ()
{
	SystemInit();	//Initializes system
	UartInit();		//Initializes UART0

	//whether this is watchdog reset
	if ((SYSCON_GetRstinfoWdogresetreq()) !=0)
	{
		UART_SendString(UART0,"Wdog Reset!\r\n");

		SYSCON->RSTINFO = SYSCON_RSTINFO_WDOGRESETREQ;//clear flag
	}
	else
	{
		UART_SendString(UART0,"System Reset!\r\n");
	}

	watchdog_init(86666666,2);
	while(1)                        
	{
		//add monitor codes
		//if there
		if(UART_ReceiveChar(UART0)==2)
		{
			//feed dogs
			UART_SendString(UART0,"Wdog Feed!\r\n");
			watchdog_init(86666666,2);
		}   
	}
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

/* Update watchdog counter */
void watchdog_set(unsigned int cycle)
{
  WDOG_UnlockWriteAccess();
  WDOG->CTRL = 2;
  WDOG_RestartCounter(cycle);
	WDOG_SetResetEnable();
  WDOG_LockWriteAccess();
}

/* Watchdog initialization */
void watchdog_init(unsigned int cycle, int type)
{
  //puts   ("  Unlocking watchdog...");
  WDOG_UnlockWriteAccess();

  WDOG_RestartCounter(cycle);
  if (type==0)
  {
    //puts   ("  Set to no action");
    WDOG->CTRL = 0;
  }
  else if (type==1)
  {
    //puts   ("  Set to NMI generation");
    WDOG_SetIntEnable();
  }
  else
  {
    //puts   ("  Set to reset generation");
    WDOG_SetResetEnable();
    WDOG_SetIntEnable();
  }

  //puts   ("  Locking watchdog...");
  WDOG_LockWriteAccess();
}
