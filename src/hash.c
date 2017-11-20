#include <string.h>

#include "hash.h"

#define FNV_OFFSET_64 0xcbf29ce484222325ULL//14695981039346656037ULL
#define FNV_OFFSET_32 0x811c9dc5//2166136261
#define FNV_PRIME_64 1099511628211ULL//0xb3
#define FNV_PRIME_32 16777619//0x93

unsigned long long _FNV_(char * raw, char is32bit, char use1a){
    size_t len = strlen(raw);

    unsigned long long offset = is32bit ? FNV_OFFSET_32 : FNV_OFFSET_64;
    unsigned long long prime = is32bit ? FNV_PRIME_32 : FNV_PRIME_64;
    unsigned long long hash = offset;

    for (size_t i=0; i < len; ++i){
        if (use1a){
            hash ^= raw[i];
            hash *= prime;
        } else {
            hash *= prime;
            hash ^= raw[i];
        }

        //force wrap
        if (is32bit){
            hash = (unsigned long) hash;
        }
    }

    return hash;
}

unsigned long fnv_32(char * raw){
    return (unsigned long) _FNV_(raw, 1, 0);
}

unsigned long long fnv_64(char * raw){
    return _FNV_(raw, 0, 0);
}

unsigned long fnv1a_32(char * raw){
    return (unsigned long) _FNV_(raw, 1, 1);
}

unsigned long long fnv1a_64(char * raw){
    return _FNV_(raw, 0, 1);
}