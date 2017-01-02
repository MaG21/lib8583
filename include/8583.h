#ifndef _8583_TYPES_H_
#define _8583_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include <ini.h>

#include "constants.h"

struct i8583_def {
	uint8_t type;
	uint8_t format;
	uint8_t codec;
};

#define ISO_BITS_PER_BITMAP 64
#define ISO_SIZE_PER_BITMAP 8

#define ISO_64BIT_BITMAP 64
#define ISO_128BIT_BITMAP 128

#define ISO_HEX_BITMAP 1
#define ISO_BIN_BITMAP 2

struct i8583_bitmap {
	uint8_t bitmap_size;
	uint8_t bitmap_representation;
};

struct i8583_message_def {
	uint16_t mti;

	struct i8583_bitmap bitmap;

	struct i8583_def    def[ISO_BITS_PER_BITMAP];
};

enum {
	/* types */
	ISO_N=1,    /* important =1 */
	ISO_NS,
	ISO_AN,
	ISO_ANS,
	ISO_ANP,
	ISO_A,
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

/*
 * This functions loads a 8583 message spec. +reader+ is the function tha will
 * be used to read from +stream+, the prototype of reader is the same as
 * fgets(3) from the standard library.
 *
 * return:
 * 	- 0 if it loaded the spec correctly.
 * 	- -1 if either the bitmap or mti section is missing.
 * 	- a positive number greater than 0, indicating the line of a syntax
 *        error or line where an unrecognized key and/or value was given.
 */
int i8583_load_definition_file(ini_reader, void *,struct i8583_message_def *);


#ifdef __cplusplus
}
#endif

#endif

