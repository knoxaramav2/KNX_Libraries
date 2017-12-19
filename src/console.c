#include <stdio.h>
#include <stdlib.h>

#include "KNX_Console.h"

terminal * createTerminal(){
    terminal * term = malloc(sizeof(terminal));

    //Get current terminal dimensions
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &term->size);

    term->component.buffer = malloc(sizeof(unsigned *) * term->size.ws_col);
    term->component.width = term->size.ws_col;
    term->component.width = term->size.ws_row;

    for (size_t i = 0; i < term->size.ws_col; ++i){
        term->component.buffer[i] = malloc(term->size.ws_col);

        for (size_t j = 0; j < term->size.ws_row; ++j){
            term->component.buffer[i][j] = ' ' | 0x00;
        }

    }

    return term;
}

void destroyTerminal(terminal * term){

    for (size_t i = 0; i < term->size.ws_col; ++i){
        free (term->component.buffer[i]);
    }

    free (term->component.buffer);
    free(term);
}

void renderTerminal(terminal * term){

}

void updateTerminal(terminal * term){

}