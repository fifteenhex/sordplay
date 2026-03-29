MEMORY { .rom(rx) : ORIGIN = 0xe00000, LENGTH = 16K }
OUTPUT_ARCH(m68k)
ENTRY(_start)

SECTIONS
{
	.text :
	{
		*(.start*)
	} > .rom
}
