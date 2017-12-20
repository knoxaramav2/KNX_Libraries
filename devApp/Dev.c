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
    return 0;
    //char c;

    //do{
    //    c = getKeyPress();
    //} while(c != '5');

    getConsoleDimensions(&term->component.width, &term->component.height);

    printf("%d %d\r\n", term->component.width, term->component.height);

    destroyTerminal(term);
    endConsoleControl();

    return 0;
}