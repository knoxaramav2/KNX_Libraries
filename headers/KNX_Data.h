#ifndef KNX_DATA
#define KNX_DATA

#include <stddef.h>

//data structure components

typedef struct Leaf{

int meta;
void * data;

struct Leaf ** branch;
struct Leaf * parent;

}Leaf;

typedef struct LNode{

    int meta;
    void * data;
    struct LNode * prev;
    struct LNode * next;

}LNode;

//data structures

//binary and splay tree
typedef struct BinaryTree{
    Leaf * root;
    Leaf * head;
}BinaryTree;

//Doubly linked list
typedef struct LList{
    LNode * root;
    LNode * head;
}LList;

typedef struct HashMap{
    unsigned size;

    int * meta;//void type meta info
    void ** value;
    unsigned long long * key;//FNV-1A
}HashMap;

//factories
BinaryTree * BuildBinaryTree();
Leaf * BuildBTLeaf(void*, int);
LList * BuildLinkedList();
LNode * BuildLNode();
HashMap * BuildHashMap();

//BT methods
void DestroyBinaryTree(BinaryTree*);
void AppendBTLeaf(BinaryTree*, Leaf*);

//Linked list methods
void DestroyLList(LList*);

//HashMap list
void DestroyHashMap(HashMap*);

#endif
