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
extern void COnScreen__InitBoxDraw(Gfx **ppDLP) ;
extern void COnScreen__DrawHilightBox(Gfx **ppDLP, signed long x1, signed long y1, signed long x2, signed long y2, signed long thick, int invert,
           unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) ;
extern void D_800814AC(Gfx **ppDLP,
         char *String,
         int nX, int nY,
         int Opacity, int centre, int shadow) ;
extern void D_800808F8(Gfx **ppDLP, int tr, int tg, int tb, int br, int bg, int bb) ;
extern void D_8008092C(float XScale, float YScale) ;
extern void func_80080B0C(Gfx **ppDLP) ;
extern void func_80080BF0(Gfx **ppDLP) ;
extern sa_s32 D_80119AB8 ;
typedef struct s_File
{
 int index ;
 char string[20] ;
 int pages ;
} t_File ;
extern t_File D_80119AC8[] ;
enum SaveMemorySelections
{
 SAVEMEMORY_SAVE,
 SAVEMEMORY_DELETE,
 SAVEMEMORY_SHOWALL,
 SAVEMEMORY_EXIT,
 SAVEMEMORY_END_SELECTION
} ;
typedef struct CSave_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed short m_SaveType ;
 sa_s32 m_Side ;
 signed long m_ASelection ;
 signed long m_BSelection ;
 signed long m_FirstVisible ;
 signed long m_MaxVisible ;
 int m_ShowAll ;
 signed long m_Selection ;
} CSave ;
extern void CPause__InitPolygon(Gfx **ppDLP) ;
extern void CPause__DrawBar(Gfx **ppDLP, float x, float y, float w, float h, float a) ;
extern char D_800B7EA4[1] ;
extern char D_800B7F58[1] ;
extern char *D_800B8174[4];
extern void func_8000D6BC(CSave *pThis, Gfx **ppDLP) ;
void func_8000D6BC(CSave *pThis, Gfx **ppDLP);
void func_8000D6BC(CSave *pThis, Gfx **ppDLP){
 int i, y ;
 COnScreen__InitBoxDraw(ppDLP) ;
 COnScreen__DrawHilightBox(ppDLP,
        (20 +120), 64,
        (20 +120)+(320-(20 +120)-20), 64 +150,
        2, 0,
        50,30,30, 200 * pThis->m_Alpha) ;
 COnScreen__DrawHilightBox(ppDLP,
        20, 64,
        20 +120, 64 +150,
        2, 0,
        30,30,50, 200 * pThis->m_Alpha) ;
 if (pThis->m_Side == 0)
 {
  y = pThis->m_BSelection *18 ;
  COnScreen__DrawHilightBox(ppDLP,
        20 +4, 64 +7+y,
        20 +120 -4, 64 +7+y+18,
        1, 0,
        30,30,50, 150 * pThis->m_Alpha) ;
  CPause__InitPolygon(ppDLP) ;
  y = (pThis->m_ASelection - pThis->m_FirstVisible) *8 ;
  CPause__DrawBar(ppDLP, (20 +120)+2, 64 +8+y,
       (320-(20 +120)-20)-4, 8, pThis->m_Alpha) ;
 }
 else
 {
  y = (pThis->m_ASelection - pThis->m_FirstVisible) *8 ;
  COnScreen__DrawHilightBox(ppDLP,
        (20 +120)+4, 64 +6+y,
        (20 +120)+(320-(20 +120)-20)-4, 64 +6+y+11,
        1, 0,
        50,30,30, 150 * pThis->m_Alpha) ;
  CPause__InitPolygon(ppDLP) ;
  y = pThis->m_BSelection *18 ;
  CPause__DrawBar(ppDLP, 20 +2, 64 +8+y,
       120 -4, 18, pThis->m_Alpha) ;
 }
 COnScreen__InitBoxDraw(ppDLP) ;
 COnScreen__DrawHilightBox(ppDLP,
       ((320/2) - ((16*14)/2)), 32,
       ((320/2) - ((16*14)/2))+(16*14), 32 +26,
       1, 0,
       50,10,50, 200 * pThis->m_Alpha) ;
 COnScreen__InitFontDraw(ppDLP) ;
 D_8008092C(1.0, 1.0) ;
 D_800808F8(ppDLP, 50, 255, 50, 255, 255, 50) ;
 D_800814AC(ppDLP,
         D_800B7EA4,
         320/2, 32 +4,
         (int)(255 * pThis->m_Alpha), 1, 1) ;
 func_80080B0C(ppDLP) ;
 y = 0 ;
 if (pThis->m_ASelection==0)
   D_800808F8(ppDLP, 255, 255, 255, 255, 0, 255) ;
 D_800814AC(ppDLP,
         D_800B7F58,
         (20 +120)+8, 64 +8+(y*8),
         (int)(255 * pThis->m_Alpha), 0, 0) ;
 y++ ;
 func_80080BF0(ppDLP) ;
 D_8008092C(1.0, 1.0) ;
 for (i=0; i<D_80119AB8; i++)
 {
  if (i==(pThis->m_ASelection-1))
   D_800808F8(ppDLP, 255, 255, 255, 255, 0, 255) ;
  else
   D_800808F8(ppDLP, 150, 150, 150, 150, 0, 150) ;
  D_800814AC(ppDLP,
          D_80119AC8[i].string,
          (20 +120)+8, 64 +8+(y*8),
          (int)(255 * pThis->m_Alpha), 0, 0) ;
  y++ ;
 }
 COnScreen__InitFontDraw(ppDLP) ;
 for (i=0; i<SAVEMEMORY_END_SELECTION; i++)
 {
  if (i==pThis->m_BSelection)
   D_800808F8(ppDLP, 200*1.25, 200*1.25, 138*1.25, 86*1.25, 71*1.25, 47*1.25) ;
  else
   D_800808F8(ppDLP, 200*.9, 200*.9, 138*.9, 86*.9, 71*.9, 47*.9) ;
  D_800814AC(ppDLP,
          D_800B8174[i],
          20 +8, 64 +8 + (i*18),
          (int)(255 * pThis->m_Alpha), 0, 1) ;
 }
}
