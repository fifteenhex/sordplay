MAKEFLAGS += --no-builtin-rules

M68KCC=m68k-linux-gnu-gcc
M68KLD=m68k-linux-gnu-ld
M68KOBJCOPY=m68k-linux-gnu-objcopy

all: deadtestrom.even deadtestrom.odd

start.o: start.S
	$(M68KCC) -c -o $@ $<

deadtestrom.elf: start.o
	$(M68KLD) -T deadtestrom.lds $^ -o $@

deadtestrom.bin: deadtestrom.elf
	$(M68KOBJCOPY) -O binary $< $@

romsplit: romsplit.c
	$(CC) -o $@ $<

deadtestrom.even deadtestrom.odd: deadtestrom.bin romsplit
	./romsplit $< deadtestrom


deadtestrom.onerom.even: deadtestrom.even
	onerom firmware build --board fire-28-a --slot file=$<,type=27C64 \
	-o $@


deadtestrom.onerom.odd: deadtestrom.odd
	onerom firmware build --board fire-28-a --slot file=$<,type=27C64 \
	-o $@

.PHONY: flash.odd flash.even

flash.even: deadtestrom.onerom.even
	onerom program --serial 384910EBD4AFB283 --firmware deadtestrom.onerom.even

flash.odd: deadtestrom.onerom.odd
	onerom program --serial 7B760F4DE7FF27BE --firmware deadtestrom.onerom.odd

.PHONY: clean
clean:
	rm -rf *.o *.elf *.bin *.even *.odd
