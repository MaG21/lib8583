include Makefile.inc

all: crc inih

inih: inih/ini.c inih/ini.h
	$(CC) -c -o ../build/ini.o inih/ini.c $(CFLAGS)

crc: crc32.c crc32.h
	$(CC) -c -o ../build/crc32.o crc32.c $(CFLAGS)

clean:

.PHONY: inih crc
