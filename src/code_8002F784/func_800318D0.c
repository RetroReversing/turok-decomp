#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef union {struct {unsigned long w0,w1;} words;unsigned long long force_align;} Gfx;
typedef struct {u8 pad[0x7e60];u8 m_ParticleSystem[1];} CScene;
void CParticleSystem__Draw(void*,Gfx**);
#define CParticleSystem__Draw CParticleSystem__Draw
#define WORD(pkt,offset,value) {Gfx *_g=(Gfx*)(pkt); _g->words.w0=0xbc000004 | ((offset)<<8); _g->words.w1=(value);}
#define gSPClipRatio(pkt,r) { WORD(pkt,4,1);WORD(pkt,12,1);WORD(pkt,20,0xffff);WORD(pkt,28,0xffff); }
#define FRUSTRATIO_1 1







void func_800318D0(CScene *pThis, Gfx **ppDLP)
{
	// 1 makes ground aligned particles look better
	gSPClipRatio((*ppDLP)++, FRUSTRATIO_1);

	CParticleSystem__Draw(&pThis->m_ParticleSystem, ppDLP);
}

