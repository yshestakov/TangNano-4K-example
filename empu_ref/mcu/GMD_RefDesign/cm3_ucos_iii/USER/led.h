/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			led.h
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/
 
#ifndef	__LED_H_
#define	__LED_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/* Includes-------------------------------------------------------------------------------- */
#include <stdint.h>

/* Declarations----------------------------------------------------------------------------- */
extern void led_init(void);
extern void led_on(uint8_t led);
extern void led_off(uint8_t led);
extern void led_toggle(uint8_t led);


#ifdef __cplusplus
}  //extern "C"
#endif //__cplusplus

#endif    /* __LED_H_ */
