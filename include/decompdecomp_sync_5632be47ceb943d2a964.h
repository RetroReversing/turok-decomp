typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef unsigned long DWORD;typedef unsigned short WORD;typedef unsigned char BYTE;
typedef struct {float x,y,z;} CVector3;
typedef struct {CVector3 m_vCorner;float m_Ceiling;} CGameCorner;
typedef struct {u16 m_nRegionSet,m_wFlags;CGameCorner*m_pCorners[3];} CGameRegion;
typedef struct {u8 pad[0x20];float m_WaterElevation;} CROMRegionSet;
extern u8 D_800FA3C8[];
CROMRegionSet*CScene__GetRegionAttributes(void*,CGameRegion*);
CVector3 CGameRegion__GetCeilingNormal(CGameRegion*);
void CVector3__Subtract(CVector3*,CVector3*,CVector3*);
#define CScene__GetRegionAttributes CScene__GetRegionAttributes
#define CGameRegion__GetCeilingNormal CGameRegion__GetCeilingNormal
#define CVector3__Subtract CVector3__Subtract
#define CVector3__Dot(a,b) ((a)->x*(b)->x+(a)->y*(b)->y+(a)->z*(b)->z)
#define NULL ((void*)0)
#define TRUE 1
#define FALSE 0
#define REGFLAG_HASWATER 1

#define pRegionCache D_800B9730
#define pRegionSetCache D_800B9734


