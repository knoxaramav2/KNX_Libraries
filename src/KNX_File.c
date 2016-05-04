#define _GNU_SOURCE
#include "../headers/KNX_File.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bufferedFile*openBufferedFile(const char*path)
{
  FILE * fp;
  //attempt to open file
  fp = fopen(path,"r");
  if (fp==NULL)
    return NULL;

  bufferedFile * bf = malloc(sizeof(bufferedFile));

  if (bf==NULL)
  {
    fclose(fp);
    return NULL;
  }

  bf->filePath = malloc(sizeof(path)+1);

  strncpy(bf->filePath,path,strlen(path)+1);

  bf->lines=0;

  char* buff = NULL;
  size_t buffLen = 0;
  bf->text=malloc(0);
  size_t read=0;
  while ((read = getline(&buff, &buffLen, fp)) != -1)
  {
    ++bf->lines;
    char ** tmp=(char**)realloc(bf->text,bf->lines*sizeof(char*));
    if (tmp==NULL)
    {
      perror("realloc");
      return NULL;
    }
    bf->text=tmp;
    fflush(stdout);
    bf->text[bf->lines-1]=(char*)malloc(strlen(buff)+1);
    fflush(stdout);
    strncpy(bf->text[bf->lines-1], buff, strlen(buff)+1);

    //remove newline/carriage return (windows)
    #ifdef __WINDOWS
    bf->text[bf->lines-1][strlen(buff)-2]=0;
    #else//Linux
    bf->text[bf->lines-1][strlen(buff)-1]=0;
    #endif
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
  if (bf==NULL)
    return 0;

  FILE * fp = fopen(bf->filePath ,"w");

  if (fp==NULL)
    return 0;

  for (size_t x=0; x<bf->lines; ++x)
  {
    #ifdef __WINDOWS
    fprintf(fp, "%s\r\n", bf->text[x]);
    #else//Linux
    fprintf(fp, "%s\n", bf->text[x]);
    #endif
  }
return 1;
}


char * getExtension(const char*input)
{

  if (input==NULL)
    return NULL;

  printf("<<");
  fflush(stdout);
  size_t len = strlen(input);
  printf(">>");
  //scan for '.'
  int dPos=-1;
  for (int x=(int)len-1; x>=0; --x)
  {
    if (input[x]=='.')
      {
        dPos=(int)x;
        break;
      }
  }

  if (dPos==-1)
    return NULL;

  printf("%d\n", (int)(len-dPos)+1);
  char * ret = malloc((len-dPos)+1);
  strncpy(ret, input+dPos, len+1);


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

char * getPath(const char * input)
{

  return NULL;
}

char *getExePath()
{

  char path[256];
  char dest[256];
  //struct stat info;
  //pid_t pid = getpid();
  sprintf(path, "/proc/self/exe");
  readlink(path, dest, 256);

  //localAddr = dest;

  #ifdef __WINDOWS
  //remove cygwin path

  char * lcAddr = malloc(sizeof(dest)-12);
  lcAddr[0]=dest[0];
  lcAddr[1]=':';
  strncpy(lcAddr, dest+12, sizeof(dest)-12);
  lcAddr[sizeof(dest)-12]=0;

  /*
  localAddr.erase(localAddr.begin(), localAddr.begin()+10);
  localAddr.erase(localAddr.end()-3, localAddr.end());
  localAddr.insert(localAddr.begin()+1, ':');*/

  return lcAddr;
  #else
  //localAddr.erase(localAddr.end()-3, localAddr.end());
  char *lcAddr = malloc(sizeof(dest)-3);
  strncpy(lcAddr, dest, sizeof(dest)-3);
  lcAddr[sizeof(dest)-3]=0;
  return lcAddr;

  #endif

  return NULL;
}
