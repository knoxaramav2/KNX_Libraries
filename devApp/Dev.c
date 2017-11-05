#include "../headers/KNX_File.h"
#include "../headers/KNX_String.h"
#include "../headers/KNX_Hash.h"
#include "KNX_Data.h"

#include <stdio.h>
#include <stdlib.h>

#define STRING_TEST		1
#define FILE_TEST		2
#define CGRAPHIC_TEST	3
#define DATA_TEST       4
#define HASH_TEST       5

#define CMODE STRING_TEST

#if CMODE == STRING_TEST
int main ()
{
    //char ** list;
    printf("TheWhole World = %s\n", toLowerc("TheWhole World"));

return 0;
}
#elif CMODE == FILE_TEST
int main()
{

    char * teststr = "test.txt";
    char * demostr = "demo.txt";

    BufferedFile * bfile = buildBufferedFile(teststr);

    if (!bfile){
        printf("Fail\r\n");
        return -1;
    }

    saveBufferedFileAs(bfile, demostr);
    closeBufferedFile(bfile);

}

#elif CMODE == CGRAPHIC_TEST

    
#elif CMODE == HASH_TEST
int main()
{
    printf(">>%d\r\n", BITMODE);
    printf("%llu\r\n", FNV_1a_32("hello world"));
    printf("%llu\r\n", FNV_1a("hello world"));
    printf("%llu\r\n", FNV_1_32("hello world"));
    printf("%llu\r\n", FNV_1("hello world"));
}
#endif
