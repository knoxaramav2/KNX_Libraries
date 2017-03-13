#ifndef KNX_FILE
#define KNX_FILE

#ifdef __cplusplus
extern "C"{
#endif
#include <string.h>

//loads file and keeps other information

struct bfileTag;
typedef struct bfileTag
{
char*filePath;
unsigned lines;
unsigned bytes;

char**text;
char*iterator;

}BufferedFile;

//general functions
BufferedFile*buildBufferedFile(char*path);
int closeBufferedFile(BufferedFile*);
int saveBufferedFile(BufferedFile*);

//path functions
char * getExtension(char*);
char * getFileName(char*, char);
char * getPath(char*);
char * getExePath();
//iterator functions
char getChar(BufferedFile *);
char getLine(BufferedFile *);
void toStart(BufferedFile *);//reset iterator to beginning
void toEnd(BufferedFile *);//place iterator at end

#ifdef __cplusplus
}
#endif
#endif
