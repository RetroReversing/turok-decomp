typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct {
	u8	dummy;                  /* for word aliening */
	u8	txsize;			/* Tx size */
	u8	rxsize;			/* Rx size */
	u8	cmd;			/* commmand */
	u8      typeh;
	u8      typel;
	u8      status;
	u8	dummy1;                  /* for word aliening */
} __OSContRequesFormat;
extern u8 D_80137C90[64];
extern u8 D_80137C41;
#define __osMaxControllers D_80137C41
#define __osContPifRam D_80137C90
#define CON_ERR_MASK 0xc0
typedef struct {u16 type; u8 status,errno;} OSContStatus;

