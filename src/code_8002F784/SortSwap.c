#include "common.h"

typedef struct { s32 x,y; } SolPair;
void SortSwap(SolPair *a, SolPair *b) { SolPair t; t=*a;*a=*b;*b=t;}
