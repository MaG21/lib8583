include Makefile.inc

INCLUDE = -I. -I../include -I../lib -I ../lib/inih/

all: load.o utils.o

load.o: utils.o load.[ch]
	$(CC) -c -o ../build/load.o load.c $(CFLAGS) $(INCLUDE)

utils.o: utils.[ch]
	$(CC) -c -o ../build/utils.o utils.c $(CFLAGS) $(INCLUDE)

