/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			task_app.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/

/* Include-------------------------------------------------------------------------------- */
#include "gw1ns4c.h"
#include "uart_app.h"
#include "includes.h"
#include "printf.h"
#include "led.h"
#include "task_app.h"

/* Macros-------------------------------------------------------------------------------- */
#define SW_STR_NAME							"Gowin_EMPU(GW1NS-4C)_UC/OS-III"
#define SW_STR_EDITION					"V1.x.x"
#define SW_STR_AUTHOR						"GOWIN"

#define LOGO_PRINT_ON

#ifdef LOGO_PRINT_ON
#include "logo.h"
#endif	//LOGO_PRINT_ON

#define STARTUP_TASK_PRIO		3
#define STARTUP_STK_SIZE 		96

/* Declarations-------------------------------------------------------------------------------- */
OS_TCB startup_task_tcb;
CPU_STK STARTUP_TASK_STK[STARTUP_STK_SIZE];
static void startup_task(void *p_arg);

#define APP_TASK_PRIO			(STARTUP_TASK_PRIO + 1)
#define APP_STK_SIZE 			96
OS_TCB app_task_tcb;
CPU_STK APP_TASK_STK[APP_STK_SIZE];
static void app_task(void *p_arg);

/* Funtions-------------------------------------------------------------------------------- */
//Print string
static void printf_str(const char *str)
{
#ifdef PRINTF_USE
	printf_d(str);
#else
	UART_SendString(UART_CONSOLE, (char *)str);
#endif	//PRINTF_USE
}

//Print Software informations
static void sw_edition_print(void)
{
	printf_str("\r\n");
	printf_str(starts_str);
	printf_str("Name:     "SW_STR_NAME"\r\n"
             "Edition:  "SW_STR_EDITION"\r\n"
		         "Compiled: "__DATE__", "__TIME__"\r\n"
			       "Author:   "SW_STR_AUTHOR"\r\n");
	printf_str(starts_str);
	printf_str("\r\n");
}

//Pinrt logo informations
static void start_info_print(void)
{
	sw_edition_print();

#ifdef LOGO_PRINT_ON
	printf_str("\r\n");
	printf_str(starts_str);
	printf_str(logo_str);
	printf_str(starts_str);
	printf_str("\r\n");
#endif	//LOGO_PRINT_ON
}

//Initializes
static void init_misc(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);

	uart_app_init(UART_CONSOLE_BAUDRATE);	//Initializes UART0
	led_init();														//Initializes GPIO

	start_info_print();
}

//task
static void app_task(void *p_arg)
{
	OS_ERR os_err;

	p_arg = p_arg;

	while(1)
	{
		led_toggle(0);	//LED1

		printf_str("1.app_task\r\n\r\n");
		OSTimeDlyHMSM(0, 0, 0, 1000, OS_OPT_TIME_HMSM_STRICT, &os_err);
	}
}

//Start task
static void startup_task(void *p_arg)
{
	OS_ERR os_err;
	CPU_SR_ALLOC();

	p_arg = p_arg;

	OS_CPU_SysTickInit(SystemCoreClock / OSCfg_TickRate_Hz);

	CPU_CRITICAL_ENTER();
	{
		OSTaskCreate((OS_TCB *			)&app_task_tcb,
								 (CPU_CHAR *		)"app_task",
								 (OS_TASK_PTR		)app_task,
								 (void *				)0,
								 (OS_PRIO				)APP_TASK_PRIO,
								 (CPU_STK *			)&APP_TASK_STK[0],
								 (CPU_STK_SIZE	)(APP_STK_SIZE / 10),
								 (CPU_STK_SIZE	)APP_STK_SIZE,
								 (OS_MSG_QTY		)0,
								 (OS_TICK				)0,
								 (void *				)0,
								 (OS_OPT				)(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
								 (OS_ERR *			)&os_err);

		if (OS_ERR_NONE != os_err)
		{
			while (1);
		}
	}
	CPU_CRITICAL_EXIT();

	while(1)
	{
		//led_toggle(1);
		led_toggle(0);	//LED1

		printf_str("0.startup_task\r\n");
		OSTimeDlyHMSM(0, 0, 0, 250, OS_OPT_TIME_HMSM_STRICT, &os_err);
	}
}

void task_app(void)
{
	OS_ERR os_err;
	CPU_SR_ALLOC();

	init_misc();
  CPU_Init();
  OSInit(&os_err);
	
  if (OS_ERR_NONE != os_err)
	{
     while (1);
  }

	CPU_CRITICAL_ENTER();
	{
		OSTaskCreate((OS_TCB *			)&startup_task_tcb,
								 (CPU_CHAR *		)"startup_task",
								 (OS_TASK_PTR		)startup_task,
								 (void *				)0,
								 (OS_PRIO				)STARTUP_TASK_PRIO,
								 (CPU_STK *			)&STARTUP_TASK_STK[0],
								 (CPU_STK_SIZE	)(STARTUP_STK_SIZE / 10),
								 (CPU_STK_SIZE	)STARTUP_STK_SIZE,
								 (OS_MSG_QTY		)0,
								 (OS_TICK				)0,
								 (void *				)0,
								 (OS_OPT				)(OS_OPT_TASK_STK_CHK | OS_OPT_TASK_STK_CLR),
								 (OS_ERR *			)&os_err);

		if (OS_ERR_NONE != os_err)
		{
			while (1);
		}
	}
	CPU_CRITICAL_EXIT();

	OSStart(&os_err);

	while (1)
	{
		;
	}
}
