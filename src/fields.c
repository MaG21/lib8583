#include <stdbool.h>
#include "utils.h"
#include "8583.h"

static inline uint16_t
bcd_byte_to_number(uint8_t byte)
{
	return ((byte & 0xF0) >> 4) * 10 + (byte & 0x0F);
}

static inline uint8_t
number_byte_to_bcd(uint8_t n)
{
	return ((n/10) << 4) | (n%10);
}

/*
 * max size in bcd for LLVAR is   99
 * max size in bcd for LLLVAR is  999
 * max size in bcd for LLLLVAR is 9999
 */
static uint16_t
unpack_bcd_size(int format, uint8_t *bytes)
{
	uint8_t  ret;
	uint16_t n;

	switch(format) {
	case ISO_LLVAR:
		n = bcd_byte_to_number(*bytes);
		if(n > 99)
			goto error;

		break;
	case ISO_LLLVAR:
	case ISO_LLLLVAR:
		ret = bcd_byte_to_number(*bytes);
		if(ret> 99)
			goto error;

		n = ret * 100;
		bytes++;

		ret = bcd_byte_to_number(*bytes);
		if(ret> 99)
			goto error;

		n += ret;

		if(format==ISO_LLLVAR && n > 999)
			goto error;

		break;
	default:
		goto error;
	}

	return n;

error:
	return UINT16_MAX;
}



static void
unpack_bcd(int type, char *buf, size_t n)
{
	int i;

	for(i=0; i<n; i++) {
		d



