//#include "KNX_Data.h"

#include <stdlib.h>

kPtr ** kPtrDb;
size_t kdbSz;

void initkDb()
{
  kPtrDb=malloc(0);
  kdbSz=0;
}

kPtr * mkPtr(void * ref)
{
  if (kPtrDb==0)
    initkDb();

  //check if resource already owned
  for (size_t x=0; x<kdbSz; ++x)
  {
    if (kPtrDb[x]->data==ref)
      return kPtrDb[x];
  }

  kPtr * ret = malloc(sizeof(kPtr));
  ret->data=ref;
  //ret->size=sizeof(ref);

  kPtrDb = malloc(sizeof(kPtr*)*(kdbSz+1));
  kPtrDb[kdbSz++]=ret;

  return ret;
}

//TODO work out how to protect existing references
int dlPtr(kPtr*ref)
{
  for (size_t x=0; x<kdbSz; ++x)
  {
    if (kPtrDb[x]->data==ref)
    {
      free(kPtrDb[x]);

      return 0;
    }
  }


  return 1;
}
