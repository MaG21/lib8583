#include "utils.h"

int
parse_int10(const char *restrict s, int *isvalid)
{
	int value = 0;
	int sign  = 1;

	if( *s=='+' || *s=='-' ) {
		if( *s == '-' )
			sign = -1;
		s++;
	}

	for(; *s; s++) {
		if(!ISDIGIT(*s)) {
			*isvalid = false;
			return 0;
		}

		value *= 10;
		value += (int) (*s-'0');
	}

	*isvalid = true;

	return (value * sign);
}

