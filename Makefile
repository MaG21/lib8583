# by: MaG.

include Makefile.inc

all: lib generator src

lib:
	$(ECHO) "Stepping into: lib/"
	$(MAKE) -I.. -C lib/

src: generator
	$(ECHO) "Stepping into: src/"
	$(MAKE) -I.. -C src/

generator: lib generate_header.c
	$(CC) -o build/generate_header generate_header.c build/hash.o $(CFLAGS) -I./lib/

	./build/generate_header include/

clean:
	rm ./build/*

	$(MAKE) clean -C lib/ -I../
	$(MAKE) clean -C src/ -I../

.PHONY: all generator lib src
