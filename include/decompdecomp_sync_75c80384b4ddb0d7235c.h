typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
#define IO_READ(a) (*(volatile u32 *)(a))
#define IO_WRITE(a,b) (*(volatile u32 *)(a)=(b))
#define K1_TO_PHYS(a) ((u32)(a)&0x1fffffff)
#define OS_READ 0
#define OS_WRITE 1
#define PI_STATUS_IO_BUSY 2
#define PI_STATUS_DMA_BUSY 1
#define PI_STATUS_REG 0xA4600010
#define PI_DRAM_ADDR_REG 0xA4600000
#define PI_CART_ADDR_REG 0xA4600004
#define PI_WR_LEN_REG 0xA460000C
#define PI_RD_LEN_REG 0xA4600008
u32 osVirtualToPhysical(void *);
typedef struct OSPiHandle_s {struct OSPiHandle_s *next;u8 type,latency,pageSize,relDuration,pulse,domain;u32 baseAddress,speed;} OSPiHandle;
#define AI_DACRATE_REG 0xA4500010
#define AI_BITRATE_REG 0xA4500014
#define AI_CONTROL_REG 0xA4500008
#define AI_CONTROL_DMA_ON 1
#define AI_MIN_DAC_RATE 132
#define AI_MAX_BIT_RATE 16
extern s32 D_800EF338;
#define osViClock D_800EF338

