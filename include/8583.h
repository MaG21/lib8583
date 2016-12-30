#ifndef _8583_TYPES_H_
#define _8583_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "constants.h"

enum {
	ISO_64BIT_BITMAP=63,
	ISO_128BIT_BITMAP=127,

	ISO_HEX_BITMAP,
	ISO_BIN_BITMAP,

	/* types */
	ISO_N,
	ISO_NS,
	ISO_A,
	ISO_AN,
	ISO_B,
	ISO_Z,

	/* formats */
	ISO_FIXED,
	ISO_LLVAR,
	ISO_LLLVAR,
	ISO_LLLLVAR,

	/* codecs */
	ISO_BCD_CODEC,
	ISO_ASCII_CODEC
};


struct i8583_message {
};

struct i8583_def {
	char     *desc;

	int      format;
	int      codec;

	unsigned int number;

	/* validation */

	unsigned int length;
	unsigned int minimum;
	unsigned int maximum;
};

struct i8583_anatomy {
	int      bitmap_size;
	int      bitmap_representation;

	struct i8583_def *mti;
	struct i8583_def *defs;
};

#ifdef __cplusplus
}
#endif

#endif

