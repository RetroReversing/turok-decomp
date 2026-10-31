#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef union {s32 m[4][4];s64 force_structure_alignment;} Mtx;
#define FTOFIX32(x) ((int)((x)*65536.0f))
#define FIX32TOF(x) ((float)(x)/65536.0f)
#line 15 "MTXUTIL.C"
void guMtxF2L(float mf[4][4], Mtx *m)
{
	int	i, j;
	int	e1,e2;
	int	*ai,*af;


	ai=(int *) &m->m[0][0];
	af=(int *) &m->m[2][0];

	for (i=0; i<4; i++)
	for (j=0; j<2; j++) {
		e1=FTOFIX32(mf[i][j*2]);
		e2=FTOFIX32(mf[i][j*2+1]);
		*(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff);
		*(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff);
	}
}

