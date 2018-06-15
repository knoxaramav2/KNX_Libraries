#ifndef KNX_BTREE
#define KNX_BTREE

#define BTREE_DUPLICATE_ENTRY   -1
#define BTREE_EMPTY_DELETE      -2
#define BTREE_NOT_FOUND         -3

typedef struct leaf leaf;

typedef struct bEntry{
    char identifier;
    void * data;
} bEntry;

typedef struct leaf{

    struct leaf * parent;
    struct leaf * left;
    struct leaf * right;

    int index;

    bEntry * entry;

} leaf;

typedef struct binaryTree{

    unsigned records;

    leaf * root;

} binaryTree;

binaryTree * createBinaryTree();
int addBRecord(binaryTree * btree, char identifier, void * data, int index);
int removeBRecord(binaryTree * btree, int index);
void clearBRecord(binaryTree * btree);
bEntry * getBEntry(binaryTree * btree, int index, int splay);

#endif