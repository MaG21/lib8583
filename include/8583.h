#ifndef _8583_TYPES_H_
#define _8583_TYPES_H_

#include <stdint.h>
#include "constants.h"

struct 8583_message {
};

struct 8583_def {
	uint8_t bit;

	char    *desc;

	int     type;

	int (*func)(const void *data);
};

#endif

