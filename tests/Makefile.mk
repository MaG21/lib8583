#
# NOTE: PLEASE, AVOID EDITING THIS FILE.
#

include ../../Makefile.inc

INCLUDE = -I. -I../../include -I../../lib -I ../../lib/inih/ -I../../src

OBJS    = $(patsubst %.c,%.o,$(wildcard *.c))
EXECS   = $(basename $(OBJS))
LIB_OBJ = ../../build/$(LIB_NAME)

.PHONY: all link clean run

all: $(OBJS) link

link: $(OBJS) $(EXECS)

$(EXECS):
	$(LD) -o $@ $@.o $(LIB_OBJ) $(CFLAGS)

# Tells make how I want to compile the object files
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDE)

clean:
	-rm -f *.o $(EXECS)
