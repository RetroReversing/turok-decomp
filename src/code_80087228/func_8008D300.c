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
extern void func_8009E000(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
extern void func_8009E150(OSThread *);
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
extern sa_s32 func_800A4D00(sa_u32);
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
extern void D_800A4E90(ALLink *element, ALLink *after);
typedef sa_s32 (*ALDMAproc)(sa_s32 addr, sa_s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);
typedef struct {
    sa_u8 *base;
    sa_u8 *cur;
    sa_s32 len;
    sa_s32 count;
} ALHeap;
extern void *D_800A2100(sa_u8 *file, sa_s32 line, ALHeap *D_8012AF18, sa_s32 num, sa_s32 size);
typedef sa_u8 ALFxId;
typedef ALMicroTime (*ALVoiceHandler)(void *);
typedef struct {
    sa_s32 maxVVoices;
    sa_s32 maxPVoices;
    sa_s32 maxUpdates;
    sa_s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    sa_s32 outputRate;
    ALFxId fxType;
    sa_s32 *D_800ECEC4;
} ALSynConfig;
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
extern void D_800A4EEC(ALGlobals *glob, ALSynConfig *c);
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
extern sa_u64 dram_stack[];
extern sa_u64 D_8014B660[];
typedef struct
{
    sa_u32 outputRate;
    sa_u32 framesPerField;
    sa_u32 maxACMDSize;
} amConfig;
extern void func_8008D300(ALSynConfig *c, OSPri priority, amConfig *amc);
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
extern AMAudioMgr D_8012F0D0;
extern AMDMAState D_8012F518;
extern AMDMABuffer D_8012F528[64];
extern sa_u32 D_8012FA28;
extern sa_u32 D_8012FA2C;
extern sa_u32 D_8012FA30;
extern sa_u32 D_8012FA34;
extern AudioMsg D_8012FA38;
extern OSMesgQueue D_80130058;
extern OSMesg D_80130070[64];
extern void func_8008D620(void *arg);
extern ALDMAproc func_8008DB34(AMDMAState **state);
void func_8008D300(ALSynConfig *c, OSPri pri, amConfig *amc);
extern void func_8008D620(void *arg);
ALDMAproc func_8008DB34(AMDMAState **state);
void func_8008D300(ALSynConfig *c, OSPri pri, amConfig *amc){
    /* Configure audio frame sizes, allocate DMA and command buffers, then start the audio thread. */
    sa_u32 i;
    sa_f32 fsize;
    D_8012F518.initialized = 0;
  D_8012FA38.gen.type = (4 + 3);
    c->dmaproc = func_8008DB34;
    c->outputRate = func_800A4D00(amc->outputRate);
    fsize = (sa_f32) amc->framesPerField * c->outputRate / (sa_f32) 60;
    D_8012FA2C = (sa_s32) fsize;
    if (D_8012FA2C < fsize)
        D_8012FA2C++;
    if (D_8012FA2C & 0xf)
        D_8012FA2C = (D_8012FA2C & ~0xf) + 0x10;
    D_8012FA28 = D_8012FA2C - 16;
    D_8012FA30 = D_8012FA2C + 80 + 16;
    D_800A4EEC(&D_8012F0D0.g, c);
    D_8012F528[0].node.prev = 0;
    D_8012F528[0].node.next = 0;
    for (i=0; i<64 -1; i++)
    {
        D_800A4E90((ALLink*)&D_8012F528[i+1],(ALLink*)&D_8012F528[i]);
        D_8012F528[i].ptr = D_800A2100(0, 0,(c->heap),(1),(0x800));
    }
    D_8012F528[i].ptr = D_800A2100(0, 0,(c->heap),(1),(0x800));
    for(i=0;i<2;i++)
        D_8012F0D0.ACMDList[i] = (Acmd*)D_800A2100(0, 0,(c->heap),(1),(amc->maxACMDSize * sizeof(Acmd)));
    D_8012FA34 = amc->maxACMDSize;
    for (i = 0; i < 3; i++)
    {
        D_8012F0D0.audioInfo[i] = (AudioInfo *)D_800A2100(0, 0,(c->heap),(1),(sizeof(AudioInfo)));
        D_8012F0D0.audioInfo[i]->msg.done.type = 2;
        D_8012F0D0.audioInfo[i]->msg.done.info = D_8012F0D0.audioInfo[i];
        D_8012F0D0.audioInfo[i]->data = D_800A2100(0, 0,(c->heap),(1),(4*D_8012FA30));
    }
    func_8009E4A0(&D_8012F0D0.audioReplyMsgQ, D_8012F0D0.audioReplyMsgBuf, 64);
    func_8009E4A0(&D_8012F0D0.audioFrameMsgQ, D_8012F0D0.audioFrameMsgBuf, 64);
    func_8009E4A0(&D_80130058, D_80130070, 64);
 func_8009D020(6, &D_8012F0D0.audioFrameMsgQ, &D_8012FA38);
    func_8009E000(&D_8012F0D0.thread, 3, func_8008D620, 0,
                   (void *)(D_8014B660+0x4000/sizeof(sa_u64)), pri);
    func_8009E150(&D_8012F0D0.thread);
}
