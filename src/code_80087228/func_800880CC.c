#include "common.h"

typedef struct CPause_t CPause;
extern char D_801293F0[];

int func_800880CC(CPause *pThis)
{
    int nTotal = 0;
    int cnt;
    for (cnt = 0; cnt < 30; cnt++)
        nTotal += D_801293F0[cnt];
    return nTotal;
}
