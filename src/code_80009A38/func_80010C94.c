#include "common.h"

typedef unsigned char sa_u8;
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
typedef sa_u32 OSEvent;
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    sa_s32 validCount;
    sa_s32 first;
    sa_s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
extern void func_8009E4A0(OSMesgQueue *, OSMesg *, sa_s32);
extern void func_8009D020(OSEvent, OSMesgQueue *, OSMesg);
typedef struct {
 sa_u16 type;
 sa_u8 status;
 sa_u8 errno;
}OSContStatus;
extern sa_s32 func_8009EBD0(OSMesgQueue *, sa_u8 *, OSContStatus *);
typedef struct CControlState_t
{
 sa_u16 BDown,
   BUp,
   BSingle,
   BDbl,
   BDblHold,
   BTimer [ 16 ];
 sa_s8 StickX,
   StickY;
 float Smooth,
   SStickX,
   SStickY;
} CControlState;
extern CControlState D_801199D0;
extern sa_u8 D_800B86D0;
extern OSContStatus D_80119980[];
extern int func_80010C94 ( void );
typedef struct {
    short type;
    char misc[30];
} OSScMsg;
extern OSMesgQueue D_800F9C20;
extern sa_u8 D_800B86D0;
extern OSContStatus D_80119980[4];
extern OSScMsg D_801199A8;
extern CControlState D_801199D0;
extern OSMesgQueue D_80119A70;
extern OSMesg D_80119A88;
int func_80010C94 ( void );
int func_80010C94 ( void ){
 sa_u16 i, cnt;
 sa_u16 controller ;
 func_8009E4A0(&D_80119A70, &D_80119A88, 1);
 func_8009D020(5, &D_80119A70, (OSMesg)1);
 func_8009EBD0(&D_80119A70, &D_800B86D0, &D_80119980[0]) ;
 if (D_800B86D0)
 {
  controller = -1 ;
  for (i=0; i < 4; i++)
  {
   if ((D_800B86D0 & (1<<i)) && !(D_80119980[i].errno & 0x8))
   {
    controller = i ;
    break ;
   }
  }
  D_801199A8.type = (4 + 1);
  func_8009D020(5, &D_800F9C20, (OSMesg)&D_801199A8);
  D_801199D0.BUp = 0;
  D_801199D0.BDown = 0;
  D_801199D0.BSingle = 0;
  D_801199D0.BDbl = 0;
  D_801199D0.StickX = 0;
  D_801199D0.StickY = 0;
  D_801199D0.SStickX = 0;
  D_801199D0.SStickY = 0;
  D_801199D0.Smooth = 2;
  for ( cnt = 0; cnt < 16; cnt ++ )
   D_801199D0. BTimer[cnt] = 6 +1;
  return controller ;
 }
                                        ;
 return -1;
}
