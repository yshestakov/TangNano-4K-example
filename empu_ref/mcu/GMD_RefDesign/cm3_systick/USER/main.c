
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
#include "systick.h"

/* Declarations ------------------------------------------------------------------*/
void GPIOInit(void);

/* Functions ------------------------------------------------------------------*/
int main(void)
{
	SystemInit();		//Initializes system
	SystickInit();	//Initializes Systick
	GPIOInit();			//Initializes GPIO
	
  while(1)
  {
		GPIO_ResetBit(GPIO0,GPIO_Pin_0);
    delay_ms(100); 
    GPIO_SetBit(GPIO0,GPIO_Pin_0);
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
