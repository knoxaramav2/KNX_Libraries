#include <stdio.h>

#include "KNX_String.h"

int main(){

    char msg [] = "a";
    printf("%s\r\n", toLowercase(msg));
    printf("%s\r\n", toUppercase(msg));
    printf("%lx\r\n", fnv1a_32(msg));
    printf("%llx\r\n", fnv1a_64(msg));
    printf("%lx\r\n", fnv_32(msg));
    printf("%llx\r\n", fnv_64(msg));

    return 0;
}