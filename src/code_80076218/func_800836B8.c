#include "common.h"

extern const double D_800F5ED0;
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
  unsigned long color;
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
 Gsetcolor setcolor;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;
enum BARREL_MODES
{
 BARREL_UP,
 BARREL_DOWN
} ;
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
extern void func_800836B8(CBarrel *pThis) ;
void func_800836B8(CBarrel *pThis);
void func_800836B8(CBarrel *pThis){
 pThis->m_SelectedAngle = pThis->m_Selected * pThis->m_DisplayStep ;
 if (pThis->m_SelectedAngle != pThis->m_CurrentAngle)
 {
  pThis->m_delta = pThis->m_SelectedAngle - pThis->m_CurrentAngle ;
  if (pThis->m_Direction == BARREL_DOWN)
  {
   while (pThis->m_delta < 0)
    pThis->m_delta += (pThis->m_Buffersize * pThis->m_DisplayStep) ;
  }
  else
  {
   while (pThis->m_delta > 0)
    pThis->m_delta -= (pThis->m_Buffersize * pThis->m_DisplayStep) ;
  }
  pThis->m_AngleAccel = pThis->m_delta / pThis->m_SpinSpeed ;
  pThis->m_CurrentAngle += pThis->m_AngleAccel ;
  pThis->m_ViewAngleOffset += pThis->m_AngleAccel ;
  if (pThis->m_CurrentAngle < 0)
   pThis->m_CurrentAngle += (pThis->m_Buffersize * pThis->m_DisplayStep) ;
  else if (pThis->m_CurrentAngle > (pThis->m_Buffersize * pThis->m_DisplayStep))
   pThis->m_CurrentAngle -= (pThis->m_Buffersize * pThis->m_DisplayStep) ;
  if ((((pThis->m_delta) < 0) ? -(pThis->m_delta) : (pThis->m_delta)) < D_800F5ED0)
  {
   pThis->m_CurrentAngle = pThis->m_SelectedAngle ;
   pThis->m_Current = pThis->m_Selected ;
   pThis->m_AngleAccel = 0;
   pThis->m_ViewAngleOffset = 0;
  }
 }
 while (pThis->m_ViewAngleOffset >= pThis->m_DisplayStep)
 {
  pThis->m_ViewAngleOffset -= pThis->m_DisplayStep ;
  pThis->m_Current++ ;
  if (pThis->m_Current >= pThis->m_Buffersize)
   pThis->m_Current = 0 ;
 }
 while (pThis->m_ViewAngleOffset <= -pThis->m_DisplayStep)
 {
  pThis->m_ViewAngleOffset += pThis->m_DisplayStep ;
  pThis->m_Current-- ;
  if (pThis->m_Current < 0)
   pThis->m_Current = pThis->m_Buffersize-1 ;
 }
}
