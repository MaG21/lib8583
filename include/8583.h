#ifndef _8583_TYPES_H_
#define _8583_TYPES_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

#include "constants.h"

struct i8583_def {
	uint16_t format;
	uint16_t codec;
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

struct i8583_message {
	uint8_t mti;

	struct i8583_bitmap bitmap;

	struct i8583_def    def[ISO_BITS_PER_BITMAP];
};

enum {
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

#ifdef __cplusplus
}
#endif

#endif

