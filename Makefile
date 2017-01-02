# by: MaG.

include Makefile.inc

VPATH = build

$(LIB_NAME): lib src generate_header.o 
	ar rcs build/$(LIB_NAME) src/utils.o src/load.o lib/hash.o lib/ini.o

.PHONY: lib src tests

lib:
	$(ECHO) "Stepping into: lib/"
	$(MAKE) -I.. -C lib/

src: generate_header.o
	$(ECHO) "Stepping into: src/"
	$(MAKE) -I.. -C src/

generate_header.o: generate_header.c lib/hash.o
	$(CC) -c $< $(CFLAGS) -I./lib/
	$(CC) -o build/generate_header generate_header.o lib/hash.o $(CFLAGS)

	./build/generate_header include/

tests:
	$(MAKE) -C tests/ -I..

clean:
	-rm -f build/generate_header build/$(LIB_NAME)

	$(MAKE) clean -C lib/ -I../
	$(MAKE) clean -C src/ -I../
	$(MAKE) clean -C tests/ -I../

