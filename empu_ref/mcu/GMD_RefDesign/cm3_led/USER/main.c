
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
#include <stdio.h>

/* Declarations ------------------------------------------------------------------*/
void delay_ms(__IO uint32_t delay_ms);
void GPIOInit(void);
void UartInit(void);
void do_blink(int ms);

// copied from cm3_uart/retarget.c
#include <sys/stat.h>

__attribute__ ((used))  int _write (int fd, char *ptr, int len)
{
  int i;

  for (i=0; i<len; i++)
  {
    UART_SendChar(UART0, ptr[i]); // call character output function
  }
  return len;
}

/* Functions ------------------------------------------------------------------*/
int main(void)
{

	SystemInit();	//Initializes system
	GPIOInit();		//Initializes GPIO
	UartInit();
	
	for(int i=8; i>=0; i--)
		do_blink(125);
	printf("\r\nUart Initial finished -----------"); // it could hangs there
	fflush(stdout);
	while(1)
		do_blink(250);
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

	GPIO_Init(GPIO0,&GPIO_InitType);

    GPIO_SetBit(GPIO0,GPIO_Pin_0);
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

//delay ms
void delay_ms(__IO uint32_t delay_ms)
{
	for(delay_ms=(SystemCoreClock>>13)*delay_ms; delay_ms != 0; delay_ms--);
}
