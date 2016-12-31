include Makefile.inc

all: hash inih

inih: inih/ini.c inih/ini.h
	$(CC) -c -o ../build/ini.o inih/ini.c $(CFLAGS)

hash: hash.c hash.h
	$(CC) -c -o ../build/hash.o hash.c $(CFLAGS)

clean:

.PHONY: inih hash
