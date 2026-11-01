typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef struct {u8 pad[0xF660];BOOL active;u8 gap[0xF8A0-0xF664];BOOL m_bMessageBox;} ErrorApp;
extern ErrorApp D_80109F10;extern u8 D_80119568[],D_800B7E7C[],D_800B7EB4[],D_800B7EC8[],D_800B7ED8[],D_800B7EE8[],D_800B7EF8[],D_800B7F08[],D_800B7F10[],D_800B8148[],D_800B815C[];
void func_8000E498(void*,void*,void*);
#define GetApp() (&D_80109F10)
#define PFS_DIR_FULL 8
#define PFS_DATA_FULL 7
#define TRUE 1
#define FALSE 0


