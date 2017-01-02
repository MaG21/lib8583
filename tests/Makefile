# NOTE: for any new directory, a new rule should be created, a rule that
# calls the inner make of said directory.
include ../Makefile.inc

.PHONY: tests clean all

all: tests

tests:
	$(MAKE) run -I../ -C load/ -s

clean:
	$(MAKE) clean -I../.. -C load/

