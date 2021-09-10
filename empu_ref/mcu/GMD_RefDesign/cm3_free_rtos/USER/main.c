/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file		  main.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date		  2021-01-01 09:00:00
 * @brief		  main function
 ******************************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

//FreeRTOS Library
#include "FreeRTOS.h"
#include "task.h"

/* Definitions ------------------------------------------------------------------*/
#define SW_STR_NAME						"GW1NS_4C_FreerRTOS_V10.2.1"	//Software name
#define SW_STR_EDITION				"V1.x.x"											//Software version
#define SW_STR_AUTHOR					"GOWIN"												//Author

#define LOGO_PRINT_ON
#ifdef LOGO_PRINT_ON
#include "logo.h"
#endif	//LOGO_PRINT_ON

#define TASK_DELAY_MS_TO_TICK(ms)		((ms) / (1000 / configTICK_RATE_HZ))

//Task 1
#define LED0_TASK_PRIO			1
#define LED0_STK_SIZE 			16
TaskHandle_t LED0Task_Handler;
volatile int led0_task_flag = 0;

//Task 2
#define LED1_TASK_PRIO			2
#define LED1_STK_SIZE 			16
TaskHandle_t LED1Task_Handler;
volatile int led1_task_flag = 0;

/* Declarations ------------------------------------------------------------------*/
extern void xPortSysTickHandler(void);
static void led0_task(void *pvParameters);
static void led1_task(void *pvParameters);
static void printf_str(const char *str);
static void stars_print(uint8_t n);
static void sw_edition_print(void);
static void GPIOInit(void);
static void UARTInit(uint32_t baudrate);
static void sys_tick_init(void);

/* Functions ------------------------------------------------------------------*/
int main(void)
{
	SystemInit();						//Initializes system
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	//config NVIC
	UARTInit(115200);				//Initializes UART0
	GPIOInit();							//Initializes GPIO
	
	sw_edition_print();
	
#ifdef LOGO_PRINT_ON
	printf_str(LOGO);
#endif	//LOGO_PRINT_ON

	sys_tick_init();				//Initializes Systick
	
	taskENTER_CRITICAL();
	
  xTaskCreate((TaskFunction_t )led0_task,
              (const char *   )"led0_task",
              (uint16_t       )LED0_STK_SIZE,
              (void *         )NULL,
              (UBaseType_t    )LED0_TASK_PRIO,
              (TaskHandle_t *  )&LED0Task_Handler);

  xTaskCreate((TaskFunction_t )led1_task,
              (const char *   )"led1_task",
              (uint16_t       )LED1_STK_SIZE,
              (void *         )NULL,
              (UBaseType_t    )LED1_TASK_PRIO,
              (TaskHandle_t * )&LED1Task_Handler);
				
  taskEXIT_CRITICAL();
	
  vTaskStartScheduler();
	
	while(1);
}

//Print string
static void printf_str(const char *str)
{
	UART_SendString(UART0, (char *)str);
}

//Print *
static void stars_print(uint8_t n)
{
	while (n--)
	{
		printf_str("*");
	}
}

//Print software information
static void sw_edition_print(void)
{
	printf_str("\r\n");
	stars_print(48);
	printf_str("\r\n");
	printf_str("************************************************\r\n");
	printf_str("Name:     "SW_STR_NAME"\r\n"
						 "Edition:  "SW_STR_EDITION"\r\n"
						 "Compiled: "__DATE__", "__TIME__"\r\n"
						 "Author:   "SW_STR_AUTHOR"\r\n");
	printf_str("************************************************\r\n");
	stars_print(48);
	printf_str("\r\n\r\n");
}

//Initializes GPIO
static void GPIOInit(void)
{
	GPIO_InitTypeDef GPIO_InitType;
	
	GPIO_InitType.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitType.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitType.GPIO_Int = GPIO_Int_Disable;

	GPIO_Init(GPIO0,&GPIO_InitType);

  GPIO_SetBit(GPIO0,GPIO_Pin_0);
}

//Initializes UART0
static void UARTInit(uint32_t baudrate)
{
	UART_InitTypeDef UART_InitStruct;

	UART_InitStruct.UART_Mode.UARTMode_Tx = ENABLE;
	UART_InitStruct.UART_Mode.UARTMode_Rx = ENABLE;
	UART_InitStruct.UART_Int.UARTInt_Tx = DISABLE;
	UART_InitStruct.UART_Int.UARTInt_Rx = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Tx = DISABLE;
	UART_InitStruct.UART_Ovr.UARTOvr_Rx = DISABLE;
	UART_InitStruct.UART_Hstm = DISABLE;
	UART_InitStruct.UART_BaudRate = baudrate;

	UART_Init(UART0,&UART_InitStruct);
}

//Initializes Systick
static void sys_tick_init(void)
{
	uint32_t temp;
	
	//24-bit register, max value is 16777215
	//When SystemCoreClock is 25MHz, it is 671ms
	//Set value of reload register
	temp = (1000 / configTICK_RATE_HZ) * (SystemCoreClock / 1000) - 1;
	SysTick->LOAD = temp;
	
	SysTick->VAL = temp;	//Reset current counter value

	//Select clock source, enable interrupt, enable counter
	SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; 
}

//Systick interrupt handler
void SysTick_Handler(void)
{
	if(taskSCHEDULER_NOT_STARTED != xTaskGetSchedulerState())
    {
        xPortSysTickHandler();	
    }
}

//Task 1
static void led0_task(void *pvParameters)
{
  while (1)
	{
		if (0 == led0_task_flag)
		{
			GPIO_ResetBit(GPIO0, GPIO_Pin_0);
		}
		else
		{
			GPIO_SetBit(GPIO0, GPIO_Pin_0);
		}
		
		printf_str("0.task0\r\n");
		led0_task_flag = !led0_task_flag;
		vTaskDelay(TASK_DELAY_MS_TO_TICK(250));
	}
}

//Task 2
static void led1_task(void *pvParameters)
{
  while (1)
	{
		if (0 == led1_task_flag)
		{
			GPIO_ResetBit(GPIO0, GPIO_Pin_1);
		}
		else
		{
			GPIO_SetBit(GPIO0, GPIO_Pin_1);
		}
		
		printf_str("1.task1\r\n\r\n");
		led1_task_flag = !led1_task_flag;
		vTaskDelay(TASK_DELAY_MS_TO_TICK(1000));
	}
}
