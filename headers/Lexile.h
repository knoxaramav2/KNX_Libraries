#ifndef KNX_LEXILE
#define KNX_LEXILE

/*
Provides common algorithms and structures for performing
lexical analysis
*/

typedef ilToken
{
  char*str;
  int type;
} lToken;

/*
null terminated token stream
raw input, regex table, data table, table size, common mode options
Input string is analyzed. For each segment found via its associated
regex, a token is generated with a copy of the target substring, as
well as its code as defined by the symbol table.

Common mode options allow for ignored characters, such as whitespace
*/
lToken ** tokenize(char*,char**, int*, int, unsigned);

//Common mode values. May be OR'd
typedef enum {SPACE_DEL=1,TAB_DEL, WHITE_DEL, SNGL_QUOTE, DBL_QUOTE};

#endif
