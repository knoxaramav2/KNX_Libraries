#ifndef KNX_STRING
#define KNX_STRING

#ifdef __cplusplus
extern "C"{
#endif
#include <string.h>

//return index of substring
size_t getSubIndex(char*input,char*substring);
//convert characters to lowercase
const char* toLower(char*input);
//convert characters to uppercase
const char* toUpper(char*input);

//split input string into multiple strings via delimeter
char**split(char*input, char*delimeter);
#ifdef __cplusplus
}
#endif
#endif
