#include "common.h"

typedef struct SortStruct_t
{
 void *p;
 float dist;
} SortStruct;
int func_80030920(const void *pA, const void *pB);
int func_80030920(const void *pA, const void *pB){
 return ((((SortStruct*)pA)->dist < ((SortStruct*)pB)->dist)) ? -1 : 1;
}
