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
extern void func_80081B20(Gfx **ppDLP,
          void *pTexture,
          void *pOpacity,
          int XPos, int YPos,
          int TextureWidth, int TextureHeight) ;
void func_80081B20(Gfx **ppDLP,
          void *pTexture,
          void *pOpacity,
          int XPos, int YPos,
          int TextureWidth, int TextureHeight);
void func_80081B20(Gfx **ppDLP,
          void *pTexture,
          void *pOpacity,
          int XPos, int YPos,
          int TextureWidth, int TextureHeight){
                                  ;
                                  ;
 { { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(4) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((1)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (unsigned int)((pOpacity)); }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(4) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(256) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf3) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((((((TextureWidth)*(TextureHeight)+3)>>2)-1) < (2047) ? ((((TextureWidth)*(TextureHeight)+3)>>2)-1) : (2047)))) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((((1 << 11) + ((1) > (((TextureWidth)/16)) ? (1) : (((TextureWidth)/16))) - 1) / ((1) > (((TextureWidth)/16)) ? (1) : (((TextureWidth)/16))))) & ((0x01 << (12)) - 1)) << (0)))); }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(4) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)(((((TextureWidth)>>1)+7)>>3)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(256) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((TextureWidth)-1) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((TextureHeight)-1) << 2) & ((0x01 << (12)) - 1)) << (0))); } };
  { { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xfd) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((1)-1) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = (unsigned int)((pTexture)); }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe6) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf3) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(7) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((((((TextureWidth)*(TextureHeight) + 0) >> 0) -1) < (2047) ? ((((TextureWidth)*(TextureHeight) + 0) >> 0) -1) : (2047)))) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((((1 << 11) + ((1) > (((TextureWidth)*(2)/8)) ? (1) : (((TextureWidth)*(2)/8))) - 1) / ((1) > (((TextureWidth)*(2)/8)) ? (1) : (((TextureWidth)*(2)/8))))) & ((0x01 << (12)) - 1)) << (0)))); }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(2) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((((TextureWidth) * 2)+7)>>3) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); }; { Gfx *_g = (Gfx *)(((*ppDLP)++)); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((TextureWidth)-1) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((TextureHeight)-1) << 2) & ((0x01 << (12)) - 1)) << (0))); } };
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf5) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(4) & ((0x01 << (3)) - 1)) << (21))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (19))) | ((unsigned int) (((unsigned int)((TextureWidth/16)) & ((0x01 << (9)) - 1)) << (9))) | ((unsigned int) (((unsigned int)(256) & ((0x01 << (9)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(1) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (20))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (18))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (14))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (10))) |((unsigned int) (((unsigned int)(0) & ((0x01 << (2)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (4))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (4)) - 1)) << (0))); };
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xf2) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (12)) - 1)) << (0))); _g->words.w1 = ((unsigned int) (((unsigned int)(1) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((TextureWidth-1) << 2) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((TextureHeight-1) << 2) & ((0x01 << (12)) - 1)) << (0))); };
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xe4) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(((XPos + TextureWidth) << 2)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)(((YPos + TextureHeight) << 2)) & ((0x01 << (12)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(0) & ((0x01 << (3)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((XPos << 2)) & ((0x01 << (12)) - 1)) << (12))) | ((unsigned int) (((unsigned int)((YPos << 2)) & ((0x01 << (12)) - 1)) << (0)))); { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -11))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(0) & ((0x01 << (16)) - 1)) << (0))))); }; { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(((-65 -12))) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = (unsigned int)((((unsigned int) (((unsigned int)((1 << 10)) & ((0x01 << (16)) - 1)) << (16))) | ((unsigned int) (((unsigned int)((1 << 10)) & ((0x01 << (16)) - 1)) << (0))))); };};
}
