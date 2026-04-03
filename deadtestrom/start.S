#include "m68mx.h"

.section .start, "ax"

_initial_sp:
	.long 0x0
_initial_pc:
	.long _start

.global _start
_start:

	move.l #PTM, %a0
	/* Select CR1 */
#if 0
	move.b #0x1, PTM_CR2(%a0)
	move.b #0x82, PTM_CR1_CR3(%a0)

	move.w #0x4ef1, 4(%a0)
	move.b #0x82, 2(%a0)

	move.w #0x7, 2(%a0)
	move.b #0x0, 2(%a0)

	move.w #0xee, 0xc(%a0)
#endif

#if 0
	lea CRTC, %a0
	move.b #0x6f, (%a0)
	move.b #0x50, (%a0)
	move.b #0x5a, (%a0)
	move.b #0x8c, (%a0)
	move.b #0x19, (%a0)
	move.b #0x0c, (%a0)
	move.b #0x19, (%a0)
	move.b #0x19, (%a0)
	move.b #0x40, (%a0)
	move.b #0x13, (%a0)
	move.b #0x72, (%a0)
	move.b #0x12, (%a0)
	move.b #0x0, (%a0)
	move.b #0x0, (%a0)
	move.b #0x0, (%a0)
	move.b #0x0, (%a0)
#endif

#if 0
	lea TEXTVRAM, %a0
	lea TEXTVRAM, %a1
	add.l #TEXTVRAMSZ, %a1
_cleartextvramloop:
	move.l #0x70020, (%a0)+
	cmp %a0, %a1
	bne _cleartextvramloop
#endif

#if 0
	move.b	#0x15, ACIA2_CS
	move.b	'a', ACIA2_DATA
#endif

_spin:
.rept 406
	nop
	nop
.endr
	jmp _spin


