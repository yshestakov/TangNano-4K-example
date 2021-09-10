/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file			task_app.h
 * @author		Embedded Development Team
 * @version		V1.x.x
 * @date			2021-01-01 09:00:00
 * @brief			uC/OS-III task application
 ******************************************************************************************/
 
#ifndef	__TASK_APP_H_
#define	__TASK_APP_H_

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

/* Macros-------------------------------------------------------------------------------- */
#define PRINTF_USE

#ifdef	PRINTF_USE
#define printf_d(args...)					printf(args)
#endif	//PRINTF_USE

/* Declarations-------------------------------------------------------------------------------- */
extern void task_app(void);


#ifdef __cplusplus
}  //extern "C"
#endif //__cplusplus

#endif    /* __TASK_APP_H_ */
