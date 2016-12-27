CC=gcc
CFLAGS=-v -Wall -O3 -Ilib/

all: remove

remove: generator run
	rm generate_header

run:
	./generate_header include/

generator: generate_header.c lib/crc32.c lib/crc32.h
	$(CC) -o generate_header generate_header.c lib/crc32.c $(CFLAGS)

.PHONY: all run remove generator

