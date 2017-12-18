#include <stdio.h>

#include "KNX_String.h"
#include "KNX_Console.h"

int main(){

    char val = 0;

    startConsoleControl();
    printf("%c\r\n", getchar());

    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
    printf("WIN\r\n");
    #elif defined (__CYGWIN__)
    printf("CYG\r\n");
    #else
    printf("LIN\r\n");
    #endif

    while(val != ' '){
        val = getKeyPress();
        printf("%d\r\n", val);
    }

    endConsoleControl();

    return 0;
}