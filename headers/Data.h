#ifndef KNX_DATA
#define KNX_DATA

/*
Defines common data storage structures
*/

//Binary Search Tree Token



typedef struct bToken
{
  //generic user defined type
  unsigned bToken;
  void * token;
  struct bToken * next;
  struct bToken * left;
}bToken;


#endif
