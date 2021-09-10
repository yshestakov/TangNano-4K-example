----------------------------------------------------------------
Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.   
                    All rights reserved.
----------------------------------------------------------------
		Gowin_EMPU(GW1NS-4C) MCU Reference Design
----------------------------------------------------------------
MCU IDE
	ARM Keil MDK V5.26 [not copied from Gowin IDE]
	GowinMCU Designer (GMD) V1.1 [Ecplise based]
----------------------------------------------------------------

There is an issue with `printf`: it causes hangs.
So, some of examples were rewritten by using UART_SendString and
UART_SendChar instead