#ifndef KNX_CONSOLE
#define KNX_CONSOLE

#include "kw_code.h"



///route all control through library commands
int startConsoleControl();
///reset terminal control to normal
void endConsoleControl();

/** Returns a keycode for a key stroke, in ascii or 
 *  as a macro for special keys, such as arrows
 */
unsigned getKeyPress();

//informational

#endif