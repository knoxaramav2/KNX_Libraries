#include <stdio.h>
#include <stdlib.h>

#include "KNX_Console.h"

terminal * createTerminal(){
    terminal * term = malloc(sizeof(terminal));

    //Get current terminal dimensions
    getConsoleDimensions(&term->component.width, &term->component.height);

    term->component.buffer = malloc(sizeof(unsigned *) * term->component.width);

    for (size_t i = 0; i < term->component.width; ++i){
        term->component.buffer[i] = malloc(term->component.width);
        for (size_t j = 0; j < term->component.height; ++j){
            term->component.buffer[i][j] = ' ' | 0x00;
        }
    }

    return term;
}

void destroyTerminal(terminal * term){

    for (size_t i = 0; i < term->component.width; ++i){
        free (term->component.buffer[i]);
    }

    free (term->component.buffer);
    free(term);
}

void renderTerminal(terminal * term){

    consComponent * cmp = &term->component;

    for (unsigned x = 0; x< cmp->width; ++x){
        for (unsigned y=0; y<cmp->height; ++y){
            printf("\033[%d;%dH%c", y, x, CELL_VALUE(cmp->buffer[x][y]));
        }
    }
}

void updateTerminal(terminal * term){

}