#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
#line 1 "reference.c"
extern void func_800806B4(int);
extern void func_8008092C(float, float);
extern void func_800808F8(int, int, int, int, int, int, int);
extern void COnScreen__PrepareSmallFont(int);
extern void func_800814AC(int, const char *, int, int, int, int, int);
extern unsigned char D_800B86D0;
extern int D_80119940;
extern float D_80119944;
extern char D_800B6B80[];
extern char D_800B6B90[];
extern char D_800B6BA8[];
extern char D_800B6BBC[];
extern char D_800B6BCC[];
extern char D_800B6BD8[];
extern char D_800B7E50[];
extern char D_800B7E60[];
extern char D_800B8148[];
extern char D_800B815C[];
extern char D_800EFB50[];
extern char D_800EFB74[];
extern char D_800EFB8C[];
extern char D_800EFBB0[];
extern char D_800EFBC8[];
extern char D_800EFBEC[];
extern char D_800EFC10[];
extern char D_800EFC30[];
extern char D_800EFC54[];
extern char D_800EFC6C[];
extern char D_800EFC88[];
extern char D_800EFCA4[];
extern char D_800EFCC8[];
extern char D_800EFCE0[];
void func_8000B28C(int a){
 int y;
 func_800806B4(a);
 if(!D_800B86D0){
  func_8008092C(1.0f,2.0f);
  func_800808F8(a,50,250,50,250,250,50);
  y=100;
  func_800814AC(a,D_800B6B80,160,y,(int)D_80119944,1,0);y+=40;
  func_800814AC(a,D_800B6B90,160,y,(int)D_80119944,1,0);y+=40;
  func_800814AC(a,D_800B6BA8,160,y,(int)D_80119944,1,0);
 }else if(D_80119940){
  func_8008092C(1.0f,2.0f);
  func_800808F8(a,50,250,50,250,250,50);
  if(D_80119940==3){
   y=120;func_800814AC(a,D_800B8148,160,y,(int)D_80119944,1,0);y=160;
   func_800814AC(a,D_800B815C,160,160,(int)D_80119944,1,0);
  }else if(D_80119940==1){
   y=120;func_800814AC(a,D_800B6BBC,160,y,(int)D_80119944,1,0);y=160;
   func_800814AC(a,D_800B6BCC,160,160,(int)D_80119944,1,0);
  }else if(D_80119940==2){
   y=100;func_800814AC(a,D_800B7E50,160,y,(int)D_80119944,1,0);y=136;
   func_800814AC(a,D_800B7E60,160,136,(int)D_80119944,1,0);y=180;
   func_800814AC(a,D_800B6BD8,160,180,(int)D_80119944,1,0);
  }
 }else{
  func_8008092C(1.0f,1.0f);func_800808F8(a,150,150,150,150,150,150);COnScreen__PrepareSmallFont(a);
  y=92;
 func_800814AC(a,D_800EFB50,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFB74,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFB8C,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFBB0,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFBC8,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFBEC,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFC10,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFC30,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFC54,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFC6C,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFC88,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFCA4,160,y,(int)D_80119944,1,0);
 y+=9;
 func_800814AC(a,D_800EFCC8,160,y,(int)D_80119944,1,0);
 y+=15;
 func_800814AC(a,D_800EFCE0,160,y,(int)D_80119944,1,0);
 }
}

