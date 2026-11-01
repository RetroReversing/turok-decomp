typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int INT32,BOOL;typedef struct {int m_Mode;float m_Alpha;BOOL b_Active;int m_Selection,m_RealSelection;} CCheat;
typedef struct {u8 pad[0xF6E0];unsigned long m_dwEnabledCheatFlags;} CheatAppView;
extern CheatAppView D_80109F10;extern u8 D_801293F0[30];int func_800880CC(CCheat*);
#define GetApp() (&D_80109F10)
#define CHEAT_NULL 0
#define CHEAT_FADEUP 1
#define TRUE 1
#define CHEAT_END_SELECTION 30
#define CHEAT_EXIT 29
#define cheat_menu_items D_801293F0
#define CCheat__GetOptionAmt func_800880CC


