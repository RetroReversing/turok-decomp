typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {u32 type,flags;u64*ucode_boot;u32 ucode_boot_size;u64*ucode;u32 ucode_size;u64*ucode_data;u32 ucode_data_size;u64*dram_stack;u32 dram_stack_size;u64*output_buff;u64*output_buff_size;u64*data_ptr;u32 data_size;u64*yield_data_ptr;u32 yield_data_size;} TaskBody;typedef union {TaskBody t;u64 align;} OSTask;
typedef void OSMesgQueue;typedef void* OSMesg;
typedef struct OSScTask_s {struct OSScTask_s*next;u32 state,flags;void*framebuffer;OSTask list;OSMesgQueue*msgQ;OSMesg msg;} OSScTask;
typedef struct {u8 unused[0x268];OSScTask*gfxListHead;OSScTask*audioListTail;OSScTask*gfxListTail;OSScTask*curRSPTask;OSScTask*curRDPTask;} OSSched;
u64 osGetTime(void);u64 __ll_mul(u64,u64);u64 func_8009D3C8(u64,u64);float func_8009DA98(u64);
int osSpTaskYielded(OSTask*);int osSendMesg(OSMesgQueue*,OSMesg,int);
void func_8002C56C(OSSched*,OSScTask*);void func_8002C63C(OSSched*,OSScTask*,OSScTask*);
s32 __scSchedule(OSSched*,OSScTask**,OSScTask**,s32);
#define __scTaskComplete func_8002C56C
#define func_8002C63C func_8002C63C
extern u64 D_800EE4D0;
u64 D_8011A128,D_8011A130,D_8011A138;
extern float D_800B6B1C,D_800B6B20,D_800B6B24,D_8011A120;
extern int D_800BA900;
#define CYCLES_TO_NSEC(c) func_8009D3C8(__ll_mul((c),1000000000LL),D_800EE4D0)
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
int func_800A1610(void*,u64);
extern int D_800BA904,D_800BA908;
u64 D_8011A140;
#define rdp_start_time D_8011A140
#define dp_busy D_800BA904
#define dpCount D_800BA908
#define osDpSetNextBuffer func_800A1610
#define M_AUDTASK 2

#define osWritebackDCacheAll func_8009D1F0
void func_8009D1F0(void);


