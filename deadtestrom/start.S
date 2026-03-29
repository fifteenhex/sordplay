.section .start, "ax"

_initial_sp:
	.long 0x0
_initial_pc:
	.long _start

.global _start
_start:
	jmp .


