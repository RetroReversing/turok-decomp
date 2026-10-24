#include "common.h"

typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;
typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;
typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;
extern Vtx D_800F9ED0[4];
extern void func_80001B74();
extern Vtx D_800F9ED0[4];
void func_80001B74();
void func_80001B74(){
 int v;
 Vtx *pV;
 for (v=0; v<4; v++)
 {
  pV = &D_800F9ED0[v];
  switch (v)
  {
   case 0:
    pV->v.ob[0] = -1;
    pV->v.ob[2] = 1;
    pV->v.tc[0] = 0;
    pV->v.tc[1] = 0;
    break;
   case 1:
    pV->v.ob[0] = 1;
    pV->v.ob[2] = 1;
    pV->v.tc[0] = 32*(1 << 5);
    pV->v.tc[1] = 0;
    break;
   case 2:
    pV->v.ob[0] = 1;
    pV->v.ob[2] = -1;
    pV->v.tc[0] = 32*(1 << 5);
    pV->v.tc[1] = 32*(1 << 5);
    break;
   case 3:
    pV->v.ob[0] = -1;
    pV->v.ob[2] = -1;
    pV->v.tc[0] = 0;
    pV->v.tc[1] = 32*(1 << 5);
    break;
  }
  pV->v.ob[1] = 0;
  pV->v.flag = 0;
  pV->v.cn[0] = 255;
  pV->v.cn[1] = 255;
  pV->v.cn[2] = 255;
  pV->v.cn[3] = 255;
 }
}
