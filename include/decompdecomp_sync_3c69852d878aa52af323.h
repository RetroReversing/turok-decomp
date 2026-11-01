typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state;} OSThread;
typedef void *OSMesg;
typedef struct {OSThread *mtqueue,*fullqueue;s32 validCount,first,msgCount;OSMesg *msg;} OSMesgQueue;
typedef struct {
	u32		errStatus;	/* error status */
        void     	*dramAddr;      /* RDRAM buffer address (DMA) */
	void		*C2Addr;	/* C2 buffer address */
	u32		sectorSize;	/* size of transfering sector */
	u32		C1ErrNum;	/* total # of C1 errors */
	u32		C1ErrSector[4];	/* error sectors */
} __OSBlockInfo;

typedef struct {
	u32     	cmdType;       	/* for disk only */
	u16     	transferMode;   /* Block, Track, or sector?   */
	u16		blockNum;	/* which block is transfering */
	s32     	sectorNum;      /* which sector is transfering */
	u32     	devAddr;        /* Device buffer address */
	u32		bmCtlShadow;	/* asic bm_ctl(510) register shadow ram */
	u32		seqCtlShadow;	/* asic seq_ctl(518) register shadow ram */
	__OSBlockInfo	block[2];	/* bolck transfer info */
} __OSTranxInfo;


typedef struct OSPiHandle_s {
        struct OSPiHandle_s     *next;  /* point to next handle on the table */
        u8                      type;   /* DEVICE_TYPE_BULK for disk */
        u8                      latency;        /* domain latency */
        u8                      pageSize;       /* domain page size */
        u8                      relDuration;    /* domain release duration */
        u8                      pulse;          /* domain pulse width */
	u8			domain;		/* which domain */
        u32                     baseAddress;    /* Domain address */
        u32                     speed;          /* for roms only */
        /* The following are "private" elements" */
        __OSTranxInfo           transferInfo;	/* for disk only */
} OSPiHandle;

typedef struct {
        u8      type;
        u32     address;
} OSPiInfo;

/*
 * Structure for I/O message block
 */
typedef struct {
        u16 		type;		/* Message type */
        u8 		pri;		/* Message priority (High or Normal) */
        u8		status;		/* Return status */
	OSMesgQueue	*retQueue;	/* Return message queue to notify I/O 
					 * completion */
} OSIoMesgHdr;

typedef struct {
	OSIoMesgHdr	hdr;		/* Message header */
	void *		dramAddr;	/* RDRAM buffer address (DMA) */
	u32		devAddr;	/* Device buffer address (DMA) */
	u32 		size;		/* DMA transfer size in bytes */
	OSPiHandle	*piHandle;	/* PI device handle */
} OSIoMesg;

/*
 * Structure for device manager block
 */
