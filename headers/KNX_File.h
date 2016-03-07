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

//creates new bufferd file
bufferedFile*openBufferedFile(char*path);
int closeBufferedFile(bufferedFile*);
int saveBufferedFile(bufferedFile*);

char * getExtension(const char*);
char * getFileName(const char*);
char * getPath(const char*);

#ifdef __cplusplus
}
#endif
#endif
