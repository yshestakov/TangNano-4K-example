/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			uart_app.c
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/
 
#ifndef	__UART_APP_H_
#define	__UART_APP_H_

/* Include------------------------------------------------------------------------------- */
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/* Macros------------------------------------------------------------------------------- */
#define UART_CONSOLE					UART0
#define UART_CONSOLE_BAUDRATE			115200

/* Declarations------------------------------------------------------------------------------- */
extern void _putchar(char character);
extern void uart_app_init(uint32_t baudrate);

#ifdef __cplusplus
}  //extern "C"
#endif //__cplusplus

#endif   /* __UART_APP_H_ */
