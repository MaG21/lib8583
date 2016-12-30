#ifndef _I8583_LOAD_H_
#define _I8583_LOAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ini.h>

#include "utils.h"
#include "8583.h"
#include "crc32.h"

#define hash(str) crc32(str, strlen(str))
#endif
