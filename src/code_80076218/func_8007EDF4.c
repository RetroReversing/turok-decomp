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
    sa_s32 active;
    OSThread *thread;
    OSMesgQueue *cmdQueue;
    OSMesgQueue *evtQueue;
    OSMesgQueue *acsQueue;
    sa_s32 (*dma)(sa_s32, sa_u32, void *, sa_u32);
    sa_s32 (*edma)(OSPiHandle *, sa_s32, sa_u32, void *, sa_u32);
} OSDevMgr;
typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;
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
extern float func_8009E630(float angle);
extern unsigned long D_800B6AF0;
typedef struct C16BitGraphic_t
{
 unsigned short m_BlocksAcross ;
 unsigned short m_BlocksDown ;
 unsigned short m_Width ;
 unsigned short m_Height ;
 unsigned char m_pPart[1] ;
} C16BitGraphic ;
extern void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale) ;
typedef struct s_CBarrel
{
 int m_Current ;
 int m_Selected ;
 float m_CurrentAngle ;
 float m_SelectedAngle ;
 float m_delta ;
 float m_AngleAccel ;
 float m_ViewAngleOffset ;
 int m_Display ;
 float m_DisplayStep ;
 float m_SpinSpeed ;
 int m_Buffersize ;
 int m_X,
   m_Y,
   m_XStep,
   m_YStep ;
 int m_Direction ;
 void(*InitGraphics)(Gfx **ppDLP) ;
 void(*DrawItem)(Gfx **ppDLP, int index, float x, float y, float xscale, float yscale, int alpha) ;
} CBarrel ;
extern unsigned long D_800B6AF0;
typedef struct s_WeaponInfo
{
 int XOff, YOff ;
 void *Icon ;
} t_WeaponInfo ;
extern t_WeaponInfo D_800BF190[45] ;
extern CBarrel D_80129090 ;
extern int D_801290E8[15] ;
void func_8007EDF4(Gfx **ppDLP, int index, float x, float y, float xscale, float yscale, int alpha);
void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale);
void func_8007EDF4(Gfx **ppDLP, int index, float x, float y, float xscale, float yscale, int alpha){
 C16BitGraphic *ppIcon ;
 int xoff, yoff ;
 float mod ;
 mod = 64.0*func_8009E630((float)D_800B6AF0/2.0) ;
 if (D_80129090.m_Selected == index)
 {
  { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfb) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)(192+mod) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(192+mod) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(192+mod) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (0))))); };
 }
 else
 {
  { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfb) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)(alpha/2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(alpha/2) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(alpha/2) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(alpha) & ((0x01 << (8)) - 1)) << (0))))); };
 }
 ppIcon = (C16BitGraphic *)D_800BF190[D_801290E8[index]].Icon ;
  xoff = D_800BF190[D_801290E8[index]].XOff ;
  yoff = D_800BF190[D_801290E8[index]].YOff ;
  func_80082FA0(ppDLP,
            ppIcon,
            x+xoff, y+yoff,
            xscale, yscale) ;
}
