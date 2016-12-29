#ifndef _8583_UTILS_H_
#define _8583_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>

#include "8583/types.h"

int        parse_int(const char *, int, int *);
inline int parse_int10(const char *, int *);
inline int parse_int16(const char *, int *);

char *8586_dump();


#endif
