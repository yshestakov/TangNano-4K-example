/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			systick.h
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			Systick header file
 ******************************************************************************************
 */
 
#ifndef SYSTICK_H
#define SYSTICK_H

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/* Declarations ------------------------------------------------------------------*/
void SystickInit(void);
void delay_us(__IO uint32_t nTime);
void TimingDelay_Decrement(void);

//delay ms
#define delay_ms(x) delay_us(100*x);

#endif
