#
# NOTE: PLEASE, AVOID EDITING THIS FILE.
#

include ../../Makefile.inc

VPATH   = ../../build/
INCLUDE = -I. -I../../include -I../../lib -I ../../lib/inih/ -I../../src

OBJS    = $(patsubst %.c,%.o,$(wildcard *.c))
EXECS   = $(basename $(OBJS))
LIB_OBJ = ../../build/$(LIB_NAME)

.PHONY: all link clean run

all: $(OBJS) link

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
