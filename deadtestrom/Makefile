MAKEFLAGS += --no-builtin-rules

M68KCC=m68k-linux-gnu-gcc
M68KLD=m68k-linux-gnu-ld
M68KOBJCOPY=m68k-linux-gnu-objcopy

all: deadtestrom.even deadtestrom.odd

start.o: start.S m68mx.h
	$(M68KCC) -c -o $@ $<

deadtestrom.elf: start.o
	$(M68KLD) -T deadtestrom.lds $^ -o $@

deadtestrom.bin: deadtestrom.elf
	$(M68KOBJCOPY) -O binary $< $@

romsplit: romsplit.c
	$(CC) -o $@ $<

deadtestrom.even deadtestrom.odd: deadtestrom.bin romsplit
	./romsplit $< deadtestrom

M68MX-EVEN.01E:
	wget -O $@ "https://archive.org/download/sordm68mxrom/SORD%20MX-MAIN-C/M68MX-EVEN.01E"

M68MX-ODD.01E:
	wget -O $@ "https://archive.org/download/sordm68mxrom/SORD%20MX-MAIN-C/M68MX-ODD.01E"

deadtestrom.onerom.even: deadtestrom.even M68MX-EVEN.01E
	onerom firmware build --board fire-28-a --slot file=$<,type=27C64 \
	--slot file=M68MX-EVEN.01E,type=27C64 \
	-o $@


deadtestrom.onerom.odd: deadtestrom.odd M68MX-ODD.01E
	onerom firmware build --board fire-28-a --slot file=$<,type=27C64 \
	--slot file=M68MX-ODD.01E,type=27C64 \
	-o $@

.PHONY: flash.odd flash.even

flash.even: deadtestrom.onerom.even
	onerom program --serial 384910EBD4AFB283 --firmware deadtestrom.onerom.even

flash.odd: deadtestrom.onerom.odd
	onerom program --serial 7B760F4DE7FF27BE --firmware deadtestrom.onerom.odd

.PHONY: clean
clean:
	rm -rf *.o *.elf *.bin *.even *.odd
