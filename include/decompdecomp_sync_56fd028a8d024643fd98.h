typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL;typedef short INT16;typedef int INT32;
typedef struct {float m_Alpha;INT16 m_Mode;BOOL b_Active;INT16 m_LoadType;s32 m_Side;INT32 m_ASelection,m_BSelection,m_FirstVisible,m_MaxVisible,m_Selection,m_SubSelection,m_EntryPos;} CLoad;
typedef struct {float m_Alpha;INT16 m_Mode;BOOL b_Active;INT32 m_Selection;char *Line1,*Line2;} CMessageBox;
typedef struct {u8 pad[0xF658];CMessageBox m_MessageBox;u8 gap[0xF8A0-0xF658-sizeof(CMessageBox)];BOOL m_bMessageBox;} App;
extern App D_80109F10;
#define GetApp() (&D_80109F10)
extern u8 D_800B86D4;
#define validpaks D_800B86D4
extern int D_80119AB8;
#define TurokFiles D_80119AB8
int func_80011224(void);int func_800113A8(int);
void func_8000E498(CMessageBox*,char*,char*);
#define SetupFileSystem func_80011224
#define ScanFileList func_800113A8
#define CMessageBox__Construct func_8000E498
extern char D_800B8148[],D_800B815C[],D_800B7E50[],D_800B7E60[];
#define text_errorcontroller D_800B8148
#define text_pakdamaged D_800B815C
#define text_nocontroller D_800B7E50
#define text_pakfound D_800B7E60
#define LOAD_NULL 0
#define LOAD_FADEUP 1
#define LOAD_FADEDOWN 3
#define LOAD_MEMORYCARD 0
#define LOADMEMORY_EXIT 1
#define FALSE 0
#define TRUE 1


