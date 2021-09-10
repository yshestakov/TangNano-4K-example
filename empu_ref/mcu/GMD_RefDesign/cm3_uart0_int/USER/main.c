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

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);
void GPIOInit(void);
void delay_ms(__IO uint32_t delay_ms);
void do_blink(int ms);

/* Functions ------------------------------------------------------------------*/
int main()
{
	NVIC_InitTypeDef InitTypeDef_NVIC;

    SystemInit();	//Initializes system

    UartInit();		//Initializes UART0
	GPIOInit();		//Initializes GPIO

	for(int i=4; i>=0; i--)
		do_blink(125);
	printf("\r\n(cm3_uart0_in) UART Initial finished. Enable UART0 int handler");
	fflush(stdout);
	//Enable UART0 interrupt handler
	InitTypeDef_NVIC.NVIC_IRQChannel = UART0_IRQn;
    InitTypeDef_NVIC.NVIC_IRQChannelPreemptionPriority = 1;
    InitTypeDef_NVIC.NVIC_IRQChannelSubPriority = 1;
    InitTypeDef_NVIC.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&InitTypeDef_NVIC);
	for(int i=2; i>=0; i--) {
		UART_SendChar(UART0, '@');
		do_blink(250);
	}
	UART_SendChar(UART0, '>');
#if 0
	printf("/** GOWINSEMI **/\r\n");
	fflush(stdout);
	for(int i=2; i>=0; i--) do_blink(250);
	printf("   GOWIN_EMPU_M3 \r\n");
	fflush(stdout);
	for(int i=2; i>=0; i--) do_blink(250);
	printf("/****************/\r\n");
	fflush(stdout);
#endif
    while(1) {
	  do_blink(1000);
    }
}

void do_blink(int ms)
{
	GPIO_ResetBit(GPIO0, GPIO_Pin_0);	//LED1 on
	delay_ms(ms);

	GPIO_SetBit(GPIO0, GPIO_Pin_0);		//LED1 off
	delay_ms(ms);
}

//Initializes GPIO
void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;
	GPIO_Init(GPIO0, &GPIO_InitType);
    GPIO_SetBit(GPIO0, GPIO_Pin_0);
}

//Initialized UART0
void UartInit(void)
{
  UART_InitTypeDef UART_InitStruct;
	
  UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
  UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
  UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;
  UART_InitStruct.UART_Int.UARTInt_Rx = ENABLE;//Enable UART0 RX interrupt register
  UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
  UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
  UART_InitStruct.UART_Hstm = DISABLE;
  UART_InitStruct.UART_BaudRate = 115200;//Baud Rate
	
  UART_Init(UART0,&UART_InitStruct);
}

/**
  * @brief  This function handles UART0 interrupt request.
  * @param  none
  * @retval none
  */
void UART0_Handler(void)
{
	char num = '0';
	
	if(UART_GetRxIRQStatus(UART0) == SET)
	{
		num  = UART_ReceiveChar(UART0);
		UART_SendString(UART0, "UART0 got ");
		UART_SendChar(UART0, num);
		UART_SendString(UART0, "\r\n");
		
		switch (num)
		{
		case '4':
			do_blink(125);
		case '3':
			do_blink(125);
		case '2':
			do_blink(125);
		case '1':
			do_blink(125);
			break;
		default:
			UART_SendString(UART0, "No operation!\r\n");
			break;
		}
	}
	UART_ClearRxIRQ(UART0);
}

//delay ms
void delay_ms(__IO uint32_t delay_ms)
{
	for(delay_ms=(SystemCoreClock>>13)*delay_ms; delay_ms != 0; delay_ms--);
}
