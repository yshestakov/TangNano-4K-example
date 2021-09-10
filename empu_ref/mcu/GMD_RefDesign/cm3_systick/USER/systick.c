/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			systick.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			Systick
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "systick.h"

/* Variable ------------------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/* Functions ------------------------------------------------------------------*/
//systick initialization
//start systick
void SystickInit(void)
{
	//SystemCoreClock / 1000 : 1ms interrupt
	uint32_t temp = SystemCoreClock / 10000;
	SysTick->LOAD = temp;
	SysTick->VAL = temp;//Reset current counter's value
	
	//select clock source, enable interrupt, enable counter
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | 
									SysTick_CTRL_TICKINT_Msk | 
									SysTick_CTRL_ENABLE_Msk; 
}

//delay 10us
void delay_us(__IO uint32_t nTime)
{
	TimingDelay = nTime;
	
	//enable systick
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
	
	while(TimingDelay != 0);
}

//get systick
//add into SysTick_Handler
void TimingDelay_Decrement(void)
{
	if(TimingDelay != 0x00)
	{
		TimingDelay--;
	}
}
