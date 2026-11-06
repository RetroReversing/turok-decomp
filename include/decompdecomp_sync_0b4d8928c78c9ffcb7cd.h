typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {u32 type,flags;u64*ucode_boot;u32 ucode_boot_size;u64*ucode;u32 ucode_size;u64*ucode_data;u32 ucode_data_size;u64*dram_stack;u32 dram_stack_size;u64*output_buff;u64*output_buff_size;u64*data_ptr;u32 data_size;u64*yield_data_ptr;u32 yield_data_size;} TaskBody;typedef union {TaskBody t;u64 align;} OSTask;
typedef void OSMesgQueue;typedef void* OSMesg;
typedef struct OSScTask_s {struct OSScTask_s*next;u32 state,flags;void*framebuffer;OSTask list;OSMesgQueue*msgQ;OSMesg msg;} OSScTask;
typedef struct {u8 unused[0x268];OSScTask*gfxListHead;OSScTask*audioListTail;OSScTask*gfxListTail;OSScTask*curRSPTask;OSScTask*curRDPTask;} OSSched;
u64 osGetTime(void);u64 __ll_mul(u64,u64);u64 __ull_div(u64,u64);float __ull_to_f(u64);
int osSpTaskYielded(OSTask*);int osSendMesg(OSMesgQueue*,OSMesg,int);
void __scTaskComplete(OSSched*,OSScTask*);void __scExec(OSSched*,OSScTask*,OSScTask*);
s32 __scSchedule(OSSched*,OSScTask**,OSScTask**,s32);
#define __scTaskComplete __scTaskComplete
#define __scExec __scExec
extern u64 D_800EE4D0,D_8011A128,D_8011A130,D_8011A138;
extern float D_800B6B1C,D_800B6B20,D_800B6B24,D_8011A120;
extern int D_800BA900;
#define CYCLES_TO_NSEC(c) __ull_div(__ll_mul((c),1000000000LL),D_800EE4D0)
#define rsp_audio_start_time D_8011A128
#define rsp_graphics_start_time D_8011A130
#define rsp_start_time D_8011A138
#define rsp_total_time D_800B6B1C
#define rsp_audio_time D_800B6B20
#define rsp_graphics_time D_800B6B24
#define this_rsp_graphics_time D_8011A120
#define c_retrace D_800BA900
#define SHIP_IT 1
#define ASSERT(x)
#define NULL ((void*)0)
#define OS_SC_YIELD 0x10
#define OS_SC_YIELDED 0x20
#define OS_SC_TYPE_MASK 7
#define OS_SC_XBUS 3
#define OS_SC_LAST_TASK 0x20
#define OS_SC_NEEDS_RSP 2
#define M_GFXTASK 1
#define OS_MESG_NOBLOCK 0

void osWritebackDCacheAll(void);void osSpTaskLoad(OSTask*);void osSpTaskStartGo(OSTask*);
int func_800A1610(void*,u32);
extern int D_800BA904,D_800BA908;
extern u64 D_8011A140;
#define rdp_start_time D_8011A140
#define dp_busy D_800BA904
#define dpCount D_800BA908
#define osDpSetNextBuffer func_800A1610
#define M_AUDTASK 2

typedef unsigned long DWORD;typedef int BOOL;
typedef union {u64 align;u32 words[16];} Mtx;
typedef struct {u64 m_DepthData[2];int m_DepthPos;BOOL m_Visible,m_VisibleZ,align;} CSunFrameData;
typedef struct {u8 bytes[32];} LookAt;
typedef struct {u8 bytes[64];} GFXMsg;
typedef union {u64 words;} Gfx;
typedef struct CFrameData_t
{
	Mtx					m_mProjection;
	LookAt				m_LookAt;
	CSunFrameData		m_SunFrame;
	OSScTask				m_Task,
							m_LineTask;
	GFXMsg				m_Msg;
	void					*m_pFrameBuffer;
	Gfx					*m_pDisplayList,
							*m_pLineList;
	DWORD					m_DisplayListSize,
							m_LineListSize,
							m_nPredictFields;
	BOOL					m_DrawMap;
} CFrameData;

typedef struct {CFrameData m_FrameData[3];} FrameDataView;
extern CFrameData D_800F9F10;
#define GetApp() ((FrameDataView*)&D_800F9F10)
extern int D_800F9D50,D_800F9D54,D_800F9D58,D_800F9D5C,D_800F9D60,D_800F9D64,D_800F9D68,D_800F9D70;
extern void*D_800F9D88;
extern CFrameData*D_800F9D78[3];
extern float D_800B6B28;
void osViSwapBuffer(void*);void CSunFrameData__RDPComplete(CSunFrameData*);
#define c_field D_800F9D50
#define n_fields D_800F9D54
#define n_l_fields D_800F9D58
#define n_ll_fields D_800F9D5C
#define n_lll_fields D_800F9D60
#define c_waiting D_800F9D64
#define n_waiting D_800F9D68
#define n_pending D_800F9D70
#define p_waiting_frames D_800F9D78
#define p_pending_fb D_800F9D88
#define CSunFrameData__RDPComplete CSunFrameData__RDPComplete
#define rdp_time D_800B6B28
#define OS_SC_NEEDS_RDP 1


