/* app.ld */
/* Define output sections */
SECTIONS
{  
  /* The startup code goes first into FLASH */
  .intvec (ORIGIN(REGION_FLASH)) :
  {
    . = ALIGN(4);
    
    KEEP(*(.intvec)) /* Startup code */
    
    . = ALIGN(4);
  } >REGION_FLASH


  /* The program code and other data goes into FLASH */
  .text :
  {
    . = ALIGN(4);

    KEEP(*(.cmd_call_table))
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(i.*)             /* i.* sections (code) */
    *(.rodata)         /* .rodata sections (constants, strings, etc.) */
    *(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    *(.constdata)
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */

    . = ALIGN(4);
     _etext = .;
  } >REGION_FLASH

  /* used by the startup to initialize data */
  _sidata = LOADADDR(.data);
  /* used by the startup to initialize data */
  _sidata2 = LOADADDR(.ram_preamble);


  /* RAM preamble no init */
  .ram_preamble_noinit 0x20000000 (NOLOAD) :
  {
    . = ALIGN(4);
    . = 0x04 ; /* There is a waste of RAM here */
    KEEP(*(.ota_sw_activation))
  }  >REGION_RAM

  /* RAM preamble initialized */
  .ram_preamble 0x20000008 /*(NOLOAD)*/ :
  {
    _sdata2 = .;        /* create a global symbol at data start */
    /* This is used by the startup in order to initialize the .bss section */
    KEEP(*(.savedMSP))
    . = 0x04 ;
    KEEP(*(.wakeupFromSleepFlag))
    . = 0x08 ;
    KEEP(*(.app_base))
    . = 0x0C ;
    KEEP(*(.flash_sw_lock))
    . = 0x10;
    KEEP(*(.rfTimeout))
    . = 0x14 ;
    KEEP(*(.BOR_config))
    . = 0x28 ;
    KEEP(*(.__blueflag_RAM))
      _edata2 = .;        /* create a global symbol at data end (.__crash_RAM is skipped since it must not be initialized) */
  }  >REGION_RAM AT> REGION_FLASH

  /* RAM preamble no init */
  .ram_preamble_noinit2 0x20000034 (NOLOAD) :
  {
    KEEP(*(.__crash_RAM))
  }  >REGION_RAM
  /* Uninitialized data section */
   
  .bss.blueRAM 0x200000C0 :
  {
    . = ALIGN(4);
    _sbssblue = .;         /* define a global symbol at .bss.blueRAM start */
    KEEP(*(.bss.__blue_RAM))
    . = ALIGN(4);
    _ebssblue = .;         /* define a global symbol at .bss.blueRAM end */
    
    . = 0x20c + MEMORY_RAM_APP_OFFSET - 0x2cc;
    
  } >REGION_RAM  
  
  .bss  :
  {
    . = ALIGN(4);
    _sbss = .;         /* define a global symbol at bss start */
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
  } >REGION_RAM

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data :
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
  } >REGION_RAM AT> REGION_FLASH
  
  /* Data section that will not be initialized to any value. */
  .noinit (NOLOAD):
  {
    . = ALIGN(4);
    *(.noinit)
    . = ALIGN(4);
  } >REGION_RAM

/**
* Last two sectors of FLASH are reserved for BLE Stack. The BLE Host
* stores its security database and other non-volatile information in this area.
* The linker needs to make sure this area is left empty.
*/
  BLOCK_STACKLIB_FLASH_DATA (_MEMORY_FLASH_END_ - FLASH_NVM_DATASIZE + 1) (NOLOAD) :
  {
    . = ALIGN(2048);
    
    KEEP(*(.noinit.stacklib_flash_data))
    KEEP(*(.noinit.stacklib_stored_device_id_data))
    
  } >REGION_NVM



  /* This is to emulate place at end of IAR linker */
  CSTACK (ORIGIN(REGION_RAM) + LENGTH(REGION_RAM) - _Min_Stack_Size) (NOLOAD) :
  {
    . = ALIGN(4);
    _estack = . + _Min_Stack_Size;         /* define a global symbol at bss end */
    . = ALIGN(4);
  } > REGION_RAM

  
  .rom_info (NOLOAD) :
  {
    . = ALIGN(4);
    KEEP(*(.rom_info)) 
    . = ALIGN(4);
  } >REGION_ROM
  
  /* Remove information from the standard libraries */
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
