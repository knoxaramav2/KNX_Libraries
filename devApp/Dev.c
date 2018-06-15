#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "KNX_String.h"
#include "KNX_Console.h"
#include "KNX_Struct.h"

#define PI 3.14159265



int main(){

    binaryTree * tree = createBinaryTree();

    addBRecord(tree, 0, malloc(sizeof(int)), 8);
    addBRecord(tree, 0, malloc(sizeof(int)), 2);
    addBRecord(tree, 0, malloc(sizeof(int)), 7);
    addBRecord(tree, 0, malloc(sizeof(int)), 5);
    addBRecord(tree, 1, malloc(sizeof(double)), 11);
    addBRecord(tree, 2, malloc(sizeof(char) * 4), 4);

    *(int*)(getBEntry(tree, 8, 0)->data) = 3;

    printf("%d\r\n", *(int *)(getBEntry(tree, 8, 0))->data);

    return 0;
}