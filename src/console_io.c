#include <string.h>
#include <stdio.h>

#include "KNX_Console.h"

void flatten(consComponent * dest, consComponent * src){

    unsigned dxOffset = 0;
    unsigned dyOffset = 0;
    unsigned sxOffset = 0;
    unsigned syOffset = 0;
    unsigned xLimit, yLimit;

    if (src->xOffset < 0){
        sxOffset = src->xOffset * -1;
    } else {
        dxOffset = src->xOffset * -1;
    }

    if (src->yOffset < 0){
        syOffset = src->yOffset * -1;
    } else {
        dyOffset = src->yOffset * -1;
    }

    unsigned sLimit = src->width - sxOffset;
    unsigned dLimit = dest->width - dxOffset;
    xLimit = sLimit < dLimit ? sLimit : dLimit;

    sLimit = src->height - syOffset;
    dLimit = dest->height - dyOffset;
    yLimit = sLimit < dLimit ? sLimit : dLimit;

    for (unsigned x=0; x < xLimit; ++x){
        for (unsigned y=0; y < yLimit; ++y){
            dest->buffer[x+dxOffset][y+dyOffset] = src->buffer[sxOffset][syOffset];
        }
    }
}

unsigned getKeyPress(){

    unsigned c = getchar();

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


int putAt(consComponent * screen, unsigned val, unsigned x, unsigned y){

    if (screen == 0){
        printf("\033[%d;%dH%c", y, x, CELL_VALUE(val));
        return 0;
    }
    
    if(x >= screen->width) return 1;
    if(y >= screen->height) return 2;

    screen->buffer[x][y] = val;

    return 0;
}