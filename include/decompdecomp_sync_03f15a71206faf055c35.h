typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef void*OSMesg;typedef struct OSMesgQueue OSMesgQueue;
typedef struct {
    u32	ctrl;
    u32	width;
    u32	burst;
    u32	vSync;
    u32	hSync;
    u32	leap;
    u32	hStart;
    u32	xScale;
    u32	vCurrent;
} OSViCommonRegs;


/*
 * Structure to store VI register values that change between fields
 */
typedef struct {
    u32	origin;
    u32	yScale;
    u32	vStart;	
    u32	vBurst;
    u32	vIntr;
} OSViFieldRegs;


/*
 * Structure for VI mode
 */
typedef struct {
    u8			type;		/* Mode type */
    OSViCommonRegs	comRegs;	/* Common registers for both fields */
    OSViFieldRegs	fldRegs[2];	/* Registers for Field 1  & 2 */
} OSViMode;
typedef struct {
    f32		factor;		/* Scaling factor 0.0 <= x <= 1.0 */
    u16		offset;		/* Result origin offset (16-bit) */	
    u32		scale;		/* Result scale (12-bit) */
} __OSViScale;


/**************************************************************************
 * Structure for VI context
 */
typedef struct {
    u16			state;		/* internal state */
    u16			retraceCount;	/* Number of retrace before get msg */
    void		*framep;	/* pointer to frame buffer */
    OSViMode		*modep;		/* pointer to standard mode struct */
    u32			control;	/* VI control value */
    OSMesgQueue		*msgq;		/* Application message queue */
    OSMesg		msg;		/* Application message */
    __OSViScale		x;		/* X-scaling */
    __OSViScale		y;		/* Y-scaling */
} __OSViContext;
#define	VI_STATE_NORMAL		0x00
#define	VI_STATE_MODE		0x01
#define	VI_STATE_X_SCALE	0x02
#define	VI_STATE_Y_SCALE	0x04
#define	VI_STATE_CONTROL	0x08
#define	VI_STATE_FRAME		0x10
#define	VI_STATE_BLACK		0x20
#define	VI_STATE_REPEAT_LINE	0x40
#define	VI_STATE_FADE		0x80
extern __OSViContext *D_800EF330,*D_800EF334;
#define __osViCurr D_800EF330
#define __osViNext D_800EF334
u32 osVirtualToPhysical(void*);
#define IO_READ(a) (*(volatile u32*)(a))
#define IO_WRITE(a,b) (*(volatile u32*)(a)=(b))
#define VI_CONTROL_REG 0xa4400000
#define VI_ORIGIN_REG 0xa4400004
#define VI_WIDTH_REG 0xa4400008
#define VI_BURST_REG 0xa4400014
#define VI_V_SYNC_REG 0xa4400018
#define VI_H_SYNC_REG 0xa440001c
#define VI_LEAP_REG 0xa4400020
#define VI_H_START_REG 0xa4400024
#define VI_V_START_REG 0xa4400028
#define VI_V_BURST_REG 0xa440002c
#define VI_V_INTR_REG 0xa440000c
#define VI_CURRENT_REG 0xa4400010
#define VI_X_SCALE_REG 0xa4400030
#define VI_Y_SCALE_REG 0xa4400034

