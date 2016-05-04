#ifndef KNX_DATA
#define KNX_DATA

#include <stddef.h>

//garbage collected smart pointer
typedef struct kPtr
{
void * data;
}kPtr;

//create and register new pointer
//if pointer to object already exists, return existing reference
kPtr * mkPtr(void*);
int dlPtr(kPtr*);

//global smart pointer reference
extern kPtr ** kPtrDb;
extern size_t kdbSz;//Would be much easier with visibility controls

#endif
