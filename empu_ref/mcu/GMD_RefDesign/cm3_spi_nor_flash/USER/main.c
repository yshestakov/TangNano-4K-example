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
#include "spi_nor_flash.h"

/* Declarations ------------------------------------------------------------------*/
void UartInit(void);
void GPIOInit(void);
void delay_ms(__IO uint32_t delay_ms);

/* Variables ------------------------------------------------------------------*/
uint8_t tx_buffer[200] = {0};
uint8_t rx_buffer[200] = {0};

/* Functions ------------------------------------------------------------------*/
int main()
{
	int flag = 0;
	
	SystemInit();					//Initializes system
	UartInit();						//Initializes UART0
	GPIOInit();						//Initializes GPIO
	spi_nor_flash_init();	//Initializes SPI_Nor_Flash
	
	delay_ms(10);					//Wait SPI_Nor_Flash initialization
	
	printf("/******************GOWINSEMI***************************/\r\n");
	printf("         Gowin_EMPU(GW1NS-4C) SPI_Nor_Flash             \r\n");
	printf("/******************************************************/\r\n");

	//Read initialized data from SPI_Nor_Flash
	printf("Read initialized data from SPI_Nor_Flash\r\n");
	spi_nor_flash_read(200,0x03,0x600000,rx_buffer);
	printf("SPI_Nor_Flash initialized data :\r\n");
	for(int i = 0;i < 200;i++)
	{
		printf("%x ",rx_buffer[i]);
	}
	printf("\r\n");
		
	//Erase SPI_Nor_Flash sector
	printf("Erase SPI_Nor_Flash\r\n");
	spi_nor_flash_sector_erase(0x600000);
	printf("After erase SPI_Nor_Flash, read data :\r\n");
		
	//second read the data from SPI_Nor_Flash
	spi_nor_flash_read(200,0x03,0x600000,rx_buffer);
	for(int i = 0;i < 200;i++)
	{
		printf("%x ",rx_buffer[i]);
	}
	printf("\r\n");
		
	//Write data to SPI_Nor_Flash
	for(int i = 0;i < 200;i++)
	{
		tx_buffer[i] = i;
	}
	
	spi_nor_flash_sector_erase(0x600000);
	printf("Erase SPI_Nor_Flash, and then write SPI_Nor_Flash\r\n");
	spi_nor_flash_page_program(200,0x600000,tx_buffer);
	
	//Read the data writed
	printf("Read data after page write from SPI_Nor_Flash :\r\n");
	spi_nor_flash_read(200,0x03,0x600000,rx_buffer);
	for(int i = 0;i < 200;i++)
	{
		printf("%d ",rx_buffer[i]);
	}
	printf("\r\n");
	
	//Erase data
	spi_nor_flash_sector_erase(0x600000);
	printf("Erase SPI_Nor_Flash sector data\r\n");
	
	//Check write and read data
	for(int i = 0;i < 200;i++)
	{
		if(rx_buffer[i] != tx_buffer[i])
		{
			flag = 1;
			break;
		}
	}
	
	if(flag)
	{
		GPIO_SetBit(GPIO0,GPIO_Pin_0);//LED1 off
		printf("SPI_Nor_Flash testing failed!\r\n");
	}
	else
	{
		GPIO_ResetBit(GPIO0,GPIO_Pin_0);//LED1 on
		printf("SPI_Nor_Flash testing successfully!\r\n");
	}

	delay_ms(2000);
	
	while(1)
	{
		GPIO_SetBit(GPIO0,GPIO_Pin_0);
		delay_ms(100);
		GPIO_ResetBit(GPIO0,GPIO_Pin_0);
		delay_ms(100);
	}
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
