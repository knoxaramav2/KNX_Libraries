#include "../headers/KNX_File.h"

#include <stdlib.h>
#include <stdio.h>

bufferedFile*openBufferedFile(const char*path)
{
  FILE * fp;
  //attempt to open file
  fp = fopen(path,"r");
  if (fp==NULL)
    return NULL;

  bufferedFile * bf = malloc(sizeof(bufferedFile*));

  if (bf==NULL)
  {
    fclose(fp);
    return NULL;
  }


  bf=malloc(strlen(path)+1);
  if (bf==NULL)
    {
      fclose(fp);
      free(bf);
    }

  strncpy(bf->filePath,path,strlen(path)+1);

  bf->lines=0;

  char* buff = NULL;
  size_t buffLen = 0;
  bf->text=malloc(0);
  size_t read=0;
  while ((read = getline(&buff, &buffLen, fp)) != -1)
  {
    ++bf->lines;
    bf->text=realloc(bf->text,bf->lines);
    bf->text[bf->lines-1]=malloc(strlen(buff)+1);
    strncpy(bf->text[bf->lines-1], buff, strlen(buff)+1);
    printf("%s", buff);
  }


  //close file handle
  fclose(fp);

  return bf;
}

int closeBufferedFile(bufferedFile*bf)
{

  if (bf==NULL)
    return 0;

  free(bf->text);
  free(bf->filePath);
  free(bf->iterator);
  free(bf);

  return 1;
}

int saveBufferedFile(bufferedFile*bf)
{

return 1;
}


char * getExtension(const char*input)
{

  if (input==NULL)
    return NULL;

  size_t len = strlen(input);

  //scan for '.'
  unsigned dPos=-1;
  for (size_t x=len-1; x>=0; --x)
  {
    if (input[x]=='.')
      {
        dPos=(unsigned)x;
        break;
      }
  }

  if (dPos==-1)
    return NULL;

  char * ret = malloc((len-dPos)+1);
  strncpy(ret, input+dPos, len);

  return ret;
}

char * getFileName(const char*input)
{
  int rPos=-1;//index before extension
  int lPos=0;//index after last '/' or '\\'

  unsigned len = (unsigned) strlen(input);
  rPos=len-1;

  if (len==0)
    return NULL;

  for (unsigned x=0; x<len; ++len)
  {
    if (input[x]=='.' || x+1==len)//end
    {
      rPos=x-1;
      break;
    }else if (input[x]=='/' || input[x]=='\\')
      lPos=x;
  }

  return NULL;
}

char *getPath(const char*input)
{

  return NULL;
}
