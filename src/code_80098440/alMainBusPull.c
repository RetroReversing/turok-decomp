#include "common.h"
#line 1 "func.c"
typedef struct {struct {u32 w0,w1;} words;} Acmd;
typedef struct LiveFilter LiveFilter;
struct LiveFilter {s32 pad;Acmd *(*handler)(void*,s16*,s32,s32,Acmd*);};
typedef LiveFilter ALFilter;
typedef struct {u8 pad[0x14];s32 sourceCount;s32 maximum;ALFilter **sources;} ALMainBus;
#define A_CLEARBUFF 2
#define A_MIXER 12
#define A_SETBUFF 8
#define AL_MAIN_L_OUT 0x440
#define AL_MAIN_R_OUT 0x580
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
#define	aMix(pkt, f, g, i, o)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(g, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(i,16, 16) | _SHIFTL(o, 0, 16);		\
}
#define	aSetBuffer(pkt, f, i, o, c)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(i, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16);		\
}
#line 24 "mainbus.c"
Acmd *alMainBusPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) 
{
    Acmd        *ptr = p;
    ALMainBus   *m = (ALMainBus *)filter;
    ALFilter    **sources = m->sources;
    s32         i;

    /*
     * clear the output buffers here
     */
    aClearBuffer(ptr++, AL_MAIN_L_OUT, outCount<<1);
    aClearBuffer(ptr++, AL_MAIN_R_OUT, outCount<<1);

    for (i = 0; i < m->sourceCount; i++) {
        ptr = (sources[i]->handler)(sources[i], outp, outCount, sampleOffset,
                                    ptr);
	aSetBuffer(ptr++, 0, 0, 0, outCount<<1);
	aMix(ptr++, 0, 0x7fff, AL_AUX_L_OUT, AL_MAIN_L_OUT);
	aMix(ptr++, 0, 0x7fff, AL_AUX_R_OUT, AL_MAIN_R_OUT);
    }
    
    return ptr;
}

