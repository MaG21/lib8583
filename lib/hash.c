#include "hash.h"

/*
 * djb2 hash algorithm.
 */
unsigned int
hash_f(const char *restrict s)
{
	int c;
	unsigned int hash = 5381;

	while((c = (unsigned char)*s++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}
