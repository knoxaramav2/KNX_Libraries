#include <stdio.h>

#if defined _WIN32 && defined OS_WINDOWS

#include <windows.h>

#include "KNX_Console.h"

HANDLE hConsoleIn;
HANDLE hConsoleOut;
DWORD  cMode_old;
DWORD  cMode_new;

int startConsoleControl(){

    hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
    hConsoleIn = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode(hConsoleIn, &cMode_old);
    cMode_new = cMode_old;

    return 1;
}

void endConsoleControl(){
    SetConsoleMode(hConsole, cMode_old);
}

void setEcho(char c){
    if (c){
        SetConsoleMode(hConsole, cMode_new & ENABLE_ECHO_INPUT);
    } else {
        SetConsoleMode(hConsole, cMode_new & (~ENABLE_ECHO_INPUT));
    }
}

void getConsoleDimensions(int * width, int * height){
    
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int col, row;

    GetConsoleScreenBufferInfo(hConsoleIn, &csbi);
    *width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    return 0;
}



#endif