/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        gw1ns4c_it.c
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       Main Interrupt Service Routines.
 *              This file provides template for all exceptions handler and
 *              peripherals interrupt service routine.
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c_it.h"
#include <stdio.h>
#include <stdbool.h>

/** @addtogroup GW1NS4C_StdPeriph_Template
  * @{
  */

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M3 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  none
  * @retval none
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  none
  * @retval none
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Memory Manage exception.
  * @param  none
  * @retval none
  */
void MemManage_Handler(void)
{
  /* Go to infinite loop when Memory Manage exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Bus Fault exception.
  * @param  none
  * @retval none
  */
void BusFault_Handler(void)
{
  /* Go to infinite loop when Bus Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles Usage Fault exception.
  * @param  none
  * @retval none
  */
void UsageFault_Handler(void)
{
  /* Go to infinite loop when Usage Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  none
  * @retval none
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles Debug Monitor exception.
  * @param  none
  * @retval none
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  none
  * @retval none
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  none
  * @retval none
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                  GW1NS4C Peripherals Interrupt Handlers                     */
/*  Add here the Interrupt Handler for the used peripheral(s) (XXX), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_gw1ns4c.s).                                                  */
/******************************************************************************/

/**
  * @brief  This function handles USER INT0 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT0_Handler(void)
{
}

/**
  * @brief  This function handles USER INT1 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT1_Handler(void)
{
}

/**
  * @brief  This function handles USER INT2 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT2_Handler(void)
{
}

/**
  * @brief  This function handles USER INT3 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT3_Handler(void)
{
}

/**
  * @brief  This function handles USER INT4 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT4_Handler(void)
{
}

/**
  * @brief  This function handles USER INT5 interrupt request.
  * @param  none
  * @retval none
  */
void USER_INT5_Handler(void)
{
}

/**
  * @brief  This function handles UART0 interrupt request.
  * @param  none
  * @retval none
  */
void UART0_Handler(void)
{
}

/**
  * @brief  This function handles UART1 interrupt request.
  * @param  none
  * @retval none
  */
void UART1_Handler(void)
{
}

/**
  * @brief  This function handles TIMER0 interrupt request.
  * @param  none
  * @retval none
  */
void TIMER0_Handler(void)
{
}

/**
  * @brief  This function handles TIMER1 interrupt request.
  * @param  none
  * @retval none
  */
void TIMER1_Handler(void)
{
}

/**
  * @brief  This function handles I2C interrupt request.
  * @param  none
  * @retval none
  */
void I2C_Handler(void)
{
}

#if 0
/**
  * @brief  This function handles RTC interrupt request.
  * @param  none
  * @retval none
  */
static bool led_flag = true;

void RTC_Handler(void)
{
	printf("Enter RTC Interrupt.\r\n");
	
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
	
	printf("Exit RTC Interrupt.\r\n");
}
#endif

/**
  * @}
  */ 

/*************************GowinSemiconductor*****END OF FILE*********************/
