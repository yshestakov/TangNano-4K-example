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

/* Macros ------------------------------------------------------------------*/
#define true 1
#define false 0

typedef uint8_t bool;

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);
void TimerInit(TIMER_TypeDef* TIMERx);

/* Variables ------------------------------------------------------------------*/
volatile uint32_t counter;
bool timer_flag = false;
bool counter_flag = false;

//Interrupt Priority
int main()
{
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
  SystemInit();				//Initializes system
  UartInit();					//Initializes UART0
  TimerInit(TIMER0);	//Initializes Timer0
	
	//Config interrupt and interrupt priority
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
	//Timer0 interrupt
  InitTypeDef_NVIC.NVIC_IRQChannel = TIMER0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);
	//UART0 interrupt
  InitTypeDef_NVIC.NVIC_IRQChannel = UART0_IRQn;
  InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 0;
  InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
  InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&InitTypeDef_NVIC);

	//Enable Timer0 interrupt
  TIMER_EnableIRQ(TIMER0);
	
	//Start Timer0
	TIMER_StartTimer(TIMER0);
	
	timer_flag = true;

  int num=0;

	while(1)
   {
     if(counter==2)
     {
       counter=0;
			 printf("%d\r\n",num);
       num++;
     }
		
     if(num==60)
	   {	
			 num=0;
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
  UART_InitStruct.UART_Int.UARTInt_Rx = ENABLE; //Enable UART0 RX interrupt
  UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
  UART_InitStruct.UART_Hstm = DISABLE;
  UART_InitStruct.UART_BaudRate = 115200;//Baud Rate
	
  UART_Init(UART0,&UART_InitStruct);
}

//UART0 interrupt handler
void UART0_Handler(void)
{
	if(UART_GetRxIRQStatus(UART0) == SET)
	{
		printf("UART0 Rx interrupt receives a value %c.\r\n",UART_ReceiveChar(UART0));
		printf("UART0 is Rx in interrupt status.\r\n");
		
		if(timer_flag == true)
		{
			counter_flag = true;
		}
		
		UART_ClearRxIRQ(UART0);
		
		if(timer_flag == false)
		{
			TIMER_StartTimer(TIMER0);
			timer_flag = true;
		}
	}
}

//Initializes Timer0
void TimerInit(TIMER_TypeDef* TIMERx)
{ 
  TIMER0->INTCLEAR = 0;
  TIMER0->RELOAD=25000026;//Set the value of the Timmer 1s
  TIMER0->VALUE= TIMER0->RELOAD; //Set the init value
  TIMER0->CTRL=0;  // timmer interrupt
	
	UART_SendString(UART0,"TIMER0 registers begin initialized status.\r\n");
	UART_SendString(UART0,"TIMER0 registers finish initialized status.\r\n");
}

//Timer0 interrupt handler
void TIMER0_Handler(void)
{
  if(TIMER_GetIRQStatus(TIMER0) != RESET)
  {
    while(1)
    {
		  counter ++;
		  printf("Timer0 interrupt counter is %d.\r\n",counter);
			
			if(counter_flag == true)
			{
				break;
			}
    }
		
		TIMER_ClearIRQ(TIMER0);
		TIMER_StopTimer(TIMER0);
		counter = 0;
		timer_flag = false;
		
		counter_flag = false;
  }
}