typedef struct {
        s32             active;		/* Status flag */
	OSThread	*thread;	/* Calling thread */
        OSMesgQueue  	*cmdQueue;	/* Command queue */
        OSMesgQueue  	*evtQueue;	/* Event queue */
        OSMesgQueue  	*acsQueue;	/* Access queue */
					/* Raw DMA routine */
        s32             (*dma)(s32, u32, void *, u32);
        s32             (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;
#define _RCP_H_
#define RDRAM_0_START		0x00000000
#define RDRAM_0_END		0x001FFFFF
#define RDRAM_1_START		0x00200000
#define RDRAM_1_END		0x003FFFFF
#define RDRAM_START		RDRAM_0_START
#define RDRAM_END		RDRAM_1_END
#define IS_RDRAM(x)     ((unsigned)(x) >= RDRAM_START && \
			(unsigned)(x) < RDRAM_END)
#define RDRAM_BASE_REG		0x03F00000
#define RDRAM_CONFIG_REG	(RDRAM_BASE_REG+0x00)
#define RDRAM_DEVICE_TYPE_REG	(RDRAM_BASE_REG+0x00)
#define RDRAM_DEVICE_ID_REG	(RDRAM_BASE_REG+0x04)
#define RDRAM_DELAY_REG		(RDRAM_BASE_REG+0x08)
#define RDRAM_MODE_REG		(RDRAM_BASE_REG+0x0c)
#define RDRAM_REF_INTERVAL_REG	(RDRAM_BASE_REG+0x10)
#define RDRAM_REF_ROW_REG	(RDRAM_BASE_REG+0x14)
#define RDRAM_RAS_INTERVAL_REG	(RDRAM_BASE_REG+0x18)
#define RDRAM_MIN_INTERVAL_REG	(RDRAM_BASE_REG+0x1c)
#define RDRAM_ADDR_SELECT_REG	(RDRAM_BASE_REG+0x20)
#define RDRAM_DEVICE_MANUF_REG	(RDRAM_BASE_REG+0x24)
#define RDRAM_0_DEVICE_ID	0
#define RDRAM_1_DEVICE_ID	1
#define RDRAM_RESET_MODE        0
#define RDRAM_ACTIVE_MODE       1
#define RDRAM_STANDBY_MODE      2
#define RDRAM_LENGTH		(2*512*2048)
#define RDRAM_0_BASE_ADDRESS	(RDRAM_0_DEVICE_ID*RDRAM_LENGTH)
#define RDRAM_1_BASE_ADDRESS	(RDRAM_1_DEVICE_ID*RDRAM_LENGTH)
#define RDRAM_0_CONFIG		0x00000
#define RDRAM_1_CONFIG		0x00400
#define RDRAM_GLOBAL_CONFIG	0x80000
#define PIF_ROM_START		0x1FC00000
#define PIF_ROM_END		0x1FC007BF
#define PIF_RAM_START		0x1FC007C0
#define PIF_RAM_END		0x1FC007FF
#define CHNL_ERR_NORESP		0x80	/* Bit 7 (Rx): No response error */
#define CHNL_ERR_OVERRUN	0x40	/* Bit 6 (Rx): Overrun error */
#define CHNL_ERR_FRAME		0x80	/* Bit 7 (Tx): Frame error */
#define CHNL_ERR_COLLISION	0x40	/* Bit 6 (Tx): Collision error */
#define CHNL_ERR_MASK		0xC0	/* Bit 6-7: channel errors */
#define DEVICE_TYPE_CART	0	/* ROM cartridge */
#define DEVICE_TYPE_BULK	1	/* ROM bulk */
#define DEVICE_TYPE_64DD	2	/* 64 Disk Drive */
#define SP_DMEM_START		0x04000000	/* read/write */
#define SP_DMEM_END		0x04000FFF
#define SP_IMEM_START		0x04001000	/* read/write */
#define SP_IMEM_END		0x04001FFF
#define SP_BASE_REG		0x04040000
#define SP_MEM_ADDR_REG		(SP_BASE_REG+0x00)	/* Master */
#define SP_DRAM_ADDR_REG	(SP_BASE_REG+0x04)	/* Slave */
#define SP_RD_LEN_REG		(SP_BASE_REG+0x08)	/* R/W: read len */
#define SP_WR_LEN_REG		(SP_BASE_REG+0x0C)	/* R/W: write len */
#define SP_STATUS_REG		(SP_BASE_REG+0x10)
#define SP_DMA_FULL_REG		(SP_BASE_REG+0x14)
#define SP_DMA_BUSY_REG		(SP_BASE_REG+0x18)
#define SP_SEMAPHORE_REG	(SP_BASE_REG+0x1C)
#define SP_PC_REG		0x04080000
#define SP_DMA_DMEM		0x0000		/* Bit 12: 0=DMEM, 1=IMEM */
#define SP_DMA_IMEM		0x1000		/* Bit 12: 0=DMEM, 1=IMEM */
#define SP_CLR_HALT		0x00001	    /* Bit  0: clear halt */
#define SP_SET_HALT		0x00002	    /* Bit  1: set halt */
#define SP_CLR_BROKE		0x00004	    /* Bit  2: clear broke */
#define SP_CLR_INTR		0x00008	    /* Bit  3: clear intr */
#define SP_SET_INTR		0x00010	    /* Bit  4: set intr */
#define SP_CLR_SSTEP		0x00020	    /* Bit  5: clear sstep */
#define SP_SET_SSTEP		0x00040	    /* Bit  6: set sstep */
#define SP_CLR_INTR_BREAK	0x00080	    /* Bit  7: clear intr on break */
#define SP_SET_INTR_BREAK	0x00100	    /* Bit  8: set intr on break */
#define SP_CLR_SIG0		0x00200	    /* Bit  9: clear signal 0 */
#define SP_SET_SIG0		0x00400	    /* Bit 10: set signal 0 */
#define SP_CLR_SIG1		0x00800	    /* Bit 11: clear signal 1 */
#define SP_SET_SIG1		0x01000	    /* Bit 12: set signal 1 */
#define SP_CLR_SIG2		0x02000	    /* Bit 13: clear signal 2 */
#define SP_SET_SIG2		0x04000	    /* Bit 14: set signal 2 */
#define SP_CLR_SIG3		0x08000	    /* Bit 15: clear signal 3 */
#define SP_SET_SIG3		0x10000	    /* Bit 16: set signal 3 */
#define SP_CLR_SIG4		0x20000	    /* Bit 17: clear signal 4 */
#define SP_SET_SIG4		0x40000	    /* Bit 18: set signal 4 */
#define SP_CLR_SIG5		0x80000	    /* Bit 19: clear signal 5 */
#define SP_SET_SIG5	       0x100000	    /* Bit 20: set signal 5 */
#define SP_CLR_SIG6	       0x200000	    /* Bit 21: clear signal 6 */
#define SP_SET_SIG6	       0x400000	    /* Bit 22: set signal 6 */
#define SP_CLR_SIG7	       0x800000	    /* Bit 23: clear signal 7 */
#define SP_SET_SIG7	      0x1000000	    /* Bit 24: set signal 7 */
#define SP_STATUS_HALT		0x001		/* Bit  0: halt */
#define SP_STATUS_BROKE		0x002		/* Bit  1: broke */
#define SP_STATUS_DMA_BUSY	0x004		/* Bit  2: dma busy */
#define SP_STATUS_DMA_FULL	0x008		/* Bit  3: dma full */
#define SP_STATUS_IO_FULL	0x010		/* Bit  4: io full */
#define SP_STATUS_SSTEP		0x020		/* Bit  5: single step */
#define SP_STATUS_INTR_BREAK	0x040		/* Bit  6: interrupt on break */
#define SP_STATUS_SIG0		0x080		/* Bit  7: signal 0 set */
#define SP_STATUS_SIG1		0x100		/* Bit  8: signal 1 set */
#define SP_STATUS_SIG2		0x200		/* Bit  9: signal 2 set */
#define SP_STATUS_SIG3		0x400		/* Bit 10: signal 3 set */
#define SP_STATUS_SIG4		0x800		/* Bit 11: signal 4 set */
#define SP_STATUS_SIG5	       0x1000		/* Bit 12: signal 5 set */
#define SP_STATUS_SIG6	       0x2000		/* Bit 13: signal 6 set */
#define SP_STATUS_SIG7	       0x4000		/* Bit 14: signal 7 set */
#define SP_CLR_YIELD		SP_CLR_SIG0
#define SP_SET_YIELD		SP_SET_SIG0
#define SP_STATUS_YIELD		SP_STATUS_SIG0
#define SP_CLR_YIELDED		SP_CLR_SIG1
#define SP_SET_YIELDED		SP_SET_SIG1
#define SP_STATUS_YIELDED	SP_STATUS_SIG1
#define SP_CLR_TASKDONE		SP_CLR_SIG2
#define SP_SET_TASKDONE		SP_SET_SIG2
#define SP_STATUS_TASKDONE	SP_STATUS_SIG2
#define SP_IBIST_REG	0x04080004
#define SP_IBIST_CHECK		0x01		/* Bit 0: BIST check */
#define SP_IBIST_GO		0x02		/* Bit 1: BIST go */
#define SP_IBIST_CLEAR		0x04		/* Bit 2: BIST clear */
#define SP_IBIST_DONE		0x04		/* Bit 2: BIST done */
#define SP_IBIST_FAILED		0x78		/* Bit [6:3]: BIST fail */
#define DPC_BASE_REG		0x04100000
#define DPC_START_REG		(DPC_BASE_REG+0x00)
#define DPC_END_REG		(DPC_BASE_REG+0x04)
#define DPC_CURRENT_REG		(DPC_BASE_REG+0x08)	
#define DPC_STATUS_REG		(DPC_BASE_REG+0x0C)
#define DPC_CLOCK_REG		(DPC_BASE_REG+0x10)	
#define DPC_BUFBUSY_REG		(DPC_BASE_REG+0x14)
#define DPC_PIPEBUSY_REG	(DPC_BASE_REG+0x18)
#define DPC_TMEM_REG		(DPC_BASE_REG+0x1C)
#define DPC_CLR_XBUS_DMEM_DMA	0x0001		/* Bit 0: clear xbus_dmem_dma */
#define DPC_SET_XBUS_DMEM_DMA	0x0002		/* Bit 1: set xbus_dmem_dma */
#define DPC_CLR_FREEZE		0x0004		/* Bit 2: clear freeze */
#define DPC_SET_FREEZE		0x0008		/* Bit 3: set freeze */
#define DPC_CLR_FLUSH		0x0010		/* Bit 4: clear flush */
#define DPC_SET_FLUSH		0x0020		/* Bit 5: set flush */
#define DPC_CLR_TMEM_CTR	0x0040		/* Bit 6: clear tmem ctr */
#define DPC_CLR_PIPE_CTR	0x0080		/* Bit 7: clear pipe ctr */
#define DPC_CLR_CMD_CTR		0x0100		/* Bit 8: clear cmd ctr */
#define DPC_CLR_CLOCK_CTR	0x0200		/* Bit 9: clear clock ctr */
#define DPC_STATUS_XBUS_DMEM_DMA	0x001	/* Bit  0: xbus_dmem_dma */
#define DPC_STATUS_FREEZE		0x002	/* Bit  1: freeze */
#define DPC_STATUS_FLUSH		0x004	/* Bit  2: flush */
#define DPC_STATUS_START_GCLK		0x008	/* Bit  3: start gclk */
#define DPC_STATUS_TMEM_BUSY		0x010	/* Bit  4: tmem busy */
#define DPC_STATUS_PIPE_BUSY		0x020	/* Bit  5: pipe busy */
#define DPC_STATUS_CMD_BUSY		0x040	/* Bit  6: cmd busy */
#define DPC_STATUS_CBUF_READY		0x080	/* Bit  7: cbuf ready */
#define DPC_STATUS_DMA_BUSY		0x100	/* Bit  8: dma busy */
#define DPC_STATUS_END_VALID		0x200	/* Bit  9: end valid */
#define DPC_STATUS_START_VALID		0x400	/* Bit 10: start valid */
#define DPS_BASE_REG		0x04200000
#define DPS_TBIST_REG		(DPS_BASE_REG+0x00)
#define DPS_TEST_MODE_REG	(DPS_BASE_REG+0x04)
#define DPS_BUFTEST_ADDR_REG	(DPS_BASE_REG+0x08)
#define DPS_BUFTEST_DATA_REG	(DPS_BASE_REG+0x0C)
#define DPS_TBIST_CHECK		0x01		/* Bit 0: BIST check */
#define DPS_TBIST_GO		0x02		/* Bit 1: BIST go */
#define DPS_TBIST_CLEAR		0x04		/* Bit 2: BIST clear */
#define DPS_TBIST_DONE		0x004		/* Bit 2: BIST done */
#define DPS_TBIST_FAILED	0x7F8		/* Bit [10:3]: BIST fail */
#define MI_BASE_REG		0x04300000
#define MI_INIT_MODE_REG	(MI_BASE_REG+0x00)
#define MI_MODE_REG		MI_INIT_MODE_REG
#define MI_CLR_INIT		0x0080		/* Bit  7: clear init mode */
#define MI_SET_INIT		0x0100		/* Bit  8: set init mode */
#define MI_CLR_EBUS		0x0200		/* Bit  9: clear ebus test */
#define MI_SET_EBUS		0x0400		/* Bit 10: set ebus test mode */
#define MI_CLR_DP_INTR		0x0800		/* Bit 11: clear dp interrupt */
#define MI_CLR_RDRAM		0x1000		/* Bit 12: clear RDRAM reg */
#define MI_SET_RDRAM		0x2000		/* Bit 13: set RDRAM reg mode */
#define MI_MODE_INIT		0x0080		/* Bit  7: init mode */
#define MI_MODE_EBUS		0x0100		/* Bit  8: ebus test mode */
#define MI_MODE_RDRAM		0x0200		/* Bit  9: RDRAM reg mode */
#define MI_VERSION_REG		(MI_BASE_REG+0x04)
#define MI_NOOP_REG		MI_VERSION_REG
#define MI_INTR_REG		(MI_BASE_REG+0x08)
#define MI_INTR_MASK_REG	(MI_BASE_REG+0x0C)
#define MI_INTR_SP		0x01		/* Bit 0: SP intr */
#define MI_INTR_SI		0x02		/* Bit 1: SI intr */
#define MI_INTR_AI		0x04		/* Bit 2: AI intr */
#define MI_INTR_VI		0x08		/* Bit 3: VI intr */
#define MI_INTR_PI		0x10		/* Bit 4: PI intr */
#define MI_INTR_DP		0x20		/* Bit 5: DP intr */
#define MI_INTR_MASK_CLR_SP	0x0001		/* Bit  0: clear SP mask */
#define MI_INTR_MASK_SET_SP	0x0002		/* Bit  1: set SP mask */
#define MI_INTR_MASK_CLR_SI	0x0004		/* Bit  2: clear SI mask */
#define MI_INTR_MASK_SET_SI	0x0008		/* Bit  3: set SI mask */
#define MI_INTR_MASK_CLR_AI	0x0010		/* Bit  4: clear AI mask */
#define MI_INTR_MASK_SET_AI	0x0020		/* Bit  5: set AI mask */
#define MI_INTR_MASK_CLR_VI	0x0040		/* Bit  6: clear VI mask */
#define MI_INTR_MASK_SET_VI	0x0080		/* Bit  7: set VI mask */
#define MI_INTR_MASK_CLR_PI	0x0100		/* Bit  8: clear PI mask */
#define MI_INTR_MASK_SET_PI	0x0200		/* Bit  9: set PI mask */
#define MI_INTR_MASK_CLR_DP	0x0400		/* Bit 10: clear DP mask */
#define MI_INTR_MASK_SET_DP	0x0800		/* Bit 11: set DP mask */
#define MI_INTR_MASK_SP		0x01		/* Bit 0: SP intr mask */
#define MI_INTR_MASK_SI		0x02		/* Bit 1: SI intr mask */
#define MI_INTR_MASK_AI		0x04		/* Bit 2: AI intr mask */
#define MI_INTR_MASK_VI		0x08		/* Bit 3: VI intr mask */
#define MI_INTR_MASK_PI		0x10		/* Bit 4: PI intr mask */
#define MI_INTR_MASK_DP		0x20		/* Bit 5: DP intr mask */
#define VI_BASE_REG		0x04400000
#define VI_STATUS_REG		(VI_BASE_REG+0x00)
#define VI_CONTROL_REG		VI_STATUS_REG
#define VI_ORIGIN_REG		(VI_BASE_REG+0x04)
#define VI_DRAM_ADDR_REG	VI_ORIGIN_REG
#define VI_WIDTH_REG		(VI_BASE_REG+0x08)	
#define VI_H_WIDTH_REG		VI_WIDTH_REG
#define VI_INTR_REG		(VI_BASE_REG+0x0C)	
#define VI_V_INTR_REG		VI_INTR_REG
#define VI_CURRENT_REG		(VI_BASE_REG+0x10)	
#define VI_V_CURRENT_LINE_REG	VI_CURRENT_REG
#define VI_BURST_REG		(VI_BASE_REG+0x14)	
#define VI_TIMING_REG		VI_BURST_REG
#define VI_V_SYNC_REG		(VI_BASE_REG+0x18)	
#define VI_H_SYNC_REG		(VI_BASE_REG+0x1C)	
#define VI_LEAP_REG		(VI_BASE_REG+0x20)	
#define VI_H_SYNC_LEAP_REG	VI_LEAP_REG
#define VI_H_START_REG		(VI_BASE_REG+0x24)
#define VI_H_VIDEO_REG		VI_H_START_REG
#define VI_V_START_REG		(VI_BASE_REG+0x28)
#define VI_V_VIDEO_REG		VI_V_START_REG
#define VI_V_BURST_REG		(VI_BASE_REG+0x2C)	
#define VI_X_SCALE_REG		(VI_BASE_REG+0x30)	
#define VI_Y_SCALE_REG		(VI_BASE_REG+0x34)	
#define VI_CTRL_TYPE_16		 0x00002    /* Bit [1:0] pixel size: 16 bit */
#define VI_CTRL_TYPE_32		 0x00003    /* Bit [1:0] pixel size: 32 bit */
#define VI_CTRL_GAMMA_DITHER_ON	 0x00004    /* Bit 2: default = on */
#define VI_CTRL_GAMMA_ON	 0x00008    /* Bit 3: default = on */
#define VI_CTRL_DIVOT_ON	 0x00010    /* Bit 4: default = on */
#define VI_CTRL_SERRATE_ON	 0x00040    /* Bit 6: on if interlaced */
#define VI_CTRL_ANTIALIAS_MASK	 0x00300    /* Bit [9:8] anti-alias mode */
#define VI_CTRL_DITHER_FILTER_ON 0x10000    /* Bit 16: dither-filter mode */
#define VI_NTSC_CLOCK		48681812        /* Hz = 48.681812 MHz */
#define VI_PAL_CLOCK		49656530        /* Hz = 49.656530 MHz */
#define VI_MPAL_CLOCK		48628316        /* Hz = 48.628316 MHz */
#define AI_BASE_REG		0x04500000
#define AI_DRAM_ADDR_REG	(AI_BASE_REG+0x00)	/* R0: DRAM address */
#define AI_LEN_REG		(AI_BASE_REG+0x04)	/* R1: Length */
#define AI_CONTROL_REG		(AI_BASE_REG+0x08)	/* R2: DMA Control */
#define AI_STATUS_REG		(AI_BASE_REG+0x0C)	/* R3: Status */
#define AI_DACRATE_REG		(AI_BASE_REG+0x10)	/* R4: DAC rate 14-lsb*/
#define AI_BITRATE_REG		(AI_BASE_REG+0x14)	/* R5: Bit rate 4-lsb */
#define AI_CONTROL_DMA_ON	0x01			/* LSB = 1: DMA enable*/
#define AI_CONTROL_DMA_OFF	0x00			/* LSB = 1: DMA enable*/
#define AI_STATUS_FIFO_FULL	0x80000000		/* Bit 31: full */
#define AI_STATUS_DMA_BUSY	0x40000000		/* Bit 30: busy */
#define AI_MAX_DAC_RATE         16384           /* 14-bit+1 */
#define AI_MIN_DAC_RATE         132
#define AI_MAX_BIT_RATE         16              /* 4-bit+1 */
#define AI_MIN_BIT_RATE         2
#define AI_NTSC_MAX_FREQ        368000          /* 368 KHz */
#define AI_NTSC_MIN_FREQ        3000            /*   3 KHz ~ 2971 Hz */
#define AI_PAL_MAX_FREQ         376000          /* 376 KHz */
#define AI_PAL_MIN_FREQ         3050            /*   3 KHz ~ 3031 Hz */
#define AI_MPAL_MAX_FREQ        368000          /* 368 KHz */
#define AI_MPAL_MIN_FREQ        3000            /*   3 KHz ~ 2968 Hz */
#define PI_BASE_REG		0x04600000
#define PI_DRAM_ADDR_REG	(PI_BASE_REG+0x00)	/* DRAM address */
#define PI_CART_ADDR_REG	(PI_BASE_REG+0x04)
#define PI_RD_LEN_REG		(PI_BASE_REG+0x08)
#define PI_WR_LEN_REG		(PI_BASE_REG+0x0C)
#define PI_STATUS_REG		(PI_BASE_REG+0x10)
#define PI_BSD_DOM1_LAT_REG	(PI_BASE_REG+0x14)
#define PI_BSD_DOM1_PWD_REG	(PI_BASE_REG+0x18)
#define PI_BSD_DOM1_PGS_REG	(PI_BASE_REG+0x1C)    /*   page size */
#define PI_BSD_DOM1_RLS_REG	(PI_BASE_REG+0x20)
#define PI_BSD_DOM2_LAT_REG	(PI_BASE_REG+0x24)    /* Domain 2 latency */
#define PI_BSD_DOM2_PWD_REG	(PI_BASE_REG+0x28)    /*   pulse width */
#define PI_BSD_DOM2_PGS_REG	(PI_BASE_REG+0x2C)    /*   page size */
#define PI_BSD_DOM2_RLS_REG	(PI_BASE_REG+0x30)    /*   release duration */
#define	PI_DOMAIN1_REG		PI_BSD_DOM1_LAT_REG
#define	PI_DOMAIN2_REG		PI_BSD_DOM2_LAT_REG
#define PI_DOM_LAT_OFS		0x00
#define PI_DOM_PWD_OFS		0x04
#define PI_DOM_PGS_OFS		0x08
#define PI_DOM_RLS_OFS		0x0C
#define	PI_STATUS_ERROR		0x04
#define	PI_STATUS_IO_BUSY	0x02
#define	PI_STATUS_DMA_BUSY	0x01
#define	PI_STATUS_RESET		0x01
#define	PI_SET_RESET		PI_STATUS_RESET
#define	PI_STATUS_CLR_INTR	0x02
#define	PI_CLR_INTR		PI_STATUS_CLR_INTR
#define	PI_DMA_BUFFER_SIZE	128
#define PI_DOM1_ADDR1		0x06000000	/* to 0x07FFFFFF */
#define PI_DOM1_ADDR2		0x10000000	/* to 0x1FBFFFFF */
#define PI_DOM1_ADDR3		0x1FD00000	/* to 0x7FFFFFFF */
#define PI_DOM2_ADDR1		0x05000000	/* to 0x05FFFFFF */
#define PI_DOM2_ADDR2		0x08000000	/* to 0x0FFFFFFF */
#define RI_BASE_REG		0x04700000
#define RI_MODE_REG		(RI_BASE_REG+0x00)	
#define RI_CONFIG_REG		(RI_BASE_REG+0x04)
#define RI_CURRENT_LOAD_REG	(RI_BASE_REG+0x08)
#define RI_SELECT_REG		(RI_BASE_REG+0x0C)
#define RI_REFRESH_REG		(RI_BASE_REG+0x10)
#define RI_COUNT_REG		RI_REFRESH_REG
#define RI_LATENCY_REG		(RI_BASE_REG+0x14)
#define RI_RERROR_REG		(RI_BASE_REG+0x18)
#define RI_WERROR_REG		(RI_BASE_REG+0x1C)
#define SI_BASE_REG		0x04800000
#define SI_DRAM_ADDR_REG	(SI_BASE_REG+0x00)	/* R0: DRAM address */
#define SI_PIF_ADDR_RD64B_REG	(SI_BASE_REG+0x04)	/* R1: 64B PIF->DRAM */
#define SI_PIF_ADDR_WR64B_REG	(SI_BASE_REG+0x10)	/* R4: 64B DRAM->PIF */
#define SI_STATUS_REG		(SI_BASE_REG+0x18)	/* R6: Status */
#define	SI_STATUS_DMA_BUSY	0x0001
#define	SI_STATUS_RD_BUSY	0x0002
#define	SI_STATUS_DMA_ERROR	0x0008
#define	SI_STATUS_INTERRUPT	0x1000
#define GIO_BASE_REG		0x18000000
#define GIO_GIO_INTR_REG	(GIO_BASE_REG+0x000)
#define GIO_GIO_SYNC_REG	(GIO_BASE_REG+0x400)
#define GIO_CART_INTR_REG	(GIO_BASE_REG+0x800)
#define	IO_READ(addr)		(*(vu32 *)PHYS_TO_K1(addr))
#define	IO_WRITE(addr,data)	(*(vu32 *)PHYS_TO_K1(addr)=(u32)(data))
#define RCP_STAT_PRINT							\
	rmonPrintf("current=%x start=%x end=%x dpstat=%x spstat=%x
#define	_OS_H_
#define OS_STATE_STOPPED	1
#define OS_STATE_RUNNABLE	2
#define OS_STATE_RUNNING	4
#define OS_STATE_WAITING	8
#define OS_NUM_EVENTS           15
#define OS_NUM_EVENTS           23
#define OS_EVENT_SW1              0     /* CPU SW1 interrupt */
#define OS_EVENT_SW2              1     /* CPU SW2 interrupt */
#define OS_EVENT_CART             2     /* Cartridge interrupt: used by rmon */
#define OS_EVENT_COUNTER          3     /* Counter int: used by VI/Timer Mgr */
#define OS_EVENT_SP               4     /* SP task done interrupt */
#define OS_EVENT_SI               5     /* SI (controller) interrupt */
#define OS_EVENT_AI               6     /* AI interrupt */
#define OS_EVENT_VI               7     /* VI interrupt: used by VI/Timer Mgr */
#define OS_EVENT_PI               8     /* PI interrupt: used by PI Manager */
#define OS_EVENT_DP               9     /* DP full sync interrupt */
#define OS_EVENT_CPU_BREAK        10    /* CPU breakpoint: used by rmon */
#define OS_EVENT_SP_BREAK         11    /* SP breakpoint:  used by rmon */
#define OS_EVENT_FAULT            12    /* CPU fault event: used by rmon */
#define OS_EVENT_THREADSTATUS     13    /* CPU thread status: used by rmon */
#define OS_EVENT_PRENMI           14    /* Pre NMI interrupt */
#define OS_EVENT_RDB_READ_DONE    15    /* RDB read ok event: used by rmon */
#define OS_EVENT_RDB_LOG_DONE     16    /* read of log data complete */
#define OS_EVENT_RDB_DATA_DONE    17    /* read of hostio data complete */
#define OS_EVENT_RDB_REQ_RAMROM   18    /* host needs ramrom access */
#define OS_EVENT_RDB_FREE_RAMROM  19    /* host is done with ramrom access */
#define OS_EVENT_RDB_DBG_DONE     20
#define OS_EVENT_RDB_FLUSH_PROF   21
#define OS_EVENT_RDB_ACK_PROF     22
#define	OS_FLAG_CPU_BREAK	1	/* Break exception has occurred */
#define	OS_FLAG_FAULT		2	/* CPU fault has occurred */
#define	OS_IM_NONE	0x00000001
#define	OS_IM_SW1	0x00000501
#define	OS_IM_SW2	0x00000601
#define	OS_IM_CART	0x00000c01
#define	OS_IM_PRENMI	0x00001401
#define OS_IM_RDBWRITE	0x00002401
#define OS_IM_RDBREAD	0x00004401
#define	OS_IM_COUNTER	0x00008401
#define	OS_IM_CPU	0x0000ff01
#define	OS_IM_SP	0x00010401
#define	OS_IM_SI	0x00020401
#define	OS_IM_AI	0x00040401
#define	OS_IM_VI	0x00080401
#define	OS_IM_PI	0x00100401
#define	OS_IM_DP	0x00200401
#define	OS_IM_ALL	0x003fff01
#define	RCP_IMASK	0x003f0000
#define	RCP_IMASKSHIFT	16
#define OS_PRIORITY_MAX		255
#define OS_PRIORITY_VIMGR	254
#define OS_PRIORITY_RMON	250
#define OS_PRIORITY_RMONSPIN	200
#define OS_PRIORITY_PIMGR	150
#define OS_PRIORITY_SIMGR	140
#define	OS_PRIORITY_APPMAX	127
#define OS_PRIORITY_IDLE	  0	/* Must be 0 */
#define	OS_MESG_NOBLOCK		0
#define	OS_MESG_BLOCK		1
#define	OS_READ			0		/* device -> RDRAM */
#define	OS_WRITE		1		/* device <- RDRAM */
#define	OS_OTHERS		2		/* for Leo disk only */
#define OS_MESG_TYPE_BASE	(10)
#define OS_MESG_TYPE_LOOPBACK	(OS_MESG_TYPE_BASE+0)
#define OS_MESG_TYPE_DMAREAD	(OS_MESG_TYPE_BASE+1)
#define OS_MESG_TYPE_DMAWRITE	(OS_MESG_TYPE_BASE+2)
#define OS_MESG_TYPE_VRETRACE	(OS_MESG_TYPE_BASE+3)
#define OS_MESG_TYPE_COUNTER	(OS_MESG_TYPE_BASE+4)
#define OS_MESG_TYPE_EDMAREAD	(OS_MESG_TYPE_BASE+5)
#define OS_MESG_TYPE_EDMAWRITE	(OS_MESG_TYPE_BASE+6)
#define OS_MESG_PRI_NORMAL	0
#define OS_MESG_PRI_HIGH	1
#define OS_PM_4K	0x0000000
#define OS_PM_16K	0x0006000
#define OS_PM_64K	0x001e000
#define OS_PM_256K	0x007e000
#define OS_PM_1M	0x01fe000
#define OS_PM_4M	0x07fe000
#define OS_PM_16M	0x1ffe000
#define OS_PIM_STACKSIZE	4096
#define OS_VIM_STACKSIZE	4096
#define OS_SIM_STACKSIZE	4096
#define	OS_MIN_STACKSIZE	72
#define	OS_TV_PAL		0
#define	OS_TV_NTSC		1
#define	OS_TV_MPAL		2
#define OS_VI_NTSC_LPN1		0	/* NTSC */
#define OS_VI_NTSC_LPF1		1
#define OS_VI_NTSC_LAN1		2
#define OS_VI_NTSC_LAF1		3
#define OS_VI_NTSC_LPN2		4
#define OS_VI_NTSC_LPF2		5
#define OS_VI_NTSC_LAN2		6
#define OS_VI_NTSC_LAF2		7
#define OS_VI_NTSC_HPN1		8
#define OS_VI_NTSC_HPF1		9
#define OS_VI_NTSC_HAN1		10
#define OS_VI_NTSC_HAF1		11
#define OS_VI_NTSC_HPN2		12
#define OS_VI_NTSC_HPF2		13
#define OS_VI_PAL_LPN1		14	/* PAL */
#define OS_VI_PAL_LPF1		15
#define OS_VI_PAL_LAN1		16
#define OS_VI_PAL_LAF1		17
#define OS_VI_PAL_LPN2		18
#define OS_VI_PAL_LPF2		19
#define OS_VI_PAL_LAN2		20
#define OS_VI_PAL_LAF2		21
#define OS_VI_PAL_HPN1		22
#define OS_VI_PAL_HPF1		23
#define OS_VI_PAL_HAN1		24
#define OS_VI_PAL_HAF1		25
#define OS_VI_PAL_HPN2		26
#define OS_VI_PAL_HPF2		27
#define OS_VI_MPAL_LPN1		28	/* MPAL - mainly Brazil */
#define OS_VI_MPAL_LPF1		29
#define OS_VI_MPAL_LAN1		30
#define OS_VI_MPAL_LAF1		31
#define OS_VI_MPAL_LPN2		32
#define OS_VI_MPAL_LPF2		33
#define OS_VI_MPAL_LAN2		34
#define OS_VI_MPAL_LAF2		35
#define OS_VI_MPAL_HPN1		36
#define OS_VI_MPAL_HPF1		37
#define OS_VI_MPAL_HAN1		38
#define OS_VI_MPAL_HAF1		39
#define OS_VI_MPAL_HPN2		40
#define OS_VI_MPAL_HPF2		41
#define	OS_VI_GAMMA_ON			0x0001
#define	OS_VI_GAMMA_OFF			0x0002
#define	OS_VI_GAMMA_DITHER_ON		0x0004
#define	OS_VI_GAMMA_DITHER_OFF		0x0008
#define	OS_VI_DIVOT_ON			0x0010
#define	OS_VI_DIVOT_OFF			0x0020
#define	OS_VI_DITHER_FILTER_ON		0x0040
#define	OS_VI_DITHER_FILTER_OFF		0x0080
#define OS_VI_BIT_NONINTERLACE		0x0001          /* lo-res */
#define OS_VI_BIT_INTERLACE		0x0002          /* lo-res */
#define OS_VI_BIT_NORMALINTERLACE	0x0004          /* hi-res */
#define OS_VI_BIT_DEFLICKINTERLACE	0x0008          /* hi-res */
#define OS_VI_BIT_ANTIALIAS		0x0010
#define OS_VI_BIT_POINTSAMPLE		0x0020
#define OS_VI_BIT_16PIXEL		0x0040
#define OS_VI_BIT_32PIXEL		0x0080
#define OS_VI_BIT_LORES			0x0100
#define OS_VI_BIT_HIRES			0x0200
#define OS_VI_BIT_NTSC			0x0400
#define OS_VI_BIT_PAL			0x0800
#define LEO_BLOCK_MODE	1
#define LEO_TRACK_MODE	2
#define LEO_SECTOR_MODE	3
#define MAXCONTROLLERS  4
#define MAXCONTROLLERS  6
#define CONT_NO_RESPONSE_ERROR          0x8
#define CONT_OVERRUN_ERROR              0x4
#define CONT_FRAME_ERROR                0x2
#define CONT_COLLISION_ERROR            0x1
#define CONT_ABSOLUTE           0x0001
#define CONT_RELATIVE           0x0002
#define CONT_JOYPORT            0x0004
#define CONT_EEPROM		0x8000
#define CONT_CARD_ON            0x01
#define CONT_CARD_PULL          0x02
#define CONT_ADDR_CRC_ER        0x04
#define CONT_EEPROM_BUSY	0x80
#define CONT_A      0x8000
#define CONT_B      0x4000
#define CONT_G	    0x2000
#define CONT_START  0x1000
#define CONT_UP     0x0800
#define CONT_DOWN   0x0400
#define CONT_LEFT   0x0200
#define CONT_RIGHT  0x0100
#define CONT_L      0x0020
#define CONT_R      0x0010
#define CONT_E      0x0008
#define CONT_D      0x0004
#define CONT_C      0x0002
#define CONT_F      0x0001
#define A_BUTTON	CONT_A
#define B_BUTTON	CONT_B
#define L_TRIG		CONT_L
#define R_TRIG		CONT_R
#define Z_TRIG		CONT_G
#define START_BUTTON	CONT_START
#define U_JPAD		CONT_UP
#define L_JPAD		CONT_LEFT
#define R_JPAD		CONT_RIGHT
#define D_JPAD		CONT_DOWN
#define U_CBUTTONS	CONT_E
#define L_CBUTTONS	CONT_C
#define R_CBUTTONS	CONT_F
#define D_CBUTTONS	CONT_D
#define PFS_FILE_NAME_LEN       16
#define PFS_FILE_EXT_LEN        4
#define BLOCKSIZE		32		/* bytes */
#define PFS_ONE_PAGE            8		/* blocks */
#define PFS_MAX_BANKS		62
#define PFS_READ                0
#define PFS_WRITE               1
#define PFS_CREATE              2
#define PFS_INITIALIZED		0x1
#define PFS_CORRUPTED		0x2		/* File system was corrupted */
#define PFS_ERR_NOPACK		1	/* no memory card is plugged or   */
#define PFS_ERR_NEW_PACK        2	/* ram pack has been changed to a */
#define PFS_ERR_INCONSISTENT    3	/* need to run Pfschecker 	  */
#define PFS_ERR_CONTRFAIL	CONT_OVERRUN_ERROR              
#define PFS_ERR_INVALID         5	/* invalid parameter or file not exist*/
#define PFS_ERR_BAD_DATA        6       /* the data read from pack are bad*/
#define PFS_DATA_FULL           7	/* no free pages on ram pack      */
#define PFS_DIR_FULL            8	/* no free directories on ram pack*/
#define PFS_ERR_EXIST		9	/* file exists 			  */
#define PFS_ERR_ID_FATAL	10	/* dead ram pack */
#define PFS_ERR_DEVICE		11	/* wrong device type*/
#define EEPROM_MAXBLOCKS	64
#define EEPROM_BLOCK_SIZE	8
#define PROF_MIN_INTERVAL	50	/* microseconds */
#define	BOOT_ADDRESS_ULTRA	0x80000400
#define	BOOT_ADDRESS_COSIM	0x80002000
#define	BOOT_ADDRESS_EMU	0x20010000
#define	BOOT_ADDRESS_INDY 	0x88100000
#define OS_APP_NMI_BUFSIZE	64
#define MQ_GET_COUNT(mq)        ((mq)->validCount)
#define MQ_IS_EMPTY(mq)		(MQ_GET_COUNT(mq) == 0)
#define MQ_IS_FULL(mq)		(MQ_GET_COUNT(mq) >= (mq)->msgCount)
#define OS_NSEC_TO_CYCLES(n)	(((u64)(n)*(osClockRate))/1000000000LL)
#define OS_USEC_TO_CYCLES(n)	(((u64)(n)*(osClockRate))/1000000LL)
#define OS_CYCLES_TO_NSEC(c)	(((u64)(c)*1000000000LL)/(osClockRate))
#define OS_CYCLES_TO_USEC(c)	(((u64)(c)*1000000LL)/(osClockRate))
#define	OS_DCACHE_ROUNDUP_ADDR(x)	(void *)(((((u32)(x)+0xf)/0x10)*0x10))
#define	OS_DCACHE_ROUNDUP_SIZE(x)	(u32)(((((u32)(x)+0xf)/0x10)*0x10))
#define	OS_K0_TO_PHYSICAL(x)	(u32)(((char *)(x)-0x80000000))
#define	OS_K1_TO_PHYSICAL(x)	(u32)(((char *)(x)-0xa0000000))
#define	OS_PHYSICAL_TO_K0(x)	(void *)(((u32)(x)+0x80000000))
#define	OS_PHYSICAL_TO_K1(x)	(void *)(((u32)(x)+0xa0000000))
#define R_MODE                     0
#define W_MODE                     1
#define REQ_C2                     0x01 /* C2 correction request */
#define SECTOR_READ                0x02 /* target is only 1 sector (not block) */
#define NO_RETRY                   0x04 /* no retry done at read */
#define LOCK_C2_PARAM              0x08 /* c2 correction parameter is locked (never change) */
#define DISABLE_C2                 0x10 /* disable c2 correction. use for DC2 or EEC bit handling */
#define WRITE_MODE                 0x20 /* write mode */
#define C1_ERROR_LIMIT             4 /* C2������������ǽ��C1���׎��ε��ƿ� */
#define DISK_TYPES                 7 /* �Îގ������μ���ο� */
#define ZONES_PER_DRV              9 /* �Ďގ׎��̎ޤΎ��ގ��ݿ� (HD0:0��7 / HD1:1��8)  */
#define HEADS_PER_DRV              2 /* �Ďގ׎��̎ޤΎ͎��Ď޿�                        */
#define VZONES_PER_DRV             ((ZONES_PER_DRV - 1) * HEADS_PER_DRV)
#define SPARE_CYLS_PER_ZONE        4 /* ���������ގ��ݤ��Ѱդ���Ƥ��뎽�͎ߎ����؎ݎ��޿� */
#define BLK_P_TRK                  2 /* 1�Ď׎�����������̎ގێ�����          */
#define SYSTEM_LBAS               24 /* �����Î��ΰ�Ύ̎ގێ�����             */
#define SYS_DATA_LBA1              2 /* �����ÎѾ��󤬵�Ͽ���줿LBA       */
#define SYS_DATA_LBA2              3 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_DATA_LBA3             10 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_DATA_LBA4             11 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_UNCORR_LBA            12 /* ���ˎߎ��̎ߎێÎ����Ѥθ�C2����LBA     */
#define SYS_DATA_LBA1              0 /* �����ÎѾ��󤬵�Ͽ���줿LBA       */
#define SYS_DATA_LBA2              1 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_DATA_LBA3              8 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_DATA_LBA4              9 /* �����ÎѾ��󤬵�Ͽ���줿LBA(ͽ��) */
#define SYS_UNCORR_LBA            12 /* ���ˎߎ��̎ߎێÎ����Ѥθ�C2����LBA     */
#define RD_BYTES_PER_DRV           0x03d78f40UL
#define MAX_P_LBA                  0x10dbUL
#define MAX_L_LBA                  (MAX_P_LBA - SYSTEM_LBAS)
#define USR_SECS_PER_BLK          85 /* 1�����̎ގێ�����ΎՎ����ގ������Ѳ�ǽ�ʎ������� */
#define C2_SECS_PER_BLK            4 /* 1�����̎ގێ������C2����Ύ�������          */
#define GAP_SECS_PER_BLK           1 /* 1�����̎ގێ������GAP��������               */
#define HALF_SECS_U16         0x5900 /* 1�����̎ގێ������ͭ����������(GAP�����)<<16*/
#define C1_LENGTH                  7 /* �Ǝ�������C1�����ĎޤΎʎގ��Ŀ� */
#define SEC_SIZE_ZONE0           232 /* ���ގ���0��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE1           216 /* ���ގ���1��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE2           208 /* ���ގ���2��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE3           192 /* ���ގ���3��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE4           176 /* ���ގ���4��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE5           160 /* ���ގ���5��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE6           144 /* ���ގ���6��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE7           128 /* ���ގ���7��1�������Ύʎގ��Ŀ�   */
#define SEC_SIZE_ZONE8           112 /* ���ގ���8��1�������Ύʎގ��Ŀ�   */
#define ALL_SECS_PER_BLK         (USR_SECS_PER_BLK + C2_SECS_PER_BLK + GAP_SECS_PER_BLK)
#define GAP_BYTES_ZONE0          4
#define TK_PER_ZONE0_HD0         150 /* �͎��Ď�0�����ގ���0�ΎĎ׎�����(���ؤ��Ď׎����������ÎюĎ׎����ޤ�) */
#define TK_PER_ZONE1_HD0         150 /* �͎��Ď�0�����ގ���1�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE2_HD0         141 /* �͎��Ď�0�����ގ���2�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE3_HD0         141 /* �͎��Ď�0�����ގ���3�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE4_HD0         141 /* �͎��Ď�0�����ގ���4�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE5_HD0         141 /* �͎��Ď�0�����ގ���5�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE6_HD0         141 /* �͎��Ď�0�����ގ���6�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE7_HD0         106 /* �͎��Ď�0�����ގ���7�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE1_HD1         150 /* �͎��Ď�1�����ގ���1�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE2_HD1         150 /* �͎��Ď�1�����ގ���2�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE3_HD1         141 /* �͎��Ď�1�����ގ���3�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE4_HD1         141 /* �͎��Ď�1�����ގ���4�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE5_HD1         141 /* �͎��Ď�1�����ގ���5�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE6_HD1         141 /* �͎��Ď�1�����ގ���6�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE7_HD1         141 /* �͎��Ď�1�����ގ���7�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define TK_PER_ZONE8_HD1         106 /* �͎��Ď�1�����ގ���8�ΎĎ׎�����(���ؤ��Ď׎����ޤ�) */
#define ALT_TK_PER_ZONE            4 /* �Ǝ��ގ��ݤ����ؤ��Ď׎����� */
#define SYSTEM_TK                 12 /* �����Î��ΰ�ΎĎ׎�����     */
#define MSEQ_RD_GAP1_ADR           1
#define MSEQ_RD_DATA_ADR           4
#define MSEQ_RD_GAP2_ADR           7
#define MSEQ_WR_GAP1_ADR           1
#define MSEQ_WR_DATA_ADR           4
#define MSEQ_WR_GAP2_ADR           8
#define MSEQ_LEN                  16
#define ASIC_NO_OPERATION          0x00000000
#define ASIC_RD_SEEK               0x00010001
#define ASIC_WR_SEEK               0x00020001
#define ASIC_RECAL                 0x00030001
#define ASIC_SLEEP                 0x00040000
#define ASIC_START                 0x00050001
#define ASIC_SET_STBY              0x00060000
#define ASIC_SET_SLEEP             0x00070000
#define ASIC_CLR_CHGFLG            0x00080000
#define ASIC_CLR_RSTFLG            0x00090000
#define ASIC_RD_VERSION            0x000a0000
#define ASIC_SET_DTYPE             0x000b0001
#define ASIC_REQ_STATUS            0x000c0000
#define ASIC_STANDBY               0x000d0000
#define ASIC_INDEX_LOCK_RETRY      0x000e0001
#define ASIC_SET_TIMER_YEAR        0x000f0000
#define ASIC_SET_TIMER_DATE        0x00100000
#define ASIC_SET_TIMER_MINUTE      0x00110000
#define ASIC_READ_TIMER_YEAR       0x00120000
#define ASIC_READ_TIMER_DATE       0x00130000
#define ASIC_READ_TIMER_MINUTE     0x00140000
#define ASIC_NEED_DISK_IN          0x00000001 /* �Îގ��������׎����פ�Ƚ�ꤹ��̎׎��� */
#define ASIC_DUMMY_DATA            0x00000000
#define MC_ERR_DIAGNOSTIC          0x00010000 /* �Ҏ����ݤμ��ʿ��ǎ��׎�       */
#define MC_ERR_SERVO_DATA          0x00020000 /* �����Ύ޾���Ύ؎��Ď�NG        */
#define MC_ERR_INDEX               0x00040000 /* ���ݎÎގ������θ��Фȴֳ֤�NG */
#define MC_ERR_SETRING_TIMEOUT     0x00080000 /* ���Ď؎ݎ��ގ����ю�����ȯ��        */
#define MC_ERR_UNDEFINE_CMD        0x00100000 /* ̤����Ύ��ώݎĎޤ����     */
#define MC_INVALID_PARAM           0x00200000 /* DATA out of range       */
#define ASIC_IO_BASE       0x05000000
#define ASIC_C2_BUFF       (ASIC_IO_BASE+0x0000) /* C2�Îގ������Ǽ����ʎގ��̎� */
#define ASIC_SECTOR_BUFF   (ASIC_IO_BASE+0x0400) /* C2������Ԥ��Îގ����юʎގ��̎� */
#define MSEQ_RAM_ADDR      (ASIC_IO_BASE+0x0580) /* �ώ����ێ��������ݎ�����Ƭ���Ďގڎ� */
#define ASIC_DATA          (ASIC_IO_BASE+0x0500) /* W / R */
#define ASIC_MISC_REG      (ASIC_IO_BASE+0x0504) /* R     */
#define ASIC_STATUS        (ASIC_IO_BASE+0x0508) /* R     */
#define ASIC_CMD           (ASIC_IO_BASE+0x0508) /* W     */
#define ASIC_CUR_TK        (ASIC_IO_BASE+0x050c) /* R     */
#define ASIC_BM_STATUS     (ASIC_IO_BASE+0x0510) /* R     */
#define ASIC_BM_CTL        (ASIC_IO_BASE+0x0510) /* W     */
#define ASIC_ERR_SECTOR    (ASIC_IO_BASE+0x0514) /* R     */
#define ASIC_SEQ_STATUS    (ASIC_IO_BASE+0x0518) /* R     */
#define ASIC_SEQ_CTL       (ASIC_IO_BASE+0x0518) /* W     */
#define ASIC_CUR_SECTOR    (ASIC_IO_BASE+0x051c) /* R     */
#define ASIC_HARD_RESET    (ASIC_IO_BASE+0x0520) /* W     */
#define ASIC_C1_S0         (ASIC_IO_BASE+0x0524) /* R     */
#define ASIC_HOST_SECBYTE  (ASIC_IO_BASE+0x0528) /* W / R */
#define ASIC_C1_S2         (ASIC_IO_BASE+0x052c) /* R     */
#define ASIC_SEC_BYTE      (ASIC_IO_BASE+0x0530) /* W / R */
#define ASIC_C1_S4         (ASIC_IO_BASE+0x0534) /* R     */
#define ASIC_C1_S6         (ASIC_IO_BASE+0x0538) /* R     */
#define ASIC_CUR_ADDR      (ASIC_IO_BASE+0x053c) /* R     */
#define ASIC_ID_REG        (ASIC_IO_BASE+0x0540) /* R     */
#define ASIC_TEST_REG      (ASIC_IO_BASE+0x0544) /* R     */
#define ASIC_TEST_PIN_SEL  (ASIC_IO_BASE+0x0548) /* W     */
#define LEO_STAT_DATA_REQ      0x40000000
#define LEO_STAT_C2_XFER       0x10000000
#define LEO_STAT_BM_ERROR      0x08000000
#define LEO_STAT_BM_INT        0x04000000
#define LEO_STAT_MECHA_INT     0x02000000
#define LEO_STAT_DISK          0x01000000
#define LEO_STAT_BUSY          0x00800000
#define LEO_STAT_RESET         0x00400000
#define LEO_STAT_SPM_OFF       0x00100000
#define LEO_STAT_HEAD_RETRACT  0x00080000
#define LEO_STAT_WPROTECT_ERR  0x00040000
#define LEO_STAT_MECHA_ERROR   0x00020000
#define LEO_STAT_DISK_CHANGE   0x00010000
#define LEO_STAT_MASK          0xffff0000
#define LEO_STAT_NC_CHK        0x0000ffff
#define LEO_STAT_WRITE_END     0x00000000
#define LEO_BMST_RUNNING       0x80000000 /* bit 15 */
#define LEO_BMST_ERROR         0x04000000 /* bit 10 */
#define LEO_BMST_MICRO_STATUS  0x02000000 /* bit  9 */
#define LEO_BMST_BLOCKS        0x01000000 /* bit  8 */
#define LEO_BMST_C1_CORRECT    0x00800000 /* bit  7 */
#define LEO_BMST_C1_DOUBLE     0x00400000 /* bit  6 */
#define LEO_BMST_C1_SINGLE     0x00200000 /* bit  5 */
#define LEO_BMST_C1_ERROR      0x00010000 /* bit  0 */
#define START_BM               0x80000000
#define BM_MODE                0x40000000
#define BM_INT_MASK            0x20000000
#define BM_RESET               0x10000000
#define BM_DISABLE_OR_CHK      0x08000000
#define BM_DISABLE_C1          0x04000000
#define BM_XFERBLKS            0x02000000
#define BM_MECHA_INT_RESET     0x01000000
#define BIT_AM_FAIL            0x80000000
#define BIT_MICRO_FAIL         0x40000000
#define BIT_SPINDLE_FAIL       0x20000000
#define BIT_OVER_RUN           0x10000000
#define BIT_OFFTRACK           0x08000000
#define BIT_NO_DISK            0x04000000
#define BIT_CLOCK_UNLOCK       0x02000000
#define BIT_SELF_STOP          0x01000000
#define MICRO_INT_MASK         0x80000000
#define MICRO_PC_ENABLE        0x40000000
#define BIT_INDEX_LOCK         0x60000000
#define ASIC_RESET_CODE        0xaaaa0000
#define   leoAd16ReadIo(adr,data)    osEPiReadIo(LEOPiInfo,adr,data)
#define   leoAd16WriteIo(adr,data)   osEPiWriteIo(LEOPiInfo,adr,data)
#define   leoAd16StartDma(flag)      LEOpiDmaParam.hdr.type = flag, \
                                     osEPiStartDma(LEOpiInfo,&LEOpiDmaParam)
#define leoGet_leo_status(x)       osEPiReadIo(LEOPiInfo,ASIC_STATUS, x)
#define leoGet_leo_bm_status(x)    osEPiReadIo(LEOPiInfo,ASIC_BM_STATUS, x)
#define leoGet_leo_err_sec(x)      osEPiReadIo(LEOPiInfo,ASIC_ERR_SECTOR, x)
#define leoGet_leo_asic_id(x)      osEPiReadIo(LEOPiInfo,ASIC_ID_REG, x)
#define leoGet_leo_asic_data(x)    osEPiReadIo(LEOPiInfo,ASIC_DATA, x)
#define leoGet_leo_cur_tk(x)       osEPiReadIo(LEOPiInfo,ASIC_CUR_TK, x)
#define leoMicro_pc_disable()      LEOasic_seq_ctl_shadow &= (~MICRO_PC_ENABLE),\
                                   osEPiWriteIo(LEOPiInfo,ASIC_SEQ_CTL,LEOasic_seq_ctl_shadow)
#define leoMicro_pc_enable()       LEOasic_seq_ctl_shadow |= MICRO_PC_ENABLE,\
                                   osEPiWriteIo(LEOPiInfo,ASIC_SEQ_CTL,LEOasic_seq_ctl_shadow)
#define leoClear_bm_error()        osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL,(LEOasic_bm_ctl_shadow | BM_RESET) ),\
                                   osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL, LEOasic_bm_ctl_shadow)
#define leoStart_sequencer()       osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL,(LEOasic_bm_ctl_shadow | START_BM))
#define leoStop_sequencer()        osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL,(LEOasic_bm_ctl_shadow | BM_RESET) ),\
                                   osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL, LEOasic_bm_ctl_shadow)
