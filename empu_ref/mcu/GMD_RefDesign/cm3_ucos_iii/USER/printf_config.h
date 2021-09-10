/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			printf_config.h
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/
 
#ifndef	__PRINTF_CONFIG_H_
#define	__PRINTF_CONFIG_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/* Macros---------------------------------------------------------------------------------- */	
#define PRINTF_DISABLE_SUPPORT_FLOAT
#define PRINTF_DISABLE_SUPPORT_EXPONENTIAL
#define PRINTF_DISABLE_SUPPORT_LONG_LONG

#ifdef __cplusplus
}  //extern "C"
#endif //__cplusplus

#endif /* __PRINTF_CONFIG_H_ */
