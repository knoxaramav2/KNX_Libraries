#include "../headers/KNX_Hash.h"

#include <stdio.h>
#include <string.h>

#define FNV_OFFSET_64 14695981039346656037ULL
#define FNV_OFFSET_32 2166136261
#define FNV_PRIME_64 0xb3
#define FNV_PRIME_32 0x93

long long unsigned _FNV_1(const char*str, unsigned long long offset, unsigned prime)
{
long long unsigned hash = offset;

size_t len = strlen(str);

for (unsigned x=0; x<len; ++x)
	{
		hash *= prime;
		hash ^= str[x];
	}

return hash;
}

long long unsigned _FNV_1a(const char*str, unsigned long long offset, unsigned prime)
{
long long unsigned hash = offset;

size_t len = strlen(str);
for (unsigned x=0; x<len; ++x)
	{
		hash ^= prime;
		hash *= str[x];
	}

return hash;
}

long long unsigned FNV_1(const char*str)
{
long long unsigned offset;
unsigned prime;

#if BITMODE==64
offset = FNV_OFFSET_64;//FNV offset
prime = FNV_PRIME_64;
#else
offset = FNV_OFFSET_32;
prime = FNV_PRIME_32;
#endif

return _FNV_1(str, offset, prime);
}

long long unsigned FNV_1a(const char*str)
{
long long unsigned offset;
unsigned prime;

#if BITMODE==64
offset = FNV_OFFSET_64;//FNV offset
prime = FNV_PRIME_64;
#else
offset = FNV_OFFSET_32;
prime = FNV_PRIME_32;
#endif


return _FNV_1a(str, offset, prime);
}

long long unsigned FNV_1_32(const char* str)
{
return _FNV_1(str, FNV_OFFSET_32, FNV_PRIME_32);
}

long long unsigned FNV_1a_32(const char* str)
{
return _FNV_1a(str, FNV_OFFSET_32, FNV_PRIME_32);
}