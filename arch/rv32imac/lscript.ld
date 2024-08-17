ENTRY(__start)

MEMORY
{
	ROM   (rx)  : ORIGIN = 0x40000000, LENGTH = 320K
	RAM   (rwx) : ORIGIN = 0x40800000, LENGTH = 512K
	FLASH (rx)  : ORIGIN = 0x42000000, LENGTH = 16M
}

SECTIONS
{
	.text :
	{
		*(.text.head)
		*(.text)
	} > FLASH
	
	.rodata :
	{
		*(.rodata)
	} > RAM

	.data :
	{
		*(.data)
	} > RAM

	. = ALIGN(0x8);
	.bss :
	{
		__bss_start__ = .;
		*(.bss)
		__bss_end__ = .;
	} > RAM
}
