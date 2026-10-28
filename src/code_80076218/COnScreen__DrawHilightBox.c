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
extern void COnScreen__DrawBox(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2,
        unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) ;
extern /* Draws a beveled highlight box with light and dark edges, optionally inverted. */
void COnScreen__DrawHilightBox(Gfx **ppDLP, signed long x1, signed long y1, signed long x2, signed long y2, signed long thick, int invert,
           unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) ;
void COnScreen__DrawBox(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2,
        unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha);
void COnScreen__DrawHilightBox(Gfx **ppDLP, signed long x1, signed long y1, signed long x2, signed long y2, signed long thick, int invert,
           unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
void COnScreen__DrawHilightBox(Gfx **ppDLP, signed long x1, signed long y1, signed long x2, signed long y2, signed long thick, int invert,
           unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha){
 int lr, lg, lb ;
 int dr, dg, db ;
 lr = (invert) ? red/2 : red*2 ;
 lg = (invert) ? green/2 : green*2 ;
 lb = (invert) ? blue/2 : blue*2 ;
 dr = (invert) ? red*2 : red/2 ;
 dg = (invert) ? green*2 : green/2 ;
 db = (invert) ? blue*2 : blue/2 ;
 COnScreen__DrawBox(ppDLP,
        x1, y1,
        x2, y2,
        red, green, blue, alpha) ;
 COnScreen__DrawBox(ppDLP,
        x1, y1,
        x2, y1+thick,
        lr,lg,lb, alpha) ;
 COnScreen__DrawBox(ppDLP,
        x2-thick, y1,
        x2, y2,
        lr,lg,lb, alpha) ;
 COnScreen__DrawBox(ppDLP,
        x1, y2-thick,
        x2, y2,
        dr,dg,db, alpha) ;
 COnScreen__DrawBox(ppDLP,
        x1, y1,
        x1+thick, y2,
        dr,dg,db, alpha) ;
}