#define leoClear_mecha_int()       osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL,(LEOasic_bm_ctl_shadow | (BM_MECHA_INT_RESET+BM_INT_MASK))),\
                                   osEPiWriteIo(LEOPiInfo,ASIC_BM_CTL,(LEOasic_bm_ctl_shadow &= (~BM_INT_MASK)));
#define leoChk_sys_read()          (LEOdrive_flag &  (u8)0x02)
#define leoSet_sys_read()          (LEOdrive_flag |= (u8)0x02)
#define leoClr_sys_read()          (LEOdrive_flag &= (u8)0xfd)
#define leoChk_clr_que_flag()      (LEOdrive_flag &  (u8)0x04)
#define leoSet_clr_que_flag()      (LEOdrive_flag |= (u8)0x04)
#define leoClr_clr_que_flag()      (LEOdrive_flag &= (u8)0xfb)
#define leoSeek_read_i()           (leoSeek_i(R_MODE))
#define leoSeek_write_i()          (leoSeek_i(W_MODE))
#define  LEO_DISK_TYPE_MIN    0
#define  LEO_DISK_TYPE_MAX    6
#define  LEO_LBA_MIN          0
#define  LEO_LBA_MAX          4291
#define  LEO_LBA_ROM_TOP      LEO_LBA_MIN
#define  LEO_LBA_ROM_END0     1417
#define  LEO_LBA_ROM_END1     1965
#define  LEO_LBA_ROM_END2     2513
#define  LEO_LBA_ROM_END3     3061
#define  LEO_LBA_ROM_END4     3609
#define  LEO_LBA_ROM_END5     4087
#define  LEO_LBA_ROM_END6     LEO_LBA_MAX
#define  LEO_LBA_RAM_TOP0     (LEO_LBA_ROM_END0+1)
#define  LEO_LBA_RAM_TOP1     (LEO_LBA_ROM_END1+1)
#define  LEO_LBA_RAM_TOP2     (LEO_LBA_ROM_END2+1)
#define  LEO_LBA_RAM_TOP3     (LEO_LBA_ROM_END3+1)
#define  LEO_LBA_RAM_TOP4     (LEO_LBA_ROM_END4+1)
#define  LEO_LBA_RAM_TOP5     (LEO_LBA_ROM_END5+1)
#define  LEO_LBA_RAM_TOP6     (LEO_LBA_ROM_END6+1)
#define  LEO_LBA_RAM_END6     LEO_LBA_MAX
#define  LEO_PRIORITY_WRK   (OS_PRIORITY_PIMGR-1)
#define  LEO_PRIORITY_INT   OS_PRIORITY_PIMGR
#define LEO_COMMAND_CLEAR_QUE         0x01
#define LEO_COMMAND_INQUIRY           0x02
#define LEO_COMMAND_TEST_UNIT_READY   0x03
#define LEO_COMMAND_REZERO            0x04
#define LEO_COMMAND_READ              0x05
#define LEO_COMMAND_WRITE             0x06
#define LEO_COMMAND_SEEK              0x07
#define LEO_COMMAND_START_STOP        0x08
#define LEO_COMMAND_READ_CAPACITY     0x09
#define LEO_COMMAND_TRANSLATE         0x0a
#define LEO_COMMAND_MODE_SELECT       0x0b
#define LEO_COMMAND_READ_DISK_ID      0x0c
#define LEO_COMMAND_READ_TIMER        0x0d
#define LEO_COMMAND_SET_TIMER         0x0e
#define LEO_CONTROL_POST              0x80   /* ENABLE POST QUEUE */
#define LEO_CONTROL_START             0x01   /* START COMMAND */
#define LEO_CONTROL_STBY              0x02   /* STAND-BY MODE(NOT SLEEP MODE) */
#define LEO_CONTROL_WRT               0x01   /* READ RE-WRITE-ABLE CAPACITY */
#define LEO_CONTROL_TBL               0x01   /* TRANSLATE BYTE TO LBA */
#define LEO_TEST_UNIT_MR              0x01   /* MEDIUM REMOVED */
#define LEO_TEST_UNIT_RE              0x02   /* HEAD RETRACTED */
#define LEO_TEST_UNIT_SS              0x04   /* SPINDLE STOPPED */
#define LEO_STATUS_GOOD               0x00
#define LEO_STATUS_CHECK_CONDITION    0x02
#define LEO_STATUS_BUSY               0x08
#define LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION   00
#define LEO_SENSE_DRIVE_NOT_READY                  01
#define LEO_SENSE_DIAGNOSTIC_FAILURE               02
#define LEO_SENSE_COMMAND_PHASE_ERROR              03
#define LEO_SENSE_DATA_PHASE_ERROR                 04
#define LEO_SENSE_INCOMPATIBLE_MEDIUM_INSTALLED    11
#define LEO_SENSE_UNKNOWN_FORMAT                   11
#define LEO_SENSE_NO_SEEK_COMPLETE                 21
#define LEO_SENSE_WRITE_FAULT                      22
#define LEO_SENSE_UNRECOVERED_READ_ERROR           23
#define LEO_SENSE_NO_REFERENCE_POSITION_FOUND      24 
#define LEO_SENSE_TRACK_FOLLOWING_ERROR            25
#define LEO_SENSE_TRACKING_OR_SPDL_SERVO_FAILURE   25
#define LEO_SENSE_INVALID_COMMAND_OPERATION_CODE   31
#define LEO_SENSE_LBA_OUT_OF_RANGE                 32
#define LEO_SENSE_WRITE_PROTECT_ERROR              33
#define LEO_SENSE_COMMAND_TERMINATED               34
#define LEO_SENSE_QUEUE_FULL                       35
#define LEO_SENSE_DEVICE_COMMUNICATION_FAILURE     41
#define LEO_SENSE_MEDIUM_NOT_PRESENT               42
#define LEO_SENSE_POWERONRESET_DEVICERESET_OCCURED 43
#define LEO_SENSE_MEDIUM_MAY_HAVE_CHANGED          47
#define _PIINT_H_
#define PI_DOMAIN1	0
#define PI_DOMAIN2	1
#define SC_OVERRUN_ERROR 29	

