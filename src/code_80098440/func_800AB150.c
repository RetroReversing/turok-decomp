#include "common.h"

typedef struct { u8 pad[0x60]; u8 *entries; } ObjAB150;
void func_800AB150(ObjAB150 *obj, u8 *src, u32 i) {
    *(u8 **)(obj->entries + (i << 4)) = src;
    *(u8 *)(obj->entries + (i << 4) + 7) = src[1];
    *(u8 *)(obj->entries + (i << 4) + 9) = src[0];
    *(u8 *)(obj->entries + (i << 4) + 8) = src[2];
    *(s16 *)(obj->entries + (i << 4) + 4) = *(s16 *)(src + 12);
}
