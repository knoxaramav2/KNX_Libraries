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

char**text;
char*iterator;

}bufferedFile;

//general functions
bufferedFile*openBufferedFile(const char*path);
int closeBufferedFile(bufferedFile*);
int saveBufferedFile(bufferedFile*);

//path functions
char * getExtension(const char*);
char * getFileName(const char*);
char * getPath(const char*);
//iterator functions
char getChar(bufferedFile *);
char getLine(bufferedFile *);
void toStart(bufferedFile *);//reset iterator to beginning
void toEnd(bufferedFile *);//place iterator at end

#ifdef __cplusplus
}
#endif
#endif
