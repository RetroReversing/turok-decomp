#include "common.h"

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
typedef struct s_C16BitPart
{
 unsigned long m_BlockWidth ;
 unsigned long m_BlockHeight ;
 unsigned char m_pData[1] ;
} C16BitPart ;
typedef struct C16BitGraphic_t
{
 unsigned short m_BlocksAcross ;
 unsigned short m_BlocksDown ;
 unsigned short m_Width ;
 unsigned short m_Height ;
 unsigned char m_pPart[1] ;
} C16BitGraphic ;
extern void func_80081F58(Gfx **ppDLP,
           void *pTexture,
           void *pOpacity,
           float XPos, float YPos,
           int TextureWidth, int TextureHeight,
           float XScale, float YScale) ;
extern void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale) ;
void func_80081F58(Gfx **ppDLP,
            void *pTexture,
            void *pOpacity,
            float XPos, float YPos,
            int TextureWidth, int TextureHeight,
            float XScale, float YScale);
void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale);
void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale){
 /* Draw each 16-bit graphic block at the requested scale. */
 float curx, XCount, YCount ;
 unsigned long width, height ;
 void *image, *opacity ;
 unsigned char *Part ;
 Part = (unsigned char *)Graphic->m_pPart ;
 YCount = Graphic->m_BlocksDown;
 while(YCount--)
 {
  XCount = Graphic->m_BlocksAcross ;
  curx = X ;
  while(XCount--)
  {
   width = ((C16BitPart *)Part)->m_BlockWidth ;
   height = ((C16BitPart *)Part)->m_BlockHeight ;
   image = ((C16BitPart *)Part)->m_pData ;
   opacity = ((C16BitPart *)Part)->m_pData + (width*height*2);
   func_80081F58(ppDLP, image, opacity,
              curx, Y,
              width, height,
              XScale, YScale) ;
   curx += width * XScale ;
   Part += (width*height*2) + (width*height/2) ;
   Part += 8 ;
  }
  Y += height * YScale ;
 }
}
