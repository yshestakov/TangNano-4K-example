/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			led.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application.
 ******************************************************************************************/

/* Include-------------------------------------------------------------------------------- */
#include "gw1ns4c.h"
#include "led.h"

/* Functions-------------------------------------------------------------------------------- */
//Initializes GPIO
void led_init(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_SetBit(GPIO0,GPIO_Pin_0);
}

//led on
void led_on(uint8_t led)
{
  switch (led)
  {
      case 0:
       	GPIO_ResetBit(GPIO0, GPIO_Pin_0);
       	break;
      case 1:
       	GPIO_ResetBit(GPIO0, GPIO_Pin_1);
       	break;
      case 2:
       	GPIO_ResetBit(GPIO0, GPIO_Pin_2);
       	break;
      case 3:
       	GPIO_ResetBit(GPIO0, GPIO_Pin_3);
       	break;
      default:
       	break;
    }
}

//led off
void led_off(uint8_t led)
{
	switch (led)
  {
      case 0:
       	GPIO_SetBit(GPIO0, GPIO_Pin_0);
       	break;
      case 1:
       	GPIO_SetBit(GPIO0, GPIO_Pin_1);
       	break;
      case 2:
       	GPIO_SetBit(GPIO0, GPIO_Pin_2);
       	break;
      case 3:
       	GPIO_SetBit(GPIO0, GPIO_Pin_3);
       	break;
      default:
       	break;
    }
}

//led toggle
void led_toggle(uint8_t led)
{
	uint32_t temp;

	temp = GPIO0->DATAOUT;

	switch (led)
  {
      case 0:
      	if (temp & GPIO_Pin_0)
       	{
       		GPIO_ResetBit(GPIO0, GPIO_Pin_0);
       	}
       	else
       	{
       		GPIO_SetBit(GPIO0, GPIO_Pin_0);
       	}
				break;
      case 1:
       	if (temp & GPIO_Pin_1)
       	{
       		GPIO_ResetBit(GPIO0, GPIO_Pin_1);
       	}
      	else
       	{
       		GPIO_SetBit(GPIO0, GPIO_Pin_1);
       	}
				break;
      case 2:
       	if (temp & GPIO_Pin_2)
       	{
       		GPIO_ResetBit(GPIO0, GPIO_Pin_2);
       	}
       	else
       	{
       		GPIO_SetBit(GPIO0, GPIO_Pin_2);
       	}
				break;
      case 3:
       	if (temp & GPIO_Pin_3)
       	{
       		GPIO_ResetBit(GPIO0, GPIO_Pin_3);
       	}
       	else
       	{
       		GPIO_SetBit(GPIO0, GPIO_Pin_3);
       	}
				break;
      default:
       	break;
    }
}
