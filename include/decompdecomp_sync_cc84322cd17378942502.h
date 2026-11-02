typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {unsigned int inst1,inst2,inst3,inst4;} __osExceptionVector;
typedef u32 OSIntMask;typedef int OSHWIntr;
#define SR_CU1 0x20000000
#define FPCSR_FS 0x01000000
#define FPCSR_EV 0x00000800
#define PIF_RAM_START 0x1fc007c0
#define UT_VEC 0x80000000
#define XUT_VEC 0x80000080
#define ECC_VEC 0x80000100
#define E_VEC 0x80000180
#define RAMROM_CLOCKRATE_OFFSET 4
#define RAMROM_CLOCKRATE_MASK 0xfffffff0
#define OS_APP_NMI_BUFSIZE 64
#define PI_STATUS_REG 0x04600010
#define ASIC_STATUS 0x05000508
#define PI_STATUS_IO_BUSY 2
#define PI_STATUS_DMA_BUSY 1
#define IO_READ(a) (*(volatile u32*)((u32)(a)|0xa0000000))
extern s32 D_80136A20;
#define __osFinalrom D_80136A20
u64 D_800EE4D0 = 62500000;
#define osClockRate D_800EE4D0
extern u32 D_8000030C,D_800EE4E0;
#define osResetType D_8000030C
#define osDiskExist D_800EE4E0
#define osAppNMIBuffer ((void*)0x8000031c)
extern u32 func_800A57D0[];
#define __osExceptionPreamble func_800A57D0
u32 func_800A64F0(void);void func_800A64E0(u32);u32 func_8009D0A0(u32);
s32 func_800A6500(u32,u32*);s32 func_800A6550(u32,u32);
void func_800A16E0(void*,s32);void func_800A65A0(void*,s32);void func_800A6620(void);
s32 func_800A6680(u32,u32*);void _bzero(void*,s32);
u64 __ull_div(u64,u64);u64 __ll_mul(u64,u64);
s32 func_800A67D0(void);void __osSetHWIntrRoutine(OSHWIntr,s32(*)(void));
#define __osGetSR func_800A64F0
#define __osSetSR func_800A64E0
#define __osSetFpcCsr func_8009D0A0
#define __osSiRawReadIo func_800A6500
#define __osSiRawWriteIo func_800A6550
#define osWritebackDCache func_800A16E0
#define osInvalICache func_800A65A0
#define osMapTLBRdb func_800A6620
#define osPiRawReadIo func_800A6680
#define bzero _bzero
#define __osLeoInterrupt func_800A67D0

