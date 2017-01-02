# NOTE: for any new directory, a new rule should be created, a rule that
# calls the inner make of said directory.
include ../Makefile.inc

.PHONY: run tests load clean all

all: load

load:
	$(MAKE) -I../.. -C load/

tests:
	$(MAKE) run -I../ -C load/ -s

clean:
	$(MAKE) clean -I../.. -C load/

