#ifndef KNX_CONSOLE
#define KNX_CONSOLE

#include <sys/ioctl.h>
#include <unistd.h>

#include "kw_code.h"

#define CELL_VALUE(c) ((unsigned char) c)
#define CELL_ATTRIBUTE(c) ((unsigned)(c >> 8))

typedef struct consComponent{
    unsigned ** buffer;
    unsigned width, height;
    unsigned id;

    int xOffset, yOffet;

    struct consComponent ** children;
} consComponent;

typedef struct terminal{
    consComponent component;
    struct winsize size;
} terminal;

terminal * createTerminal();
void destroyTerminal(terminal *);
void renderTerminal(terminal *);
void updateTerminal(terminal *);

///route all control through library commands
int startConsoleControl();
///reset terminal control to normal
void endConsoleControl();

///option switches
void setEcho(char);

///interraction
void clearScreen(terminal *);
void putAt(terminal *, unsigned, unsigned, unsigned);

/** Returns a keycode for a key stroke, in ascii or 
 *  as a macro for special keys, such as arrows
 */
unsigned getKeyPress();

//informational

#endif