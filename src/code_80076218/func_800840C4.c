#include "common.h"

s32 func_800137A0(void);
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
#define B(p,o) (*(s8*)((u8*)(p)+(o)))
void func_800840C4(void *aiDynamic,void *attributes,void *instance) {
 /* Randomize a human enemy's head, armor, weapon and extra model. */
 s32 r; s32 attackStyle; s32 objectType;
 H(aiDynamic,0x7a)=0; H(aiDynamic,0x78)=0; H(aiDynamic,0x76)=0; H(aiDynamic,0x74)=0;
 objectType=H(instance,0x11a); if(objectType!=2)return;
 attackStyle=B(attributes,0x4e);
 if(attackStyle<9) {
  H(aiDynamic,0x74)=func_800137A0()%12;
  if(attackStyle!=2&&attackStyle!=3&&attackStyle!=6&&attackStyle!=8) H(aiDynamic,0x76)=0; else H(aiDynamic,0x76)=1;
  switch(attackStyle){
  case 0:case 1:
   r=func_800137A0()%100;
   if(r<33)H(aiDynamic,0x78)=1;
   else if(r<66)H(aiDynamic,0x78)=14;
   else H(aiDynamic,0x78)=2;
   break;
  case 3:
   r=func_800137A0()%100;
   if(r<50)H(aiDynamic,0x78)=3;else H(aiDynamic,0x78)=16;
   break;
  }
  switch(attackStyle){
  case 1: case 2: case 4:
   H(aiDynamic,0x7a)=func_800137A0()%100<50?2:0;break;
  case 3: case 5: case 6: case 7:
   H(aiDynamic,0x7a)=func_800137A0()%100<50?3:0;break;
  }
 }else if(attackStyle<18){H(aiDynamic,0x74)=func_800137A0()%7;}
}
