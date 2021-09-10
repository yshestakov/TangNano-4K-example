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
#include <stdbool.h>
/* Declarations ------------------------------------------------------------------*/
void GPIOInit(void);
void UartInit(void);
void RTCInit(void);
void delay_ms(__IO uint32_t delay_ms);

/* Functions ------------------------------------------------------------------*/
int main()
{
	uint32_t rtc_current_val = 0;
	NVIC_InitTypeDef InitTypeDef_NVIC;
	
    SystemInit();	//Initialzes system
	GPIOInit();		//Initializes GPIO
	UartInit();		//Initializes UART
	RTCInit();		//Initializes RTC
	
	//Enable RTC interrupt
	InitTypeDef_NVIC.NVIC_IRQChannel = RTC_IRQn;
    InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
    InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
    InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&InitTypeDef_NVIC);
	
	//RTC interrupt handler
	
  while(1)
	{
	    char buf[32];
		rtc_current_val = Get_Current_Value();
	    UART_SendString(UART0, " RTC Value : 0x");
		sprintf(buf, "%X\r\n", rtc_current_val);
	    UART_SendString(UART0, buf);
		delay_ms(258);
//		if (UART_GetTxBufferOverrunStatus(UART0))
//			UART_ClearTxBufferOverrunStatus(UART0);
	}
}

/**
  * @brief  This function handles RTC interrupt request.
  * @param  none
  * @retval none
  */
static bool led_flag = true;
void RTC_Handler(void)
{
	UART_SendString(UART0, "Enter RTC Interrupt.\r\n");

	if(led_flag)
	{
		GPIO_ResetBit(GPIO0, GPIO_Pin_0);
	}
	else
	{
		GPIO_SetBit(GPIO0, GPIO_Pin_0);
	}
	led_flag = !led_flag;

	//Clear Inetrrupt
	Clear_RTC_interrupt();

	Set_Load_Value(0);

	UART_SendString(UART0, "Exit RTC Interrupt.\r\n");
}

//delay ms
void delay_ms(__IO uint32_t delay_ms)
{
  for(delay_ms=delay_ms*8500; delay_ms != 0; delay_ms--);
}

//Initializes RTC
void RTCInit(void)
{
	Set_Match_Value(10);	//Match 10
	Set_Load_Value(0);		//0 Start
	RTC_Inter_Mask_Set();

	Start_RTC();
}

//Initializes GPIO
void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_SetBit(GPIO0,GPIO_Pin_0);//light : low level
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

//RTC Interrupt handler --> gw1ns4c_it.c
