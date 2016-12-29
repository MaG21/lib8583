#ifndef _8583_TYPES_H_
#define _8583_TYPES_H_

#include <stdint.h>

#include "constants.h"

enum {
	ISO_64BIT_BITMAP=64,
	ISO_128BIT_BITMAP=128,

	ISO_HEX_BITMAP,
	ISO_BIN_BITMAP,

	/* types */
	ISO_N,
	ISO_NS,
	ISO_A,
	ISO_AN,
	ISO_AN,
	ISO_AN,
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
	uint8_t  bit;

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
}

#endif

