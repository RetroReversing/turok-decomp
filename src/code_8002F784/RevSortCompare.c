#include "common.h"

typedef struct SortStruct_t
{
 void *p;
 float dist;
} SortStruct;
int RevSortCompare(const void *pA, const void *pB);
int RevSortCompare(const void *pA, const void *pB){
 return ((((SortStruct*)pA)->dist < ((SortStruct*)pB)->dist)) ? -1 : 1;
}
