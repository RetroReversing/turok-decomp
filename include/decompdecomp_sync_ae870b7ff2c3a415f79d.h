typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef int BOOL,INT32;typedef short INT16;typedef unsigned long DWORD;
typedef struct CSave_t
{
	// Mode vars
	float				m_Alpha ;				// 0..1
	INT16				m_Mode ;					// state of fade

	BOOL				b_Active ;

	INT16				m_SaveType ;			// memory card or password

	// Selection vars
	s32				m_Side ;					// left or right column
	INT32				m_ASelection ;			// Current selection
	INT32				m_BSelection ;			// Current selection
	INT32				m_FirstVisible ;
	INT32				m_MaxVisible ;

	BOOL				m_ShowAll ;				// show all file types

	INT32				m_Selection ;			// Current selection

} CSave ;
typedef struct {u8 pad[0xF660];BOOL messageActive;u8 gap[0xF89C-0xF664];BOOL m_bRequestor,m_bMessageBox;} SaveAppView;
extern SaveAppView D_80109F10;extern u8 D_80119568[],D_800B8148[],D_800B815C[],D_800B7E50[],D_800B7E60[];extern u8 D_800B86D4;extern int D_80119974;
int func_80011224(void);void func_800113A8(BOOL);void func_8000E498(void*,void*,void*);
#define GetApp() (&D_80109F10)
#define SetupFileSystem func_80011224
#define validpaks D_800B86D4
#define SaveRequestMode D_80119974
#define ScanFileList func_800113A8
#define SAVE_NULL 0
#define SAVE_FADEUP 1
#define SAVE_FADEDOWN 3
#define SAVE_MEMORYCARD 0
#define TRUE 1
#define FALSE 0
#define NULL 0


