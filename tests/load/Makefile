include ../../Makefile.inc

VPATH   = ../../build/
INCLUDE = -I. -I../../include -I../../lib -I ../../lib/inih/ -I../../src

OBJS    = $(patsubst %.c,%.o,$(wildcard *.c))
EXECS   = $(basename $(OBJS))
LIB_OBJ = ../../build/$(LIB_NAME)

.PHONY: all link clean run

all: $(OBJS) link

run: link
	$(ECHO) -e "\nLOADING SPEC TESTS\n"
	tput setaf 2; $(ECHO) "Can load form .ini file correctly."; tput setaf 1; 
	./load_ini
	tput setaf 2; $(ECHO) "Throw a syntax error loading from a corrupt .ini file."; tput setaf 1
	./error_ini
	tput setaf 2; $(ECHO) "Throw an error if the bitmap section is missing."; tput setaf 1
	./missing_bitmap
	tput setaf 2; $(ECHO) "Throw an error if the mti section is missing."; tput setaf 1
	./missing_mti
	tput setaf 2; $(ECHO) "Throw an error if a unrecognized section is fetched."; tput setaf 1
	./section_error
	tput sgr0; $(ECHO) "Done."


link: $(OBJS)
	for obj in $(EXECS); do \
		$(LD) -o $$obj $$obj.o $(LIB_OBJ) $(CFLAGS); \
	done

$(OBJS):

# Tells make how I want to compile the object files
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDE)

clean:
	-rm -f *.o $(EXECS)
