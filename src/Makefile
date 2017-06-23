include Makefile.inc

VPATH = ../include
INCLUDE = -I. -I../include -I../lib -I ../lib/inih/

.PHONY: all clean

all: load.o utils.o

load.o: load.c utils.o constants.h 8583.h
	$(CC) -c $< $(CFLAGS) $(INCLUDE)

utils.o: utils.c utils.h
	$(CC) -c $< $(CFLAGS) $(INCLUDE)

clean:
	-rm -f *.o

