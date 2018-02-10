#ifndef KNX_STRUTIL
#define KNX_STRUTIL

//Case
//To Lowercase
char * toLowercase(char * raw);
//To Uppercase
char * toUppercase(char * raw);

/*
    Returns:
        0 if not a number
        1 if integer
        2 if floating
*/
int isNumber(char * raw);

#endif