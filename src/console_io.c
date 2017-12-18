#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

#include "KNX_Console.h"

struct termios old_termios, new_termios;

int startConsoleControl(){

    tcgetattr( STDIN_FILENO, &old_termios );
    new_termios = old_termios;
    new_termios.c_lflag &= ~( ICANON | ECHO );

    tcsetattr( STDIN_FILENO, TCSANOW, &new_termios );

    return 1;
}

void endConsoleControl(){
    tcsetattr( STDIN_FILENO, TCSANOW, &old_termios );
}

unsigned getKeyPress(){
    return (unsigned) getchar();
}