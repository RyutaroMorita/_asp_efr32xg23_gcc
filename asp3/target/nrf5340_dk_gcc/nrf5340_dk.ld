MEMORY
{
    FLASH(rx) : ORIGIN = 0x00000000, LENGTH = 1024k
    RAM(rwx) : ORIGIN =  0x20000000, LENGTH = 512k
}

ENTRY(_kernel_start)

SECTIONS
{
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
