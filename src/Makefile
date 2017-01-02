include Makefile.inc

INCLUDE = -I. -I../include -I../lib -I ../lib/inih/
VPATH = ../build ../include/8583.h

.PHONY: all clean

all: load.o utils.o

load.o: load.c utils.o constants.h 8583.h
	$(CC) -c -o ../build/$@ $< $(CFLAGS) $(INCLUDE)

utils.o: utils.c utils.h
	$(CC) -c -o ../build/$@ $< $(CFLAGS) $(INCLUDE)

clean:
	-$(RM) *.o

