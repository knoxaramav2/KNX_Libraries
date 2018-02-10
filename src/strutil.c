#include <stdlib.h>
#include <string.h>

#include "strutil.h"

char * toLowercase(char * raw){

    size_t len = strlen(raw);
    char * ret = malloc(len+1);

    for (size_t i = 0; i <= len; ++i){
        ret[i] = raw[i] >= 65 && raw[i] <= 90 ?
            raw[i] + 32 : raw[i];
    }

    return ret;
}

char * toUppercase(char * raw){

    size_t len = strlen(raw);
    char * ret = malloc(len+1);

    for (size_t i = 0; i <= len; ++i){
        ret[i] = raw[i] >= 97 && raw[i] <= 122 ?
            raw[i] - 32 : raw[i];
    }

    return ret;
}


int isNumber(char * raw){

    char decimal = 0;

    while (*raw != 0){
        if (*raw == '.'){
            if (decimal == 1)
                return 0;
            decimal = 1;
        } else {
            if (*raw < '0' || *raw > '9')
                return 0;
        }

        ++raw;
    }

    return decimal == 0 ? 1 : 2;
}