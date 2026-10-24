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
extern sa_u32 func_800A4F30(void *);
typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;
extern void func_800A4E60(ALLink *element);
extern void D_800A4E90(ALLink *element, ALLink *after);
typedef struct
{
    ALLink node;
    sa_u32 startAddr;
    sa_u32 lastFrame;
    char *ptr;
} AMDMABuffer;
typedef struct
{
    sa_u8 initialized;
    AMDMABuffer *firstUsed;
    AMDMABuffer *firstFree;
} AMDMAState;
extern AMDMAState D_8012F518;
extern sa_u32 D_800ED450 ;
extern sa_u32 D_800ED454 ;
extern OSIoMesg D_8012FA58[64];
extern OSMesgQueue D_80130058;
extern sa_s32 func_8008D9B8(sa_s32 addr, sa_s32 len, void *state);
sa_s32 func_8008D9B8(sa_s32 addr, sa_s32 len, void *state);
sa_s32 func_8008D9B8(sa_s32 addr, sa_s32 len, void *state){
    void *foundBuffer;
    sa_s32 delta, addrEnd, buffEnd;
    AMDMABuffer *dmaPtr, *lastDmaPtr;
    lastDmaPtr = 0;
    dmaPtr = D_8012F518.firstUsed;
    addrEnd = addr+len;
    while(dmaPtr)
    {
        buffEnd = dmaPtr->startAddr + 0x800;
        if(dmaPtr->startAddr > addr)
            break;
        else if(addrEnd <= buffEnd)
        {
            dmaPtr->lastFrame = D_800ED450;
            foundBuffer = dmaPtr->ptr + addr - dmaPtr->startAddr;
            return (int) func_800A4F30(foundBuffer);
        }
        lastDmaPtr = dmaPtr;
        dmaPtr = (AMDMABuffer*)dmaPtr->node.next;
    }
    dmaPtr = D_8012F518.firstFree;
                ;
    D_8012F518.firstFree = (AMDMABuffer*)dmaPtr->node.next;
    func_800A4E60((ALLink*)dmaPtr);
    if(lastDmaPtr)
    {
        D_800A4E90((ALLink*)dmaPtr,(ALLink*)lastDmaPtr);
    }
    else if(D_8012F518.firstUsed)
    {
        lastDmaPtr = D_8012F518.firstUsed;
        D_8012F518.firstUsed = dmaPtr;
        dmaPtr->node.next = (ALLink*)lastDmaPtr;
        dmaPtr->node.prev = 0;
        lastDmaPtr->node.prev = (ALLink*)dmaPtr;
    }
    else
    {
        D_8012F518.firstUsed = dmaPtr;
        dmaPtr->node.next = 0;
        dmaPtr->node.prev = 0;
    }
    foundBuffer = dmaPtr->ptr;
    delta = addr & 0x1;
    addr -= delta;
    dmaPtr->startAddr = addr;
    dmaPtr->lastFrame = D_800ED450;
                                   ;
 func_800A1810(&D_8012FA58[D_800ED454++], 1, 0,
                 (sa_u32)addr, foundBuffer, 0x800, &D_80130058);
    return (int) func_800A4F30(foundBuffer) + delta;
}
