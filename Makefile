# by: MaG.

include Makefile.inc

VPATH = ./lib/

all: lib generator src

.PHONY: lib generator src tests

lib:
	$(ECHO) "Stepping into: lib/"
	$(MAKE) -I.. -C lib/

src: generator
	$(ECHO) "Stepping into: src/"
	$(MAKE) -I.. -C src/

generator: hash.c generate_header.c
	$(CC) -o build/generate_header generate_header.c build/hash.o $(CFLAGS) -I./lib/

	./build/generate_header include/

tests:
	$(MAKE) -C tests/ -I..

clean:
	-$(RM) build/generate_header build/*.o

	$(MAKE) clean -C lib/ -I../
	$(MAKE) clean -C src/ -I../

