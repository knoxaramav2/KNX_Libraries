#include "../headers/KNX_File.h"

#include <stdio.h>

int main()
{

bufferedFile * bf = NULL;
bf = openBufferedFile("test.txt");

if (bf==NULL)
	printf("Failed to load\n");

closeBufferedFile(bf);

return 0;
}
