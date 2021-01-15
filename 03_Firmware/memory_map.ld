/*******************************************************************************
* BlueNRG-1 generic linker file
*******************************************************************************/

/*******************************************************************************
* Memory Definitions
*******************************************************************************/
/*
BlueNRG-1 memory map
+-----------------------+ 0x20005FFF
|  RAM (24K)            |
+-----------------------+ 0x20000000
|                       |
|                       |
+-----------------------+ 0x10067FFF
|                       |
|  FLASH (160K)         |
+-----------------------+ 0x10040000
|                       |
+-----------------------| 0x100007FF
|   ROM (2K)            |
+-----------------------+ 0x10000000
*/

_VECTOR_TABLE_SIZE_ = 0xC0;               /* 192B */

_MEMORY_RAM_BEGIN_   =  0x20000000; 
_MEMORY_RAM_SIZE_    =  0x6000;           /* 24KB  */
_MEMORY_RAM_END_     =  0x20005FFF; 

_MEMORY_FLASH_BEGIN_ = 0x10040000;  
_MEMORY_FLASH_SIZE_  = 0x28000;           /* 160KB */ 
_MEMORY_FLASH_END_   = 0x10067FFF;  

_MEMORY_ROM_BEGIN_   = 0x10000000;    
_MEMORY_ROM_SIZE_    = 0x800;             /* 2KB */ 
_MEMORY_ROM_END_     = 0x100007FF;  


  /* This configuration is intended for application not supporting OTA firmware upgrade */
  /*
  BlueNRG-1 standard application memory map
  +-----------------------+ 0x20005FFF
  |  RAM (24K - 192B)     |
  +-----------------------+ 0x200000C0
  |  Vector Table in RAM  |
  +-----------------------+ 0x20000000
  |                       |
  |                       |
  +-----------------------+ 0x10068000
  |                       |
  |  NVM(4K)              |
  +-----------------------+ 0x10067000
  |                       |
  |  User app (152K)      |
  +-----------------------+ 0x10041000
  |  Bootloader (4k)      |
  +-----------------------+ 0x10040000
  |                       |
  +-----------------------| 0x100007FF
  |   ROM (2K)            |
  +-----------------------+ 0x10000000
*/

/* Reserved for BTLE stack non volatile memory */
FLASH_NVM_DATASIZE    = (4*1024);
/* 4k i2c bootloader for now */
/* FLASH_BOOTLOADER_SIZE = (0); */
FLASH_BOOTLOADER_SIZE = (64*1024);

MEMORY_FLASH_APP_OFFSET = DEFINED(MEMORY_FLASH_APP_OFFSET) ? (MEMORY_FLASH_APP_OFFSET) : (FLASH_BOOTLOADER_SIZE) ;
MEMORY_FLASH_APP_SIZE = DEFINED(MEMORY_FLASH_APP_SIZE) ? (MEMORY_FLASH_APP_SIZE) : ( _MEMORY_FLASH_SIZE_ - FLASH_NVM_DATASIZE - MEMORY_FLASH_APP_OFFSET);
MEMORY_RAM_APP_OFFSET = DEFINED(MEMORY_RAM_APP_OFFSET) ? (MEMORY_RAM_APP_OFFSET) : (0x2CC) ;


/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x0;      /* required amount of heap  */
_Min_Stack_Size = 0xC00; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
  REGION_RAM (xrw)         		: ORIGIN = _MEMORY_RAM_BEGIN_ + _VECTOR_TABLE_SIZE_, LENGTH = _MEMORY_RAM_SIZE_ - _VECTOR_TABLE_SIZE_
  REGION_BOOT (rx)            : ORIGIN = _MEMORY_FLASH_BEGIN_, LENGTH = FLASH_BOOTLOADER_SIZE
  REGION_FLASH (rx)        		: ORIGIN = _MEMORY_FLASH_BEGIN_ + FLASH_BOOTLOADER_SIZE, LENGTH = MEMORY_FLASH_APP_SIZE
  REGION_NVM (rx)          		: ORIGIN = _MEMORY_FLASH_END_ + 1 - FLASH_NVM_DATASIZE, LENGTH = FLASH_NVM_DATASIZE
  REGION_ROM (rx)          		: ORIGIN = _MEMORY_ROM_BEGIN_, LENGTH = _MEMORY_ROM_SIZE_
}

/* Define some variables accessible from C code */
__bootrom_start__ = ORIGIN(REGION_BOOT);
__bootrom_size__ = LENGTH(REGION_BOOT);
__approm_start__ = ORIGIN(REGION_FLASH);
__approm_size__ = LENGTH(REGION_FLASH);
__ram_start__ = ORIGIN(REGION_RAM);
__ram_size__ = LENGTH(REGION_RAM);
__vector_table_ram_start__ = _MEMORY_RAM_BEGIN_;