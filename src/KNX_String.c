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

char**split(char*input, char*delimiter)
{
  char**table=malloc(0);
  char**dlm=malloc(0);

  //parse delimiters
  size_t len=strlen(delimiter);
  size_t lIndex=0;
  size_t nDlm=0;
  for (size_t x=0; x<=len; ++len)
  {
    if (x==len && lIndex!=x)
    {
      dlm=realloc(dlm, ++nDlm);
      dlm[nDlm-1]=malloc((len-lIndex)+1);
      strncpy(dlm[nDlm-1], delimiter+lIndex, (len-lIndex));
    }

    if (delimiter[x]=='\\')//ignore next character
      ++x;
    else if (delimiter[x]=='|')//break element
    {
      if (lIndex==x)
        continue;
      dlm=realloc(table,++nDlm);
      dlm[nDlm-1]=malloc((x-lIndex)+1);
      strncpy(dlm[nDlm-1], input+lIndex, (x-lIndex));
      dlm[nDlm-1][x-lIndex]='\0';
      lIndex=x+1;
    }
  }

  free(dlm);
  return NULL;
}
