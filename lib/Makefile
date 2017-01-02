include Makefile.inc

# In order:
#   - disable multi-line entries.
#   - stop on first error
INIH_CFLAGS = -DINI_ALLOW_MULTILINE=0 -DINI_STOP_ON_FIRST_ERROR=1
VPATH = ../build

all: hash inih

ini.o: inih/ini.c inih/ini.h
	$(CC) -c -o ../build/$@ $< $(CFLAGS) $(INIH_CFLAGS) -DINI_INLINE_COMMENT_PREFIXES='"#"'

hash.o: hash.c hash.h
	$(CC) -c -o ../build/$@ $< $(CFLAGS)

clean:
	-$(RM) *.o

