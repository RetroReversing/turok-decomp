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
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    sa_s32 validCount;
    sa_s32 first;
    sa_s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
extern sa_s32 func_8009D0B0(OSMesgQueue *, OSMesg *, sa_s32);
typedef struct {
    sa_u32 errStatus;
    void *dramAddr;
    void *C2Addr;
    sa_u32 sectorSize;
    sa_u32 C1ErrNum;
    sa_u32 C1ErrSector[4];
} __OSBlockInfo;
typedef struct {
    sa_u32 cmdType;
    sa_u16 transferMode;
    sa_u16 blockNum;
    sa_s32 sectorNum;
    sa_u32 devAddr;
    sa_u32 bmCtlShadow;
    sa_u32 seqCtlShadow;
    __OSBlockInfo block[2];
} __OSTranxInfo;
typedef struct OSPiHandle_s {
    struct OSPiHandle_s *next;
    sa_u8 type;
    sa_u8 latency;
    sa_u8 pageSize;
    sa_u8 relDuration;
    sa_u8 pulse;
    sa_u8 domain;
    sa_u32 baseAddress;
    sa_u32 speed;
    __OSTranxInfo transferInfo;
} OSPiHandle;
typedef struct {
    sa_u16 type;
    sa_u8 pri;
    sa_u8 status;
    OSMesgQueue *retQueue;
} OSIoMesgHdr;
typedef struct {
    OSIoMesgHdr hdr;
    void *dramAddr;
    sa_u32 devAddr;
    sa_u32 size;
    OSPiHandle *piHandle;
} OSIoMesg;
extern sa_s32 func_800A1810(OSIoMesg *, sa_s32, sa_s32, sa_u32, void *, sa_u32, OSMesgQueue *);
extern void func_800A1760(void *, sa_s32);
extern void func_800A16E0(void *, sa_s32);
typedef ROMAddress;
extern sa_u32 D_80270800[];
extern OSMesgQueue D_800F9BC8;
extern OSIoMesg D_800F9D38;
extern void func_8002D020(void *pRAM, ROMAddress *rpROM, unsigned long Length);
void func_8002D020(void *pRAM, ROMAddress *rpROM, unsigned long Length);
void func_8002D020(void *pRAM, ROMAddress *rpROM, unsigned long Length){
 unsigned long transferLength,
   remainLength;
 func_800A16E0(pRAM, Length);
 func_800A1760(D_80270800, 0x16A000);
 remainLength = Length;
 while (remainLength)
 {
  transferLength = ((8192) < (remainLength) ? (8192) : (remainLength));
  func_800A1810(&D_800F9D38, 0, 0,
       (unsigned long)rpROM + Length - remainLength,
       (void*) ((unsigned long) pRAM + Length - remainLength),
       transferLength,
       &D_800F9BC8);
  func_8009D0B0(&D_800F9BC8, ((void*)0), 1);
  remainLength -= transferLength;
 }
 func_800A1760(pRAM, Length);
}
