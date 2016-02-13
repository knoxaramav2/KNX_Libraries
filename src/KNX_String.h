#ifndef KNX_STRING
#define KNX_STRING

#include <string.h>

//return index of substring
size_t getSubIndex(char*input,char*substring);
//convert characters to lowercase
void toLower(char*input);
//convert characters to uppercase
void toUpper(char*input);

//split input string into multiple strings via delimeter
char**split(char*input, char*delimeter);

#endif
