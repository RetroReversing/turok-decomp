typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef unsigned long DWORD;typedef struct CCartCache CCartCache;typedef struct CCacheEntry CCacheEntry;typedef void ROMAddress;
typedef struct {u8 pad[0xc414];CCartCache*m_pCache;CCacheEntry*m_pceParticleEffects,*m_pceTextureSetsIndex;} CParticleSystem;
typedef void (*pfnCACHENOTIFY)(void*,CCacheEntry**);
void func_80029D94(CParticleSystem*,CCacheEntry**);
void CCartCache__RequestBlock(CCartCache*,void*,pfnCACHENOTIFY,pfnCACHENOTIFY,CCacheEntry**,ROMAddress*,DWORD,const char*);
extern char D_800F17D0[];
#define CCartCache__RequestBlock CCartCache__RequestBlock
#define CParticleSystem__DecompressParticles func_80029D94
#define NULL ((void*)0)


