typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef struct {float x,y,z;} CVector3;
typedef struct {CVector3 m_vCorner;} CROMCorner;
typedef struct {u32 flags;CROMCorner *m_pCorners[3];} CGameRegion;
#define TRUE 1
#define FALSE 0







