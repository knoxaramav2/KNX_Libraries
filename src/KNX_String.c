#include "../headers/KNX_String.h"

#include <stdlib.h>
#include <stdio.h>

size_t getSubIndex(char*input, char*substring)
{
  size_t sz_i=strlen(input);
  size_t sb_i=strlen(substring);

  if (sb_i>sz_i)
    return (unsigned)-1;//similar to npos, wraps to max integer for bitmode

  unsigned szDif=sz_i-(sz_i-sb_i);
  for (unsigned x=0; x<szDif; ++x)
  {
    if (input[x]==substring[x])//check for matching first character
      for (unsigned y=x; y<sb_i; ++y)
      {
        if (input[y]!=substring[y])
          goto brk;
        if (y+1==sb_i)
          return x;
      }
    brk:;
  }
  return (unsigned)-1;
}

const char* toLower(char*input)
{
  size_t len = strlen(input);

  for (size_t x=0; x<len; ++x)
    if (input[x]>='A' && input[x]<='Z')//if uppercase ascii character
      {
        printf("%c>>", input[x]);
        input[x]+=32;
        printf("%c\n", input[x]);
      }
return input;
}

const char* toUpper(char*input)
{
  size_t len = strlen(input);

  for (size_t x=0; x<len; ++x)
    if (input[x]>='a' && input[x]<='z')//if uppercase ascii character
      input[x]-=32;

  return input;
}

char * toLowerc(const char * input)
{
  size_t len = strlen(input);

  char * ret = malloc(len+1);
  strncpy(ret, input, len+1);

  for (size_t x=0; x<len; ++x)
    if (ret[x]>='A' && ret[x]<='Z')//if uppercase ascii character
      {
        //printf("%c>>", ret[x]);
        ret[x]+=32;
        //printf("%c\n", ret[x]);
      }
return ret;
}

char * toUpperc(const char * input)
{
  size_t len = strlen(input);

  char * ret = malloc(len+1);
  strncpy(ret, input, len+1);

  for (size_t x=0; x<len; ++x)
    if (ret[x]>='a' && ret[x]<='z')//if uppercase ascii character
      ret[x]-=32;

  return ret;
}

int isNumeric(const char * input)
{
  char deciFound=0;//decimal value found

  size_t size=strlen(input);

  //printf(">> %s\n", input);

  for (unsigned x=0; x<size; ++x)
  {
    if (input[x]=='.')
    {
      ++deciFound;
      if (deciFound!=1)
        return 0;
    }
    else if (input[x]=='-')
      {
        if (x>0)
          return 0;
      }
    else if (input[x]<'0' || input[x]>'9')
      return 0;
  }

  return deciFound==0?1:2;
}
