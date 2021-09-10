/*
 * *****************************************************************************************
 *
 * 		Copyright (C) 2014-2021 Gowin Semiconductor Technology Co.,Ltd.
 * 		
 * @file      spi_nor_flash.h
 * @author    Embedded Development Team
 * @version   V1.x.x
 * @date      2021-01-01 09:00:00
 * @brief     spi nor flash.
 ******************************************************************************************
 */

#ifndef SPI_NOR_FLASH_H
#define SPI_NOR_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "gw1ns4c.h"

/* Definitions ------------------------------------------------------------------*/
//SPI_Nor_Flash typedef definition
typedef struct 
{
	unsigned int IDREV;                /* Offset: 0x00 (R/ ) ID and revision Register           */
	unsigned int RESERVED0[3];         /* Offset: 0x04~0x0c Reserved                            */
	unsigned int TRANSFMT;             /* Offset: 0x10 (R/W) SPI transfer format Register       */
	unsigned int DIRECTIO;             /* Offset: 0x14 (R/W) SPI direct IO control Register     */
	unsigned int RESERVED1[2];         /* Offset: 0x18~0x1c Reserved                            */
	unsigned int TRANSCTRL;            /* Offset: 0x20 (R/W) SPI transfer control Register      */
	unsigned int CMD;                  /* Offset: 0x24 (R/W) SPI command Register               */
	unsigned int ADDR;                 /* Offset: 0x28 (R/W) SPI address Register               */
	unsigned int DATA;                 /* Offset: 0x2c (R/W) SPI data Register                  */
	unsigned int CTRL;                 /* Offset: 0x30 (R/W) SPI control Register               */
	unsigned int STATUS;               /* Offset: 0x34 (R/ ) SPI status Register                */
	unsigned int INTREN;               /* Offset: 0x38 (R/W) SPI interrupt enable Register      */
	unsigned int INTRST;               /* Offset: 0x3c ( /W)SPI interrupt status Register       */
	unsigned int TIMING;               /* Offset: 0x40 (R/W) SPI interface timing Register      */
	unsigned int RESERVED2[3];         /* Offset: 0x44~0x4c Reserved                            */
	unsigned int MEMCTRL;              /* Offset: 0x50 (R/W) SPI memory access control Register */
	unsigned int RESERVED3[3];         /* Offset: 0x54~0x5c Reserved                            */
	unsigned int SLVST;                /* Offset: 0x60 (R/W) SPI slave status Register          */
	unsigned int SLVDATACNT;           /* Offset: 0x64 (R/ ) SPI slave data count Register      */
	unsigned int RESERVED4[5];         /* Offset: 0x68~0x78 Reserved                            */
	unsigned int CONFIG;               /* Offset: 0x7c (R/ ) Configuration Register             */
}SPI_NOR_FLASH_TypeDef;

//Address definition
#define SPI_NOR_FLASH_BASE    (APB2MASTER1_BASE)    	/* !< SPI_Nor_Flash Base Address> 							*/

//Type definition
#define SPI_NOR_FLASH         ((SPI_NOR_FLASH_TypeDef  *) SPI_NOR_FLASH_BASE)


/* Macros ------------------------------------------------------------------*/
#define SPI_CMDEN                     (1UL << 30)
#define SPI_ADDREN                    (1UL << 29)

//The winbone SPI_Nor_Flash command
#define CHIP_ERASE                    0x60
#define WRITE_ENABLE                  0x06
#define WRITE_DISABLE                 0x04


/* Declarations ------------------------------------------------------------------*/
/**
  * @brief Initializes SPI_Nor_Flash
  */
extern void spi_nor_flash_init(void);
/**
  * @brief Switch SPI_Nor_Flash mode between download and read/write/erase memory
  */
extern void change_mode_spi_nor_flash(void);
/**
  * @brief Read data from SPI_Nor_Flash
  */
extern void spi_nor_flash_read(uint8_t rd_len, uint32_t cmd, uint32_t address,uint8_t *read_buffer);
/**
  * @brief Write data into SPI_Nor_Flash
  */
extern void spi_nor_flash_write(uint8_t wr_len, uint32_t cmd, uint32_t address,uint8_t *write_buffer);
/**
  * @brief Write data into SPI_Nor_Flash and read data from SPI_Nor_Flash
  */
extern void spi_nor_flash_write_read(uint8_t wr_len, uint8_t rd_len, uint32_t cmd, uint8_t *wr_buffer, uint8_t *rd_buffer);
/**
  * @brief Write data into a page of SPI_Nor_Flash
  */
extern void spi_nor_flash_page_program(uint8_t wr_len,uint32_t address,uint8_t *write_buffer);
/**
  * @brief Erase a sector of SPI_Nor_Flash
  */
extern void spi_nor_flash_sector_erase(uint32_t address);


#ifdef __cplusplus
}
#endif

#endif  /* SPI_NOR_FLASH_H */
