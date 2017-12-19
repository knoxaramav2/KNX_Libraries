#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "KNX_String.h"
#include "KNX_Console.h"
#define PI 3.14159265

int main(){

    startConsoleControl();

    terminal * term = createTerminal();

    setEcho(1);

    printf("\033[H\033[J");

    for(int i=0; i < 30; ++i){
        putAt(&term->component ,(unsigned)'A' + i,  i, i);
        fflush(stdout);
    }

    renderTerminal(term);

    printf("-------------%d %d------\r\n", 
        term->component.width,
        term->component.height);

    destroyTerminal(term);
    endConsoleControl();

    return 0;
}