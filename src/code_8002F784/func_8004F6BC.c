#include "common.h"

extern u8 D_800BDBCC;
extern u8 D_80112C18[];
extern void func_80043028(void *, s32, void *);
extern void func_8004305C(void *, void *);
extern void func_8003983C(void *, s32);
typedef struct {u8 pad[0x8cc4]; s32 flags; u8 pad2[0x178]; s32 value;} Global;
extern Global D_80109F10;
void func_8004F6BC(s32 a, void *b) {
    *(s32 *)((u8 *)b + 0x20) = 0x37;
    func_80043028((u8 *)b + 0x188, a, b);
    func_8004305C((u8 *)b + 0x188, &D_800BDBCC);
    D_80109F10.flags |= 0x20000;
    D_80109F10.value = a;
    func_8003983C(D_80112C18, 0x800);
    *(f32 *)((u8 *)b + 0x258) = 0.0f;
}
