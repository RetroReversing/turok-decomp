#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
void func_80011194(void);
void func_800111F4(s32);
s32 func_80034B4C(void *);
s32 func_80034B90(void *);
s32 osPfsReadWriteFile(void *, s32, s32, s32, s32, s32);
s32 osPfsAllocateFile(void *, u16, s32, void *, s8 *, s32, s32 *);
extern u16 D_800B86D8;
extern s32 D_800B86DC;
extern struct 
{
  u8 data[11];
} D_800B86E0;
extern s8 D_800B86F0;
extern u8 D_800FA3C8;
extern s32 D_801195F4;
extern u8 D_80119A08;
extern s32 D_80119AC0;
s32 SaveNew(void)
{
  s32 result;
  s32 size;
  s32 saveSize;
  s32 sp28 = 0;
  func_80011194();
  size = func_80034B4C(&D_800FA3C8);
  saveSize = func_80034B90(&D_800FA3C8);
  size = ((size / 256) + 1) << 8;
  D_800B86F0 = (s8) D_80119AC0;
 D_800B86E0.data[10] = (u8) (D_801195F4 + 16); result = osPfsAllocateFile(&D_80119A08, D_800B86D8, D_800B86DC, &D_800B86E0, &D_800B86F0, size, &sp28);
  if (result == 0)
  {
    result = osPfsReadWriteFile(&D_80119A08, sp28, 1, 0, size, saveSize);
  }
  func_800111F4(result);
  return result;
}

