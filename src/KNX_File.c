#define _GNU_SOURCE
#include "../headers/KNX_File.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <limits.h>
#include <math.h>

/*
char*filePath;
unsigned lines;

char**text;
char*iterator;
*/

//buffer grows exponentially at bz = 32*2^n
BufferedFile*buildBufferedFile(char*path)
{
  FILE * fp;
  //attempt to open file
  fp = fopen(path,"r");
  if (fp==NULL)
    return NULL;

  BufferedFile * bf = malloc(sizeof(BufferedFile));

  //copy file path
  size_t plen = strlen(path);
  bf->filePath = malloc(plen + 1);
  strncpy(bf->filePath, path, plen);
  bf->filePath[plen]=0;

  bf->lines = 0;
  bf->bytes = 0;

  bf->text = malloc(sizeof(char*) * 32);
  bf->iterator = 0;

  ssize_t bytesRead = 0;
  size_t len = 0;
  
  char * temp = 0;

  //begin reading file
  while ((bytesRead = getline(&temp, &len, fp)) != -1){
    
    //remove newline characters
    if (temp[bytesRead-1]=='\n'){
      #ifdef __WINDOWS
      temp[bytesRead-1]=0;
      temp[bytesRead-2]=0;
      bytesRead -= 2;
      #else
      temp[bytesRead-1]=0;
      --bytesRead;
      #endif
    }
    
    
    bf->bytes += bytesRead;

    //grow buffer if neccessary
    if ((bf->lines+1) % 32 == 0){

      char ** tmp = realloc(bf->text, 32 * pow(2, bf->lines/32));
    
      if (tmp == 0){
        perror("Failed to grow buffer\r\n");

        for (size_t x = 0; x < bf->lines; ++x)
        {
          free(bf->text[x]);
        }

        free(bf->text);

        return 0;
      }

      bf->text = tmp;
    }
    
    //append to buffer
    bf->text[bf->lines] = malloc(bytesRead);
    strncpy(bf->text[bf->lines], temp, bytesRead);
    ++bf->lines;

    printf("%lu | %s\r\n", bytesRead, bf->text[bf->lines-1]);
  }

  free (temp);

  return bf;
}

int closeBufferedFile(BufferedFile*bf)
{

  if (bf==NULL)
    return 0;

  free(bf->text);
  free(bf->filePath);
  free(bf->iterator);
  free(bf);

  return 1;
}

int saveBufferedFile(BufferedFile*bf)
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


char * getExtension(char*input)
{
  if (input==0)
    return 0;

  size_t len = strlen(input);
  size_t x = len - 1;

  for (; x>=0 && input[x] != '.'; --x);

  if (input[x] == '.') ++x;

  char * ret = malloc(len - x + 1);
  strncpy(ret, input+x, len - x);
  ret[len - x] = 0;

  return ret;
}

char * getFileName(char*input, char includeExtension)
{
  if (input==0)
	  return 0;

  size_t len = strlen(input);

  if (len == 0)
	  return 0;

  char * ret = 0;
  char * eCap = input + len - 2;

  for (size_t x = len - 1; x >= 0 ; --x)
  {
    if (input[x]=='.' && !includeExtension){
      eCap = input + x - 2;
    } else if (input[x]=='/' || input[x]=='\\' || x == 0){
      ret = malloc((eCap - (input + x)) + 1);
      strncpy(ret, input + x + 1, (eCap - (input + x)) + 1);
      ret[(eCap - (input + x)) + 1] = 0;
      break;
    }
  }

  return ret;
}

char * getPath(char * input)
{

  if (input == 0) return 0;

  size_t len = strlen(input);
  size_t x = len - 1;

  for (; x>=0 && input[x] != '/' && input[x] != '\\'; --x);

  char * ret = malloc(x+1);
  strncpy(ret, input, x);
  ret[x]=0;


  return ret;
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
