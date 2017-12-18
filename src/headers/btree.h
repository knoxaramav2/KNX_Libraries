#ifndef KNX_BTREE
#define KNX_BTREE

typedef struct leaf leaf;

typedef struct leaf{

    struct leaf * parent;
    struct leaf * left;
    struct leaf * right;

} leaf;

typedef struct binaryTree{

    unsigned records;

    leaf * root;

} binaryTree;

binaryTree * createBinaryTree();

#endif