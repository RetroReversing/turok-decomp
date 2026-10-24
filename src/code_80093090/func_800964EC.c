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
extern void func_800964EC();
extern Vtx D_80130D80[2][512];
extern Vtx D_80134D80[2][3];
extern Vtx D_80134DE0[2][10*3];
extern Vtx D_801351A0[2][8];
void func_800964EC();
void func_800964EC(){
 int e, i;
 for (e=0; e<2; e++)
 {
  for (i=0; i<512; i++)
  {
   D_80130D80[e][i].v.ob[0] = 0;
   D_80130D80[e][i].v.ob[1] = 0;
   D_80130D80[e][i].v.ob[2] = 0;
   D_80130D80[e][i].v.flag = 0;
   D_80130D80[e][i].v.tc[0] = 0;
   D_80130D80[e][i].v.tc[1] = 0;
   D_80130D80[e][i].v.cn[0] = 0;
   D_80130D80[e][i].v.cn[1] = 200;
   D_80130D80[e][i].v.cn[2] = 0;
   D_80130D80[e][i].v.cn[3] = 255;
  }
  for (i=0; i<3; i++)
  {
   D_80134D80[e][i].v.ob[0] = 0;
   D_80134D80[e][i].v.ob[1] = 0;
   D_80134D80[e][i].v.ob[2] = 0;
   D_80134D80[e][i].v.flag = 0;
   D_80134D80[e][i].v.tc[0] = 0;
   D_80134D80[e][i].v.tc[1] = 0;
   D_80134D80[e][i].v.cn[0] = 200;
   D_80134D80[e][i].v.cn[1] = 200;
   D_80134D80[e][i].v.cn[2] = 0;
   D_80134D80[e][i].v.cn[3] = 255;
  }
  for (i=0; i<10*3; i++)
  {
   D_80134DE0[e][i].v.ob[0] = 0;
   D_80134DE0[e][i].v.ob[1] = 0;
   D_80134DE0[e][i].v.ob[2] = 0;
   D_80134DE0[e][i].v.flag = 0;
   D_80134DE0[e][i].v.tc[0] = 0;
   D_80134DE0[e][i].v.tc[1] = 0;
   D_80134DE0[e][i].v.cn[0] = 200;
   D_80134DE0[e][i].v.cn[1] = 0;
   D_80134DE0[e][i].v.cn[2] = 0;
   D_80134DE0[e][i].v.cn[3] = 255;
  }
  for (i=0; i<8; i++)
  {
   D_801351A0[e][i].v.ob[0] = 0;
   D_801351A0[e][i].v.ob[1] = 0;
   D_801351A0[e][i].v.ob[2] = 0;
   D_801351A0[e][i].v.flag = 0;
   D_801351A0[e][i].v.tc[0] = 0;
   D_801351A0[e][i].v.tc[1] = 0;
   D_801351A0[e][i].v.cn[0] = 200;
   D_801351A0[e][i].v.cn[1] = 0;
   D_801351A0[e][i].v.cn[2] = 200;
   D_801351A0[e][i].v.cn[3] = 255;
  }
 }
}
