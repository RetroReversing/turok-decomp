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
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    sa_s32 validCount;
    sa_s32 first;
    sa_s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
typedef sa_u32 OSIntMask;
extern OSIntMask func_8009D220(OSIntMask);
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
extern void func_8002B9B0(OSSched *s, OSScClient *c);
extern sa_u64 dram_stack[];
void func_8002B9B0(OSSched *D_800F95E0, OSScClient *c);
void func_8002B9B0(OSSched *D_800F95E0, OSScClient *c){
    OSScClient *client = D_800F95E0->clientList;
    OSScClient *prev = 0;
    OSIntMask mask;
    mask = func_8009D220(0x00000001);
    while (client != 0) {
        if (client == c) {
     if(prev)
  prev->next = c->next;
     else
  D_800F95E0->clientList = c->next;
            break;
        }
        prev = client;
        client = client->next;
    }
    func_8009D220(mask);
}
