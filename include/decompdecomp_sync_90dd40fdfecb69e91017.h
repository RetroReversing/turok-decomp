typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
u32 osVirtualToPhysical(void *);
#define IO_READ(a) (*(volatile u32 *)(a))
#define IO_WRITE(a,b) (*(volatile u32 *)(a)=(b))
#define K1_TO_PHYS(a) ((u32)(a)&0x1fffffff)
#define OS_READ 0
#define OS_WRITE 1
#define PI_STATUS_IO_BUSY 2
#define PI_STATUS_DMA_BUSY 1
extern u32 D_80000308;
#define osRomBase D_80000308
extern volatile u32 D_A4600010;
#define PI_STATUS_REG 0xA4600010
extern volatile u32 D_A4600000;
#define PI_DRAM_ADDR_REG 0xA4600000
extern volatile u32 D_A4600004;
#define PI_CART_ADDR_REG 0xA4600004
extern volatile u32 D_A460000C;
#define PI_WR_LEN_REG 0xA460000C
extern volatile u32 D_A4600008;
#define PI_RD_LEN_REG 0xA4600008
extern volatile u32 D_A4500000;
#define AI_DRAM_ADDR_REG 0xA4500000
extern volatile u32 D_A4500004;
#define AI_LEN_REG 0xA4500004

