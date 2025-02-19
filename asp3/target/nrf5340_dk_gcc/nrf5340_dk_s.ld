MEMORY
{
    FLASH(rx) : ORIGIN = 0x00000000, LENGTH = 0x7FE00
    SG_veneer_table (rx) : ORIGIN = 0x7FE00, LENGTH = 0x200
    /* It might be unfare that only secure code can use single-cycle RAM */
    RAM(rwx) : ORIGIN =  0x20000000, LENGTH = 128k
}

ENTRY(_kernel_start)

PROVIDE(hardware_init_hook = 0);
PROVIDE(software_init_hook = 0);
PROVIDE(software_term_hook = 0);
PROVIDE(__flash_start = ORIGIN(FLASH));
PROVIDE(__flash_end = ORIGIN(FLASH) + LENGTH(FLASH) + LENGTH(SG_veneer_table));
PROVIDE(__nsc_start = ORIGIN(SG_veneer_table));
PROVIDE(__nsc_size = LOG2CEIL(LENGTH(SG_veneer_table)) - 4);
PROVIDE(__ram_start = ORIGIN(RAM));
PROVIDE(__ram_end = ORIGIN(RAM) + LENGTH(RAM));

ASSERT((ORIGIN(FLASH) % (16 * 1024)) == 0, "FLASH origin address must be 16 kB aligned.");
ASSERT((ORIGIN(FLASH) + LENGTH(FLASH)) == ORIGIN(SG_veneer_table), "SG_veneer_table must be at the end of FLASH");
ASSERT(((ORIGIN(SG_veneer_table) + LENGTH(SG_veneer_table)) % (16 * 1024)) == 0, "SG_veneer_table must be end at 16 kB aligned address");
ASSERT((LENGTH(SG_veneer_table) ==   32) || (LENGTH(SG_veneer_table) ==   64) || (LENGTH(SG_veneer_table) ==  128) &&
       (LENGTH(SG_veneer_table) ==  256) || (LENGTH(SG_veneer_table) ==  512) || (LENGTH(SG_veneer_table) == 1024) &&
       (LENGTH(SG_veneer_table) == 2048) || (LENGTH(SG_veneer_table) == 4096),
       "Length of SG_veneer_table must be 32, 64, 128, 256, 512, 1024, 2048, or 4096.");
ASSERT((ORIGIN(RAM) % (8 * 1024)) == 0, "RAM origin address must be 8 kB aligned.");
ASSERT(((ORIGIN(RAM) + LENGTH(RAM)) % (8 * 1024)) == 0, "RAM end address must be 8 kB aligned.");

SECTIONS
{
    .gnu.sgstubs : ALIGN (32)
    {
        . = ALIGN(32);
        _start_sg = .;
        *(.gnu.sgstubs*)
        . = ALIGN(32);
        _end_sg = .;
    } > SG_veneer_table

    /* MAIN TEXT SECTION */
    .text : ALIGN(4)
    {
        KEEP(*(.vector))
        *(.text*)
        *(.rodata .rodata.* .constdata .constdata.*)
        KEEP(*(.empty.*))
        . = ALIGN(4);
    } > FLASH

    __idata_start = .;
    /* Main DATA section (SRAM) */
    .data : ALIGN(4)
    {
        __data_start = .;
        *(.data*)
    } > RAM AT>FLASH
    __idata_end = __idata_start + SIZEOF(.data);

    /* MAIN BSS SECTION */
    .bss : ALIGN(4)
    {
        __bss_start = .;
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        __bss_end = .;
    } > RAM
}
