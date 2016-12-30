#ifndef _8583_UTILS_H_
#define _8583_UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include <stdbool.h>

#include "8583.h"

int  parse_int(const char *, int, int *);
int  parse_int10(const char *, int *);
int  parse_int16(const char *, int *);

bool isstrnumber(const char *);

#endif
