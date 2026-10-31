#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {struct {u32 w0,w1;} words;} Acmd;
typedef struct ALFilter ALFilter;
struct ALFilter {s32 pad;Acmd *(*handler)(void*,s16*,s32,s32,Acmd*);};
typedef struct {u8 pad[0x14];s32 sourceCount;s32 maximum;ALFilter **sources;} ALAuxBus;
#define A_CLEARBUFF 2
#define AL_AUX_L_OUT 0x6c0
#define AL_AUX_R_OUT 0x800
#define _SHIFTL(v,s,w) ((u32)(((u32)(v) & ((1U << (w))-1)) << (s)))
#define	aClearBuffer(pkt, d, c)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24);	\
	_a->words.w1 = (unsigned int)(c);				\
}
#line 24 "auxbus.c"
Acmd *alAuxBusPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                   Acmd *p) 
{
    Acmd        *ptr = p;
    ALAuxBus     *m = (ALAuxBus *)filter;
    ALFilter    **sources = m->sources;
    s32         i;

    /*
     * clear the output buffers here
     */
    aClearBuffer(ptr++, AL_AUX_L_OUT, outCount<<1);
    aClearBuffer(ptr++, AL_AUX_R_OUT, outCount<<1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = (sources[i]->handler)(sources[i], outp, outCount, sampleOffset,
                                    ptr);
    }
    
    return ptr;
}

