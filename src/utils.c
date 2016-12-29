#include "utils.h"
#include <stdbool.h>

int
parse_int(const char *s, int base, int *isvalid)
{
	long val;
	char *endptr;

	*isvalid = true;

	errno = 0;
	val = strtol(str, &endptr, base);

	if ((errno == ERANGE && (val == LONG_MAX || val == LONG_MIN))
			|| (errno != 0 && val == 0)) {
		isvalid = false;
		return 0;
	}

	if (endptr == str) {
		isvalid = false;
		return 0;
	}

	return (int)val;
}

inline int
parse_int10(const char *s, int *isvalid) {
	return parse_int(s, 10, isvalid);
}

inline int
parse_int16(const char *s, int *isvalid) {
	return parse_int(s, 16, isvalid);
}
