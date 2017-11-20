#ifndef KNX_HASH
#define KNX_HASH

//FNV Hash
//32 bit FNV
unsigned long fnv_32(char * raw);
//64 bit FNV
unsigned long long fnv_64(char * raw);

//FNV 1A Hash
//32 bit FNV 1A
unsigned long fnv1a_32(char * raw);
//64 bit FNV 1A
unsigned long long fnv1a_64(char * raw);

#endif