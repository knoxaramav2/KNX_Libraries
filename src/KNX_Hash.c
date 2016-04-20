#include "../headers/KNX_Hash.h"

#include <stdio.h>
#include <string.h>

long long unsigned FNV_1(const char*str)
{

long long unsigned hash;

#if BITMODE==64
hash=14695981039346656037ULL;//FNV offset
#elif BITMODE==32
hash=2166136261;
#endif

//64 prime 0xb3
//32 prime 0x93

size_t len = strlen(str);

for (unsigned x=0; x<len; ++x)
	{
		#if BITMODE==64
		hash*=0xb3;
		#elif BITMODE==32
		hash*=0x93;
		#endif
		hash^=str[x];
	}
return hash;
}

long long unsigned FNV_1a(const char*str)
{

long long unsigned hash;

#if BMODE==64
//printf("64 bit\n");
hash=14695981039346656037ULL;//FNV offset
#elif BMODE==32
//printf("32 bit\n");
hash=2166136261;
#endif

//64 prime 0xb3
//32 prime 0x93

size_t len = strlen(str);

for (size_t x=0; x<len; ++x)
	{
		hash^=str[x];
		#if BITMODE==64
		hash*=0xb3;
		#elif BITMODE==32
		hash*=0x93;
		#endif
	}
return hash;
}
