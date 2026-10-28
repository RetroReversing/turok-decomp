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
extern void func_8007FAE0(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2, signed long Thickness,
           unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) ;
void func_8007FAE0(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2, signed long Thickness,
           unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha);
/* Draw a colored outline with four filled rectangles. */
void func_8007FAE0(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2, signed long Thickness,
           unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha){
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = ((unsigned int) (((unsigned int)(0xe7) & ((0x01 << (8)) - 1)) << (24))); _g->words.w1 = 0; };
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xfa) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(255) & ((0x01 << (8)) - 1)) << (0)))); _g->words.w1 = (((unsigned int) (((unsigned int)(Red) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)(Green) & ((0x01 << (8)) - 1)) << (16))) | ((unsigned int) (((unsigned int)(Blue) & ((0x01 << (8)) - 1)) << (8))) | ((unsigned int) (((unsigned int)(Alpha) & ((0x01 << (8)) - 1)) << (0)))); };
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf6) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((X2)) > (0) ? ((X2)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y1+Thickness)) > (0) ? ((Y1+Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); _g->words.w1 = (((unsigned int) (((unsigned int)((((X1)) > (0) ? ((X1)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y1)) > (0) ? ((Y1)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); } ;
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf6) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((X2)) > (0) ? ((X2)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y2)) > (0) ? ((Y2)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); _g->words.w1 = (((unsigned int) (((unsigned int)((((X1)) > (0) ? ((X1)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y2-Thickness)) > (0) ? ((Y2-Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); } ;
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf6) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((X1+Thickness)) > (0) ? ((X1+Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y2-Thickness)) > (0) ? ((Y2-Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); _g->words.w1 = (((unsigned int) (((unsigned int)((((X1)) > (0) ? ((X1)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y1+Thickness)) > (0) ? ((Y1+Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); } ;
 { Gfx *_g = (Gfx *)((*ppDLP)++); _g->words.w0 = (((unsigned int) (((unsigned int)(0xf6) & ((0x01 << (8)) - 1)) << (24))) | ((unsigned int) (((unsigned int)((((X2)) > (0) ? ((X2)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y2-Thickness)) > (0) ? ((Y2-Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); _g->words.w1 = (((unsigned int) (((unsigned int)((((X2-Thickness)) > (0) ? ((X2-Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (14))) | ((unsigned int) (((unsigned int)((((Y1+Thickness)) > (0) ? ((Y1+Thickness)) : (0))) & ((0x01 << (10)) - 1)) << (2)))); } ;
}
