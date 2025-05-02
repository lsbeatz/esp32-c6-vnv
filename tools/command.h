#ifndef COMMAND_H
#define COMMAND_H

enum command_type {
    /* Begin Flash Download */             FLASH_BEGIN         = 0x02,
    /* Flash Download Data */              FLASH_DATA          = 0x03,
    /* Finish Flash Download */            FLASH_END           = 0x04,
    /* Begin RAM Download Start */         MEM_BEGIN           = 0x05,
    /* Finish RAM Download */              MEM_END             = 0x06,
    /* RAM Download Data */                MEM_DATA            = 0x07,
    /* Sync Frame */                       SYNC                = 0x08,
    /* Write 32-bit memory address */      WRITE_REG           = 0x09,
    /* Read 32-bit memory address */       READ_REG            = 0x0A,
    /* Configure SPI flash */              SPI_SET_PARAMS      = 0x0B,
    /* Attach SPI flash */                 SPI_ATTACH          = 0x0D,
    /* Change Baud rate */                 CHANGE_BAUDRATE     = 0x0F,
    /* Begin compressed flash download */  FLASH_DEFL_BEGIN    = 0x10,
    /* Compressed flash download data */   FLASH_DEFL_DATA     = 0x11,
    /* End compressed flash download */    FLASH_DEFL_END      = 0x12,
    /* Calculate MD5 of flash region */    SPI_FLASH_MD5       = 0x13,
    /* Read chip security info */          GET_SECURITY_INFO   = 0x14,
};

union command {
	uint8_t raw;

	struct {
		uint8_t dir :1;
		uint8_t cmd :1;
		uint8_t size:2;
		uint8_t checksum:4;
	} request;
	
	struct {
		uint8_t dir :1;
		uint8_t cmd :1;
		uint8_t size:2;
		uint8_t value:4;
	} response;
};

#endif /* COMMAND_H */
