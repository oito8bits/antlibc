ENTRY(_start)

virtual_entrypoint = 0x400000;

SECTIONS
{
  . = virtual_entrypoint;
  
  .text ALIGN(0x1000):
  {
    *(.text)
    *(.text*)
  }

  .data ALIGN(0x1000):
  {
    *(.data)
    *(.data*)
  }

  .rodata ALIGN(0x1000):
  {
    *(.rodata)
    *(.rodata*)
  }
  
  .bss ALIGN(0x1000):
  {
    *(.bss)
    *(.bss*)
  }
}
