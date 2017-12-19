#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "KNX_String.h"
#include "KNX_Console.h"
#define PI 3.14159265

int main(){

    startConsoleControl();

    terminal * term = createTerminal();

    setEcho(1);

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    printf ("lines %d\n", w.ws_row);
    printf ("columns %d\n", w.ws_col);

    printf("\033[H\033[J");

    for(int i=0; i < 360; ++i){
        putAt(term ,(unsigned)'X',  i/3, abs(8.0f*sin(i*(PI/180))));
    }

    destroyTerminal(term);
    endConsoleControl();

    return 0;
}