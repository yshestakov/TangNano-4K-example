
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

/* Includes ------------------------------------------------------------------*/
void SPIInit(void);

/* Functions ------------------------------------------------------------------*/
int main(void)
{
  SystemInit();		//Initializes system
	SPIInit();			//Initializes SPI
	
  SPI_Select_Slave(0x01) ;	//Select The SPI Slave	
  SPI_WriteData(0x9F);			//Send Jedec
	
  while(1)
  {
		if(~SPI_GetToeStatus() && SPI_GetTrdyStatus() == 1)
		{
			  SPI_WriteData(0x9F);//Send Jedec
		}
		
		if(~SPI_GetRoeStatus() && SPI_GetRrdyStatus() == 1)
		{
			  UART_SendChar(UART0,SPI_ReadData());
		}
  }  
}

//Initializes SPI
void SPIInit(void)
{
	SPI_InitTypeDef init_spi;
	
  init_spi.CLKSEL= CLKSEL_CLK_DIV_8;		//80MHZ / 8
  init_spi.DIRECTION = DISABLE;					//MSB First
  init_spi.PHASE =DISABLE;							//ENABLE;//posedge
  init_spi.POLARITY =DISABLE;						//polarity 0
	
  SPI_Init(&init_spi);
}
