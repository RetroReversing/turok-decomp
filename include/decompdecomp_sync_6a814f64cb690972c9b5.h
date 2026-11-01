typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {u8 pad[0x3c];u32 m_dwTypeFlags2;} EA;
typedef struct {u8 pad[0x18];EA*m_pEA;u8 gap[0x1d0-0x1c];u32 m_dwStatusFlags;} CGameObjectInstance;
int func_8001C348(CGameObjectInstance*,int,int*,int*,int*);void func_8005FCA0(CGameObjectInstance*,int,int);
#define CGameObjectInstance__GetRandomAnimIndex func_8001C348
#define AI_SetDesiredAnimByIndex func_8005FCA0
#define AI_GetEA(p) ((p)->m_pEA)
#define AI_GetDyn(p) (p)
#define FALSE 0
#define AI_ANIM_WALK									1				// ai walks forward
#define AI_ANIM_TURNL90								3				// ai does a normal turn left
#define AI_ANIM_TURNR90								4				// ai does a normal turn right
#define AI_ANIM_TURN180								6				// ai does a 180 degree turn
#define AI_ANIM_WTURNL90							7				// ai does a walking turn left  90 degrees
#define AI_ANIM_WTURNR90							8				// ai does a walking turn right 90 degrees
#define AI_ANIM_WTURN180							9				// ai does a walking 180 degree turn
#define AI_ANIM_WALK2									130				// ai walks forward
#define AI_ANIM_TURNL902								132				// ai does a normal turn left
#define AI_ANIM_TURNR902								133				// ai does a normal turn right
#define AI_ANIM_TURN1802								134				// ai does a 180 degree turn
#define AI_ANIM_WTURNL902								135				// ai does a walking turn left  90 degrees
#define AI_ANIM_WTURNR902								136				// ai does a walking turn right 90 degrees
#define AI_ANIM_WTURN1802								137				// ai does a walking 180 degree turn
#define	AI_WAITFOR_CYCLE					(1<<4)				// wait for cycle completed
#define	AI_TYPE2_USE2NDSETOFMOVES			(1<<21)

typedef struct {int values[7];} AnimArray;
extern AnimArray D_800BE5EC,D_800BE608,D_800BE624;


