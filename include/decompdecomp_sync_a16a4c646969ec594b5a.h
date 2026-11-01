typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef unsigned long DWORD;typedef unsigned short WORD;typedef unsigned char BYTE;
typedef struct {float x,y,z;} CVector3;
typedef struct {CVector3 m_vCorner;float m_Ceiling;} CGameCorner;
typedef struct {u16 m_nRegionSet,m_wFlags;CGameCorner*m_pCorners[3];} CGameRegion;
typedef struct {u8 pad[0x20];float m_WaterElevation;} CROMRegionSet;
extern u8 D_800FA3C8[];
CROMRegionSet*func_8002E438(void*,CGameRegion*);
CVector3 func_800207C0(CGameRegion*);
void func_800144C8(CVector3*,CVector3*,CVector3*);
#define CScene__GetRegionAttributes func_8002E438
#define func_800207C0 func_800207C0
#define CVector3__Subtract func_800144C8
#define CVector3__Dot(a,b) ((a)->x*(b)->x+(a)->y*(b)->y+(a)->z*(b)->z)
#define NULL ((void*)0)
#define TRUE 1
#define FALSE 0
#define REGFLAG_HASWATER 1

void func_80013BBC(CVector3*,CVector3*,CVector3*);
#define CVector3__Cross func_80013BBC
#define pNormalCache D_800B9720
#define vNormalCache D_80119D60


