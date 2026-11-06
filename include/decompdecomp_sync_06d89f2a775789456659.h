typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL,INT32;typedef unsigned long DWORD;typedef unsigned short WORD;
typedef struct {float x,y,z;} CVector3;
typedef struct {u8 pad[0x34];DWORD m_dwSpecies;} CEnemyAttributes;
typedef struct {u8 kind,flags;u16 type;CVector3 m_vPos;float offset;void*region;CEnemyAttributes*m_pEA;} CInstanceHdr;
typedef struct {CInstanceHdr ih;} CAnimInstanceHdr;
typedef struct {CAnimInstanceHdr ah;} CGameObjectInstance;
typedef struct {u8 pad20[0x20];int m_Mode;u8 pad24[0x14];float m_MoveTime;} CBoss;
typedef struct {CBoss m_Boss;} CMantis;
typedef struct {u8 pad[0x7AD8];int pickupActive;u8 pad7ADC[0x8CC4-0x7ADC];DWORD m_BossFlags;u8 pad8CC8[0x8E40-0x8CC8];CGameObjectInstance*tracked;} DeathAppView;
extern DeathAppView D_80109F10;extern CGameObjectInstance*D_8010201C;extern u8 D_80112C18[];
void AI_Event_Dispatcher(CInstanceHdr*,CInstanceHdr*,int,DWORD,CVector3,float);void CCamera__FadeToCinema(void*,int);
#define AI_Event_Dispatcher AI_Event_Dispatcher
#define GetApp() (&D_80109F10)
#define MANTIS_DEATH_FLOOR_MODE 54
#define BOSS_FLAG_MANTIS_DEAD 1024


