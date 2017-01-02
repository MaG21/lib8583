#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "8583.h"

#define FILENAME "section_error.ini"

int
main(void)
{
	int   ret;
	FILE *file;
	struct i8583_message_def msg;

	file = fopen(FILENAME, "r");
	if(!file) {
		perror(FILENAME);
		exit(EXIT_FAILURE);
	}

	ret = i8583_load_definition_file((ini_reader)fgets, file, &msg);

	assert(ret>0);
	assert(ret==15);
	fclose(file);

	return EXIT_SUCCESS;
}

