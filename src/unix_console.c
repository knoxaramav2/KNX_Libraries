#include <stdio.h>

#if !defined _WIN32 && !defined OS_WINDOWS

#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <poll.h>

#include "KNX_Console.h"

struct termios old_termios, new_termios;
struct pollfd poll_fd = { 
    .fd = STDIN_FILENO, 
    .events = 
        POLLIN      | 
        POLLRDBAND  | 
        POLLRDNORM  | 
        POLLPRI };

int startConsoleControl(){

    tcgetattr( STDIN_FILENO, &old_termios );
    new_termios = old_termios;
    new_termios.c_lflag &= ~( ICANON | ECHO );
    new_termios.c_cflag |= (CLOCAL | CREAD);
    new_termios.c_cflag &= ~CSTOPB;

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

void getConsoleDimensions(int * width, int * height){
    struct winsize sz;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz);
    *width = sz.ws_col;
    *height = sz.ws_row;
}



#endif