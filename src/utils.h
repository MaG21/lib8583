#ifndef _8583_UTILS_H_
#define _8583_UTILS_H_

#include <stdbool.h>

#include "8583.h"

#define ISDIGIT(c) ((c>='0' && c<='9'))

int parse_int10(const char *, int *isvalid);

#endif
