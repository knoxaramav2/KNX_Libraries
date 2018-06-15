#include <stdlib.h>

#include "btree.h"


//returns pointer to leaf reference, or pointer to where it would be if null
leaf ** searchSlot(binaryTree * btree, int index, leaf ** parent){

    leaf ** current = &btree->root;
    *parent = 0;

    leaf * test = malloc(sizeof(test));
    test->index = 4;

    for(;*current != 0;){

        if ((*current)->index == index){
            return current;
        }

        leaf ** select = index > (*current)->index ? 
            &((*current)->right) :
            &((*current)->left);

        //(*select) = test;
        
        if (parent){
            *parent = *current;
        }

        current = select;
    }

    return current;
}


binaryTree * createBinaryTree(){

    binaryTree * ret = malloc(sizeof(binaryTree));

    ret->root = 0;
    ret->records = 0;

    return ret;
}

int addBRecord(binaryTree * btree, char identifier, void * data, int index){

    bEntry * b = malloc(sizeof(bEntry));
    b->identifier = identifier;
    b->data = data;

    leaf * l = malloc(sizeof(leaf));
    l->parent = 0;
    l->left = 0;
    l->right = 0;
    l->entry = b;
    l->index = index;

    leaf * parent = 0;
    leaf ** slot = searchSlot(btree, index, &parent);
    if (*slot){
        return BTREE_DUPLICATE_ENTRY;
    }

    *slot = l;
    l->parent = parent;
    ++btree->records;

    return btree->records;
}

int removeBRecord(binaryTree * btree, int index){

    if (btree->records == 0){
        return BTREE_EMPTY_DELETE;
    }

    leaf * parent = 0;
    leaf ** slot = searchSlot(btree, index, &parent);

    if (!*slot){
        return BTREE_NOT_FOUND;
    }

    leaf * left = (*slot)->left;
    leaf * right = (*slot)->right;

    //non root and target is less than parent
    if (parent && *slot == left){

    }

    return btree->records;
}

void clearBRecord(binaryTree * btree){

    
}

bEntry * getBEntry(binaryTree * btree, int index, int splay){

    return 0;
}

