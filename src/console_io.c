#include <string.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <poll.h>
#include <windows.h>

#include "KNX_Console.h"

struct termios old_termios, new_termios;
struct pollfd poll_fd = { .fd = STDIN_FILENO, .events = 
    POLLIN      | 
    POLLRDBAND  | 
    POLLRDNORM  | 
    POLLPRI };

int startConsoleControl(){

    tcgetattr( STDIN_FILENO, &old_termios );
    new_termios = old_termios;
    new_termios.c_lflag &= ~( ICANON | ECHO );

    //for handling escape sequences

    tcsetattr( STDIN_FILENO, TCSANOW, &new_termios );

    return 1;
}

void endConsoleControl(){
    tcsetattr( STDIN_FILENO, TCSANOW, &old_termios );
}

void setEcho(char c){
    if (c){
        new_termios.c_lflag |= ECHO;
    } else {
        new_termios.c_lflag &= ~ECHO;
    }

    tcsetattr( STDIN_FILENO, TCSANOW, &new_termios );
}

unsigned getKeyPress(){

    unsigned c = getchar();
    printf("%c||%x\r\n", (char)c, c);

    ///TODO Support Esc key, other sequences
    if (c == 27){
        //Get Arrow Keys
        if (getchar() == 91){
            switch(getchar()){
                case 65: c = KEY_ARROW_UP; break;
                case 66: c = KEY_ARROW_DOWN; break;
                case 67: c = KEY_ARROW_RIGHT; break;
                case 68: c = KEY_ARROW_LEFT; break;
            }
        }
    }

    return c;
}


void putAt(terminal * term, unsigned val, unsigned x, unsigned y){
    printf("\033[%d;%dH%c", (y), (x), CELL_VALUE(val));
    //printf("%c", CELL_VALUE(val));
}