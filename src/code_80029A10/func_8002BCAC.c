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
extern sa_s32 func_800A1180(OSMesgQueue *, OSMesg, sa_s32);
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
    sa_s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    sa_s32 (*dma)(sa_s32, sa_u32, void *, sa_u32);
    sa_s32 (*edma)(OSPiHandle *, sa_s32, sa_u32, void *, sa_u32);
} OSDevMgr;
extern void func_8009DD40(void *);
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
 unsigned char flag;
 unsigned char v[3];
} Tri;
typedef long Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;
typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;
typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;
typedef struct {
    Light l[2];
} LookAt;
typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;
typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;
typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;
typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;
typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;
typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;
typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;
typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;
typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;
typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long D_80130D78;
} Gsetcolor;
typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;
typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;
typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;
typedef Gloadtile Gsettilesize;
typedef Gloadtile Gloadtlut;
typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;
typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor D_80095060;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
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
typedef struct CSunFrameData_t
{
 sa_u64 m_DepthData[2];
 int m_DepthPos;
 int m_Visible,
     m_VisibleZ,
     align;
} CSunFrameData;
typedef union
{
 struct
 {
  short type;
 } gen;
 struct
 {
  short type;
 } done;
 OSScMsg app;
} GFXMsg;
typedef struct CFrameData_t
{
 Mtx m_mProjection;
 LookAt m_LookAt;
 CSunFrameData m_SunFrame;
 OSScTask m_Task,
       m_LineTask;
 GFXMsg m_Msg;
 void *m_pFrameBuffer;
 Gfx *m_pDisplayList,
       *m_pLineList;
 unsigned long m_DisplayListSize,
       m_LineListSize,
       m_nPredictFields;
 int m_DrawMap;
} CFrameData;
extern CFrameData *pFrameData;
extern sa_u64 dram_stack[];
extern unsigned long D_800F9D50;
extern unsigned long D_800F9D68;
extern unsigned long D_800F9D6C;
extern unsigned long D_800F9D70;
extern CFrameData *D_800F9D78[3];
extern void *D_800F9D84;
extern void *D_800F9D88;
extern void func_8002BCAC(OSSched *s);
extern void func_8002BF28(OSSched *s);
extern void func_8002C5D4(OSSched *s, OSScTask *t);
extern void func_8002C63C(OSSched *sc, OSScTask *sp, OSScTask *dp);
extern void func_8002C7A0(OSSched *s);
extern sa_s32 func_8002C7DC(OSSched *sc, OSScTask **sp, OSScTask **dp,
                             sa_s32 availRCP);
extern int D_800BA900 ;
void func_8002BCAC(OSSched *sc);
void func_8002BF28(OSSched *sc);
void func_8002C5D4(OSSched *sc, OSScTask *t);
void func_8002C63C(OSSched *sc, OSScTask *sp, OSScTask *dp);
extern void func_8002C7A0(OSSched *sc);
sa_s32 func_8002C7DC(OSSched *sc, OSScTask **sp, OSScTask **dp, sa_s32 availRCP);
/* Process a video retrace, advance frame buffers, schedule tasks, and notify clients. */
void func_8002BCAC(OSSched *sc){
 OSScTask *rspTask = 0;
 OSScClient *client;
 sa_s32 state;
 OSScTask *sp = 0;
 OSScTask *dp = 0;
 CFrameData *pFrameData;
 char buffer[50];
  sc->frameCount++;
 while (func_8009D0B0(&sc->cmdQ, (OSMesg*) &rspTask, 0) != -1)
  func_8002C5D4(sc, rspTask);
 D_800F9D50++;
                                             ;
 if (D_800F9D70)
 {
  D_800F9D50 = 0;
  D_800F9D70 = 0;
  D_800F9D84 = D_800F9D88;
  D_800F9D88 = 0;
 }
 if (D_800F9D68)
 {
  pFrameData = D_800F9D78[D_800F9D6C];
  if ((D_800F9D50 + 1) >= pFrameData->m_nPredictFields)
  {
   D_800F9D88 = pFrameData->m_pFrameBuffer;
   func_8009DD40(pFrameData->m_pFrameBuffer);
   D_800F9D68--;
   D_800F9D70++;
   if (++D_800F9D6C == 3)
    D_800F9D6C = 0;
  }
  else
  {
  }
 }
 else
 {
 }
 if (!sc->curRSPTask && !sc->curRDPTask && sc->gfxListHead)
 {
  if ( (sc->gfxListHead->list.t.type == 1)
    && (sc->gfxListHead->state == (0x0010 | 0x0020 | 0x0002)) )
  {
   sc->gfxListHead->state &= ~(0x0010 | 0x0020);
   sc->curRSPTask = sc->gfxListHead;
   sc->gfxListHead = sc->gfxListHead->next;
   if (!sc->gfxListHead)
    sc->gfxListTail = 0;
   func_8002BF28(sc);
  }
 }
                        ;
 if (++D_800BA900 == 160)
 {
  *((char*)(0)) = 0;
 }
 if (sc->doAudio && sc->curRSPTask)
 {
  func_8002C7A0(sc);
 }
 else
 {
  state = ((sc->curRSPTask == 0) << 1) | (sc->curRDPTask == 0);
  if (func_8002C7DC (sc, &sp, &dp, state) != state)
   func_8002C63C(sc, sp, dp);
 }
 for (client=sc->clientList; client!=0; client=client->next)
  func_800A1180(client->msgQ, (OSMesg) &sc->retraceMsg, 0);
}
