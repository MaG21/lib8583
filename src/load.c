#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "8583.h"
#include "crc32.h"

#include <inih.h>

/*
 * FIXME: avoid magic values
 *
 */
static int
message_type(const char *value)
{
	switch(crc32(value)) {
	case I_HEX:
	case I_HEXADECIMAL:
		return ISO_HEX_BITMAP;
	case I_BIN:
	case I_BINARY:
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
	switch(crc32(value)) {
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
 * somehow I'm repeating myself. That's not good.
 */
static int
bitmap_section(void *user, const char *key, const char *value)
{
	int                   ret;
	struct i8583_anatomy *anatomy = user;

	switch(crc32(key)) {
	case I_TYPE:
		ret = message_type(value);
		if(ret<0)
			return 0;

		anatomy->bitmap_representation = ret;
		break;

	case I_SIZE:
		ret = message_size(value);
		if(ret<0)
			return 0;

		anatomy->bitmap_size = ret;
		break;

	default:
		return 0;
	}
	return 1;
}

static struct i8583_def*
mti_object(struct i8583_anatomy *anatomy)
{
	struct i8583_def *ptr;

	if(anatomy->mti) 
		return anatomy->mti;

	ptr = malloc(sizeof(*ptr));
	if(!ptr)
		exit(EXIT_FAILURE);

	ptr->bit = 0;

	anatomy->mti = ptr;
	return ptr;
}

static int
def_format(const char *value)
{
	switch(crc32(value)) {
	case I_FIXED:
		return ISO_FIXED;
	case I_LLVAR:
		return ISO_LLVAR;
	case I_LLLVAR:
		return = ISO_LLLVAR;
	case I_LLLLVAR:
		return ISO_LLLLVAR;
	}

	return -1;
}

static int
def_codec(const char *value)
{
	switch(crc32(value)) {
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
	int               isvalid;
	struct i8583_def *def      = user;

	switch(crc32(key)) {
	case I_NAME:
		if(!value)
			return 0;
		def->desc = strdup(value);
		break;

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

	case I_NUMBER:
		ret = parse_int10(value, &isvalid);
		if(!isvalid)
			return 0;
		def->number = ret;
		break;

	case I_LENGTH:
		ret = parse_int10(value, &isvalid);
		if(!isvalid)
			return 0;

		def->length = ret;
		break;

	case I_MINIMUM:
		ret = parse_int10(value, &isvalid);
		if(!isvalid)
			return 0;
		def->minimum = ret;
		break;

	case I_MAXIMUM:
		ret = parse_int10(value, &isvalid);
		if(!isvalid)
			return 0;

		def->maximum = ret;
		break;

	default:
		/* unrecognized key */
		return 0;
	}

	return 1;
}

/*
 * FIXME: avoid magic values
 *
 */
static int
handler(void *user, const char *section, const char *key, const char *value)
{
	int                   ret;
	uint32_t              section_crc = crc32(section);
	struct i8583_def     *mti;
	struct i8583_anatomy *anatomy     = user;

	if(strncmp(section, "bit-", 4)) {
	}

	switch(section) {
	case I_BITMAP:
		ret = bitmap_section(anatomy, key, value);
		if(!ret)
			return 0;

	case I_MTI:
		mti = mti_object(anatomy);
		ret = def_section(mti, key, value);

	default:
		return 0;  /* unknown secction */
	}

	bit = parse_int10(&section[4]);

	if(


struct i8583_anatomy*
i8583_load_definition_file(const char *filename, int bitmap_size)
{
	struct i8583_anatomy *anatomy;

	anatomy = malloc(sizeof(*anatomy));
	if(!anatomy) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	anatomy->defs = malloc(sizeof(*anatomy->defs));
	if(!anatomy->defs) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	ini_parse(
