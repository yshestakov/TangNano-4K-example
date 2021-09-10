/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file        malloc.h
 * @author      Embedded Development Team
 * @version     V1.x.x
 * @date        2021-01-01 09:00:00
 * @brief       memory management
 ******************************************************************************************
 */

#ifndef __MALLOC_H  
#define __MALLOC_H  

/* Includes --------------------------------------------------------------------- */
#include "gw1ns4c.h"

/* Macros --------------------------------------------------------------------- */
#ifndef NULL
#define NULL 0
#endif  

#define MEM_BLOCK_SIZE          8
#define MEM_MAX_SIZE            3296
#define MEM_ALLOC_TABLE_SIZE    MEM_MAX_SIZE/MEM_BLOCK_SIZE

/* Definitions --------------------------------------------------------------------- */     
struct _m_mallco_dev  
{
    void (*init)(void);
    uint8_t (*perused)(void);
    uint8_t  *membase;
    uint8_t *memmap;
    uint8_t  memrdy;
};

extern struct _m_mallco_dev mallco_dev;

/* Declarations --------------------------------------------------------------------- */
void mymemset(void *s,uint8_t c,uint32_t count);
void mymemcpy(void *des,void *src,uint32_t n);
int mymemcmp(void*des,void*src,uint32_t n);
void mem_init(void);
uint32_t mem_malloc(uint32_t size);
uint8_t mem_free(uint32_t offset);
uint8_t mem_perused(void);

void myfree(void *ptr);
void *mymalloc(uint32_t size);

#endif 