#define NULL ((void*)0)
#define PHYS_TO_K1(a) ((u32)(a)|0xa0000000)
#define IO_READ(a) (*(volatile u32 *)PHYS_TO_K1(a))
#define IO_WRITE(a,b) (*(volatile u32 *)PHYS_TO_K1(a)=(b))
#define K1_TO_PHYS(a) ((u32)(a)&0x1fffffff)
extern OSPiHandle D_8013A160;
extern OSPiHandle *D_8013A1D4,*D_800EF22C;
extern u32 D_800EE4DC;
extern s32 D_800EE4E0;
#define LeoDiskHandle D_8013A160
#define __osDiskHandle D_8013A1D4
#define __osPiTable D_800EF22C
#define __OSGlobalIntMask D_800EE4DC
#define osDiskExist D_800EE4E0
#define __osLeoAbnormalResume func_800A6EB4
#define osEPiRawStartDma func_800A7380
#define osEPiRawWriteIo func_800AFF50
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
void _bzero(void*,s32);
#define bzero _bzero
u32 func_800A5750(void);void func_800A5770(u32);
void __osLeoResume(void);void func_800A6EB4(void);
s32 func_800A7380(OSPiHandle*,s32,u32,void*,u32);
s32 func_800AFF50(OSPiHandle*,u32,u32);
s32 osRecvMesg(OSMesgQueue*,OSMesg*,s32);s32 osSendMesg(OSMesgQueue*,OSMesg,s32);
void __osResetGlobalIntMask(u32);void __osSetGlobalIntMask(u32);void osYieldThread(void);
#define RESETMASK 		0xfffffbfe
#define LEO_DISK_STACKSIZE	4096
#define LeoAbort(errCode) 	blockInfo->errStatus = errCode;	\
				__osLeoAbnormalResume(); 	\
				return(1)	
#define PIWait()		pi_stat = IO_READ(PI_STATUS_REG);	\
				while (pi_stat & PI_STATUS_IO_BUSY)  {  \
					pi_stat = IO_READ(PI_STATUS_REG);}

