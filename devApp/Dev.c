#include <stdio.h>

#include "KNX_String.h"

int main(){

    char fileStr [] = "this/is/a.test";

    printf("%s\r\n", getFileExtension(fileStr));
    printf("%s\r\n", getFilePath(fileStr));
    printf("%s\r\n", getFileName(fileStr, 0));
    printf("%s\r\n", getFileName(fileStr, 1));

    char fileStr2 [] = "a.test";

    printf("%s\r\n", getFileExtension(fileStr2));
    printf("%s\r\n", getFilePath(fileStr2));
    printf("%s\r\n", getFileName(fileStr2, 0));
    printf("%s\r\n", getFileName(fileStr2, 1));

    return 0;
}