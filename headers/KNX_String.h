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
//same as toLower, but with const char input
char * toLowerc(const char*input);
//^^^
char * toUpperc(const char*input);
//0=non numeric, 1=integer 2=decimal
int isNumeric(const char*input);

//split input string into multiple strings via delimeter
char**split(char*input, char*delimeter);
#ifdef __cplusplus
}
#endif
#endif
