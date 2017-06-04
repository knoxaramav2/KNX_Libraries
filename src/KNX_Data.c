//#include "KNX_Data.h"

#include <stdlib.h>

BinaryTree * BuildBinaryTree(){

  BinaryTree * btree = malloc(sizeof(BinaryTree));

  btree->root = NULL;
  btree->head = NULL;

  return btree;
}

Leaf * BuildBTLeaf(){
  Leaf * leaf = malloc(sizeof(Leaf));

  return leaf;
}

LList * BuildLinkedList(){

  LList * list = malloc(sizeof(LList));

  list->root = NULL;
  list->head = NULL;

  return list;
}

LNode * BuildLNode(){
  LNode * lnode = malloc(sizeof(LNode));

  return lnode;
}

HashMap * BuildHashMap(){
  
  HashMap * hmap = malloc(sizeof(HashMap));

  hmap->size = 0;
  hmap->value = NULL;
  hmap->key = NULL;
  hamp->meta = NULL;

  return hmap;
}


void DestroyBinaryTree(BinaryTree*bt){

  if (bt==NULL) return;

  free(bt);
}


void DestroyLList(LList*ls){

  if (ls == NULL) return;

  LNode * itr = ls->root;

  while (itr != NULL){
    LNode * next = itr->next;

    if (itr->data != NULL) free(itr->data);
    free(itr);

    itr = next;
  }

  free(ls);
}


void DestroyHashMap(HashMap*hmap){

  if (hmap == NULL) return;

  for (unsigned x=0; x<hmap->size; ++x){
    if (hmap->value[x] != NULL) free(hmap(value));
  }

  free(hmap->meta);
  free(hmap->key);
  free(hmap);

}