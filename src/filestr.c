#include <string.h>
#include <stdlib.h>

#include "file_string.h"

char * getFileExtension(char * filePath){
    size_t len = strlen(filePath);
    size_t index = len;
    //char * ret = malloc(len + 1);

    for (size_t i=0; i < len; ++i){
        if (*(filePath + i) == '.'){
            index = i + 1;
            break;
        }
    }

    char * ret = malloc((len-index)+1);
    return strncpy(ret, filePath+index, len-index);
}

char * getFilePath(char * filePath){
    size_t len = strlen(filePath);
    size_t index = len;

    for (size_t i=len; i > 0; --i){

        char c = *(filePath + i);

        if (c == '/' || c=='\\'){
            index = i;
            break;
        }
    }

    char * ret = malloc((len-index)+1);
    return strncpy(ret, filePath, len-index);
}

char * getFileName(char * filePath, char includeExtension){
    size_t len = strlen(filePath);
    size_t sIndex = 0;
    size_t eIndex = len;

    for (size_t i=len; i > 0; --i){

        char c = *(filePath + i);

        if (c=='.' && !includeExtension){
            eIndex = i;
        }

        if (c == '/' || c=='\\'){
            sIndex = i + 1;
            break;
        }
    }

    char * ret = malloc((eIndex - sIndex)+1);
    strncpy(ret, filePath+sIndex, eIndex-sIndex);
    ret[eIndex - sIndex] = 0;
    return ret;
}