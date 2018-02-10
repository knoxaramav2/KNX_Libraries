#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "KNX_String.h"
#include "KNX_Console.h"
#define PI 3.14159265

int main(){

    char s1 [] = {"125"};
    char s2 [] = {"12.5"};
    char s3 [] = {"1.2.5"};
    char s4 [] = {"12.a"};
    char s5 [] = {"hello"};

    printf("%d\r\n", isNumber(s1));
    printf("%d\r\n", isNumber(s2));
    printf("%d\r\n", isNumber(s3));
    printf("%d\r\n", isNumber(s4));
    printf("%d\r\n", isNumber(s5));

    return 0;
}