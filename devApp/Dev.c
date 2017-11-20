#include <stdio.h>

#include "KNX_String.h"

int main(){

    char msg [] = "Hello World!";
    printf("%s\r\n", toLowercase(msg));
    printf("%s\r\n", toUppercase(msg));


    return 0;
}