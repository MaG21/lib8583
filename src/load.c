#include "load.h"

/*
 * FIXME: avoid magic values
 *
 */
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
 * FIXME: avoid magic values
 *
 */
static int
message_size(const char *value)
{
	switch(hash_f(value)) {
	case I_64BIT:
		return ISO_64BIT_BITMAP;
	case I_128BIT:
		return ISO_128BIT_BITMAP;
	}

	return -1;
}

/*
 * FIXME: avoid magic values
 * 0 -> error
 *
 */
static int
bitmap_section(void *user, const char *key, const char *value)
{
	int                   ret;
	struct i8583_bitmap  *bitmap = user;

	switch(hash_f(key)) {
	case I_TYPE:
		ret = message_type(value);
		if(ret<0)
			return 0;

		bitmap->bitmap_representation = ret;
		break;

	case I_SIZE:
		ret = message_size(value);
		if(ret<0)
			return 0;

		bitmap->bitmap_size = ret;
		break;

	default:
		return 0;
	}
	return 1;
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
def_section(void *user, const char *key, const char *value)
{
	int               ret;
	struct i8583_def *def      = user;

	switch(hash_f(key)) {
	case I_FORMAT:
		ret = def_format(value);
		if(ret<0)
			return 0;

		def->format = ret;
		break;

	case I_CODEC:
		ret = def_codec(value);
		if(ret<0)
			return 0;

		def->codec = ret;
		break;

	default:
		/* unrecognized key */
		return 0;
	}

	return 1;
}

#define MTI_IDX 0

/*
 * FIXME: avoid magic values
 *
 */
static int
handler(void *user, const char *section, const char *key, const char *value)
{
	int                   ret;
	int                   isvalid;
	int                   bit_number;
	unsigned int          hash;
	struct i8583_message  *msg = user;

	bit_number = parse_int10(section, &isvalid);

	hash = isvalid ? I_BIT : hash_f(section);

	switch(hash) {
	case I_MTI:
		/* FIXME: allow multiple MTIs */
		ret = def_section(&msg->def[MTI_IDX], key, value);
		if(!ret)
			return 0;
		break;

	case I_BITMAP:
		ret = bitmap_section(&msg->bitmap, key, value);
		if(!ret)
			return 0;
		break;

	case I_BIT:
		if(bit_number <= 0 || bit_number > ISO_128BIT_BITMAP)
			return 0; /* bitmap size <-> bit number mismatch */

		ret = def_section(&msg->def[bit_number], key, value);
		if(!ret)
			return 0;
		break;

	default:
		return 0;  /* unknown secction */
	}

	return 1;
}


int
i8583_load_definition_file(const char *filename, struct i8583_message *msg)
{
	int ret;

	ret = ini_parse(filename, handler, msg);
	if(ret > 0) {
		fprintf(stderr, "[INI]: Syntax error at: %d\n", ret);
		exit(EXIT_FAILURE);
	} else if(ret < 0) {
		perror(filename);
		exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

