#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
typedef short sa_s16;
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
    sa_s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    sa_s32 (*dma)(sa_s32, sa_u32, void *, sa_u32);
    sa_s32 (*edma)(OSPiHandle *, sa_s32, sa_u32, void *, sa_u32);
} OSDevMgr;
extern sa_u32 func_800A4F20(void);
extern sa_s32 func_800A4FB0(void *, sa_u32);
typedef sa_u64 OSTime;
extern sa_u32 func_800A4F30(void *);
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
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Aadpcm;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Apolef;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvelope;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int dmem:16;
 unsigned int pad2:16;
 unsigned int count:16;
} Aclearbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int pad2:16;
 unsigned int inL:16;
        unsigned int inR:16;
} Ainterleave;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Aloadbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvmixer;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int dmemi:16;
 unsigned int dmemo:16;
} Amixer;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pitch:16;
 unsigned int addr;
} Aresample;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Areverb;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Asavebuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int pad2:2;
 unsigned int number:4;
 unsigned int base:24;
} Asegment;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int dmemin:16;
 unsigned int dmemout:16;
 unsigned int count:16;
} Asetbuff;
typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int vol:16;
 unsigned int voltgt:16;
 unsigned int volrate:16;
} Asetvol;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int dmemin:16;
    unsigned int dmemout:16;
    unsigned int count:16;
} Admemmove;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int count:16;
    unsigned int addr;
} Aloadadpcm;
typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int pad2:16;
    unsigned int addr;
} Asetloop;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Awords;
typedef union {
 Awords words;
 Aadpcm adpcm;
        Apolef polef;
 Aclearbuff clearbuff;
 Aenvelope envelope;
        Ainterleave interleave;
 Aloadbuff loadbuff;
        Aenvmixer envmixer;
 Aresample resample;
 Areverb reverb;
 Asavebuff savebuff;
 Asegment segment;
 Asetbuff setbuff;
 Asetvol setvol;
        Admemmove dmemmove;
        Aloadadpcm loadadpcm;
        Amixer mixer;
        Asetloop setloop;
        long long int force_union_align;
} Acmd;
typedef sa_s32 ALMicroTime;
typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;
typedef sa_s32 (*ALDMAproc)(sa_s32 addr, sa_s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);
typedef struct {
    sa_u8 *base;
    sa_u8 *cur;
    sa_s32 len;
    sa_s32 count;
} ALHeap;
typedef ALMicroTime (*ALVoiceHandler)(void *);
typedef struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    ALVoiceHandler handler;
    ALMicroTime callTime;
    sa_s32 samplesLeft;
} ALPlayer;
typedef struct {
    ALPlayer *head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    sa_s32 paramSamples;
    sa_s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;
    struct ALParam_s *paramList;
    struct ALMainBus_s *mainBus;
    struct ALAuxBus_s *auxBus;
    struct ALFilter_s *outputFilter;
    sa_s32 numPVoices;
    sa_s32 maxAuxBusses;
    sa_s32 outputRate;
    sa_s32 maxOutSamples;
} ALSynth;
typedef struct {
    ALSynth drvr;
} ALGlobals;
extern Acmd *func_800A51A8(Acmd *cmdList, sa_s32 *cmdLen, sa_s16 *outBuf, sa_s32 outLen);
extern long long int D_800B2380[], D_800B2450[];
extern long long int D_800B5B70[], aspMainTextEnd[];
extern long long int D_800F8E10[], aspMainDataEnd[];
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
extern sa_u64 dram_stack[];
extern void func_8002BB80(OSSched *D_800F95E0, OSScTask *pTask);
extern void func_8008A820(void);
typedef union {
    struct
 {
        short type;
    } gen;
    struct {
        short type;
        struct AudioInfo_s *info;
    } done;
    OSScMsg app;
} AudioMsg;
typedef struct AudioInfo_s
{
    short *data;
    short frameSamples;
    OSScTask task;
    AudioMsg msg;
} AudioInfo;
typedef struct
{
    Acmd *ACMDList[2];
    AudioInfo *audioInfo[3];
    OSThread thread;
    OSMesgQueue audioFrameMsgQ;
    OSMesg audioFrameMsgBuf[64];
    OSMesgQueue audioReplyMsgQ;
    OSMesg audioReplyMsgBuf[64];
    ALGlobals g;
} AMAudioMgr;
extern OSSched D_800F95E0;
extern AMAudioMgr D_8012F0D0;
extern sa_u32 D_800ED458 ;
extern sa_u32 D_8012FA28;
extern sa_u32 D_8012FA2C;
extern sa_u32 func_8008D7C8(AudioInfo *, AudioInfo *);
extern void func_8008DB6C(void);
extern sa_u32 func_8008D7C8(AudioInfo *info, AudioInfo *lastInfo);
extern void func_8008DB6C(void);
/* Build and queue the audio synthesis task for the next frame. */
sa_u32 func_8008D7C8(AudioInfo *info, AudioInfo *lastInfo){
    OSScTask *t;
  sa_s16 *audioPtr;
    Acmd *cmdp;
    sa_s32 cmdLen;
  int check = 0;
    func_8008DB6C();
    audioPtr = (sa_s16 *) func_800A4F30(info->data);
 if (lastInfo)
 {
  check = func_800A4FB0(lastInfo->data, lastInfo->frameSamples<<2);
  if (!(func_800A4F20() & (1 << 31)))
  {
                                                ;
  }
  if (check < 0)
  {
                                                          ;
  }
 }
  info->frameSamples = D_8012FA2C;
    if(info->frameSamples < D_8012FA28)
        info->frameSamples = D_8012FA28;
 cmdp = func_800A51A8(D_8012F0D0.ACMDList[D_800ED458], &cmdLen, audioPtr,
       info->frameSamples);
                              ;
    if(cmdLen == 0)
        return 0;
   t = &info->task;
   t->next = 0;
   t->msgQ = &D_8012F0D0.audioReplyMsgQ;
   t->msg = (OSMesg)&info->msg;
   t->flags = 0x0002;
   t->list.t.data_ptr = (sa_u64 *) D_8012F0D0.ACMDList[D_800ED458];
   t->list.t.data_size = (cmdp - D_8012F0D0.ACMDList[D_800ED458]) * sizeof(Acmd);
   t->list.t.type = 2;
   t->list.t.ucode_boot = (sa_u64 *)D_800B2380;
   t->list.t.ucode_boot_size =
        ((int) D_800B2450 - (int) D_800B2380);
 t->list.t.flags = 0;
   t->list.t.ucode = (sa_u64 *) D_800B5B70;
   t->list.t.ucode_data = (sa_u64 *) D_800F8E10;
   t->list.t.ucode_data_size = 2048;
   t->list.t.yield_data_ptr = 0;
   t->list.t.yield_data_size = 0;
 t->list.t.dram_stack = 0;
 t->list.t.dram_stack_size = 0;
 t->list.t.output_buff = 0;
 t->list.t.output_buff_size = 0;
 func_8002BB80(&D_800F95E0, t);
    D_800ED458 ^= 1;
  func_8008A820();
  return 1;
}
