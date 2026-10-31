#include "common.h"

typedef unsigned short sa_u16;
typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
typedef long sa_s32;
typedef float sa_f32;
typedef double sa_f64;
typedef sa_s32 OSPri;
typedef sa_s32 OSId;
typedef union {
    struct {
        sa_f32 f_odd;
        sa_f32 f_even;
    } f;
    sa_f64 d;
} __OSfp;
typedef struct {
    sa_u64 at, v0, v1, a0, a1, a2, a3;
    sa_u64 t0, t1, t2, t3, t4, t5, t6, t7;
    sa_u64 s0, s1, s2, s3, s4, s5, s6, s7;
    sa_u64 t8, t9;
    sa_u64 gp, sp, sa_s8, ra;
    sa_u64 lo, hi;
    sa_u32 sr, pc, cause, badvaddr, rcp;
    sa_u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct {
    sa_u32 flag;
    sa_u32 count;
    sa_u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s {
    struct OSThread_s *next;
    OSPri priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    sa_u16 state;
    sa_u16 flags;
    OSId id;
    int fp;
    __OSThreadprofile_s *thprof;
    __OSThreadContext context;
} OSThread;
extern void osSetThreadPri(OSThread *, OSPri);
extern OSPri func_800A1920(OSThread *);
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CSun_t
{
 int m_nBuffer, m_nReceived;
 float m_ScreenX, m_ScreenY,
     m_Opacity;
 CVector3 m_vDir;
 int m_Visible;
} CSun;
extern void func_80098670(CSun *pThis, int *pVisible, float *pX, float *pY, float *pOpacity);
void func_80098670(CSun *pThis, int *pVisible, float *pX, float *pY, float *pOpacity);
void func_80098670(CSun *pThis, int *pVisible, float *pX, float *pY, float *pOpacity){
 OSPri ospri;
 ospri = func_800A1920(((void*)0));
 osSetThreadPri(((void*)0), 15);
 *pVisible = pThis->m_Visible;
 *pOpacity = pThis->m_Opacity;
 osSetThreadPri(((void*)0), ospri);
 *pX = pThis->m_ScreenX;
 *pY = pThis->m_ScreenY;
}
