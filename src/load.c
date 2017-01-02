#include "ini.h"
#include "utils.h"
#include "hash.h"
#include "8583.h"

static int
message_type(const char *value)
{
	switch(hash_f(value)) {
	case I_HEX:
		return ISO_HEX_BITMAP;
	case I_BIN:
		return ISO_BIN_BITMAP;
	}

	return -1;
}

/*
 * returns -1 on error.
 */
static int
bitmap_section(void *user, const char *key, const char *value)
{
	int_fast16_t          ret;
	struct i8583_bitmap  *bitmap = user;

	switch(hash_f(key)) {
	case I_TYPE:
		ret = message_type(value);
		if(ret<0)
			return -1;

		bitmap->bitmap_representation = ret;
		break;
	default:
		return -1;
	}

	return 0;
}

static int
def_format(const char *value)
{
	switch(hash_f(value)) {
	case I_FIXED:
		return ISO_FIXED;
	case I_LLVAR:
		return ISO_LLVAR;
	case I_LLLVAR:
		return ISO_LLLVAR;
	case I_LLLLVAR:
		return ISO_LLLLVAR;
	}

	return -1;
}

static int
def_codec(const char *value)
{
	switch(hash_f(value)) {
	case I_BCD:
		return ISO_BCD_CODEC;
	case I_ASCII:
		return ISO_ASCII_CODEC;
	}
	return -1;
}

static int
def_type(const char *value)
{
	switch(hash_f(value)) {
	case I_N:
		return ISO_N;
	case I_NS:
		return ISO_NS;
	case I_A:
		return ISO_A;
	case I_AN:
		return ISO_AN;
	case I_ANS:
		return ISO_ANS;
	case I_ANP:
		return ISO_ANP;
	case I_B:
		return ISO_B;
	case I_Z:
		return ISO_Z;
	}
	return -1;
}


/*
 * returns -1 on error.
 */
static int
def_section(void *user, const char *key, const char *value)
{
	int_fast16_t      ret;
	struct i8583_def *def      = user;

	switch(hash_f(key)) {
	case I_FORMAT:
		ret = def_format(value);
		if(ret<0)
			return -1;

		def->format = ret;
		break;

	case I_CODEC:
		ret = def_codec(value);
		if(ret<0)
			return -1;

		def->codec = ret;
		break;

	case I_TYPE:
		ret = def_type(value);
		if(ret<0)
			return -1;

		def->type = ret;
		break;

	default:
		return -1;
	}

	return 0;
}

#define MTI_IDX 0

/*
 * From inih doc:
 * 	handler should return nonzero on success.
 */
static int
handler(void *user, const char *restrict section, const char *restrict key,
        const char *restrict value)
{
	uint_fast8_t             bit_number;
	int                      ret;
	int                      isvalid;
	unsigned int             hash;
	struct i8583_message_def *msg = user;

	bit_number = (uint_fast8_t)parse_int10(section, &isvalid);

	hash = isvalid ? I_BIT : hash_f(section);

	switch(hash) {
	case I_MTI:
		ret = def_section(&msg->def[MTI_IDX], key, value);
		if(ret<0)
			return 0;
		break;

	case I_BITMAP:
		ret = bitmap_section(&msg->bitmap, key, value);
		if(ret<0)
			return 0;
		break;

	case I_BIT:
		if(bit_number <= 0 || bit_number > ISO_BITS_PER_BITMAP)
			return 0;

		ret = def_section(&msg->def[bit_number], key, value);
		if(ret<0)
			return 0;
		break;

	default:
		return 0;
	}

	return 1;
}

int
i8583_load_definition_file(ini_reader reader, void *stream, 
                           struct i8583_message_def *msg)
{
	int ret;

	msg->def[MTI_IDX].type = 0;
	msg->bitmap.bitmap_representation = 0;

	ret = ini_parse_stream(reader, stream, handler, msg);
	if(ret)
		return ret;

	if(!msg->def[MTI_IDX].type || !msg->bitmap.bitmap_representation)
		return -1;

	return 0;
}

