#include "../headers/KNX_File.h"
#include "../headers/KNX_String.h"
#include "../headers/KNX_Hash.h"

#include <stdio.h>

int main()
{
printf("%llu\n", FNV_1a("Hello World"));
printf("%llu\n", FNV_1a("Hello World"));
printf("%llu\n", FNV_1a("Hello World"));

return 0;
}
