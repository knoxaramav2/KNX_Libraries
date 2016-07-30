#include "../headers/KNX_File.h"
#include "../headers/KNX_String.h"
#include "../headers/KNX_Hash.h"

#include <stdio.h>
#include <stdlib.h>

#define STRING_TEST		1
#define FILE_TEST		2
#define CGRAPHIC_TEST		3

#define CMODE FILE_TEST

#if CMODE == STRING_TEST
int main ()
{
printf("TheWhole World = %s\n", toLowerc("TheWhole World"));

return 0;
}
#elif CMODE == FILE_TEST
int main()
{
	printf("mark\n");
printf("%s\n", getFileName("this/is/a.test"));
	printf("mark\n");
printf("%s\n", getExtension("this/is/a.test"));
	printf("mark3\n");
printf("%s\n", getPath("this/is/a.test"));
}

#elif CMODE == CGRAPHIC_TEST




#else




#endif
