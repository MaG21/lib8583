include ../Makefile.mk

run: link
	$(ECHO) -e "\nLOADING SPEC TESTS\n"
	tput setaf 2; $(ECHO) "(load_ini.c)Can load form .ini file correctly."; tput setaf 1; 
	./load_ini
	tput setaf 2; $(ECHO) "(error_ini.c)Throw a syntax error loading from a corrupt .ini file."; tput setaf 1
	./error_ini
	tput setaf 2; $(ECHO) "(missing_bitmap.c)Throw an error if the bitmap section is missing."; tput setaf 1
	./missing_bitmap
	tput setaf 2; $(ECHO) "(missing_mti.c)Throw an error if the mti section is missing."; tput setaf 1
	./missing_mti
	tput setaf 2; $(ECHO) "(section_error.c)Throw an error if an unrecognized section is fetched."; tput setaf 1
	./section_error
	tput setaf 2; $(ECHO) "(missing_option.c)Throw an error if an option is missing somewhere."; tput setaf 1
	./missing_option
	tput sgr0; $(ECHO) "Done."
