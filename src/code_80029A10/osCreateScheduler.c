#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

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
extern void osCreateThread(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
extern void osStartThread(OSThread *);
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
extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, sa_s32);
extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);
typedef struct {
    sa_u32 ctrl;
    sa_u32 width;
    sa_u32 burst;
    sa_u32 vSync;
    sa_u32 hSync;
    sa_u32 leap;
    sa_u32 hStart;
    sa_u32 xScale;
    sa_u32 vCurrent;
} OSViCommonRegs;
typedef struct {
    sa_u32 origin;
    sa_u32 yScale;
    sa_u32 vStart;
    sa_u32 vBurst;
    sa_u32 vIntr;
} OSViFieldRegs;
typedef struct {
    sa_u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;
extern OSViMode func_800EE4F0[];
extern void osViSetMode(OSViMode *);
extern void osViSetEvent(OSMesgQueue *, OSMesg, sa_u32);
extern void osViBlack(sa_u8);
extern void osCreateViManager(OSPri);
typedef sa_u64 OSTime;
typedef struct {
 sa_u32 type;
 sa_u32 flags;
 sa_u64 *ucode_boot;
 sa_u32 ucode_boot_size;
 sa_u64 *ucode;
 sa_u32 ucode_size;
 sa_u64 *ucode_data;
 sa_u32 ucode_data_size;
 sa_u64 *dram_stack;
 sa_u32 dram_stack_size;
 sa_u64 *output_buff;
 sa_u64 *output_buff_size;
 sa_u64 *data_ptr;
 sa_u32 data_size;
 sa_u64 *yield_data_ptr;
 sa_u32 yield_data_size;
} OSTask_t;
typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;
typedef struct {
    short type;
    char misc[30];
} OSScMsg;
typedef struct OSScTask_s {
    struct OSScTask_s *next;
    sa_u32 state;
    sa_u32 flags;
    void *framebuffer;
    OSTask list;
    OSMesgQueue *msgQ;
    OSMesg msg;
    OSTime startTime;
    OSTime totalTime;
} OSScTask;
typedef struct SCClient_s {
    struct SCClient_s *next;
    OSMesgQueue *msgQ;
} OSScClient;
typedef struct {
    OSScMsg retraceMsg;
    OSScMsg prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg intBuf[8];
    OSMesgQueue cmdQ;
    OSMesg cmdMsgBuf[8];
    OSThread thread;
    OSScClient *clientList;
    OSScTask *audioListHead;
    OSScTask *gfxListHead;
    OSScTask *audioListTail;
    OSScTask *gfxListTail;
    OSScTask *curRSPTask;
    OSScTask *curRDPTask;
    sa_u32 frameCount;
    sa_s32 doAudio;
} OSSched;
extern void osCreateScheduler(OSSched *s, void *stack, OSPri priority,
                                  sa_u8 mode, sa_u8 numFields);
extern sa_u64 dram_stack[];
extern void __scMain(void *arg);
void osCreateScheduler(OSSched *D_800F95E0, void *stack, OSPri priority,
                       sa_u8 mode, sa_u8 numFields);
extern void __scMain(void *arg);
void osCreateScheduler(OSSched *sc, void *stack, OSPri priority,
                       sa_u8 mode, sa_u8 numFields){
    sc->curRSPTask = 0;
    sc->curRDPTask = 0;
    sc->clientList = 0;
    sc->frameCount = 0;
    sc->audioListHead = 0;
    sc->gfxListHead = 0;
    sc->audioListTail = 0;
    sc->gfxListTail = 0;
  sc->doAudio = 0;
    sc->retraceMsg.type = 1;
    sc->prenmiMsg.type = 4;
    osCreateMesgQueue(&sc->interruptQ, sc->intBuf, 8);
    osCreateMesgQueue(&sc->cmdQ, sc->cmdMsgBuf, 8);
    osCreateViManager(254);
    osViSetMode(&func_800EE4F0[mode]);
    osViBlack(1);
    osSetEventMesg(4, &sc->interruptQ, (OSMesg)667);
    osSetEventMesg(9, &sc->interruptQ, (OSMesg)668);
    osSetEventMesg(14, &sc->interruptQ, (OSMesg)669);
    osViSetEvent(&sc->interruptQ, (OSMesg)666, numFields);
    osCreateThread(&sc->thread, 4, __scMain, (void *)sc, stack, priority);
    osStartThread(&sc->thread);
}
