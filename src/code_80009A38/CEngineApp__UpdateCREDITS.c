#include "common.h"

/* machine draft (m2c) for ido-5.3 -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK CEngineApp__SetupFadeTo(void *, M2C_UNK);             /* extern */
M2C_UNK CEngineApp__UpdateCameraAttributes(void *);                      /* extern */
M2C_UNK CEngineApp__PrepareFrame(void *, M2C_UNK);             /* extern */
M2C_UNK func_8000B96C();                            /* extern */
M2C_UNK ReadControllerAdvanced();                            /* extern */
f32 CTControl__IsStart(s32);                             /* extern */
M2C_UNK osContStartReadData(M2C_UNK *);                   /* extern */
extern u8 D_800B86D0;
extern M2C_UNK D_800F9C20;
extern s32 D_800F9E44;
extern s32 D_80119908;
extern s32 D_8011990C;

void CEngineApp__UpdateCREDITS(void *arg0) {
    if ((D_800B86D0 != 0) && (D_80119908 == 0)) {
        D_80119908 = 1;
        osContStartReadData(&D_800F9C20);
    }
    if (D_8011990C != 0) {
        ReadControllerAdvanced();
    }
    CEngineApp__UpdateCameraAttributes(arg0);
    CEngineApp__PrepareFrame(arg0, 4);
    func_8000B96C();
    if ((M2C_FIELD(arg0, s32 *, 0x1F888) != 0) && (CTControl__IsStart(D_800F9E44) != 0.0f)) {
        CEngineApp__SetupFadeTo(arg0, 0);
    }
}
