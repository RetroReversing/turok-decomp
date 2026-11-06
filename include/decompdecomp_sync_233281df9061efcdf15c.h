typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef unsigned long DWORD;typedef unsigned char BYTE;typedef short INT16;
typedef struct {float x,y,z;} CVector3;typedef struct {float x,y,z,t;} CQuatern;
typedef struct {void*m_pData;BOOL m_AutoDeleteData;DWORD m_CurrentAllocSize;} CUnindexedSet;
typedef struct {void*m_pData;BOOL m_AutoDeleteData;} CIndexedSet;
typedef struct {CVector3 m_vPos;INT16 m_RotX,m_RotY,m_RotZ,m_RotT;} CROMInitialOrientation;
typedef struct {short m_nTranslationSet,m_nRotationSet;} CROMNodeIndex;
typedef struct {CVector3 m_vPos;} CPosFrame;typedef struct {INT16 x,y,z,t;} CRotFrame;
CROMNodeIndex CGameObjectInstance__GetNodeAnimIndex(CIndexedSet*,int);
void*func_8002DC68(CIndexedSet*,void*,int);
void CUnindexedSet__ConstructFromRawData(CUnindexedSet*,void*,BOOL);
#define CGameObjectInstance__GetNodeAnimIndex CGameObjectInstance__GetNodeAnimIndex
#define CIndexedSet__GetAddress(p,n) func_8002DC68((p),(p)->m_pData,(n))
#define CUnindexedSet__ConstructFromRawData CUnindexedSet__ConstructFromRawData
#define CUnindexedSet__GetBasePtr(p) ((void*)((BYTE*)((p)->m_pData)+8))
#define CUnindexedSet__GetBlockSize(p) (((DWORD*)(p)->m_pData)[0])
#define CUnindexedSet__GetBlock(p,n) ((void*)((BYTE*)CUnindexedSet__GetBasePtr(p)+(n)*CUnindexedSet__GetBlockSize(p)))
#define CUnindexedSet__Destruct(p)
#define ASSERT(x)
#define FALSE 0
#define CART_ANIM_usInitialOrients 2
#define CART_ANIM_usTranslationSets 3
#define CART_ANIM_usRotationSets 4
#define INT162FLOAT(intValue,maxValue) ((float)((intValue)*((float)(maxValue))/32767.0f))


