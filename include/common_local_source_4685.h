


#define __STDC__ 1
#define __STDC_HOSTED__ 1
#define __STDC_VERSION__ 201710L
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_EMBED_NOT_FOUND__ 0
#define __STDC_EMBED_FOUND__ 1
#define __STDC_EMBED_EMPTY__ 2



#define _LANGUAGE_C 1






#define F3DEX_GBI 




#define _ULTRATYPES_H_ 

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;

typedef signed char s8;
typedef short s16;
typedef long s32;
typedef long long s64;

typedef volatile unsigned char vu8;
typedef volatile unsigned short vu16;
typedef volatile unsigned long vu32;
typedef volatile unsigned long long vu64;

typedef volatile signed char vs8;
typedef volatile short vs16;
typedef volatile long vs32;
typedef volatile long long vs64;

typedef float f32;
typedef double f64;








#define TRUE 1



#define FALSE 0



#define NULL 0



#define _OS_H_ 

typedef s32 OSPri;
typedef s32 OSId;
typedef union { struct { f32 f_odd; f32 f_even; } f; f64 d; } __OSfp;

typedef struct {
 u64 at, v0, v1, a0, a1, a2, a3;
 u64 t0, t1, t2, t3, t4, t5, t6, t7;
 u64 s0, s1, s2, s3, s4, s5, s6, s7;
 u64 t8, t9, gp, sp, s8, ra;
 u64 lo, hi;
 u32 sr, pc, cause, badvaddr, rcp;
 u32 fpcsr;
 __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
 __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;

typedef struct OSThread_s {
 struct OSThread_s *next;
 OSPri priority;
 struct OSThread_s **queue;
 struct OSThread_s *tlnext;
 u16 state;
 u16 flags;
 OSId id;
 int fp;
 __OSThreadContext context;
} OSThread;

typedef u32 OSEvent;
typedef u32 OSIntMask;
typedef u32 OSPageMask;
typedef u32 OSHWIntr;




typedef void * OSMesg;




typedef struct OSMesgQueue_s {
 OSThread *mtqueue;

 OSThread *fullqueue;

 s32 validCount;
 s32 first;
 s32 msgCount;
 OSMesg *msg;
} OSMesgQueue;

typedef struct {
 u32 errStatus;
        void *dramAddr;
 void *C2Addr;
 u32 sectorSize;
 u32 C1ErrNum;
 u32 C1ErrSector[4];
} __OSBlockInfo;

typedef struct {
 u32 cmdType;
 u16 transferMode;
 u16 blockNum;
 s32 sectorNum;
 u32 devAddr;
 u32 bmCtlShadow;
 u32 seqCtlShadow;
 __OSBlockInfo block[2];
} __OSTranxInfo;


typedef struct OSPiHandle_s {
        struct OSPiHandle_s *next;
        u8 type;
        u8 latency;
        u8 pageSize;
        u8 relDuration;
        u8 pulse;
        u32 baseAddress;
        u32 speed;

        __OSTranxInfo transferInfo;
} OSPiHandle;

typedef struct {
        u8 type;
        u8 status;
        u32 address;
} OSPiInfo;




typedef struct {
        u16 type;
        u8 pri;
        u8 status;
 OSMesgQueue *retQueue;

} OSIoMesgHdr;

typedef struct {
 OSIoMesgHdr hdr;
 void * dramAddr;
 u32 devAddr;
 u32 size;
 OSPiHandle *piHandle;
} OSIoMesg;




typedef struct {
        s32 active;
 OSThread *thread;
        OSMesgQueue *cmdQueue;
        OSMesgQueue *evtQueue;
        OSMesgQueue *acsQueue;

        s32 (*dma)(s32, u32, void *, u32);
        s32 (*edma)(OSPiHandle *, s32, u32, void *, u32);
} OSDevMgr;





typedef struct {
    u32 ctrl;
    u32 width;
    u32 burst;
    u32 vSync;
    u32 hSync;
    u32 leap;
    u32 hStart;
    u32 xScale;
    u32 vCurrent;
} OSViCommonRegs;





typedef struct {
    u32 origin;
    u32 yScale;
    u32 vStart;
    u32 vBurst;
    u32 vIntr;
} OSViFieldRegs;





typedef struct {
    u8 type;
    OSViCommonRegs comRegs;
    OSViFieldRegs fldRegs[2];
} OSViMode;




typedef u64 OSTime;




typedef struct OSTimer_s {
 struct OSTimer_s *next;
 struct OSTimer_s *prev;
 OSTime interval;
 OSTime value;

 OSMesgQueue *mq;
 OSMesg msg;
} OSTimer;





typedef struct {
 u16 type;
 u8 status;
 u8 errno;
}OSContStatus;

typedef struct {
 u16 button;
 s8 stick_x;
 s8 stick_y;
 u8 errno;
} OSContPad;

typedef struct {
 void *address;
 u8 databuffer[32];
        u8 addressCrc;
 u8 dataCrc;
 u8 errno;
} OSContRamIo;







typedef struct {
 int status;
 OSMesgQueue *queue;
 int channel;
 u8 id[32];
 u8 label[32];
 int version;
 int dir_size;
 int inode_table;
 int minode_table;
 int dir_table;
 int inode_start_page;
 u8 banks;
 u8 activebank;
} OSPfs;


typedef struct {
 u32 file_size;
   u32 game_code;
   u16 company_code;
   char ext_name[4];
   char game_name[16];
} OSPfsState;




typedef struct {
 u16 *histo_base;
 u32 histo_size;
 u32 *text_start;
 u32 *text_end;
} OSProf;

#define OS_STATE_STOPPED 1
#define OS_STATE_RUNNABLE 2
#define OS_STATE_RUNNING 4
#define OS_STATE_WAITING 8





#define OS_NUM_EVENTS 23


#define OS_EVENT_SW1 0
#define OS_EVENT_SW2 1
#define OS_EVENT_CART 2
#define OS_EVENT_COUNTER 3
#define OS_EVENT_SP 4
#define OS_EVENT_SI 5
#define OS_EVENT_AI 6
#define OS_EVENT_VI 7
#define OS_EVENT_PI 8
#define OS_EVENT_DP 9
#define OS_EVENT_CPU_BREAK 10
#define OS_EVENT_SP_BREAK 11
#define OS_EVENT_FAULT 12
#define OS_EVENT_THREADSTATUS 13
#define OS_EVENT_PRENMI 14

#define OS_EVENT_RDB_READ_DONE 15
#define OS_EVENT_RDB_LOG_DONE 16
#define OS_EVENT_RDB_DATA_DONE 17
#define OS_EVENT_RDB_REQ_RAMROM 18
#define OS_EVENT_RDB_FREE_RAMROM 19
#define OS_EVENT_RDB_DBG_DONE 20
#define OS_EVENT_RDB_FLUSH_PROF 21
#define OS_EVENT_RDB_ACK_PROF 22




#define OS_FLAG_CPU_BREAK 1
#define OS_FLAG_FAULT 2



#define OS_IM_NONE 0x00000001
#define OS_IM_SW1 0x00000501
#define OS_IM_SW2 0x00000601
#define OS_IM_CART 0x00000c01
#define OS_IM_PRENMI 0x00001401
#define OS_IM_RDBWRITE 0x00002401
#define OS_IM_RDBREAD 0x00004401
#define OS_IM_COUNTER 0x00008401
#define OS_IM_CPU 0x0000ff01
#define OS_IM_SP 0x00010401
#define OS_IM_SI 0x00020401
#define OS_IM_AI 0x00040401
#define OS_IM_VI 0x00080401
#define OS_IM_PI 0x00100401
#define OS_IM_DP 0x00200401
#define OS_IM_ALL 0x003fff01
#define RCP_IMASK 0x003f0000
#define RCP_IMASKSHIFT 16



#define OS_PRIORITY_MAX 255
#define OS_PRIORITY_VIMGR 254
#define OS_PRIORITY_RMON 250
#define OS_PRIORITY_RMONSPIN 200
#define OS_PRIORITY_PIMGR 150
#define OS_PRIORITY_SIMGR 140
#define OS_PRIORITY_APPMAX 127
#define OS_PRIORITY_IDLE 0




#define OS_MESG_NOBLOCK 0
#define OS_MESG_BLOCK 1



#define OS_READ 0
#define OS_WRITE 1
#define OS_OTHERS 2




#define OS_MESG_TYPE_BASE (10)
#define OS_MESG_TYPE_LOOPBACK (OS_MESG_TYPE_BASE+0)
#define OS_MESG_TYPE_DMAREAD (OS_MESG_TYPE_BASE+1)
#define OS_MESG_TYPE_DMAWRITE (OS_MESG_TYPE_BASE+2)
#define OS_MESG_TYPE_VRETRACE (OS_MESG_TYPE_BASE+3)
#define OS_MESG_TYPE_COUNTER (OS_MESG_TYPE_BASE+4)
#define OS_MESG_TYPE_EDMAREAD (OS_MESG_TYPE_BASE+5)
#define OS_MESG_TYPE_EDMAWRITE (OS_MESG_TYPE_BASE+6)




#define OS_MESG_PRI_NORMAL 0
#define OS_MESG_PRI_HIGH 1




#define OS_PM_4K 0x0000000
#define OS_PM_16K 0x0006000
#define OS_PM_64K 0x001e000
#define OS_PM_256K 0x007e000
#define OS_PM_1M 0x01fe000
#define OS_PM_4M 0x07fe000
#define OS_PM_16M 0x1ffe000






#define OS_PIM_STACKSIZE 4096
#define OS_VIM_STACKSIZE 4096
#define OS_SIM_STACKSIZE 4096

#define OS_MIN_STACKSIZE 72




#define OS_TV_PAL 0
#define OS_TV_NTSC 1
#define OS_TV_MPAL 2




#define OS_VI_NTSC_LPN1 0
#define OS_VI_NTSC_LPF1 1
#define OS_VI_NTSC_LAN1 2
#define OS_VI_NTSC_LAF1 3
#define OS_VI_NTSC_LPN2 4
#define OS_VI_NTSC_LPF2 5
#define OS_VI_NTSC_LAN2 6
#define OS_VI_NTSC_LAF2 7
#define OS_VI_NTSC_HPN1 8
#define OS_VI_NTSC_HPF1 9
#define OS_VI_NTSC_HAN1 10
#define OS_VI_NTSC_HAF1 11
#define OS_VI_NTSC_HPN2 12
#define OS_VI_NTSC_HPF2 13

#define OS_VI_PAL_LPN1 14
#define OS_VI_PAL_LPF1 15
#define OS_VI_PAL_LAN1 16
#define OS_VI_PAL_LAF1 17
#define OS_VI_PAL_LPN2 18
#define OS_VI_PAL_LPF2 19
#define OS_VI_PAL_LAN2 20
#define OS_VI_PAL_LAF2 21
#define OS_VI_PAL_HPN1 22
#define OS_VI_PAL_HPF1 23
#define OS_VI_PAL_HAN1 24
#define OS_VI_PAL_HAF1 25
#define OS_VI_PAL_HPN2 26
#define OS_VI_PAL_HPF2 27

#define OS_VI_MPAL_LPN1 28
#define OS_VI_MPAL_LPF1 29
#define OS_VI_MPAL_LAN1 30
#define OS_VI_MPAL_LAF1 31
#define OS_VI_MPAL_LPN2 32
#define OS_VI_MPAL_LPF2 33
#define OS_VI_MPAL_LAN2 34
#define OS_VI_MPAL_LAF2 35
#define OS_VI_MPAL_HPN1 36
#define OS_VI_MPAL_HPF1 37
#define OS_VI_MPAL_HAN1 38
#define OS_VI_MPAL_HAF1 39
#define OS_VI_MPAL_HPN2 40
#define OS_VI_MPAL_HPF2 41




#define OS_VI_GAMMA_ON 0x0001
#define OS_VI_GAMMA_OFF 0x0002
#define OS_VI_GAMMA_DITHER_ON 0x0004
#define OS_VI_GAMMA_DITHER_OFF 0x0008
#define OS_VI_DIVOT_ON 0x0010
#define OS_VI_DIVOT_OFF 0x0020
#define OS_VI_DITHER_FILTER_ON 0x0040
#define OS_VI_DITHER_FILTER_OFF 0x0080




#define OS_VI_BIT_NONINTERLACE 0x0001
#define OS_VI_BIT_INTERLACE 0x0002
#define OS_VI_BIT_NORMALINTERLACE 0x0004
#define OS_VI_BIT_DEFLICKINTERLACE 0x0008
#define OS_VI_BIT_ANTIALIAS 0x0010
#define OS_VI_BIT_POINTSAMPLE 0x0020
#define OS_VI_BIT_16PIXEL 0x0040
#define OS_VI_BIT_32PIXEL 0x0080
#define OS_VI_BIT_LORES 0x0100
#define OS_VI_BIT_HIRES 0x0200
#define OS_VI_BIT_NTSC 0x0400
#define OS_VI_BIT_PAL 0x0800







#define LEO_BLOCK_MODE 1
#define LEO_TRACK_MODE 2
#define LEO_SECTOR_MODE 3






#define MAXCONTROLLERS 4





#define CONT_NO_RESPONSE_ERROR 0x8
#define CONT_OVERRUN_ERROR 0x4







#define CONT_ABSOLUTE 0x0001
#define CONT_RELATIVE 0x0002
#define CONT_JOYPORT 0x0004
#define CONT_EEPROM 0x8000



#define CONT_CARD_ON 0x01
#define CONT_CARD_PULL 0x02
#define CONT_ADDR_CRC_ER 0x04
#define CONT_EEPROM_BUSY 0x80



#define CONT_A 0x8000
#define CONT_B 0x4000
#define CONT_G 0x2000
#define CONT_START 0x1000
#define CONT_UP 0x0800
#define CONT_DOWN 0x0400
#define CONT_LEFT 0x0200
#define CONT_RIGHT 0x0100
#define CONT_L 0x0020
#define CONT_R 0x0010
#define CONT_E 0x0008
#define CONT_D 0x0004
#define CONT_C 0x0002
#define CONT_F 0x0001



#define A_BUTTON CONT_A
#define B_BUTTON CONT_B
#define L_TRIG CONT_L
#define R_TRIG CONT_R
#define Z_TRIG CONT_G
#define START_BUTTON CONT_START
#define U_JPAD CONT_UP
#define L_JPAD CONT_LEFT
#define R_JPAD CONT_RIGHT
#define D_JPAD CONT_DOWN
#define U_CBUTTONS CONT_E
#define L_CBUTTONS CONT_C
#define R_CBUTTONS CONT_F
#define D_CBUTTONS CONT_D



#define PFS_FILE_NAME_LEN 16
#define PFS_FILE_EXT_LEN 4
#define BLOCKSIZE 32
#define PFS_ONE_PAGE 8
#define PFS_MAX_BANKS 62



#define PFS_READ 0
#define PFS_WRITE 1
#define PFS_CREATE 2


#define PFS_INITIALIZED 0x1
#define PFS_CORRUPTED 0x2



#define PFS_ERR_NOPACK 1
#define PFS_ERR_NEW_PACK 2

#define PFS_ERR_INCONSISTENT 3
#define PFS_ERR_CONTRFAIL CONT_OVERRUN_ERROR
#define PFS_ERR_INVALID 5
#define PFS_ERR_BAD_DATA 6
#define PFS_DATA_FULL 7
#define PFS_DIR_FULL 8
#define PFS_ERR_EXIST 9
#define PFS_ERR_ID_FATAL 10
#define PFS_ERR_DEVICE 11



#define EEPROM_MAXBLOCKS 64
#define EEPROM_BLOCK_SIZE 8




#define PROF_MIN_INTERVAL 50




#define BOOT_ADDRESS_ULTRA 0x80000400
#define BOOT_ADDRESS_COSIM 0x80002000
#define BOOT_ADDRESS_EMU 0x20010000
#define BOOT_ADDRESS_INDY 0x88100000




#define OS_APP_NMI_BUFSIZE 64

#define MQ_GET_COUNT(mq) ((mq)->validCount)


#define MQ_IS_EMPTY(mq) (MQ_GET_COUNT(mq) == 0)
#define MQ_IS_FULL(mq) (MQ_GET_COUNT(mq) >= (mq)->msgCount)








extern u64 osClockRate;

#define OS_NSEC_TO_CYCLES(n) (((u64)(n)*(osClockRate))/1000000000LL)
#define OS_USEC_TO_CYCLES(n) (((u64)(n)*(osClockRate))/1000000LL)
#define OS_CYCLES_TO_NSEC(c) (((u64)(c)*1000000000LL)/(osClockRate))
#define OS_CYCLES_TO_USEC(c) (((u64)(c)*1000000LL)/(osClockRate))







extern OSViMode osViModeTable[];

extern OSViMode osViModeNtscLpn1;
extern OSViMode osViModeNtscLpf1;
extern OSViMode osViModeNtscLan1;
extern OSViMode osViModeNtscLaf1;
extern OSViMode osViModeNtscLpn2;
extern OSViMode osViModeNtscLpf2;
extern OSViMode osViModeNtscLan2;
extern OSViMode osViModeNtscLaf2;
extern OSViMode osViModeNtscHpn1;
extern OSViMode osViModeNtscHpf1;
extern OSViMode osViModeNtscHan1;
extern OSViMode osViModeNtscHaf1;
extern OSViMode osViModeNtscHpn2;
extern OSViMode osViModeNtscHpf2;

extern OSViMode osViModePalLpn1;
extern OSViMode osViModePalLpf1;
extern OSViMode osViModePalLan1;
extern OSViMode osViModePalLaf1;
extern OSViMode osViModePalLpn2;
extern OSViMode osViModePalLpf2;
extern OSViMode osViModePalLan2;
extern OSViMode osViModePalLaf2;
extern OSViMode osViModePalHpn1;
extern OSViMode osViModePalHpf1;
extern OSViMode osViModePalHan1;
extern OSViMode osViModePalHaf1;
extern OSViMode osViModePalHpn2;
extern OSViMode osViModePalHpf2;

extern OSViMode osViModeMpalLpn1;
extern OSViMode osViModeMpalLpf1;
extern OSViMode osViModeMpalLan1;
extern OSViMode osViModeMpalLaf1;
extern OSViMode osViModeMpalLpn2;
extern OSViMode osViModeMpalLpf2;
extern OSViMode osViModeMpalLan2;
extern OSViMode osViModeMpalLaf2;
extern OSViMode osViModeMpalHpn1;
extern OSViMode osViModeMpalHpf1;
extern OSViMode osViModeMpalHan1;
extern OSViMode osViModeMpalHaf1;
extern OSViMode osViModeMpalHpn2;
extern OSViMode osViModeMpalHpf2;

extern s32 osRomType;
extern void *osRomBase;
extern s32 osTvType;
extern s32 osResetType;
extern s32 osCicId;
extern s32 osVersion;
extern u32 osMemSize;
extern s32 osAppNMIBuffer[];

extern OSIntMask __OSGlobalIntMask;
extern OSPiHandle *__osPiTable;
extern OSPiHandle *__osDiskHandle;
extern u32 osDiskExist;

extern void osCreateThread(OSThread *, OSId, void (*)(void *),
           void *, void *, OSPri);
extern void osDestroyThread(OSThread *);
extern void osYieldThread(void);
extern void osStartThread(OSThread *);
extern void osStopThread(OSThread *);
extern OSId osGetThreadId(OSThread *);
extern void osSetThreadPri(OSThread *, OSPri);
extern OSPri osGetThreadPri(OSThread *);



extern void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32);
extern s32 osSendMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osJamMesg(OSMesgQueue *, OSMesg, s32);
extern s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32);



extern void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg);



extern OSIntMask osGetIntMask(void);
extern OSIntMask osSetIntMask(OSIntMask);



extern void osInitRdb(u8 *sendBuf, u32 sendSize);



extern void osInvalDCache(void *, s32);
extern void osInvalICache(void *, s32);
extern void osWritebackDCache(void *, s32);
extern void osWritebackDCacheAll(void);

#define OS_DCACHE_ROUNDUP_ADDR(x) (void *)(((((u32)(x)+0xf)/0x10)*0x10))
#define OS_DCACHE_ROUNDUP_SIZE(x) (u32)(((((u32)(x)+0xf)/0x10)*0x10))



extern void osMapTLB(s32, OSPageMask, void *, u32, u32, s32);
extern void osMapTLBRdb(void);
extern void osUnmapTLB(s32);
extern void osUnmapTLBAll(void);
extern void osSetTLBASID(s32);



extern u32 osVirtualToPhysical(void *);
extern void * osPhysicalToVirtual(u32);

#define OS_K0_TO_PHYSICAL(x) (u32)(((char *)(x)-0x80000000))
#define OS_K1_TO_PHYSICAL(x) (u32)(((char *)(x)-0xa0000000))

#define OS_PHYSICAL_TO_K0(x) (void *)(((u32)(x)+0x80000000))
#define OS_PHYSICAL_TO_K1(x) (void *)(((u32)(x)+0xa0000000))




extern u32 osAiGetStatus(void);
extern u32 osAiGetLength(void);
extern s32 osAiSetFrequency(u32);
extern s32 osAiSetNextBuffer(void *, u32);


extern u32 osDpGetStatus(void);
extern void osDpSetStatus(u32);
extern void osDpGetCounters(u32 *);
extern s32 osDpSetNextBuffer(void *, u64);


extern u32 osPiGetStatus(void);
extern s32 osPiGetDeviceType(void);
extern s32 osPiRawWriteIo(u32, u32);
extern s32 osPiRawReadIo(u32, u32 *);
extern s32 osPiRawStartDma(s32, u32, void *, u32);
extern s32 osPiWriteIo(u32, u32);
extern s32 osPiReadIo(u32, u32 *);
extern s32 osPiStartDma(OSIoMesg *, s32, s32, u32, void *, u32,
         OSMesgQueue *);
extern void osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32);


extern u32 osViGetStatus(void);
extern u32 osViGetCurrentMode(void);
extern u32 osViGetCurrentLine(void);
extern u32 osViGetCurrentField(void);
extern void *osViGetCurrentFramebuffer(void);
extern void *osViGetNextFramebuffer(void);
extern void osViSetXScale(f32);
extern void osViSetYScale(f32);
extern void osViSetSpecialFeatures(u32);
extern void osViSetMode(OSViMode *);
extern void osViSetEvent(OSMesgQueue *, OSMesg, u32);
extern void osViSwapBuffer(void *);
extern void osViBlack(u8);
extern void osViFade(u8, u16);
extern void osRepeatLine(u8);
extern void osCreateViManager(OSPri);



extern OSTime osGetTime(void);
extern void osSetTime(OSTime);
extern int osSetTimer(OSTimer *, OSTime, OSTime,
       OSMesgQueue *, OSMesg);
extern int osStopTimer(OSTimer *);



extern s32 osContInit(OSMesgQueue *, u8 *, OSContStatus *);
extern s32 osContReset(OSMesgQueue *, OSContStatus *);
extern s32 osContStartQuery(OSMesgQueue *);
extern s32 osContStartReadData(OSMesgQueue *);

extern s32 osContSetCh(u8);

extern void osContGetQuery(OSContStatus *);
extern void osContGetReadData(OSContPad *);



extern s32 osPfsInit(OSMesgQueue *, OSPfs *, int);
extern s32 osPfsReFormat(OSPfs *, OSMesgQueue *, int);
extern s32 osPfsChecker(OSPfs *);
extern s32 osPfsAllocateFile(OSPfs *, u16, u32, u8 *, u8 *, int, s32 *);
extern s32 osPfsFindFile(OSPfs *, u16, u32, u8 *, u8 *, s32 *);
extern s32 osPfsDeleteFile(OSPfs *, u16, u32, u8 *, u8 *);
extern s32 osPfsReadWriteFile(OSPfs *, s32, u8, int, int, u8 *);
extern s32 osPfsFileState(OSPfs *, s32, OSPfsState *);
extern s32 osPfsGetLabel(OSPfs *, u8 *, int *);
extern s32 osPfsSetLabel(OSPfs *, u8 *);
extern s32 osPfsIsPlug(OSMesgQueue *, u8 *);
extern s32 osPfsFreeBlocks(OSPfs *, s32 *);
extern s32 osPfsNumFiles(OSPfs *, s32 *, s32 *);
extern s32 osPfsReSizeFile(OSPfs *, u16 , u32 , u8 *, u8 *, int);



extern s32 osEepromProbe(OSMesgQueue *);
extern s32 osEepromRead(OSMesgQueue *, u8, u8 *);
extern s32 osEepromWrite(OSMesgQueue *, u8, u8 *);
extern s32 osEepromLongRead(OSMesgQueue *, u8, u8 *, int);
extern s32 osEepromLongWrite(OSMesgQueue *, u8, u8 *, int);



extern OSPiHandle *osCartRomInit(void);
extern OSPiHandle *osLeoDiskInit(void);
extern OSPiHandle *osDriveRomInit(void);

extern s32 osEPiDeviceType(OSPiHandle *, OSPiInfo *);
extern s32 osEPiRawWriteIo(OSPiHandle *, u32 , u32);
extern s32 osEPiRawReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiRawStartDma(OSPiHandle *, s32 , u32 , void *, u32 );
extern s32 osEPiWriteIo(OSPiHandle *, u32 , u32 );
extern s32 osEPiReadIo(OSPiHandle *, u32 , u32 *);
extern s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32);



extern void osProfileInit(OSProf *, u32 profcnt);
extern void osProfileStart(u32);
extern void osProfileFlush(void);
extern void osProfileStop(void);



extern s32 osTestHost(void);
extern void osReadHost(void *, u32);
extern void osWriteHost(void *, u32);
extern void osAckRamromRead(void);
extern void osAckRamromWrite(void);




extern void bcopy(const void *, void *, int);
extern int bcmp(const void *, const void *, int);
extern void bzero(void *, int);



extern void osInitialize(void);
extern u32 osGetCount(void);
extern void osExit(void);



extern int sprintf(char *s, const char *fmt, ...);
extern void osSyncPrintf(const char *fmt, ...);
extern void osAsyncPrintf(const char *fmt, ...);
extern int osSyncGetChars(char *buf);
extern int osAsyncGetChars(char *buf);



#define _MBI_H_ 

#define _SHIFTL(v,s,w) ((unsigned int) (((unsigned int)(v) & ((0x01 << (w)) - 1)) << (s)))

#define _SHIFTR(v,s,w) ((unsigned int)(((unsigned int)(v) >> (s)) & ((0x01 << (w)) - 1)))


#define _SHIFT _SHIFTL

#define G_ON (1)
#define G_OFF (0)









#define _GBI_H_ 

#define G_SPNOOP 0
#define G_MTX 1
#define G_RESERVED0 2
#define G_MOVEMEM 3
#define G_VTX 4
#define G_RESERVED1 5
#define G_DL 6
#define G_RESERVED2 7
#define G_RESERVED3 8
#define G_SPRITE2D 9


#define G_IMMFIRST -65
#define G_TRI1 (G_IMMFIRST-0)
#define G_CULLDL (G_IMMFIRST-1)
#define G_POPMTX (G_IMMFIRST-2)
#define G_MOVEWORD (G_IMMFIRST-3)
#define G_TEXTURE (G_IMMFIRST-4)
#define G_SETOTHERMODE_H (G_IMMFIRST-5)
#define G_SETOTHERMODE_L (G_IMMFIRST-6)
#define G_ENDDL (G_IMMFIRST-7)
#define G_SETGEOMETRYMODE (G_IMMFIRST-8)
#define G_CLEARGEOMETRYMODE (G_IMMFIRST-9)
#define G_LINE3D (G_IMMFIRST-10)






#define G_RDPHALF_1 (G_IMMFIRST-11)
#define G_RDPHALF_2 (G_IMMFIRST-12)

#define G_MODIFYVTX (G_IMMFIRST-13)
#define G_TRI2 (G_IMMFIRST-14)






#define G_NOOP 0xc0
#define G_SETCIMG 0xff
#define G_SETZIMG 0xfe
#define G_SETTIMG 0xfd
#define G_SETCOMBINE 0xfc
#define G_SETENVCOLOR 0xfb
#define G_SETPRIMCOLOR 0xfa
#define G_SETBLENDCOLOR 0xf9
#define G_SETFOGCOLOR 0xf8
#define G_SETFILLCOLOR 0xf7
#define G_FILLRECT 0xf6
#define G_SETTILE 0xf5
#define G_LOADTILE 0xf4
#define G_LOADBLOCK 0xf3
#define G_SETTILESIZE 0xf2
#define G_LOADTLUT 0xf0
#define G_RDPSETOTHERMODE 0xef
#define G_SETPRIMDEPTH 0xee
#define G_SETSCISSOR 0xed
#define G_SETCONVERT 0xec
#define G_SETKEYR 0xeb
#define G_SETKEYGB 0xea
#define G_RDPFULLSYNC 0xe9
#define G_RDPTILESYNC 0xe8
#define G_RDPPIPESYNC 0xe7
#define G_RDPLOADSYNC 0xe6
#define G_TEXRECTFLIP 0xe5
#define G_TEXRECT 0xe4

#define G_TRI_FILL 0xc8
#define G_TRI_SHADE 0xcc
#define G_TRI_TXTR 0xca
#define G_TRI_SHADE_TXTR 0xce
#define G_TRI_FILL_ZBUFF 0xc9
#define G_TRI_SHADE_ZBUFF 0xcd
#define G_TRI_TXTR_ZBUFF 0xcb
#define G_TRI_SHADE_TXTR_ZBUFF 0xcf

#define G_RDP_TRI_FILL_MASK 0x08
#define G_RDP_TRI_SHADE_MASK 0x04
#define G_RDP_TRI_TXTR_MASK 0x02
#define G_RDP_TRI_ZBUFF_MASK 0x01

#define BOWTIE_VAL 0



#define G_RDP_ADDR_FIXUP 3





#define GDMACMD(x) (x)
#define GIMMCMD(x) (G_IMMFIRST-(x))
#define GRDPCMD(x) (0xff-(x))

#define G_DMACMDSIZ 128
#define G_IMMCMDSIZ 64
#define G_RDPCMDSIZ 64




#define G_TEXTURE_IMAGE_FRAC 2
#define G_TEXTURE_SCALE_FRAC 16
#define G_SCALE_FRAC 8
#define G_ROTATE_FRAC 16

#define G_MAXFBZ 0x3fff

#define GPACK_RGBA5551(r,g,b,a) ((((r)<<8) & 0xf800) | (((g)<<3) & 0x7c0) | (((b)>>2) & 0x3e) | ((a) & 0x1))


#define GPACK_ZDZ(z,dz) ((z) << 2 | (dz))




#define G_MTX_MODELVIEW 0x00
#define G_MTX_PROJECTION 0x01
#define G_MTX_MUL 0x00
#define G_MTX_LOAD 0x02
#define G_MTX_NOPUSH 0x00
#define G_MTX_PUSH 0x04

#define G_ZBUFFER 0x00000001
#define G_TEXTURE_ENABLE 0x00000002
#define G_SHADE 0x00000004

#define G_SHADING_SMOOTH 0x00000200
#define G_CULL_FRONT 0x00001000
#define G_CULL_BACK 0x00002000
#define G_CULL_BOTH 0x00003000
#define G_FOG 0x00010000
#define G_LIGHTING 0x00020000
#define G_TEXTURE_GEN 0x00040000
#define G_TEXTURE_GEN_LINEAR 0x00080000
#define G_LOD 0x00100000

#define G_CLIPPING 0x00800000

#define G_IM_FMT_RGBA 0
#define G_IM_FMT_YUV 1
#define G_IM_FMT_CI 2
#define G_IM_FMT_IA 3
#define G_IM_FMT_I 4




#define G_IM_SIZ_4b 0
#define G_IM_SIZ_8b 1
#define G_IM_SIZ_16b 2
#define G_IM_SIZ_32b 3

#define G_IM_SIZ_4b_BYTES 0
#define G_IM_SIZ_4b_TILE_BYTES G_IM_SIZ_4b_BYTES
#define G_IM_SIZ_4b_LINE_BYTES G_IM_SIZ_4b_BYTES

#define G_IM_SIZ_8b_BYTES 1
#define G_IM_SIZ_8b_TILE_BYTES G_IM_SIZ_8b_BYTES
#define G_IM_SIZ_8b_LINE_BYTES G_IM_SIZ_8b_BYTES

#define G_IM_SIZ_16b_BYTES 2
#define G_IM_SIZ_16b_TILE_BYTES G_IM_SIZ_16b_BYTES
#define G_IM_SIZ_16b_LINE_BYTES G_IM_SIZ_16b_BYTES

#define G_IM_SIZ_32b_BYTES 4
#define G_IM_SIZ_32b_TILE_BYTES 2
#define G_IM_SIZ_32b_LINE_BYTES 2

#define G_IM_SIZ_4b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_8b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_16b_LOAD_BLOCK G_IM_SIZ_16b
#define G_IM_SIZ_32b_LOAD_BLOCK G_IM_SIZ_32b

#define G_IM_SIZ_4b_SHIFT 2
#define G_IM_SIZ_8b_SHIFT 1
#define G_IM_SIZ_16b_SHIFT 0
#define G_IM_SIZ_32b_SHIFT 0

#define G_IM_SIZ_4b_INCR 3
#define G_IM_SIZ_8b_INCR 1
#define G_IM_SIZ_16b_INCR 0
#define G_IM_SIZ_32b_INCR 0





#define G_CCMUX_COMBINED 0
#define G_CCMUX_TEXEL0 1
#define G_CCMUX_TEXEL1 2
#define G_CCMUX_PRIMITIVE 3
#define G_CCMUX_SHADE 4
#define G_CCMUX_ENVIRONMENT 5
#define G_CCMUX_CENTER 6
#define G_CCMUX_SCALE 6
#define G_CCMUX_COMBINED_ALPHA 7
#define G_CCMUX_TEXEL0_ALPHA 8
#define G_CCMUX_TEXEL1_ALPHA 9
#define G_CCMUX_PRIMITIVE_ALPHA 10
#define G_CCMUX_SHADE_ALPHA 11
#define G_CCMUX_ENV_ALPHA 12
#define G_CCMUX_LOD_FRACTION 13
#define G_CCMUX_PRIM_LOD_FRAC 14
#define G_CCMUX_NOISE 7
#define G_CCMUX_K4 7
#define G_CCMUX_K5 15
#define G_CCMUX_1 6
#define G_CCMUX_0 31


#define G_ACMUX_COMBINED 0
#define G_ACMUX_TEXEL0 1
#define G_ACMUX_TEXEL1 2
#define G_ACMUX_PRIMITIVE 3
#define G_ACMUX_SHADE 4
#define G_ACMUX_ENVIRONMENT 5
#define G_ACMUX_LOD_FRACTION 0
#define G_ACMUX_PRIM_LOD_FRAC 6
#define G_ACMUX_1 6
#define G_ACMUX_0 7


#define G_CC_PRIMITIVE 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE
#define G_CC_SHADE 0, 0, 0, SHADE, 0, 0, 0, SHADE
#define G_CC_MODULATEI TEXEL0, 0, SHADE, 0, 0, 0, 0, SHADE
#define G_CC_MODULATEIA TEXEL0, 0, SHADE, 0, TEXEL0, 0, SHADE, 0
#define G_CC_MODULATEIDECALA TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0
#define G_CC_MODULATERGB G_CC_MODULATEI
#define G_CC_MODULATERGBA G_CC_MODULATEIA
#define G_CC_MODULATERGBDECALA G_CC_MODULATEIDECALA
#define G_CC_MODULATEI_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define G_CC_MODULATEIA_PRIM TEXEL0, 0, PRIMITIVE, 0, TEXEL0, 0, PRIMITIVE, 0
#define G_CC_MODULATEIDECALA_PRIM TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0
#define G_CC_MODULATERGB_PRIM G_CC_MODULATEI_PRIM
#define G_CC_MODULATERGBA_PRIM G_CC_MODULATEIA_PRIM
#define G_CC_MODULATERGBDECALA_PRIM G_CC_MODULATEIA_PRIM
#define G_CC_DECALRGB 0, 0, 0, TEXEL0, 0, 0, 0, SHADE
#define G_CC_DECALRGBA 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL0
#define G_CC_BLENDI ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDIA ENVIRONMENT, SHADE, TEXEL0, SHADE, TEXEL0, 0, SHADE, 0
#define G_CC_BLENDIDECALA ENVIRONMENT, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_BLENDRGBA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDRGBDECALA TEXEL0, SHADE, TEXEL0_ALPHA, SHADE, 0, 0, 0, TEXEL0
#define G_CC_ADDRGB 1, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_ADDRGBDECALA 1, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_REFLECTRGB ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_REFLECTRGBDECALA ENVIRONMENT, 0, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_HILITERGB PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE
#define G_CC_HILITERGBA PRIMITIVE, SHADE, TEXEL0, SHADE, PRIMITIVE, SHADE, TEXEL0, SHADE
#define G_CC_HILITERGBDECALA PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_SHADEDECALA 0, 0, 0, SHADE, 0, 0, 0, TEXEL0
#define G_CC_BLENDPE PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, SHADE, 0
#define G_CC_BLENDPEDECALA PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0


#define _G_CC_BLENDPE ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, TEXEL0, 0, SHADE, 0
#define _G_CC_BLENDPEDECALA ENVIRONMENT, PRIMITIVE, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0
#define _G_CC_TWOCOLORTEX PRIMITIVE, SHADE, TEXEL0, SHADE, 0, 0, 0, SHADE

#define _G_CC_SPARSEST PRIMITIVE, TEXEL0, LOD_FRACTION, TEXEL0, PRIMITIVE, TEXEL0, LOD_FRACTION, TEXEL0
#define G_CC_TEMPLERP TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0


#define G_CC_TRILERP TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0, TEXEL1, TEXEL0, LOD_FRACTION, TEXEL0
#define G_CC_INTERFERENCE TEXEL0, 0, TEXEL1, 0, TEXEL0, 0, TEXEL1, 0




#define G_CC_1CYUV2RGB TEXEL0, K4, K5, TEXEL0, 0, 0, 0, SHADE





#define G_CC_YUV2RGB TEXEL1, K4, K5, TEXEL1, 0, 0, 0, 0


#define G_CC_PASS2 0, 0, 0, COMBINED, 0, 0, 0, COMBINED
#define G_CC_MODULATEI2 COMBINED, 0, SHADE, 0, 0, 0, 0, SHADE
#define G_CC_MODULATEIA2 COMBINED, 0, SHADE, 0, COMBINED, 0, SHADE, 0
#define G_CC_MODULATERGB2 G_CC_MODULATEI2
#define G_CC_MODULATERGBA2 G_CC_MODULATEIA2
#define G_CC_MODULATEI_PRIM2 COMBINED, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE
#define G_CC_MODULATEIA_PRIM2 COMBINED, 0, PRIMITIVE, 0, COMBINED, 0, PRIMITIVE, 0
#define G_CC_MODULATERGB_PRIM2 G_CC_MODULATEI_PRIM2
#define G_CC_MODULATERGBA_PRIM2 G_CC_MODULATEIA_PRIM2
#define G_CC_DECALRGB2 0, 0, 0, COMBINED, 0, 0, 0, SHADE




#define G_CC_BLENDI2 ENVIRONMENT, SHADE, COMBINED, SHADE, 0, 0, 0, SHADE
#define G_CC_BLENDIA2 ENVIRONMENT, SHADE, COMBINED, SHADE, COMBINED, 0, SHADE, 0
#define G_CC_CHROMA_KEY2 TEXEL0, CENTER, SCALE, 0, 0, 0, 0, 0
#define G_CC_HILITERGB2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, SHADE
#define G_CC_HILITERGBA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, ENVIRONMENT, COMBINED, TEXEL0, COMBINED
#define G_CC_HILITERGBDECALA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, TEXEL0
#define G_CC_HILITERGBPASSA2 ENVIRONMENT, COMBINED, TEXEL0, COMBINED, 0, 0, 0, COMBINED




#define G_MDSFT_ALPHACOMPARE 0
#define G_MDSFT_ZSRCSEL 2
#define G_MDSFT_RENDERMODE 3
#define G_MDSFT_BLENDER 16




#define G_MDSFT_BLENDMASK 0
#define G_MDSFT_ALPHADITHER 4
#define G_MDSFT_RGBDITHER 6

#define G_MDSFT_COMBKEY 8
#define G_MDSFT_TEXTCONV 9
#define G_MDSFT_TEXTFILT 12
#define G_MDSFT_TEXTLUT 14
#define G_MDSFT_TEXTLOD 16
#define G_MDSFT_TEXTDETAIL 17
#define G_MDSFT_TEXTPERSP 19
#define G_MDSFT_CYCLETYPE 20
#define G_MDSFT_COLORDITHER 22
#define G_MDSFT_PIPELINE 23


#define G_PM_1PRIMITIVE (1 << G_MDSFT_PIPELINE)
#define G_PM_NPRIMITIVE (0 << G_MDSFT_PIPELINE)


#define G_CYC_1CYCLE (0 << G_MDSFT_CYCLETYPE)
#define G_CYC_2CYCLE (1 << G_MDSFT_CYCLETYPE)
#define G_CYC_COPY (2 << G_MDSFT_CYCLETYPE)
#define G_CYC_FILL (3 << G_MDSFT_CYCLETYPE)


#define G_TP_NONE (0 << G_MDSFT_TEXTPERSP)
#define G_TP_PERSP (1 << G_MDSFT_TEXTPERSP)


#define G_TD_CLAMP (0 << G_MDSFT_TEXTDETAIL)
#define G_TD_SHARPEN (1 << G_MDSFT_TEXTDETAIL)
#define G_TD_DETAIL (2 << G_MDSFT_TEXTDETAIL)


#define G_TL_TILE (0 << G_MDSFT_TEXTLOD)
#define G_TL_LOD (1 << G_MDSFT_TEXTLOD)


#define G_TT_NONE (0 << G_MDSFT_TEXTLUT)
#define G_TT_RGBA16 (2 << G_MDSFT_TEXTLUT)
#define G_TT_IA16 (3 << G_MDSFT_TEXTLUT)


#define G_TF_POINT (0 << G_MDSFT_TEXTFILT)
#define G_TF_AVERAGE (3 << G_MDSFT_TEXTFILT)
#define G_TF_BILERP (2 << G_MDSFT_TEXTFILT)


#define G_TC_CONV (0 << G_MDSFT_TEXTCONV)
#define G_TC_FILTCONV (5 << G_MDSFT_TEXTCONV)
#define G_TC_FILT (6 << G_MDSFT_TEXTCONV)


#define G_CK_NONE (0 << G_MDSFT_COMBKEY)
#define G_CK_KEY (1 << G_MDSFT_COMBKEY)


#define G_CD_MAGICSQ (0 << G_MDSFT_RGBDITHER)
#define G_CD_BAYER (1 << G_MDSFT_RGBDITHER)
#define G_CD_NOISE (2 << G_MDSFT_RGBDITHER)


#define G_CD_DISABLE (3 << G_MDSFT_RGBDITHER)
#define G_CD_ENABLE G_CD_NOISE






#define G_AD_PATTERN (0 << G_MDSFT_ALPHADITHER)
#define G_AD_NOTPATTERN (1 << G_MDSFT_ALPHADITHER)
#define G_AD_NOISE (2 << G_MDSFT_ALPHADITHER)
#define G_AD_DISABLE (3 << G_MDSFT_ALPHADITHER)


#define G_AC_NONE (0 << G_MDSFT_ALPHACOMPARE)
#define G_AC_THRESHOLD (1 << G_MDSFT_ALPHACOMPARE)
#define G_AC_DITHER (3 << G_MDSFT_ALPHACOMPARE)


#define G_ZS_PIXEL (0 << G_MDSFT_ZSRCSEL)
#define G_ZS_PRIM (1 << G_MDSFT_ZSRCSEL)


#define AA_EN 0x8
#define Z_CMP 0x10
#define Z_UPD 0x20
#define IM_RD 0x40
#define CLR_ON_CVG 0x80
#define CVG_DST_CLAMP 0
#define CVG_DST_WRAP 0x100
#define CVG_DST_FULL 0x200
#define CVG_DST_SAVE 0x300
#define ZMODE_OPA 0
#define ZMODE_INTER 0x400
#define ZMODE_XLU 0x800
#define ZMODE_DEC 0xc00
#define CVG_X_ALPHA 0x1000
#define ALPHA_CVG_SEL 0x2000
#define FORCE_BL 0x4000
#define TEX_EDGE 0x0000

#define G_BL_CLR_IN 0
#define G_BL_CLR_MEM 1
#define G_BL_CLR_BL 2
#define G_BL_CLR_FOG 3
#define G_BL_1MA 0
#define G_BL_A_MEM 1
#define G_BL_A_IN 0
#define G_BL_A_FOG 1
#define G_BL_A_SHADE 2
#define G_BL_1 2
#define G_BL_0 3

#define GBL_c1(m1a,m1b,m2a,m2b) (m1a) << 30 | (m1b) << 26 | (m2a) << 22 | (m2b) << 18

#define GBL_c2(m1a,m1b,m2a,m2b) (m1a) << 28 | (m1b) << 24 | (m2a) << 20 | (m2b) << 16


#define RM_AA_ZB_OPA_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_RA_ZB_OPA_SURF(clk) AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_XLU_SURF(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_XLU | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_OPA_DECAL(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_RA_ZB_OPA_DECAL(clk) AA_EN | Z_CMP | CVG_DST_WRAP | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_XLU_DECAL(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_OPA_INTER(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_INTER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_RA_ZB_OPA_INTER(clk) AA_EN | Z_CMP | Z_UPD | CVG_DST_CLAMP | ALPHA_CVG_SEL | ZMODE_INTER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_XLU_INTER(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_INTER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_XLU_LINE(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_XLU | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_DEC_LINE(clk) AA_EN | Z_CMP | IM_RD | CVG_DST_SAVE | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_TEX_EDGE(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_TEX_INTER(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_INTER | TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_SUB_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_ZB_PCL_SURF(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_OPA_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_TEX_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_ZB_SUB_TERR(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)





#define RM_AA_OPA_SURF(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_RA_OPA_SURF(clk) AA_EN | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_XLU_SURF(clk) AA_EN | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_XLU_LINE(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_DEC_LINE(clk) AA_EN | IM_RD | CVG_DST_FULL | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_TEX_EDGE(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_SUB_SURF(clk) AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_AA_PCL_SURF(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | G_AC_DITHER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_OPA_TERR(clk) AA_EN | IM_RD | CVG_DST_CLAMP | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_TEX_TERR(clk) AA_EN | IM_RD | CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | ZMODE_OPA | TEX_EDGE | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_AA_SUB_TERR(clk) AA_EN | IM_RD | CVG_DST_FULL | ZMODE_OPA | ALPHA_CVG_SEL | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)





#define RM_ZB_OPA_SURF(clk) Z_CMP | Z_UPD | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)




#define RM_ZB_XLU_SURF(clk) Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_XLU | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_ZB_OPA_DECAL(clk) Z_CMP | CVG_DST_FULL | ALPHA_CVG_SEL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_A_MEM)



#define RM_ZB_XLU_DECAL(clk) Z_CMP | IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_ZB_CLD_SURF(clk) Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_XLU | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_ZB_OVL_SURF(clk) Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_DEC | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_ZB_PCL_SURF(clk) Z_CMP | Z_UPD | CVG_DST_FULL | ZMODE_OPA | G_AC_DITHER | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)





#define RM_OPA_SURF(clk) CVG_DST_CLAMP | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)



#define RM_XLU_SURF(clk) IM_RD | CVG_DST_FULL | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_TEX_EDGE(clk) CVG_DST_CLAMP | CVG_X_ALPHA | ALPHA_CVG_SEL | FORCE_BL | ZMODE_OPA | TEX_EDGE | AA_EN | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)




#define RM_CLD_SURF(clk) IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)



#define RM_PCL_SURF(clk) CVG_DST_FULL | FORCE_BL | ZMODE_OPA | G_AC_DITHER | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)




#define RM_ADD(clk) IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1)



#define RM_NOOP(clk) GBL_c##clk(0, 0, 0, 0)


#define RM_VISCVG(clk) IM_RD | FORCE_BL | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_BL, G_BL_A_MEM)




#define RM_OPA_CI(clk) CVG_DST_CLAMP | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)





#define G_RM_AA_ZB_OPA_SURF RM_AA_ZB_OPA_SURF(1)
#define G_RM_AA_ZB_OPA_SURF2 RM_AA_ZB_OPA_SURF(2)
#define G_RM_AA_ZB_XLU_SURF RM_AA_ZB_XLU_SURF(1)
#define G_RM_AA_ZB_XLU_SURF2 RM_AA_ZB_XLU_SURF(2)
#define G_RM_AA_ZB_OPA_DECAL RM_AA_ZB_OPA_DECAL(1)
#define G_RM_AA_ZB_OPA_DECAL2 RM_AA_ZB_OPA_DECAL(2)
#define G_RM_AA_ZB_XLU_DECAL RM_AA_ZB_XLU_DECAL(1)
#define G_RM_AA_ZB_XLU_DECAL2 RM_AA_ZB_XLU_DECAL(2)
#define G_RM_AA_ZB_OPA_INTER RM_AA_ZB_OPA_INTER(1)
#define G_RM_AA_ZB_OPA_INTER2 RM_AA_ZB_OPA_INTER(2)
#define G_RM_AA_ZB_XLU_INTER RM_AA_ZB_XLU_INTER(1)
#define G_RM_AA_ZB_XLU_INTER2 RM_AA_ZB_XLU_INTER(2)
#define G_RM_AA_ZB_XLU_LINE RM_AA_ZB_XLU_LINE(1)
#define G_RM_AA_ZB_XLU_LINE2 RM_AA_ZB_XLU_LINE(2)
#define G_RM_AA_ZB_DEC_LINE RM_AA_ZB_DEC_LINE(1)
#define G_RM_AA_ZB_DEC_LINE2 RM_AA_ZB_DEC_LINE(2)
#define G_RM_AA_ZB_TEX_EDGE RM_AA_ZB_TEX_EDGE(1)
#define G_RM_AA_ZB_TEX_EDGE2 RM_AA_ZB_TEX_EDGE(2)
#define G_RM_AA_ZB_TEX_INTER RM_AA_ZB_TEX_INTER(1)
#define G_RM_AA_ZB_TEX_INTER2 RM_AA_ZB_TEX_INTER(2)
#define G_RM_AA_ZB_SUB_SURF RM_AA_ZB_SUB_SURF(1)
#define G_RM_AA_ZB_SUB_SURF2 RM_AA_ZB_SUB_SURF(2)
#define G_RM_AA_ZB_PCL_SURF RM_AA_ZB_PCL_SURF(1)
#define G_RM_AA_ZB_PCL_SURF2 RM_AA_ZB_PCL_SURF(2)
#define G_RM_AA_ZB_OPA_TERR RM_AA_ZB_OPA_TERR(1)
#define G_RM_AA_ZB_OPA_TERR2 RM_AA_ZB_OPA_TERR(2)
#define G_RM_AA_ZB_TEX_TERR RM_AA_ZB_TEX_TERR(1)
#define G_RM_AA_ZB_TEX_TERR2 RM_AA_ZB_TEX_TERR(2)
#define G_RM_AA_ZB_SUB_TERR RM_AA_ZB_SUB_TERR(1)
#define G_RM_AA_ZB_SUB_TERR2 RM_AA_ZB_SUB_TERR(2)

#define G_RM_RA_ZB_OPA_SURF RM_RA_ZB_OPA_SURF(1)
#define G_RM_RA_ZB_OPA_SURF2 RM_RA_ZB_OPA_SURF(2)
#define G_RM_RA_ZB_OPA_DECAL RM_RA_ZB_OPA_DECAL(1)
#define G_RM_RA_ZB_OPA_DECAL2 RM_RA_ZB_OPA_DECAL(2)
#define G_RM_RA_ZB_OPA_INTER RM_RA_ZB_OPA_INTER(1)
#define G_RM_RA_ZB_OPA_INTER2 RM_RA_ZB_OPA_INTER(2)

#define G_RM_AA_OPA_SURF RM_AA_OPA_SURF(1)
#define G_RM_AA_OPA_SURF2 RM_AA_OPA_SURF(2)
#define G_RM_AA_XLU_SURF RM_AA_XLU_SURF(1)
#define G_RM_AA_XLU_SURF2 RM_AA_XLU_SURF(2)
#define G_RM_AA_XLU_LINE RM_AA_XLU_LINE(1)
#define G_RM_AA_XLU_LINE2 RM_AA_XLU_LINE(2)
#define G_RM_AA_DEC_LINE RM_AA_DEC_LINE(1)
#define G_RM_AA_DEC_LINE2 RM_AA_DEC_LINE(2)
#define G_RM_AA_TEX_EDGE RM_AA_TEX_EDGE(1)
#define G_RM_AA_TEX_EDGE2 RM_AA_TEX_EDGE(2)
#define G_RM_AA_SUB_SURF RM_AA_SUB_SURF(1)
#define G_RM_AA_SUB_SURF2 RM_AA_SUB_SURF(2)
#define G_RM_AA_PCL_SURF RM_AA_PCL_SURF(1)
#define G_RM_AA_PCL_SURF2 RM_AA_PCL_SURF(2)
#define G_RM_AA_OPA_TERR RM_AA_OPA_TERR(1)
#define G_RM_AA_OPA_TERR2 RM_AA_OPA_TERR(2)
#define G_RM_AA_TEX_TERR RM_AA_TEX_TERR(1)
#define G_RM_AA_TEX_TERR2 RM_AA_TEX_TERR(2)
#define G_RM_AA_SUB_TERR RM_AA_SUB_TERR(1)
#define G_RM_AA_SUB_TERR2 RM_AA_SUB_TERR(2)

#define G_RM_RA_OPA_SURF RM_RA_OPA_SURF(1)
#define G_RM_RA_OPA_SURF2 RM_RA_OPA_SURF(2)

#define G_RM_ZB_OPA_SURF RM_ZB_OPA_SURF(1)
#define G_RM_ZB_OPA_SURF2 RM_ZB_OPA_SURF(2)
#define G_RM_ZB_XLU_SURF RM_ZB_XLU_SURF(1)
#define G_RM_ZB_XLU_SURF2 RM_ZB_XLU_SURF(2)
#define G_RM_ZB_OPA_DECAL RM_ZB_OPA_DECAL(1)
#define G_RM_ZB_OPA_DECAL2 RM_ZB_OPA_DECAL(2)
#define G_RM_ZB_XLU_DECAL RM_ZB_XLU_DECAL(1)
#define G_RM_ZB_XLU_DECAL2 RM_ZB_XLU_DECAL(2)
#define G_RM_ZB_CLD_SURF RM_ZB_CLD_SURF(1)
#define G_RM_ZB_CLD_SURF2 RM_ZB_CLD_SURF(2)
#define G_RM_ZB_OVL_SURF RM_ZB_OVL_SURF(1)
#define G_RM_ZB_OVL_SURF2 RM_ZB_OVL_SURF(2)
#define G_RM_ZB_PCL_SURF RM_ZB_PCL_SURF(1)
#define G_RM_ZB_PCL_SURF2 RM_ZB_PCL_SURF(2)

#define G_RM_OPA_SURF RM_OPA_SURF(1)
#define G_RM_OPA_SURF2 RM_OPA_SURF(2)
#define G_RM_XLU_SURF RM_XLU_SURF(1)
#define G_RM_XLU_SURF2 RM_XLU_SURF(2)
#define G_RM_CLD_SURF RM_CLD_SURF(1)
#define G_RM_CLD_SURF2 RM_CLD_SURF(2)
#define G_RM_TEX_EDGE RM_TEX_EDGE(1)
#define G_RM_TEX_EDGE2 RM_TEX_EDGE(2)
#define G_RM_PCL_SURF RM_PCL_SURF(1)
#define G_RM_PCL_SURF2 RM_PCL_SURF(2)
#define G_RM_ADD RM_ADD(1)
#define G_RM_ADD2 RM_ADD(2)
#define G_RM_NOOP RM_NOOP(1)
#define G_RM_NOOP2 RM_NOOP(2)
#define G_RM_VISCVG RM_VISCVG(1)
#define G_RM_VISCVG2 RM_VISCVG(2)
#define G_RM_OPA_CI RM_OPA_CI(1)
#define G_RM_OPA_CI2 RM_OPA_CI(2)


#define G_RM_FOG_SHADE_A GBL_c1(G_BL_CLR_FOG, G_BL_A_SHADE, G_BL_CLR_IN, G_BL_1MA)
#define G_RM_FOG_PRIM_A GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_IN, G_BL_1MA)
#define G_RM_PASS GBL_c1(G_BL_CLR_IN, G_BL_0, G_BL_CLR_IN, G_BL_1)




#define G_CV_K0 175
#define G_CV_K1 -43
#define G_CV_K2 -89
#define G_CV_K3 222
#define G_CV_K4 114
#define G_CV_K5 42




#define G_SC_NON_INTERLACE 0
#define G_SC_ODD_INTERLACE 3
#define G_SC_EVEN_INTERLACE 2


#define G_DL_PUSH 0x00
#define G_DL_NOPUSH 0x01

typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 unsigned char cn[4];
} Vtx_t;




typedef struct {
 short ob[3];
 unsigned short flag;
 short tc[2];
 signed char n[3];
 unsigned char a;
} Vtx_tn;

typedef union {
    Vtx_t v;
    Vtx_tn n;
    long long int force_structure_alignment;
} Vtx;

typedef struct {
  void *SourceImagePointer;
  void *TlutPointer;
  short Stride;
  short SubImageWidth;
  short SubImageHeight;
  char SourceImageType;
  char SourceImageBitSize;
  short ScaleX;
  short ScaleY;
  char FlipTextureX;
  char FlipTextureY;
  short SourceImageOffsetS;
  short SourceImageOffsetT;
  short PScreenX;
  short PScreenY;



  char dummy[2];

} uSprite_t;


typedef union {
  uSprite_t s;


  long long int force_structure_allignment[4];
} uSprite;




typedef struct {
 unsigned char flag;
 unsigned char v[3];
} Tri;






typedef long Mtx_t[4][4];

typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;

#define G_MAXZ 0x03ff

typedef struct {
 short vscale[4];
 short vtrans[4];

} Vp_t;

typedef union {
    Vp_t vp;
    long long int force_structure_alignment;
} Vp;

#define G_MV_VIEWPORT 0x80
#define G_MV_LOOKATY 0x82
#define G_MV_LOOKATX 0x84
#define G_MV_L0 0x86
#define G_MV_L1 0x88
#define G_MV_L2 0x8a
#define G_MV_L3 0x8c
#define G_MV_L4 0x8e
#define G_MV_L5 0x90
#define G_MV_L6 0x92
#define G_MV_L7 0x94
#define G_MV_TXTATT 0x96
#define G_MV_MATRIX_1 0x9e
#define G_MV_MATRIX_2 0x98
#define G_MV_MATRIX_3 0x9a
#define G_MV_MATRIX_4 0x9c

#define G_MW_MATRIX 0x00
#define G_MW_NUMLIGHT 0x02
#define G_MW_CLIP 0x04
#define G_MW_SEGMENT 0x06
#define G_MW_FOG 0x08
#define G_MW_LIGHTCOL 0x0a
#define G_MW_POINTS 0x0c

#define G_MW_PERSPNORM 0x0e





#define G_MWO_NUMLIGHT 0x00
#define G_MWO_CLIP_RNX 0x04
#define G_MWO_CLIP_RNY 0x0c
#define G_MWO_CLIP_RPX 0x14
#define G_MWO_CLIP_RPY 0x1c
#define G_MWO_SEGMENT_0 0x00
#define G_MWO_SEGMENT_1 0x01
#define G_MWO_SEGMENT_2 0x02
#define G_MWO_SEGMENT_3 0x03
#define G_MWO_SEGMENT_4 0x04
#define G_MWO_SEGMENT_5 0x05
#define G_MWO_SEGMENT_6 0x06
#define G_MWO_SEGMENT_7 0x07
#define G_MWO_SEGMENT_8 0x08
#define G_MWO_SEGMENT_9 0x09
#define G_MWO_SEGMENT_A 0x0a
#define G_MWO_SEGMENT_B 0x0b
#define G_MWO_SEGMENT_C 0x0c
#define G_MWO_SEGMENT_D 0x0d
#define G_MWO_SEGMENT_E 0x0e
#define G_MWO_SEGMENT_F 0x0f
#define G_MWO_FOG 0x00
#define G_MWO_aLIGHT_1 0x00
#define G_MWO_bLIGHT_1 0x04
#define G_MWO_aLIGHT_2 0x20
#define G_MWO_bLIGHT_2 0x24
#define G_MWO_aLIGHT_3 0x40
#define G_MWO_bLIGHT_3 0x44
#define G_MWO_aLIGHT_4 0x60
#define G_MWO_bLIGHT_4 0x64
#define G_MWO_aLIGHT_5 0x80
#define G_MWO_bLIGHT_5 0x84
#define G_MWO_aLIGHT_6 0xa0
#define G_MWO_bLIGHT_6 0xa4
#define G_MWO_aLIGHT_7 0xc0
#define G_MWO_bLIGHT_7 0xc4
#define G_MWO_aLIGHT_8 0xe0
#define G_MWO_bLIGHT_8 0xe4
#define G_MWO_MATRIX_XX_XY_I 0x00
#define G_MWO_MATRIX_XZ_XW_I 0x04
#define G_MWO_MATRIX_YX_YY_I 0x08
#define G_MWO_MATRIX_YZ_YW_I 0x0c
#define G_MWO_MATRIX_ZX_ZY_I 0x10
#define G_MWO_MATRIX_ZZ_ZW_I 0x14
#define G_MWO_MATRIX_WX_WY_I 0x18
#define G_MWO_MATRIX_WZ_WW_I 0x1c
#define G_MWO_MATRIX_XX_XY_F 0x20
#define G_MWO_MATRIX_XZ_XW_F 0x24
#define G_MWO_MATRIX_YX_YY_F 0x28
#define G_MWO_MATRIX_YZ_YW_F 0x2c
#define G_MWO_MATRIX_ZX_ZY_F 0x30
#define G_MWO_MATRIX_ZZ_ZW_F 0x34
#define G_MWO_MATRIX_WX_WY_F 0x38
#define G_MWO_MATRIX_WZ_WW_F 0x3c


#define G_MWO_POINT_RGBA 0x10
#define G_MWO_POINT_ST 0x14
#define G_MWO_POINT_XYSCREEN 0x18
#define G_MWO_POINT_ZSCREEN 0x1c

typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
  signed char dir[3];
  char pad3;
} Light_t;

typedef struct {
  unsigned char col[3];
  char pad1;
  unsigned char colc[3];
  char pad2;
} Ambient_t;

typedef struct {
  int x1,y1,x2,y2;
} Hilite_t;

typedef union {
    Light_t l;
    long long int force_structure_alignment[2];
} Light;

typedef union {
    Ambient_t l;
    long long int force_structure_alignment[1];
} Ambient;

typedef struct {
    Ambient a;
    Light l[7];
} Lightsn;

typedef struct {
    Ambient a;
    Light l[1];
} Lights0;

typedef struct {
    Ambient a;
    Light l[1];
} Lights1;

typedef struct {
    Ambient a;
    Light l[2];
} Lights2;

typedef struct {
    Ambient a;
    Light l[3];
} Lights3;

typedef struct {
    Ambient a;
    Light l[4];
} Lights4;

typedef struct {
    Ambient a;
    Light l[5];
} Lights5;

typedef struct {
    Ambient a;
    Light l[6];
} Lights6;

typedef struct {
    Ambient a;
    Light l[7];
} Lights7;

typedef struct {
    Light l[2];
} LookAt;

typedef union {
    Hilite_t h;
    long int force_structure_alignment[4];
} Hilite;

#define gdSPDefLights0(ar,ag,ab) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ { 0, 0, 0},0,{ 0, 0, 0},0,{ 0, 0, 0},0}}} }


#define gdSPDefLights1(ar,ag,ab,r1,g1,b1,x1,y1,z1) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}} }


#define gdSPDefLights2(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}} }



#define gdSPDefLights3(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}} }




#define gdSPDefLights4(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}} }





#define gdSPDefLights5(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}} }








#define gdSPDefLights6(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5,r6,g6,b6,x6,y6,z6) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}, {{ {r6,g6,b6},0,{r6,g6,b6},0,{x6,y6,z6},0}}} }

#define gdSPDefLights7(ar,ag,ab,r1,g1,b1,x1,y1,z1,r2,g2,b2,x2,y2,z2,r3,g3,b3,x3,y3,z3,r4,g4,b4,x4,y4,z4,r5,g5,b5,x5,y5,z5,r6,g6,b6,x6,y6,z6,r7,g7,b7,x7,y7,z7) { {{ {ar,ag,ab},0,{ar,ag,ab},0}}, {{{ {r1,g1,b1},0,{r1,g1,b1},0,{x1,y1,z1},0}}, {{ {r2,g2,b2},0,{r2,g2,b2},0,{x2,y2,z2},0}}, {{ {r3,g3,b3},0,{r3,g3,b3},0,{x3,y3,z3},0}}, {{ {r4,g4,b4},0,{r4,g4,b4},0,{x4,y4,z4},0}}, {{ {r5,g5,b5},0,{r5,g5,b5},0,{x5,y5,z5},0}}, {{ {r6,g6,b6},0,{r6,g6,b6},0,{x6,y6,z6},0}}, {{ {r7,g7,b7},0,{r7,g7,b7},0,{x7,y7,z7},0}}} }

#define gdSPDefLookAt(rightx,righty,rightz,upx,upy,upz) { {{ {{0,0,0},0,{0,0,0},0,{rightx,righty,rightz},0}}, { {{0,0x80,0},0,{0,0x80,0},0,{upx,upy,upz},0}}} }






typedef struct {
 int cmd:8;
 unsigned int par:8;
 unsigned int len:16;
 unsigned int addr;
} Gdma;




typedef struct {
  int cmd:8;
  int pad:24;
  Tri tri;
} Gtri;

typedef struct {
  int cmd:8;
  int pad1:24;
  int pad2:24;
  unsigned char param:8;
} Gpopmtx;

typedef struct {
  int cmd:8;
  int pad0:8;
  int mw_index:8;
  int number:8;
  int pad1:8;
  int base:24;
} Gsegment;

typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeL;

typedef struct {
  int cmd:8;
  int pad0:8;
  int sft:8;
  int len:8;
  unsigned int data:32;
} GsetothermodeH;

typedef struct {
  unsigned char cmd;
  unsigned char lodscale;
  unsigned char tile;
  unsigned char on;
  unsigned short s;
  unsigned short t;
} Gtexture;

typedef struct {
  int cmd:8;
  int pad:24;
  Tri line;
} Gline3D;

typedef struct {
  int cmd:8;
  int pad1:24;
  short int pad2;
  short int scale;
} Gperspnorm;





typedef struct {
                int cmd:8;
                unsigned int fmt:3;
                unsigned int siz:2;
                unsigned int pad:7;
                unsigned int wd:12;
                unsigned int dram;
} Gsetimg;

typedef struct {
  int cmd:8;
  unsigned int muxs0:24;
  unsigned int muxs1:32;
} Gsetcombine;

typedef struct {
  int cmd:8;
  unsigned char pad;
  unsigned char prim_min_level;
  unsigned char prim_level;
  unsigned long color;
} Gsetcolor;

typedef struct {
  int cmd:8;
  int x0:10;
  int x0frac:2;
  int y0:10;
  int y0frac:2;
  unsigned int pad:8;
  int x1:10;
  int x1frac:2;
  int y1:10;
  int y1frac:2;
} Gfillrect;

typedef struct {
  int cmd:8;
  unsigned int fmt:3;
  unsigned int siz:2;
  unsigned int pad0:1;
  unsigned int line:9;
  unsigned int tmem:9;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int palette:4;
  unsigned int ct:1;
  unsigned int mt:1;
  unsigned int maskt:4;
  unsigned int shiftt:4;
  unsigned int cs:1;
  unsigned int ms:1;
  unsigned int masks:4;
  unsigned int shifts:4;
} Gsettile;

typedef struct {
  int cmd:8;
  unsigned int sl:12;
  unsigned int tl:12;
  int pad:5;
  unsigned int tile:3;
  unsigned int sh:12;
  unsigned int th:12;
} Gloadtile;

typedef Gloadtile Gloadblock;

typedef Gloadtile Gsettilesize;

typedef Gloadtile Gloadtlut;

typedef struct {
  unsigned int cmd:8;
  unsigned int xl:12;
  unsigned int yl:12;
  unsigned int pad1:5;
  unsigned int tile:3;
  unsigned int xh:12;
  unsigned int yh:12;
  unsigned int s:16;
  unsigned int t:16;
  unsigned int dsdx:16;
  unsigned int dtdy:16;
} Gtexrect;

#define MakeTexRect(xh,yh,flip,tile,xl,yl,s,t,dsdx,dtdy) G_TEXRECT, xh, yh, 0, flip, 0, tile, xl, yl, s, t, dsdx, dtdy





typedef struct {
    unsigned long w0;
    unsigned long w1;
    unsigned long w2;
    unsigned long w3;
} TexRect;




typedef struct {
 unsigned int w0;
 unsigned int w1;
} Gwords;





typedef union {
 Gwords words;
 Gdma dma;
 Gtri tri;
 Gline3D line;
 Gpopmtx popmtx;
 Gsegment segment;
 GsetothermodeH setothermodeH;
 GsetothermodeL setothermodeL;
 Gtexture texture;
 Gperspnorm perspnorm;
 Gsetimg setimg;
 Gsetcombine setcombine;
 Gsetcolor setcolor;
 Gfillrect fillrect;
 Gsettile settile;
 Gloadtile loadtile;
 Gsettilesize settilesize;
 Gloadtlut loadtlut;
        long long int force_structure_alignment;
} Gfx;








#define gDma0p(pkt,c,s,l) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8) | _SHIFTL((l), 0, 24); _g->words.w1 = (unsigned int)(s); }







#define gsDma0p(c,s,l) { _SHIFTL((c), 24, 8) | _SHIFTL((l), 0, 24), (unsigned int)(s) }




#define gDma1p(pkt,c,s,l,p) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL((c), 24, 8) | _SHIFTL((p), 16, 8) | _SHIFTL((l), 0, 16)); _g->words.w1 = (unsigned int)(s); }








#define gsDma1p(c,s,l,p) { (_SHIFTL((c), 24, 8) | _SHIFTL((p), 16, 8) | _SHIFTL((l), 0, 16)), (unsigned int)(s) }






#define gSPNoOp(pkt) gDma0p(pkt, G_SPNOOP, 0, 0)
#define gsSPNoOp() gsDma0p(G_SPNOOP, 0, 0)

#define gSPMatrix(pkt,m,p) gDma1p(pkt, G_MTX, m, sizeof(Mtx), p)
#define gsSPMatrix(m,p) gsDma1p(G_MTX, m, sizeof(Mtx), p)

#define gSPVertex(pkt,v,n,v0) gDma1p(pkt, G_VTX, v, ((n)<<10)|(sizeof(Vtx)*(n)-1), (v0)*2)

#define gsSPVertex(v,n,v0) gsDma1p(G_VTX, v, ((n)<<10)|(sizeof(Vtx)*(n)-1), (v0)*2)








#define gSPViewport(pkt,v) gDma1p(pkt, G_MOVEMEM, v, sizeof(Vp), G_MV_VIEWPORT)
#define gsSPViewport(v) gsDma1p(G_MOVEMEM, v, sizeof(Vp), G_MV_VIEWPORT)

#define gSPDisplayList(pkt,dl) gDma1p(pkt,G_DL,dl,0,G_DL_PUSH)
#define gsSPDisplayList(dl) gsDma1p( G_DL,dl,0,G_DL_PUSH)

#define gSPBranchList(pkt,dl) gDma1p(pkt,G_DL,dl,0,G_DL_NOPUSH)
#define gsSPBranchList(dl) gsDma1p( G_DL,dl,0,G_DL_NOPUSH)

#define gSPSprite2D(pkt,s) gDma1p(pkt, G_SPRITE2D, s, sizeof(uSprite), 0)
#define gsSPSprite2D(s) gsDma1p(G_SPRITE2D, s, sizeof(uSprite), 0)




#define gImmp0(pkt,c) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); }






#define gsImmp0(c) { _SHIFTL((c), 24, 8) }




#define gImmp1(pkt,c,p0) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (unsigned int)(p0); }







#define gsImmp1(c,p0) { _SHIFTL((c), 24, 8), (unsigned int)(p0) }




#define gImmp2(pkt,c,p0,p1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = _SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8); }







#define gsImmp2(c,p0,p1) { _SHIFTL((c), 24, 8), _SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8)}




#define gImmp3(pkt,c,p0,p1,p2) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL((c), 24, 8); _g->words.w1 = (_SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8) | _SHIFTL((p2), 0, 8)); }








#define gsImmp3(c,p0,p1,p2) { _SHIFTL((c), 24, 8), (_SHIFTL((p0), 16, 16) | _SHIFTL((p1), 8, 8) | _SHIFTL((p2), 0, 8))}





#define gImmp21(pkt,c,p0,p1,dat) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL((c), 24, 8) | _SHIFTL((p0), 8, 16) | _SHIFTL((p1), 0, 8)); _g->words.w1 = (unsigned int) (dat); }








#define gsImmp21(c,p0,p1,dat) { _SHIFTL((c), 24, 8) | _SHIFTL((p0), 8, 16) | _SHIFTL((p1), 0, 8), (unsigned int) (dat) }





#define gMoveWd(pkt,index,offset,data) gImmp21(pkt, G_MOVEWORD, offset, index, data)


#define gsMoveWd(index,offset,data) gsImmp21( G_MOVEWORD, offset, index, data)

#define __gsSP1Triangle_w1(v0,v1,v2) (_SHIFTL((v0)*2,16,8)|_SHIFTL((v1)*2,8,8)|_SHIFTL((v2)*2,0,8))


#define __gsSP1Triangle_w1f(v0,v1,v2,flag) (((flag) == 0) ? __gsSP1Triangle_w1(v0, v1, v2): ((flag) == 1) ? __gsSP1Triangle_w1(v1, v2, v0): __gsSP1Triangle_w1(v2, v0, v1))




#define __gsSPLine3D_w1(v0,v1,wd) (_SHIFTL((v0)*2,16,8)|_SHIFT((v1)*2,8,8)|_SHIFT((wd),0,8))


#define __gsSPLine3D_w1f(v0,v1,wd,flag) (((flag) == 0) ? __gsSPLine3D_w1(v0, v1, wd): __gsSPLine3D_w1(v1, v0, wd))

#define gSP1Triangle(pkt,v0,v1,v2,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_TRI1, 24, 8); _g->words.w1 = __gsSP1Triangle_w1f(v0, v1, v2, flag); }







#define gsSP1Triangle(v0,v1,v2,flag) { _SHIFTL(G_TRI1, 24, 8), __gsSP1Triangle_w1f(v0, v1, v2, flag) }








#define gSPLine3D(pkt,v0,v1,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_LINE3D, 24, 8); _g->words.w1 = __gsSPLine3D_w1f(v0, v1, 0, flag); }







#define gsSPLine3D(v0,v1,flag) { _SHIFTL(G_LINE3D, 24, 8), __gsSPLine3D_w1f(v0, v1, 0, flag) }








#define gSPLineW3D(pkt,v0,v1,wd,flag) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_LINE3D, 24, 8); _g->words.w1 = __gsSPLine3D_w1f(v0, v1, wd, flag); }







#define gsSPLineW3D(v0,v1,wd,flag) { _SHIFTL(G_LINE3D, 24, 8), __gsSPLine3D_w1f(v0, v1, wd, flag) }

#define gSP2Triangles(pkt,v00,v01,v02,flag0,v10,v11,v12,flag1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TRI2, 24, 8)| __gsSP1Triangle_w1f(v00, v01, v02, flag0)); _g->words.w1 = __gsSP1Triangle_w1f(v10, v11, v12, flag1); }








#define gsSP2Triangles(v00,v01,v02,flag0,v10,v11,v12,flag1) { (_SHIFTL(G_TRI2, 24, 8)| __gsSP1Triangle_w1f(v00, v01, v02, flag0)), __gsSP1Triangle_w1f(v10, v11, v12, flag1) }

#define gSP1Quadrangle(pkt,v0,v1,v2,v3,flag) gSP2Triangles(pkt, v1, v2, v3, 0, v1, v3, v0, 0)

#define gsSP1Quadrangle(v0,v1,v2,v3,flag) gsSP2Triangles(v1, v2, v3, 0, v1, v3, v0, 0)

#define gSPCullDisplayList(pkt,vstart,vend) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_CULLDL, 24, 8) | _SHIFTL((vstart)*2, 0, 16); _g->words.w1 = _SHIFTL((vend)*2, 0, 16); }








#define gsSPCullDisplayList(vstart,vend) { _SHIFTL(G_CULLDL, 24, 8) | _SHIFTL((vstart)*2, 0, 16), _SHIFTL((vend)*2, 0, 16) }

#define gSPSegment(pkt,segment,base) gMoveWd(pkt, G_MW_SEGMENT, (segment*4), base)

#define gsSPSegment(segment,base) gsMoveWd( G_MW_SEGMENT, (segment*4), base)





#define FR_NEG_FRUSTRATIO_1 0x00000001
#define FR_POS_FRUSTRATIO_1 0x0000ffff
#define FR_NEG_FRUSTRATIO_2 0x00000002
#define FR_POS_FRUSTRATIO_2 0x0000fffe
#define FR_NEG_FRUSTRATIO_3 0x00000003
#define FR_POS_FRUSTRATIO_3 0x0000fffd
#define FR_NEG_FRUSTRATIO_4 0x00000004
#define FR_POS_FRUSTRATIO_4 0x0000fffc
#define FR_NEG_FRUSTRATIO_5 0x00000005
#define FR_POS_FRUSTRATIO_5 0x0000fffb
#define FR_NEG_FRUSTRATIO_6 0x00000006
#define FR_POS_FRUSTRATIO_6 0x0000fffa



#define gSPClipRatio(pkt,r) { gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNX, FR_NEG_##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RNY, FR_NEG_##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPX, FR_POS_##r); gMoveWd(pkt, G_MW_CLIP, G_MWO_CLIP_RPY, FR_POS_##r); }







#define gsSPClipRatio(r) gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RNX, FR_NEG_##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RNY, FR_NEG_##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RPX, FR_POS_##r), gsMoveWd(G_MW_CLIP, G_MWO_CLIP_RPY, FR_POS_##r)

#define gSPInsertMatrix(pkt,where,num) gMoveWd(pkt, G_MW_MATRIX, where, num)


#define gsSPInsertMatrix(where,num) gsMoveWd(G_MW_MATRIX, where, num)







#define gSPForceMatrix(pkt,mptr) { gDma1p(pkt, G_MOVEMEM, mptr, 16, G_MV_MATRIX_1); gDma1p(pkt, G_MOVEMEM, (char *)(mptr)+16, 16, G_MV_MATRIX_2); gDma1p(pkt, G_MOVEMEM, (char *)(mptr)+32, 16, G_MV_MATRIX_3); gDma1p(pkt, G_MOVEMEM, (char *)(mptr)+48, 16, G_MV_MATRIX_4); }






#define gsSPForceMatrix(mptr) gsDma1p( G_MOVEMEM, mptr, 16, G_MV_MATRIX_1), gsDma1p( G_MOVEMEM, (char *)(mptr)+16, 16, G_MV_MATRIX_2), gsDma1p( G_MOVEMEM, (char *)(mptr)+32, 16, G_MV_MATRIX_3), gsDma1p( G_MOVEMEM, (char *)(mptr)+48, 16, G_MV_MATRIX_4)

#define gSPModifyVertex(pkt,vtx,where,val) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_MODIFYVTX,24,8)| _SHIFTL((where),16,8)|_SHIFTL((vtx)*2,0,16)); _g->words.w1 = (unsigned int)(val); }






#define gsSPModifyVertex(vtx,where,val) { _SHIFTL(G_MODIFYVTX,24,8)| _SHIFTL((where),16,8)|_SHIFTL((vtx)*2,0,16), (unsigned int)(val) }

#define NUML(n) (((n)+1)*32 + 0x80000000)

#define NUMLIGHTS_0 1
#define NUMLIGHTS_1 1
#define NUMLIGHTS_2 2
#define NUMLIGHTS_3 3
#define NUMLIGHTS_4 4
#define NUMLIGHTS_5 5
#define NUMLIGHTS_6 6
#define NUMLIGHTS_7 7





#define gSPNumLights(pkt,n) gMoveWd(pkt, G_MW_NUMLIGHT, G_MWO_NUMLIGHT, NUML(n))

#define gsSPNumLights(n) gsMoveWd( G_MW_NUMLIGHT, G_MWO_NUMLIGHT, NUML(n))


#define LIGHT_1 1
#define LIGHT_2 2
#define LIGHT_3 3
#define LIGHT_4 4
#define LIGHT_5 5
#define LIGHT_6 6
#define LIGHT_7 7
#define LIGHT_8 8








#define gSPLight(pkt,l,n) gDma1p(pkt, G_MOVEMEM, l, sizeof(Light),((n)-1)*2+G_MV_L0)
#define gsSPLight(l,n) gsDma1p( G_MOVEMEM, l, sizeof(Light),((n)-1)*2+G_MV_L0)






#define gSPLightColor(pkt,n,col) { gMoveWd(pkt, G_MW_LIGHTCOL, G_MWO_a##n, col); gMoveWd(pkt, G_MW_LIGHTCOL, G_MWO_b##n, col); }




#define gsSPLightColor(n,col) gsMoveWd(G_MW_LIGHTCOL, G_MWO_a##n, col), gsMoveWd(G_MW_LIGHTCOL, G_MWO_b##n, col)





#define gSPSetLights0(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_0); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.a,2); }





#define gsSPSetLights0(name) gsSPNumLights(NUMLIGHTS_0), gsSPLight(&name.l[0],1), gsSPLight(&name.a,2)




#define gSPSetLights1(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_1); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.a,2); }





#define gsSPSetLights1(name) gsSPNumLights(NUMLIGHTS_1), gsSPLight(&name.l[0],1), gsSPLight(&name.a,2)




#define gSPSetLights2(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_2); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.a,3); }






#define gsSPSetLights2(name) gsSPNumLights(NUMLIGHTS_2), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.a,3)





#define gSPSetLights3(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_3); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.a,4); }







#define gsSPSetLights3(name) gsSPNumLights(NUMLIGHTS_3), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.a,4)






#define gSPSetLights4(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_4); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.a,5); }








#define gsSPSetLights4(name) gsSPNumLights(NUMLIGHTS_4), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.a,5)







#define gSPSetLights5(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_5); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.a,6); }

#define gsSPSetLights5(name) gsSPNumLights(NUMLIGHTS_5), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.a,6)








#define gSPSetLights6(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_6); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.l[5],6); gSPLight(pkt,&name.a,7); }

#define gsSPSetLights6(name) gsSPNumLights(NUMLIGHTS_6), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.l[5],6), gsSPLight(&name.a,7)

#define gSPSetLights7(pkt,name) { gSPNumLights(pkt,NUMLIGHTS_7); gSPLight(pkt,&name.l[0],1); gSPLight(pkt,&name.l[1],2); gSPLight(pkt,&name.l[2],3); gSPLight(pkt,&name.l[3],4); gSPLight(pkt,&name.l[4],5); gSPLight(pkt,&name.l[5],6); gSPLight(pkt,&name.l[6],7); gSPLight(pkt,&name.a,8); }

#define gsSPSetLights7(name) gsSPNumLights(NUMLIGHTS_7), gsSPLight(&name.l[0],1), gsSPLight(&name.l[1],2), gsSPLight(&name.l[2],3), gsSPLight(&name.l[3],4), gsSPLight(&name.l[4],5), gsSPLight(&name.l[5],6), gsSPLight(&name.l[6],7), gsSPLight(&name.a,8)

#define gSPLookAtX(pkt,l) gDma1p(pkt, G_MOVEMEM, l, sizeof(Light),G_MV_LOOKATX)
#define gsSPLookAtX(l) gsDma1p( G_MOVEMEM, l, sizeof(Light),G_MV_LOOKATX)

#define gSPLookAtY(pkt,l) gDma1p(pkt, G_MOVEMEM, l, sizeof(Light),G_MV_LOOKATY)
#define gsSPLookAtY(l) gsDma1p( G_MOVEMEM, l, sizeof(Light),G_MV_LOOKATY)

#define gSPLookAt(pkt,la) { gSPLookAtX(pkt,la) gSPLookAtY(pkt,((char *)la)+16) }




#define gsSPLookAt(la) gsSPLookAtX(la), gsSPLookAtY(((char *)la)+16)



#define gDPSetHilite1Tile(pkt,tile,hilite,width,height) gDPSetTileSize(pkt, tile, (hilite)->h.x1 & 0xfff, (hilite)->h.y1 & 0xfff, ((((width)-1)*4)+(hilite)->h.x1) & 0xfff, ((((height)-1)*4)+(hilite)->h.y1) & 0xfff)


#define gsDPSetHilite1Tile(tile,hilite,width,height) gsDPSetTileSize(tile, (hilite)->h.x1 & 0xfff, (hilite)->h.y1 & 0xfff, ((((width)-1)*4)+(hilite)->h.x1) & 0xfff, ((((height)-1)*4)+(hilite)->h.y1) & 0xfff)



#define gDPSetHilite2Tile(pkt,tile,hilite,width,height) gDPSetTileSize(pkt, tile, (hilite)->h.x2 & 0xfff, (hilite)->h.y2 & 0xfff, ((((width)-1)*4)+(hilite)->h.x2) & 0xfff, ((((height)-1)*4)+(hilite)->h.y2) & 0xfff)


#define gsDPSetHilite2Tile(tile,hilite,width,height) gsDPSetTileSize(tile, (hilite)->h.x2 & 0xfff, (hilite)->h.y2 & 0xfff, ((((width)-1)*4)+(hilite)->h.x2) & 0xfff, ((((height)-1)*4)+(hilite)->h.y2) & 0xfff)

#define gSPFogFactor(pkt,fm,fo) gMoveWd(pkt, G_MW_FOG, G_MWO_FOG, (_SHIFTL(fm,16,16) | _SHIFTL(fo,0,16)))



#define gsSPFogFactor(fm,fo) gsMoveWd(G_MW_FOG, G_MWO_FOG, (_SHIFTL(fm,16,16) | _SHIFTL(fo,0,16)))



#define gSPFogPosition(pkt,min,max) gMoveWd(pkt, G_MW_FOG, G_MWO_FOG, (_SHIFTL((128000/(max-min)),16,16) | _SHIFTL(((500-min)*256/(max-min)),0,16)))




#define gsSPFogPosition(min,max) gsMoveWd(G_MW_FOG, G_MWO_FOG, (_SHIFTL((128000/(max-min)),16,16) | _SHIFTL(((500-min)*256/(max-min)),0,16)))







#define gSPTexture(pkt,s,t,level,tile,on) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(BOWTIE_VAL, 16, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 0, 8)); _g->words.w1 = (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); }

#define gsSPTexture(s,t,level,tile,on) { (_SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(BOWTIE_VAL, 16, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 0, 8)), (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)) }

#define gSPTextureL(pkt,s,t,level,xparam,tile,on) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(xparam, 16, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 0, 8)); _g->words.w1 = (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)); }

#define gsSPTextureL(s,t,level,xparam,tile,on) { (_SHIFTL(G_TEXTURE, 24, 8) | _SHIFTL(xparam, 16, 8) | _SHIFTL(level, 11, 3) | _SHIFTL(tile, 8, 3) | _SHIFTL(on, 0, 8)), (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16)) }








#define gSPPerspNormalize(pkt,s) gMoveWd(pkt, G_MW_PERSPNORM, 0, (s))
#define gsSPPerspNormalize(s) gsMoveWd( G_MW_PERSPNORM, 0, (s))





#define gSPPopMatrix(pkt,n) gImmp1(pkt, G_POPMTX, n)
#define gsSPPopMatrix(n) gsImmp1(G_POPMTX, n)

#define gSPEndDisplayList(pkt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_ENDDL, 24, 8); _g->words.w1 = 0; }







#define gsSPEndDisplayList() { _SHIFTL(G_ENDDL, 24, 8), 0 }




#define gSPSetGeometryMode(pkt,word) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETGEOMETRYMODE, 24, 8); _g->words.w1 = (unsigned int)(word); }







#define gsSPSetGeometryMode(word) { _SHIFTL(G_SETGEOMETRYMODE, 24, 8), (unsigned int)(word) }




#define gSPClearGeometryMode(pkt,word) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_CLEARGEOMETRYMODE, 24, 8); _g->words.w1 = (unsigned int)(word); }







#define gsSPClearGeometryMode(word) { _SHIFTL(G_CLEARGEOMETRYMODE, 24, 8), (unsigned int)(word) }




#define gSPSetOtherMode(pkt,cmd,sft,len,data) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(cmd, 24, 8) | _SHIFTL(sft, 8, 8) | _SHIFTL(len, 0, 8)); _g->words.w1 = (unsigned int)(data); }








#define gsSPSetOtherMode(cmd,sft,len,data) { _SHIFTL(cmd, 24, 8) | _SHIFTL(sft, 8, 8) | _SHIFTL(len, 0, 8), (unsigned int)(data) }








#define gDPPipelineMode(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, mode)

#define gsDPPipelineMode(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_PIPELINE, 1, mode)


#define gDPSetCycleType(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, type)

#define gsDPSetCycleType(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_CYCLETYPE, 2, type)


#define gDPSetTexturePersp(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, type)

#define gsDPSetTexturePersp(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTPERSP, 1, type)


#define gDPSetTextureDetail(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, type)

#define gsDPSetTextureDetail(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTDETAIL, 2, type)


#define gDPSetTextureLOD(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, type)

#define gsDPSetTextureLOD(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLOD, 1, type)


#define gDPSetTextureLUT(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, type)

#define gsDPSetTextureLUT(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTLUT, 2, type)


#define gDPSetTextureFilter(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, type)

#define gsDPSetTextureFilter(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTFILT, 2, type)


#define gDPSetTextureConvert(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, type)

#define gsDPSetTextureConvert(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_TEXTCONV, 3, type)


#define gDPSetCombineKey(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, type)

#define gsDPSetCombineKey(type) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_COMBKEY, 1, type)



#define gDPSetColorDither(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, mode)

#define gsDPSetColorDither(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_RGBDITHER, 2, mode)

#define gDPSetAlphaDither(pkt,mode) gSPSetOtherMode(pkt, G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, mode)

#define gsDPSetAlphaDither(mode) gsSPSetOtherMode(G_SETOTHERMODE_H, G_MDSFT_ALPHADITHER, 2, mode)







#define gDPSetBlendMask(pkt,mask) gDPNoOp(pkt)
#define gsDPSetBlendMask(mask) gsDPNoOp()

#define gDPSetAlphaCompare(pkt,type) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, type)

#define gsDPSetAlphaCompare(type) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ALPHACOMPARE, 2, type)


#define gDPSetDepthSource(pkt,src) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, src)

#define gsDPSetDepthSource(src) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_ZSRCSEL, 1, src)


#define gDPSetRenderMode(pkt,c0,c1) gSPSetOtherMode(pkt, G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c0) | (c1))


#define gsDPSetRenderMode(c0,c1) gsSPSetOtherMode(G_SETOTHERMODE_L, G_MDSFT_RENDERMODE, 29, (c0) | (c1))



#define gSetImage(pkt,cmd,fmt,siz,width,i) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12); _g->words.w1 = (unsigned int)(i); }








#define gsSetImage(cmd,fmt,siz,width,i) { _SHIFTL(cmd, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL((width)-1, 0, 12), (unsigned int)(i) }






#define gDPSetColorImage(pkt,f,s,w,i) gSetImage(pkt, G_SETCIMG, f, s, w, i)
#define gsDPSetColorImage(f,s,w,i) gsSetImage(G_SETCIMG, f, s, w, i)



#define gDPSetDepthImage(pkt,i) gSetImage(pkt, G_SETZIMG, 0, 0, 1, i)
#define gsDPSetDepthImage(i) gsSetImage(G_SETZIMG, 0, 0, 1, i)

#define gDPSetMaskImage(pkt,i) gDPSetDepthImage(pkt, i)
#define gsDPSetMaskImage(i) gsDPSetDepthImage(i)

#define gDPSetTextureImage(pkt,f,s,w,i) gSetImage(pkt, G_SETTIMG, f, s, w, i)
#define gsDPSetTextureImage(f,s,w,i) gsSetImage(G_SETTIMG, f, s, w, i)





#define gDPSetCombine(pkt,muxs0,muxs1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(muxs0, 0, 24); _g->words.w1 = (unsigned int)(muxs1); }







#define gsDPSetCombine(muxs0,muxs1) { _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(muxs0, 0, 24), (unsigned int)(muxs1) }





#define GCCc0w0(saRGB0,mRGB0,saA0,mA0) (_SHIFTL((saRGB0), 20, 4) | _SHIFTL((mRGB0), 15, 5) | _SHIFTL((saA0), 12, 3) | _SHIFTL((mA0), 9, 3))



#define GCCc1w0(saRGB1,mRGB1) (_SHIFTL((saRGB1), 5, 4) | _SHIFTL((mRGB1), 0, 5))


#define GCCc0w1(sbRGB0,aRGB0,sbA0,aA0) (_SHIFTL((sbRGB0), 28, 4) | _SHIFTL((aRGB0), 15, 3) | _SHIFTL((sbA0), 12, 3) | _SHIFTL((aA0), 9, 3))



#define GCCc1w1(sbRGB1,saA1,mA1,aRGB1,sbA1,aA1) (_SHIFTL((sbRGB1), 24, 4) | _SHIFTL((saA1), 21, 3) | _SHIFTL((mA1), 18, 3) | _SHIFTL((aRGB1), 6, 3) | _SHIFTL((sbA1), 3, 3) | _SHIFTL((aA1), 0, 3))




#define gDPSetCombineLERP(pkt,a0,b0,c0,d0,Aa0,Ab0,Ac0,Ad0,a1,b1,c1,d1,Aa1,Ab1,Ac1,Ad1) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(GCCc0w0(G_CCMUX_##a0, G_CCMUX_##c0, G_ACMUX_##Aa0, G_ACMUX_##Ac0) | GCCc1w0(G_CCMUX_##a1, G_CCMUX_##c1), 0, 24); _g->words.w1 = (unsigned int)(GCCc0w1(G_CCMUX_##b0, G_CCMUX_##d0, G_ACMUX_##Ab0, G_ACMUX_##Ad0) | GCCc1w1(G_CCMUX_##b1, G_ACMUX_##Aa1, G_ACMUX_##Ac1, G_CCMUX_##d1, G_ACMUX_##Ab1, G_ACMUX_##Ad1)); }

#define gsDPSetCombineLERP(a0,b0,c0,d0,Aa0,Ab0,Ac0,Ad0,a1,b1,c1,d1,Aa1,Ab1,Ac1,Ad1) { _SHIFTL(G_SETCOMBINE, 24, 8) | _SHIFTL(GCCc0w0(G_CCMUX_##a0, G_CCMUX_##c0, G_ACMUX_##Aa0, G_ACMUX_##Ac0) | GCCc1w0(G_CCMUX_##a1, G_CCMUX_##c1), 0, 24), (unsigned int)(GCCc0w1(G_CCMUX_##b0, G_CCMUX_##d0, G_ACMUX_##Ab0, G_ACMUX_##Ad0) | GCCc1w1(G_CCMUX_##b1, G_ACMUX_##Aa1, G_ACMUX_##Ac1, G_CCMUX_##d1, G_ACMUX_##Ab1, G_ACMUX_##Ad1)) }

#define gDPSetCombineMode(pkt,a,b) gDPSetCombineLERP(pkt, a, b)
#define gsDPSetCombineMode(a,b) gsDPSetCombineLERP(a, b)

#define gDPSetColor(pkt,c,d) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(c, 24, 8); _g->words.w1 = (unsigned int)(d); }







#define gsDPSetColor(c,d) { _SHIFTL(c, 24, 8), (unsigned int)(d) }




#define DPRGBColor(pkt,cmd,r,g,b,a) gDPSetColor(pkt, cmd, (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)))



#define sDPRGBColor(cmd,r,g,b,a) gsDPSetColor(cmd, (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)))




#define gDPSetEnvColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETENVCOLOR, r,g,b,a)

#define gsDPSetEnvColor(r,g,b,a) sDPRGBColor(G_SETENVCOLOR, r,g,b,a)

#define gDPSetBlendColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETBLENDCOLOR, r,g,b,a)

#define gsDPSetBlendColor(r,g,b,a) sDPRGBColor(G_SETBLENDCOLOR, r,g,b,a)

#define gDPSetFogColor(pkt,r,g,b,a) DPRGBColor(pkt, G_SETFOGCOLOR, r,g,b,a)

#define gsDPSetFogColor(r,g,b,a) sDPRGBColor(G_SETFOGCOLOR, r,g,b,a)

#define gDPSetFillColor(pkt,d) gDPSetColor(pkt, G_SETFILLCOLOR, (d))

#define gsDPSetFillColor(d) gsDPSetColor(G_SETFILLCOLOR, (d))


#define gDPSetPrimDepth(pkt,z,dz) gDPSetColor(pkt, G_SETPRIMDEPTH, _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16))


#define gsDPSetPrimDepth(z,dz) gsDPSetColor(G_SETPRIMDEPTH, _SHIFTL(z, 16, 16) | _SHIFTL(dz, 0, 16))



#define gDPSetPrimColor(pkt,m,l,r,g,b,a) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)); _g->words.w1 = (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)); }

#define gsDPSetPrimColor(m,l,r,g,b,a) { (_SHIFTL(G_SETPRIMCOLOR, 24, 8) | _SHIFTL(m, 8, 8) | _SHIFTL(l, 0, 8)), (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8)) }

#define G_TX_LOADTILE 7
#define G_TX_RENDERTILE 0

#define G_TX_NOMIRROR 0
#define G_TX_WRAP 0
#define G_TX_MIRROR 0x1
#define G_TX_CLAMP 0x2
#define G_TX_NOMASK 0
#define G_TX_NOLOD 0



#define MAX(a,b) ((a) > (b) ? (a) : (b))



#define MIN(a,b) ((a) < (b) ? (a) : (b))

#define G_TX_DXT_FRAC 11

#define G_TX_LDBLK_MAX_TXL 2047


#define TXL2WORDS(txls,b_txl) MAX(1, ((txls)*(b_txl)/8))
#define CALC_DXT(width,b_txl) (((1 << G_TX_DXT_FRAC) + TXL2WORDS(width, b_txl) - 1) / TXL2WORDS(width, b_txl))



#define TXL2WORDS_4b(txls) MAX(1, ((txls)/16))
#define CALC_DXT_4b(width) (((1 << G_TX_DXT_FRAC) + TXL2WORDS_4b(width) - 1) / TXL2WORDS_4b(width))



#define gDPLoadTileGeneric(pkt,c,tile,uls,ult,lrs,lrt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12); }

#define gsDPLoadTileGeneric(c,tile,uls,ult,lrs,lrt) { _SHIFTL(c, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12), _SHIFTL(tile, 24, 3) | _SHIFTL(lrs, 12, 12) | _SHIFTL(lrt, 0, 12)}





#define gDPSetTileSize(pkt,t,uls,ult,lrs,lrt) gDPLoadTileGeneric(pkt, G_SETTILESIZE, t, uls, ult, lrs, lrt)

#define gsDPSetTileSize(t,uls,ult,lrs,lrt) gsDPLoadTileGeneric(G_SETTILESIZE, t, uls, ult, lrs, lrt)

#define gDPLoadTile(pkt,t,uls,ult,lrs,lrt) gDPLoadTileGeneric(pkt, G_LOADTILE, t, uls, ult, lrs, lrt)

#define gsDPLoadTile(t,uls,ult,lrs,lrt) gsDPLoadTileGeneric(G_LOADTILE, t, uls, ult, lrs, lrt)


#define gDPSetTile(pkt,fmt,siz,line,tmem,tile,palette,cmt,maskt,shiftt,cms,masks,shifts) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9); _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) |_SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4); }

#define gsDPSetTile(fmt,siz,line,tmem,tile,palette,cmt,maskt,shiftt,cms,masks,shifts) { (_SHIFTL(G_SETTILE, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(siz, 19, 2) | _SHIFTL(line, 9, 9) | _SHIFTL(tmem, 0, 9)), (_SHIFTL(tile, 24, 3) | _SHIFTL(palette, 20, 4) | _SHIFTL(cmt, 18, 2) | _SHIFTL(maskt, 14, 4) | _SHIFTL(shiftt, 10, 4) | _SHIFTL(cms, 8, 2) | _SHIFTL(masks, 4, 4) | _SHIFTL(shifts, 0, 4)) }

#define gDPLoadBlock(pkt,tile,uls,ult,lrs,dxt) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs,G_TX_LDBLK_MAX_TXL)), 12, 12) | _SHIFTL(dxt, 0, 12)); }

#define gsDPLoadBlock(tile,uls,ult,lrs,dxt) { (_SHIFTL(G_LOADBLOCK, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL((MIN(lrs,G_TX_LDBLK_MAX_TXL)), 12, 12) | _SHIFTL(dxt, 0, 12)) }








#define gDPLoadTLUTCmd(pkt,tile,count) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_LOADTLUT, 24, 8); _g->words.w1 = _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10);}







#define gsDPLoadTLUTCmd(tile,count) { _SHIFTL(G_LOADTLUT, 24, 8), _SHIFTL((tile), 24, 3) | _SHIFTL((count), 14, 10) }





#define gDPLoadTextureBlock(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT) -1, CALC_DXT(width, siz##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadTextureBlockYuv(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT) -1, CALC_DXT(width, siz##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * 1)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadTextureBlockS(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiBlockS(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadTextureBlockYuvS(pkt,timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1,0); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * 1)+7)>>3, 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define _gDPLoadTextureBlock(pkt,timg,tmem,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define _gDPLoadTextureBlockTile(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiBlock(pkt,timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz##_LOAD_BLOCK, 1, timg); gDPSetTile(pkt, fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((width) * siz##_LINE_BYTES)+7)>>3, tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gsDPLoadTextureBlock(timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadTextureBlockS(timg,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt,shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, 0 ), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define _gsDPLoadTextureBlock(timg,tmem,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define _gsDPLoadTextureBlockTile(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiBlock(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, CALC_DXT(width, siz##_BYTES)), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiBlockS(timg,tmem,rtile,fmt,siz,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz##_LOAD_BLOCK, 1, timg), gsDPSetTile(fmt, siz##_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt,shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height) + siz##_INCR) >> siz##_SHIFT)-1, 0 ), gsDPPipeSync(), gsDPSetTile(fmt, siz, ((((width) * siz##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gDPLoadTextureBlock_4b(pkt,timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadTextureBlock_4bS(pkt,timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, 0 ); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiBlock_4b(pkt,timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiBlock_4bS(pkt,timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, 0 ); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define _gDPLoadTextureBlock_4b(pkt,timg,tmem,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_16b, 1, timg); gDPSetTile(pkt, fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadBlock(pkt, G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC) }

#define gsDPLoadTextureBlock_4b(timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadTextureBlock_4bS(timg,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1,0), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiBlock_4b(timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiBlock_4bS(timg,tmem,rtile,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1,0), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define _gsDPLoadTextureBlock_4b(timg,tmem,fmt,width,height,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_16b, 1, timg), gsDPSetTile(fmt, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadBlock(G_TX_LOADTILE, 0, 0, (((width)*(height)+3)>>2)-1, CALC_DXT_4b(width)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, ((((width)>>1)+7)>>3), tmem, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, ((width)-1) << G_TEXTURE_IMAGE_FRAC, ((height)-1) << G_TEXTURE_IMAGE_FRAC)

#define gDPLoadTextureTile(pkt,timg,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz, width, timg); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz##_TILE_BYTES)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiTile(pkt,timg,tmem,rtile,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, siz, width, timg); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz##_TILE_BYTES)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, siz, (((((lrs)-(uls)+1) * siz##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }

#define gsDPLoadTextureTile(timg,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz, width, timg), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz##_TILE_BYTES)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC), gsDPPipeSync(), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz##_LINE_BYTES)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiTile(timg,tmem,rtile,fmt,siz,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, siz, width, timg), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz##_TILE_BYTES)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC), gsDPPipeSync(), gsDPSetTile(fmt, siz, (((((lrs)-(uls)+1) * siz##_LINE_BYTES)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)

#define gDPLoadTextureTile_4b(pkt,timg,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg); gDPSetTile(pkt, fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }

#define gDPLoadMultiTile_4b(pkt,timg,tmem,rtile,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) { gDPSetTextureImage(pkt, fmt, G_IM_SIZ_8b, ((width)>>1), timg); gDPSetTile(pkt, fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts); gDPLoadSync(pkt); gDPLoadTile( pkt, G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)); gDPPipeSync(pkt); gDPSetTile(pkt, fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts); gDPSetTileSize(pkt, rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC) }

#define gsDPLoadTextureTile_4b(timg,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_8b, ((width)>>1), timg), gsDPSetTile(fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), 0, G_TX_RENDERTILE, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(G_TX_RENDERTILE, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)

#define gsDPLoadMultiTile_4b(timg,tmem,rtile,fmt,width,height,uls,ult,lrs,lrt,pal,cms,cmt,masks,maskt,shifts,shiftt) gsDPSetTextureImage(fmt, G_IM_SIZ_8b, ((width)>>1), timg), gsDPSetTile(fmt, G_IM_SIZ_8b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, G_TX_LOADTILE, 0 , cmt, maskt, shiftt, cms, masks, shifts), gsDPLoadSync(), gsDPLoadTile( G_TX_LOADTILE, (uls)<<(G_TEXTURE_IMAGE_FRAC-1), (ult)<<(G_TEXTURE_IMAGE_FRAC), (lrs)<<(G_TEXTURE_IMAGE_FRAC-1), (lrt)<<(G_TEXTURE_IMAGE_FRAC)), gsDPPipeSync(), gsDPSetTile(fmt, G_IM_SIZ_4b, (((((lrs)-(uls)+1)>>1)+7)>>3), tmem, rtile, pal, cmt, maskt, shiftt, cms, masks, shifts), gsDPSetTileSize(rtile, (uls)<<G_TEXTURE_IMAGE_FRAC, (ult)<<G_TEXTURE_IMAGE_FRAC, (lrs)<<G_TEXTURE_IMAGE_FRAC, (lrt)<<G_TEXTURE_IMAGE_FRAC)

#define gDPLoadTLUT_pal16(pkt,pal,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, (256+(((pal)&0xf)*16)), G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, 15); gDPPipeSync(pkt) }

#define gsDPLoadTLUT_pal16(pal,dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, (256+(((pal)&0xf)*16)), G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, 15), gsDPPipeSync()

#define gDPLoadTLUT_pal256(pkt,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, 256, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, 255); gDPPipeSync(pkt) }

#define gsDPLoadTLUT_pal256(dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, 256, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, 255), gsDPPipeSync()

#define gDPLoadTLUT(pkt,count,tmemaddr,dram) { gDPSetTextureImage(pkt, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram); gDPTileSync(pkt); gDPSetTile(pkt, 0, 0, 0, tmemaddr, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0); gDPLoadSync(pkt); gDPLoadTLUTCmd(pkt, G_TX_LOADTILE, ((count)-1)); gDPPipeSync(pkt); }

#define gsDPLoadTLUT(count,tmemaddr,dram) gsDPSetTextureImage(G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, dram), gsDPTileSync(), gsDPSetTile(0, 0, 0, tmemaddr, G_TX_LOADTILE, 0 , 0, 0, 0, 0, 0, 0), gsDPLoadSync(), gsDPLoadTLUTCmd(G_TX_LOADTILE, ((count)-1)), gsDPPipeSync()

#define gDPSetScissor(pkt,mode,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((float)(ulx)*4.0F), 12, 12) | _SHIFTL((int)((float)(uly)*4.0F), 0, 12); _g->words.w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx)*4.0F), 12, 12) | _SHIFTL((int)((float)(lry)*4.0F), 0, 12); }

#define gDPSetScissorFrac(pkt,mode,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)pkt; _g->words.w0 = _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((ulx)), 12, 12) | _SHIFTL((int)((uly)), 0, 12); _g->words.w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((lrx)), 12, 12) | _SHIFTL((int)((lry)), 0, 12); }

#define gsDPSetScissor(mode,ulx,uly,lrx,lry) { _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((float)(ulx)*4.0F), 12, 12) | _SHIFTL((int)((float)(uly)*4.0F), 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx)*4.0F), 12, 12) | _SHIFTL((int)((float)(lry)*4.0F), 0, 12) }

#define gsDPSetScissorFrac(mode,ulx,uly,lrx,lry) { _SHIFTL(G_SETSCISSOR, 24, 8) | _SHIFTL((int)((ulx)), 12, 12) | _SHIFTL((int)((uly)), 0, 12), _SHIFTL(mode, 24, 2) | _SHIFTL((int)(lrx), 12, 12) | _SHIFTL((int)(lry), 0, 12) }

#define gDPFillRectangle(pkt,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)); _g->words.w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10));}








#define gsDPFillRectangle(ulx,uly,lrx,lry) { (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)), (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10)) }







#define gDPScisFillRectangle(pkt,ulx,uly,lrx,lry) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_FILLRECT, 24, 8) | _SHIFTL(MAX((lrx),0), 14, 10) | _SHIFTL(MAX((lry),0), 2, 10)); _g->words.w1 = (_SHIFTL(MAX((ulx),0), 14, 10) | _SHIFTL(MAX((uly),0), 2, 10)); }

#define gDPSetConvert(pkt,k0,k1,k2,k3,k4,k5) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETCONVERT, 24, 8) | _SHIFTL(k0, 13, 9) | _SHIFTL(k1, 4, 9) | _SHIFTR(k2, 5, 4)); _g->words.w1 = (_SHIFTL(k2, 27, 5) | _SHIFTL(k3, 18, 9) | _SHIFTL(k4, 9, 9) | _SHIFTL(k5, 0, 9)); }

#define gsDPSetConvert(k0,k1,k2,k3,k4,k5) { (_SHIFTL(G_SETCONVERT, 24, 8) | _SHIFTL(k0, 13, 9) | _SHIFTL(k1, 4, 9) | _SHIFTL(k2, 5, 4)), (_SHIFTL(k2, 27, 5) | _SHIFTL(k3, 18, 9) | _SHIFTL(k4, 9, 9) | _SHIFTL(k5, 0, 9)) }







#define gDPSetKeyR(pkt,cR,sR,wR) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(G_SETKEYR, 24, 8); _g->words.w1 = (_SHIFTL(wR, 16, 12) | _SHIFTL(cR, 8, 8) | _SHIFTL(sR, 0, 8)); }








#define gsDPSetKeyR(cR,sR,wR) { _SHIFTL(G_SETKEYR, 24, 8), _SHIFTL(wR, 16, 12) | _SHIFTL(cR, 8, 8) | _SHIFTL(sR, 0, 8) }





#define gDPSetKeyGB(pkt,cG,sG,wG,cB,sB,wB) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_SETKEYGB, 24, 8) | _SHIFTL(wG, 12, 12) | _SHIFTL(wB, 0, 12)); _g->words.w1 = (_SHIFTL(cG, 24, 8) | _SHIFTL(sG, 16, 8) | _SHIFTL(cB, 8, 8) | _SHIFTL(sB, 0, 8)); }

#define gsDPSetKeyGB(cG,sG,wG,cB,sB,wB) { (_SHIFTL(G_SETKEYGB, 24, 8) | _SHIFTL(wG, 12, 12) | _SHIFTL(wB, 0, 12)), (_SHIFTL(cG, 24, 8) | _SHIFTL(sG, 16, 8) | _SHIFTL(cB, 8, 8) | _SHIFTL(sB, 0, 8)) }







#define gDPNoParam(pkt,cmd) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8); _g->words.w1 = 0; }







#define gsDPNoParam(cmd) { _SHIFTL(cmd, 24, 8), 0 }




#define gDPParam(pkt,cmd,param) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = _SHIFTL(cmd, 24, 8); _g->words.w1 = (param); }







#define gsDPParam(cmd,param) { _SHIFTL(cmd, 24, 8), (param) }

#define gsDPTextureRectangle(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) ;                                                                                                                                             , { _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16), _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16) }

#define gsDPTextureRectangleFlip(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) ;                                                                                                                                                 , { _SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16), _SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16) }

#define gsSPTextureRectangle(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)), gsImmp1(G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))), gsImmp1(G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)))





#define gSPTextureRectangle(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)));}

#define gSPScisTextureRectangle(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECT, 24, 8) | _SHIFTL(MAX((s16)(xh),0), 12, 12) | _SHIFTL(MAX((s16)(yh),0), 0, 12)); _g->words.w1 = (_SHIFTL((tile), 24, 3) | _SHIFTL(MAX((s16)(xl),0), 12, 12) | _SHIFTL(MAX((s16)(yl),0), 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl)*(s16)(dsdx))>>7),0)) : (MIN((((s16)(xl)*(s16)(dsdx))>>7),0))) : 0)), 16, 16) | _SHIFTL(((t) - (((yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl)*(s16)(dtdy))>>7),0)) : (MIN((((s16)(yl)*(s16)(dtdy))>>7),0))) : 0)), 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL((dsdx), 16, 16) | _SHIFTL((dtdy), 0, 16))); }

#define gsSPTextureRectangleFlip(xl,yl,xh,yh,tile,s,t,dsdx,dtdy) (_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)), (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)), gsImmp1(G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))), gsImmp1(G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16)))






#define gSPTextureRectangleFlip(pkt,xl,yl,xh,yh,tile,s,t,dsdx,dtdy) { Gfx *_g = (Gfx *)(pkt); _g->words.w0 = (_SHIFTL(G_TEXRECTFLIP, 24, 8) | _SHIFTL(xh, 12, 12) | _SHIFTL(yh, 0, 12)); _g->words.w1 = (_SHIFTL(tile, 24, 3) | _SHIFTL(xl, 12, 12) | _SHIFTL(yl, 0, 12)); gImmp1(pkt, G_RDPHALF_1, (_SHIFTL(s, 16, 16) | _SHIFTL(t, 0, 16))); gImmp1(pkt, G_RDPHALF_2, (_SHIFTL(dsdx, 16, 16) | _SHIFTL(dtdy, 0, 16))); }

#define gsDPWord(wordhi,wordlo) gsImmp1(G_RDPHALF_1, (unsigned int)(wordhi)), gsImmp1(G_RDPHALF_2, (unsigned int)(wordlo))



#define gDPWord(pkt,wordhi,wordlo) { Gfx *_g = (Gfx *)(pkt); gImmp1(pkt, G_RDPHALF_1, (unsigned int)(wordhi)); gImmp1(pkt, G_RDPHALF_2, (unsigned int)(wordlo)); }







#define gDPFullSync(pkt) gDPNoParam(pkt, G_RDPFULLSYNC)
#define gsDPFullSync() gsDPNoParam(G_RDPFULLSYNC)
#define gDPTileSync(pkt) gDPNoParam(pkt, G_RDPTILESYNC)
#define gsDPTileSync() gsDPNoParam(G_RDPTILESYNC)
#define gDPPipeSync(pkt) gDPNoParam(pkt, G_RDPPIPESYNC)
#define gsDPPipeSync() gsDPNoParam(G_RDPPIPESYNC)
#define gDPLoadSync(pkt) gDPNoParam(pkt, G_RDPLOADSYNC)
#define gsDPLoadSync() gsDPNoParam(G_RDPLOADSYNC)
#define gDPNoOp(pkt) gDPNoParam(pkt, G_NOOP)
#define gsDPNoOp() gsDPNoParam(G_NOOP)
#define gDPNoOpTag(pkt,tag) gDPParam(pkt, G_NOOP, tag)
#define gsDPNoOpTag(tag) gsDPParam(G_NOOP, tag)










#define _ABI_H_ 

#define A_SPNOOP 0
#define A_ADPCM 1
#define A_CLEARBUFF 2
#define A_ENVMIXER 3
#define A_LOADBUFF 4
#define A_RESAMPLE 5
#define A_SAVEBUFF 6
#define A_SEGMENT 7
#define A_SETBUFF 8
#define A_SETVOL 9
#define A_DMEMMOVE 10
#define A_LOADADPCM 11
#define A_MIXER 12
#define A_INTERLEAVE 13
#define A_POLEF 14
#define A_SETLOOP 15

#define ACMD_SIZE 32




#define A_INIT 0x01
#define A_CONTINUE 0x00
#define A_LOOP 0x02
#define A_OUT 0x02
#define A_LEFT 0x02
#define A_RIGHT 0x00
#define A_VOL 0x04
#define A_RATE 0x00
#define A_AUX 0x08
#define A_NOAUX 0x00
#define A_MAIN 0x00
#define A_MIX 0x10

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Aadpcm;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int addr;
} Apolef;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvelope;

typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int dmem:16;
 unsigned int pad2:16;
 unsigned int count:16;
} Aclearbuff;

typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:8;
 unsigned int pad2:16;
 unsigned int inL:16;
        unsigned int inR:16;
} Ainterleave;

typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Aloadbuff;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Aenvmixer;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int gain:16;
 unsigned int dmemi:16;
 unsigned int dmemo:16;
} Amixer;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int dmem2:16;
 unsigned int addr;
} Apan;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pitch:16;
 unsigned int addr;
} Aresample;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int pad1:16;
 unsigned int addr;
} Areverb;

typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int addr;
} Asavebuff;

typedef struct {
   unsigned int cmd:8;
 unsigned int pad1:24;
 unsigned int pad2:2;
 unsigned int number:4;
 unsigned int base:24;
} Asegment;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int dmemin:16;
 unsigned int dmemout:16;
 unsigned int count:16;
} Asetbuff;

typedef struct {
   unsigned int cmd:8;
 unsigned int flags:8;
 unsigned int vol:16;
 unsigned int voltgt:16;
 unsigned int volrate:16;
} Asetvol;

typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int dmemin:16;
    unsigned int dmemout:16;
    unsigned int count:16;
} Admemmove;

typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int count:16;
    unsigned int addr;
} Aloadadpcm;

typedef struct {
    unsigned int cmd:8;
    unsigned int pad1:8;
    unsigned int pad2:16;
    unsigned int addr;
} Asetloop;





typedef struct {
 unsigned int w0;
 unsigned int w1;
} Awords;

typedef union {
 Awords words;
 Aadpcm adpcm;
        Apolef polef;
 Aclearbuff clearbuff;
 Aenvelope envelope;
        Ainterleave interleave;
 Aloadbuff loadbuff;
        Aenvmixer envmixer;
 Aresample resample;
 Areverb reverb;
 Asavebuff savebuff;
 Asegment segment;
 Asetbuff setbuff;
 Asetvol setvol;
        Admemmove dmemmove;
        Aloadadpcm loadadpcm;
        Amixer mixer;
        Asetloop setloop;
        long long int force_union_align;
} Acmd;




#define ADPCMVSIZE 8
#define ADPCMFSIZE 16
typedef short ADPCM_STATE[16];




typedef short POLEF_STATE[4];




typedef short RESAMPLE_STATE[16];




#define UNITY_PITCH 0x8000
#define MAX_RATIO 1.99996




typedef short ENVMIX_STATE[40];





#define aADPCMdec(pkt,f,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(f, 16, 8); _a->words.w1 = (unsigned int)(s); }







#define aPoleFilter(pkt,f,g,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); _a->words.w1 = (unsigned int)(s); }








#define aClearBuffer(pkt,d,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_CLEARBUFF, 24, 8) | _SHIFTL(d, 0, 24); _a->words.w1 = (unsigned int)(c); }







#define aEnvMixer(pkt,f,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_ENVMIXER, 24, 8) | _SHIFTL(f, 16, 8); _a->words.w1 = (unsigned int)(s); }







#define aInterleave(pkt,l,r) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8); _a->words.w1 = _SHIFTL(l, 16, 16) | _SHIFTL(r, 0, 16); }







#define aLoadBuffer(pkt,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_LOADBUFF, 24, 8); _a->words.w1 = (unsigned int)(s); }







#define aMix(pkt,f,g,i,o) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_MIXER, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(g, 0, 16)); _a->words.w1 = _SHIFTL(i,16, 16) | _SHIFTL(o, 0, 16); }








#define aPan(pkt,f,d,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_PAN, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(d, 0, 16)); _a->words.w1 = (unsigned int)(s); }








#define aResample(pkt,f,p,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(p, 0, 16)); _a->words.w1 = (unsigned int)(s); }








#define aSaveBuffer(pkt,s) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SAVEBUFF, 24, 8); _a->words.w1 = (unsigned int)(s); }







#define aSegment(pkt,s,b) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SEGMENT, 24, 8); _a->words.w1 = _SHIFTL(s, 24, 8) | _SHIFTL(b, 0, 24); }







#define aSetBuffer(pkt,f,i,o,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_SETBUFF, 24, 8) | _SHIFTL(f, 16, 8) | _SHIFTL(i, 0, 16)); _a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); }








#define aSetVolume(pkt,f,v,t,r) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 16) | _SHIFTL(v, 0, 16)); _a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16); }








#define aSetLoop(pkt,a) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_SETLOOP, 24, 8); _a->words.w1 = (unsigned int)(a); }






#define aDMEMMove(pkt,i,o,c) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_DMEMMOVE, 24, 8) | _SHIFTL(i, 0, 24); _a->words.w1 = _SHIFTL(o, 16, 16) | _SHIFTL(c, 0, 16); }







#define aLoadADPCM(pkt,c,d) { Acmd *_a = (Acmd *)pkt; _a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24); _a->words.w1 = (unsigned int) d; }








#define M_GFXTASK 1
#define M_AUDTASK 2
#define M_VIDTASK 3







#define NUM_SEGMENTS (16)
#define SEGMENT_OFFSET(a) ((unsigned int)(a) & 0x00ffffff)
#define SEGMENT_NUMBER(a) ((unsigned int)(a) >> 24)
#define SEGMENT_ADDR(num,off) (((num) << 24) + (off))



#define _GU_H_ 



#define _SPTASK_H_ 

typedef struct {
 u32 type;
 u32 flags;

 u64 *ucode_boot;
 u32 ucode_boot_size;

 u64 *ucode;
 u32 ucode_size;

 u64 *ucode_data;
 u32 ucode_data_size;

 u64 *dram_stack;
 u32 dram_stack_size;

 u64 *output_buff;
 u64 *output_buff_size;

 u64 *data_ptr;
 u32 data_size;

 u64 *yield_data_ptr;
 u32 yield_data_size;

} OSTask_t;

typedef union {
    OSTask_t t;
    long long int force_structure_alignment;
} OSTask;

typedef u32 OSYieldResult;

#define OS_TASK_YIELDED 0x0001
#define OS_TASK_DP_WAIT 0x0002
#define OS_TASK_USR0 0x0010
#define OS_TASK_USR1 0x0020
#define OS_TASK_USR2 0x0040
#define OS_TASK_USR3 0x0080

#define OS_YIELD_DATA_SIZE 0xc00
#define OS_YIELD_SPRITE_SIZE 0xc00




#define OS_YIELD_AUDIO_SIZE 0x400

#define osSpTaskStart(tp) { osSpTaskLoad((tp)); osSpTaskStartGo((tp)); }

extern void osSpTaskLoad(OSTask *tp);
extern void osSpTaskStartGo(OSTask *tp);

extern void osSpTaskYield(void);
extern OSYieldResult osSpTaskYielded(OSTask *tp);









#define M_PI 3.14159265358979323846
#define M_DTOR (3.14159265358979323846/180.0)

#define FTOFIX32(x) ((x) * 0x10000)
#define FIX32TOF(x) ((float)(((float)x) / (float)(0x10000)))
#define FTOFRAC8(x) ((int) MIN(((x) * (128.0)),127.0) & 0xff)

#define FILTER_WRAP 0
#define FILTER_CLAMP 1

#define RAND(x) (guRandom()%x)




typedef struct {
 unsigned char *base;
 int fmt, siz;
 int xsize, ysize;
 int lsize;

 int addr;
 int w, h;
 int s, t;
} Image;

typedef struct {
 float col[3];
 float pos[3];
 float a1, a2;
} PositionalLight;






extern int guLoadTextureBlockMipMap(Gfx **glist, unsigned char *tbuf, Image *im,
  unsigned char startTile, unsigned char pal, unsigned char cms,
  unsigned char cmt, unsigned char masks, unsigned char maskt,
  unsigned char shifts, unsigned char shiftt, unsigned char cfs,
  unsigned char cft);

extern int guGetDPLoadTextureTileSz (int ult, int lrt);
extern void guDPLoadTextureTile (Gfx *glistp, void *timg,
   int texl_fmt, int texl_size,
   int img_width, int img_height,
   int uls, int ult, int lrs, int lrt,
   int palette,
   int cms, int cmt,
   int masks, int maskt,
   int shifts, int shiftt);

extern void guMtxIdent(Mtx *m);
extern void guMtxIdentF(float mf[4][4]);
extern void guOrtho(Mtx *m, float l, float r, float b, float t,
      float n, float f, float scale);
extern void guOrthoF(float mf[4][4], float l, float r, float b, float t,
       float n, float f, float scale);
extern void guFrustum(Mtx *m, float l, float r, float b, float t,
        float n, float f, float scale);
extern void guFrustumF(float mf[4][4], float l, float r, float b, float t,
         float n, float f, float scale);
extern void guPerspective(Mtx *m, u16 *perspNorm, float fovy,
     float aspect, float near, float far, float scale);
extern void guPerspectiveF(float mf[4][4], u16 *perspNorm, float fovy,
      float aspect, float near, float far, float scale);
extern void guLookAt(Mtx *m,
   float xEye, float yEye, float zEye,
   float xAt, float yAt, float zAt,
   float xUp, float yUp, float zUp);
extern void guLookAtF(float mf[4][4], float xEye, float yEye, float zEye,
        float xAt, float yAt, float zAt,
        float xUp, float yUp, float zUp);
extern void guLookAtReflect(Mtx *m, LookAt *l,
   float xEye, float yEye, float zEye,
   float xAt, float yAt, float zAt,
   float xUp, float yUp, float zUp);
extern void guLookAtReflectF(float mf[4][4], LookAt *l,
        float xEye, float yEye, float zEye,
        float xAt, float yAt, float zAt,
        float xUp, float yUp, float zUp);
extern void guLookAtHilite(Mtx *m, LookAt *l, Hilite *h,
                float xEye, float yEye, float zEye,
                float xAt, float yAt, float zAt,
                float xUp, float yUp, float zUp,
                float xl1, float yl1, float zl1,
                float xl2, float yl2, float zl2,
  int twidth, int theight);
extern void guLookAtHiliteF(float mf[4][4], LookAt *l, Hilite *h,
  float xEye, float yEye, float zEye,
  float xAt, float yAt, float zAt,
  float xUp, float yUp, float zUp,
  float xl1, float yl1, float zl1,
  float xl2, float yl2, float zl2,
  int twidth, int theight);
extern void guLookAtStereo(Mtx *m,
   float xEye, float yEye, float zEye,
   float xAt, float yAt, float zAt,
   float xUp, float yUp, float zUp,
   float eyedist);
extern void guLookAtStereoF(float mf[4][4],
         float xEye, float yEye, float zEye,
         float xAt, float yAt, float zAt,
         float xUp, float yUp, float zUp,
   float eyedist);
extern void guRotate(Mtx *m, float a, float x, float y, float z);
extern void guRotateF(float mf[4][4], float a, float x, float y, float z);
extern void guRotateRPY(Mtx *m, float r, float p, float y);
extern void guRotateRPYF(float mf[4][4], float r, float p, float h);
extern void guAlign(Mtx *m, float a, float x, float y, float z);
extern void guAlignF(float mf[4][4], float a, float x, float y, float z);
extern void guScale(Mtx *m, float x, float y, float z);
extern void guScaleF(float mf[4][4], float x, float y, float z);
extern void guTranslate(Mtx *m, float x, float y, float z);
extern void guTranslateF(float mf[4][4], float x, float y, float z);
extern void guPosition(Mtx *m, float r, float p, float h, float s,
         float x, float y, float z);
extern void guPositionF(float mf[4][4], float r, float p, float h, float s,
   float x, float y, float z);
extern void guMtxF2L(float mf[4][4], Mtx *m);
extern void guMtxL2F(float mf[4][4], Mtx *m);
extern void guMtxCatF(float m[4][4], float n[4][4], float r[4][4]);
extern void guMtxCatL(Mtx *m, Mtx *n, Mtx *res);
extern void guMtxXFMF(float mf[4][4], float x, float y, float z,
        float *ox, float *oy, float *oz);
extern void guMtxXFML(Mtx *m, float x, float y, float z,
        float *ox, float *oy, float *oz);


extern void guNormalize(float *x, float *y, float *z);


void guPosLight(PositionalLight *pl, Light *l,
                float xOb, float yOb, float zOb);
void guPosLightHilite(PositionalLight *pl1, PositionalLight *pl2,
                Light *l1, Light *l2,
                LookAt *l, Hilite *h,
                float xEye, float yEye, float zEye,
                float xOb, float yOb, float zOb,
                float xUp, float yUp, float zUp,
                int twidth, int theight);
extern int guRandom(void);




extern float sinf(float angle);
extern float cosf(float angle);
extern signed short sins (unsigned short angle);
extern signed short coss (unsigned short angle);
extern float sqrtf(float value);





#define GU_PARSERDP_VERBOSE 1
#define GU_PARSERDP_PRAREA 2
#define GU_PARSERDP_PRHISTO 4
#define GU_PARSERDP_DUMPONLY 32



extern void guParseRdpDL(u64 *rdp_dl, u64 nbytes, u8 flags);
extern void guParseString(char *StringPointer, u64 nbytes);








#define GU_BLINKRDP_HILITE 1
#define GU_BLINKRDP_EXTRACT 2

extern void
guBlinkRdpDL(u64 *rdp_dl_in, u64 nbytes_in,
             u64 *rdp_dl_out, u64 *nbytes_out,
             u32 x, u32 y, u32 radius,
             u8 red, u8 green, u8 blue,
             u8 flags);


#define GU_PARSEGBI_ROWMAJOR 1
#define GU_PARSEGBI_NONEST 2
#define GU_PARSEGBI_FLTMTX 4
#define GU_PARSEGBI_SHOWDMA 8
#define GU_PARSEGBI_ALLMTX 16
#define GU_PARSEGBI_DUMPONLY 32




extern void guParseGbiDL(u64 *gbi_dl, u32 nbytes, u8 flags);
extern void guDumpGbiDL(OSTask *tp,u8 flags);

#define GU_PARSE_GBI_TYPE 1
#define GU_PARSE_RDP_TYPE 2
#define GU_PARSE_READY 3
#define GU_PARSE_MEM_BLOCK 4
#define GU_PARSE_ABI_TYPE 5
#define GU_PARSE_STRING_TYPE 6

typedef struct {
    int dataSize;
    int dlType;
    int flags;
    u32 paddr;
} guDLPrintCB;

void guSprite2DInit(uSprite *SpritePointer,
      void *SourceImagePointer,
      void *TlutPointer,
      int Stride,
      int SubImageWidth,
      int SubImageHeight,
      int SourceImageType,
      int SourceImageBitSize,
      int ScaleX,
      int ScaleY,
      int FlipTextureX,
      int FlipTextureY,
      int SourceImageOffsetS,
      int SourceImageOffsetT,
      int PScreenX,
      int PScreenY);



#define __LIB_AUDIO__ 

#define NULL 0

#define AL_FX_BUFFER_SIZE 8192
#define AL_FRAME_INIT -1
#define AL_USEC_PER_FRAME 16000
#define AL_MAX_PRIORITY 127
#define AL_GAIN_CHANGE_TIME 1000

typedef s32 ALMicroTime;
typedef u8 ALPan;

#define AL_PAN_CENTER 64
#define AL_PAN_LEFT 0
#define AL_PAN_RIGHT 127
#define AL_VOL_FULL 127
#define AL_KEY_MIN 0
#define AL_KEY_MAX 127
#define AL_DEFAULT_FXMIX 0
#define AL_SUSTAIN 63

#define ALFailIf(condition,error) if (condition) { return; }

#define ALFlagFailIf(condition,flag,error) if (condition) { return; }







typedef struct ALLink_s {
    struct ALLink_s *next;
    struct ALLink_s *prev;
} ALLink;

void alUnlink(ALLink *element);
void alLink(ALLink *element, ALLink *after);

typedef s32 (*ALDMAproc)(s32 addr, s32 len, void *state);
typedef ALDMAproc (*ALDMANew)(void *state);

void alCopy(void *src, void *dest, s32 len);

typedef struct {
    u8 *base;
    u8 *cur;
    s32 len;
    s32 count;
} ALHeap;

#define AL_HEAP_DEBUG 1
#define AL_HEAP_MAGIC 0x20736a73
#define AL_HEAP_INIT 0

void alHeapInit(ALHeap *hp, u8 *base, s32 len);
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size);
s32 alHeapCheck(ALHeap *hp);




#define alHeapAlloc(hp,elem,size) alHeapDBAlloc(0, 0,(hp),(elem),(size))





#define AL_FX_NONE 0
#define AL_FX_SMALLROOM 1
#define AL_FX_BIGROOM 2
#define AL_FX_CHORUS 3
#define AL_FX_FLANGE 4
#define AL_FX_ECHO 5
#define AL_FX_CUSTOM 6

typedef u8 ALFxId;
typedef void *ALFxRef;





#define AL_BANK_VERSION 'B1'


enum {AL_ADPCM_WAVE = 0,
         AL_RAW16_WAVE};

typedef struct {
    s32 order;
    s32 npredictors;
    s16 book[1];
} ALADPCMBook;

typedef struct {
    u32 start;
    u32 end;
    u32 count;
    ADPCM_STATE state;
} ALADPCMloop;

typedef struct {
    u32 start;
    u32 end;
    u32 count;
} ALRawLoop;

typedef struct {
    ALMicroTime attackTime;
    ALMicroTime decayTime;
    ALMicroTime releaseTime;
    u8 attackVolume;
    u8 decayVolume;
} ALEnvelope;

typedef struct {
    u8 velocityMin;
    u8 velocityMax;
    u8 keyMin;
    u8 keyMax;
    u8 keyBase;
    s8 detune;
} ALKeyMap;

typedef struct {
    ALADPCMloop *loop;
    ALADPCMBook *book;
} ALADPCMWaveInfo;

typedef struct {
    ALRawLoop *loop;
} ALRAWWaveInfo;

typedef struct ALWaveTable_s {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
    union {
        ALADPCMWaveInfo adpcmWave;
        ALRAWWaveInfo rawWave;
    } waveInfo;
} ALWaveTable;

typedef struct ALSound_s {
    ALEnvelope *envelope;
    ALKeyMap *keyMap;
    ALWaveTable *wavetable;
    ALPan samplePan;
    u8 sampleVolume;
    u8 flags;
} ALSound;

typedef struct {
    u8 volume;
    ALPan pan;
    u8 priority;
    u8 flags;
    u8 tremType;
    u8 tremRate;
    u8 tremDepth;
    u8 tremDelay;
    u8 vibType;
    u8 vibRate;
    u8 vibDepth;
    u8 vibDelay;
    s16 bendRange;
    s16 soundCount;
    ALSound *soundArray[1];
} ALInstrument;

typedef struct ALBank_s {
    s16 instCount;
    u8 flags;
    u8 pad;
    s32 sampleRate;
    ALInstrument *percussion;
    ALInstrument *instArray[1];
} ALBank;

typedef struct {
    s16 revision;
    s16 bankCount;
    ALBank *bankArray[1];
} ALBankFile;

void alBnkfNew(ALBankFile *f, u8 *table);




#define AL_SEQBANK_VERSION 'S1'

typedef struct {
    u8 *offset;
    s32 len;
} ALSeqData;

typedef struct {
    s16 revision;
    s16 seqCount;
    ALSeqData seqArray[1];
} ALSeqFile;

void alSeqFileNew(ALSeqFile *f, u8 *base);




typedef ALMicroTime (*ALVoiceHandler)(void *);

typedef struct {
    s32 maxVVoices;
    s32 maxPVoices;
    s32 maxUpdates;
    s32 maxFXbusses;
    void *dmaproc;
    ALHeap *heap;
    s32 outputRate;
    ALFxId fxType;
    s32 *params;
} ALSynConfig;

typedef struct ALPlayer_s {
    struct ALPlayer_s *next;
    void *clientData;
    ALVoiceHandler handler;
    ALMicroTime callTime;
    s32 samplesLeft;
} ALPlayer;

typedef struct ALVoice_s {
    ALLink node;
    struct PVoice_s *pvoice;
    ALWaveTable *table;
    void *clientPrivate;
    s16 state;
    s16 priority;
    s16 fxBus;
    s16 unityPitch;
} ALVoice;

typedef struct ALVoiceConfig_s {
    s16 priority;
    s16 fxBus;
    u8 unityPitch;
} ALVoiceConfig;

typedef struct {
    ALPlayer *head;
    ALLink pFreeList;
    ALLink pAllocList;
    ALLink pLameList;
    s32 paramSamples;
    s32 curSamples;
    ALDMANew dma;
    ALHeap *heap;

    struct ALParam_s *paramList;

    struct ALMainBus_s *mainBus;
    struct ALAuxBus_s *auxBus;
    struct ALFilter_s *outputFilter;

    s32 numPVoices;
    s32 maxAuxBusses;
    s32 outputRate;
    s32 maxOutSamples;

} ALSynth;

void alSynNew(ALSynth *s, ALSynConfig *config);
void alSynDelete(ALSynth *s);

void alSynAddPlayer(ALSynth *s, ALPlayer *client);
void alSynRemovePlayer(ALSynth *s, ALPlayer *client);

s32 alSynAllocVoice(ALSynth *s, ALVoice *v, ALVoiceConfig *vc);
void alSynFreeVoice(ALSynth *s, ALVoice *voice);

void alSynStartVoice(ALSynth *s, ALVoice *voice, ALWaveTable *w);
void alSynStartVoiceParams(ALSynth *s, ALVoice *voice, ALWaveTable *w,
                              f32 pitch, s16 vol, ALPan pan, u8 fxmix,
                              ALMicroTime t);
void alSynStopVoice(ALSynth *s, ALVoice *voice);

void alSynSetVol(ALSynth *s, ALVoice *v, s16 vol, ALMicroTime delta);
void alSynSetPitch(ALSynth *s, ALVoice *voice, f32 ratio);
void alSynSetPan(ALSynth *s, ALVoice *voice, ALPan pan);
void alSynSetFXMix(ALSynth *s, ALVoice *voice, u8 fxmix);
void alSynSetPriority(ALSynth *s, ALVoice *voice, s16 priority);
s16 alSynGetPriority(ALSynth *s, ALVoice *voice);

ALFxRef *alSynAllocFX(ALSynth *s, s16 bus, ALSynConfig *c, ALHeap *hp);
ALFxRef alSynGetFXRef(ALSynth *s, s16 bus, s16 index);
void alSynFreeFX(ALSynth *s, ALFxRef *fx);
void alSynSetFXParam(ALSynth *s, ALFxRef fx, s16 paramID, void *param);




typedef struct {
    ALSynth drvr;
} ALGlobals;

extern ALGlobals *alGlobals;

void alInit(ALGlobals *glob, ALSynConfig *c);
void alClose(ALGlobals *glob);

Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen);








#define AL_STOPPED 0
#define AL_PLAYING 1
#define AL_STOPPING 2

#define AL_DEFAULT_PRIORITY 5
#define AL_DEFAULT_VOICE 0
#define AL_MAX_CHANNELS 16




enum ALMsg {
    AL_SEQ_REF_EVT,
    AL_SEQ_MIDI_EVT,
    AL_SEQP_MIDI_EVT,
    AL_TEMPO_EVT,
    AL_SEQ_END_EVT,
    AL_NOTE_END_EVT,
    AL_SEQP_ENV_EVT,
    AL_SEQP_META_EVT,
    AL_SEQP_PROG_EVT,
    AL_SEQP_API_EVT,
    AL_SEQP_VOL_EVT,
    AL_SEQP_LOOP_EVT,
    AL_SEQP_PRIORITY_EVT,
    AL_SEQP_SEQ_EVT,
    AL_SEQP_BANK_EVT,
    AL_SEQP_PLAY_EVT,
    AL_SEQP_STOP_EVT,
    AL_SEQP_STOPPING_EVT,
    AL_TRACK_END,
    AL_CSP_LOOPSTART,
    AL_CSP_LOOPEND,
    AL_CSP_NOTEOFF_EVT,
    AL_TREM_OSC_EVT,
    AL_VIB_OSC_EVT
};




#define AL_EVTQ_END 0x7fffffff

enum AL_MIDIstatus {

    AL_MIDI_ChannelMask = 0x0F,
    AL_MIDI_StatusMask = 0xF0,


    AL_MIDI_ChannelVoice = 0x80,
    AL_MIDI_NoteOff = 0x80,
    AL_MIDI_NoteOn = 0x90,
    AL_MIDI_PolyKeyPressure = 0xA0,
    AL_MIDI_ControlChange = 0xB0,
    AL_MIDI_ChannelModeSelect = 0xB0,
    AL_MIDI_ProgramChange = 0xC0,
    AL_MIDI_ChannelPressure = 0xD0,
    AL_MIDI_PitchBendChange = 0xE0,


    AL_MIDI_SysEx = 0xF0,


    AL_MIDI_SystemCommon = 0xF1,
    AL_MIDI_TimeCodeQuarterFrame = 0xF1,
    AL_MIDI_SongPositionPointer = 0xF2,
    AL_MIDI_SongSelect = 0xF3,
    AL_MIDI_Undefined1 = 0xF4,
    AL_MIDI_Undefined2 = 0xF5,
    AL_MIDI_TuneRequest = 0xF6,
    AL_MIDI_EOX = 0xF7,


    AL_MIDI_SystemRealTime = 0xF8,
    AL_MIDI_TimingClock = 0xF8,
    AL_MIDI_Undefined3 = 0xF9,
    AL_MIDI_Start = 0xFA,
    AL_MIDI_Continue = 0xFB,
    AL_MIDI_Stop = 0xFC,
    AL_MIDI_Undefined4 = 0xFD,
    AL_MIDI_ActiveSensing = 0xFE,
    AL_MIDI_SystemReset = 0xFF,
    AL_MIDI_Meta = 0xFF
};

enum AL_MIDIctrl {
    AL_MIDI_VOLUME_CTRL = 0x07,
    AL_MIDI_PAN_CTRL = 0x0A,
    AL_MIDI_PRIORITY_CTRL = 0x10,
    AL_MIDI_FX_CTRL_0 = 0x14,
    AL_MIDI_FX_CTRL_1 = 0x15,
    AL_MIDI_FX_CTRL_2 = 0x16,
    AL_MIDI_FX_CTRL_3 = 0x17,
    AL_MIDI_FX_CTRL_4 = 0x18,
    AL_MIDI_FX_CTRL_5 = 0x19,
    AL_MIDI_FX_CTRL_6 = 0x1A,
    AL_MIDI_FX_CTRL_7 = 0x1B,
    AL_MIDI_FX_CTRL_8 = 0x1C,
    AL_MIDI_FX_CTRL_9 = 0x1D,
    AL_MIDI_SUSTAIN_CTRL = 0x40,
    AL_MIDI_FX1_CTRL = 0x5B,
    AL_MIDI_FX3_CTRL = 0x5D
};

enum AL_MIDImeta {
    AL_MIDI_META_TEMPO = 0x51,
    AL_MIDI_META_EOT = 0x2f
};


#define AL_CMIDI_BLOCK_CODE 0xFE
#define AL_CMIDI_LOOPSTART_CODE 0x2E
#define AL_CMIDI_LOOPEND_CODE 0x2D
#define AL_CMIDI_CNTRL_LOOPSTART 102
#define AL_CMIDI_CNTRL_LOOPEND 103
#define AL_CMIDI_CNTRL_LOOPCOUNT_SM 104
#define AL_CMIDI_CNTRL_LOOPCOUNT_BIG 105

typedef struct {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
} ALSeqMarker;

typedef struct {
    s32 ticks;
    u8 status;
    u8 byte1;
    u8 byte2;
    u32 duration;
} ALMIDIEvent;

typedef struct {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
    u8 byte1;
    u8 byte2;
    u8 byte3;
} ALTempoEvent;

typedef struct {
    s32 ticks;
    u8 status;
    u8 type;
    u8 len;
} ALEndEvent;

typedef struct {
    struct ALVoice_s *voice;
} ALNoteEvent;

typedef struct {
    struct ALVoice_s *voice;
    ALMicroTime delta;
    u8 vol;
} ALVolumeEvent;

typedef struct {
    s16 vol;
} ALSeqpVolEvent;

typedef struct {
    ALSeqMarker *start;
    ALSeqMarker *end;
    s32 count;
} ALSeqpLoopEvent;

typedef struct {
    u8 chan;
    u8 priority;
} ALSeqpPriorityEvent;

typedef struct {
    void *seq;
} ALSeqpSeqEvent;

typedef struct {
    ALBank *bank;
} ALSeqpBankEvent;

typedef struct {
    struct ALVoiceState_s *vs;
    void *oscState;
    u8 chan;
} ALOscEvent;

typedef struct {
    s16 type;
    union {
        ALMIDIEvent midi;
        ALTempoEvent tempo;
        ALEndEvent end;
        ALNoteEvent note;
        ALVolumeEvent vol;
        ALSeqpLoopEvent loop;
        ALSeqpVolEvent spvol;
 ALSeqpPriorityEvent sppriority;
 ALSeqpSeqEvent spseq;
 ALSeqpBankEvent spbank;
        ALOscEvent osc;
    } msg;
} ALEvent;

typedef struct {
    ALLink node;
    ALMicroTime delta;
    ALEvent evt;
} ALEventListItem;

typedef struct {
    ALLink freeList;
    ALLink allocList;
    s32 eventCount;
} ALEventQueue;

void alEvtqNew(ALEventQueue *evtq, ALEventListItem *items,
                          s32 itemCount);
ALMicroTime alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt);
void alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt,
                                ALMicroTime delta);
void alEvtqFlush(ALEventQueue *evtq);
void alEvtqFlushType(ALEventQueue *evtq, s16 type);


#define AL_PHASE_ATTACK 0
#define AL_PHASE_NOTEON 0
#define AL_PHASE_DECAY 1
#define AL_PHASE_SUSTAIN 2
#define AL_PHASE_RELEASE 3
#define AL_PHASE_SUSTREL 4

typedef struct ALVoiceState_s {
    struct ALVoiceState_s *next;
    ALVoice voice;
    ALSound *sound;
    ALMicroTime envEndTime;
    f32 pitch;
    f32 vibrato;
    u8 envGain;
    u8 channel;
    u8 key;
    u8 velocity;
    u8 envPhase;
    u8 phase;
    u8 tremelo;
    u8 flags;

} ALVoiceState;

typedef struct {
    ALInstrument *instrument;
    s16 bendRange;
    ALFxId fxId;
    ALPan pan;
    u8 priority;
    u8 vol;
    u8 fxmix;
    u8 sustain;
    f32 pitchBend;
} ALChanState;

typedef struct ALSeq_s {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
} ALSeq;

typedef struct {
    u32 trackOffset[16];
    u32 division;
} ALCMidiHdr;

typedef struct ALCSeq_s {
    ALCMidiHdr *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[16];


    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeq;

typedef struct {
    u32 validTracks;
    s32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
} ALCSeqMarker;

#define NO_SOUND_ERR_MASK 0x01
#define NOTE_OFF_ERR_MASK 0x02
#define NO_VOICE_ERR_MASK 0x04

typedef struct {
    s32 maxVoices;
    s32 maxEvents;
    u8 maxChannels;
    u8 debugFlags;
    ALHeap *heap;
    void *initOsc;
    void *updateOsc;
    void *stopOsc;
} ALSeqpConfig;

typedef ALMicroTime (*ALOscInit)(void **oscState,f32 *initVal, u8 oscType,
                                   u8 oscRate, u8 oscDepth, u8 oscDelay);
typedef ALMicroTime (*ALOscUpdate)(void *oscState, f32 *updateVal);
typedef void (*ALOscStop)(void *oscState);

typedef struct {
    ALPlayer node;
    ALSynth *drvr;
    ALSeq *target;
    ALMicroTime curTime;
    ALBank *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
    ALSeqMarker *loopStart;
    ALSeqMarker *loopEnd;
    s32 loopCount;
} ALSeqPlayer;

typedef struct {
    ALPlayer node;
    ALSynth *drvr;
    ALCSeq *target;
    ALMicroTime curTime;
    ALBank *bank;
    s32 uspt;
    s32 nextDelta;
    s32 state;
    u16 chanMask;
    s16 vol;
    u8 maxChannels;
    u8 debugFlags;
    ALEvent nextEvent;
    ALEventQueue evtq;
    ALMicroTime frameTime;
    ALChanState *chanState;
    ALVoiceState *vAllocHead;
    ALVoiceState *vAllocTail;
    ALVoiceState *vFreeList;
    ALOscInit initOsc;
    ALOscUpdate updateOsc;
    ALOscStop stopOsc;
} ALCSPlayer;




void alSeqNew(ALSeq *seq, u8 *ptr, s32 len);
void alSeqNextEvent(ALSeq *seq, ALEvent *event);
s32 alSeqGetTicks(ALSeq *seq);
f32 alSeqTicksToSec(ALSeq *seq, s32 ticks, u32 tempo);
u32 alSeqSecToTicks(ALSeq *seq, f32 sec, u32 tempo);
void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks);
void alSeqSetLoc(ALSeq *seq, ALSeqMarker *marker);
void alSeqGetLoc(ALSeq *seq, ALSeqMarker *marker);



void alCSeqNew(ALCSeq *seq, u8 *ptr);
void alCSeqNextEvent(ALCSeq *seq,ALEvent *evt);
s32 alCSeqGetTicks(ALCSeq *seq);
f32 alCSeqTicksToSec(ALCSeq *seq, s32 ticks, u32 tempo);
u32 alCSeqSecToTicks(ALCSeq *seq, f32 sec, u32 tempo);
void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks);
void alCSeqSetLoc(ALCSeq *seq, ALCSeqMarker *marker);
void alCSeqGetLoc(ALCSeq *seq, ALCSeqMarker *marker);




f32 alCents2Ratio(s32 cents);

void alSeqpNew(ALSeqPlayer *seqp, ALSeqpConfig *config);
void alSeqpDelete(ALSeqPlayer *seqp);
void alSeqpSetSeq(ALSeqPlayer *seqp, ALSeq *seq);
ALSeq *alSeqpGetSeq(ALSeqPlayer *seqp);
void alSeqpPlay(ALSeqPlayer *seqp);
void alSeqpStop(ALSeqPlayer *seqp);
s32 alSeqpGetState(ALSeqPlayer *seqp);
void alSeqpSetBank(ALSeqPlayer *seqp, ALBank *b);
void alSeqpSetTempo(ALSeqPlayer *seqp, s32 tempo);
s32 alSeqpGetTempo(ALSeqPlayer *seqp);
s16 alSeqpGetVol(ALSeqPlayer *seqp);
void alSeqpSetVol(ALSeqPlayer *seqp, s16 vol);
void alSeqpLoop(ALSeqPlayer *seqp, ALSeqMarker *start, ALSeqMarker *end, s32 count);

void alSeqpSetChlProgram(ALSeqPlayer *seqp, u8 chan, u8 prog);
s32 alSeqpGetChlProgram(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlFXMix(ALSeqPlayer *seqp, u8 chan, u8 fxmix);
u8 alSeqpGetChlFXMix(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlVol(ALSeqPlayer *seqp, u8 chan, u8 vol);
u8 alSeqpGetChlVol(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlPan(ALSeqPlayer *seqp, u8 chan, ALPan pan);
ALPan alSeqpGetChlPan(ALSeqPlayer *seqp, u8 chan);
void alSeqpSetChlPriority(ALSeqPlayer *seqp, u8 chan, u8 priority);
u8 alSeqpGetChlPriority(ALSeqPlayer *seqp, u8 chan);
void alSeqpSendMidi(ALSeqPlayer *seqp, s32 ticks, u8 status, u8 byte1, u8 byte2);



#define alSeqpSetProgram alSeqpSetChlProgram
#define alSeqpGetProgram alSeqpGetChlProgram
#define alSeqpSetFXMix alSeqpSetChlFXMix
#define alSeqpGetFXMix alSeqpGetChlFXMix
#define alSeqpSetPan alSeqpSetChlPan
#define alSeqpGetPan alSeqpGetChlPan
#define alSeqpSetChannelPriority alSeqpSetChlPriority
#define alSeqpGetChannelPriority alSeqpGetChlPriority






void alCSPNew(ALCSPlayer *seqp, ALSeqpConfig *config);
void alCSPDelete(ALCSPlayer *seqp);
void alCSPSetSeq(ALCSPlayer *seqp, ALCSeq *seq);
ALCSeq *alCSPGetSeq(ALCSPlayer *seqp);
void alCSPPlay(ALCSPlayer *seqp);
void alCSPStop(ALCSPlayer *seqp);
s32 alCSPGetState(ALCSPlayer *seqp);
void alCSPSetBank(ALCSPlayer *seqp, ALBank *b);
void alCSPSetTempo(ALCSPlayer *seqp, s32 tempo);
s32 alCSPGetTempo(ALCSPlayer *seqp);
s16 alCSPGetVol(ALCSPlayer *seqp);
void alCSPSetVol(ALCSPlayer *seqp, s16 vol);

void alCSPSetChlProgram(ALCSPlayer *seqp, u8 chan, u8 prog);
s32 alCSPGetChlProgram(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlFXMix(ALCSPlayer *seqp, u8 chan, u8 fxmix);
u8 alCSPGetChlFXMix(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlPan(ALCSPlayer *seqp, u8 chan, ALPan pan);
ALPan alCSPGetChlPan(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlVol(ALCSPlayer *seqp, u8 chan, u8 vol);
u8 alCSPGetChlVol(ALCSPlayer *seqp, u8 chan);
void alCSPSetChlPriority(ALCSPlayer *seqp, u8 chan, u8 priority);
u8 alCSPGetChlPriority(ALCSPlayer *seqp, u8 chan);
void alCSPSendMidi(ALCSPlayer *seqp, s32 ticks, u8 status,
                       u8 byte1, u8 byte2);



#define alCSPSetProgram alCSPSetChlProgram
#define alCSPGetProgram alCSPGetChlProgram
#define alCSPSetFXMix alCSPSetChlFXMix
#define alCSPGetFXMix alCSPGetChlFXMix
#define alCSPSetPan alCSPSetChlPan
#define alCSPGetPan alCSPGetChlPan
#define alCSPSetChannelPriority alCSPSetChlPriority
#define alCSPGetChannelPriority alCSPGetChlPriority







typedef struct {
    s32 maxSounds;
    s32 maxEvents;
    ALHeap *heap;
} ALSndpConfig;

typedef struct {
    ALPlayer node;
    ALEventQueue evtq;
    ALEvent nextEvent;
    ALSynth *drvr;
    s32 target;
    void *sndState;
    s32 maxSounds;
    ALMicroTime frameTime;
    ALMicroTime nextDelta;
    ALMicroTime curTime;
} ALSndPlayer;

typedef s16 ALSndId;

void alSndpNew(ALSndPlayer *sndp, ALSndpConfig *c);
void alSndpDelete(ALSndPlayer *sndp);

ALSndId alSndpAllocate(ALSndPlayer *sndp, ALSound *sound);
void alSndpDeallocate(ALSndPlayer *sndp, ALSndId id);

void alSndpSetSound(ALSndPlayer *sndp, ALSndId id);
ALSndId alSndpGetSound(ALSndPlayer *sndp);

void alSndpPlay(ALSndPlayer *sndp);
void alSndpPlayAt(ALSndPlayer *sndp, ALMicroTime delta);
void alSndpStop(ALSndPlayer *sndp);

void alSndpSetVol(ALSndPlayer *sndp, s16 vol);
void alSndpSetPitch(ALSndPlayer *sndp, f32 pitch);
void alSndpSetPan(ALSndPlayer *sndp, ALPan pan);
void alSndpSetPriority(ALSndPlayer *sndp, ALSndId id, u8 priority);

void alSndpSetFXMix(ALSndPlayer *sndp, u8 mix);
s32 alSndpGetState(ALSndPlayer *sndp);


void alParseAbiCL(Acmd *cmdList, u32 nbytes);







#define _INC_DEFS 




#define MAKE_CART 
#define SHIP_IT 


#define TRAP_ON_ASSERT 
#define DISPLAY_FRAMERATE 
#define DISPLAY_COORDINATES 



#define ENGLISH 

#define USE_ZBUFFER 
#define USE_FOG 
#define USE_FIFO 



#define FIFO_SIZE 0x10000



#define LINELIST_LEN 2048
#define GLIST_LEN (16384 - LINELIST_LEN)

#define FRAME_FPS 15



#define REFRESHES_TO_FRAME_INC(nRefreshes,RefreshRate) (((nRefreshes)*FRAME_FPS)/RefreshRate)
#define FRAME_INC_TO_REFRESHES(frameInc) ((frameInc)*refresh_rate*(1.0/FRAME_FPS))
#define FRAME_INC_TO_SECONDS(frameInc) ((frameInc)*(1.0/FRAME_FPS))

#define SECONDS_TO_FRAMES(secs) ((secs)*FRAME_FPS)
#define DISPLAY_LIST_RESERVE_FRONTEND 3000

#define MAX_FRAME_SKIP 4
#define HASH_ALLOC_BLOCK 512
#define HASH_TABLE_SIZE 473

#define COLLISION_MAX_INSTANCES 1024
#define MAX_ACTIVE_ANIM_INSTANCES 64
#define STATICEVENTS_MAX_INSTANCES 64


#define PARTICLES_MAX_COUNT 128


#define MATTABLE_MATRICES 32

#define MAX_TRANSPARENT_INSTANCES 64

#define TUROK_HEIGHT 6.0
#define TUROK_EYE_HEIGHT (0.9*TUROK_HEIGHT)

#define COLLISION_GREASE_FACTOR 0.25
#define PLAYER_TILT_FACTOR 0.8
#define PLAYER_ZROT_FACTOR 0.25
#define NEWGROUNDROT_FACTOR 0.125
#define NEWSHADOWROT_FACTOR 0.4


#define WORLD_LIMIT (1400*SCALING_FACTOR)





#define G_CC_ROB_SHADEPRIMRGBA PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE




#define G_CC_ROB_DECALRGBA_PRIMALPHA 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0





#define G_CC_ROB_PSEUDOCOLOR_PRIMALPHA PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0




#define G_CC_ROB_BLACK_PRIMALPHA 0, 0, 0, 0, TEXEL0, 0, PRIMITIVE, 0






#define TRUE 1
#define FALSE 0

#define BOOL int
#define BYTE unsigned char
#define DWORD unsigned long
#define WORD unsigned short
#define INT32 signed long
#define UINT32 unsigned long
#define UINT unsigned long

#define FLOAT float
#define UINT16 unsigned short
#define INT16 signed short
#define INT8 signed char
#define UINT8 unsigned char





#define MAKE_CART 




#undef IG_DEBUG
#undef SCREEN_SHOT


#undef TRAP_ON_ASSERT
#undef DISPLAY_FRAMERATE
#undef DISPLAY_COORDINATES

#define ASSERT(expr) 







#define PASCAL 
#define CYCLES_TO_NSEC OS_CYCLES_TO_NSEC

extern unsigned long D_800B6AF0;
extern int trap_line;
extern const char *trap_file;
extern const char *trap_expr;
extern int trap_thread;

#define TRACE0(a0) 
#define TRACE(a0,a1) 
#define TRACE1(a0,a1) 
#define TRACE2(a0,a1,a2) 
#define TRACE3(a0,a1,a2,a3) 
#define TRACE4(a0,a1,a2,a3,a4) 
#define TRACE5(a0,a1,a2,a3,a4,a5) 
#define TRACE6(a0,a1,a2,a3,a4,a5,a6) 


#define max(a,b) MAX(a, b)
#define min(a,b) MIN(a, b)
#define abs(n) (((n) < 0) ? -(n) : (n))
#define fabs(n) abs(n)
#define sqrt(n) sqrtf(n)
#define sin(n) sinf(n)
#define cos(n) cosf(n)
#define floor(n) ((n >= 0) ? ((int)(n)) : ((((int)(n)) == n) ? ((int)(n)) : (((int)(n)) - 1)))
#define ceil(n) ((n <= 0) ? ((int)(n)) : ((((int)(n)) == n) ? ((int)(n)) : (((int)(n)) + 1)))
void func_80083B80(const char *src, const char *dest, const int len);
void igAssert(const char *szFile, int nLine, const char *szExpr);
int func_80083BF4(unsigned long Keys[], int nItems, unsigned long SearchKey);
int func_80083C74(unsigned long Keys[], int nItems, unsigned long SearchKey, int *pFirst, int *pLast);
int func_80083D38(int nBits);
int func_80083D54(unsigned char Bits[], int nBit);
void func_80083D94(unsigned char Bits[], int nBit, int Set);

#define ANGLE_PI 3.14159265358979323846
#define ANGLE_DTOR(deg) ((deg)*(ANGLE_PI/180))
#define ANGLE_RTOD(radian) (((radian)*180.0)/ANGLE_PI)
#define ANGLE_COS_60 0.5
#define ANGLE_LEDGE_COSINE ANGLE_COS_60
#define SQR(a) ((a) * (a))

#define INVERSE_SQR_TWEEN(t) (1.0 - ((1.0-(t))*(1.0-(t))))
#define COSINE_TWEEN(Tween) (0.5 - (cos((Tween) * ANGLE_PI) / 2.0))
#define SQR_TWEEN(Tween) ((Tween)*(Tween))




#define CQuatern__Blend(pqThis,u,pqA,pqB) CQuatern__BlendThreshold(pqThis, u, pqA, pqB)


#define RSP_ADDRESS(p) (p)
#define RDP_ADDRESS(p) (p)



#define RANDOM(range) (RandomSwapWord() % (range))
#define SOUND_RANDOM(range) (SoundRandomSwapWord() % (range))


#define MIN_COL 0
#define MAX_COL 255

#define MIN_OPAQ 0
#define MAX_OPAQ 255

#define MIN_TRANS 255
#define MAX_TRANS 0





#define __MEMORY_H 



#define LOCAL_STDDEF_H 
typedef unsigned int size_t;
typedef int ptrdiff_t;



#define offsetof(type,field) ((unsigned int)&((type *)0)->field)


#define MEMORY_ALIGN 8

typedef struct s_Memory {
 struct s_Memory *prev ;
 struct s_Memory *next ;
 void *addr ;
 int size ;
} t_Memory ;



typedef struct s_MemoryPool {
 void *addr ;
 int size ;
 struct s_Memory *free_head ;
 struct s_Memory *free_tail ;
 struct s_Memory *used_head ;
} t_MemoryPool ;

void func_80012158 (void *pAddress, int Size) ;

t_MemoryPool *i3D_addPool (int size) ;
int i3D_removePool (t_MemoryPool *pool) ;
void *func_80011EC0 (t_MemoryPool *pool, int size) ;
void *func_80011E04 (t_MemoryPool *pool, int size) ;

void *func_80011FC8 (t_MemoryPool *pool, void *address, int size) ;
void *func_80012084 (void *address, int size) ;

int i3D_freePool (t_MemoryPool *pool, void *address) ;
int func_80011D6C (t_MemoryPool *pool) ;

void *i3D_malloc (int size) ;
void *i3D_mallocTop (int size) ;
int i3D_free (void *address) ;
int i3D_freeAll (void) ;

int func_80011B1C (t_MemoryPool *pool) ;
int i3D_memoryCheckGlobal();

void FreeMem(int *pTotal, int *pLargest);
int func_80011AF8(void *pAddress);
void PrintLowestFree();

#define ALLOC(size) i3D_malloc(size)
#define ALLOCTOP(size) i3D_mallocTop(size)
#define DEALLOC(ptr) i3D_free(ptr)



void func_80012218(void *pDest, void *pSrc, int Count);
void func_800121B8(void *pDest, unsigned char Val, int Count);





#define F3DEX_GBI 









#define _INC_TENGINE 





#define STATIC_SEGMENT 1
#define CFB_SEGMENT 2

#define SCREEN_HT 240
#define SCREEN_WD 320

#define IDLE_STACKSIZE 128
#define STACKSIZE 0x1000
#define MAIN_STACKSIZE 0xe000
#define AUDIO_STACKSIZE 0x4000







#define _INC_SCENE 






#define _INC_CART 







#define _INC_HASH 

typedef void* HASHPOS;
typedef void* BASE_KEY;
typedef void* BASE_ARG_KEY;
typedef void* BASE_VALUE;
typedef void* BASE_ARG_VALUE;

struct CAssoc_t;
struct CHashPlex_t;

typedef struct CHashTable_t
{
 struct CAssoc_t **m_pHashTable;
 unsigned long m_nHashTableSize;
 int m_nCount;
 struct CAssoc_t *m_pFreeList;
 struct CHashPlex_t *m_pBlocks;
 int m_nBlockSize;
} CHashTable;




void func_8002E254(CHashTable *pThis, int nBlockSize );
void CHashTable__Destruct(CHashTable *pThis);

int CHashTable__GetCount(CHashTable *pThis);
int CHashTable__IsEmpty(CHashTable *pThis);
int func_8002E13C(CHashTable *pThis, void* key, void **prValue);


void func_8002E098(CHashTable *pThis, void* key, void* newValue);


int CHashTable__RemoveKey(CHashTable *pThis, void* key);
void CHashTable__RemoveAll(CHashTable *pThis);


HASHPOS CHashTable__GetStartPosition(CHashTable *pThis);
void CHashTable__GetNextAssoc(CHashTable *pThis, HASHPOS *prNextPosition, void **prKey, void **prValue);


unsigned long CHashTable__GetHashTableSize(CHashTable *pThis);
void func_8002DFA0(CHashTable *pThis, unsigned long hashSize, int bAllocNow );


#define CARTCACHE_CACHEENTRY_COUNT 512
#define CARTCACHE_NOTIFYENTRY_COUNT 16


#define CMPTYPE_FASTER 0
#define CMPTYPE_MIXED 1
#define CMPTYPE_BETTER 2




#define SWAP_U32(a) ( ((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned long)(a) >>24) )








#define ORDERBYTES(data) (data)


#define FixAlignment(Size,Alignment) ( ( (Size) + ((Alignment) - 1) ) & ~((DWORD) (Alignment) - 1) )

typedef ROMAddress;



#define SS_NHEADERS 1

#define SS_SIZE 0

#define SS_HEADER_SIZE (SS_NHEADERS*sizeof(DWORD))
#define SS_TOTAL_SIZE(Size) (US_HEADER_SIZE + Size)

typedef struct CStreamSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CStreamSet;




void CStreamSet__Construct(CStreamSet *pThis);
void CStreamSet__ConstructFromRawData(CStreamSet *pThis,
              void *pData, int AutoDeleteData );



#define CStreamSet__Destruct(pThis) 


void CStreamSet__AddBlock(CStreamSet *pThis, const void *pBlock, const unsigned long Size);
void CStreamSet__AddBlockBYTE(CStreamSet *pThis, unsigned char bData);
void CStreamSet__AddBlockWORD(CStreamSet *pThis, unsigned short wData);
void CStreamSet__AddBlockDWORD(CStreamSet *pThis, unsigned long dwData);

#define CStreamSet__GetBasePtr(pThis) ( (void*) ( ((BYTE*)((pThis)->m_pData)) + SS_HEADER_SIZE ) )
void* CStreamSet__GetBasePtrAndSize(CStreamSet *pThis, unsigned long *pSize);


void CStreamSet__GetRawData(CStreamSet *pThis, void **ppData, unsigned long *pSize);
void CStreamSet__AttatchRawData(CStreamSet *pThis, void *pData, int AutoDeleteData );



#define US_NHEADERS 2

#define US_BLOCKSIZE 0
#define US_BLOCKCOUNT 1

#define US_HEADER_SIZE (US_NHEADERS*sizeof(DWORD))
#define US_TOTAL_SIZE(BlockSize,BlockCount) (US_HEADER_SIZE + (BlockSize)*(BlockCount))

typedef struct CUnindexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
   unsigned long m_CurrentAllocSize;
} CUnindexedSet;

struct CIndexedSet_t;




void CUnindexedSet__Construct(CUnindexedSet *pThis);
void CUnindexedSet__ConstructWithSize(CUnindexedSet *pThis,
               int BlockSize, int BlockCount, int AutoDeleteData );
void func_8002DA8C(CUnindexedSet *pThis,
               void *pData, int AutoDeleteData );
void CUnindexedSet__ConstructWithAllocatedBlock(CUnindexedSet *pThis,
                  void *pData, int BlockSize, int BlockCount, int AutoDeleteData );



#define CUnindexedSet__Destruct(pThis) 


void CUnindexedSet__PreAllocate(CUnindexedSet *pThis, int BlockSize, int BlockCount);

int CUnindexedSet__AddBlock(CUnindexedSet *pThis, const void *pBlock, const unsigned long Size);
int CUnindexedSet__AddBlockBYTE(CUnindexedSet *pThis, unsigned char bData);
int CUnindexedSet__AddBlockWORD(CUnindexedSet *pThis, unsigned short wData);
int CUnindexedSet__AddBlockDWORD(CUnindexedSet *pThis, unsigned long dwData);
int CUnindexedSet__AddBlockFloat(CUnindexedSet *pThis, float fData);
int CUnindexedSet__AddBlockIS(CUnindexedSet *pThis, struct CIndexedSet_t *pisBlock);
int CUnindexedSet__AddBlockUS(CUnindexedSet *pThis, CUnindexedSet *pusBlock);
int CUnindexedSet__AddBlockSS(CUnindexedSet *pThis, CStreamSet *ssBlock);

#define CUnindexedSet__GetBasePtr(pThis) ( (void*) ( ((BYTE*)((pThis)->m_pData)) + US_HEADER_SIZE ) )
void* CUnindexedSet__GetBasePtrAndSize(CUnindexedSet *pThis, unsigned long *pSize);

#define CUnindexedSet__GetBlockSize(pThis) ( (DWORD) ORDERBYTES(((DWORD*) (pThis)->m_pData)[US_BLOCKSIZE]) )
#define CUnindexedSet__GetBlockCount(pThis) ( (DWORD) ORDERBYTES(((DWORD*) (pThis)->m_pData)[US_BLOCKCOUNT]) )
#define CUnindexedSet__GetBlock(pThis,nBlock) ( (void*) ( ((BYTE*) CUnindexedSet__GetBasePtr(pThis)) + (nBlock)*CUnindexedSet__GetBlockSize(pThis) ) )


void CUnindexedSet__GetRawData(CUnindexedSet *pThis, void **ppData, unsigned long *pSize);
void CUnindexedSet__AttatchRawData(CUnindexedSet *pThis, void *pData, int AutoDeleteData );






void func_8002D7AC(CUnindexedSet *pThis, void *pDest, int CopyBack);



#define IS_ALIGNMENT 8






#define IS_NHEADERS 1

#define IS_BLOCKCOUNT 0

#define IS_HEADER_SIZE (IS_NHEADERS*sizeof(DWORD))
#define IS_INDEX_SIZE(nBlocks) FixAlignment(IS_HEADER_SIZE + ((nBlocks)+1)*sizeof(DWORD), IS_ALIGNMENT)


typedef struct CIndexedSet_t
{
   void *m_pData;
   int m_AutoDeleteData;
} CIndexedSet;




void func_8002DD34(CIndexedSet *pThis);
void CIndexedSet__ConstructFromRawData(CIndexedSet *pThis, void *pData, int AutoDeleteData );



#define CIndexedSet__Destruct(pThis) 


int CIndexedSet__AddBlockDWORD(CIndexedSet *pThis, unsigned long dwData);
int CIndexedSet__AddBlockSS(CIndexedSet *pThis, CStreamSet *ssBlock);
int CIndexedSet__AddBlockUS(CIndexedSet *pThis, CUnindexedSet *pusBlock);
int CIndexedSet__AddBlockIS(CIndexedSet *pThis, CIndexedSet *pisBlock);
int CIndexedSet__AddBlock(CIndexedSet *pThis, const void *pBlock, unsigned long Size);
int CIndexedSet__AddBlocks(CIndexedSet *pThis, void *pBlocks[], unsigned long Sizes[], int nBlocks);
int CIndexedSet__AddCompressedBlockIS(CIndexedSet *pThis, CIndexedSet *pisBlock, unsigned long *pCompressedSize, int Better);
int CIndexedSet__AddCompressedBlockUS(CIndexedSet *pThis, CUnindexedSet *pusBlock, unsigned long *pCompressedSize, int Better);
int CIndexedSet__AddCompressedBlockSS(CIndexedSet *pThis, CStreamSet *pssBlock, unsigned long *pCompressedSize, int Better);
int CIndexedSet__CompressAndAddBlock(CIndexedSet *pThis, void *pData, unsigned long Length, unsigned long *pCompressedSize, int Better);

void* CIndexedSet__GetBlock(CIndexedSet *pThis, void *pBaseAddress, int nBlock);
void* CIndexedSet__GetAddressAndSize(CIndexedSet *pThis, void *pBaseAddress, int nBlock, unsigned long *pLength);

ROMAddress* func_8002DC24(CIndexedSet *pThis,
                                       ROMAddress *rpBaseAddress, int nBlock);
ROMAddress* CIndexedSet__GetROMAddressAndSize(CIndexedSet *pThis,
                                              ROMAddress *rpBaseAddress, int nBlock, unsigned long *pLength);

#define CIndexedSet__GetBlock(pThis,nBlock) CIndexedSet__GetBlock((pThis), (pThis)->m_pData, (nBlock))
#define CIndexedSet__GetBlockAndSize(pThis,nBlock,pLength) CIndexedSet__GetAddressAndSize((pThis), (pThis)->m_pData, (nBlock), (pLength))
#define CIndexedSet__GetBlockCount(pThis) ORDERBYTES(((DWORD*) (pThis)->m_pData)[IS_BLOCKCOUNT])


#define CIndexedSet__GetOffset(pThis,nBlock) ORDERBYTES( ((DWORD*) ((pThis)->m_pData))[IS_NHEADERS + (nBlock)] )



unsigned long func_8002DBD0(CIndexedSet *pThis, const int nBlock, unsigned long *pLength);

#define CIndexedSet__SetBlockCount(pThis,nBlocks) ((DWORD*) ((pThis)->m_pData))[IS_BLOCKCOUNT] = ORDERBYTES((DWORD) (nBlocks))
#define CIndexedSet__SetNextOffset(pThis,Offset) ((DWORD*) ((pThis)->m_pData))[IS_NHEADERS + CIndexedSet__GetBlockCount(pThis)] = ORDERBYTES((DWORD) (Offset))
#define CIndexedSet__GetNextOffset(pThis) ORDERBYTES( ((DWORD*) ((pThis)->m_pData))[IS_NHEADERS + CIndexedSet__GetBlockCount(pThis)] )


void func_8002DC80(CIndexedSet *pThis, void **ppData, unsigned long *pSize);
void CIndexedSet__AttatchRawData(CIndexedSet *pThis, void *pData, int AutoDeleteData );
void CIndexedSet__DetatchRawData(CIndexedSet *pThis, void **ppData, unsigned long *pSize);






#define CACHE_BLOCK_VERSION_MASK 0xc0000000
#define CACHE_BLOCK_VERSION(v) ((v) << 30)
#define CACHE_BLOCK_GETVERSION(addr) (((DWORD)(addr)) >> 30)


struct CCartCache_t;


typedef struct CCacheEntry_t
{
   void *m_pData;
 unsigned long m_DataLength;

   ROMAddress *m_rpAddress;
   unsigned long m_rLength;

 struct CCartCache_t *m_pOwner;


 unsigned long m_LastAccessed;
   int m_InHashTable,
      m_Compressed;

#define CACHEENTRY_ALLOCATED 489554
#define CACHEENTRY_UNALLOCATED 89355
 unsigned long m_Allocated;
   const char *m_szDescription;

   struct CCacheEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CCacheEntry;




#define CCacheEntry__ResetAge(pThis) func_8002D410((pThis)->m_pOwner, pThis)

void* CCacheEntry__GetData(CCacheEntry *pThis);

#define CCacheEntry__GetDataPtr(pThis) ((pThis)->m_pData)
#define CCacheEntry__GetRequestedAddress(pThis) ((pThis)->m_rpAddress)

#define CCacheEntry__AllocDataForReplacement(pThis,NewSize) func_8002D648(pThis, NewSize, FALSE)
#define CCacheEntry__AllocTempDataForReplacement(pThis,NewSize) func_8002D648(pThis, NewSize, TRUE)
void* func_8002D648(CCacheEntry *pThis, unsigned long NewSize, int AllocTop);
void func_8002D604(CCacheEntry *pThis, void *pNewData, unsigned long NewLength);
void func_8002CB0C(CCacheEntry *pThis);
void func_8002D784(void *pVoid, CCacheEntry **ppceTarget);
#define CCacheEntry__Decompress(pThis) CCacheEntry__DoDecompress(pThis, FALSE)
#define CCacheEntry__DecompressTemp(pThis) CCacheEntry__DoDecompress(pThis, TRUE)
int CCacheEntry__DoDecompress(CCacheEntry *pThis, int AllocTop);



typedef void (*pfnCACHENOTIFY)(void *pNotifyPtr, CCacheEntry **ppceTarget);


typedef struct CNotifyEntry_t
{
   void *m_pNotifyPtr;
   pfnCACHENOTIFY m_pfnDecompress,

                  m_pfnBlockReceived;

   CCacheEntry **m_ppceTarget;

   ROMAddress *m_rpRequestedAddress;
   unsigned long m_rLength;
   const char *m_szDescription;

   struct CNotifyEntry_t *m_pLast, *m_pNext,
         *m_pNextFree;
} CNotifyEntry;



typedef struct CCartCache_t
{
   CHashTable m_HashTable;
   CNotifyEntry *m_pNotifyHead, *m_pNotifyTail;
   CCacheEntry *m_pCacheHead, *m_pCacheTail;
   int m_DiscardAge;

 CCacheEntry m_CacheEntries[512];
 CCacheEntry *m_pCacheFreeHead;

 CNotifyEntry m_NotifyEntries[16];
 CNotifyEntry *m_pNotifyFreeHead;

} CCartCache;




void CCartCache__Construct(CCartCache *pThis);
void CCartCache__Destruct(CCartCache *pThis);
void CCartCache__RequestBlock(CCartCache *pThis,
            void *pNotifyPtr,
                        pfnCACHENOTIFY pfnDecompress,
                        pfnCACHENOTIFY pfnBlockReceived,
                        CCacheEntry **ppceTarget,
                        ROMAddress *rpRequestAddress, unsigned long rLength,
                        const char *szDescription );

int func_8002D3EC(CCartCache *pThis, ROMAddress *rpAddress);
#define CCartCache__SetDiscardAge(pThis,DiscardAge) (pThis)->m_DiscardAge = DiscardAge

void CCartCache__Empty(CCartCache *pThis);
int CCartCache__Compress(CCartCache *pThis);
void func_8002D410(CCartCache *pThis, CCacheEntry *pCacheEntry);
void func_8002D4A0(CCartCache *pThis);




void CMP_CompressData(int better, void *pData, unsigned long Length, unsigned char **ppOut, unsigned long *pLength);
void CMP_DeallocData(unsigned char *pData);
unsigned long func_8002CA14(void *pCompressedData);
int func_8002C9C0(void *pCompressedData, void *pOutputBuffer);





#define _INC_ROMMMODEL 





#define _INC_GRAPHU64 






struct CQuatern_t;




typedef struct CVector3_t
{
 float x, y, z;
} CVector3;




void func_800144FC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void func_800144C8(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013C2C(CVector3 *pvThis, CVector3 *pvIn, float Scaler);
void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
#define CVector3__Dot(pvLeft,pvRight) ((pvLeft)->x*(pvRight)->x + (pvLeft)->y*(pvRight)->y + (pvLeft)->z*(pvRight)->z)
#define CVector3__MagnitudeSquared(pvThis) ((pvThis)->x*(pvThis)->x + (pvThis)->y*(pvThis)->y + (pvThis)->z*(pvThis)->z)
#define CVector3__Magnitude(pvThis) sqrt(CVector3__MagnitudeSquared(pvThis))
#define CVector3__Set(pThis,X,Y,Z) (pThis)->x = X ; (pThis)->y = Y ; (pThis)->z = Z ;
void func_80013B2C(CVector3 *pvThis);
CVector3 func_800143F8(CVector3 *pvThis, float uRandom);
CVector3 func_8001434C(CVector3 *pvThis, float uRandom);
CVector3 func_800142A0(CVector3 *pvThis, float uRandom);
CVector3 func_800141F8(CVector3 *pvThis, float uRandom);
void func_80014124(CVector3 *pvThis, CVector3 *pvStart, CVector3 *pvEnd, float Y);
CVector3 func_80014074(CVector3 *pThis, CVector3 *pvSurfaceUnitNormal, float EnergyFactor);
CVector3 func_80013E64(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
CVector3 CVector3__ProjectCrease(CVector3 *pvThis, CVector3 *pvNormalA, CVector3 *pvNormalB);
CVector3 func_80013EF0(CVector3 *pvThis, CVector3 *pvSurfaceUnitNormal);
int CVector3__Clamp(CVector3 *pvThis, float MaxVal);
void CVector3__Print(CVector3 *pvThis);
#define CVector3__IsEqual(pvLeft,pvRight) (((pvLeft)->x == (pvRight)->x) && ((pvLeft)->y == (pvRight)->y) && ((pvLeft)->z == (pvRight)->z))
struct CQuatern_t func_80013C58(CVector3 *pvThis);

float func_80013A24(CVector3 *pThis) ;
float func_800139A8(CVector3 *pThis) ;
float func_80013944(CVector3 *pThis, CVector3 *pvPos) ;
float func_80013980(CVector3 *pThis, CVector3 *pvPos) ;





typedef float CMtxF[4][4];

typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;





#define CMtxF__ToMtx(mfThis,mFixed) func_80012290((mfThis), &(mFixed))
#define CMtxF__FromMtx(mfThis,mFixed) guMtxL2F((mfThis), &(mFixed))
void func_800155D4(CMtxF mfThis);
void func_80015910(CMtxF mfThis, CMtxF mfLeft, CMtxF mfRight);
void func_80015800(CMtxF mfThis) ;
void func_80015754(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void func_80015624(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void CMtxF__Translate(CMtxF mfThis, float X, float Y, float Z);
void CMtxF__Scale(CMtxF mfThis, float X, float Y, float Z);
void CMtxF__Rotate(CMtxF mfThis, float Theta, float X, float Y, float Z);
void CMtxF__Print(CMtxF mfThis);
void func_80014F28(CMtxF mfThis, CMtxF mfSource);
void func_80014FAC(CMtxF mfThis, CMtxF mfIn);




void func_80013224(CMtxF mfThis, CMtxF mfLeft, CMtxF mfRight) ;

void CMtxF__PreMultTranslate(CMtxF mfThis, float Tx, float Ty, float Tz) ;
void CMtxF__PostMultTranslate(CMtxF mfThis, float Tx, float Ty, float Tz) ;

void CMtxF__PreMultScale(CMtxF mfThis, float Sx, float Sy, float Sz) ;
void CMtxF__CopyPreMultScale(CMtxF mfThis, CMtxF mfSource, float Sx, float Sy, float Sz) ;

void CMtxF__PostMultScale(CMtxF mfThis, float Sx, float Sy, float Sz) ;

void func_80012EFC(CMtxF mfThis, float Theta) ;
void func_80012E6C(CMtxF mfThis, float Theta) ;
void func_80012DE0(CMtxF mfThis, float Theta) ;

void func_80012D28(CMtxF mfThis, float RotX) ;
void func_80012C48(CMtxF mfThis, float RotX) ;

void func_80012B90(CMtxF mfThis, float RotY) ;
void func_80012AB0(CMtxF mfThis, float RotY) ;

void func_800129F8(CMtxF mfThis, float RotZ) ;
void func_80012918(CMtxF mfThis, float RotZ) ;

void func_800128E4(CMtxF mfThis) ;
void func_80012864(CMtxF mfThis, CMtxF mfSource) ;

void func_80012820(CMtxF mfThis) ;
void func_800127A0(CMtxF mfThis, CMtxF mfSource) ;


void func_80012290(CMtxF mfThis, Mtx *m) ;
void func_80012504(CMtxF mfThis, Mtx *m, float Tx, float Ty, float Tz) ;





#define BlendFLOAT(u,A,B) ((A) + (u)*(((float)(B)) - (A)))

#define GetCosineBlender(u) ((cos((1.0-(u))*ANGLE_PI) + 1.0)/2.0)
#define GetHermiteBlender(r1,r2,u) ( (-2.0 + ((float)r2) + ((float)r1))*((float)u)*((float)u)*((float)u) + (3.0 - ((float)r2) - 2.0*((float)r1))*((float)u)*((float)u) + ((float)r1)*((float)u) )

#define BlendFLOATCosine(u,A,B) (BlendFLOAT(GetCosineBlender(u), A, B))

float func_800136C8(float u, float A, float B);
float func_80013620(float A, float B);
void func_80013588(float *pTheta);
void NormalizeBigRotation(float *pTheta);




#define CQuatern__BuildFromAxisAngle(pqThis,X,Y,Z,Theta) sin_angle = sin((Theta)/2); (pqThis)->x = (X)*sin_angle; (pqThis)->y = (Y)*sin_angle; (pqThis)->z = (Z)*sin_angle; (pqThis)->t = cos((Theta)/2);





#define CQuatern__Identity(pqThis) { (pqThis)->x = (pqThis)->y = (pqThis)->z = 0; (pqThis)->t = 1; }

#define CQuatern__Add(pqThis,pqLeft,pqRight) (pqThis)->x = (pqLeft)->x + (pqRight)->x; (pqThis)->y = (pqLeft)->y + (pqRight)->y; (pqThis)->z = (pqLeft)->z + (pqRight)->z; (pqThis)->t = (pqLeft)->t + (pqRight)->t;




#define CQuatern__MultScaler(pqThis,pqIn,Scaler) (pqThis)->x = (pqIn)->x * Scaler; (pqThis)->y = (pqIn)->y * Scaler; (pqThis)->z = (pqIn)->z * Scaler; (pqThis)->t = (pqIn)->t * Scaler;




void func_80014CB8(CQuatern *pqThis, const CQuatern *pqLeft, const CQuatern *pqRight);
#define CQuatern__Dot(pqLeft,pqRight) ((pqLeft)->x*(pqRight)->x + (pqLeft)->y*(pqRight)->y + (pqLeft)->z*(pqRight)->z + (pqLeft)->t*(pqRight)->t)

#define CQuatern__MagnitudeSquared(pqThis) ((pqThis)->x*(pqThis)->x + (pqThis)->y*(pqThis)->y + (pqThis)->z*(pqThis)->z + (pqThis)->t*(pqThis)->t)

#define CQuatern__Magnitude(pqThis) sqrt(CQuatern__MagnitudeSquared(pqThis))
void func_80014538(CQuatern *pqThis);
#define CQuatern__Inverse(pqThis,pqIn) ASSERT(CQuatern__MagnitudeSquared(pqIn) != 0); inv_mag_squared = (-1.0)/CQuatern__MagnitudeSquared(pqIn); (pqThis)->x = (pqIn)->x * inv_mag_squared; (pqThis)->y = (pqIn)->y * inv_mag_squared; (pqThis)->z = (pqIn)->z * inv_mag_squared; (pqThis)->t = (pqIn)->t * -inv_mag_squared;






#define CQuatern__Negate(pqThis) (pqThis)->x = -((pqThis)->x); (pqThis)->y = -((pqThis)->y); (pqThis)->z = -((pqThis)->z); (pqThis)->t = -((pqThis)->t);




void func_80014DC4(CQuatern *pqThis, CMtxF mfRotate);
void func_80014C50(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void func_80014A04(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void CQuatern__BlendThreshold(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void func_800148B8(CQuatern *pqThis, CQuatern *pqTarget);
void CQuatern__Print(CQuatern *pqThis);




extern float sin_angle,
     inv_mag_squared;

extern unsigned long random_value;
extern unsigned long sound_random_value;


void func_80013928();
int RandomSwapWord();
int SoundRandomSwapWord() ;
float func_80013840(float Max);
float func_8001349C(float x);




typedef struct CROMFacet_t
{
   unsigned long m_Vertices[3];
} CROMFacet;





#define _INC_ROMSTRUC 







#define _INC_ANIM 

typedef struct CGameAnimateState_t
{
 CCacheEntry *m_pceAnim;
 unsigned long m_nAnim,
      m_nDesiredAnim,
      m_nFrames;
 float m_cFrame;
 int m_CycleCompleted;
} CGameAnimateState;




void func_800376A4(CGameAnimateState *pThis);
#define CGameAnimateState__SetDesiredAnim(pThis,nAnim) (pThis)->m_nDesiredAnim = nAnim
int func_80037564(CGameAnimateState *pThis);
int func_800374D8(CGameAnimateState *pThis);
void func_80037394(CGameAnimateState *pThis);
#define CGameAnimateState__IsCycleCompleted(pThis) ((pThis)->m_CycleCompleted)



typedef struct CROMTransition_t
{
 unsigned short m_BlendFromLength,
    m_nExitToFrame,
    m_BlendStart,
    m_BlendFinish;
} CROMTransition;

typedef struct CROMTransitionEntry_t
{
 unsigned long m_nRequestedAnim,
    m_nWaitForFrame,
    m_nDeliveredAnim;
} CROMTransitionEntry;

typedef struct CROMEventEntry_t
{
   unsigned short m_nFrame,
      m_nEvent;

 float m_Value;
 CVector3 m_vOffset;

} CROMEventEntry;






#define _INC_GEOMETRY 







extern unsigned long current_combine_mode ;
extern unsigned long current_render_mode ;


extern int draw_transparent_geometry ;
extern int draw_intersect_geometry ;




typedef struct CGeometry_t
{
 CCacheEntry *m_pceGeometry,
         *m_pceTextureSetsIndex;
} CGeometry;




#define CGeometry__GetCacheEntry(pThis) ((pThis)->m_pceGeometry)
void CGeometry__RequestBlock(CGeometry *pThis, CCartCache *pCache,
                ROMAddress *rpGeometryAddress, unsigned long GeometrySize,
             CCacheEntry *pceTextureSetsIndex);
void CGeometry__DrawPart(CGeometry *pThis, Gfx **ppDLP, CCartCache *pCache,
           int nNode, int nPart,
           int Inter, int Better, int nFrame);
void CGeometry__DrawShadow(Gfx **ppDLP, Mtx *pmShadow, int Decal, unsigned char Alpha);
#define CGeometry__IsModelLoaded(pThis) ((pThis)->m_pceGeometry != NULL)
void CGeometry__Morph(CGeometry *pThis, int nNode, float Frame);
void func_800220BC(CGeometry *pThis, int nNode, float Increment);





#define FXMODE_NONE 0
#define G_CC_FXMODE_NONE 0, 0, 0, COMBINED, 0, 0, 0, COMBINED



#define FXMODE_TOTRANSPARENT 1
#define FXMODE_TOTRANSPARENT_NOISE 2
#define G_CC_FXMODE_TOTRANSPARENT 0, 0, 0, COMBINED, COMBINED, 0, ENVIRONMENT, 0



#define FXMODE_TOCOLOR 3
#define G_CC_FXMODE_TOCOLOR ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, 0, 0, 0, COMBINED



#define FXMODE_FROMCOLOR_TOTRANSPARENT 4
#define FXMODE_FROMCOLOR_TOTRANSPARENT_NOISE 5
#define G_CC_FXMODE_FROMCOLOR_TOTRANSPARENT 0, 0, 0, ENVIRONMENT, COMBINED, 0, ENVIRONMENT, 0



#define FXMODE_TOCOLORANDTRANSPARENT 6
#define G_CC_FXMODE_TOCOLORANDTRANSPARENT ENVIRONMENT, COMBINED, ENV_ALPHA, COMBINED, COMBINED, 0, PRIMITIVE, 0



#define FXMODE_GLARE 7
#define G_CC_FXMODE_GLARE ENVIRONMENT, COMBINED, SHADE, COMBINED, 0, 0, 0, COMBINED



extern unsigned long fx_mode;
extern float fx_color[5];



#define RM_AA_ZB_XLU_SURF_ZUPD(clk) AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_WRAP | CLR_ON_CVG | FORCE_BL | ZMODE_OPA | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)




#define RM_ROB_ZB_PCL_SURF_BLEND(clk) Z_CMP | IM_RD | CVG_DST_SAVE | FORCE_BL | ZMODE_XLU | G_AC_DITHER | GBL_c##clk(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA)







#define G_CC_16RGBA_4A TEXEL0, 0, ENVIRONMENT, 0, TEXEL1, 0, ENVIRONMENT, 0




#define G_CC_MULTIBIT_ALPHA ENVIRONMENT, PRIMITIVE, TEXEL1, PRIMITIVE, TEXEL0, 0, ENVIRONMENT, 0



#define G_CC_ROB_PSEUDOCOLOR_SHADEALPHA ENVIRONMENT, SHADE, TEXEL0, SHADE, SHADE, 0, TEXEL0, 0





#define G_CC_ROB_SELFILLUM_PSEUDO PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0



#define G_CC_ROB_SELFILLUM_PSEUDO_SHADEALPHA PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, SHADE, 0, TEXEL0, 0



#define G_CC_ROB_LIGHTED2 COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED



#define G_CC_ROB_SELFILLUM_TEXTURE 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0



#define G_CC_ROB_LIGHTED_TEXTURE TEXEL0, 0, SHADE, 0, TEXEL0, 0, PRIMITIVE, 0



#define G_CC_ROB_SELFILLUM_SOLID 0, 0, 0, PRIMITIVE, 0, 0, 0, PRIMITIVE



#define G_CC_ROB_LIGHTED_SOLID PRIMITIVE, 0, SHADE, 0, 0, 0, 0, PRIMITIVE



#define G_CC_ROB_QUACK_PRIM 0, 0, 0, PRIMITIVE, 0, 0, 0, 1



#define G_CC_ROB_QUACK_PRIM 0, 0, 0, PRIMITIVE, 0, 0, 0, 1



#define G_CC_ROB_QUACK_ENV 0, 0, 0, ENVIRONMENT, 0, 0, 0, 1





#define G_CC_ROB_SELFILLUM_PSEUDO_SHADEALPHA__G_CC_PASS2 0
#define G_CC_ROB_SELFILLUM_PSEUDO_SHADEALPHA__G_CC_FXMODE_TOTRANSPARENT 1
#define G_CC_ROB_SELFILLUM_PSEUDO__G_CC_PASS2 2
#define G_CC_ROB_SELFILLUM_PSEUDO_SHADEALPHA__G_CC_ROB_LIGHTED2 3
#define G_CC_ROB_SELFILLUM_PSEUDO__G_CC_ROB_LIGHTED2 4
#define G_CC_TRILERP__G_CC_DECALRGB2 5
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_PASS2 6
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_FXMODE_TOTRANSPARENT 7
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_FXMODE_TOCOLOR 8
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_FXMODE_GLARE 9
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_FXMODE_FROMCOLOR_TOTRANSPARENT 10
#define G_CC_ROB_SELFILLUM_TEXTURE__G_CC_FXMODE_TOCOLORANDTRANSPARENT 11
#define G_CC_TRILERP__G_CC_MODULATERGB2 12
#define G_CC_ROB_LIGHTED_TEXTURE__G_CC_FXMODE_NONE 13
#define G_CC_ROB_LIGHTED_TEXTURE__G_CC_FXMODE_TOTRANSPARENT 14
#define G_CC_ROB_LIGHTED_TEXTURE__G_CC_FXMODE_TOCOLOR 15
#define G_CC_ROB_LIGHTED_TEXTURE__G_CC_FXMODE_FROMCOLOR_TOTRANSPARENT 16
#define G_CC_ROB_LIGHTED_TEXTURE__G_CC_FXMODE_TOCOLORANDTRANSPARENT 17
#define G_CC_ROB_SELFILLUM_SOLID__G_CC_PASS2 18
#define G_CC_ROB_LIGHTED_SOLID__G_CC_FXMODE_NONE 19
#define G_CC_ROB_LIGHTED_SOLID__G_CC_FXMODE_TOTRANSPARENT 20
#define G_CC_ROB_LIGHTED_SOLID__G_CC_FXMODE_TOCOLOR 21
#define G_CC_ROB_SELFILLUM_SOLID__G_CC_FXMODE_GLARE 22
#define G_CC_ROB_LIGHTED_SOLID__G_CC_FXMODE_FROMCOLOR_TOTRANSPARENT 23


#define G_CC_ROB_DECALRGBA_PRIMALPHA__G_CC_ROB_DECALRGBA_PRIMALPHA 24
#define G_CC_PRIMITIVE__G_CC_PRIMITIVE 25
#define G_CC_MULTIBIT_ALPHA__G_CC_PASS2 26
#define G_CC_16RGBA_4A__G_CC_PASS2 27

#define G_CC_SHADE__G_CC_SHADE 28

#define G_CC_ROB_PSEUDOCOLOR_PRIMALPHA__G_CC_ROB_PSEUDOCOLOR_PRIMALPHA 29
#define G_CC_ROB_QUACK_PRIM__G_CC_ROB_QUACK_PRIM 30
#define G_CC_ROB_QUACK_ENV__G_CC_ROB_QUACK_ENV 31

#define G_CC_ROB_PSEUDOCOLOR_SHADEALPHA__G_CC_ROB_PSEUDOCOLOR_SHADEALPHA 32
#define G_CC_MODULATERGB__G_CC_MODULATERGB 33

#define G_CC_ROB_BLACK_PRIMALPHA__G_CC_PASS2 34




#define G_RM_PASS__G_RM_AA_ZB_XLU_SURF2 0
#define G_RM_FOG_SHADE_A__G_RM_AA_ZB_XLU_SURF2 1
#define G_RM_PASS__G_RM_ZB_XLU_SURF2 2
#define G_RM_PASS__G_RM_ZB_CLD_SURF2 3
#define G_RM_FOG_SHADE_A__G_RM_AA_ZB_XLU_DECAL2 4
#define G_RM_FOG_SHADE_A__RM_AA_ZB_XLU_SURF_ZUPD 5
#define G_RM_FOG_SHADE_A__G_RM_AA_ZB_TEX_EDGE2 6
#define G_RM_FOG_SHADE_A__G_RM_ZB_OPA_DECAL2 7
#define G_RM_FOG_SHADE_A__G_RM_AA_ZB_OPA_INTER2 8
#define G_RM_FOG_SHADE_A__G_RM_RA_ZB_OPA_INTER2 9
#define G_RM_FOG_SHADE_A__G_RM_AA_ZB_OPA_SURF2 10
#define G_RM_FOG_SHADE_A__G_RM_RA_ZB_OPA_SURF2 11

#define G_RM_AA_ZB_XLU_INTER__G_RM_AA_ZB_XLU_INTER2 12
#define G_RM_ZB_CLD_SURF__G_RM_ZB_CLD_SURF2 13

#define G_RM_AA_ZB_XLU_SURF__G_RM_AA_ZB_XLU_SURF2 14

#define G_RM_ZB_XLU_DECAL__G_RM_ZB_XLU_DECAL2 15
#define RM_ROB_ZB_PCL_SURF_BLEND1__RM_ROB_ZB_PCL_SURF_BLEND2 16
#define G_RM_AA_ZB_TEX_EDGE__G_RM_AA_ZB_TEX_EDGE2 17
#define G_RM_AA_TEX_EDGE__G_RM_AA_TEX_EDGE2 18
#define G_RM_CLD_SURF__G_RM_CLD_SURF2 19

#define G_RM_NOOP__G_RM_NOOP2 20
#define G_RM_XLU_SURF__G_RM_XLU_SURF2 21
#define G_RM_VISCVG__G_RM_VISCVG2 22

#define G_RM_FOG_SHADE_A__G_RM_ZB_CLD_SURF2 23
#define G_RM_FOG_SHADE_A__G_RM_ZB_XLU_DECAL2 24

#define G_RM_PASS__G_RM_XLU_SURF2 25
#define G_RM_PASS__G_RM_CLD_SURF2 26

void CGeometry__ResetDrawModes(void) ;
void CGeometry__SetCombineMode(Gfx **ppDLP, unsigned long mode) ;
int CGeometry__SetRenderMode(Gfx **ppDLP, unsigned long mode) ;



#define _REGION_H_ 

#define ALIGNSZ (sizeof(long long))
#define ALIGNOFFST (ALIGNSZ-1)


#define BUF_CTRL_SIZE ALIGNSZ


#define MAX_BUFCOUNT 0x8000

#define BUF_FREE_WO_NEXT 0x8000




#define OS_RG_ALIGN_2B 2
#define OS_RG_ALIGN_4B 4
#define OS_RG_ALIGN_8B 8
#define OS_RG_ALIGN_16B 16

#define OS_RG_ALIGN_DEFAULT OS_RG_ALIGN_8B

#define ALIGN(s,align) (((u32)(s) + (align-1)) & ~(align-1))

typedef struct _Region_s {
 u8 *r_startBufferAddress;
 u8 *r_endAddress;
 s32 r_bufferSize;
 s32 r_bufferCount;

 u16 r_freeList;

 u16 r_alignSize;
} OSRegion;




#define RP(x) rp->r_##x







extern void *osCreateRegion(void *, u32, u32, u32);
extern void *osMalloc(void *);
extern void osFree(void *, void *);
extern s32 osGetRegionBufCount(void *);
extern s32 osGetRegionBufSize(void *);





#define _INC_PARTTYPE 




#define PARTICLE_TYPE_NONE 0
#define PARTICLE_TYPE_ARROW 1
#define PARTICLE_TYPE_BULLET 2
#define PARTICLE_TYPE_SHOTGUN 3
#define PARTICLE_TYPE_GRENADE 4
#define PARTICLE_TYPE_PLASMA1 5
#define PARTICLE_TYPE_PLASMA2 6
#define PARTICLE_TYPE_BULLET_SHELL 7
#define PARTICLE_TYPE_SHOTGUN_SHELL 8
#define PARTICLE_TYPE_BLOOD 9
#define PARTICLE_TYPE_WOODCHIP 10
#define PARTICLE_TYPE_FOLIAGE 11
#define PARTICLE_TYPE_EXPLOSION 12
#define PARTICLE_TYPE_SPARK 13
#define PARTICLE_TYPE_WATERSPLASH 14
#define PARTICLE_TYPE_TEST 15
#define PARTICLE_TYPE_ACIDSPIT 16
#define PARTICLE_TYPE_BREATH 17
#define PARTICLE_TYPE_DEATHRAIN 18
#define PARTICLE_TYPE_ENERGYBLAST 19
#define PARTICLE_TYPE_EYEFIRE 20
#define PARTICLE_TYPE_FIREBALL 21
#define PARTICLE_TYPE_SHOCKWAVE 22
#define PARTICLE_TYPE_SPELLCAST 23
#define PARTICLE_TYPE_SARROWFLASH 24
#define PARTICLE_TYPE_SARROWFIZZLE 25
#define PARTICLE_TYPE_ENEMY_BULLET 26
#define PARTICLE_TYPE_ENEMY_PLASMA1 27
#define PARTICLE_TYPE_DUSTCLOUD_FOOTFALL 28
#define PARTICLE_TYPE_DUSTCLOUD_BODYFALL 29
#define PARTICLE_TYPE_WEFFECT_ASSAULTRIFLE 30
#define PARTICLE_TYPE_WEFFECT_AUTOMATICSHOTGUN 31
#define PARTICLE_TYPE_WEFFECT_GRENADELAUNCHER 32
#define PARTICLE_TYPE_WEFFECT_KNIFEFORWARD 33
#define PARTICLE_TYPE_WEFFECT_KNIFELEFT 34
#define PARTICLE_TYPE_WEFFECT_KNIFERIGHT 35
#define PARTICLE_TYPE_WEFFECT_MACHINEGUN 36
#define PARTICLE_TYPE_WEFFECT_MINIGUN 37
#define PARTICLE_TYPE_WEFFECT_PISTOL 38
#define PARTICLE_TYPE_WEFFECT_RIOTSHOTGUN 39
#define PARTICLE_TYPE_WEFFECT_TECHWEAPON1 40
#define PARTICLE_TYPE_WEFFECT_TECHWEAPON2 41
#define PARTICLE_TYPE_ENEMY_MUZZLEFLASH 42
#define PARTICLE_TYPE_HULK_BLASTER 43
#define PARTICLE_TYPE_RAPTOR_PROJECTILE 44
#define PARTICLE_TYPE_PLASMA_EXPLOSION 45
#define PARTICLE_TYPE_FIREBALL_EXPLOSION 46
#define PARTICLE_TYPE_TECH_EXPLOSION 47
#define PARTICLE_TYPE_GREENBLOOD 48
#define PARTICLE_TYPE_ROBOT_BULLET 49
#define PARTICLE_TYPE_ROBOT_ROCKET 50
#define PARTICLE_TYPE_SPURT_BLOOD 51
#define PARTICLE_TYPE_GUSH_BLOOD 52
#define PARTICLE_TYPE_FOUNTAIN_BLOOD 53
#define PARTICLE_TYPE_DROOL 54
#define PARTICLE_TYPE_ARTERIAL_BLOOD 55
#define PARTICLE_TYPE_SPURT_GREENBLOOD 56
#define PARTICLE_TYPE_GUSH_GREENBLOOD 57
#define PARTICLE_TYPE_FOUNTAIN_GREENBLOOD 58
#define PARTICLE_TYPE_ARTERIAL_GREENBLOOD 59
#define PARTICLE_TYPE_KNIFELEFT_BLOOD 60
#define PARTICLE_TYPE_KNIFELEFT_GBLOOD 61
#define PARTICLE_TYPE_KNIFELEFT_SPARK 62
#define PARTICLE_TYPE_KNIFERIGHT_BLOOD 63
#define PARTICLE_TYPE_KNIFERIGHT_GBLOOD 64
#define PARTICLE_TYPE_KNIFERIGHT_SPARK 65
#define PARTICLE_TYPE_KNIFEFORWARD_BLOOD 66
#define PARTICLE_TYPE_KNIFEFORWARD_GBLOOD 67
#define PARTICLE_TYPE_KNIFEFORWARD_SPARK 68
#define PARTICLE_TYPE_TOMAHAWKLEFT_BLOOD 69
#define PARTICLE_TYPE_TOMAHAWKLEFT_GBLOOD 70
#define PARTICLE_TYPE_TOMAHAWKLEFT_SPARK 71
#define PARTICLE_TYPE_TOMAHAWKRIGHT_BLOOD 72
#define PARTICLE_TYPE_TOMAHAWKRIGHT_GBLOOD 73
#define PARTICLE_TYPE_TOMAHAWKRIGHT_SPARK 74
#define PARTICLE_TYPE_TOMAHAWKFORWARD_BLOOD 75
#define PARTICLE_TYPE_TOMAHAWKFORWARD_GBLOOD 76
#define PARTICLE_TYPE_TOMAHAWKFORWARD_SPARK 77
#define PARTICLE_TYPE_KTFATAL_BLOOD 78
#define PARTICLE_TYPE_KTFATAL_GBLOOD 79
#define PARTICLE_TYPE_KTFATAL_SPARK 80
#define PARTICLE_TYPE_ENEMY_PLASMA2 81
#define PARTICLE_TYPE_WATER_DROP 82
#define PARTICLE_TYPE_WATER_FOAM 83
#define PARTICLE_TYPE_WATER_STEAM 84
#define PARTICLE_TYPE_AUTOSHOTGUN 85
#define PARTICLE_TYPE_GENERIC1 86
#define PARTICLE_TYPE_GENERIC2 87
#define PARTICLE_TYPE_GENERIC3 88
#define PARTICLE_TYPE_GENERIC4 89
#define PARTICLE_TYPE_GENERIC5 90
#define PARTICLE_TYPE_GENERIC6 91
#define PARTICLE_TYPE_GENERIC7 92
#define PARTICLE_TYPE_GENERIC8 93
#define PARTICLE_TYPE_GENERIC9 94
#define PARTICLE_TYPE_GENERIC10 95
#define PARTICLE_TYPE_GENERIC11 96
#define PARTICLE_TYPE_GENERIC12 97
#define PARTICLE_TYPE_GENERIC13 98
#define PARTICLE_TYPE_GENERIC14 99
#define PARTICLE_TYPE_GENERIC15 100
#define PARTICLE_TYPE_GENERIC16 101
#define PARTICLE_TYPE_GENERIC17 102
#define PARTICLE_TYPE_GENERIC18 103
#define PARTICLE_TYPE_GENERIC19 104
#define PARTICLE_TYPE_GENERIC20 105
#define PARTICLE_TYPE_GENERIC21 106
#define PARTICLE_TYPE_GENERIC22 107
#define PARTICLE_TYPE_GENERIC23 108
#define PARTICLE_TYPE_GENERIC24 109
#define PARTICLE_TYPE_GENERIC25 110
#define PARTICLE_TYPE_GENERIC26 111
#define PARTICLE_TYPE_GENERIC27 112
#define PARTICLE_TYPE_GENERIC28 113
#define PARTICLE_TYPE_GENERIC29 114
#define PARTICLE_TYPE_GENERIC30 115
#define PARTICLE_TYPE_ROCKET 116
#define PARTICLE_TYPE_SHOCKWAVEPULSE1 117
#define PARTICLE_TYPE_WEFFECT_ROCKET 118
#define PARTICLE_TYPE_WEFFECT_SHOCKWAVEPULSE 119
#define PARTICLE_TYPE_LHGUN_PULSE 120
#define PARTICLE_TYPE_WATER_BUBBLE 121
#define PARTICLE_TYPE_WATER_RIPPLE 122
#define PARTICLE_TYPE_WATER_SPLASH 123
#define PARTICLE_TYPE_GENERIC31 124
#define PARTICLE_TYPE_GENERIC32 125
#define PARTICLE_TYPE_GENERIC33 126
#define PARTICLE_TYPE_GENERIC34 127
#define PARTICLE_TYPE_GENERIC35 128
#define PARTICLE_TYPE_GENERIC36 129
#define PARTICLE_TYPE_GENERIC37 130
#define PARTICLE_TYPE_GENERIC38 131
#define PARTICLE_TYPE_GENERIC39 132
#define PARTICLE_TYPE_GENERIC40 133
#define PARTICLE_TYPE_GENERIC41 134
#define PARTICLE_TYPE_GENERIC42 135
#define PARTICLE_TYPE_GENERIC43 136
#define PARTICLE_TYPE_GENERIC44 137
#define PARTICLE_TYPE_GENERIC45 138
#define PARTICLE_TYPE_GENERIC46 139
#define PARTICLE_TYPE_GENERIC47 140
#define PARTICLE_TYPE_GENERIC48 141
#define PARTICLE_TYPE_GENERIC49 142
#define PARTICLE_TYPE_GENERIC50 143
#define PARTICLE_TYPE_GENERIC51 144
#define PARTICLE_TYPE_GENERIC52 145
#define PARTICLE_TYPE_GENERIC53 146
#define PARTICLE_TYPE_GENERIC54 147
#define PARTICLE_TYPE_GENERIC55 148
#define PARTICLE_TYPE_GENERIC56 149
#define PARTICLE_TYPE_GENERIC57 150
#define PARTICLE_TYPE_GENERIC58 151
#define PARTICLE_TYPE_GENERIC59 152
#define PARTICLE_TYPE_GENERIC60 153
#define PARTICLE_TYPE_GENERIC61 154
#define PARTICLE_TYPE_GENERIC62 155
#define PARTICLE_TYPE_GENERIC63 156
#define PARTICLE_TYPE_GENERIC64 157
#define PARTICLE_TYPE_GENERIC65 158
#define PARTICLE_TYPE_GENERIC66 159
#define PARTICLE_TYPE_GENERIC67 160
#define PARTICLE_TYPE_GENERIC68 161
#define PARTICLE_TYPE_GENERIC69 162
#define PARTICLE_TYPE_GENERIC70 163
#define PARTICLE_TYPE_GENERIC71 164
#define PARTICLE_TYPE_GENERIC72 165
#define PARTICLE_TYPE_GENERIC73 166
#define PARTICLE_TYPE_GENERIC74 167
#define PARTICLE_TYPE_GENERIC75 168
#define PARTICLE_TYPE_GENERIC76 169
#define PARTICLE_TYPE_GENERIC77 170
#define PARTICLE_TYPE_GENERIC78 171
#define PARTICLE_TYPE_GENERIC79 172
#define PARTICLE_TYPE_GENERIC80 173
#define PARTICLE_TYPE_GENERIC81 174
#define PARTICLE_TYPE_GENERIC82 175
#define PARTICLE_TYPE_GENERIC83 176
#define PARTICLE_TYPE_GENERIC84 177
#define PARTICLE_TYPE_GENERIC85 178
#define PARTICLE_TYPE_GENERIC86 179
#define PARTICLE_TYPE_GENERIC87 180
#define PARTICLE_TYPE_GENERIC88 181
#define PARTICLE_TYPE_GENERIC89 182
#define PARTICLE_TYPE_GENERIC90 183
#define PARTICLE_TYPE_GENERIC91 184
#define PARTICLE_TYPE_GENERIC92 185
#define PARTICLE_TYPE_GENERIC93 186
#define PARTICLE_TYPE_GENERIC94 187
#define PARTICLE_TYPE_GENERIC95 188
#define PARTICLE_TYPE_GENERIC96 189
#define PARTICLE_TYPE_GENERIC97 190
#define PARTICLE_TYPE_GENERIC98 191
#define PARTICLE_TYPE_GENERIC99 192
#define PARTICLE_TYPE_GENERIC100 193
#define PARTICLE_TYPE_ARROWEXPLOSIVE 194
#define PARTICLE_TYPE_SHOTGUNEXPLOSIVE 195
#define PARTICLE_TYPE_SHOTGUN_EXPLOSIVE_SHELL 196
#define PARTICLE_TYPE_SHOCKWAVE_CHARGE 197
#define PARTICLE_TYPE_SHOCKWAVEPULSE2 198
#define PARTICLE_TYPE_SHOCKWAVEPULSE3 199
#define PARTICLE_TYPE_SHOCKWAVEPULSE4 200
#define PARTICLE_TYPE_SHOCKWAVEPULSE5 201
#define PARTICLE_TYPE_GENERIC101 202
#define PARTICLE_TYPE_GENERIC102 203
#define PARTICLE_TYPE_GENERIC103 204
#define PARTICLE_TYPE_GENERIC104 205
#define PARTICLE_TYPE_GENERIC105 206
#define PARTICLE_TYPE_GENERIC106 207
#define PARTICLE_TYPE_GENERIC107 208
#define PARTICLE_TYPE_GENERIC108 209
#define PARTICLE_TYPE_GENERIC109 210
#define PARTICLE_TYPE_GENERIC110 211
#define PARTICLE_TYPE_GENERIC111 212
#define PARTICLE_TYPE_GENERIC112 213
#define PARTICLE_TYPE_GENERIC113 214
#define PARTICLE_TYPE_GENERIC114 215
#define PARTICLE_TYPE_GENERIC115 216
#define PARTICLE_TYPE_GENERIC116 217
#define PARTICLE_TYPE_GENERIC117 218
#define PARTICLE_TYPE_GENERIC118 219
#define PARTICLE_TYPE_GENERIC119 220
#define PARTICLE_TYPE_GENERIC120 221
#define PARTICLE_TYPE_GENERIC121 222
#define PARTICLE_TYPE_GENERIC122 223
#define PARTICLE_TYPE_GENERIC123 224
#define PARTICLE_TYPE_GENERIC124 225
#define PARTICLE_TYPE_GENERIC125 226
#define PARTICLE_TYPE_GENERIC126 227
#define PARTICLE_TYPE_GENERIC127 228
#define PARTICLE_TYPE_GENERIC128 229
#define PARTICLE_TYPE_GENERIC129 230
#define PARTICLE_TYPE_GENERIC130 231
#define PARTICLE_TYPE_GENERIC131 232
#define PARTICLE_TYPE_GENERIC132 233
#define PARTICLE_TYPE_GENERIC133 234
#define PARTICLE_TYPE_GENERIC134 235
#define PARTICLE_TYPE_GENERIC135 236
#define PARTICLE_TYPE_GENERIC136 237
#define PARTICLE_TYPE_GENERIC137 238
#define PARTICLE_TYPE_GENERIC138 239
#define PARTICLE_TYPE_GENERIC139 240
#define PARTICLE_TYPE_GENERIC140 241
#define PARTICLE_TYPE_GENERIC141 242
#define PARTICLE_TYPE_GENERIC142 243
#define PARTICLE_TYPE_GENERIC143 244
#define PARTICLE_TYPE_GENERIC144 245
#define PARTICLE_TYPE_GENERIC145 246
#define PARTICLE_TYPE_GENERIC146 247
#define PARTICLE_TYPE_GENERIC147 248
#define PARTICLE_TYPE_GENERIC148 249
#define PARTICLE_TYPE_GENERIC149 250
#define PARTICLE_TYPE_GENERIC150 251
#define PARTICLE_TYPE_GENERIC151 252
#define PARTICLE_TYPE_GENERIC152 253
#define PARTICLE_TYPE_GENERIC153 254
#define PARTICLE_TYPE_GENERIC154 255
#define PARTICLE_TYPE_GENERIC155 256
#define PARTICLE_TYPE_GENERIC156 257
#define PARTICLE_TYPE_GENERIC157 258
#define PARTICLE_TYPE_GENERIC158 259
#define PARTICLE_TYPE_GENERIC159 260
#define PARTICLE_TYPE_GENERIC160 261
#define PARTICLE_TYPE_GENERIC161 262
#define PARTICLE_TYPE_GENERIC162 263
#define PARTICLE_TYPE_GENERIC163 264
#define PARTICLE_TYPE_GENERIC164 265
#define PARTICLE_TYPE_GENERIC165 266
#define PARTICLE_TYPE_GENERIC166 267
#define PARTICLE_TYPE_GENERIC167 268
#define PARTICLE_TYPE_GENERIC168 269
#define PARTICLE_TYPE_GENERIC169 270
#define PARTICLE_TYPE_GENERIC170 271
#define PARTICLE_TYPE_GENERIC171 272
#define PARTICLE_TYPE_GENERIC172 273
#define PARTICLE_TYPE_GENERIC173 274
#define PARTICLE_TYPE_GENERIC174 275
#define PARTICLE_TYPE_GENERIC175 276
#define PARTICLE_TYPE_GENERIC176 277
#define PARTICLE_TYPE_GENERIC177 278
#define PARTICLE_TYPE_GENERIC178 279
#define PARTICLE_TYPE_GENERIC179 280
#define PARTICLE_TYPE_GENERIC180 281
#define PARTICLE_TYPE_GENERIC181 282
#define PARTICLE_TYPE_GENERIC182 283
#define PARTICLE_TYPE_GENERIC183 284
#define PARTICLE_TYPE_GENERIC184 285
#define PARTICLE_TYPE_GENERIC185 286
#define PARTICLE_TYPE_GENERIC186 287
#define PARTICLE_TYPE_GENERIC187 288
#define PARTICLE_TYPE_GENERIC188 289
#define PARTICLE_TYPE_GENERIC189 290
#define PARTICLE_TYPE_GENERIC190 291
#define PARTICLE_TYPE_GENERIC191 292
#define PARTICLE_TYPE_GENERIC192 293
#define PARTICLE_TYPE_GENERIC193 294
#define PARTICLE_TYPE_GENERIC194 295
#define PARTICLE_TYPE_GENERIC195 296
#define PARTICLE_TYPE_GENERIC196 297
#define PARTICLE_TYPE_GENERIC197 298
#define PARTICLE_TYPE_GENERIC198 299
#define PARTICLE_TYPE_GENERIC199 300
#define PARTICLE_TYPE_GENERIC200 301
#define PARTICLE_TYPE_REGENERATION_APPEARANCE 302
#define PARTICLE_TYPE_MINIGUN_BULLET 303
#define PARTICLE_TYPE_PLAYER_IMPACT_BLOOD 304
#define PARTICLE_TYPE_FREEZE_EXPLOSION 305
#define PARTICLE_TYPE_PICKUPSPECIAL1 306
#define PARTICLE_TYPE_PICKUPSPECIAL2 307
#define PARTICLE_TYPE_PICKUPSPECIAL3 308
#define PARTICLE_TYPE_FREEZE_START 309
#define PARTICLE_TYPE_CHRONOSCEPTER 310
#define PARTICLE_TYPE_WEFFECT_CHRONOSCEPTER 311
#define PARTICLE_TYPE_ENEMY_LONGHUNTER 312
#define PARTICLE_TYPE_CHRONOSCEPTERCHARGE 313
#define PARTICLE_TYPE_REGENERATION_START 314
#define PARTICLE_TYPE_GENERIC201 315
#define PARTICLE_TYPE_GENERIC202 316
#define PARTICLE_TYPE_GENERIC203 317
#define PARTICLE_TYPE_GENERIC204 318
#define PARTICLE_TYPE_GENERIC205 319
#define PARTICLE_TYPE_GENERIC206 320
#define PARTICLE_TYPE_GENERIC207 321
#define PARTICLE_TYPE_GENERIC208 322
#define PARTICLE_TYPE_GENERIC209 323
#define PARTICLE_TYPE_GENERIC210 324
#define PARTICLE_TYPE_GENERIC211 325
#define PARTICLE_TYPE_GENERIC212 326
#define PARTICLE_TYPE_GENERIC213 327
#define PARTICLE_TYPE_GENERIC214 328
#define PARTICLE_TYPE_GENERIC215 329
#define PARTICLE_TYPE_GENERIC216 330
#define PARTICLE_TYPE_GENERIC217 331
#define PARTICLE_TYPE_GENERIC218 332
#define PARTICLE_TYPE_GENERIC219 333
#define PARTICLE_TYPE_GENERIC220 334
#define PARTICLE_TYPE_GENERIC221 335
#define PARTICLE_TYPE_GENERIC222 336
#define PARTICLE_TYPE_GENERIC223 337
#define PARTICLE_TYPE_GENERIC224 338
#define PARTICLE_TYPE_GENERIC225 339
#define PARTICLE_TYPE_GENERIC226 340
#define PARTICLE_TYPE_GENERIC227 341
#define PARTICLE_TYPE_GENERIC228 342
#define PARTICLE_TYPE_GENERIC229 343
#define PARTICLE_TYPE_GENERIC230 344
#define PARTICLE_TYPE_GENERIC231 345
#define PARTICLE_TYPE_GENERIC232 346
#define PARTICLE_TYPE_GENERIC233 347
#define PARTICLE_TYPE_GENERIC234 348
#define PARTICLE_TYPE_GENERIC235 349
#define PARTICLE_TYPE_GENERIC236 350
#define PARTICLE_TYPE_GENERIC237 351
#define PARTICLE_TYPE_GENERIC238 352
#define PARTICLE_TYPE_GENERIC239 353
#define PARTICLE_TYPE_GENERIC240 354
#define PARTICLE_TYPE_GENERIC241 355
#define PARTICLE_TYPE_GENERIC242 356
#define PARTICLE_TYPE_GENERIC243 357
#define PARTICLE_TYPE_GENERIC244 358
#define PARTICLE_TYPE_GENERIC245 359
#define PARTICLE_TYPE_GENERIC246 360
#define PARTICLE_TYPE_GENERIC247 361
#define PARTICLE_TYPE_GENERIC248 362
#define PARTICLE_TYPE_GENERIC249 363
#define PARTICLE_TYPE_GENERIC250 364
#define PARTICLE_TYPE_GENERIC251 365
#define PARTICLE_TYPE_GENERIC252 366
#define PARTICLE_TYPE_GENERIC253 367
#define PARTICLE_TYPE_GENERIC254 368
#define PARTICLE_TYPE_GENERIC255 369
#define PARTICLE_TYPE_GENERIC256 370
#define PARTICLE_TYPE_GENERIC257 371
#define PARTICLE_TYPE_GENERIC258 372
#define PARTICLE_TYPE_GENERIC259 373
#define PARTICLE_TYPE_GENERIC260 374

#define PARTICLE_TYPE_MAX 375

extern char *Particle_Strings[];





#define PARTICLE_IMPACTS_GRASS 0
#define PARTICLE_IMPACTS_WATERSURFACE 1
#define PARTICLE_IMPACTS_STEEL 2
#define PARTICLE_IMPACTS_STONE 3
#define PARTICLE_IMPACTS_FLESH 4
#define PARTICLE_IMPACTS_ALIENFLESH 5
#define PARTICLE_IMPACTS_FLESHWATER 6
#define PARTICLE_IMPACTS_LAVA 7
#define PARTICLE_IMPACTS_TAR 8
#define PARTICLE_IMPACTS_FORCEFIELD 9

#define PARTICLE_IMPACTS_ENDLIFE 10
#define PARTICLE_IMPACTS_EVERYFRAME 11
#define PARTICLE_IMPACTS_ENDLIFEWATER 12
#define PARTICLE_IMPACTS_EVERYFRAMEWATER 13

#define PARTICLE_IMPACTS_AMT 14

extern char *Particle_Impact_Strings[];

#define PARTICLE_PLAYBACK_RUNONCE 0
#define PARTICLE_PLAYBACK_RUNANDHOLD 1
#define PARTICLE_PLAYBACK_LOOP 2
#define PARTICLE_PLAYBACK_PINGPONG 3
#define PARTICLE_PLAYBACK_RANDOM 4
#define PARTICLE_PLAYBACK_RANDOMANDHOLD 5




#define PARTICLE_VISIBLE_CLOSE 0
#define PARTICLE_VISIBLE_FAR 1
#define PARTICLE_VISIBLE_ALWAYS 2
#define PARTICLE_VISIBLE_INVISIBLE 3




#define PARTICLE_ALIGN_SCREEN 0
#define PARTICLE_ALIGN_UP 1
#define PARTICLE_ALIGN_GROUND 2
#define PARTICLE_ALIGN_WALL 3
#define PARTICLE_ALIGN_AUTO 4
#define PARTICLE_ALIGN_YAXIS 5




#define PARTICLE_BEHAVIOR_FADEOUT (1 << 0)

#define PARTICLE_BEHAVIOR_HOLDANIMONBOUNCE (1 << 2)
#define PARTICLE_BEHAVIOR_ALIGNONBOTTOM (1 << 3)
#define PARTICLE_BEHAVIOR_RETAINVELOCITY (1 << 4)
#define PARTICLE_BEHAVIOR_ADDSOURCEVELOCITY (1 << 5)
#define PARTICLE_BEHAVIOR_CANNOTHITSOURCE (1 << 6)
#define PARTICLE_BEHAVIOR_CREATEONCE (1 << 7)
#define PARTICLE_BEHAVIOR_MIRRORWIDTH (1 << 8)
#define PARTICLE_BEHAVIOR_MIRRORHEIGHT (1 << 9)
#define PARTICLE_BEHAVIOR_INTERSECTION (1 << 10)
#define PARTICLE_BEHAVIOR_BOUNCEONLYONCE (1 << 11)
#define PARTICLE_BEHAVIOR_SCALELINEAR (1 << 12)
#define PARTICLE_BEHAVIOR_DRAWONBOTTOM (1 << 13)
#define PARTICLE_BEHAVIOR_ZBUFFER (1 << 14)
#define PARTICLE_BEHAVIOR_SPARKLE (1 << 15)
#define PARTICLE_BEHAVIOR_CROSSFADE (1 << 16)
#define PARTICLE_BEHAVIOR_DIEONWATERSURFACE (1 << 17)
#define PARTICLE_BEHAVIOR_AIMATPLAYER (1 << 18)
#define PARTICLE_BEHAVIOR_HASLENSFLARE (1 << 19)
#define PARTICLE_BEHAVIOR_GLARE (1 << 20)
#define PARTICLE_BEHAVIOR_PLAYONLYWHENFAR (1 << 21)
#define PARTICLE_BEHAVIOR_PLAYONLYWHENNEAR (1 << 22)
#define PARTICLE_BEHAVIOR_CENTERIMPACTONINSTANCE (1 << 23)
#define PARTICLE_BEHAVIOR_GLOBALCOORD (1 << 24)
#define PARTICLE_BEHAVIOR_BLOODEFFECT (1 << 25)
#define PARTICLE_BEHAVIOR_IMPACTEFFECT (1 << 26)
#define PARTICLE_BEHAVIOR_RESTRICTAIMATPLAYER (1 << 27)
#define PARTICLE_BEHAVIOR_NOWALLSPAWN (1 << 28)
#define PARTICLE_BEHAVIOR_NOGRDSPAWN (1 << 29)




#define PARTICLE_DEFAULT_PRIORITY 50





#define _INC_TEXTLOAD 




struct CROMTextureFormat_t;
struct CCacheEntry_t;



typedef struct CTextureInfo_t
{
 int m_nBitmaps,
          m_nPalettes;
 struct CROMTextureFormat_t *m_pFormat;
} CTextureInfo;



typedef struct CTextureLoader_t
{
 struct CCacheEntry_t *m_pceTextureSet;
 ROMAddress *m_rpTextureSet;
 unsigned long m_TextureSetSize;
} CTextureLoader;




void func_80026DA4(CTextureLoader *pThis, ROMAddress *rpTextureSet, unsigned long TextureSetSize);
void CTextureLoader__ConstructFromIndex(CTextureLoader *pThis,
                CIndexedSet *pisTextureSetsIndex,
                ROMAddress *rpTextureSets,
                int nIndex);
int CTextureLoader__RequestTextureSet(CTextureLoader *pThis, CCartCache *pCache, char *szDescription);
void func_80026AD0(CTextureLoader *pThis, CTextureInfo *pInfo);
void CTextureLoader__LoadTexture(CTextureLoader *pThis, Gfx **ppDLP,
             int nBitmap, int nPalette,
             int MultU, int MultV,
             unsigned int TileFlagsU, unsigned int TileFlagsV,
             unsigned int Shift);
void CTextureLoader__InvalidateTextureCache();







#define _INC_AISTRUC 

struct CGameObjectInstance_t;
struct CGameRegion_t;



#define GRAVITY_EARTH (-32.174*SCALING_FACTOR*15)
#define GRAVITY_ACCELERATION (-12*SCALING_FACTOR*15)
#define GRAVITY_WATER_ACCELERATION (-1.8*SCALING_FACTOR*15)






#define AI_OBJECT_CHARACTER_PLAYER 0
#define AI_OBJECT_CHARACTER_RAPTOR 1
#define AI_OBJECT_CHARACTER_HUMAN1 2
#define AI_OBJECT_CHARACTER_SABERTIGER 3
#define AI_OBJECT_CHARACTER_DIMETRODON 4
#define AI_OBJECT_CHARACTER_TRICERATOPS 5
#define AI_OBJECT_CHARACTER_MOSCHOPS 6
#define AI_OBJECT_CHARACTER_PTERANODON 7
#define AI_OBJECT_CHARACTER_SUBTERRANEAN 8
#define AI_OBJECT_CHARACTER_LEAPER 9
#define AI_OBJECT_CHARACTER_ALIEN 10
#define AI_OBJECT_CHARACTER_HULK 11
#define AI_OBJECT_CHARACTER_ROBOT 12
#define AI_OBJECT_CHARACTER_BADFISH 13
#define AI_OBJECT_CHARACTER_GOODFISH 14
#define AI_OBJECT_CHARACTER_SLUDGEBOY 15
#define AI_OBJECT_CHARACTER_PLANT 16
#define AI_OBJECT_CHARACTER_ANCIENTWARRIOR 17
#define AI_OBJECT_CHARACTER_HIGHPRIEST 18
#define AI_OBJECT_CHARACTER_PLAYER_WARP_DESTINATION 19
#define AI_OBJECT_CHARACTER_GENERICRED 20
#define AI_OBJECT_CHARACTER_GENERICGREEN 21
#define AI_OBJECT_CHARACTER_GENERICMETAL 22


#define AI_OBJECT_CHARACTER_MANTIS_BOSS 1000
#define AI_OBJECT_CHARACTER_TREX_BOSS 1001
#define AI_OBJECT_CHARACTER_CAMPAIGNER_BOSS 1002
#define AI_OBJECT_CHARACTER_LONGHUNTER_BOSS 1003
#define AI_OBJECT_CHARACTER_HUMVEE_BOSS 1004


#define AI_OBJECT_CEILING_TURRET 2000
#define AI_OBJECT_BUNKER_TURRET 2001


#define AI_SPECIES_RAPTOR (1<<0)
#define AI_SPECIES_HUMAN1 (1<<1)
#define AI_SPECIES_SABERTIGER (1<<2)
#define AI_SPECIES_DIMETRODON (1<<3)
#define AI_SPECIES_TRICERATOPS (1<<4)
#define AI_SPECIES_MOSCHOPS (1<<5)
#define AI_SPECIES_PTERANODON (1<<6)
#define AI_SPECIES_SUBTERRANEAN (1<<7)
#define AI_SPECIES_LEAPER (1<<8)
#define AI_SPECIES_ALIEN (1<<9)
#define AI_SPECIES_HULK (1<<10)
#define AI_SPECIES_ROBOT (1<<11)
#define AI_SPECIES_MANTIS_BOSS (1<<12)

#define AI_OBJECT_WEAPON_START 100
#define AI_OBJECT_WEAPON_KNIFE 100
#define AI_OBJECT_WEAPON_TOMAHAWK 101
#define AI_OBJECT_WEAPON_TEKBOW 102
#define AI_OBJECT_WEAPON_SEMIAUTOMATICPISTOL 103
#define AI_OBJECT_WEAPON_ASSAULTRIFLE 104
#define AI_OBJECT_WEAPON_MACHINEGUN 105
#define AI_OBJECT_WEAPON_RIOTSHOTGUN 106
#define AI_OBJECT_WEAPON_AUTOMATICSHOTGUN 107
#define AI_OBJECT_WEAPON_MINIGUN 108
#define AI_OBJECT_WEAPON_GRENADE_LAUNCHER 109
#define AI_OBJECT_WEAPON_TECHWEAPON1 110
#define AI_OBJECT_WEAPON_TECHWEAPON2 111
#define AI_OBJECT_WEAPON_ROCKET 112
#define AI_OBJECT_WEAPON_SHOCKWAVE 113
#define AI_OBJECT_WEAPON_CHRONOSCEPTER 114
#define AI_OBJECT_WEAPON_END 114
#define AI_OBJECT_WEAPON_TOTAL ((AI_OBJECT_WEAPON_END-AI_OBJECT_WEAPON_START)+1)

#define AI_OBJECT_STATIC_NOWELD 200
#define AI_OBJECT_STATIC_GRASS 201
#define AI_OBJECT_STATIC_DIRT 202
#define AI_OBJECT_STATIC_WATERSURFACE 203
#define AI_OBJECT_STATIC_STEEL 204
#define AI_OBJECT_STATIC_STONE 205
#define AI_OBJECT_STATIC_WOOD 206
#define AI_OBJECT_STATIC_FOLIAGE 207
#define AI_OBJECT_STATIC_FLESH 208
#define AI_OBJECT_STATIC_ALIENFLESH 209
#define AI_OBJECT_STATIC_WATERFLOOR 210

#define AI_OBJECT_DEVICE_START 300
#define AI_OBJECT_DEVICE_DOOR 300
#define AI_OBJECT_DEVICE_ACTION 301
#define AI_OBJECT_DEVICE_STATUE 302
#define AI_OBJECT_DEVICE_TIMERACTION 303
#define AI_OBJECT_DEVICE_CONSTANTACTION 304
#define AI_OBJECT_DEVICE_WALL 305
#define AI_OBJECT_DEVICE_ARROWTARGET 306
#define AI_OBJECT_DEVICE_SPINDOOR 307
#define AI_OBJECT_DEVICE_LASER 308
#define AI_OBJECT_DEVICE_EXPTARGET 309
#define AI_OBJECT_DEVICE_ELEVATOR 310
#define AI_OBJECT_DEVICE_PLATFORM 311
#define AI_OBJECT_DEVICE_DEATHELEVATOR 312
#define AI_OBJECT_DEVICE_TREXELEVATOR 313
#define AI_OBJECT_DEVICE_TREXPLATFORM 314
#define AI_OBJECT_DEVICE_LONGHUNTER_SWITCH 315
#define AI_OBJECT_DEVICE_COLLAPSINGPLATFORM 316
#define AI_OBJECT_DEVICE_PORTAL 317
#define AI_OBJECT_DEVICE_LOCK 318
#define AI_OBJECT_DEVICE_DRAIN 319
#define AI_OBJECT_DEVICE_FLOOD 320
#define AI_OBJECT_DEVICE_GATE 321
#define AI_OBJECT_CINEMA_TUROK_ARROW 322
#define AI_OBJECT_DEVICE_CRYSTAL 323
#define AI_OBJECT_DEVICE_SPINELEVATOR 324
#define AI_OBJECT_DEVICE_KEYFLOOR 325
#define AI_OBJECT_DEVICE_SPINPLATFORM 326
#define AI_OBJECT_DEVICE_FADEINFADEOUT 327
#define AI_OBJECT_DEVICE_PRESSUREACTION 328
#define AI_OBJECT_DEVICE_FOOTELEVATOR 329
#define AI_OBJECT_DEVICE_PICKUP_GERATOR 330
#define AI_OBJECT_DEVICE_ANIMOFFSCREENACTION 331
#define AI_OBJECT_DEVICE_END 332

#define AI_OBJECT_PICKUP_START 400
#define AI_OBJECT_PICKUP_HEALTH_2 400
#define AI_OBJECT_PICKUP_HEALTH_10 401
#define AI_OBJECT_PICKUP_HEALTH_25 402
#define AI_OBJECT_PICKUP_HEALTH_100 403
#define AI_OBJECT_PICKUP_HEALTH_100PLUS 404
#define AI_OBJECT_PICKUP_MORTAL_WOUND 405
#define AI_OBJECT_PICKUP_BACKPACK 406
#define AI_OBJECT_PICKUP_SPIRITUAL 407
#define AI_OBJECT_PICKUP_MAP 408
#define AI_OBJECT_PICKUP_PISTOL 409
#define AI_OBJECT_PICKUP_RIFLE 410
#define AI_OBJECT_PICKUP_RIOTSHOTGUN 411
#define AI_OBJECT_PICKUP_AUTOSHOTGUN 412
#define AI_OBJECT_PICKUP_MINIGUN 413
#define AI_OBJECT_PICKUP_GRENADELAUNCHER 414
#define AI_OBJECT_PICKUP_MACHINEGUN 415
#define AI_OBJECT_PICKUP_TECHWEAPON1 416
#define AI_OBJECT_PICKUP_ROCKET 417
#define AI_OBJECT_PICKUP_SHOCKWAVE 418
#define AI_OBJECT_PICKUP_TECHWEAPON2 419
#define AI_OBJECT_PICKUP_AMMO_ARROWS 420
#define AI_OBJECT_PICKUP_AMMO_EXPARROWSSMALL 421
#define AI_OBJECT_PICKUP_AMMO_EXPARROWSLARGE 422
#define AI_OBJECT_PICKUP_AMMO_BULLETCLIP 423
#define AI_OBJECT_PICKUP_AMMO_BULLETBOX 424
#define AI_OBJECT_PICKUP_AMMO_SHOTGUN 425
#define AI_OBJECT_PICKUP_AMMO_SHOTGUNBOX 426
#define AI_OBJECT_PICKUP_AMMO_EXPSHOTGUN 427
#define AI_OBJECT_PICKUP_AMMO_EXPSHOTGUNBOX 428
#define AI_OBJECT_PICKUP_AMMO_MINIGUN 429
#define AI_OBJECT_PICKUP_AMMO_GRENADES 430
#define AI_OBJECT_PICKUP_AMMO_GRENADEBOX 431
#define AI_OBJECT_PICKUP_AMMO_TECHSMALL 432
#define AI_OBJECT_PICKUP_AMMO_TECHLARGE 433
#define AI_OBJECT_PICKUP_AMMO_ROCKETS 434
#define AI_OBJECT_PICKUP_AMMO_SHOCKWAVE 435
#define AI_OBJECT_PICKUP_AMMO_TECHWEAPON2 436
#define AI_OBJECT_PICKUP_ARMOR_TEK 437
#define AI_OBJECT_PICKUP_SMALL_TOKEN 438
#define AI_OBJECT_PICKUP_LARGE_TOKEN 439
#define AI_OBJECT_PICKUP_KEY2 440
#define AI_OBJECT_PICKUP_KEY3 441
#define AI_OBJECT_PICKUP_KEY4 442
#define AI_OBJECT_PICKUP_KEY5 443
#define AI_OBJECT_PICKUP_KEY6 444
#define AI_OBJECT_PICKUP_KEY7 445
#define AI_OBJECT_PICKUP_KEY8 446
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR1 447
#define AI_OBJECT_PICKUP_TEKBOW 448
#define AI_OBJECT_PICKUP_KEY8MANTIS 449
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR2 450
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR3 451
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR4 452
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR5 453
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR6 454
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR7 455
#define AI_OBJECT_PICKUP_CHRONOSCEPTOR8 456
#define AI_OBJECT_PICKUP_END 457

#define AI_OBJECT_WARP_START 600
#define AI_OBJECT_WARP_DYNAMIC 600
#define AI_OBJECT_WARP_END 600

#define AI_OBJECT_BOUNCY_START 700
#define AI_OBJECT_BOUNCY_ROCK 700
#define AI_OBJECT_BOUNCY_ALIEN_HEAD 701
#define AI_OBJECT_BOUNCY_ALIEN_HAND 702
#define AI_OBJECT_BOUNCY_ALIEN_FOOT 703
#define AI_OBJECT_BOUNCY_ALIEN_TORSO 704
#define AI_OBJECT_BOUNCY_LEAPER_HEAD 705
#define AI_OBJECT_BOUNCY_LEAPER_HAND 706
#define AI_OBJECT_BOUNCY_LEAPER_FOOT 707
#define AI_OBJECT_BOUNCY_LEAPER_TORSO 708
#define AI_OBJECT_BOUNCY_END 709

#define AI_OBJECT_MORPH_START 800
#define AI_OBJECT_MORPHER 800
#define AI_OBJECT_MORPH_END 800


#define AI_ANIM_IDLE 0
#define AI_ANIM_WALK 1
#define AI_ANIM_RUN 2
#define AI_ANIM_TURNL90 3
#define AI_ANIM_TURNR90 4
#define AI_ANIM_GETATTENTION 5
#define AI_ANIM_TURN180 6
#define AI_ANIM_WTURNL90 7
#define AI_ANIM_WTURNR90 8
#define AI_ANIM_WTURN180 9
#define AI_ANIM_RTURNL90 10
#define AI_ANIM_RTURNR90 11
#define AI_ANIM_RTURN180 12
#define AI_ANIM_IDLE_INTEL1 13
#define AI_ANIM_IDLE_INTEL2 14
#define AI_ANIM_EVADE_LEFT 15
#define AI_ANIM_EVADE_RIGHT 16
#define AI_ANIM_EVADE_CROUCH 17
#define AI_ANIM_ATTACK_STRONG1 18
#define AI_ANIM_ATTACK_STRONG2 19
#define AI_ANIM_ATTACK_STRONG3 20
#define AI_ANIM_ATTACK_STRONG4 21
#define AI_ANIM_ATTACK_STRONG5 22
#define AI_ANIM_ATTACK_STRONG6 23
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE 24
#define AI_ANIM_ATTACK_STRONG7 25
#define AI_ANIM_ATTACK_STRONG8 26
#define AI_ANIM_ATTACK_STRONG9 27
#define AI_ANIM_IMPACT_NORMAL 28
#define AI_ANIM_IMPACT_STUNNED 29
#define AI_ANIM_IMPACT_EXPLODE_LEFT 30
#define AI_ANIM_IMPACT_EXPLODE_RIGHT 31
#define AI_ANIM_IMPACT_EXPLODE_FORWARD 32
#define AI_ANIM_IMPACT_EXPLODE_BACKWARD 33
#define AI_ANIM_DEATH_NORMAL 34
#define AI_ANIM_DEATH_VIOLENT 35
#define AI_ANIM_DEATH_HIGH_FALL 36
#define AI_ANIM_DEATH_WIPEOUT 37
#define AI_ANIM_RAGE 38

#define AI_ANIM_WEAPON_IDLE 39
#define AI_ANIM_WEAPON_WALK 40
#define AI_ANIM_WEAPON_RUN 41
#define AI_ANIM_WEAPON_SLASHLEFT 42
#define AI_ANIM_WEAPON_SLASHRIGHT 43
#define AI_ANIM_WEAPON_STAB 44
#define AI_ANIM_WEAPON_FIRE1 45
#define AI_ANIM_WEAPON_FIRE2 46
#define AI_ANIM_WEAPON_ONSCREEN 47
#define AI_ANIM_WEAPON_OFFSCREEN 48
#define AI_ANIM_WEAPON_GUNKICKBACK 49
#define AI_ANIM_WEAPON_GUNKICKLEFT 50
#define AI_ANIM_WEAPON_GUNKICKRIGHT 51
#define AI_ANIM_WEAPON_GUNKICKUP 52
#define AI_ANIM_WEAPON_GUNKICKDOWN 53

#define AI_ANIM_ATTACK_STRONG10 54
#define AI_ANIM_ATTACK_STRONG11 55
#define AI_ANIM_ATTACK_STRONG12 56
#define AI_ANIM_ATTACK_STRONG13 57
#define AI_ANIM_ATTACK_STRONG14 58
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE2 59
#define AI_ANIM_IMPACT_EXPLODE_DEAD1 60
#define AI_ANIM_IMPACT_EXPLODE_DEAD2 61


#define AI_ANIM_BOSS_MANTIS_IDLE_CEILING 62
#define AI_ANIM_BOSS_MANTIS_IDLE_FLOOR 63
#define AI_ANIM_BOSS_MANTIS_IDLE_LEFT_WALL 64
#define AI_ANIM_BOSS_MANTIS_IDLE_RIGHT_WALL 65
#define AI_ANIM_BOSS_MANTIS_LOOK 66

#define AI_ANIM_BOSS_MANTIS_TURN_CEILING_LEFT90 67
#define AI_ANIM_BOSS_MANTIS_TURN_CEILING_RIGHT90 68
#define AI_ANIM_BOSS_MANTIS_TURN_FLOOR_LEFT90 69
#define AI_ANIM_BOSS_MANTIS_TURN_FLOOR_RIGHT90 70

#define AI_ANIM_BOSS_MANTIS_BREAK_FLOOR 71
#define AI_ANIM_BOSS_MANTIS_DEATH_FLOOR 72
#define AI_ANIM_BOSS_MANTIS_PHASE_FLOOR 73
#define AI_ANIM_BOSS_MANTIS_RAGE_FLOOR 74

#define AI_ANIM_BOSS_MANTIS_WALK_CEILING 75
#define AI_ANIM_BOSS_MANTIS_WALK_FLOOR 76

#define AI_ANIM_BOSS_MANTIS_JUMP_CEILING_TO_FLOOR 77

#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_A 78
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_B 79
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_C 80
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR 81

#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_CEILING_A 82

#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_LEFT_WALL_A 83
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_LEFT_WALL_B 84
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_LEFT_WALL_C 85
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_LEFT_WALL 86

#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_A 87
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_B 88
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_C 89
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_RIGHT_WALL 90

#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_CEILING 91
#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_FLOOR 92
#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_A 93
#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_B 94
#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_C 95
#define AI_ANIM_BOSS_MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL 96

#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_CEILING 97
#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_FLOOR 98
#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_A 99
#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_B 100
#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_C 101
#define AI_ANIM_BOSS_MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL 102

#define AI_ANIM_BOSS_MANTIS_BLAST_FLOOR 103
#define AI_ANIM_BOSS_MANTIS_RAIN_CEILING 104
#define AI_ANIM_BOSS_MANTIS_SPIT_CEILING 105
#define AI_ANIM_BOSS_MANTIS_SPIT_FLOOR 106

#define AI_ANIM_BOSS_MANTIS_SPIT_LEFT_WALL 107
#define AI_ANIM_BOSS_MANTIS_SPIT_LEFT_WALL2 108

#define AI_ANIM_BOSS_MANTIS_SPIT_RIGHT_WALL 109
#define AI_ANIM_BOSS_MANTIS_SPIT_RIGHT_WALL2 110

#define AI_ANIM_BOSS_MANTIS_SWIPE_FLOOR 111

#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_CEILING_B 112
#define AI_ANIM_BOSS_MANTIS_JUMP_FLOOR_TO_CEILING_C 113

#define AI_ANIM_BOSS_MANTIS_EXPLODE_FLOOR_BACK 114
#define AI_ANIM_BOSS_MANTIS_EXPLODE_FLOOR_FRONT 115
#define AI_ANIM_BOSS_MANTIS_EXPLODE_FLOOR_LEFT 116
#define AI_ANIM_BOSS_MANTIS_EXPLODE_FLOOR_RIGHT 117
#define AI_ANIM_BOSS_MANTIS_EXPLODE_CEILING 118
#define AI_ANIM_BOSS_MANTIS_EXPLODE_LEFT_WALL 119
#define AI_ANIM_BOSS_MANTIS_EXPLODE_RIGHT_WALL 120

#define AI_ANIM_ATTACK_WEAPON_PROJECTILE3 121
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE4 122
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE5 123
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE6 124

#define AI_ANIM_IMPACT_EXPLODE_LEFT_LAND 125
#define AI_ANIM_IMPACT_EXPLODE_RIGHT_LAND 126
#define AI_ANIM_IMPACT_EXPLODE_FORWARD_LAND 127
#define AI_ANIM_IMPACT_EXPLODE_BACKWARD_LAND 128

#define AI_ANIM_IDLE2 129
#define AI_ANIM_WALK2 130
#define AI_ANIM_RUN2 131
#define AI_ANIM_TURNL902 132
#define AI_ANIM_TURNR902 133
#define AI_ANIM_TURN1802 134
#define AI_ANIM_WTURNL902 135
#define AI_ANIM_WTURNR902 136
#define AI_ANIM_WTURN1802 137
#define AI_ANIM_RTURNL902 138
#define AI_ANIM_RTURNR902 139
#define AI_ANIM_RTURN1802 140

#define AI_ANIM_ATTACK_WEAPON_PROJECTILE7 141
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE8 142
#define AI_ANIM_DEATH_NORMAL2 143
#define AI_ANIM_DEATH_VIOLENT2 144
#define AI_ANIM_DEATH_WIPEOUT2 145
#define AI_ANIM_DEATH_FLYINGFALL 146
#define AI_ANIM_DEATH_FLYINGCRASHLAND 147
#define AI_ANIM_DEATH_VIOLENTLESSCHANCE 148
#define AI_ANIM_DEATH_VIOLENT2LESSCHANCE 149
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE9 150
#define AI_ANIM_ATTACK_WEAPON_PROJECTILE10 151

#define AI_ANIM_INTERACTIVE_ANIMATION1 200
#define AI_ANIM_INTERACTIVE_ANIMATION2 201
#define AI_ANIM_INTERACTIVE_ANIMATION3 202
#define AI_ANIM_INTERACTIVE_ANIMATION4 203
#define AI_ANIM_INTERACTIVE_ANIMATION5 204
#define AI_ANIM_INTERACTIVE_ANIMATION6 205
#define AI_ANIM_INTERACTIVE_ANIMATION7 206
#define AI_ANIM_INTERACTIVE_ANIMATION8 207
#define AI_ANIM_INTERACTIVE_ANIMATION9 208
#define AI_ANIM_INTERACTIVE_ANIMATION10 209
#define AI_ANIM_INTERACTIVE_ANIMATION11 210
#define AI_ANIM_INTERACTIVE_ANIMATION12 211
#define AI_ANIM_INTERACTIVE_ANIMATION13 212
#define AI_ANIM_INTERACTIVE_ANIMATION14 213
#define AI_ANIM_INTERACTIVE_ANIMATION15 214
#define AI_ANIM_INTERACTIVE_ANIMATION16 215
#define AI_ANIM_INTERACTIVE_ANIMATION17 216
#define AI_ANIM_INTERACTIVE_ANIMATION18 217
#define AI_ANIM_INTERACTIVE_ANIMATION19 218
#define AI_ANIM_INTERACTIVE_ANIMATION20 219
#define AI_ANIM_INTERACTIVE_ANIMATION21 220
#define AI_ANIM_INTERACTIVE_ANIMATION22 221
#define AI_ANIM_INTERACTIVE_ANIMATION23 222
#define AI_ANIM_INTERACTIVE_ANIMATION24 223
#define AI_ANIM_INTERACTIVE_ANIMATION25 224
#define AI_ANIM_INTERACTIVE_ANIMATION26 225
#define AI_ANIM_INTERACTIVE_ANIMATION27 226
#define AI_ANIM_INTERACTIVE_ANIMATION28 227
#define AI_ANIM_INTERACTIVE_ANIMATION29 228
#define AI_ANIM_INTERACTIVE_ANIMATION30 229


#define AI_ABSOLUTE_ANIM_START 230
#define AI_ANIM_INTERACTIVE_ABS_31 230
#define AI_ANIM_INTERACTIVE_ABS_32 231
#define AI_ANIM_INTERACTIVE_ABS_33 232
#define AI_ANIM_INTERACTIVE_ABS_34 233
#define AI_ANIM_INTERACTIVE_ABS_35 234
#define AI_ANIM_INTERACTIVE_ABS_36 235
#define AI_ANIM_INTERACTIVE_ABS_37 236
#define AI_ANIM_INTERACTIVE_ABS_38 237
#define AI_ANIM_INTERACTIVE_ABS_39 238
#define AI_ANIM_INTERACTIVE_ABS_40 239
#define AI_ANIM_INTERACTIVE_ABS_41 240
#define AI_ANIM_INTERACTIVE_ABS_42 241
#define AI_ANIM_INTERACTIVE_ABS_43 242
#define AI_ANIM_INTERACTIVE_ABS_44 243
#define AI_ANIM_INTERACTIVE_ABS_45 244
#define AI_ANIM_INTERACTIVE_ABS_46 245
#define AI_ANIM_INTERACTIVE_ABS_47 246
#define AI_ANIM_INTERACTIVE_ABS_48 247
#define AI_ANIM_INTERACTIVE_ABS_49 248
#define AI_ANIM_INTERACTIVE_ABS_50 249
#define AI_ABSOLUTE_ANIM_END 249


#define AI_ANIM_WEAPON_UNDERWATER_SLASH 250
#define AI_ANIM_WEAPON_UNDERWATER_IDLE 251


#define AI_ANIM_WEAPON_LASTBULLETOFFSCREEN 2000
#define AI_ANIM_TWITCH_NORMAL1 2001
#define AI_ANIM_TWITCH_NORMAL2 2002
#define AI_ANIM_TWITCH_VIOLENT1 2003
#define AI_ANIM_TWITCH_VIOLENT2 2004
#define AI_ANIM_TWITCH_HIGHFALL1 2005
#define AI_ANIM_TWITCH_HIGHFALL2 2006
#define AI_ANIM_TWITCH_WIPEOUT1 2007
#define AI_ANIM_TWITCH_WIPEOUT2 2008
#define AI_ANIM_TWITCH_EXPDEAD1_1 2009
#define AI_ANIM_TWITCH_EXPDEAD1_2 2010
#define AI_ANIM_TWITCH_EXPDEAD2_1 2011
#define AI_ANIM_TWITCH_EXPDEAD2_2 2012
#define AI_ANIM_TWITCH_EXPLEFT1 2013
#define AI_ANIM_TWITCH_EXPLEFT2 2014
#define AI_ANIM_TWITCH_EXPRIGHT1 2015
#define AI_ANIM_TWITCH_EXPRIGHT2 2016
#define AI_ANIM_TWITCH_EXPBACK1 2017
#define AI_ANIM_TWITCH_EXPBACK2 2018
#define AI_ANIM_TWITCH_EXPFOR1 2019
#define AI_ANIM_TWITCH_EXPFOR2 2020

#define AI_ANIM_SWIM 2500
#define AI_ANIM_ATTACK_SWIM1 2501
#define AI_ANIM_ATTACK_SWIM2 2502
#define AI_ANIM_ATTACK_SWIM3 2503
#define AI_ANIM_DEATH_SWIM 2504
#define AI_ANIM_SWIMRETREAT 2505
#define AI_ANIM_RETREAT 2506
#define AI_ANIM_DEATH_SWIM_SINK 2507
#define AI_ANIM_DEATH_SWIM_SINK_POSE 2508
#define AI_ANIM_IDLE_SWIM 2509
#define AI_ANIM_SWIM2 2510
#define AI_ANIM_DEATH_SWIM_FLOAT_UP 2511
#define AI_ANIM_DEATH_SWIM_SURFACE_BOB 2512

#define AI_ANIM_TELEPORT_APPEAR 2550
#define AI_ANIM_TELEPORT_AWAY 2551
#define AI_ANIM_TELEPORT_AWAY2 2552
#define AI_ANIM_TELEPORT_MOVE 2553

#define AI_ANIM_DOOR_START 2600
#define AI_ANIM_DOOR_OPEN 2601
#define AI_ANIM_DOOR_CLOSE 2602
#define AI_ANIM_ACTION_START 2603
#define AI_ANIM_ACTION_GO 2604
#define AI_ANIM_STATUE_START 2605
#define AI_ANIM_STATUE_GO 2606
#define AI_ANIM_TIMERACTION_START 2607
#define AI_ANIM_TIMERACTION_GO 2608
#define AI_ANIM_CONSTANTACTION_START 2609
#define AI_ANIM_CONSTANTACTION_GO 2610
#define AI_ANIM_WALL_START 2611
#define AI_ANIM_WALL_LEFT 2612
#define AI_ANIM_WALL_RIGHT 2613
#define AI_ANIM_ARROWTARGET_START 2614
#define AI_ANIM_SPINDOOR_STILL1 2615
#define AI_ANIM_SPINDOOR_ROTATE1 2616
#define AI_ANIM_SPINDOOR_STILL2 2617
#define AI_ANIM_SPINDOOR_ROTATE2 2618
#define AI_ANIM_SPINDOOR_STILL3 2619
#define AI_ANIM_SPINDOOR_ROTATE3 2620
#define AI_ANIM_SPINDOOR_STILL4 2621
#define AI_ANIM_SPINDOOR_ROTATE4 2622
#define AI_ANIM_LASER_START 2623
#define AI_ANIM_LASER_GO 2624
#define AI_ANIM_LASER_STOP 2625
#define AI_ANIM_EXPTARGET_START 2626
#define AI_ANIM_EXPTARGET_GO 2627
#define AI_ANIM_TREXELEVATOR_STILL 2628
#define AI_ANIM_TREXELEVATOR_OPEN 2629
#define AI_ANIM_TREXPLATFORM_CLOSED 2630
#define AI_ANIM_TREXPLATFORM_OPEN 2631
#define AI_ANIM_TREXPLATFORM_FALL 2632
#define AI_ANIM_LONGHUNTER_SWITCH_START 2633
#define AI_ANIM_LONGHUNTER_SWITCH_GO 2634
#define AI_ANIM_PORTAL_INACTIVE 2635
#define AI_ANIM_PORTAL_ACTIVE 2636
#define AI_ANIM_CRYSTAL_START 2637
#define AI_ANIM_CRYSTAL_SINK 2638
#define AI_ANIM_CRYSTAL_RISE 2639



#define AI_ANIM_ATTACK_WEAK1 2700
#define AI_ANIM_ATTACK_WEAK2 2701
#define AI_ANIM_ATTACK_WEAK3 2702
#define AI_ANIM_ATTACK_WEAK4 2703
#define AI_ANIM_ATTACK_WEAK5 2704
#define AI_ANIM_ATTACK_WEAK6 2705
#define AI_ANIM_ATTACK_WEAK7 2706
#define AI_ANIM_ATTACK_WEAK8 2707
#define AI_ANIM_ATTACK_WEAK9 2708
#define AI_ANIM_ATTACK_WEAK10 2709
#define AI_ANIM_ATTACK_WEAK11 2710
#define AI_ANIM_ATTACK_WEAK12 2711
#define AI_ANIM_ATTACK_WEAK13 2712
#define AI_ANIM_ATTACK_WEAK14 2713


#define AI_ANIM_EXTRA1 2801
#define AI_ANIM_EXTRA2 2802
#define AI_ANIM_EXTRA3 2803
#define AI_ANIM_EXTRA4 2804
#define AI_ANIM_EXTRA5 2805
#define AI_ANIM_EXTRA6 2806
#define AI_ANIM_EXTRA7 2807
#define AI_ANIM_EXTRA8 2808
#define AI_ANIM_EXTRA9 2809
#define AI_ANIM_EXTRA10 2810
#define AI_ANIM_EXTRA11 2811
#define AI_ANIM_EXTRA12 2812
#define AI_ANIM_EXTRA13 2813
#define AI_ANIM_EXTRA14 2814
#define AI_ANIM_EXTRA15 2815
#define AI_ANIM_EXTRA16 2816
#define AI_ANIM_EXTRA17 2817
#define AI_ANIM_EXTRA18 2818
#define AI_ANIM_EXTRA19 2819
#define AI_ANIM_EXTRA20 2820
#define AI_ANIM_EXTRA21 2821
#define AI_ANIM_EXTRA22 2822
#define AI_ANIM_EXTRA23 2823
#define AI_ANIM_EXTRA24 2824


#define AI_ANIM_LIMP 2900
#define AI_ANIM_LTURNL90 2901
#define AI_ANIM_LTURNR90 2902
#define AI_ANIM_LTURN180 2903




#define AI_AGITATION_MAX 300
#define AI_AGITATION_STEP 100

#define AI_AGITATION_CALM 7
#define AI_AGITATION_CALMAFTERFIGHT 15
#define AI_AGITATION_QUIETNOISE 200
#define AI_AGITATION_LOUDNOISE 200
#define AI_AGITATION_GETATTN 300
#define AI_AGITATION_SEETARGET 300
#define AI_AGITATION_FIGHTING 300
#define AI_AGITATION_HIT 300
#define AI_AGITATION_EXPLOSION 300


#define AI_AGITATED_IDLE 0
#define AI_AGITATED_AGITATED 1
#define AI_AGITATED_ATTACK 2


#define AI_RUNTURN_SMOOTHNESS 6
#define AI_WALKTURN_SMOOTHNESS 8
#define AI_TURN_SMOOTHNESS 1.1
#define AI_SWIMTURN_SMOOTHNESS 12


#define AI_RUN2WALK_DISTANCE ((18*SCALING_FACTOR)*(18*SCALING_FACTOR))


#define AI_ATTACK_DISTANCE (17*17)
#define AI_ATTACK_PROJECTILE_DISTANCE (60*60)


#define AI_SEVENT_ACIDINCOMING 0
#define AI_SEVENT_ACIDSPITPART 1
#define AI_SEVENT_ACIDSPITSND 2
#define AI_SEVENT_BLOWGUNFIRE 3
#define AI_SEVENT_BREATHPART 4
#define AI_SEVENT_BREATHSND 5
#define AI_SEVENT_CHARGEHEADSLAM 6
#define AI_SEVENT_DEATHRAINPART 7
#define AI_SEVENT_DEATHRAINSND 8
#define AI_SEVENT_EARTHQUAKE 9
#define AI_SEVENT_ENERGYBLASTPART 10
#define AI_SEVENT_ENERGYBLASTSND 11
#define AI_SEVENT_EXPLOSIVELAUNCHED 12
#define AI_SEVENT_EYEFIREPART 13
#define AI_SEVENT_EYEFIRESND 14
#define AI_SEVENT_FIREBALLPART 15
#define AI_SEVENT_FIREBALLSND 16
#define AI_SEVENT_JAWSSNAP 17
#define AI_SEVENT_SHOCKWAVEPART 18
#define AI_SEVENT_SHOCKWAVESND 19
#define AI_SEVENT_SPELLCASTPART 20
#define AI_SEVENT_SPELLCASTSND 21
#define AI_SEVENT_SWINGFISTSWEAPON 22
#define AI_SEVENT_WEAPONFIRE 23
#define AI_SEVENT_WEAPONFLASH 24
#define AI_SEVENT_WEAPONROUND 25
#define AI_SEVENT_WEAPONCOCK 26
#define AI_MEVENT_GETATTN 27
#define AI_MEVENT_QUIETNOISE 28
#define AI_MEVENT_LOUDNOISE 29
#define AI_SEVENT_LOOKOFFSET 30
#define AI_MEVENT_HIT1 31
#define AI_MEVENT_HIT2 32
#define AI_MEVENT_HIT3 33
#define AI_MEVENT_HIT5 34
#define AI_MEVENT_HIT10 35
#define AI_MEVENT_HIT15 36
#define AI_MEVENT_HIT20 37
#define AI_MEVENT_HIT30 38
#define AI_MEVENT_HIT40 39
#define AI_MEVENT_HIT50 40
#define AI_MEVENT_HIT100 41
#define AI_MEVENT_EXPLOSION 42
#define AI_SEVENT_TEST 43
#define AI_SEVENT_SURFACEIMPACT 44
#define AI_SEVENT_CHITTER 45
#define AI_SEVENT_ALERT 46
#define AI_SEVENT_HYDRAULICS 47
#define AI_SEVENT_SHUTDOWN 48
#define AI_SEVENT_SWIVEL 49
#define AI_SEVENT_JETPACKOUTOFCTRL 50
#define AI_SEVENT_BURSTFROMGROUND 51
#define AI_SEVENT_CHESTTHUMP 52
#define AI_SEVENT_DEATH 53
#define AI_SEVENT_EXPLODE 54
#define AI_SEVENT_FOOTFALL 55
#define AI_SEVENT_GRUNT 56
#define AI_SEVENT_GURGLE 57
#define AI_SEVENT_HANDFALL 58
#define AI_SEVENT_HISS 59
#define AI_SEVENT_HITGROUND 60
#define AI_SEVENT_LICKING 61
#define AI_SEVENT_RAGE 62
#define AI_SEVENT_ROCKNOISE1 63
#define AI_SEVENT_RUBBINGSKIN 64
#define AI_SEVENT_SCRATCH 65
#define AI_SEVENT_SCREECH 66
#define AI_SEVENT_SNIFF 67
#define AI_SEVENT_SWOOSH 68
#define AI_SEVENT_TURNTOSTONE 69
#define AI_SEVENT_VIOLENTDEATH 70
#define AI_SEVENT_WINGFLAP 71
#define AI_SEVENT_GROWL 72
#define AI_SEVENT_ALERT1 73
#define AI_SEVENT_ALERT2 74
#define AI_SEVENT_ALERT3 75
#define AI_SEVENT_ALERT4 76
#define AI_SEVENT_DEATH1 77
#define AI_SEVENT_DEATH2 78
#define AI_SEVENT_DEATH3 79
#define AI_SEVENT_DEATH4 80
#define AI_SEVENT_INJURY1 81
#define AI_SEVENT_INJURY2 82
#define AI_SEVENT_INJURY3 83
#define AI_SEVENT_LONG1 84
#define AI_SEVENT_LONG2 85
#define AI_SEVENT_LONG3 86
#define AI_SEVENT_TAUNT1 87
#define AI_SEVENT_TAUNT2 88
#define AI_SEVENT_TAUNT3 89
#define AI_SEVENT_VIOLENTDEATH1 90
#define AI_SEVENT_VIOLENTDEATH2 91
#define AI_MEVENT_NUDGEBACK 92
#define AI_SEVENT_SCREENSHAKE 93
#define AI_SEVENT_INVINCIBLE 94
#define AI_SEVENT_BLOODARCPARTICLES 95
#define AI_SEVENT_MUZZLEFLASH 96
#define AI_SEVENT_HULK_BLASTER 97
#define AI_SEVENT_ALIEN_PROJECTILE 98
#define AI_SEVENT_KNIFEFORWARD 99
#define AI_SEVENT_KNIFELEFT 100
#define AI_SEVENT_KNIFERIGHT 101
#define AI_SEVENT_GREENBLOODARCPARTICLES 102
#define AI_SEVENT_SPURT_BLOODPARTICLES 103
#define AI_SEVENT_FOUNTAIN_BLOODPARTICLES 104
#define AI_SEVENT_GUSH_BLOODPARTICLES 105
#define AI_SEVENT_DROOL_PARTICLES 106
#define AI_MEVENT_KNIFELEFT_DAMAGE 107
#define AI_MEVENT_KNIFERIGHT_DAMAGE 108
#define AI_MEVENT_KNIFEFORWARD_DAMAGE 109
#define AI_MEVENT_TOMAHAWKLEFT_DAMAGE 110
#define AI_MEVENT_TOMAHAWKRIGHT_DAMAGE 111
#define AI_MEVENT_TOMAHAWKFORWARD_DAMAGE 112
#define AI_SEVENT_ARTERIAL_BLOODPARTICLES 113
#define AI_SEVENT_SPURT_GBLOODPARTICLES 114
#define AI_SEVENT_FOUNTAIN_GBLOODPARTICLES 115
#define AI_SEVENT_GUSH_GBLOODPARTICLES 116
#define AI_SEVENT_ARTERIAL_GBLOODPARTICLES 117
#define AI_SEVENT_WATER_DROP 118
#define AI_SEVENT_WATER_FOAM 119
#define AI_SEVENT_WATER_STEAM 120
#define AI_MEVENT_WEAPONIMPACT 121
#define AI_SEVENT_ARROW_DAMAGE 122
#define AI_SEVENT_DAMAGETARGET 123
#define AI_SEVENT_DAMAGENUDGETARGET 124
#define AI_SEVENT_GENERIC1 125
#define AI_SEVENT_GENERIC2 126
#define AI_SEVENT_GENERIC3 127
#define AI_SEVENT_GENERIC4 128
#define AI_SEVENT_GENERIC5 129
#define AI_SEVENT_GENERIC6 130
#define AI_SEVENT_GENERIC7 131
#define AI_SEVENT_GENERIC8 132
#define AI_SEVENT_GENERIC9 133
#define AI_SEVENT_GENERIC10 134
#define AI_SEVENT_GENERIC11 135
#define AI_SEVENT_GENERIC12 136
#define AI_SEVENT_GENERIC13 137
#define AI_SEVENT_GENERIC14 138
#define AI_SEVENT_GENERIC15 139
#define AI_SEVENT_GENERIC16 140
#define AI_SEVENT_GENERIC17 141
#define AI_SEVENT_GENERIC18 142
#define AI_SEVENT_GENERIC19 143
#define AI_SEVENT_GENERIC20 144
#define AI_SEVENT_GENERIC21 145
#define AI_SEVENT_GENERIC22 146
#define AI_SEVENT_GENERIC23 147
#define AI_SEVENT_GENERIC24 148
#define AI_SEVENT_GENERIC25 149
#define AI_SEVENT_GENERIC26 150
#define AI_SEVENT_GENERIC27 151
#define AI_SEVENT_GENERIC28 152
#define AI_SEVENT_GENERIC29 153
#define AI_SEVENT_GENERIC30 154
#define AI_MEVENT_SMARTBOMB 155
#define AI_SEVENT_PLASMA2_PARTICLE 156
#define AI_SEVENT_WATER_BUBBLE 157
#define AI_SEVENT_WATER_RIPPLE 158
#define AI_SEVENT_WATER_SPLASH 159
#define AI_MEVENT_SHOCKWAVE_DAMAGE 160
#define AI_SEVENT_GENERIC31 161
#define AI_SEVENT_GENERIC32 162
#define AI_SEVENT_GENERIC33 163
#define AI_SEVENT_GENERIC34 164
#define AI_SEVENT_GENERIC35 165
#define AI_SEVENT_GENERIC36 166
#define AI_SEVENT_GENERIC37 167
#define AI_SEVENT_GENERIC38 168
#define AI_SEVENT_GENERIC39 169
#define AI_SEVENT_GENERIC40 170
#define AI_SEVENT_GENERIC41 171
#define AI_SEVENT_GENERIC42 172
#define AI_SEVENT_GENERIC43 173
#define AI_SEVENT_GENERIC44 174
#define AI_SEVENT_GENERIC45 175
#define AI_SEVENT_GENERIC46 176
#define AI_SEVENT_GENERIC47 177
#define AI_SEVENT_GENERIC48 178
#define AI_SEVENT_GENERIC49 179
#define AI_SEVENT_GENERIC50 180
#define AI_SEVENT_GENERIC51 181
#define AI_SEVENT_GENERIC52 182
#define AI_SEVENT_GENERIC53 183
#define AI_SEVENT_GENERIC54 184
#define AI_SEVENT_GENERIC55 185
#define AI_SEVENT_GENERIC56 186
#define AI_SEVENT_GENERIC57 187
#define AI_SEVENT_GENERIC58 188
#define AI_SEVENT_GENERIC59 189
#define AI_SEVENT_GENERIC60 190
#define AI_SEVENT_GENERIC61 191
#define AI_SEVENT_GENERIC62 192
#define AI_SEVENT_GENERIC63 193
#define AI_SEVENT_GENERIC64 194
#define AI_SEVENT_GENERIC65 195
#define AI_SEVENT_GENERIC66 196
#define AI_SEVENT_GENERIC67 197
#define AI_SEVENT_GENERIC68 198
#define AI_SEVENT_GENERIC69 199
#define AI_SEVENT_GENERIC70 200
#define AI_SEVENT_GENERIC71 201
#define AI_SEVENT_GENERIC72 202
#define AI_SEVENT_GENERIC73 203
#define AI_SEVENT_GENERIC74 204
#define AI_SEVENT_GENERIC75 205
#define AI_SEVENT_GENERIC76 206
#define AI_SEVENT_GENERIC77 207
#define AI_SEVENT_GENERIC78 208
#define AI_SEVENT_GENERIC79 209
#define AI_SEVENT_GENERIC80 210
#define AI_SEVENT_GENERIC81 211
#define AI_SEVENT_GENERIC82 212
#define AI_SEVENT_GENERIC83 213
#define AI_SEVENT_GENERIC84 214
#define AI_SEVENT_GENERIC85 215
#define AI_SEVENT_GENERIC86 216
#define AI_SEVENT_GENERIC87 217
#define AI_SEVENT_GENERIC88 218
#define AI_SEVENT_GENERIC89 219
#define AI_SEVENT_GENERIC90 220
#define AI_SEVENT_GENERIC91 221
#define AI_SEVENT_GENERIC92 222
#define AI_SEVENT_GENERIC93 223
#define AI_SEVENT_GENERIC94 224
#define AI_SEVENT_GENERIC95 225
#define AI_SEVENT_GENERIC96 226
#define AI_SEVENT_GENERIC97 227
#define AI_SEVENT_GENERIC98 228
#define AI_SEVENT_GENERIC99 229
#define AI_SEVENT_GENERIC100 230
#define AI_MEVENT_PRESSUREPLATE 231
#define AI_SEVENT_DOOR_ALLOWENTRY 232
#define AI_SEVENT_DOOR_BLOCKENTRY 233
#define AI_MEVENT_ACTION 234
#define AI_MEVENT_STATUE 235
#define AI_MEVENT_UNUSED1 236
#define AI_MEVENT_UNUSED2 237
#define AI_SEVENT_GENERATE_PICKUPS 238
#define AI_MEVENT_BOSS1 239
#define AI_MEVENT_BOSS2 240
#define AI_MEVENT_BOSS3 241
#define AI_MEVENT_BOSS4 242
#define AI_MEVENT_BOSS5 243
#define AI_MEVENT_BOSS6 244
#define AI_MEVENT_BOSS7 245
#define AI_MEVENT_BOSS8 246
#define AI_SEVENT_MAKE_INVISIBLE 247
#define AI_SEVENT_GENERAL_SOUND 248
#define AI_SEVENT_SWOOSH_ALL_HANDS 249
#define AI_SEVENT_SWOOSH_LEFT_HAND 250
#define AI_SEVENT_SWOOSH_RIGHT_HAND 251
#define AI_SEVENT_SWOOSH_ALL_FEET 252
#define AI_SEVENT_SWOOSH_LEFT_FOOT 253
#define AI_SEVENT_SWOOSH_RIGHT_FOOT 254
#define AI_SEVENT_SWOOSH_WEAPON1 255
#define AI_SEVENT_SWOOSH_WEAPON2 256
#define AI_SEVENT_SWOOSH_TAIL 257
#define AI_SEVENT_SWOOSH_LEFT_TOES 258
#define AI_SEVENT_SWOOSH_RIGHT_TOES 259
#define AI_SEVENT_GENERIC101 260
#define AI_SEVENT_GENERIC102 261
#define AI_SEVENT_GENERIC103 262
#define AI_SEVENT_GENERIC104 263
#define AI_SEVENT_GENERIC105 264
#define AI_SEVENT_GENERIC106 265
#define AI_SEVENT_GENERIC107 266
#define AI_SEVENT_GENERIC108 267
#define AI_SEVENT_GENERIC109 268
#define AI_SEVENT_GENERIC110 269
#define AI_SEVENT_GENERIC111 270
#define AI_SEVENT_GENERIC112 271
#define AI_SEVENT_GENERIC113 272
#define AI_SEVENT_GENERIC114 273
#define AI_SEVENT_GENERIC115 274
#define AI_SEVENT_GENERIC116 275
#define AI_SEVENT_GENERIC117 276
#define AI_SEVENT_GENERIC118 277
#define AI_SEVENT_GENERIC119 278
#define AI_SEVENT_GENERIC120 279
#define AI_SEVENT_GENERIC121 280
#define AI_SEVENT_GENERIC122 281
#define AI_SEVENT_GENERIC123 282
#define AI_SEVENT_GENERIC124 283
#define AI_SEVENT_GENERIC125 284
#define AI_SEVENT_GENERIC126 285
#define AI_SEVENT_GENERIC127 286
#define AI_SEVENT_GENERIC128 287
#define AI_SEVENT_GENERIC129 288
#define AI_SEVENT_GENERIC130 289
#define AI_SEVENT_GENERIC131 290
#define AI_SEVENT_GENERIC132 291
#define AI_SEVENT_GENERIC133 292
#define AI_SEVENT_GENERIC134 293
#define AI_SEVENT_GENERIC135 294
#define AI_SEVENT_GENERIC136 295
#define AI_SEVENT_GENERIC137 296
#define AI_SEVENT_GENERIC138 297
#define AI_SEVENT_GENERIC139 298
#define AI_SEVENT_GENERIC140 299
#define AI_SEVENT_GENERIC141 300
#define AI_SEVENT_GENERIC142 301
#define AI_SEVENT_GENERIC143 302
#define AI_SEVENT_GENERIC144 303
#define AI_SEVENT_GENERIC145 304
#define AI_SEVENT_GENERIC146 305
#define AI_SEVENT_GENERIC147 306
#define AI_SEVENT_GENERIC148 307
#define AI_SEVENT_GENERIC149 308
#define AI_SEVENT_GENERIC150 309
#define AI_SEVENT_GENERIC151 310
#define AI_SEVENT_GENERIC152 311
#define AI_SEVENT_GENERIC153 312
#define AI_SEVENT_GENERIC154 313
#define AI_SEVENT_GENERIC155 314
#define AI_SEVENT_GENERIC156 315
#define AI_SEVENT_GENERIC157 316
#define AI_SEVENT_GENERIC158 317
#define AI_SEVENT_GENERIC159 318
#define AI_SEVENT_GENERIC160 319
#define AI_SEVENT_NEXT_CINEMATIC_STAGE 320
#define AI_SEVENT_GENERIC161 321
#define AI_SEVENT_GENERIC162 322
#define AI_SEVENT_GENERIC163 323
#define AI_SEVENT_GENERIC164 324
#define AI_SEVENT_GENERIC165 325
#define AI_SEVENT_GENERIC166 326
#define AI_SEVENT_GENERIC167 327
#define AI_SEVENT_GENERIC168 328
#define AI_SEVENT_GENERIC169 329
#define AI_SEVENT_GENERIC170 330
#define AI_SEVENT_GENERIC171 331
#define AI_SEVENT_GENERIC172 332
#define AI_SEVENT_GENERIC173 333
#define AI_SEVENT_GENERIC174 334
#define AI_SEVENT_GENERIC175 335
#define AI_SEVENT_GENERIC176 336
#define AI_SEVENT_GENERIC177 337
#define AI_SEVENT_GENERIC178 338
#define AI_SEVENT_GENERIC179 339
#define AI_SEVENT_GENERIC180 340
#define AI_SEVENT_GENERIC181 341
#define AI_SEVENT_GENERIC182 342
#define AI_SEVENT_GENERIC183 343
#define AI_SEVENT_GENERIC184 344
#define AI_SEVENT_GENERIC185 345
#define AI_SEVENT_GENERIC186 346
#define AI_SEVENT_GENERIC187 347
#define AI_SEVENT_GENERIC188 348
#define AI_SEVENT_GENERIC189 349
#define AI_SEVENT_GENERIC190 350
#define AI_SEVENT_GENERIC191 351
#define AI_SEVENT_GENERIC192 352
#define AI_SEVENT_GENERIC193 353
#define AI_SEVENT_GENERIC194 354
#define AI_SEVENT_GENERIC195 355
#define AI_SEVENT_GENERIC196 356
#define AI_SEVENT_GENERIC197 357
#define AI_SEVENT_GENERIC198 358
#define AI_SEVENT_GENERIC199 359
#define AI_SEVENT_GENERIC200 360
#define AI_SEVENT_SCREENTREMOR 361
#define AI_MEVENT_ENEMYEXPLOSION10 362
#define AI_MEVENT_ENEMYEXPLOSION15 363
#define AI_MEVENT_ENEMYEXPLOSION20 364
#define AI_MEVENT_EXPLOSION20 365
#define AI_MEVENT_EXPLOSION30 366
#define AI_MEVENT_EXPLOSION50 367
#define AI_MEVENT_EXPLOSION100 368
#define AI_MEVENT_EXPLOSIONSPECIAL 369
#define AI_MEVENT_FREEZE 370
#define AI_SEVENT_GENERATE_PICKUP 371
#define AI_MEVENT_SMALLEXPLOSION30 372
#define AI_MEVENT_SHOVEWITHCAMERA 373
#define AI_MEVENT_BLADEHIT1 374
#define AI_MEVENT_BLADEHIT2 375
#define AI_MEVENT_BLADEHIT3 376
#define AI_MEVENT_BLADEHIT5 377
#define AI_MEVENT_BLADEHIT10 378
#define AI_MEVENT_BLADEHIT15 379
#define AI_MEVENT_BLADEHIT20 380
#define AI_MEVENT_BLADEHIT30 381
#define AI_MEVENT_BLADEHIT40 382
#define AI_MEVENT_BLADEHIT50 383
#define AI_MEVENT_BLADEHIT100 384
#define AI_MEVENT_KICKHIT1 385
#define AI_MEVENT_KICKHIT2 386
#define AI_MEVENT_KICKHIT3 387
#define AI_MEVENT_KICKHIT5 388
#define AI_MEVENT_KICKHIT10 389
#define AI_MEVENT_KICKHIT15 390
#define AI_MEVENT_KICKHIT20 391
#define AI_MEVENT_KICKHIT30 392
#define AI_MEVENT_KICKHIT40 393
#define AI_MEVENT_KICKHIT50 394
#define AI_MEVENT_KICKHIT100 395
#define AI_MEVENT_SHOTGUNEXPLOSION 396
#define AI_MEVENT_TEKBOWEXPLOSION 397
#define AI_SEVENT_BOUNCY_ROCK 398
#define AI_SEVENT_BOUNCY_ALIEN_HEAD 399
#define AI_SEVENT_BOUNCY_ALIEN_HAND 400
#define AI_SEVENT_BOUNCY_ALIEN_FOOT 401
#define AI_SEVENT_BOUNCY_ALIEN_TORSO 402
#define AI_SEVENT_BOUNCY_LEAPER_HEAD 403
#define AI_SEVENT_BOUNCY_LEAPER_HAND 404
#define AI_SEVENT_BOUNCY_LEAPER_FOOT 405
#define AI_SEVENT_BOUNCY_LEAPER_TORSO 406
#define AI_SEVENT_INSTANTDEATH 407
#define AI_SEVENT_GENERIC201 408
#define AI_SEVENT_GENERIC202 409
#define AI_SEVENT_GENERIC203 410
#define AI_SEVENT_GENERIC204 411
#define AI_SEVENT_GENERIC205 412
#define AI_SEVENT_GENERIC206 413
#define AI_SEVENT_GENERIC207 414
#define AI_SEVENT_GENERIC208 415
#define AI_SEVENT_GENERIC209 416
#define AI_SEVENT_GENERIC210 417
#define AI_SEVENT_GENERIC211 418
#define AI_SEVENT_GENERIC212 419
#define AI_SEVENT_GENERIC213 420
#define AI_SEVENT_GENERIC214 421
#define AI_SEVENT_GENERIC215 422
#define AI_SEVENT_GENERIC216 423
#define AI_SEVENT_GENERIC217 424
#define AI_SEVENT_GENERIC218 425
#define AI_SEVENT_GENERIC219 426
#define AI_SEVENT_GENERIC220 427
#define AI_SEVENT_GENERIC221 428
#define AI_SEVENT_GENERIC222 429
#define AI_SEVENT_GENERIC223 430
#define AI_SEVENT_GENERIC224 431
#define AI_SEVENT_GENERIC225 432
#define AI_SEVENT_GENERIC226 433
#define AI_SEVENT_GENERIC227 434
#define AI_SEVENT_GENERIC228 435
#define AI_SEVENT_GENERIC229 436
#define AI_SEVENT_GENERIC230 437
#define AI_SEVENT_GENERIC231 438
#define AI_SEVENT_GENERIC232 439
#define AI_SEVENT_GENERIC233 440
#define AI_SEVENT_GENERIC234 441
#define AI_SEVENT_GENERIC235 442
#define AI_SEVENT_GENERIC236 443
#define AI_SEVENT_GENERIC237 444
#define AI_SEVENT_GENERIC238 445
#define AI_SEVENT_GENERIC239 446
#define AI_SEVENT_GENERIC240 447
#define AI_SEVENT_GENERIC241 448
#define AI_SEVENT_GENERIC242 449
#define AI_SEVENT_GENERIC243 450
#define AI_SEVENT_GENERIC244 451
#define AI_SEVENT_GENERIC245 452
#define AI_SEVENT_GENERIC246 453
#define AI_SEVENT_GENERIC247 454
#define AI_SEVENT_GENERIC248 455
#define AI_SEVENT_GENERIC249 456
#define AI_SEVENT_GENERIC250 457
#define AI_SEVENT_GENERIC251 458
#define AI_SEVENT_GENERIC252 459
#define AI_SEVENT_GENERIC253 460
#define AI_SEVENT_GENERIC254 461
#define AI_SEVENT_GENERIC255 462
#define AI_SEVENT_GENERIC256 463
#define AI_SEVENT_GENERIC257 464
#define AI_SEVENT_GENERIC258 465
#define AI_SEVENT_GENERIC259 466
#define AI_SEVENT_GENERIC260 467
#define AI_SEVENT_RANDOM_BIG_SWOOSH_SOUND 468
#define AI_SEVENT_RANDOM_SMALL_SWOOSH_SOUND 469
#define AI_SEVENT_RANDOM_GRUNT_SOUND 470
#define AI_MEVENT_PARTICLE_HIT1 471
#define AI_SEVENT_START_FIRE_SOUND 472
#define AI_SEVENT_STOP_FIRE_SOUND 473

#define AI_EVENT_TYPES 474

extern char *AI_Event_Strings[];


#define AI_SPECIES_RAPTOR (1<<0)
#define AI_SPECIES_HUMAN1 (1<<1)
#define AI_SPECIES_SABERTIGER (1<<2)
#define AI_SPECIES_DIMETRODON (1<<3)
#define AI_SPECIES_TRICERATOPS (1<<4)
#define AI_SPECIES_MOSCHOPS (1<<5)
#define AI_SPECIES_PTERANODON (1<<6)
#define AI_SPECIES_SUBTERRANEAN (1<<7)
#define AI_SPECIES_LEAPER (1<<8)
#define AI_SPECIES_ALIEN (1<<9)
#define AI_SPECIES_HULK (1<<10)
#define AI_SPECIES_ROBOT (1<<11)

#define AI_SPECIES_ALL 0xffffffff



#define AI_HEALTH_PLAYER 100
#define AI_HEALTH_PLAYER_MAX 120


#define AI_HITS_EXPLOSION 50
#define AI_HITS_SHOCKWAVE 10



#define AI_COLLISION (1<<0)
#define AI_BEINGATTACKED (1<<1)
#define AI_EXPLOSION (1<<2)
#define AI_CYCLECOMPLETED (1<<3)
#define AI_WAITFOR_CYCLE (1<<4)
#define AI_EV_QUIETNOISE (1<<5)
#define AI_EV_LOUDNOISE (1<<6)
#define AI_EV_GETATTN (1<<7)
#define AI_EV_SEETARGET (1<<8)
#define AI_FIRST_ATTACK (1<<9)
#define AI_EV_HIT (1<<10)
#define AI_EV_EXPLOSION (1<<11)
#define AI_ALREADY_DEAD (1<<12)
#define AI_RUNNING (1<<13)
#define AI_NOREPEATEXP (1<<14)
#define AI_FLOCKING (1<<15)
#define AI_RESURRECTION (1<<16)
#define AI_FEIGNDEATH (1<<17)
#define AI_STARTED (1<<18)
#define AI_DOORPREOPEN (1<<19)
#define AI_DOOROPEN (1<<20)
#define AI_TELEPORTING (1<<21)
#define AI_TELEPORTAWAY (1<<22)
#define AI_TELEPORTMOVESLOW (1<<23)
#define AI_INTERACTIVEANIMATION (1<<24)
#define AI_GOBACKTOLEASH (1<<25)
#define AI_INTERANIMDELAY (1<<26)
#define AI_REGENERATE (1<<27)
#define AI_REGENERATEINTERANIM (1<<28)
#define AI_EXPTARGETEXPLODED (1<<29)
#define AI_WOUNDEDMORTALLY (1<<30)

#define AI_VALID (1<<31)



#define AI_HOLDINTANIMON1STFRAME (1<<0)
#define AI_REGENERATEAPPEARANCEDELAY (1<<1)
#define AI_KILLOUTSIDEOFVIEW (1<<2)
#define AI_GENERATED_PICKUPS (1<<3)
#define AI_VISIBLE (1<<4)
#define AI_IGNORESOUNDEVENTS (1<<5)





#define AI_TYPE_COLLISION (1<<0)
#define AI_TYPE_PROJECTILEWEAPON1 (1<<1)
#define AI_TYPE_LEADER (1<<2)
#define AI_TYPE_TRACKGROUND (1<<3)
#define AI_TYPE_EXPLOSIONDEATH (1<<4)
#define AI_TYPE_CLIMBER (1<<5)
#define AI_TYPE_PROJECTILEWEAPON2 (1<<6)
#define AI_TYPE_NOREPEATEXPLOSION (1<<7)
#define AI_TYPE_DIEONEXPLOSION (1<<8)
#define AI_TYPE_FLOCKER (1<<9)
#define AI_TYPE_SLOWENEMY (1<<10)
#define AI_TYPE_RANDOMRESURRECTION (1<<11)
#define AI_TYPE_RANDOMFEIGNDEATH (1<<12)
#define AI_TYPE_KAMIKAZE (1<<13)
#define AI_TYPE_AVOIDPLAYER (1<<14)
#define AI_TYPE_FLOATINWATERONDEATH (1<<15)
#define AI_TYPE_TELEPORT (1<<16)
#define AI_TYPE_SHADOW (1<<17)
#define AI_TYPE_TELEPORTMOVESLOW (1<<18)
#define AI_TYPE_USESTRONGATTACKS (1<<19)
#define AI_TYPE_USEWEAKATTACKS (1<<20)
#define AI_TYPE_SNIPER (1<<21)
#define AI_TYPE_MELTINGDEATH (1<<22)
#define AI_TYPE_AVOIDWATER (1<<23)
#define AI_TYPE_FLYING (1<<24)
#define AI_TYPE_TELEPORTAVOIDWATER (1<<25)
#define AI_TYPE_TELEPORTAVOIDCLIFFS (1<<26)
#define AI_TYPE_USEPRESSUREPLATES (1<<27)
#define AI_TYPE_CANNOTCAUSEAFIGHT (1<<28)
#define AI_TYPE_NOWALLCOLLISION (1<<29)
#define AI_TYPE_DEVICESCREENSHAKE (1<<30)
#define AI_TYPE_REPLAYINTANIMONREG (1<<31)


#define AI_TYPE2_PICKUP_EXPLOSIVESHELLS (1<<0)
#define AI_TYPE2_PICKUP_GRENADE (1<<1)
#define AI_TYPE2_PICKUP_HEALTH10 (1<<2)
#define AI_TYPE2_PICKUP_HEALTH100 (1<<3)
#define AI_TYPE2_PICKUP_HEALTH100PLUS (1<<4)
#define AI_TYPE2_PICKUP_HEALTH2 (1<<5)
#define AI_TYPE2_PICKUP_HEALTH25 (1<<6)
#define AI_TYPE2_PICKUP_MINIGUNSHELLS (1<<7)
#define AI_TYPE2_PICKUP_MORTALWOUND (1<<8)
#define AI_TYPE2_PICKUP_ROCKETS (1<<9)
#define AI_TYPE2_PICKUP_SHOTGUNSHELLS (1<<10)
#define AI_TYPE2_PICKUP_BATTERYLARGE (1<<11)
#define AI_TYPE2_PICKUP_BATTERYSMALL (1<<12)
#define AI_TYPE2_PICKUP_BULLETCLIP (1<<13)
#define AI_TYPE2_INSTANTDEATH (1<<14)
#define AI_TYPE2_NOBLOOD (1<<15)
#define AI_TYPE2_HOLDINTANIMON1STFRAME (1<<16)
#define AI_TYPE2_PROJECTILEWEAPON7 (1<<17)
#define AI_TYPE2_PROJECTILEWEAPON8 (1<<18)
#define AI_TYPE2_DOPICKUPONDAMAGE (1<<19)
#define AI_TYPE2_DONTDRAWONMAP (1<<20)
#define AI_TYPE2_USE2NDSETOFMOVES (1<<21)
#define AI_TYPE2_ANTIALIASING_REDUCED (1<<22)
#define AI_TYPE2_ANTIALIASING_FULL (1<<23)
#define AI_TYPE2_PROJECTILEWEAPON5 (1<<24)
#define AI_TYPE2_PROJECTILEWEAPON6 (1<<25)
#define AI_TYPE2_SARROWMORTALWOUND (1<<26)
#define AI_TYPE2_STAYINWATER (1<<27)
#define AI_TYPE2_DEVICEWARPDEATH (1<<28)
#define AI_TYPE2_STOREWARPRETURN (1<<29)
#define AI_TYPE2_PROJECTILEWEAPON3 (1<<30)
#define AI_TYPE2_PROJECTILEWEAPON4 (1<<31)

#define AI_TYPE3_RETURNWARP (1<<0)
#define AI_TYPE3_SHOWINTANIMONCE (1<<1)
#define AI_TYPE3_REGENERATEFROMSTART (1<<2)
#define AI_TYPE3_WALKINSTRAIGHTLINE (1<<3)
#define AI_TYPE3_KILLOUTSIDEOFVIEW (1<<4)
#define AI_TYPE3_DUMB (1<<5)
#define AI_TYPE3_AVOIDPLAYER2 (1<<6)
#define AI_TYPE3_DONTDOVIOLENTDEATH (1<<7)
#define AI_TYPE3_PROJECTILEWEAPON9 (1<<8)
#define AI_TYPE3_PROJECTILEWEAPON10 (1<<9)
#define AI_TYPE3_MAKEINTANIMVISIBLE (1<<10)
#define AI_TYPE3_DONTDRAWONCINEMA (1<<11)





#define AI_EVADE_NONE 0
#define AI_EVADE_START 1
#define AI_EVADE_TURN 2
#define AI_EVADE_MOVE 3
#define AI_EVADE_FACETUROK 4



#define APPEARANCE_LENGTH (0.5*FRAME_FPS)
#define APPEARANCEWHITE_LENGTH (1.2*FRAME_FPS)
#define MELT_LENGTH (4.0*FRAME_FPS)



#define AI_KNIFE_LEFT_ATTACK 0
#define AI_KNIFE_RIGHT_ATTACK 1
#define AI_KNIFE_FORWARD_ATTACK 2
#define AI_TOMAHAWK_LEFT_ATTACK 3
#define AI_TOMAHAWK_RIGHT_ATTACK 4
#define AI_TOMAHAWK_FORWARD_ATTACK 5

#define AI_MORTAL_WOUND_KT_HITS 30
#define AI_MORTAL_DEATH_KT_HITS 999


#define AI_NOT_NEAR_WATER 0
#define AI_BELOW_WATERSURFACE 1
#define AI_ABOVE_WATERSURFACE 2
#define AI_ON_WATERSURFACE 3


#define AI_RETREAT_TIME 5.0
#define AI_MAX_SWIMTURN 50.0
#define AI_MAX_TELEPORTTURN 50.0


#define AI_FREEZE_START 3.0
#define AI_FREEZE_FADETOBLACK 2.7
#define AI_FREEZE_FADETOBLACKEND 1.2
#define AI_FREEZE_END -1.0
#define AI_FREEZE_GOINGTOEXPLODE -2.0
#define AI_FREEZE_ENDED -3.0



typedef struct CEnemyAttributes_t
{
 float m_SightRadius,
     m_SightAngle,
     m_LoudRadius,
     m_QuietRadius,
     m_ProjectileRadius,
     m_FlyingHeight,
     m_CollisionRadius,
     m_CollisionWallRadius,
     m_CollisionHeight,
     m_DeadHeight,
     m_AttackRadius,
     m_LeashRadius,
     m_InteractiveAnimDelay;
 unsigned long m_dwSpecies,
     m_dwTypeFlags,
     m_dwTypeFlags2;
 unsigned short m_wTypeFlags3;

 short m_StartHealth,
     m_Id,
     m_DeathId,
     m_Regenerate;

 unsigned char m_Aggression,
     m_InteractiveAnim,
     m_nModel;
 signed char m_nTexture,
     m_AttackStyle;
 unsigned char unused1;
} CEnemyAttributes;







void func_80083E20(CEnemyAttributes *pThis);



typedef struct CAIDynamic_t
{
 float m_ViewAngleOffset,
     m_RetreatTimer,
     m_TeleportTime,
     m_Time1,
     m_Time2,
     m_InteractiveTimer,
     m_AvoidanceAngle,
     m_cRegenerateAppearance,
     m_cRegenerateAppearanceWhite,
     m_MeltTimer,
     m_FreezeTimer;
 unsigned long m_dwStatusFlags,
     m_dwStatusFlags2;
 short m_Agitation,
     m_PrevAgitation,
     m_Health,

     m_Evade,
     m_Regenerate;
 CVector3 m_vExplosion,
     m_vLeashCoor,
     m_vStartPos;
 int m_Invincible,
     m_FirstRun;
 int m_DeathAnimType;
 struct CGameRegion_t *m_pStartRegion;
 short m_HeadTexture,
     m_BodyTexture ;
 short m_WeaponModel,
     m_ExtraModel ;

} CAIDynamic;




void func_80083F00(CAIDynamic *pThis, CEnemyAttributes *pEA, CVector3 vStartPos, struct CGameObjectInstance_t *pInstance);
void func_80084364(CAIDynamic *pThis, CEnemyAttributes *pEA);
void func_80084460(CAIDynamic *pThis, CEnemyAttributes *pEA);
void func_8008453C(CAIDynamic *pThis, CEnemyAttributes *pEA, int nTypeFlag);
void func_800842CC(CAIDynamic *pThis, CEnemyAttributes *pEA, int nObjtype);
void func_800840C4(CAIDynamic *pThis, CEnemyAttributes *pEA, struct CGameObjectInstance_t *pInstance) ;









struct CCollisionInfo2_t;



#define FLOAT2INT16(floatValue,maxValue) ( (short) ((floatValue)*32767.0f/(maxValue)) )
#define INT162FLOAT(intValue,maxValue) ( (float) ((intValue)*((float)(maxValue))/32767.0f) )

#define FLOAT2INT32(floatValue,maxValue) ( (long) ((floatValue)*2147483648.0f/(maxValue)) )
#define INT322FLOAT(intValue,maxValue) ( (float) ((intValue)*((float)(maxValue))/2147483648.0f) )

#define FLOAT2INT8(floatValue,maxValue) ( (signed char) ((floatValue)*127.0f/(maxValue)) )
#define INT82FLOAT(intValue,maxValue) ( (float) ((intValue)*((float)(maxValue))/127.0f) )

typedef unsigned short SF;

SF func_80021B9C(float fValue);
float func_8001F298(SF sfValue);



typedef struct CROMCornerEnc_t
{
 long x, y, z, c;
} CROMCornerEnc;

typedef struct CROMCorner_t
{
   CVector3 m_vCorner;
   float m_Ceiling;
} CROMCorner;

typedef struct CROMRegion_t
{
 unsigned short m_nRegionSet,
       m_wFlags;
   unsigned short m_Corners[3],
       m_Neighbors[3];
} CROMRegion;

typedef struct CGameRegion_t
{
 unsigned short m_nRegionSet,
        m_wFlags;
 CROMCorner *m_pCorners[3];
 struct CGameRegion_t *m_pNeighbors[3];
} CGameRegion;




void func_80021AB4(CGameRegion *pThis, CROMRegion *pSource,
                CROMCorner Corners[], CGameRegion Regions[]);

CVector3 func_80019C78(CGameRegion *pThis);
CVector3 func_80019E30(CGameRegion *pThis);
float func_80019D3C(CGameRegion *pThis, float X, float Z);
CVector3 CGameRegion__GetCeilingNormal(CGameRegion *pThis);
CVector3 func_800208FC(CGameRegion *pThis);
float func_80021348(CGameRegion *pThis, float X, float Z);
CVector3 func_800211F8(CGameRegion *pThis, float Gravity);
float func_80021138(CGameRegion *pThis,
                float StartX, float StartZ,
                float EndX, float EndZ);
float func_8001AA68(CGameRegion *pThis,
               float StartX, float StartZ,
               float EndX, float EndZ);
int CGameRegion__InRegion(CGameRegion *pThis, float X, float Z);




unsigned long func_800210FC(CGameRegion *pThis);
unsigned long func_800210C0(CGameRegion *pThis);
int func_80020F44(CGameRegion *pThis, CVector3 *pvStart, CVector3 *pvEnd, float *Out);
int CGameRegion__GetCeilingIntersection(CGameRegion *pThis, CVector3 *pvStart, CVector3 *pvEnd, float *Out);
int CGameRegion__CalculateWaterIntersection(CGameRegion *pThis, CVector3 *pvStart, CVector3 *pvEnd, float *Out);
CQuatern func_80020B28(CGameRegion *pThis);
CQuatern func_800209A4(CGameRegion *pThis);
float func_800206E4(CGameRegion *pThis, int nEdge);
float func_80020638(CGameRegion *pThis);
#define CGameRegion__IsDoorOpen(pThis) ((pThis)->m_wFlags & REGFLAG_OPENDOOR)
void CGameRegion__OpenDoor(CGameRegion *pThis);
void CGameRegion__CloseDoor(CGameRegion *pThis);
void func_800218A4(CGameRegion *pThis) ;
void func_800217A0(CGameRegion *pThis) ;
void func_800216E0(CGameRegion *pThis);
void func_8002169C(CGameRegion *pThis);
void func_800215C8(CGameRegion *pThis) ;
void func_8002165C(CGameRegion *pThis) ;
void func_80021618(CGameRegion *pThis) ;
void func_80021508(CGameRegion *pThis, float Height);
int func_80019ED8(CGameRegion *pThis);
CGameRegion* func_8001E2F8(CGameRegion *pThis, CVector3 vPos);



typedef struct CROMBounds_t
{
 CVector3 m_vMin, m_vMax;
} CROMBounds;







void CROMBounds__Print(CROMBounds *pThis);



typedef struct CBoundsRect_t
{
 float m_MinX, m_MinZ,
      m_MaxX, m_MaxZ;
} CBoundsRect;







#define CBoundsRect__IsOverlapping(pThis,pCompare) (((pThis)->m_MaxX > (pCompare)->m_MinX) && ((pThis)->m_MinX < (pCompare)->m_MaxX) && ((pThis)->m_MaxZ > (pCompare)->m_MinZ) && ((pThis)->m_MinZ < (pCompare)->m_MaxZ))


#define CBoundsRect__IsOverlappingBounds(pThis,pCompare) (((pThis)->m_MaxX > (pCompare)->m_vMin.x) && ((pThis)->m_MinX < (pCompare)->m_vMax.x) && ((pThis)->m_MaxZ > (pCompare)->m_vMin.z) && ((pThis)->m_MinZ < (pCompare)->m_vMax.z))


#define CBoundsRect__InRect(pThis,pVector3) (((pVector3)->x >= (pThis)->m_MinX) && ((pVector3)->x <= (pThis)->m_MaxX) && ((pVector3)->z >= (pThis)->m_MinZ) && ((pVector3)->z <= (pThis)->m_MaxZ))


void CBoundsRect__EncloseVectors(CBoundsRect *pThis, int nPts, CVector3 V[]);
void func_800188C8(CBoundsRect *pThis, int nPts, CVector3 V[]);
void CBoundsRect__Print(CBoundsRect *pThis);



typedef struct CROMRegionBlock_t
{
 CBoundsRect m_BoundsRect;
 unsigned long m_nRegions;
} CROMRegionBlock;

typedef struct CROMGridBounds_t
{
 CBoundsRect m_BoundsRect;
} CROMGridBounds;

typedef struct CGameGridBounds_t
{
 CBoundsRect m_BoundsRect;
 CCacheEntry *m_pceGridSection;
} CGameGridBounds;





void func_80020600(CGameGridBounds *pThis, CROMGridBounds *pSource);

#define I_STATIC 0
#define I_ANIMATED 1
#define I_PARTICLE 2
#define I_SIMPLE 3
typedef struct CInstanceHdr_t
{
 unsigned char m_Type,
       m_bActiveFlags;
 unsigned short m_nObjType;
 CVector3 m_vPos;
 float m_CollisionHeightOffset;
 CGameRegion *m_pCurrentRegion;
 CEnemyAttributes *m_pEA;
} CInstanceHdr;




CQuatern func_8001D5C8(CInstanceHdr *pThis, CVector3 vPos);
int func_8001BA24(CInstanceHdr *pThis);
int func_8001D3DC(CInstanceHdr *pThis);
#define CInstanceHdr__DoSoundEffect(pThis,nSoundType,Looping) func_80031974(&GetApp()->m_Scene, nSoundType, Looping, pThis, &(pThis)->m_vPos, 0)
void func_80017F0C(CInstanceHdr *pThis,
                CVector3 vDesiredPos,
                CVector3 *pvOutPos, CGameRegion **ppOutRegion,
                int GroundBehavior, int InstanceBehavior);
int func_80018B08(CInstanceHdr *pThis);
float func_8001D240(CInstanceHdr *pThis, int ToTop, float TestDistance);
CQuatern func_8001ABB8(CInstanceHdr *pThis);
int func_80015E44(CInstanceHdr *pThis, int nNode);
int func_80015F50(CInstanceHdr *pThis, int nNode);
int func_80016324(CInstanceHdr *pThis, int nType, int nNode);
int func_8001D398(CInstanceHdr *pThis);
#define CInstanceHdr__GetGroundHeight(pThis) func_80019D3C((pThis)->m_pCurrentRegion, (pThis)->m_vPos.x, (pThis)->m_vPos.z)




typedef struct CAnimInstanceHdr_t
{
 CInstanceHdr ih;

 CVector3 m_vVelocity;

} CAnimInstanceHdr;

int func_8001DF50(CAnimInstanceHdr *pThis,
                CVector3 vDesired,
                struct CCollisionInfo2_t **ppCIUsed );
int CAnimInstanceHdr__CastYeThyRay(CAnimInstanceHdr *pThis, CInstanceHdr *pTarget);
void func_8001E080(CAnimInstanceHdr *pThis, float X, float Z);
#define CAnimInstanceHdr__GetVelocityRotation(pThis) func_80013C58(&(pThis)->m_vVelocity)





typedef struct CROMSimpleInstance_t
{
 CVector3 m_vPos;
 float m_MaxRadius;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation,
      m_wFlags,
      m_nID;
 signed char m_RotY;
 unsigned char m_bActiveFlags;
} CROMSimpleInstance;

#define SIMPLE_FLAG_GONE (1 << 0)
#define SIMPLE_FLAG_VISIBLE (1 << 1)
#define SIMPLE_FLAG_WARP_DYNAMIC (1 << 2)
#define SIMPLE_FLAG_DYNAMIC (1 << 3)
#define SIMPLE_FLAG_SCALEUP (1 << 4)
#define SIMPLE_FLAG_TRANSPARENCY (1 << 5)
#define SIMPLE_FLAG_CLOSEDWARP (1 << 6)




typedef struct CGameSimpleInstance_t
{
 CAnimInstanceHdr ah;

   CCacheEntry *m_pceObjectIndex,
       *m_pceStaticEvents;
 ROMAddress *m_rpObjectIndexAddress;

 Mtx m_mOrientation[2],
       m_mShadow[2];
 CGeometry m_Geometry;

 CVector3 vRotAxis ;
 float m_RotAngle, m_AngleVel;

 CROMBounds m_Bounds;
 float m_Scale, m_OffsetY;
 unsigned short m_wFlags,
       m_nID;
 float m_Time, m_MorphInc;
} CGameSimpleInstance;




void CGameSimpleInstance__TakeFromROMSimpleInstance(CGameSimpleInstance *pThis, CROMSimpleInstance *pSource,
                    ROMAddress *rpObjectAddress,
                    CGameRegion Regions[], CEnemyAttributes Variations[]);
void func_8002007C(CGameSimpleInstance *pThis, Gfx **ppDLP,
             CCartCache *pCache, CCacheEntry *pceTextureSetsIndex);
CQuatern CGameSimpleInstance__GetAimRotation(CGameSimpleInstance *pThis);




typedef struct CROMEfficientStaticInstance_t
{
 float m_Scale;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation,
      m_wFlags;


#define EFFICIENT_Y_ACCURACY 0.5
 short m_nPosY;
#define EFFICIENT_ROT_0 0
#define EFFICIENT_ROT_90 1
#define EFFICIENT_ROT_180 2
#define EFFICIENT_ROT_270 3
#define EFFICIENT_ROT_MASK (EFFICIENT_ROT_0 | EFFICIENT_ROT_90 | EFFICIENT_ROT_180 | EFFICIENT_ROT_270)
#define EFFICIENT_FLAGS_POSX_NEG (1 << 4)
#define EFFICIENT_FLAGS_POSZ_NEG (1 << 5)
 unsigned char m_bFlags,
      m_bActiveFlags,
      m_nPosX, m_nPosZ;
 signed char m_nMinX, m_nMaxX,
      m_nMinY, m_nMaxY,
      m_nMinZ, m_nMaxZ;
} CROMEfficientStaticInstance;

typedef struct CROMStaticInstance_t
{
   CVector3 m_vPos,
      m_vScale;
 SF m_BoundsMinX, m_BoundsMinY, m_BoundsMinZ,
      m_BoundsMaxX, m_BoundsMaxY, m_BoundsMaxZ;
 unsigned short m_nObjType,
      m_nCurrentRegion,
      m_nVariation;
 unsigned char m_bFlags,
      m_bActiveFlags;
 signed char m_RotX, m_RotY, m_RotZ, m_RotT;
} CROMStaticInstance;

#define STATIC_INSTANCE_GEOMVER0 (1 << 0)
#define STATIC_INSTANCE_GEOMVER1 (1 << 1)
#define STATIC_INSTANCE_GEOMVER_MASK (STATIC_INSTANCE_GEOMVER0 | STATIC_INSTANCE_GEOMVER1)

#define STATIC_INSTANCE_TRANSPARENCY (1 << 2)
#define STATIC_INSTANCE_HASEVENTS (1 << 3)

typedef struct CGameStaticInstance_t
{
 CInstanceHdr ih;

   CCacheEntry *m_pceObjectIndex,
       *m_pceStaticEvents;
 ROMAddress *m_rpObjectIndexAddress;



 Mtx m_mOrientation;
 CGeometry m_Geometry;

 CROMBounds m_Bounds;
 unsigned long m_dwFlags;
} CGameStaticInstance;





void CGameStaticInstance__TakeFromROMEfficientStaticInstance(CGameStaticInstance *pThis, CROMEfficientStaticInstance *pSource,
                       ROMAddress *rpObjectAddress,
                       CGameRegion Regions[], CEnemyAttributes Variations[],
                       float GridDistance);
void CGameStaticInstance__TakeFromROMStaticInstance(CGameStaticInstance *pThis, CROMStaticInstance *pSource,
                    ROMAddress *rpObjectAddress,
                    CGameRegion Regions[], CEnemyAttributes Variations[]);
void CGameStaticInstance__Draw(CGameStaticInstance *pThis, Gfx **ppDLP,
               CCartCache *pCache, CCacheEntry *pceTextureSetsIndex);
void func_8001EEB0(CGameStaticInstance *pThis, CCartCache *pCache, int ConstantRateFrame);




typedef struct CROMObjectInstance_t
{
 unsigned short m_nObjType,
     m_nTypeFlag,
     m_nVariation,
     m_nCurrentRegion;
 signed short m_RotY;
 unsigned char m_bFlags,
     m_bActiveFlags;
 CVector3 m_vPos,
     m_vScale;
} CROMObjectInstance;

#define ANIM_INSTANCE_DEVICE (1 << 0)
#define ANIM_INSTANCE_TRANSPARENCY (1 << 1)

#define ANIM_INSTANCE_VISIBLE (1 << 16)
#define ANIM_INSTANCE_BLENDING (1 << 17)
#define ANIM_INSTANCE_ANIMCHANGED (1 << 18)
#define ANIM_INSTANCE_NEAREDGE (1 << 19)
#define ANIM_INSTANCE_HANGINGON (1 << 20)
#define ANIM_INSTANCE_GONE (1 << 21)
#define ANIM_INSTANCE_FIRSTBLENDFR (1 << 22)
#define ANIM_INSTANCE_BLENDTORIGHT (1 << 23)

typedef struct CGameObjectInstance_t
{
 CAnimInstanceHdr ah;

   CVector3 m_vScale;
 CQuatern m_qRot,
        m_qGround,
        m_qShadow;
 float m_RotY,
        m_cMelt,
        m_ShadowPercentage;




 Mtx m_mOrientation[2];
 CGeometry m_Geometry;
 Mtx *pmtDrawMtxs ;


 ROMAddress *m_rpObject,
        *m_rpObjectInfo,
        *m_rpAnims;
 CCacheEntry *m_pceObjectIndex,
        *m_pceObjectInfo,
        *m_pceAnimsHeader,
        *m_pceAnimsIndex;
 unsigned short m_ObjectInfoSize,
        m_nTypeFlag;

 short m_nAnims,
        m_nDesiredAnim;
 CBoundsRect m_BoundsRect;

 unsigned long m_dwFlags;

 CGameAnimateState m_asCurrent,
        m_asBlend;
 short m_BlendLength,
        m_WaitingForAnim,
        m_StartupAnimType;

 signed short m_Mode ;

 float m_ModeTime ;
 float m_ModeMisc1 ;

 float m_uBlender,
        m_BlendPos;

 struct CBoss_t *m_pBoss ;

 void (*m_pCollisionFunction)(void *pThis, struct CCollisionInfo2_t *pCollisionInfo) ;
 CQuatern(*m_pCalculateOrientation)(void *pThis) ;

 unsigned char m_BlendStart,
         m_BlendFinish;


 signed short m_ActiveSwooshes ;

 float m_HeadTrackBlend ;

 float m_HeadTurnAngle ;
 float m_HeadTurnAngleVel ;

 float m_HeadTiltAngle ;
 float m_HeadTiltAngleVel ;

 struct CHeadTrackInfo_t *m_pHeadTrackInfo ;


 CAIDynamic m_AI;
 struct CGameObjectInstance_t *m_pEventCGameObjectInstance;
 struct CGameObjectInstance_t *m_pAttackerCGameObjectInstance;

} CGameObjectInstance;




enum CGameObjectInstanceModes
{
 IDLE_MODE,
 TRANS_FADE_OUT_MODE,
 END_OF_MODES
} ;





typedef struct CAnimDraw_t
{
   Gfx **ppDLP;
   CIndexedSet *pisNodes,
                        *pisCurrentAnim,
                        *pisBlendAnim;
   int RemoveRootXZ,
                        Better,
        Inter;
} CAnimDraw;





void CGameObjectInstance__TakeFromROMObjectInstance(CGameObjectInstance *pThis, CROMObjectInstance *pSource,
                    CGameRegion Regions[], CEnemyAttributes Variations[]);

#define CGameObjectInstance__GetOrientationMatrix(pThis) ((pThis)->m_mOrientation[D_800B6AF4])

#define CGameObjectInstance__IsVisible(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_VISIBLE)
#define CGameObjectInstance__SetVisible(pThis) ((pThis)->m_dwFlags |= ANIM_INSTANCE_VISIBLE)
#define CGameObjectInstance__SetNotVisible(pThis) ((pThis)->m_dwFlags &= ~ANIM_INSTANCE_VISIBLE)

#define CGameObjectInstance__IsBlending(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_BLENDING)
#define CGameObjectInstance__SetBlending(pThis) ((pThis)->m_dwFlags |= ANIM_INSTANCE_BLENDING)
#define CGameObjectInstance__SetNotBlending(pThis) ((pThis)->m_dwFlags &= ~ANIM_INSTANCE_BLENDING)

#define CGameObjectInstance__IsAnimChanged(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_ANIMCHANGED)
#define CGameObjectInstance__SetAnimChanged(pThis) ((pThis)->m_dwFlags |= ANIM_INSTANCE_ANIMCHANGED)
#define CGameObjectInstance__SetAnimNotChanged(pThis) ((pThis)->m_dwFlags &= ~ANIM_INSTANCE_ANIMCHANGED)

#define CGameObjectInstance__IsGone(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_GONE)
#define CGameObjectInstance__SetGone(pThis) ((pThis)->m_dwFlags |= ANIM_INSTANCE_GONE)
#define CGameObjectInstance__SetNotGone(pThis) ((pThis)->m_dwFlags &= ~ANIM_INSTANCE_GONE)

#define CGameObjectInstance__IsDevice(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_DEVICE)
#define CGameObjectInstance__HasTransparency(pThis) ((pThis)->m_dwFlags & ANIM_INSTANCE_TRANSPARENCY)

void CGameObjectInstance__CalculateOrientationMatrix(CGameObjectInstance *pThis, int FollowView, CVector3 vTCorners[8], CMtxF mfOrient);
void func_8001E990(CGameObjectInstance *pThis, int nAnim);
void func_8001E93C(CGameObjectInstance *pThis);
int CGameObjectInstance__LookupAIAnimType(CGameObjectInstance *pThis, int nType);
int func_8001C348(CGameObjectInstance *pThis, int nItems, int AITypes[], int Weights[], int *pPickedType);
int func_8001E9B8(CGameObjectInstance *pThis, int nItems, int Info[][3], int *pPickedType);
#define CGameObjectInstance__GetCurrentAnim(pThis) ((pThis)->m_asCurrent.m_nAnim)
#define CGameObjectInstance__IsModelLoaded(pThis) CGeometry__IsModelLoaded(&(pThis)->m_Geometry)
void CGameObjectInstance__Jerk(CGameObjectInstance *pThis);

#define CGameObjectInstance__IsCycleCompleted(pThis) CGameAnimateState__IsCycleCompleted(&(pThis)->m_asCurrent)

#define CGameObjectInstance__TypeFlag(pThis) ((pThis)->m_nTypeFlag)


void CGameObjectInstance__Reset(CGameObjectInstance *pThis,
              CIndexedSet *pisObjectsIndex, ROMAddress *rpObjectsAddress,
            int StartupAnimType);
void func_8001E660(CGameObjectInstance *pThis, Gfx **ppDLP);
void CGameObjectInstance__Draw(CGameObjectInstance *pThis, Gfx **ppDLP, CCacheEntry *pceTextureSetsIndex);

void CGameObjectInstance__GetOffsetPositionAndRegion(CGameObjectInstance *pThis,
                     CVector3 vDesiredOffset,
                     CVector3 *pvOutPos, CGameRegion **ppOutRegion);
CQuatern func_8001D464(CGameObjectInstance *pThis);
CQuatern func_8001D8F0(CGameObjectInstance *pThis, CVector3 vPos, CQuatern *pqFixResult, float Angle);
CVector3 func_8001D888(CGameObjectInstance *pThis, CVector3 vDirection);
void func_8001E7BC(CGameObjectInstance *pThis);
int func_8001E804(CGameObjectInstance *pThis);





typedef struct CROMGeometryInfo_t
{
 unsigned long unused;
} CROMGeometryInfo;

typedef struct CGameGeometryInfo_t
{
 unsigned long m_MorphFrameNumber;
 float m_cMorph;
} CGameGeometryInfo;




void func_8001E648(CGameGeometryInfo *pThis, CROMGeometryInfo *pSource);



typedef struct CROMInitialOrientation_t
{
   CVector3 m_vPos;


 signed short m_RotX, m_RotY, m_RotZ, m_RotT;
} CROMInitialOrientation;

typedef struct CROMNodeIndex_t
{
 short m_nTranslationSet,
    m_nRotationSet;
} CROMNodeIndex;

typedef struct CRotFrame_t
{

 signed short x, y, z, t;
} CRotFrame;

typedef struct CTranslationOffset_t
{
 int m_Compressed;
 CVector3 m_vOffset;
 float m_Scale;
} CTranslationOffset;

typedef struct CPosFrame_t
{
   CVector3 m_vPos;
} CPosFrame;

#define VERTEX_CACHE_SIZE 32


#define POLYSTREAM_VA_POS 0
#define POLYSTREAM_VB_POS 5
#define POLYSTREAM_VC_POS 10
#define POLYSTREAM_FLAGS_POS 15

#define POLYSTREAM_VA(val) ((val) << POLYSTREAM_VA_POS)
#define POLYSTREAM_GETVA(val) (((val) >> POLYSTREAM_VA_POS) & (VERTEX_CACHE_SIZE-1))

#define POLYSTREAM_VB(val) ((val) << POLYSTREAM_VB_POS)
#define POLYSTREAM_GETVB(val) (((val) >> POLYSTREAM_VB_POS) & (VERTEX_CACHE_SIZE-1))

#define POLYSTREAM_VC(val) ((val) << POLYSTREAM_VC_POS)
#define POLYSTREAM_GETVC(val) (((val) >> POLYSTREAM_VC_POS) & (VERTEX_CACHE_SIZE-1))

#define POLYSTREAM_LASTINRUN (0x1 << POLYSTREAM_FLAGS_POS)
#define POLYSTREAM_ISLASTINRUN(val) ((val) & POLYSTREAM_LASTINRUN)



typedef struct CROMSection_t
{
 unsigned long m_nTextureSet,
      m_dwMatFlags;
 unsigned char m_Color[4],
      m_BlackColor[4];
 unsigned short m_MultU, m_MultV;
} CROMSection;

typedef struct CGameSection_t
{
 unsigned long m_dwMatFlags;

 CTextureLoader m_TextureLoader;

 unsigned char m_Color[4],
      m_BlackColor[4];
 unsigned short m_MultU, m_MultV;
} CGameSection;




void CGameSection__TakeFromRomSection(CGameSection *pThis, CROMSection *pSource,
              CCacheEntry *pceTextureSetsIndex);



typedef struct CROMTextureFormat_t
{
#define TEXTURE_FORMAT_CI8_RGBA 0
#define TEXTURE_FORMAT_CI4_RGBA 1
#define TEXTURE_FORMAT_32_RGBA 2
#define TEXTURE_FORMAT_CI4_IA 3
#define TEXTURE_FORMAT_MM16RGBA 4
 unsigned char m_Format,
    m_PlaybackSpeed,
    m_WidthShift,
    m_HeightShift,
    m_Effect,
#define TEXTURE_EFFECT_NONE 0
#define TEXTURE_EFFECT_SHARPEN 1
#define TEXTURE_EFFECT_DETAIL_X2 2
#define TEXTURE_EFFECT_DETAIL_X4 3
    m_EffectMode;

} CROMTextureFormat;

#define LEVEL_STORE_MAP (1 << 0)
#define LEVEL_LOW_PRECISION (1 << 1)

typedef struct CROMLevel_t
{
 float m_GridDistance;
 unsigned char m_BlackColor[3],
      m_WhiteColor[3],
      m_DirectionalLight[3],
      m_AmbientLight[3],
      m_bFlags;
 signed char m_Direction[3];
} CROMLevel;

typedef struct CROMParticleImpact_t
{
 float m_ImpactEventNumber[14];
 unsigned short m_ImpactParticleType[14],
     m_ImpactEventType[14],
     m_ImpactSoundType[14];



} CROMParticleImpact;

typedef struct CROMParticleEffect_t
{
 CROMParticleImpact *m_pImpact;
 unsigned long m_dwFlags;
 SF m_BounceEnergy,
     m_DirectionSpray,
     m_SprayX,
     m_SprayY,
     m_SprayZ,
     m_DirectionX,
     m_DirectionY,
     m_DirectionZ,
     m_Gravity,
     m_GravityRandom,
     m_GroundFriction,
     m_FpsVelThreshold,
     m_AirFriction,
     m_WaterFriction,
     m_Size,
     m_SizeRandom,
     m_Scaler,
     m_ScalerRandom,
     m_Velocity,
     m_VelocityRandom,
     m_PosRandomX,
     m_PosRandomY,
     m_PosRandomZ,
     m_Rotation,
     m_RotationRandom,
     m_RotationInc,
     m_RotationIncRandom,
     m_RotationPivotX,
     m_RotationPivotY,
     m_PosX,
     m_PosY,
     m_PosZ;
 short m_nTextureSet,
     m_nParticles,
     m_nParticleRandom,
     m_nParticleFrames,
     m_nParticleFrameRandom,
     m_nParticleDelayFramesRandom;
 unsigned char m_FPS,
     m_InstanceBehavior,
     m_WallBehavior,
     m_GroundBehavior,
     m_Alignment,
     m_WhiteColor[3],
     m_BlackColor[3],
     m_RandomizeHue,
     m_RandomizeSaturation,
     m_RandomizeBrightness,
     m_Priority,
     m_Playback,
     m_Visibility,
     m_nFadeInDelay,
     m_nFadeOutDelay,
     unused;

} CROMParticleEffect;

typedef struct CROMWarpPoint_t
{
 CVector3 m_vPos;
 float m_RotY;
 unsigned short m_nLevel,
     m_nRegion;
} CROMWarpPoint;

typedef struct CROMRegionSet_t
{
 unsigned char m_FogColor[4],
     m_WaterColor[4];
 unsigned long m_FogStart,
     m_WaterStart;
 float m_FarClip,
     m_FieldOfView,
     m_WaterFarClip,
     m_WaterFieldOfView,
     m_WaterElevation,
     m_SkyElevation,
     m_SkySpeed,
     m_BlendLength,
     m_DeathTimeDelay;
 unsigned long m_dwFlags;
 unsigned short m_WarpID,
     m_PressurePlateSoundNumber,
     m_SaveCheckpointID,
     m_PressureID,
     m_DeathHitPoints;
 unsigned char m_GroundMat,
     m_WallMat,
     m_MusicID,
     m_AmbientSounds,
     m_MapColor,
     m_bActiveFlags;
} CROMRegionSet;

typedef struct CROMEnvelope_t
{
 SF m_MaxValue,
      m_StartFactor, m_EndFactor;
 unsigned short m_nDuration, m_EnvStartTime;





} CROMEnvelope;



typedef struct CROMSoundElement_t
{
 unsigned short m_nSampleNum,
      m_nDelayTime,
      m_Priority,
      m_wFlags,
      m_Probability;
 CROMEnvelope m_Volume,
      m_Pitch;
 unsigned char m_RadioVolume,
      unused2;

} CROMSoundElement;





#define _INC_PARTICLE 








#define _INC_COLLINFO 





#define _INC_UNICOL 






#define _INC_BEHAVIOR 



#define INTERSECT_BEHAVIOR_IGNORE 0
#define INTERSECT_BEHAVIOR_STICK 1
#define INTERSECT_BEHAVIOR_SLIDE 2
#define INTERSECT_BEHAVIOR_BOUNCE 3
#define INTERSECT_BEHAVIOR_REDIRECT 4
#define INTERSECT_BEHAVIOR_GREASE 5
#define INTERSECT_BEHAVIOR_SLIDEBOUNCE 6
#define INTERSECT_BEHAVIOR_ITERATE 7





struct CAnimInstanceHdr_t;
struct CCollisionInfo2_t;



typedef enum ECollisionResult_t
{
 CR_NO_COLLISION,
 CR_NO_COLLISION_NEWDESIREDPOS,
 CR_COLLISION,
 CR_COLLISION_NEWDESIREDPOS
} ECollisionResult;



typedef struct CClosestIntersect_t
{
 float t;

 ECollisionResult cr;
 CVector3 vNextVelocity,
       vNextDesired,
       vIntersect;

 CVector3 *pvIntersectPos;
 struct CGameRegion_t **ppRegion;
 int *pCollType,
       CollType;
 CInstanceHdr **ppInst,
       *pInstType;
} CClosestIntersect;




void func_8009A4B4(CClosestIntersect *pThis);
void func_8009A44C(CClosestIntersect *pThis, CAnimInstanceHdr *pInst);
#define CClosestIntersect__SetStoreDest(pThis,pvDestPos,ppDestRegion,pDestCollType,StoreCollType,ppDestInst,pDestInstType) { (pThis)->pvIntersectPos = (pvDestPos); (pThis)->ppRegion = (ppDestRegion); (pThis)->pCollType = (pDestCollType); (pThis)->CollType = (StoreCollType); (pThis)->ppInst = (ppDestInst); (pThis)->pInstType = (pDestInstType); }

typedef struct CCollide_t
{
 struct CAnimInstanceHdr_t *pInst;
 struct CCollisionInfo2_t *pCI;

 CClosestIntersect clint;

 CVector3 vDesired,
       vDelta,
       vSliding,

       vNextSliding;
 float SlidingRadius,
       NextSlidingRadius;
#define SLIDING_TYPE_NONE 0
#define SLIDING_TYPE_PLANE 1
#define SLIDING_TYPE_CYLINDER 2
 int SlidingType,
       NextSlidingType;
 int AllowRedirection,

       UsePhysics,

       TrackingGround,
       StartedInDeathFall;
} CCollide;




int CCollide__IntersectPlane(CCollide *pThis,
              CVector3 *pvNormal,
              CVector3 *pvPointOnPlane,
              int BackCull,
              int Behavior,
              float SurfaceFriction);
int CCollide__IntersectCylinder(CCollide *pThis,
               CVector3 *pvCenter, float Radius,
               int UseHeight, float Top, float Bottom,
               int BackCull,
               int Behavior,
               float SurfaceFriction);
CGameRegion* CCollide__CanEnter(CCollide *pThis,
            CGameRegion *pCurrent,
            int nDesiredEdge,
            CVector3 *pvComparePos);
void func_80098F6C(CCollide *pThis);
int func_80098F20(CCollide *pThis, CGameRegion *pCurrentRegion);

#define CCollide__InitSlideSurface(pThis) (pThis)->SlidingType = SLIDING_TYPE_NONE
#define CCollide__ClearSlideSurface(pThis) (pThis)->NextSlidingType = SLIDING_TYPE_NONE

#define CCollide__IsSliding(pThis) ((pThis)->SlidingType != SLIDING_TYPE_NONE)

#define CCollide__UpdateNextSlideSurface(pThis) { (pThis)->SlidingType = (pThis)->NextSlidingType; (pThis)->vSliding = (pThis)->vNextSliding; (pThis)->SlidingRadius = (pThis)->NextSlidingRadius; }




#define CCollide__SetSlidePlane(pThis,pvNormal) { (pThis)->NextSlidingType = SLIDING_TYPE_PLANE; (pThis)->vNextSliding = *(pvNormal); }


#define CCollide__IsSlidePlane(pThis,pvNormal) ( ((pThis)->SlidingType == SLIDING_TYPE_PLANE) && (CVector3__IsEqual(&(pThis)->vSliding, (pvNormal))) )


#define CCollide__SetSlideCylinder(pThis,pvCenter,Radius) { (pThis)->NextSlidingType = SLIDING_TYPE_CYLINDER; (pThis)->vNextSliding = *(pvCenter); (pThis)->NextSlidingRadius = (Radius); }



#define CCollide__IsSlideCylinder(pThis,pvCenter,Radius) ( ((pThis)->SlidingType == SLIDING_TYPE_CYLINDER) && ((pThis)->SlidingRadius == (Radius)) && (CVector3__IsEqual(&(pThis)->vSliding, (pvCenter))) )







int CAnimInstanceHdr__Collision3(struct CAnimInstanceHdr_t *pThis,
           CVector3 vDesired,
           struct CCollisionInfo2_t *pCI);





struct CInstanceHdr_t;
struct CGameRegion_t;







#define COLLISIONFLAG_IGNOREDEAD (1 << 3)
#define COLLISIONFLAG_USEWALLRADIUS (1 << 4)
#define COLLISIONFLAG_SMALLWALLRADIUS (1 << 5)


#define COLLISIONFLAG_WATERCOLLISION (1 << 8)

#define COLLISIONFLAG_MOVETHROUGHDOORS (1 << 10)
#define COLLISIONFLAG_PICKUPCOLLISION (1 << 11)
#define COLLISIONFLAG_CANCLIMBCLIMBABLE (1 << 12)
#define COLLISIONFLAG_CLIFFONLY (1 << 13)

#define COLLISIONFLAG_DUCKING (1 << 15)
#define COLLISIONFLAG_CANENTERRESTRICTEDAREA (1 << 16)

#define COLLISIONFLAG_AVOIDPRESSUREPLATE (1 << 18)


#define COLLISIONFLAG_PHYSICS (1 << 19)
#define COLLISIONFLAG_TRACKGROUND (1 << 20)
#define COLLISIONFLAG_CLIMBUP (1 << 21)
#define COLLISIONFLAG_CLIMBDOWN (1 << 22)
#define COLLISIONFLAG_ENTERWATER (1 << 23)
#define COLLISIONFLAG_EXITWATER (1 << 24)
#define COLLISIONFLAG_INSTANCEUPDOWN (1 << 25)
#define COLLISIONFLAG_TWOREDIRECTIONS (1 << 26)
#define COLLISIONFLAG_USEHEIGHT (1 << 27)
#define COLLISIONFLAG_ENDONBOUNCE (1 << 28)

#define GROUNDCOLLISION_NONE 0
#define GROUNDCOLLISION_GROUND 1
#define GROUNDCOLLISION_CEILING 2


typedef struct CCollisionInfo2_t
{

 unsigned long dwFlags;
 int InstanceBehavior,
         WallBehavior,
         GroundBehavior;
 float GravityAcceleration,
         BounceReturnEnergy,
         GroundFriction,
         AirFriction,
         WaterFriction;


 struct CInstanceHdr_t *pInstanceCollision;
 struct CGameRegion_t *pInstanceCollisionRegion;
 CVector3 vInstanceCollisionPos;

 struct CGameRegion_t *pWallCollisionRegion;
 CVector3 vWallCollisionPos;
 int nWallCollisionEdge;

 int nGroundCollisionType;
 struct CGameRegion_t *pGroundCollisionRegion;
 CVector3 vGroundCollisionPos;

 struct CGameRegion_t *pWaterCollisionRegion;
 CVector3 vWaterCollisionPos;

 CVector3 vCollisionVelocity;

} CCollisionInfo2;




void func_8009C5E4();
void func_8009C5D0(CCollisionInfo2 *pThis);




extern CCollisionInfo2 ci_player;
extern CCollisionInfo2 ci_playerdead;
extern CCollisionInfo2 ci_playerunderwater;
extern CCollisionInfo2 ci_playerantigrav;
extern CCollisionInfo2 ci_playeronwatersurface;
extern CCollisionInfo2 ci_playerfallintowater;
extern CCollisionInfo2 ci_player_climbing_sidestep_character;
extern CCollisionInfo2 ci_character;
extern CCollisionInfo2 ci_character_walkinwater;
extern CCollisionInfo2 ci_dead_character;
extern CCollisionInfo2 ci_flying_character;
extern CCollisionInfo2 ci_climbing_character;
extern CCollisionInfo2 ci_climbing_swimming_character;
extern CCollisionInfo2 ci_underwater_climbing_character;
extern CCollisionInfo2 ci_underwater_character;

extern CCollisionInfo2 ci_underwater_character_dead;
extern CCollisionInfo2 ci_underwater_character_float_dead;
extern CCollisionInfo2 ci_particle;
extern CCollisionInfo2 ci_pickup;
extern CCollisionInfo2 ci_nocollisionatall;
extern CCollisionInfo2 ci_movetest;
extern CCollisionInfo2 ci_swimming_movetest;
extern CCollisionInfo2 ci_climbing_movetest;
extern CCollisionInfo2 ci_climbing_swimming_movetest;
extern CCollisionInfo2 ci_raycast;
extern CCollisionInfo2 ci_nearregiontest;
extern CCollisionInfo2 ci_clifftest;




#define PARTICLE_ALLOCATED (1 << 0)
#define PARTICLE_HASHITGROUND (1 << 1)
#define PARTICLE_HASHITWALL (1 << 2)
#define PARTICLE_PERMANENT (1 << 3)
#define PARTICLE_DELETE (1 << 4)

typedef struct CParticle_t
{
 CAnimInstanceHdr ah;

 Mtx m_mOrientation[2];
 CROMParticleEffect *m_pEffect;
 CTextureLoader m_TextureLoader;
 CInstanceHdr *m_pSource;
 unsigned long m_dwFlags;
 float m_cFrame,
        m_cFramePos,
        m_FPS;
 int m_nFrames,
        m_cAnimFrame,
        m_nRandomFrame;
 float m_Size, m_SizeScaler,
        m_Rotation,
        m_RotationInc,
        m_DistanceSquared;
 unsigned char m_AlphaScaler ;
 unsigned char m_ActiveSwooshes ;
 CCollisionInfo2 m_CI;
 short m_Alignment;
 unsigned char m_WhiteColor[3],
        m_BlackColor[3];

 struct CParticle_t *m_pLast, *m_pNext,
        *m_pDrawLast, *m_pDrawNext;
} CParticle;


extern CVector3 v_particle_glare_pos;
extern unsigned char particle_glare_color[];
extern CParticle *p_particle_glare;





void func_8002B5BC (CParticle *pThis);

void CParticle__Draw(CParticle *pThis, Gfx **ppDLP, CCartCache *pCache);

void CParticle__Delete (CParticle *pThis);
void CParticle__Spawn (CParticle *pThis, int nType, int Blood);
void CParticle__SpawnWallCollision (CParticle *pThis, int nType);
void CParticle__SpawnGroundCollision (CParticle *pThis, int nType);
void CParticle__SpawnCeilingCollision (CParticle *pThis, int nType);
void CParticle__SpawnWaterSurfaceCollision(CParticle *pThis, int nType);
void CParticle__Advance (CParticle *pThis);
void CParticle__WallCollision (CParticle *pThis);
void CParticle__GroundCollision (CParticle *pThis);
void CParticle__CeilingCollision (CParticle *pThis);
void CParticle__WaterSurfaceCollision (CParticle *pThis);
void func_80029F14 (CParticle *pThis);
void CParticle__EveryFrame (CParticle *pThis);
void CParticle__EndLife (CParticle *pThis);
void CParticle__Done (CParticle *pThis);
int func_800280A8 (CParticle *pThis);
int func_8002814C (CParticle *pThis);
#define CParticle__DoSoundEffect(pThis,nSoundType,Looping,pvPos) func_80031974(&GetApp()->m_Scene, nSoundType, Looping, pThis, pvPos, 0)

#define CParticle__GetRandom(max) ((((int)max) < 0) ? -RANDOM((-((int)max))+1) : (((max) == 0) ? 0 : RANDOM((max) + 1)))
#define CParticle__GetRandomFloat(max) ((max == 0.0) ? 0.0 : func_80013840(max))




typedef struct CParticleSystem_t
{
 CParticle m_Particles[128],
     *m_pFreeHead,
     *m_pActiveHead, *m_pActiveTail,
     *m_pDrawHead, *m_pDrawTail;
 CCartCache *m_pCache;
   CCacheEntry *m_pceParticleEffects,
     *m_pceTextureSetsIndex;
} CParticleSystem;




void CParticleSystem__Construct(CParticleSystem *pThis);
void CParticleSystem__RequestData(CParticleSystem *pThis, CCartCache *pCache,
               ROMAddress *rpParticleEffectsAddress,
               unsigned long ParticleEffectsSize,
               CCacheEntry *pceTextureSetsIndex);

#define PARTICLE_SCREENY -6
#define PARTICLE_UP -5
#define PARTICLE_SCREEN -4
#define PARTICLE_GROUND -3
#define PARTICLE_CEILING -2
#define PARTICLE_NOEDGE -1
void CParticleSystem__CreateParticle(CParticleSystem *pThis, CInstanceHdr *pSource,
                int nType,
                CVector3 vBaseVelocity, CQuatern qRotateDirection,
                CVector3 vPos, CGameRegion *pRegion, int nEdge , int Blood);
void CParticleSystem__DeallocateParticle(CParticleSystem *pThis, CParticle *pParticle);
void CParticleSystem__DeallocateAllParticles(CParticleSystem *pThis);
void CParticleSystem__Draw(CParticleSystem *pThis, Gfx **ppDLP);
void CParticleSystem__DetonateGrenade(CParticleSystem *pThis);
void CParticleSystem__DetonateAllGrenades(CParticleSystem *pThis);






#define _INC_SIMPPOOL 




struct CScene_t;



#define DYNSIMPLE_ALLOCATED (1 << 0)
#define DYNSIMPLE_HASHITGROUND (1 << 1)

typedef struct CDynamicSimple_t
{
 CGameSimpleInstance s;

 float m_LifeTime ;
 float m_SparkleTime ;
 unsigned long m_dwFlags;
 struct CDynamicSimple_t **m_ppPickup ;
 struct CDynamicSimple_t *m_pLast, *m_pNext;
} CDynamicSimple;




void func_80035F9C(CDynamicSimple *pThis);
void update_dynamic_simple_instance(CDynamicSimple *pThis);
void CDynamicSimple__Delete(CDynamicSimple *pThis);

#define CDynamicSimple__IsAllocated(pThis) ((pThis)->m_dwFlags & DYNSIMPLE_ALLOCATED)
#define CDynamicSimple__SetAllocated(pThis) ((pThis)->m_dwFlags |= DYNSIMPLE_ALLOCATED)
#define CDynamicSimple__SetNotAllocated(pThis) ((pThis)->m_dwFlags &= ~DYNSIMPLE_ALLOCATED)



#define SIMPLES_MAX_COUNT 32

typedef struct CSimplePool_t
{
 CDynamicSimple m_Simples[32],
       *m_pFreeHead,
       *m_pActiveHead, *m_pActiveTail;
 CCartCache *m_pCache;
 CCacheEntry *m_pceObjectsIndex;
 ROMAddress *m_rpObjectsAddress;
 int m_Initialized;
} CSimplePool;




void func_800357D0(CSimplePool *pThis);
void func_80035F84(CSimplePool *pThis, CCartCache *pCache,
            CCacheEntry *pceObjectsIndex, ROMAddress *rpObjectsAddress);

CDynamicSimple* func_80035A74(CSimplePool *pThis, int nType,
                  CVector3 vVelocity,
                  CVector3 vPos, CGameRegion *pRegion, float Time) ;

void func_80035C68(CSimplePool *pThis);
void func_80035E74(CSimplePool *pThis, Gfx **ppDLP, CCacheEntry *pceTextureSetsIndex);
void func_80035DA0(CSimplePool *pThis, struct CScene_t *pScene);






#define _INC_PICKUP 







#define DEFAULT_PISTOL_AMMO 10
#define DEFAULT_RIFLE_AMMO 30
#define DEFAULT_RIOTSHOTGUN_AMMO 10
#define DEFAULT_AUTOSHOTGUN_AMMO 12
#define DEFAULT_MINIGUN_AMMO 125
#define DEFAULT_GRENADELAUNCHER_AMMO 5
#define DEFAULT_MACHINEGUN_AMMO 100
#define DEFAULT_TECH1_AMMO 50
#define DEFAULT_ROCKET_AMMO 6
#define DEFAULT_SHOCKWAVE_AMMO 100
#define DEFAULT_TECH2_AMMO 2
#define DEFAULT_CHRONOSCEPTOR_AMMO 3

#define DEFAULT_TEK_ARMOR 25


#define REFILL_ARROW 30
#define REFILL_EXPARROW_SMALL 5
#define REFILL_EXPARROW_LARGE 15

#define REFILL_BULLET_CLIP 10
#define REFILL_BULLET_BOX 50

#define REFILL_SHOTGUN_SHELLS 5
#define REFILL_SHOTGUN_BOX 20
#define REFILL_EXPSHOTGUN_SHELLS 4
#define REFILL_EXPSHOTGUN_BOX 10
#define REFILL_MINIGUN 125
#define REFILL_GRENADE 1
#define REFILL_GRENADE_BOX 10
#define REFILL_TECH_SMALL 25
#define REFILL_TECH_LARGE 50
#define REFILL_ROCKET 1
#define REFILL_TECH2 1



#define MAX_ARROWS 30
#define MAX_EXPARROWS 15

#define MAX_BULLETS 100
#define MAX_BULLETS_BACKPACK 200

#define MAX_SHOTGUN 20
#define MAX_SHOTGUN_BACKPACK 40
#define MAX_EXPSHOTGUN 10
#define MAX_EXPSHOTGUN_BACKPACK 20

#define MAX_MINIGUN 125

#define MAX_GRENADES 20
#define MAX_GRENADES_BACKPACK 30

#define MAX_ENERGY 100

#define MAX_ROCKETS 6
#define MAX_ROCKETS_BACKPACK 12

#define MAX_CHRONOSCEPTER 3

#define MAX_TECH2 2
#define MAX_TECH2_BACKPACK 3

#define MAX_KEY2 3
#define MAX_KEY3 3
#define MAX_KEY4 3
#define MAX_KEY5 3
#define MAX_KEY6 3
#define MAX_KEY7 3
#define MAX_KEY8 5



#define TEKBOW_AMMO_USE 1
#define PISTOL_AMMO_USE 1
#define RIFLE_AMMO_USE 1
#define RIOTSHOTGUN_AMMO_USE 1
#define AUTOSHOTGUN_AMMO_USE 1
#define MINIGUN_AMMO_USE 1
#define GRENADELAUNCHER_AMMO_USE 1
#define MACHINEGUN_AMMO_USE 1
#define TECH1_AMMO_USE 5
#define ROCKET_AMMO_USE 1
#define SHOCKWAVE_AMMO_USE1 2
#define SHOCKWAVE_AMMO_USE2 4
#define SHOCKWAVE_AMMO_USE3 6
#define SHOCKWAVE_AMMO_USE4 8
#define SHOCKWAVE_AMMO_USE5 10
#define TECH2_AMMO_USE 1
#define CHRONOSCEPTER_AMMO_USE 1




#define SPIRITUAL_TIMER 30
#define SPIRITUAL_TIMEIN 16
#define SPIRITUAL_TIMEOUT 60

#define SPIRITUAL_SKY 8.0
#define SPIRITUAL_ENEMY 0.2
#define SPIRITUAL_PARTICLE 0.2





void func_80091010(void) ;
void CPickup_Pickup(CGameSimpleInstance *pPickup);
int func_80091508(CGameSimpleInstance *pPickup, CAnimInstanceHdr *pInst);

typedef struct CPickupGenerator_t
{
 float m_Time ;
 CDynamicSimple *m_pPickup ;
 CVector3 m_vPos ;
 CGameRegion *m_pRegion ;
} CPickupGenerator ;


void func_800934A4(CPickupGenerator *pThis, CVector3 *pvPos) ;
CDynamicSimple *func_80093524(CPickupGenerator *pThis, signed long Type, float Time) ;





#define MAX_PICKUP_GENERATORS 16
typedef struct CPickupMonitor_t
{
 int m_Active ;
 CPickupGenerator m_Generators[16] ;
 signed long m_NoOfGenerators ;
} CPickupMonitor ;


void func_80093688(CPickupMonitor *pThis) ;
void func_80093694(CPickupMonitor *pThis, signed long NoOfGenerators, CVector3 *pvPosList) ;
#define CPickupMonitor__Activate(pThis) (pThis)->m_Active = TRUE
#define CPickupMonitor__Deactivate(pThis) (pThis)->m_Active = FALSE
void func_8009373C(CPickupMonitor *pThis, CPickupGenerator *pGenerator) ;
void func_80093984(CPickupMonitor *pThis) ;
void CPickupMonitor__ProduceWeapons(CPickupMonitor *pThis) ;


extern unsigned char light_table_red[];
extern unsigned char light_table_green[];
extern unsigned char light_table_blue[];

typedef struct CScene_t
{
 CCartCache m_Cache;

 ROMAddress *m_rpBaseAddress;

   CCacheEntry *m_pceIndex;

   ROMAddress *m_rpObjectsAddress,
        *m_rpTextureSetsAddress,
        *m_rpLevelsAddress,
        *m_rpLevelAddress,
        *m_rpGridSectionsAddress,
        *m_rpObjectTypesAddress,
        *m_rpObjectAttributesAddress,
        *m_rpParticleEffectsAddress,
        *m_rpGridBoundsAddress,
        *m_rpWarpPointsAddress,
        *m_rpBinaries;
   CCacheEntry *m_pceObjectAttributes,
        *m_pceObjectTypes,
        *m_pceObjectsHeader,
        *m_pceObjectsIndex,
        *m_pceCollision,
        *m_pceInstances,
        *m_pceTextureSetsHeader,
        *m_pceTextureSetsIndex,
        *m_pceLevelsHeader,
        *m_pceLevelsIndex,
        *m_pceLevelIndex,
        *m_pceGridBounds,
        *m_pceGridSectionsIndex,
        *m_pcePersistantCounts,
        *m_pceSkyTextureSet,
        *m_pceWarpPoints,
        *m_pceSoundEffects,
        *m_pceLevelInfo,
        *m_pceBinariesIndex,
        *m_pceBinaryTypes;
 unsigned long m_ObjectTypesSize,
        m_ObjectAttributesSize,
        m_ParticleEffectsSize,
        m_GridBoundsSize,
        m_WarpPointsSize;

 CInstanceHdr *m_pInstances[1024];
 int m_nInstances;

 CGameStaticInstance *m_pStaticEventsInstances[64];
 int m_nStaticEventsInstances;

 CGameObjectInstance *m_pPlayer;

 CGameObjectInstance *m_pActiveAnimInstances[64];
 int m_nActiveAnimInstances;

 int m_nTransparentInstances;
 CInstanceHdr *m_pTransparentInstances[64];

 CParticleSystem m_ParticleSystem;
 CSimplePool m_SimplePool;

 CROMLevel m_LevelInfo;
 signed short m_LightDirection[4];

 CTextureLoader m_SkyTextureLoader;
 int m_SkyTextureReady, m_SkyHeightSet,
        m_LevelInfoReceived;
 float m_SkyHeight ;
 float m_RotYPickup;
 CQuatern m_qRotYPickup;
 int m_nLevel,
        m_nWarpID;

 int m_WarpFound;
 CROMWarpPoint m_WarpPoint;

 float m_cSendStaticEventsFrame;

 unsigned long pad1, pad2, pad3, m_bPlayerActiveFlags;

 CPickupMonitor m_PickupMonitor ;
} CScene;




void CScene__Construct(CScene *pThis, int nLevel);
void CScene__Destruct(CScene *pThis);

void CScene__Draw(CScene *pThis, Gfx **ppDLP);
int CScene__Idle(CScene *pThis);
int func_80032970(CScene *pThis, int nType);
int func_80032ACC(CScene *pThis, int nObjType);
void func_800329E0(CScene *pThis, CGameObjectInstance *pInstance,
               int nObjectType, int nAnimType);
void CScene__Decompress(CScene *pThis, CCacheEntry *pceData);

CROMRegionSet* func_8002E438(CScene *pThis, CGameRegion *pRegion);
int func_80033638(CScene *pThis, CGameRegion *pRegion);
CGameRegion *func_800335B4(CScene *pThis, int Index) ;
int func_80031974(CScene *pThis,
             int nSoundType, float Volume,
             void *pSource, CVector3 *pvSourcePos, int SndFlags);
void func_80034998();
void CScene__SetInstanceFlag(CScene *pThis, CGameObjectInstance *pAnim, int Set);
int CScene__GetInstanceFlag(CScene *pThis, CGameObjectInstance *pAnim);
int CScene__GetInstanceFlagByIndex(CScene *pThis, int nInstance);
void CScene__SetPickupFlag(CScene *pThis, CGameSimpleInstance *pSimple, int Set);
int CScene__GetPickupFlag(CScene *pThis, CGameSimpleInstance *pSimple);
void func_80034834(CScene *pThis, int nRegion, int Set);
int func_80033790(CScene *pThis, int nRegion);
void func_80033C88(CScene *pThis);
struct CPersistantData_t* func_80034AF8(CScene *pThis);
void* func_80034B90(CScene *pThis);
int func_80034B4C(CScene *pThis);
void func_80034B38(CScene *pThis);
int func_80034EDC(CScene *pThis, int nBlockType,
              CCacheEntry **ppceBinaryBlock,
              void *pNotifyPtr, pfnCACHENOTIFY pfnBlockReceived);



CDynamicSimple *CScene__GeneratePickup(CScene *pThis, CGameRegion *pRegion,
             CVector3 vPos, int nType, float Time) ;

CGameRegion* func_8002E280(CScene *pThis, CVector3 *pvPos) ;

void CScene__SetupRealTimeLight(CScene *pThis) ;








#define _INC_ONSCRN 




#define AIR_TIMEIN 10
#define AIR_TIMEOUT 10

#define AIRMODE_NULL 0
#define AIRMODE_FADEON 1
#define AIRMODE_WAIT 2
#define AIRMODE_FADEOUT 3

#define BOSSBAR_TIMEIN 10
#define BOSSBAR_TIMEOUT 10

#define BOSSBARMODE_NULL 0
#define BOSSBARMODE_FADEON 1
#define BOSSBARMODE_WAIT 2
#define BOSSBARMODE_FADEOUT 3


#define LARGE_FONT 0
#define SMALL_FONT 1
#define NINTENDO_FONT 2
#define KANJI_FONT 3






typedef struct COverlay_t
{
 int m_OnScreen ;

 signed long *m_pScript,
   m_Mode,
   m_Time ;

 float m_X,
   m_Y,

   m_FinalX,
   m_FinalY,

   m_XVel,
   m_YVel,

   m_XAccel,
   m_YAccel,

   m_ZoomFactor ;
} COverlay ;



enum OverlayModes
{
 OVERLAY_INACTIVE_MODE,
 OVERLAY_READ_SCRIPT_MODE,
 OVERLAY_WAIT_MODE,
 OVERLAY_ZOOM_MODE,
 OVERLAY_DROP_OFF_MODE,
 OVERLAY_HORZDROP_OFF_MODE
} ;


enum OverlayScriptCommands
{
 OVERLAY_SCRIPT_SET_POS = 1,
 OVERLAY_SCRIPT_WAIT,
 OVERLAY_SCRIPT_ZOOM,
 OVERLAY_SCRIPT_DROP_OFF,
 OVERLAY_SCRIPT_HORZDROP_OFF
} ;



#define DEFINE_OVERLAY_SCRIPT(Name) INT32 Name[] = {



#define END_OVERLAY_SCRIPT 0 } ;





#define OVERLAY_SCRIPT_ENTRY_SET_POS(x,y) OVERLAY_SCRIPT_SET_POS,x,y,


#define OVERLAY_SCRIPT_ENTRY_WAIT(frames) OVERLAY_SCRIPT_WAIT,frames,


#define OVERLAY_SCRIPT_ENTRY_ZOOM(x,y,zoomfactor) OVERLAY_SCRIPT_ZOOM,x,y,zoomfactor,


#define OVERLAY_SCRIPT_ENTRY_DROP_OFF(gravity) OVERLAY_SCRIPT_DROP_OFF,gravity*65536,


#define OVERLAY_SCRIPT_ENTRY_HORZDROP_OFF(gravity) OVERLAY_SCRIPT_HORZDROP_OFF,gravity*65536,







void func_8007F588(COverlay *pThis, signed short nScreenX, signed short nScreenY) ;
void func_8007F5C4(COverlay *pThis, signed long *pScript) ;
void func_8007F5EC(COverlay *pThis) ;
#define COverlay__Active(pThis) ((pThis)->m_Mode == OVERLAY_INACTIVE_MODE)
#define COverlay__OnScreen(pThis) ((pThis)->m_OnScreen)







typedef struct CGridGraphic_t
{
 unsigned short m_BlocksAcross ;
 unsigned short m_BlocksDown ;
 unsigned short m_BlockWidth ;
 unsigned short m_BlockHeight ;
 unsigned char m_pData[1] ;
} CGridGraphic ;



typedef struct s_C16BitPart
{
 unsigned long m_BlockWidth ;
 unsigned long m_BlockHeight ;
 unsigned char m_pData[1] ;
} C16BitPart ;


typedef struct C16BitGraphic_t
{
 unsigned short m_BlocksAcross ;
 unsigned short m_BlocksDown ;
 unsigned short m_Width ;
 unsigned short m_Height ;
 unsigned char m_pPart[1] ;
} C16BitGraphic ;





typedef struct s_GameText
{
 float Time ;
 float DisplayTime ;
 int Mode ;
 int Alpha ;
 float Scale ;
 char *String ;
 int Id ;
} t_GameText ;




enum SpecialIcons
{
 ONSCRN_RUN_ICON = 1,
 ONSCRN_WALK_ICON,

 ONSCRN_HEALTH_ICON,
 ONSCRN_ARMOUR_ICON
} ;



typedef struct COnScreen_t
{
 signed short m_SelectionTimer ;

 int m_ExplosiveAmmo ;

 int m_BarrelDirection ;

 int m_AirMode ;
 float m_AirOpacity;

 int m_BossBarMode ;
 float m_BossBarOpacity;

 float m_FlashTimer;
 char m_FlashDraw;

 int m_TopR,
    m_TopG,
    m_TopB,
    m_BottomR,
    m_BottomG,
    m_BottomB ;
 float m_FontXScale,
    m_FontYScale ;
 int m_ShadowXOff,
    m_ShadowYOff ;

 int m_HealthAlert,
    m_ArmorAlert ;


 signed long m_Ammo,
    m_Health,
    m_Armor,
    m_HealthArmourIcon,
    m_Lives,
    m_Tokens,

    m_WalkRunIcon;

 float m_CompassPos,
    m_CompassAccel ;


 COverlay m_AmmoOverlay,
    m_HealthOverlay,
    m_LivesOverlay,
    m_TokensOverlay,
    m_WeaponOverlay,
    m_RunWalkOverlay;


 struct CBoss_t *m_pBoss ;

 u8 m_SelectPosition ;
} COnScreen ;

void func_8007D3C0(COnScreen *pThis);
void COnScreen__Reset(COnScreen *pThis);
void func_8007D5A0(COnScreen *pThis) ;
void func_8007D5F4(COnScreen *pThis, Gfx **ppDLP);
void func_8007F024(COnScreen *pThis, Gfx **ppDLP) ;
void func_8007F11C(COnScreen *pThis, int nHealth);
void func_8007F270(COnScreen *pThis, int nLives);
void func_8007F2D4(COnScreen *pThis, int nTokens) ;

void func_8007F3C0(COnScreen *pThis, int mode) ;
int func_8007F3F4(COnScreen *pThis, struct CBoss_t *pBoss) ;
void func_8007F404(COnScreen *pThis, struct CBoss_t *pBoss) ;


void func_8007F428(COnScreen *pThis, int mode) ;
void func_8007F320(COnScreen *pThis, int nAmmo, int explosive);
void func_8007F45C(COnScreen *pThis, signed long nIcon) ;
void func_8007F4A4(COnScreen *pThis, int nSelectPosition, int Direction);
void func_8007F504(COnScreen *pThis, int SelectPosition);
int func_8007F580(COnScreen *pThis);
void COnScreen__DrawParticleLensFlares(COnScreen *pThis, Gfx **ppDLP);
void func_8007E38C(COnScreen *pThis, Gfx **ppDLP, float sx, float sy, float Opacity, int Sun, int Blocked);
void func_8007DF74(COnScreen *pThis, Gfx **ppDLP);

void func_8007E208(Gfx **ppDL);

void COnScreen__InitBoxDraw(Gfx **ppDLP) ;

void COnScreen__DrawBox(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2,
        unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) ;

void func_8007FAE0(Gfx **ppDLP, signed long X1, signed long Y1, signed long X2, signed long Y2, signed long Thickness,
           unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alpha) ;
void COnScreen__DrawHilightBox(Gfx **ppDLP, signed long x1, signed long y1, signed long x2, signed long y2, signed long thick, int invert,
           unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha) ;

void func_800803D0(Gfx **ppDLP,
         int nNumber,
         int nX,
         int nY) ;

void COnScreen__DrawText(Gfx **ppDLP,
         char *String,
         int nX, int nY,
         int Opacity, int centre, int shadow) ;
void COnScreen__SetFontColor(Gfx **ppDLP, int tr, int tg, int tb, int br, int bg, int bb) ;
void COnScreen__SetFontScale(float XScale, float YScale) ;
void func_80080940(Gfx **ppDLP) ;
void func_80080B0C(Gfx **ppDLP) ;
void func_80080BF0(Gfx **ppDLP) ;

void func_80081A10(Gfx **ppDLP, int opacity) ;
void func_80081B20(Gfx **ppDLP,
          void *pTexture,
          void *pOpacity,
          int XPos, int YPos,
          int TextureWidth, int TextureHeight) ;
void func_80081F58(Gfx **ppDLP,
           void *pTexture,
           void *pOpacity,
           float XPos, float YPos,
           int TextureWidth, int TextureHeight,
           float XScale, float YScale) ;


void func_80082E64(Gfx **ppDLP, C16BitGraphic *Graphic, signed short X, signed short Y) ;
void func_80082FA0(Gfx **ppDLP, C16BitGraphic *Graphic, float X, float Y, float XScale, float YScale) ;

enum GameTextModes
{
 GAMETEXT_NULL,
 GAMETEXT_FADEUP,
 GAMETEXT_DISPLAY,
 GAMETEXT_FADEDOWN
} ;


void func_8008319C(void) ;
t_GameText *func_800831E4(char *String) ;
t_GameText *func_80083248(char *String, float Secs) ;
t_GameText *func_80083288(char *String, int id) ;
int func_800832FC(int id) ;
void func_800833C0(Gfx **ppDLP) ;





enum BARREL_MODES
{
 BARREL_UP,
 BARREL_DOWN
} ;

typedef struct s_CBarrel
{
 int m_Current ;
 int m_Selected ;
 float m_CurrentAngle ;
 float m_SelectedAngle ;

 float m_delta ;
 float m_AngleAccel ;
 float m_ViewAngleOffset ;

 int m_Display ;
 float m_DisplayStep ;

 float m_SpinSpeed ;

 int m_Buffersize ;
 int m_X,
   m_Y,
   m_XStep,
   m_YStep ;
 int m_Direction ;

 void(*InitGraphics)(Gfx **ppDLP) ;
 void(*DrawItem)(Gfx **ppDLP, int index, float x, float y, float xscale, float yscale, int alpha) ;

} CBarrel ;

void func_8008363C(CBarrel *pThis, int items,
        int x, int y, int xstep, int ystep,
        float speed, int display) ;
void func_800836B8(CBarrel *pThis) ;
void func_80083938(CBarrel *pThis, Gfx **ppDLP) ;





#define _INC_VOLUME 






typedef struct CPlane_t
{
 CVector3 m_vPoint,
     m_vNormal;
} CPlane;




void func_80084630(CPlane *pThis, CVector3 *pvA, CVector3 *pvB, CVector3 *pvC);
int func_800846A4(CPlane *pThis, CVector3 *pvPoint);
float func_80084714(CPlane *pThis, CVector3 *pvA, CVector3 *pvB);



typedef struct CViewVolume_t
{
#define VOLUME_FAR_PLANE 0
#define VOLUME_NEAR_PLANE 1
#define VOLUME_LEFT_PLANE 2
#define VOLUME_RIGHT_PLANE 3
#define VOLUME_TOP_PLANE 4
#define VOLUME_BOTTOM_PLANE 5
 CPlane m_Planes[6];
} CViewVolume;




void func_800847F0(CViewVolume *pThis,
               CVector3 *pvEye,
               CVector3 *pvUpLeft,
               CVector3 *pvUpRight,
               CVector3 *pvLowLeft,
               CVector3 *pvLowRight);
int func_800848C0(CViewVolume *pThis, CVector3 *pvPoint);
int func_8008492C(CViewVolume *pThis, int nPts, CVector3 V[]);
int func_800849FC(CViewVolume *pThis, int nPts, CVector3 V[]);
int func_80084ACC(CViewVolume *pThis, CROMBounds *pBounds);
#define CViewVolume__Intersect(pThis,nPlane,pvA,pvB) func_80084714(&(pThis)->m_Planes[(nPlane)], (pvA), (pvB))







#define _INC_PAUSE 







#define __TCONTROLH 







#define __CONTROLH 







#define CCONTROL_MAX_BUTTONS 16
#define CCONTROL_DBL_TIME 6
#define CCONTROL_SMOOTH_STICK 2



typedef struct CControlState_t
{
 u16 BDown,
   BUp,
   BSingle,
   BDbl,
   BDblHold,
   BTimer [ 16 ];

 s8 StickX,
   StickY;


 float Smooth,
   SStickX,
   SStickY;

} CControlState;






extern CControlState D_801199D0;
extern u8 D_800B86D0;
extern u8 validpaks;


extern OSContStatus statusdata[];
extern OSContPad D_80119990[];
extern OSContPad D_801199C8 ;



extern OSPfs ControllerPak ;



extern OSPfsState FileState ;
extern s32 FilesUsed, MaxFiles ;
extern s32 TurokFiles ;
extern s32 FreePages ;


typedef struct s_File
{
 int index ;
 char string[20] ;
 int pages ;
} t_File ;

extern t_File FileDirectory[] ;





int func_80010C94 ( void );

void func_80010DF0(void) ;
void ProcessPlayerController(void) ;
void func_8001116C ( void );

int SetupFileSystem (void) ;
int func_800112D8 (void) ;
int func_80011364 (int file) ;
int ScanFileList (int showall) ;

int func_8001172C(int index) ;
int func_800117C0(int index) ;
int SaveNew(void) ;
int SaveCurrent(int index) ;


#define CTTYPE_NONE 0
#define CTTYPE_DOWN 1
#define CTTYPE_UP 2
#define CTTYPE_SINGLE 3
#define CTTYPE_DBL 4
#define CTTYPE_DBLHOLD 5
#define CTTYPE_STICK_FORWARD 6
#define CTTYPE_STICK_BACKWARD 7
#define CTTYPE_STICK_LEFT 8
#define CTTYPE_STICK_RIGHT 9
#define CTTYPE_STICK_SFORWARD 10
#define CTTYPE_STICK_SBACKWARD 11
#define CTTYPE_STICK_SLEFT 12
#define CTTYPE_STICK_SRIGHT 13



#define CT_CENTER_THRESHOLD 8
#define CT_MAX_OUTPUT -1
#define CT_MAX_STICK 80



typedef struct
{
 CControlState *pCState;
 u8 CenteringX,
       CenteringY;
 u8 LookIndependant;


 u16 Fire1,
       Forward,
       Backward,
       Left,
       Right,
       Duck,
       Jump,
       JumpReleased,
       MapToggle,
       SideStepLeft,
       SideStepRight,
       SelectWeaponPrev,
       SelectWeaponNext,
       SelectEnemyPrev,
       SelectEnemyNext,
       OpenDoor,
       RollRight,
       RollLeft,
       Pause,
       Start,
       StartHeld,
       UseMenu,
       LookUp,
       LookDown,
       LookLeft,
       LookRight,
       RunBackward,
       RunForward,
       RollSpeedL,
       RollSpeedR,
       GrenadeLauncherFired,
       ToggleOnScreen,
       ClickUp,
       ClickDown,
       ClickLeft,
       ClickRight,
       RunWalkToggle,
       SwimForward,
       SwimBackward,
       SwimSideStepL,
       SwimSideStepR,
       SwimUp,
       SwimBurstForward,
       MapLeft,
       MapRight,
       MapDown,
       MapUp,
       StartJump,
       AnalogLeft,
       AnalogRight,
       AnalogDown,
       AnalogUp,
       ClimbLookLeft,
       ClimbLookRight,
       ClimbUp,
       ClimbDown,
       ClimbLeft,
       ClimbRight,
       BurstSwimToggle,
       DigitalUp,
       DigitalDown,
       ZRotTog,
       ZRotLeft,
       ZRotRight,
       EnemyForward,
       EnemyBackward,
       EnemyLeft,
       EnemyRight,
       EnemyRotLeft,
       EnemyRotRight,
       FlyUp,
       FlyDown,
       FlyLeft,
       FlyRight,
       FlyForward,
       FlyBackward;


 u16 PreFire1,
       PreForward,
       PreBackward,
       PreLeft,
       PreRight,
       PreDuck,
       PreJump,
       PreJumpReleased,
       PreMapToggle,
       PreSideStepLeft,
       PreSideStepRight,
       PreSelectWeaponPrev,
       PreSelectWeaponNext,
       PreSelectEnemyPrev,
       PreSelectEnemyNext,
       PreOpenDoor,
       PreRollLeft,
       PreRollRight,
       PrePause,
       PreStart,
       PreStartHeld,
       PreUseMenu,
       PreLookUp,
       PreLookDown,
       PreLookLeft,
       PreLookRight,
       PreRunBackward,
       PreRunForward,
       PreRollSpeedL,
       PreRollSpeedR,
       PreGrenadeLauncherFired,
       PreToggleOnScreen,
       PreClickUp,
       PreClickDown,
       PreClickLeft,
       PreClickRight,
       PreRunWalkToggle,
       PreSwimForward,
       PreSwimBackward,
       PreSwimSideStepL,
       PreSwimSideStepR,
       PreSwimUp,
       PreSwimBurstForward,
       PreMapLeft,
       PreMapRight,
       PreMapDown,
       PreMapUp,
       PreStartJump,
       PreAnalogLeft,
       PreAnalogRight,
       PreAnalogDown,
       PreAnalogUp,
       PreClimbLookLeft,
       PreClimbLookRight,
       PreClimbUp,
       PreClimbDown,
       PreClimbLeft,
       PreClimbRight,
       PreBurstSwimToggle,
       PreDigitalUp,
       PreDigitalDown,
       PreZRotTog,
       PreZRotLeft,
       PreZRotRight,
       PreEnemyForward,
       PreEnemyBackward,
       PreEnemyLeft,
       PreEnemyRight,
       PreEnemyRotLeft,
       PreEnemyRotRight,
       PreFlyUp,
       PreFlyDown,
       PreFlyLeft,
       PreFlyRight,
       PreFlyForward,
       PreFlyBackward;


 u16 NotFire1,
       NotForward,
       NotBackward,
       NotLeft,
       NotRight,
       NotDuck,
       NotJump,
       NotJumpReleased,
       NotMapToggle,
       NotSideStepLeft,
       NotSideStepRight,
       NotSelectWeaponPrev,
       NotSelectWeaponNext,
       NotSelectEnemyPrev,
       NotSelectEnemyNext,
       NotOpenDoor,
       NotRollLeft,
       NotRollRight,
       NotPause,
       NotStart,
       NotStartHeld,
       NotUseMenu,
       NotLookUp,
       NotLookDown,
       NotLookLeft,
       NotLookRight,
       NotRunBackward,
       NotRunForward,
       NotRollSpeedL,
       NotRollSpeedR,
       NotGrenadeLauncherFired,
       NotToggleOnScreen,
       NotClickUp,
       NotClickDown,
       NotClickLeft,
       NotClickRight,
       NotRunWalkToggle,
       NotSwimForward,
       NotSwimBackward,
       NotSwimSideStepL,
       NotSwimSideStepR,
       NotSwimUp,
       NotSwimBurstForward,
       NotMapLeft,
       NotMapRight,
       NotMapDown,
       NotMapUp,
       NotStartJump,
       NotAnalogLeft,
       NotAnalogRight,
       NotAnalogDown,
       NotAnalogUp,
       NotClimbLookLeft,
       NotClimbLookRight,
       NotClimbUp,
       NotClimbDown,
       NotClimbLeft,
       NotClimbRight,
       NotBurstSwimToggle,
       NotDigitalUp,
       NotDigitalDown,
       NotZRotTog,
       NotZRotLeft,
       NotZRotRight,
       NotEnemyForward,
       NotEnemyBackward,
       NotEnemyLeft,
       NotEnemyRight,
       NotEnemyRotLeft,
       NotEnemyRotRight,
       NotFlyUp,
       NotFlyDown,
       NotFlyLeft,
       NotFlyRight,
       NotFlyForward,
       NotFlyBackward;


 u8 TypeFire1,
       TypeForward,
       TypeBackward,
       TypeLeft,
       TypeRight,
       TypeDuck,
       TypeJump,
       TypeJumpReleased,
       TypeMapToggle,
       TypeSideStepLeft,
       TypeSideStepRight,
       TypeSelectWeaponPrev,
       TypeSelectWeaponNext,
       TypeSelectEnemyPrev,
       TypeSelectEnemyNext,
       TypeOpenDoor,
       TypeRollLeft,
       TypeRollRight,
       TypePause,
       TypeStart,
       TypeStartHeld,
       TypeUseMenu,
       TypeLookUp,
       TypeLookDown,
       TypeLookLeft,
       TypeLookRight,
       TypeRunBackward,
       TypeRunForward,
       TypeRollSpeedL,
       TypeRollSpeedR,
       TypeGrenadeLauncherFired,
       TypeToggleOnScreen,
       TypeClickUp,
       TypeClickDown,
       TypeClickLeft,
       TypeClickRight,
       TypeRunWalkToggle,
       TypeSwimForward,
       TypeSwimBackward,
       TypeSwimSideStepL,
       TypeSwimSideStepR,
       TypeSwimUp,
       TypeSwimBurstForward,
       TypeMapLeft,
       TypeMapRight,
       TypeMapDown,
       TypeMapUp,
       TypeStartJump,
       TypeAnalogLeft,
       TypeAnalogRight,
       TypeAnalogDown,
       TypeAnalogUp,
       TypeClimbLookLeft,
       TypeClimbLookRight,
       TypeClimbUp,
       TypeClimbDown,
       TypeClimbLeft,
       TypeClimbRight,
       TypeBurstSwimToggle,
       TypeDigitalUp,
       TypeDigitalDown,
       TypeZRotTog,
       TypeZRotLeft,
       TypeZRotRight,
       TypeEnemyForward,
       TypeEnemyBackward,
       TypeEnemyLeft,
       TypeEnemyRight,
       TypeEnemyRotLeft,
       TypeEnemyRotRight,
       TypeFlyUp,
       TypeFlyDown,
       TypeFlyLeft,
       TypeFlyRight,
       TypeFlyForward,
       TypeFlyBackward;

} CTControl;

CTControl* func_800502F0 (int Right);
float func_800510C4 (CTControl *pThis);
float func_800510F4 (CTControl *pThis);
float func_80051124 (CTControl *pThis);
float func_80051154 (CTControl *pThis);
float func_80051184 (CTControl *pThis);
float CTControl__IsDuck (CTControl *pThis);
float func_800511B4 (CTControl *pThis);
float func_800511E4 (CTControl *pThis);
float CTControl__IsDoubleJump (CTControl *pThis);
float func_80051E74 (CTControl *pThis);
float func_80051304 (CTControl *pThis);
float func_80051334 (CTControl *pThis);
float func_80051244 (CTControl *pThis);
float func_80051274 (CTControl *pThis);
float func_800512A4 (CTControl *pThis);
float func_800512D4 (CTControl *pThis);
float func_80051214 (CTControl *pThis);
float func_80051364 (CTControl *pThis);
float func_80051394 (CTControl *pThis);
float func_800513C4 (CTControl *pThis);
float func_800513F4 (CTControl *pThis);
float func_80051424 (CTControl *pThis);
float func_80051EA4 (CTControl *pThis);
float func_80051454 (CTControl *pThis);
float func_80051484 (CTControl *pThis);
float func_800514B4 (CTControl *pThis);
float func_800514E4 (CTControl *pThis);
float func_80051514 (CTControl *pThis);
float func_80051544 (CTControl *pThis);
float func_80051574 (CTControl *pThis);
float func_800515A4 (CTControl *pThis);
float CTControl__IsFirstFire (CTControl *pThis);
float CTControl__IsDetonate (CTControl *pThis);
float CTControl__IsDetonateAll (CTControl *pThis);
float func_800515D4 (CTControl *pThis);
float func_80051604 (CTControl *pThis);
float func_80051634 (CTControl *pThis);
float func_80051664 (CTControl *pThis);
float func_80051694 (CTControl *pThis);
float func_800516C4 (CTControl *pThis);
float func_800516F4 (CTControl *pThis);
float func_80051754 (CTControl *pThis);
float func_80051784 (CTControl *pThis);
float func_800517B4 (CTControl *pThis);
float func_800517E4 (CTControl *pThis);
float func_80051814 (CTControl *pThis);
float func_80051844 (CTControl *pThis);
float func_80051874 (CTControl *pThis);
float func_800518A4 (CTControl *pThis);
float func_80051904 (CTControl *pThis);
float func_800518D4 (CTControl *pThis);
float func_80051934 (CTControl *pThis);
float func_80051964 (CTControl *pThis);
float func_80051994 (CTControl *pThis);
float func_800519F4 (CTControl *pThis);
float func_800519C4 (CTControl *pThis);
float func_80051A24 (CTControl *pThis);
float func_80051A54 (CTControl *pThis);
float func_80051A84 (CTControl *pThis);
float func_80051AB4 (CTControl *pThis);
float func_80051AE4 (CTControl *pThis);
float func_80051B14 (CTControl *pThis);
float func_80051724 (CTControl *pThis);
float func_80051B44 (CTControl *pThis);
float func_80051B74 (CTControl *pThis);
float func_80051BA4 (CTControl *pThis);
float func_80051BD4 (CTControl *pThis);
float func_80051C04 (CTControl *pThis);
float func_80051C34 (CTControl *pThis);
float func_80051C64 (CTControl *pThis);
float func_80051C94 (CTControl *pThis);
float func_80051CC4 (CTControl *pThis);
float func_80051CF4 (CTControl *pThis);
float func_80051D24 (CTControl *pThis);
float func_80051D54 (CTControl *pThis);
float func_80051D84 (CTControl *pThis);
float func_80051DB4 (CTControl *pThis);
float func_80051DE4 (CTControl *pThis);
float func_80051E14 (CTControl *pThis);
float func_80051E44 (CTControl *pThis);

float CTControl__Action ( CTControl *pThis,
                   u16 Action,
                     u16 Pre,
                     u16 Type,
                   u16 Not );




extern CTControl D_80128A00;






#define _INC_LOADSAVE 






enum LoadMemorySelections
{
 LOADMEMORY_LOAD,
 LOADMEMORY_EXIT,
 LOADMEMORY_END_SELECTION
} ;

enum LoadTypes
{
 LOAD_MEMORYCARD,
 LOAD_PASSWORD
} ;


enum SaveMemorySelections
{
 SAVEMEMORY_SAVE,
 SAVEMEMORY_DELETE,
 SAVEMEMORY_SHOWALL,
 SAVEMEMORY_EXIT,
 SAVEMEMORY_END_SELECTION
} ;







enum SaveTypes
{
 SAVE_MEMORYCARD,
 SAVE_PASSWORD
} ;



enum LoadModes
{
 LOAD_NULL,
 LOAD_FADEUP,
 LOAD_NORMAL,
 LOAD_FADEDOWN
} ;
enum SaveModes
{
 SAVE_NULL,
 SAVE_FADEUP,
 SAVE_NORMAL,
 SAVE_FADEDOWN
} ;





enum RequestorSelections
{
 REQUESTOR_YES,
 REQUESTOR_NO,
 REQUESTOR_END_SELECTION
} ;

enum RequestorModes
{
 REQUESTOR_NULL,
 REQUESTOR_FADEUP,
 REQUESTOR_NORMAL,
 REQUESTOR_FADEDOWN
} ;


typedef struct CRequestor_t
{
 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;


 signed long m_Selection ;

 char **Selections ;

 char *Line1 ;
 char *Line2 ;

} CRequestor ;


enum MessageBoxSelections
{
 MESSAGEBOX_OK,
 MESSAGEBOX_END_SELECTION
} ;

enum MessageBoxModes
{
 MESSAGEBOX_NULL,
 MESSAGEBOX_FADEUP,
 MESSAGEBOX_NORMAL,
 MESSAGEBOX_FADEDOWN
} ;

typedef struct CMessageBox_t
{
 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;


 signed long m_Selection ;

 char *Line1 ;
 char *Line2 ;

} CMessageBox ;





typedef struct CLoad_t
{

 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;

 signed short m_LoadType ;


 s32 m_Side ;
 signed long m_ASelection ;
 signed long m_BSelection ;
 signed long m_FirstVisible ;
 signed long m_MaxVisible ;

 signed long m_Selection ;
 signed long m_SubSelection ;

 signed long m_EntryPos ;

} CLoad ;

typedef struct CSave_t
{

 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;

 signed short m_SaveType ;


 s32 m_Side ;
 signed long m_ASelection ;
 signed long m_BSelection ;
 signed long m_FirstVisible ;
 signed long m_MaxVisible ;

 int m_ShowAll ;

 signed long m_Selection ;

} CSave ;





enum GamePakSelections
{
 GAMEPAK_SLOT1,
 GAMEPAK_SLOT2,
 GAMEPAK_SLOT3,
 GAMEPAK_SLOT4,
 GAMEPAK_SLOT5,
 GAMEPAK_SLOT6,
 GAMEPAK_SLOT7,
 GAMEPAK_SLOT8,
 GAMEPAK_SLOT9,
 GAMEPAK_SLOT10,
 GAMEPAK_SLOT11,
 GAMEPAK_SLOT12,
 GAMEPAK_SLOT13,
 GAMEPAK_SLOT14,
 GAMEPAK_SLOT15,
 GAMEPAK_SLOT16,
 GAMEPAK_END_SELECTION
} ;

enum GamePakModes
{
 GAMEPAK_NULL,
 GAMEPAK_FADEUP,
 GAMEPAK_NORMAL,
 GAMEPAK_FADEDOWN
} ;


typedef struct CGamePak_t
{

 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;


 signed long m_Selection ;
 signed long m_Timer ;

} CGamePak ;







void CLoad__Construct(CLoad *pThis) ;
signed long CLoad__Update(CLoad *pThis) ;
void func_8000C40C(CLoad *pThis, Gfx **ppDLP) ;

void CSave__Construct(CSave *pThis) ;
signed long func_8000CE18(CSave *pThis) ;
void func_8000D554(CSave *pThis, Gfx **ppDLP) ;

void CGamePak__Construct(CGamePak *pThis) ;
signed long func_80010310(CGamePak *pThis) ;
void CGamePak__Draw(CGamePak *pThis, Gfx **ppDLP) ;


void func_8000DEB8(CRequestor *pThis, char *String1, char *String2) ;
signed long func_8000DEE8(CRequestor *pThis) ;
void CRequestor__Draw(CRequestor *pThis, Gfx **ppDLP) ;

void func_8000E498(CMessageBox *pThis, char *String1, char *String2) ;
signed long func_8000E4BC(CMessageBox *pThis) ;
void func_8000E52C(CMessageBox *pThis, Gfx **ppDLP) ;



enum CheatCodeSelections
{
 CHEATCODE_GRID1,
 CHEATCODE_GRID2,
 CHEATCODE_GRID3,
 CHEATCODE_GRID4,
 CHEATCODE_DELETE,
 CHEATCODE_ENTER,
 CHEATCODE_EXIT,
 CHEATCODE_END_SELECTION
} ;

enum CheatCodeModes
{
 CHEATCODE_NULL,
 CHEATCODE_FADEUP,
 CHEATCODE_NORMAL,
 CHEATCODE_FADEDOWN
} ;

typedef struct CCheatCode_t
{

 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;


 signed long m_Selection ;
 signed long m_SubSelection ;

 signed long m_EntryPos ;
} CCheatCode ;


typedef struct CGiveCheatCode_t
{

 float m_Alpha ;
 signed short m_Mode ;

 int b_Active ;

 int *m_Codes ;


 signed long m_Selection ;
} CGiveCheatCode ;


void func_8000EEC0(CCheatCode *pThis) ;
signed long func_8000F108(CCheatCode *pThis) ;
void func_8000F498(CCheatCode *pThis, Gfx **ppDLP) ;

void func_8000F87C(CGiveCheatCode *pThis, int *code) ;
signed long func_8000F8AC(CGiveCheatCode *pThis) ;
void CGiveCheatCode__Draw(CGiveCheatCode *pThis, Gfx **ppDLP) ;






#define _INC_OPTIONS 








enum OptionSelections
{
 OPTIONS_MUSIC_VOLUME,
 OPTIONS_SFX_VOLUME,
 OPTIONS_OPACITY,
 OPTIONS_HANALOG,
 OPTIONS_VANALOG,
 OPTIONS_CONTROL,

 OPTIONS_BLOOD,

 OPTIONS_EXIT,
 OPTIONS_END_SELECTION
} ;

enum OptionsModes
{
 OPTIONS_NULL,
 OPTIONS_FADEUP,
 OPTIONS_NORMAL,
 OPTIONS_FADEDOWN
} ;


enum BloodStyles
{
 BLOOD_OFF,
 BLOOD_RED,
 BLOOD_GREEN,

 BLOOD_END
} ;

typedef struct COption_t
{

 signed long m_Mode ;
 float m_Alpha ;

 int b_Active ;
 int m_RHControl;
 int m_Blood;

 signed long m_Selection ;


 signed long m_MusicVolume ;
 signed long m_SFXVolume ;
 signed long m_Opacity ;
 signed long m_HAnalog ;
 signed long m_VAnalog ;


 int m_OptionsStored ;
 signed long m_Storage_CheatFlags ;
 int m_Storage_RHControl ;
 int m_Storage_Blood ;
 signed long m_Storage_Opacity ;
 signed long m_Storage_HAnalog ;
 signed long m_Storage_VAnalog ;
 signed long m_Storage_Difficulty ;
} COptions ;






void COptions__Store(COptions *pThis) ;
void COptions__Restore(COptions *pThis) ;
void COptions__SetAttractDefaults(COptions *pThis) ;

void COptions__SetDefaults(COptions *pThis) ;
void func_80093DD8(COptions *pThis) ;
signed long func_80093DF4(COptions *pThis) ;
void func_80094170(COptions *pThis, Gfx **ppDLP);

enum KeySelections
{
 KEYS_EXIT,
 KEYS_END_SELECTION
} ;

enum KeysModes
{
 KEYS_NULL,
 KEYS_FADEUP,
 KEYS_NORMAL,
 KEYS_FADEDOWN
} ;



typedef struct CKeys_t
{

 signed long m_Mode ;
 float m_Alpha ;

 int b_Active ;

} CKeys ;






void func_80094880(CKeys *pThis) ;
s32 func_800948A8(CKeys *pThis) ;
void func_80094BD0(CKeys *pThis, Gfx **ppDLP);






#define _INC_CHEAT 

#define CHEATFLAG_INVINCIBILITY (1<<0)
#define CHEATFLAG_SPIRITMODE (1<<1)
#define CHEATFLAG_ALLWEAPONS (1<<2)
#define CHEATFLAG_UNLIMITEDAMMO (1<<3)
#define CHEATFLAG_INFINITELIVES (1<<4)
#define CHEATFLAG_ALLKEYS (1<<5)
#define CHEATFLAG_ALLMAP (1<<6)
#define CHEATFLAG_BIGHEADS (1<<7)
#define CHEATFLAG_TINYENEMYMODE (1<<8)
#define CHEATFLAG_PENANDINKMODE (1<<9)
#define CHEATFLAG_PURDYCOLORS (1<<10)
#define CHEATFLAG_DISCO (1<<11)
#define CHEATFLAG_QUACKMODE (1<<12)
#define CHEATFLAG_WARPLEVEL1 (1<<13)
#define CHEATFLAG_WARPLEVEL2 (1<<14)
#define CHEATFLAG_WARPLEVEL3 (1<<15)
#define CHEATFLAG_WARPLEVEL4 (1<<16)
#define CHEATFLAG_WARPLEVEL5 (1<<17)
#define CHEATFLAG_WARPLEVEL6 (1<<18)
#define CHEATFLAG_WARPLEVEL7 (1<<19)
#define CHEATFLAG_WARPLEVEL8 (1<<20)
#define CHEATFLAG_WARPLONGHUNTER (1<<21)
#define CHEATFLAG_WARPMANTIS (1<<22)
#define CHEATFLAG_WARPTREX (1<<23)
#define CHEATFLAG_WARPCAMPAIGNER (1<<24)
#define CHEATFLAG_GALLERY (1<<25)
#define CHEATFLAG_SHOWCREDITS (1<<26)
#define CHEATFLAG_FLYMODE (1<<27)

enum CheatSelections
{
 CHEAT_INVINCIBILITY,
 CHEAT_SPIRITMODE,
 CHEAT_ALLWEAPONS,
 CHEAT_UNLIMITEDAMMO,
 CHEAT_INFINITELIVES,
 CHEAT_ALLKEYS,
 CHEAT_ALLMAP,
 CHEAT_BIGHEADS,

 CHEAT_TINYENEMYMODE,

 CHEAT_PENANDINKMODE,
 CHEAT_PURDYCOLORS,

 CHEAT_DISCO,

 CHEAT_QUACKMODE,
 CHEAT_WARPLEVEL1,
 CHEAT_WARPLEVEL2,
 CHEAT_WARPLEVEL3,
 CHEAT_WARPLEVEL4,
 CHEAT_WARPLEVEL5,
 CHEAT_WARPLEVEL6,
 CHEAT_WARPLEVEL7,
 CHEAT_WARPLEVEL8,
 CHEAT_WARPLONGHUNTER,
 CHEAT_WARPMANTIS,
 CHEAT_WARPTREX,
 CHEAT_WARPCAMPAIGNER,
 CHEAT_GALLERY,
 CHEAT_SHOWCREDITS,

 CHEAT_FLYMODE,
 CHEAT_EXIT,
 CHEAT_END_SELECTION
} ;




enum CheatFadeModes
{
 CHEAT_NULL,
 CHEAT_FADEUP,
 CHEAT_NORMAL,
 CHEAT_FADEDOWN
} ;



enum GInstSelections
{
 GINST_EXIT,
 GINST_END_SELECTION
} ;

enum GInstFadeModes
{
 GINST_NULL,
 GINST_FADEUP,
 GINST_NORMAL,
 GINST_FADEDOWN
} ;

typedef struct CCheat_t
{

 signed long m_Mode ;
 float m_Alpha ;

 int b_Active ;


 signed long m_Selection ;
 int m_RealSelection ;

} CCheat ;


typedef struct CGInst_t
{

 signed long m_Mode ;
 float m_Alpha ;

 int b_Active ;


 signed long m_Selection ;

} CGInst ;







void CCheat__Construct(CCheat *pThis) ;
signed long CCheat__Update(CCheat *pThis) ;
void func_800888D4(CCheat *pThis, Gfx **ppDLP) ;

void func_80088F10(CGInst *pThis) ;
signed long func_80088F3C(CGInst *pThis) ;
void CGInst__Draw(CGInst *pThis, Gfx **ppDLP) ;






enum PauseSelections
{
 PAUSE_RESUME,
 PAUSE_OPTIONS,
 PAUSE_KEYS,





 PAUSE_LOAD,

 PAUSE_ENTERCHEAT,
 PAUSE_CHEATMENU,
 PAUSE_RESTART_GAME,
 PAUSE_END_SELECTION
} ;

enum TitleSelections
{
 TITLE_START,
 TITLE_LOAD,
 TITLE_TRAINING,
 TITLE_OPTIONS,
 TITLE_DIFFICULTY,
 TITLE_ENTERCHEAT,
 TITLE_CHEATMENU,
 TITLE_END_SELECTION
} ;



enum PauseModes
{
 PAUSE_NULL,
 PAUSE_FADEUP,
 PAUSE_NORMAL,
 PAUSE_FADEDOWN
} ;

typedef struct CPause_t
{

 signed long m_Mode ;
 float m_Alpha ;


 signed long m_Selection ;
 int m_RealSelection;

} CPause ;





extern float BarTimer ;

void CPause__Construct(CPause *pThis) ;
signed long func_80084E9C(CPause *pThis) ;
void func_80087228(CPause *pThis, Gfx **ppDLP) ;



void CPause__DrawRock(Gfx **ppDLP, int x, int y, float xscale, float yscale, int opacity) ;


void CPause__InitPolygon(Gfx **ppDLP) ;
void CPause__DrawBar(Gfx **ppDLP, float x, float y, float w, float h, float a) ;






#define _INC_BOSS 

#define BOSS_Health(pThis) (pThis->m_AI.m_Health)
#define BOSS_GetPos(pThis) (pThis->ah.ih.m_vPos)
#define BOSS_GetVel(pThis) ((pThis)->ah.m_vVelocity)

#define BOSS_CollisionHeightOffset(pThis) (pThis->ah.ih.m_CollisionHeightOffset)
#define BOSS_MODE_INFO(a,b,c,d,f) {(void *)a, (void *)b, c, d, f}

#define TUROK_Health(pThis) (pThis->m_AI.m_Health)
#define TUROK_GetPos(pThis) (pThis->ah.ih.m_vPos)
#define TUROK_GetVel(pThis) ((pThis)->ah.m_vVelocity)


#define TUROK_WAIST_HEIGHT (5*SCALING_FACTOR)








#define BF_INVINCIBLE (1<<0)
#define BF_RUN_AT_MODE_ANIM_SPEED (1<<1)

#define BF_FLOOR_MODE (1<<2)
#define BF_CEILING_MODE (1<<3)
#define BF_LEFT_WALL_MODE (1<<4)
#define BF_RIGHT_WALL_MODE (1<<5)
#define BF_JUMPING_MODE (1<<6)
#define BF_FLYING_MODE (1<<7)
#define BF_WALKING_MODE (1<<8)
#define BF_RUNNING_MODE (1<<9)
#define BF_TAUNT_MODE (1<<10)
#define BF_ATTACK_MODE (1<<11)
#define BF_EVADE_MODE (1<<12)
#define BF_ENTER_MODE (1<<13)
#define BF_KICK_IMPACT_MODE (1<<14)
#define BF_PUNCH_IMPACT_MODE (1<<15)
#define BF_EXPLODE_MODE (1<<16)
#define BF_DEATH_MODE (1<<17)
#define BF_FLAME_MODE (1<<18)

#define BF_CAN_TELEPORT (1<<19)
#define BF_CAN_FIRE (1<<20)
#define BF_CAN_EVADE (1<<21)
#define BF_CAN_FLINCH (1<<22)
#define BF_CAN_EXPLODE_FLINCH (1<<23)

#define BF_HEAD_TRACK_TUROK (1<<24)
#define BF_LASER_ON (1<<25)
#define BF_CLEAR_VELS (1<<26)







typedef struct CBossVars_t
{
 signed long m_SwitchesOn ;
 unsigned long m_SwitchFlags ;
 float m_TurokSpeed ;
 CGameRegion *m_pRegionList[4] ;
 float m_StartBossTimer ;
 CGameObjectInstance *m_pMantisInstance ;
 CVector3 m_vTurokLastPos ;
 CVector3 m_vTurokDir ;
} CBossVars ;


void func_8003F7CC(CBossVars *pThis) ;


typedef struct CDamage_t
{
 signed short m_Health ;
 signed char m_Node1, m_Node2 ;
 unsigned long m_Flags ;
} CDamage ;




typedef struct t_RGB
{
 float Red,Green,Blue, Alpha ;
} CRGB ;



typedef struct t_Light
{
 CRGB Ambient ;
 CRGB Directional ;
 CVector3 Normal ;
} CLight ;

typedef struct t_PsuedoColor
{
 CRGB m_WhiteColor ;
 CRGB m_BlackColor ;
} CPsuedoColor ;



#define BF_EVENT1 (1<<0)
#define BF_EVENT2 (1<<1)
#define BF_EVENT3 (1<<2)
#define BF_EVENT4 (1<<3)
#define BF_EVENT5 (1<<4)
#define BF_EVENT6 (1<<5)
#define BF_EVENT7 (1<<6)
#define BF_EVENT8 (1<<7)


typedef struct CShield_t
{
 signed short m_Health ;
 signed short m_StartHealth ;
 signed short m_Mode ;
 signed short m_TotalColors ;
 CPsuedoColor *m_pColors ;
 float m_Alpha ;
 float m_Time ;
 CParticle *m_pParticle ;
 CPsuedoColor *m_pColor ;
 CGameObjectInstance *m_pOwner ;
 signed long m_SoundHandle ;
} CShield ;



typedef struct CBoss_t
{
 int m_Alive ;
 int m_Initialized ;
 signed long m_ObjectType ;

 signed long m_StartHealth ;
 signed long m_LastHealth ;
 signed long m_LastPercentageHealth ;
 signed long m_PercentageHealth ;

 signed long m_EventFlags ;

 signed long m_Mode, m_OldMode, m_LastMode ;
 float m_ModeTime ;
 signed long m_OldModeFlags, m_ModeFlags ;
 float m_MoveTime ;
 signed long m_AnimPlayed ;
 signed long m_AnimEndFrame ;
 int m_AnimPastEnd ;
 signed long m_AnimRepeats ;
 signed long m_Stage ;
 CCollisionInfo2 m_CollisionInfo ;

 float m_AnimSpeed ;
 float m_ModeAnimSpeed ;
 float m_PlaybackAnimSpeed ;

 float m_Speed ;
 float m_RotX, m_RotZ ;

 CVector3 m_LastPos, m_LastVel, m_LastDir ;

 signed short m_Action ;
 signed short m_ActionStage ;
 float m_ActionTime ;

 float m_LookDeltaAngle ;
 float m_DeltaAngle ;
 CVector3 m_vTarget ;
 float m_DistFromTarget ;
 float m_DistFromTargetSqr ;

 float m_Rot1 ;
 float m_Rot2 ;
 float m_Rot3 ;
 float m_Rot4 ;
 float m_Rot5 ;

 float m_DistFromTurok ;
 float m_TurokAngle ;
 float m_TurokAngleDiff ;
 float m_TurokAngleDist ;
 float m_AtTargetDist ;
 float m_TurokDeltaAngle ;
 float m_LastTurokDeltaAngle ;
 float m_AbsTurokDeltaAngle ;

 CShield *m_pShield ;

 void(*m_pInitializeFunction)(void *pThis, void *pBoss) ;
 void(*m_pUpdateFunction)(void *pThis, void *pBoss ) ;
 void (*m_pHitByParticleFunction)(void *pThis, void *pBoss, void *pParticle) ;

 struct CBossModeInfo_t *m_pModeTable ;
 void (*m_pPreDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP) ;
 void (*m_pPostDrawFunction)(void *pThis, void *pBoss, Gfx **ppDLP) ;
 void (*m_pPauseFunction)(void *pThis, void *pBoss) ;
 void (*m_pRestoreFunction)(void *pThis, void *pBoss) ;





} CBoss ;






typedef struct CBossModeInfo_t
{
 void(*m_pSetupFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;
 void(*m_pUpdateFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;
 signed long m_Anim ;
 float m_AnimSpeed ;
 signed long m_Flags ;
} CBossModeInfo ;

typedef struct CBossScript_t
{
 signed short *m_pStart ;
 signed short *m_pCurrent ;
} CBossScript ;




typedef struct CFlinchInfo_t
{
 float RotYOffset ;

 float HeadHeight ;
 float ShoulderHeight ;
 float StomachHeight ;

 signed long HeadMode ;
 signed long BackMode ;
 signed long StomachMode ;
 signed long KneeMode ;
 signed long LeftShoulderMode ;
 signed long RightShoulderMode ;

} CFlinchInfo ;






void func_8003F7E0(CBoss *pThis) ;

void BOSS_Initialise(CGameObjectInstance *pThis, signed long nObjectType) ;


void BOSS_LevelComplete(void) ;

int func_8003FAC8(CGameObjectInstance *pThis, signed long nNewMode) ;
void BOSS_Update(CGameObjectInstance *pThis) ;
void func_8003FEE4(CGameObjectInstance *pThis, signed long Node) ;

void func_8003FF88(CGameObjectInstance *pThis, CBoss *pBoss) ;
signed long func_800400D8(CGameObjectInstance *pThis, CBoss *pBoss, float AngleRange) ;

void func_8004016C(CGameObjectInstance *pThis, CBoss *pBoss, float TurnSpeed, float DeltaAngle) ;
void func_80040228(CGameObjectInstance *pThis, CBoss *pBoss, float Speed) ;

signed long func_800402A0(CGameObjectInstance *pThis, CBoss *pBoss, CFlinchInfo *pInfo, CParticle *pParticle) ;

signed long func_8004045C(CGameObjectInstance *pThis, CVector3 *pvPos, signed long Length) ;

void func_800408F8(CGameObjectInstance *pThis, float x, float z) ;

int func_80040614(CGameObjectInstance *pThis, float Radius, float AngleOffset, CGameRegion **ppRegion, CVector3 *pvOutPos) ;






void func_80040704(CGameObjectInstance *pThis, CBoss *pBoss) ;






CQuatern func_80040764(CGameObjectInstance *pThis) ;






float func_800409AC(float Var, float Accel, float MaxSpeed) ;
float func_80040A0C(float Var, float Decel) ;

#define AccelerateVarFLOAT(pVar,Accel,MaxSpeed) *(pVar) = func_800409AC(*(pVar), Accel, MaxSpeed)
#define DecelerateVarFLOAT(pVar,Decel) *(pVar) = func_80040A0C(*(pVar), Decel)


signed long func_80040A80(signed long Var, signed long Accel, signed long MaxSpeed) ;

float func_80040ADC(float Var, float Target, float Speed) ;
void func_80040B54(float *pVar, float Target, float Speed) ;

float func_80040CB0(float Phi, float Theta) ;
float func_80040C80(float Phi, float Theta) ;

float func_80040D10(float a, float b) ;
int func_80040D74(float *pTimer) ;


void func_80040DB8(CInstanceHdr *pThis, CVector3 *pvDestPos, CVector3 *pvOutPos) ;





signed short ChooseHealthPickup(void) ;
signed short ChooseWeaponPickupTurokIsHolding(void) ;






void func_80040E48(CShield *pThis,
        CGameObjectInstance *pOwner,
        signed long Health, CPsuedoColor *pColors, signed long TotalColors) ;

int func_80040E80(CShield *pThis) ;
void func_80040EA4(CShield *pThis) ;
int func_800416C0(CShield *pThis, float Time) ;
void func_80041740(CShield *pThis) ;







#define MAX_BOSS_DATA_SIZE 800
#define MAX_BOSS_EVENTS 20
#define MAX_BOSS_PICKUPS 20


typedef struct CBossEvent_t
{
 CInstanceHdr *m_pInst ;
 CVector3 m_vPos ;
 int m_nType ;
 float m_Value ;
} CBossEvent ;


typedef struct CBossPickup_t
{
 int m_nType ;
 CVector3 m_vPos ;
} CBossPickup ;


typedef struct CBossData_t
{
 CGameObjectInstance *m_pObject ;
 CBoss *m_pBossVars ;

 void (*m_pCollisionFunction)(CGameObjectInstance *pThis, CCollisionInfo2 *pCollisionInfo) ;

 CVector3 m_vPos ;
 float m_RotY ;

 int m_IsGone ;

 signed long m_Anim ;
 signed long m_CurrentAnimFrame ;

 unsigned long m_BossDataSize ;
 unsigned char m_BossData[800] ;

 CAIDynamic m_AIDynamicData ;

 signed short m_Mode ;
 float m_ModeTime ;
 float m_ModeMisc1 ;

} CBossData ;


typedef struct CBossesStatus_t
{
 CGameObjectInstance *m_pBossActive ;

 CBossData m_BossData[3] ;

 CBossEvent m_EventData[20] ;
 signed long m_CurrentEvent ;

 int m_PickupMonitorActive ;
 CBossPickup m_PickupData[20] ;
 signed long m_CurrentPickup ;

} CBossesStatus ;


signed long func_8003F188(CGameObjectInstance *pThis) ;
signed long func_8003F1C4(CGameObjectInstance *pThis) ;

void CBossesStatus__Construct(CBossesStatus *pThis) ;
void func_8003F220(CBossesStatus *pThis, CGameObjectInstance *pObject) ;
void func_8003F298(CBossesStatus *pThis, CGameObjectInstance *pObject) ;
CBossData *func_8003F334(CBossesStatus *pThis, CGameObjectInstance *pObject) ;

void CBossesStatus__SaveAllBossesStatus(CBossesStatus *pThis) ;
void CBossesStatus__RestoreAllBossesStatus(CBossesStatus *pThis) ;

void func_8003F6D4(CBossesStatus *pThis, CInstanceHdr *pInst, int nType, CVector3 vPos, float Value) ;





#define _INC_FX 












#define _INC_MATTABLE 







#define __LISTS_H__ 

typedef struct CNode_t
{
 struct CNode_t *m_pPrev ;
 struct CNode_t *m_pNext ;
} CNode ;

typedef struct CList_t
{
 CNode *m_pHead ;
 CNode *m_pTail ;
 signed long m_Length ;
} CList ;



typedef struct CDynamicList_t
{
 CList m_FreeList ;
 CList m_ActiveList ;
} CDynamicList ;





void func_80043930(CList *pThis) ;
void func_80043940(CList *pThis, CNode *pNode) ;
void func_80043988(CList *pThis, CNode *pNode) ;
void func_800439E8(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total) ;
CNode *func_80043A60(CDynamicList *pThis) ;
void func_80043AAC(CDynamicList *pThis, CNode *pNode) ;





typedef struct CSelection_t
{
 signed short m_Number ;
 signed short m_Weight ;
} CSelection ;



typedef struct CSelectionList_t
{
 signed short m_Entries ;
 CSelection m_List[24] ;
} CSelectionList ;





signed short func_80043AE0(CSelection *pList) ;

void func_80043BA4(CSelectionList *pThis) ;
void func_80043BAC(CSelectionList *pThis, signed short Item, signed short Weight) ;
signed short func_80043BE4(CSelectionList *pThis) ;







typedef struct CAnimationMtxs_t
{
 signed short m_MtxsFree ;
 Mtx *m_pmFreeMtx ;
 signed long m_MtxsRequested ;
} CAnimationMtxs ;






void func_80035768(void) ;
void CAnimationMtxs__Update(void) ;
Mtx *func_800356E0(signed long Size) ;









#define MAX_FXSYSTEM_VERTICES 400
#define MAX_SWOOSH_EDGES 150
#define MAX_SWOOSHES 32
#define MAX_TIMER_FX 3








typedef struct CSwooshVertex_t
{
 CVector3 m_vPos ;
 CRGB m_Color ;
 float m_Alpha ;
} CSwooshVertex ;


typedef struct CSwooshEdgeVertexInfo_t
{
 CSwooshVertex m_Start, m_End ;
} CSwooshEdgeVertexInfo ;


typedef struct CSwooshInfo_t
{
 float m_LifeTime ;
 float m_FadeOutTime ;
 float m_EdgeLifeTime ;
 signed short m_Node ;
 float m_Scale ;
 signed short m_Flags ;
 signed short m_NoOfEdgeVertices ;
 CSwooshEdgeVertexInfo *m_pEdgeVertexList ;
} CSwooshInfo ;


#define SWOOSH_CLOSE_EDGES (1<<0)







typedef struct CSwooshEdge_t
{
 CNode m_Node ;
 float m_LifeTime ;
 float m_TotalLifeTime ;
 Mtx m_mMatrix ;
} CSwooshEdge ;

enum SwooshTypes
{
 PARTICLE_SWOOSH,
 OBJECT_SWOOSH,
 END_SWOOSH
} ;


typedef struct CSwoosh_t
{
 CNode m_Node ;
 signed short m_Type ;
 float m_LifeTime ;

 CSwooshInfo *m_pInfo ;

 CGameObjectInstance *m_pObject ;
 CParticle *m_pParticle ;

 CList m_EdgeList ;
} CSwoosh ;



typedef struct CTimerFx_t
{
 CNode m_Node ;
 float m_Time ;
 float m_Spacing ;
 signed long m_Count ;
 CGameObjectInstance *m_pInst ;
 void (*m_pFunction)(void *pThis) ;
} CTimerFx ;



typedef struct CFxSystem_t
{
 Vtx m_VertexList[2][400] ;
 signed long m_VtxsFree ;
 Vtx *m_pFreeVertex ;

 CSwooshEdge m_SwooshEdgeVars[150] ;
 CList m_SwooshEdgeList ;

 CSwoosh m_SwooshVars[32] ;
 CDynamicList m_SwooshList ;

 CTimerFx m_TimerFxVars[3] ;
 CDynamicList m_TimerFxList ;
} CFxSystem ;

typedef struct CSpeacialFx_t
{
 CGameObjectInstance *m_pInst ;
 signed long m_Command ;
 float m_Time ;
 float *m_pScriptStart ;
 float *m_pScript ;

 float m_Trans ;
 float m_StartTrans ;
 float m_FinalTrans ;
 float m_TransFadeTime ;

 float m_Color ;
 float m_StartColor ;
 float m_FinalColor ;
 float m_ColorFadeTime ;

 CRGB m_EnvColor ;
 CRGB m_StartEnvColor ;
 CRGB m_FinalEnvColor ;
} CSpecialFx ;

enum SpecialFxCommands
{
 SPECIALFX_COMMAND_IDLE,

 SPECIALFX_COMMAND_WAIT,
 SPECIALFX_COMMAND_RANDOM_WAIT,

 SPECIALFX_COMMAND_SET_TRANS,
 SPECIALFX_COMMAND_FADE_TRANS,

 SPECIALFX_COMMAND_SET_COLOR,
 SPECIALFX_COMMAND_FADE_COLOR,

 SPECIALFX_COMMAND_PLAY_SOUND,

 SPECIALFX_COMMAND_REPEAT
} ;

#define SPECIALFX_SCRIPT_WAIT(t) SPECIALFX_COMMAND_WAIT,t,
#define SPECIALFX_SCRIPT_RANDOM_WAIT(t1,t2) SPECIALFX_COMMAND_RANDOM_WAIT,t1,t2,

#define SPECIALFX_SCRIPT_SET_TRANS(v) SPECIALFX_COMMAND_SET_TRANS,v,
#define SPECIALFX_SCRIPT_FADE_TRANS(v,t) SPECIALFX_COMMAND_FADE_TRANS,v,t,

#define SPECIALFX_SCRIPT_SET_COLOR(r,g,b,v) SPECIALFX_COMMAND_SET_COLOR,r,g,b,v,
#define SPECIALFX_SCRIPT_FADE_COLOR(r,g,b,v,t) SPECIALFX_COMMAND_FADE_COLOR,r,g,b,v,t,

#define SPECIALFX_SCRIPT_PLAY_SOUND(s) SPECIALFX_COMMAND_PLAY_SOUND,s,

#define SPECIALFX_SCRIPT_REPEAT SPECIALFX_COMMAND_REPEAT,


#define DEFINE_SPECIALFX_SCRIPT(name) FLOAT name[] = {



#define END_SPECIALFX_SCRIPT SPECIALFX_COMMAND_IDLE } ;








void func_800423A4(CFxSystem *pThis) ;

void func_800423A4(CFxSystem *pThis) ;
void func_800424CC(CFxSystem *pThis) ;
Vtx *func_80042530(CFxSystem *pThis, signed long NoOfVertices) ;

CSwooshEdge *func_80042444(CFxSystem *pThis, CSwoosh *pSwoosh) ;
void func_80042490(CFxSystem *pThis, CSwoosh *pSwoosh, CSwooshEdge *pEdge) ;

void func_80041760(CFxSystem *pThis, CSwoosh *pSwoosh, Mtx *pmtDrawMtxs) ;

void func_80042794(CFxSystem *pThis, CGameObjectInstance *pObject, CSwooshInfo *pInfo) ;
void func_80042800(CFxSystem *pThis, CParticle *pParticle, CSwooshInfo *pInfo) ;


void func_80042564(CFxSystem *pThis, CGameObjectInstance *pObject, Mtx *pmtDrawMtxs) ;
void func_800425F8(CFxSystem *pThis, CParticle *pParticle, Mtx *pmtDrawMtxs) ;

void func_80042740(CFxSystem *pThis, CGameObjectInstance *pObject) ;
void func_800426EC(CFxSystem *pThis, CParticle *pParticle) ;

void func_80042964(CFxSystem *pThis, Gfx **ppDLP) ;




void func_80042A40(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshLeftHand(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshRightHand(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void func_80042C00(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshLeftFoot(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshRightFoot(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void func_80042E84(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshWeapon2(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshTail(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshLeftToes(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_SwooshRightToes(CInstanceHdr *pThis, CVector3 vPos, float Value) ;



void func_80043028(CSpecialFx *pThis, CGameObjectInstance *pInst) ;
void func_8004305C(CSpecialFx *pThis, float *pScript) ;
void func_8004306C(CSpecialFx *pThis) ;
void func_8004345C(CSpecialFx *pThis) ;
void func_800434C0(CSpecialFx *pThis) ;
void func_8004353C(float *pVar) ;
void func_80043584(void) ;




typedef void(*TimerFxFunction)(CTimerFx *pThis) ;

CTimerFx *func_800438C8(CFxSystem *pThis,
            TimerFxFunction pFunction,
            CGameObjectInstance *pInst,
            signed long Total,
            float Spacing) ;




#define __sched__ 




#define OS_SC_STACKSIZE 0x2000

#define OS_SC_RETRACE_MSG 1
#define OS_SC_DONE_MSG 2
#define OS_SC_RDP_DONE_MSG 3
#define OS_SC_PRE_NMI_MSG 4
#define OS_SC_LAST_MSG 4
#define OS_SC_MAX_MESGS 8

typedef struct {
    short type;
    char misc[30];
} OSScMsg;

typedef struct OSScTask_s {
    struct OSScTask_s *next;
    u32 state;
    u32 flags;
    void *framebuffer;

    OSTask list;
    OSMesgQueue *msgQ;
    OSMesg msg;

    OSTime startTime;
    OSTime totalTime;

} OSScTask;




#define OS_SC_NEEDS_RDP 0x0001
#define OS_SC_NEEDS_RSP 0x0002
#define OS_SC_DRAM_DLIST 0x0004
#define OS_SC_PARALLEL_TASK 0x0010
#define OS_SC_LAST_TASK 0x0020
#define OS_SC_SWAPBUFFER 0x0040

#define OS_SC_RCP_MASK 0x0003
#define OS_SC_TYPE_MASK 0x0007







typedef struct SCClient_s {
    struct SCClient_s *next;
    OSMesgQueue *msgQ;
} OSScClient;

typedef struct {
    OSScMsg retraceMsg;
    OSScMsg prenmiMsg;
    OSMesgQueue interruptQ;
    OSMesg intBuf[8];
    OSMesgQueue cmdQ;
    OSMesg cmdMsgBuf[8];
    OSThread thread;
    OSScClient *clientList;
    OSScTask *audioListHead;
    OSScTask *gfxListHead;
    OSScTask *audioListTail;
    OSScTask *gfxListTail;
    OSScTask *curRSPTask;
    OSScTask *curRDPTask;
    u32 frameCount;
    s32 doAudio;
} OSSched;

void func_8002B830(OSSched *s, void *stack, OSPri priority,
                                  u8 mode, u8 numFields);
void osScAddClient(OSSched *s, OSScClient *c, OSMesgQueue *msgQ);
void osScRemoveClient(OSSched *s, OSScClient *c);
OSMesgQueue *func_8002BA38(OSSched *s);






#define _INC_CAMERA 





#define STATIC_SEGMENT 1
#define CFB_SEGMENT 2

#define SCREEN_HT 240
#define SCREEN_WD 320

#define IDLE_STACKSIZE 128
#define STACKSIZE 0x1000
#define MAIN_STACKSIZE 0xe000
#define AUDIO_STACKSIZE 0x4000











#define _INC_FRONTEND 







typedef struct CLegalScreen_t
{
 u32 m_Mode ;
 float m_Time ;
} CLegalScreen;

void CLegalScreen__Contruct(void) ;
void CLegalScreen__Update(void) ;
void CLegalScreen__Draw(Gfx **ppDLP) ;





typedef struct s_Credit
{
 float xs, ys ;
 char *string ;
} t_Credit ;


typedef struct CCredits_t
{
 t_Credit *pData ;
 int Pause ;
 float ScrollY ;
 float OffsetY ;
 float SizeY ;
} CCredits;

void CCredits__Contruct(void) ;
void CCredits__Update(void) ;
void func_8000BB88(Gfx **ppDLP) ;


#define LETTERBOX_SCALE 0.4

#define CAMERA_VIEW_A_BLEND 0.0
#define CAMERA_VIEW_B_BLEND 1.0

#define MAX_CAMERA_SOUND_HANDLES 8







typedef struct CCameraTrackInfo_t
{
 float m_StartYRotOffset, m_FinalYRotOffset ;
 float m_StartRadius, m_FinalRadius ;
 float m_StartEyeYOffset, m_FinalEyeYOffset ;
 float m_StartFocusYOffset, m_FinalFocusYOffset ;
} CCameraTrackInfo ;



typedef struct CCameraPosTrackInfo_t
{
 CVector3 m_vStartEye, m_vFinalEye ;
 CVector3 m_vStartFocus, m_vFinalFocus ;
 CVector3 m_vStartRotation, m_vFinalRotation ;
} CCameraPosTrackInfo ;



typedef struct CCameraView_t
{
 float m_Time ;
 CVector3 m_vEye ;
 CVector3 m_vFocus ;
 CVector3 m_vRotation ;
 float m_YRotOffset,
     m_Radius,
     m_EyeYOffset,
     m_FocusYOffset ;
} CCameraView ;



typedef struct CShake_t
{
 float m_Shake ;
 float m_LastShake ;
 float m_Amp ;
 float m_Angle ;
} CShake ;



typedef struct CCamera_t
{

 float m_PixelXScale ;
 float m_PixelYScale ;


 signed short m_Mode ;
 float m_Time ;
 int m_CinemaMode ;
 int m_CinemaFadingOut ;
 int m_NextCinematicStage ;
 int m_StartPressed ;
 signed short m_Stage ;
 float m_StageTime ;


 u16 m_PerspNorm;
 float m_LetterBoxScale ;
 signed short m_LetterBoxTop ;
 signed short m_LetterBoxBottom ;


 float m_Fov, m_AspectRatio ;
 CCameraView m_View ;
 float m_ViewBlend ;
 CCameraView m_ViewA, m_ViewB, m_ViewC ;

 CVector3 m_vPos ;
 CVector3 m_vRotation ;


 CGameObjectInstance *m_pObject ;


 CCameraTrackInfo *m_pTrackInfo ;
 CVector3 m_vPos1, m_vPos2 ;


 float m_XScale, m_YScale ;
 float m_WaterWobbleXScale, m_WaterWobbleYScale ;
 float m_WaterWobbleXAngle, m_WaterWobbleYAngle ;
 float m_WaterWobbleXSpeed, m_WaterWobbleYSpeed ;


 CShake m_ShakeX, m_ShakeY, m_ShakeZ ;
 CVector3 m_vTremor ;


 signed long m_WarpMode ;
 float m_WarpTime ;
 CVector3 m_vWarpPos ;
 float m_WarpXScale ;
 float m_WarpYScale ;
 float m_WarpSpin ;


 signed long m_UserSoundHandles[8] ;

 signed long m_Flags ;
} CCamera ;



typedef struct s_CCameraModeInfo
{
 void(*SetupFunction)(CCamera *pThis) ;
 void(*Function)(CCamera *pThis) ;
} CCameraModeInfo ;






void func_8003792C(CCamera *pThis) ;
void func_80037960(CCamera *pThis) ;


void func_80039C30(CCamera *pThis) ;
void func_8003EE90(CCamera *pThis) ;





#define CCamera__StopTrackingObject(pThis) (pThis)->m_pObject = NULL
#define CCamera__SetObjectToTrack(pThis,pObject) (pThis)->m_pObject = pObject





void func_80037EEC(CCamera *pThis) ;
void func_80038B94(CCamera *pThis, Gfx **ppDLP);
void func_80038E94(CCamera *pThis, signed long NewMode) ;

void func_80038EF0(CCamera *pThis) ;

int func_80038F30(CCamera *pThis, CVector3 *pvPos, float Radius) ;

int func_80039030(CGameObjectInstance *pThis, float Radius) ;

void func_8003911C(CCamera *pThis, CVector3 *pvCurrentPos,
            CVector3 *pvOutPos, float EndRadius) ;

void func_800392DC(CCamera *pThis, CVector3 vDesired) ;

void func_800396F8(CCamera *pThis) ;





void func_800378B8(CCameraView *pThis) ;

void func_80039368(CCameraView *pThis, float Time, CCameraView *pViewA, CCameraView *pViewB) ;
void func_800393E0(CCameraView *pThis, CCameraPosTrackInfo *pInfo, float Time) ;
void func_80039494(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time, CVector3 *pvPos, float RotYOffset) ;
void func_800395D4(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time, CGameObjectInstance *pObject) ;
void func_8003960C(CCameraView *pThis, CCameraTrackInfo *pInfo, float Time) ;

void func_80039638(CCameraView *pThis, CVector3 *pvPos, float Speed) ;
void func_80039698(CCameraView *pThis, CVector3 *pvPos, float Speed) ;






void CCamera__FadeToCinema(CCamera *pThis, signed long CinemaFlag) ;
int CCamera__CheckForTurokDeathCinematic(CCamera *pThis) ;
int func_80039B98(CCamera *pThis) ;
int func_80039BA0(CCamera *pThis) ;
int func_80039BCC(CCamera *pThis) ;
int func_80039BF0(CCamera *pThis) ;






void func_800376EC(CShake *pThis, float Shake) ;

#define CCamera__SetShakeX(pThis,Shake) func_800376EC(&((pThis)->m_ShakeX), Shake) ;
#define CCamera__SetShakeY(pThis,Shake) func_800376EC(&((pThis)->m_ShakeY), Shake) ;
#define CCamera__SetShakeZ(pThis,Shake) func_800376EC(&((pThis)->m_ShakeZ), Shake) ;

#define CCamera__SetShake(pThis,x,y,z) CCamera__SetShakeX(pThis,x) ; CCamera__SetShakeY(pThis,y) ; CCamera__SetShakeZ(pThis,z) ;








void func_80037B0C(CCamera *pThis) ;
void func_80037B3C(CCamera *pThis) ;
void func_80037EC4(CCamera *pThis) ;
void func_80037ED8(CCamera *pThis) ;






void func_80037A84(CCamera *pThis) ;
void func_80037AB8(CCamera *pThis, signed long Index) ;
void func_80037AFC(CCamera *pThis, signed long Index, signed long Handle) ;





#define _INC_SUN 






typedef struct CSunFrameData_t
{
 u64 m_DepthData[2];
 int m_DepthPos;
 int m_Visible,
     m_VisibleZ,
     align;
} CSunFrameData;




void func_800984B0(CSunFrameData *pThis);
void func_800984BC(CSunFrameData *pThis);



typedef struct CSun_t
{
 int m_nBuffer, m_nReceived;
 float m_ScreenX, m_ScreenY,
     m_Opacity;
 CVector3 m_vDir;
 int m_Visible;
} CSun;





void func_800985E4(CSun *pThis);
void func_80098638(CSun *pThis, CVector3 *pvDir);
void func_80098670(CSun *pThis, int *pVisible, float *pX, float *pY, float *pOpacity);
void func_800986F4(CSun *pThis, Gfx **ppDLP);




extern CSun sun;






#define _INC_TRAIN 







enum TrainingModes
{
 TRAINING_NULL,
 TRAINING_FADEUP,
 TRAINING_NORMAL,
 TRAINING_FADEDOWN
} ;







typedef struct CTraining_t
{

 signed long m_Mode ;
 float m_Alpha ;

 s32 m_ID ;

} CTraining ;





void func_80087B10(CTraining *pThis, s32 id) ;
void func_80087B38(CTraining *pThis) ;
void func_80087B94(CTraining *pThis, Gfx **ppDLP) ;


#define THREAD_RMON 0
#define THREAD_IDLE 1
#define THREAD_AUDIO 3
#define THREAD_SCHED 4
#define THREAD_FAULT 5
#define THREAD_MAIN 6

#define PRIORITY_IDLEINIT 10
#define PRIORITY_IDLE OS_PRIORITY_IDLE
#define PRIORITY_MAIN 10
#define PRIORITY_AUDIO 12
#define PRIORITY_AUDIOLOCK 13
#define PRIORITY_SCHEDULER 14
#define PRIORITY_SCHEDLOCK 15

#define LOG_SCHEDULE_GFX_TASK 101
#define LOG_RDP_DONE 102
#define LOG_RETRACE 103
#define LOG_INTR 104


#define PLAYER_NOT_NEAR_WATER 0
#define PLAYER_BELOW_WATERSURFACE 1
#define PLAYER_ABOVE_WATERSURFACE 2
#define PLAYER_ON_WATERSURFACE 3


#define PLAYER_NOT_NEAR_CLIMBING_SURFACE 0
#define PLAYER_AT_CLIMBING_SURFACE 1


#define PLAYER_NOT_DUCKING 0
#define PLAYER_DUCKING 1
#define PLAYER_DUCKING_ENTRANCE_EXIT 2


#define CONTROLLER_MSG (OS_SC_LAST_MSG + 1)
#define MSG_FAULT 0x10

#define DMA_QUEUE_SIZE 200
#define MAX_MESGS 64

#define NUM_FIELDS 1

typedef union
{
 struct
 {
  short type;
 } gen;
 struct
 {
  short type;
 } done;
 OSScMsg app;
} GFXMsg;

typedef struct CFrameData_t
{
 Mtx m_mProjection;
 LookAt m_LookAt;
 CSunFrameData m_SunFrame;
 OSScTask m_Task,
       m_LineTask;
 GFXMsg m_Msg;
 void *m_pFrameBuffer;
 Gfx *m_pDisplayList,
       *m_pLineList;
 unsigned long m_DisplayListSize,
       m_LineListSize,
       m_nPredictFields;
 int m_DrawMap;
} CFrameData;

enum CodeSections { FRONTEND_CODE_SECTION, GAME_CODE_SECTION, END_OF_CODE_SECTIONS };

enum MainModes
{
 MODE_RESETGAME,
 MODE_LEGALSCREEN,

 MODE_INTRO,
 MODE_TITLE,






 MODE_GAME,
 MODE_GAMEOVER,

 MODE_RESETLEVEL,

 MODE_WAITFORDISPLAY,

 MODE_CREDITS,

 MODE_GAMEPAK,


 MODE_GALLERY
};



#define INTRO_ACCLAIM_LOGO_WARP_ID 32000
#define INTRO_IGGY_WARP_ID 32001
#define INTRO_TUROK_DRAWING_BOW_WARP_ID 32002
#define INTRO_ZOOM_TO_LOGO_WARP_ID 32003
#define LEGALSCREEN_WARP_ID 32004

#define GAME_INTRO_WARP_ID 32100
#define GAME_INTRO_KEY_WARP_ID 32101

#define CHEAT_GALLERY_WARP_ID 32200

#define END_SEQUENCE_WARP_ID 32300

#define CREDITS_WARP_ID 32400



enum FadeModes
{
 FADE_NULL,
 FADE_UP,
 FADE_DOWN
} ;

enum LevelStatuses
{
 LEVEL_RESET,
 LEVEL_CHANGE
} ;



typedef struct CPersistantData_t
{
 int SemiAutomaticPistolFlag,
   RiotShotgunFlag,
   AutomaticShotgunFlag,
   AssaultRifleFlag,
   MachineGunFlag,
   MiniGunFlag,
   GrenadeLauncherFlag,
   TechWeapon1Flag,
   RocketFlag,
   ShockwaveFlag,
   TechWeapon2Flag,
   ChronoSceptorFlag ;

 int ArmorFlag,
   BackPackFlag ;

 int BulletPool,
   ShotgunPool,
   EnergyPool,
   ExpTekBowAmmo,
   ExpShotgunPool,
   TekBowAmmo,
   MiniGunAmmo,
   GrenadeLauncherAmmo,
   RocketAmmo,
   TechWeapon2Ammo,
   ChronoSceptorAmmo;

 int ArmorAmount ;

 int WeaponUsing ;

 int Level2Keys,
   Level3Keys,
   Level4Keys,
   Level5Keys,
   Level6Keys,
   Level7Keys,
   Level8Keys ;
 int Level2Access,
   Level3Access,
   Level4Access,
   Level5Access,
   Level6Access,
   Level7Access,
   Level8Access ;
 int ChronoSceptorPieces ;

 int Difficulty ;


 int RunWalk ;
 int ControlSide ;
 int Blood ;
 int Stereo ;
 u32 MusicVolume ;
 u32 SFXVolume ;
 u32 Opacity ;
 u32 HAnalog ;
 u32 VAnalog ;
 u32 CheatFlags ;
 u32 EnabledCheatFlags ;

 int Health,
   MaxHealth,
   Tokens,
   Lives ;

 u16 Checkpoint ;

 float BestTrainTime ;

 signed long BossFlags ;

 u32 Crash ;

} CPersistantData;






typedef struct CEngineApp_t
{

 CFrameData m_FrameData[3];
 CFrameData *m_pCurrentFrameData;

 CPersistantData *m_pPersistant;

 CScene m_Scene;
 COnScreen m_OnScreen;

 CBossesStatus m_BossesStatus ;
 signed long m_BossFlags ;
 CGameObjectInstance *m_pBossActive ;
 CBossVars m_BossVars ;

 CCamera m_Camera;
 CFxSystem m_FxSystem ;

 CPause m_Pause;
 COptions m_Options;
 CKeys m_Keys;
 CLoad m_Load;
 CSave m_Save;
 CRequestor m_Requestor;
 CMessageBox m_MessageBox;
 CCheatCode m_CheatCode;
 CGiveCheatCode m_GiveCheatCode;
 CCheat m_Cheat;
 CGInst m_GInst;
 CGamePak m_GamePak;
 unsigned long m_Mode, m_NextMode ;

 unsigned long m_dwCheatFlags,
       m_dwEnabledCheatFlags;
 int m_Level ;
 int m_BossLevel ;

 signed long m_hMusic;

 u8 m_FadeFast, m_FadeStatus, unused1, unused2;
 unsigned char m_PortraitNameMode;

 float m_FadeAlpha ;

 float m_RotY,
       m_RotXOffset, m_RotYOffset, m_RotZOffset,
       m_XPos, m_YPos, m_ZPos,
       m_YPosOffset,
       m_TranslateHorizontal,
       m_TranslateVertical;
 CQuatern m_qGround,
       m_qViewAlign,
       m_qViewAlignNoZ;
 CMtxF m_mfViewOrient,
       m_mfProjection;
 CVector3 m_vTCorners[5];

 Gfx *m_pDLP;
 void *m_pStaticSegment;
 int m_DebugMode,
       m_DoIdle,
       m_SloMo,
       m_LegalBypass,
       m_GamePakCheck,
       m_FirstRun,
       m_JustLoadedGame,
       retail_unknown_before_map_mode,
       m_MapMode ;

 int m_LegalTimer ;

 float m_MapAlpha ;
 u16 m_MapStatus ;

 float m_GameOverAlpha ,
       m_GameOverMode,
       m_GameOverTime ;

 float m_TitleAlpha ;


 float m_LevelTime ;
 float m_BestTrainTime ;

 float m_ModeTime ;

 int m_bTrainingMode ;
 int m_bTraining ;
 int m_TrainingType ;
 CTraining m_Training ;


#define EASY 0
#define MEDIUM 1
#define HARD 2
 int m_Difficulty ;

 int m_bGameOver,
       m_bReset,
       m_bPause,
       m_bOptions,
       m_bKeys,
       m_bLoad,
       m_bSave,
       m_bRequestor,
       m_bMessageBox,
       m_bCheatCode,
       m_bGiveCheatCode,
       m_bCheat,
       m_bGInst,
       m_bGamePak,
       m_bDebug,
       m_UnderWater;
 u8 m_Flash,
       m_FlashDec,
       m_Alpha,
       m_AlphaDec;

 unsigned long m_nCurrentRegionSet;
 float m_cRegionSetBlend;
 unsigned char m_FogColor[4],
       m_LastFogColor[4],
       m_FlashColor[4];
 float m_FarClip,
       m_LastFarClip,
       m_FieldOfView,
       m_LastFieldOfView,
       m_SkySpeed,
       m_SkyElevation,
       m_LastSkySpeed,
       m_LastSkyElevation;
 unsigned long m_FogStart,
       m_LastFogStart;

#define RETURN_WARP_ID -1
#define CINEMA_WARP_ID -2
#define CRASH_WARP_ID -3

#define WARP_NOT_WARPING 0
#define WARP_WARPING_OUT 1
#define WARP_WARPING_IN 2
 int m_Warp,
       m_WarpID,
       m_CurrentWarpID,
       m_WarpSound;
 int m_WarpBase ;
 int m_PlayedSound;
 float m_uWarp,
       m_WarpLength;
 unsigned char m_WarpColors[4];

#define DEATH_NOT_DIEING 0
#define DEATH_DIEING 1
#define DEATH_WAITING 2
 int m_Death;
 float m_uDeath;

 int m_ReturnWarpSaved;
 CROMWarpPoint m_ReturnWarp;

#define CINEMA_FLAG_PLAY_DEATH (1<<0)
#define CINEMA_FLAG_PLAY_WATER_DEATH (1<<1)
#define CINEMA_FLAG_PLAY_FALL_DEATH (1<<2)
#define CINEMA_FLAG_PLAY_RESURRECT (1<<3)
#define CINEMA_FLAG_PLAY_LONGHUNTER (1<<4)
#define CINEMA_FLAG_PLAY_FINAL_HUMVEE (1<<5)
#define CINEMA_FLAG_TUROK_KILL_MANTIS (1<<6)
#define CINEMA_FLAG_MANTIS_KILL_TUROK (1<<7)
#define CINEMA_FLAG_TUROK_KILL_TREX (1<<8)
#define CINEMA_FLAG_TREX_KILL_TUROK (1<<9)
#define CINEMA_FLAG_TUROK_KILL_LONGHUNTER (1<<10)
#define CINEMA_FLAG_TUROK_KILL_CAMPAIGNER (1<<11)
#define CINEMA_FLAG_CAMPAIGNER_KILL_TUROK (1<<12)
#define CINEMA_FLAG_TUROK_PICKUP_KEY (1<<13)
#define CINEMA_FLAG_END_SEQUENCE (1<<14)
#define CINEMA_FLAG_END_SEQUENCE2 (1<<15)
#define CINEMA_FLAG_CREDIT (1<<16)
#define CINEMA_FLAG_TUROK_VICTORY (1<<17)

 signed long m_CinemaFlags ;
 CROMWarpPoint m_CinemaWarp ;
 int m_UseCinemaWarp ;

 float m_PortraitZoom,
        m_ActualPortraitZoom,
        m_ActualPortraitRotXSpd,
        m_ActualPortraitRotYSpd,
        m_ActualPortraitRotZSpd,
        m_PortraitRotXSpd,
        m_PortraitRotYSpd,
        m_PortraitRotZSpd,
        m_PortraitAlpha,
        m_PortraitTimer;
 CVector3 m_vPortrait;
 int m_Portrait,
        m_PortraitName;
 CQuatern m_qPortraitOrientation;
 int m_PortraitExit;

 int m_LastSaveMapLevel;
 float m_MenuUpChangeCount,
        m_MenuDownChangeCount,
        m_MenuLeftChangeCount,
        m_MenuRightChangeCount;

 float m_ActualMusicVolume,
        m_ActualSFXVolume,
        m_MusicVolume,
        m_SFXVolume;


 int m_RecordMode ;
 int m_AttractMode ;

 unsigned char *m_pAttractData ;
 signed long m_AttractCurrentBit ;

 unsigned char m_AttractPadFrames ;
 OSContPad m_AttractPad ;


} CEngineApp;





void func_80001CD4(CEngineApp *pThis);
void CEngineApp__Idle(CEngineApp *pThis, void *pArg);
void CEngineApp__Main(CEngineApp *pThis);
void func_80006CE0(CEngineApp *pThis) ;

void CEngineApp__Construct(CEngineApp *pThis);

#define CEngineApp__GetFrameData(pThis) ((pThis)->m_pCurrentFrameData)
#define CEngineApp__GetSunFrameData(pThis) (&(pThis)->m_pCurrentFrameData->m_SunFrame)
#define CEngineApp__GetStaticAddress(pThis) ((pThis)->m_pStaticSegment)
void CEngineApp__ClearZBuffer(CEngineApp *pThis, int sx, int ex, int sy, int ey);


void CEngineApp__DrawWater(CEngineApp *pThis);

void CEngineApp__DoFlash(CEngineApp *pThis, u8 Flash, u8 FlashDec);
void CEngineApp__DoColorFlash(CEngineApp *pThis, u8 Flash, u8 FlashDec, int r, int g, int b);
void CEngineApp__DrawTint(CEngineApp *pThis, unsigned char Color[4]);

#define CEngineApp__GetInstance(pThis,nInst) ((pThis)->m_Scene.m_pInstances[nInst])
#define CEngineApp__GetAllInstanceCount(pThis) ((pThis)->m_Scene.m_nInstances)

#define CEngineApp__GetPlayer(pThis) ((pThis)->m_Scene.m_pPlayer)

#define CEngineApp__GetAnimInstance(pThis,nInst) ((pThis)->m_Scene.m_pActiveAnimInstances[nInst])
#define CEngineApp__GetAnimInstanceCount(pThis) ((pThis)->m_Scene.m_nActiveAnimInstances)

int CEngineApp__GetPlayerWaterStatus(CEngineApp *pThis);
float CEngineApp__GetPlayerWaterDepth(CEngineApp *pThis);
int func_800028C4(CEngineApp *pThis);

float func_80002678(CEngineApp *pThis);
float func_80002614(CEngineApp *pThis);
#define CEngineApp__GetEyePos(pThis) ((pThis)->m_vTCorners[0])
int func_80002950(CEngineApp *pThis);
float func_800029FC(CEngineApp *pThis);
float func_80002A44(CEngineApp *pThis);
int func_80002A8C(CEngineApp *pThis);


void CEngineApp__DoDeath(CEngineApp *pThis);
void CEngineApp__GetScreenCoordinates(CEngineApp *pThis, CVector3 *pvIn, float *pX, float *pY);

#define WARP_WITHINLEVEL 0
#define WARP_BETWEENLEVELS 1
void CEngineApp__Warp(CEngineApp *pThis, int WarpID, int nType, int StoreWarpReturn);
void func_80005690(CEngineApp *pThis);

int CEngineApp__MenuDown(CEngineApp *pThis);
int CEngineApp__MenuUp(CEngineApp *pThis);
int CEngineApp__MenuLeft(CEngineApp *pThis);
int CEngineApp__MenuRight(CEngineApp *pThis);

float CEngineApp__GetEnemySpeedScaler(CEngineApp *pThis);
float CEngineApp__GetBossHitPointScaler(CEngineApp *pThis) ;

void CEngineApp__ResetBossVars(CEngineApp *pThis);





extern CMtxF mf_3dstudio_to_u64;


extern Mtx mtx_identity;


extern Vtx shadow_vtxs[4];


extern int D_80119908, D_8011990C,
      cntrlStart;
extern GFXMsg *pMsg;
extern int wait, joyReadCount, nWaitBlack;
extern CFrameData *pFrameData;
extern int nDisplayLists,
      nNextFields;







#define GetApp() (&D_800F9F10)
#define GetCache() (&D_800F9F10.m_Scene.m_Cache)




extern unsigned short cfb_16_a[];
extern unsigned short cfb_16_b[];
extern unsigned short cfb_16_c[];
extern unsigned short zbuffer[];
extern Gfx display_list_a[];
extern Gfx display_list_b[];
extern Gfx line_list_a[];
extern Gfx line_list_b[];


extern u64 fifo_buffer[];
extern u64 gfx_yield_buf[];

extern u64 dram_stack[];
extern u64 boot_stack[];
extern u64 schedule_stack[];
extern u64 idle_thread_stack[];

#define fault_thread_stack boot_stack


extern u64 main_thread_stack[];
extern u64 audio_stack[];

#define MEMORY_POOL_SIZE 0x16A000
extern u32 dynamic_memory_pool[];




extern OSMesgQueue dmaMessageQ;
extern OSIoMesg dmaIOMessageBuf;
extern OSMesgQueue romMessageQ;
extern OSMesg romMessageBuf;
extern OSIoMesg romIOMessageBuf;
extern OSMesgQueue D_800F9C20;
extern OSMesg gfxFrameMsgBuf[64];




extern unsigned long D_800B6AF0;
extern unsigned long D_800B6AF8;
extern unsigned long D_800B6AF4;

#define MICROCODE_HIGH_PRECISION 0
#define MICROCODE_LOW_PRECISION 1
extern unsigned long microcode_version;

extern unsigned long c_field;
extern unsigned long n_fields;
extern unsigned long n_l_fields;
extern unsigned long n_ll_fields;
extern unsigned long n_lll_fields;
extern unsigned long c_waiting;
extern unsigned long n_waiting;
extern unsigned long c_finished;
extern unsigned long n_pending;
extern CFrameData *p_waiting_frames[3];
extern int allow_task_sends;
extern void *p_current_fb;
extern void *p_pending_fb;

extern float D_800B6B00;
extern float D_800B6B04;
extern float D_800B6B08;
extern float D_800B6B0C;
extern float old_enemy_speed_scaler;
extern float old_particle_speed_scaler;
extern float old_sky_speed_scaler;

extern float weapon_z_rotation;

extern float rsp_total_time;
extern float rsp_audio_time;
extern float rsp_graphics_time;
extern float rdp_time;
extern float cpu_time;

extern float refresh_rate;




#define RENDERMODE_CLEAR 0
#define RENDERMODE_INTER 1
#define RENDERMODE_CUTOUT 2
#define RENDERMODE_CLOUD 3
#define RENDERMODE_CLOUD_NO_Z 4
#define RENDERMODE_CLOUD_SPARKLE 5
#define RENDERMODE_XLU 6
#define RENDERMODE_XLU_ZUPD 7
#define RENDERMODE_SURF 8
#define RENDERMODE_DECAL 9

extern int player_is_moving;
extern int cache_is_valid;

extern CViewVolume view_volume;
extern CBoundsRect view_bounds_rect,
       anim_bounds_rect;

extern unsigned char *scratch_area;
extern int scratch_area_size;

extern int Controller;
extern CTControl *D_800F9E44;

extern CEngineApp D_800F9F10;

void func_80004504(CEngineApp *pThis, unsigned long Mode) ;
void CEngineApp__Reset(CEngineApp *pThis, unsigned long NewMode);
void func_80009FBC(CEngineApp *pThis) ;


void func_8002BB80(OSSched *sc, OSScTask *pTask);




extern Vp vp;


extern Gfx rspinit_dl[];
extern Gfx rdpinit_dl[];
extern Gfx clearcfb_dl[];
extern Gfx mip_map_dl[];
extern Gfx mip_map_mirror_dl[];
extern Gfx mip_map_detail2x2_dl[];
extern Gfx mip_map_detail4x4_dl[];
extern Gfx shadow_dl[];
extern Gfx decal_shadow_dl[];

extern Lights1 thelight;




#define SCALING_MAX_VISIBLE_DISTANCE 100.0
#define SCALING_FAR_CLIP 1024.0

#define SCALING_NEAR_CLIP (((int)SCALING_FAR_CLIP) >> 6)

#define SCALING_FACTOR (SCALING_FAR_CLIP/SCALING_MAX_VISIBLE_DISTANCE)
#define SCALING_MINIMUM_OBJECT_SCALE 0.5
#define SCALING_SIMPLE_OBJECT_SCALE 0.35
#define SCALING_DETAIL_OBJECT_SCALE 0.2
#define SCALING_DEF_INSTANCE_SCALE 0.02
#define SCALING_PLAYERWEAPON_SCALE 0.03
#define SCALING_PLAYER_SCALE 0.02
#define SCALING_SIMPLE_SCALE 1.0






#define DEFAULT_FOG_THICKNESS 0.8
#define DEFAULT_FIELD_OF_VIEW 47.5
#define FIELD_OF_VIEW_ANGLE(fov,aspect) ((fov)*(aspect))

#define SCALING_MAX_DIST(farClip,fov) (farClip/cos((fov)*(3.14159265358979323846/180.0)/2.0))











#define __TMOVEH 







#define SCALING_MAX_VISIBLE_DISTANCE 100.0
#define SCALING_FAR_CLIP 1024.0

#define SCALING_NEAR_CLIP (((int)SCALING_FAR_CLIP) >> 6)

#define SCALING_FACTOR (SCALING_FAR_CLIP/SCALING_MAX_VISIBLE_DISTANCE)
#define SCALING_MINIMUM_OBJECT_SCALE 0.5
#define SCALING_SIMPLE_OBJECT_SCALE 0.35
#define SCALING_DETAIL_OBJECT_SCALE 0.2
#define SCALING_DEF_INSTANCE_SCALE 0.02
#define SCALING_PLAYERWEAPON_SCALE 0.03
#define SCALING_PLAYER_SCALE 0.02
#define SCALING_SIMPLE_SCALE 1.0






#define DEFAULT_FOG_THICKNESS 0.8
#define DEFAULT_FIELD_OF_VIEW 47.5
#define FIELD_OF_VIEW_ANGLE(fov,aspect) ((fov)*(aspect))

#define SCALING_MAX_DIST(farClip,fov) (farClip/cos((fov)*(3.14159265358979323846/180.0)/2.0))






#define _INC_AI 









#define SCALING_MAX_VISIBLE_DISTANCE 100.0
#define SCALING_FAR_CLIP 1024.0

#define SCALING_NEAR_CLIP (((int)SCALING_FAR_CLIP) >> 6)

#define SCALING_FACTOR (SCALING_FAR_CLIP/SCALING_MAX_VISIBLE_DISTANCE)
#define SCALING_MINIMUM_OBJECT_SCALE 0.5
#define SCALING_SIMPLE_OBJECT_SCALE 0.35
#define SCALING_DETAIL_OBJECT_SCALE 0.2
#define SCALING_DEF_INSTANCE_SCALE 0.02
#define SCALING_PLAYERWEAPON_SCALE 0.03
#define SCALING_PLAYER_SCALE 0.02
#define SCALING_SIMPLE_SCALE 1.0






#define DEFAULT_FOG_THICKNESS 0.8
#define DEFAULT_FIELD_OF_VIEW 47.5
#define FIELD_OF_VIEW_ANGLE(fov,aspect) ((fov)*(aspect))

#define SCALING_MAX_DIST(farClip,fov) (farClip/cos((fov)*(3.14159265358979323846/180.0)/2.0))







#define AI_GetEA(pThis) ((pThis)->ah.ih.m_pEA)
#define AI_GetDyn(pThis) (&((pThis)->m_AI))
#define AI_GetPos(pThis) ((pThis)->ah.ih.m_vPos)
#define AI_GetVelocity(pThis) (&(pThis)->ah.m_vVelocity)

extern int AICollidedWithWall ;



#define DAMAGE_NORMAL 0
#define DAMAGE_BLADE 1
#define DAMAGE_KICK 2
#define DAMAGE_PARTICLE 3



#define AVOIDANCE_RADIUS_DISTANCE_FACTOR 1.5
#define AVOIDANCE_FLYING_RADIUS_DISTANCE_FACTOR 4





int func_8007636C (int Event);
int func_80070D48 (int Event);
int func_80063630 (int Event);
void AI_Single_Event (CInstanceHdr *pThis, CInstanceHdr *pOrigin, int Event, CVector3 vPos, float Value);
void AI_Event_Dispatcher (CInstanceHdr *pThis, CInstanceHdr *pOrigin, int Event, unsigned long dwSpecies, CVector3 vPos, float Value);
void AI_Advance (CGameObjectInstance *pAI);
CGameObjectInstance *func_80076218 (CGameObjectInstance *pMe);
unsigned char func_800720C8 (CGameObjectInstance *pAI);
void AI_Multi_Event (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, int event, CVector3 vPos, float Value);
int AI_Can_See_Target (CGameObjectInstance *pMe, CGameObjectInstance *pTarget);
int AI_Make_Retreat (CGameObjectInstance *pAI, float ang);
int AI_Make_Run (CGameObjectInstance *pAI, float ang);
void AI_Make_Walk (CGameObjectInstance *pAI, float ang);
int AI_Make_Turn (CGameObjectInstance *pAI, float ang);
void func_8005F2B8 (CGameObjectInstance *pAI, short amt, short max);
void func_80074DE8 (CGameObjectInstance *pAI, short amt);
short func_80074DCC (CGameObjectInstance *pAI);
void func_80071CF0 (CGameObjectInstance *pMe);
void AI_Decrease_Health (CGameObjectInstance *pAI, int hits, int FlashScreen, int DoSounds);
int func_8005FCF4 (CGameObjectInstance *pAI, int nAnim, int InterruptBlend);
int func_8005FCA0 (CGameObjectInstance *pAI, int nAnim, int InterruptBlend);
void func_80060A54 (CGameObjectInstance *pAI, int hits);
void func_8005F840 (CInstanceHdr *pThis, int nType, CVector3 vPos);
void func_800696A8 (CAnimInstanceHdr *pThis, int nType, CVector3 vPos, int nParticles);
#define AI_DoParticleAtPlayer(pThis,nType,vPos) AI_AimParticleAtPlayer((pThis), (nType), (vPos), ANGLE_DTOR(45))
void AI_AimParticleAtPlayer (CInstanceHdr *pThis, int nType, CVector3 vPos, float MaxYRot);
void AI_GeneratePickups (CGameObjectInstance *pThis, CVector3 vPos);
struct CDynamicSimple_t *func_80063C4C(CInstanceHdr *pThis, CVector3 vPos, int nType, float Time) ;
int AI_DoSound (CInstanceHdr *pThis, int nSound, float Volume, int SndFlags);
float func_80071DA4 (CGameObjectInstance *pAI, CVector3 vPos);
float func_800747C0 (CGameObjectInstance *pAI, CVector3 vPos, CGameObjectInstance *pTarget, float radiusFactor);
void func_80072110 (CGameObjectInstance *pAI, float Angle);
float func_8005F34C (CGameObjectInstance *pAI, CVector3 vPos);
float func_80071C94 (CGameObjectInstance *pAI, CVector3 vPos);
int func_80071C8C (CGameObjectInstance *pAI);
void func_800751CC (CGameObjectInstance *pAI);
int func_80060AE4 (CGameObjectInstance *This, CInstanceHdr *pOrigin, CVector3 vPos, float rad, int nKnife);
int func_80071B18 (CInstanceHdr *pThis);
void func_8005F228 (CGameObjectInstance *pThis, CInstanceHdr *pOrigin);
void AI_FeignDeath (CGameObjectInstance *pThis);
void AI_Resurrect (CGameObjectInstance *pThis);
int func_800719B4 (CGameObjectInstance *pThis);
float func_80071934 (CGameObjectInstance *pThis);
void AI_Make_Swim (CGameObjectInstance *pAI, float ang);
void func_80072E18 (CGameObjectInstance *pAI);
void AI_Make_SwimRetreat (CGameObjectInstance *pAI, float ang);
void func_80071A88 (CGameObjectInstance *pThis);
int func_80071920 (CGameObjectInstance *pThis);
int func_80074D20 (CGameObjectInstance *pAI);
int func_80074720 (CGameObjectInstance *pAI);
void func_80074C34 (CGameObjectInstance *pAI);
void AI_Make_TeleportMoveSlow (CGameObjectInstance *pAI, float ang);
int func_8005FA10 (CGameObjectInstance *pThis);
int func_80071020 (CGameObjectInstance *pThis);
int func_8007183C (CGameObjectInstance *pThis);
int func_80063DD4 (CGameObjectInstance *pThis);
int func_80071820 (int nType);
int func_80071804 (int nType);
int func_800717E8 (int nType);
int func_800717CC (int nType);
int func_800717B4 (CGameObjectInstance *pThis);
int func_80071018 (CGameObjectInstance *pThis);
int AI_DoTeleport (CGameObjectInstance *pAI, CVector3 vDestPos);
int func_80071770 (CGameObjectInstance *pThis);
void func_8007170C (CGameObjectInstance *pThis);
int func_8005F100 (int nType);
void func_80071854 (CGameObjectInstance *pThis);
float func_8005EDD8 (CGameObjectInstance *pThis);

CVector3 func_8005ED90(CGameObjectInstance *pThis, CGameObjectInstance *pTarget) ;



void func_800620D8 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos);
void func_80062040 (CGameObjectInstance *pAI, CVector3 vPos);
void func_80061FA8 (CGameObjectInstance *pAI, CVector3 vPos);
void func_80061CC4 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, int hits, float rad, int nType);
void func_8005F3C0 (CGameObjectInstance *pAI,
                CInstanceHdr *pOrigin,
                CVector3 vPos,
                float rad,
                float ExpHits,
                int HurtPlayer,
                int EnemyFired,
                int DontHurtBigCreatures,
                float ForceMultiplier,
                int AllowDamageToDevices);
void func_800619EC (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float rad);
void func_800618E8 (CGameObjectInstance *pAI, CVector3 vPos, float Value);
void func_80061718 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_80061688 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_800615F8 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_80061568 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_800614D8 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_80061448 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_8006017C (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void AI_MEvent_PressurePlate (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_8005FC64 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void AI_MEvent_Pillar (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void AI_MEvent_SlideWall (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);
void func_8005FA74 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float rad, float ExpHits);
void func_800617A0 (CGameObjectInstance *pAI, CInstanceHdr *pOrigin, CVector3 vPos, float Value);



void func_8006BC54 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BBFC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_AcidSpitSnd (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BBB4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BB28 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BAF4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_ChargeHeadSlam (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BA88 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BA54 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006BA20 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B9B8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_EnergyBlastSnd (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B950 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B8F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B8C4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B838 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_FireBallSnd (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_JawSnap (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B798 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B764 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B70C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B6D8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B6A4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_WeaponFire (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B1C4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_WeaponCock (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006B184 (CInstanceHdr *pThis, float Value);
void AI_SEvent_Test (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006AE40 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006AF20 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006AC18 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006ABE4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006ABB0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006AB7C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006AB48 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_BurstFromGround (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_ChestThump (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A8FC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Explode (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Footfall (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069F94 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Gurgle (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A5F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Hiss (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Hitground (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Licking (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A574 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A540 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_RubbingSkin (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Scratch (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A4E4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A4B0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A47C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A448 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A220 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_WingFlap (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006A1BC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Alert1 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Alert2 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Alert3 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Alert4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Death1 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Death2 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Death3 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Death4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Injury1 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Injury2 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Injury3 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Long1 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Long2 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Long3 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069E5C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069E14 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_Taunt3 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_ViolentDeath1 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void AI_SEvent_ViolentDeath2 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069C48 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069BC4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069B78 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069B2C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069AE0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069A94 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069A48 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800699FC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800699B0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069920 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069890 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006965C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069610 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800695C4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069578 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006952C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800694E0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069494 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069448 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800607AC (CInstanceHdr *pThis, CVector3 vPos, int nTomahawk, int nHits);
void func_800693FC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800693B0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069364 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069234 (CInstanceHdr *pThis, CInstanceHdr *pOrigin, CVector3 vPos, float rad);
void func_8006364C (CInstanceHdr *pThis);
void func_80069158 (CInstanceHdr *pThis, CInstanceHdr *pOrigin, CVector3 vPos, float damage);
void AI_SEvent_DamageNudge_Target (CInstanceHdr *pThis, CInstanceHdr *pOrigin, CVector3 vPos, float damage);
void func_80069010 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068FC4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068F78 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068F2C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068EE0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068E94 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068E48 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068DFC (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068DB0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068D64 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068D18 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068CCC (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068C80 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068C34 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068BE8 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068B9C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068B50 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068B04 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068AB8 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068A6C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068A20 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800689D4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068988 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_8006893C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800688F0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800688A4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068858 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_8006880C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800687C0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068774 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80068728 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800686DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068690 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068644 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800685F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800685AC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068560 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068514 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800684C8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006847C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068430 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800683E4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068398 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006834C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068300 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800682B4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068268 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006821C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800681D0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068184 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068138 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800680EC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800680A0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068054 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80068008 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067FBC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067F70 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067F24 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067ED8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067E8C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067E40 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067DF4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067DA8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067D5C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067D10 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067CC4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067C78 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067C2C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067BE0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067B94 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067B48 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067AFC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067AB0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067A64 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067A18 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800679CC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067980 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067934 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800678E8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006789C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067850 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067804 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800677B8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006776C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067720 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800676D4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067688 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006763C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800675F0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800675A4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067558 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006750C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800674C0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067474 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067428 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800673DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067390 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067344 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800672F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800672AC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80067260 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80067214 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800671C8 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_8006717C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80067130 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800670E4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80067098 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_8006704C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80067000 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066FB4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066F68 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066F1C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066ED0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066E84 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066E38 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066DEC (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066DA0 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066D54 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066D08 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066CBC (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066C70 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066C24 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066BD8 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066B8C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066B40 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066AF4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066AA8 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066A5C (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066A10 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_800669C4 (CInstanceHdr *pThis, CVector3 vPos, float damage);
void func_80066978 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006692C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800668E0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066894 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066848 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800667FC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800667B0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066764 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066718 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800666CC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066680 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066634 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800665E8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006659C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066550 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066504 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800664B8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006646C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066420 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800663D4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066388 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006633C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800662F0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800662A4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066258 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006620C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800661C0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066174 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066128 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800660DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066090 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80066044 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065FEC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065FA0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065F54 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065F08 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065EBC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065E70 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065E24 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065DD8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065D8C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065D40 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065CF4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065CA8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065C5C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065C10 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065BC4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065B78 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065B2C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065AE0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065A94 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065A48 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800659FC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800659B0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065964 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065918 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800658CC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065880 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065834 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800657E8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006579C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065750 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065704 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800656B8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006566C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065620 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800655D4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065588 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006553C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800654F0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800654A4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065458 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006540C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800653C0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065374 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065328 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800652DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065290 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065244 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800651F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800651AC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065160 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065114 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800650C8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006507C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80065030 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064FE4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064F98 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064F4C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064F00 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064EB4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064E68 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064E1C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064D14 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064CC8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064C7C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064C30 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064BE4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064B98 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064B4C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064B00 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064AB4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064A68 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064A1C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800649D0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064984 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064938 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800648EC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800648A0 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064854 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064808 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800647BC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064770 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064724 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800646D8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006468C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064640 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800645DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064590 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064544 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800644F8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800644AC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064460 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064414 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800643C8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006437C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064330 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800642E4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064298 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8006424C (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800641D4 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064128 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_800640DC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064090 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80063AE8 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80064004 (CInstanceHdr *pThis, CVector3 vPos);
void func_80063BEC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80069BEC (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_80063D64 (CInstanceHdr *pThis, CVector3 vPos, float Value);
void func_8005F090(CInstanceHdr *pThis, CVector3 vPos, float Value ) ;
void func_8005F020(CInstanceHdr *pThis, CVector3 vPos, float Value ) ;
void func_8005EF58(CInstanceHdr *pThis, CVector3 vPos, float Value ) ;
void func_8005EE3C(CInstanceHdr *pThis, CVector3 vPos, float Value) ;
void AI_SEvent_StopFireSound(CInstanceHdr *pThis, CVector3 vPos, float Value) ;




struct CCollisionInfo2_t;





#define TMOVE_INCOMBAT_TIMER 2.5


#define TMOVE_HITSOUND_TIMER_MAX 0.4
#define TMOVE_HITSOUND_TIMER_SCREAM 0.5


#define TMOVE_MAX_RUNSPEED (2.5*SCALING_FACTOR)
#define TMOVE_MAX_WALKSPEED (1.5*SCALING_FACTOR)
#define TMOVE_MAX_BACKRUNSPEED (1.9*SCALING_FACTOR)
#define TMOVE_MAX_BACKWALKSPEED (1.2*SCALING_FACTOR)
#define TMOVE_MAX_SIDESTEPSPEED (2.5*SCALING_FACTOR)
#define TMOVE_MAX_ROLLSPEED (3.5*SCALING_FACTOR)


#define TMOVE_RUNFORWARD_SMOOTH 11.0
#define TMOVE_FORWARD_SMOOTH 6.0
#define TMOVE_BACKWARD_SMOOTH 4.0
#define TMOVE_STOP_SMOOTH 2.0
#define TMOVE_SIDESTEP_SMOOTH 4.0


#define TJUMP_UPFORCE_INC (1.5*SCALING_FACTOR)
#define TJUMP_UPFORCE_MAX (7*SCALING_FACTOR)
#define TJUMP_ROLL_FORCE (2*15.0*SCALING_FACTOR)

#define TJUMP_MULTIPLIER 5.0
#define TJUMP_LOOKANG_SMOOTH 5.0
#define TJUMP_LOOKANG_INC 0.06
#define TJUMP_UPFORCESPD_STRAIGHTEN 5.0
#define TJUMP_DOUBLEJUMP_FORCE (3*SCALING_FACTOR)
#define TJUMP_DOUBLEJUMP_THRESHOLD 2.1



#define TTURN_MAX_SPEED 12
#define TTURN_SMOOTH 3
#define TTURN_STOP_SMOOTH 2
#define TTURN_ANALOGUE_SCALER 4.5


#define TTHEAD_MOVE_TIME 7
#define TTHEAD_YROT_TIME (TTHEAD_MOVE_TIME*2)
#define TTHEAD_XROT_SMOOTH 8
#define TTHEAD_SPDCHGX_SMOOTH 8
#define TTHEAD_YROT_SMOOTH 8
#define TTHEAD_ZROT_SMOOTH 2
#define TTHEAD_YPOS_SMOOTH 4
#define TTHEAD_XROT_AMPLITUDE 62
#define TTHEAD_YROT_AMPLITUDE 54
#define TTHEAD_ZROT_AMPLITUDE 300
#define TTHEAD_YPOS_AMPLITUDE 0.7
#define TTHEAD_HEADSPD_DIP 5
#define TTHEAD_SPDXROT_TIGHTEN 1.9
#define TTHEAD_SPDYROT_TIGHTEN 2.8
#define TTHEAD_SPDZROT_TIGHTEN 3
#define TTHEAD_SPDYPOS_TIGHTEN 1
#define TTHEAD_HEADBACK_DIP (-ANGLE_PI/23)
#define TTHEAD_RUN_DIPUP 0.008
#define TTHEAD_ZROLL_SMOOTH 5
#define TTHEAD_ROLL_COUNT 40
#define TTHEAD_YPOS_KNEEBEND (0.1*SCALING_FACTOR)
#define TKNEE_STRAIGHTEN_SMOOTH 0.6
#define TTHEAD_GUNKICKXROT_SMOOTH 2


#define TMMODE_GROUND 0
#define TMMODE_GRDROLL 1
#define TMMODE_GRDJUMP 2
#define TMMODE_SWIMSURFACE 3
#define TMMODE_SWIMWATER 4
#define TMMODE_CLIMBING 5


#define TWEAPONMODE_OFF 0
#define TWEAPONMODE_COMINGON 1
#define TWEAPONMODE_ON 2
#define TWEAPONMODE_GOINGOFF 3
#define TWEAPONMODE_GOINGOFF_LASTBULLET 4
#define TWEAPONMODE_GOINGTOSTAYOFF 5
#define TWEAPONMODE_STAYOFF 6

#define TWEAPON_AMMO TRUE
#define TWEAPON_ANY FALSE



#define TWEAPON_NONE 0
#define TWEAPON_KNIFE 1
#define TWEAPON_TOMAHAWK 2
#define TWEAPON_TEKBOW 3
#define TWEAPON_SEMIAUTOMATICPISTOL 4
#define TWEAPON_ASSAULTRIFLE 5
#define TWEAPON_MACHINEGUN 6
#define TWEAPON_RIOTSHOTGUN 7
#define TWEAPON_AUTOMATICSHOTGUN 8
#define TWEAPON_MINIGUN 9
#define TWEAPON_GRENADELAUNCHER 10
#define TWEAPON_TECHWEAPON1 11
#define TWEAPON_TECHWEAPON2 12
#define TWEAPON_ROCKET 13
#define TWEAPON_SHOCKWAVE 14
#define TWEAPON_CHRONOSCEPTER 15
#define TWEAPON_TOTAL 15


#define TWEAPON_BULLET1_HITS 5
#define TWEAPON_PLASMA1_HITS 25
#define TWEAPON_PLASMA2_HITS 35
#define TWEAPON_ARROW_HITS 20
#define TWEAPON_SHOTGUN_HITS 6


#define TWEAPON_ENEMY_BULLET_HITS 1
#define TWEAPON_EPLASMA1_HITS 3
#define TWEAPON_EPLASMA2_HITS 3
#define TWEAPON_ACIDSPIT_HITS 6
#define TWEAPON_FIREBALL_HITS 10
#define TWEAPON_HULK_BLASTER_HITS 5
#define TWEAPON_RAPTOR_PROJECTILE_HITS 3
#define TWEAPON_SPELLCAST_HITS 7
#define TWEAPON_ROBOT_BULLET_HITS 4
#define TWEAPON_ROBOT_ROCKET_HITS 25


#define TWEAPON_BULLET_TUROK_TYPE 1
#define TWEAPON_BULLET_ENEMY_TYPE 2
#define TWEAPON_GRENADE_TYPE 3
#define TWEAPON_PLASMA1_TUROK_TYPE 4
#define TWEAPON_PLASMA1_ENEMY_TYPE 5
#define TWEAPON_ARROW_TYPE 6
#define TWEAPON_ACIDSPIT_TYPE 7
#define TWEAPON_BREATH_TYPE 8
#define TWEAPON_DEATHRAIN_TYPE 9
#define TWEAPON_ENERGYBLAST_TYPE 10
#define TWEAPON_EYEFIRE_TYPE 11
#define TWEAPON_FIREBALL_TYPE 12
#define TWEAPON_SHOCKWAVE_TYPE 13
#define TWEAPON_SPELLCAST_TYPE 14
#define TWEAPON_HULK_BLASTER_TYPE 15
#define TWEAPON_RAPTOR_PROJECTILE_TYPE 16
#define TWEAPON_PLASMA2_TUROK_TYPE 17
#define TWEAPON_ROBOT_BULLET_TYPE 18
#define TWEAPON_ROBOT_ROCKET_TYPE 19
#define TWEAPON_PLASMA2_ENEMY_TYPE 20





#define TMOVE_HEALTH_ALIVE 1
#define TMOVE_HEALTH_DEADSTART 2
#define TMOVE_HEALTH_DEADGOING 3
#define TMOVE_DEATH_TIMER 2.0



#define TWEAPON_MACHINEGUN_USECNT 0.16
#define TWEAPON_MINIGUN_USECNT 2
#define TWEAPON_ASSAULTRIFLE_USECNT 200
#define TWEAPON_RIOTSHOTGUNSHELL_USECNT 200
#define TWEAPON_TECHWEAPON2_USECNT 200



#define TWEAPON_AUTOMATICSHOTGUN_ZROT ANGLE_DTOR(4)
#define TWEAPON_MINIGUN_ZROT ANGLE_DTOR(30)
#define TWEAPON_SHOCKWAVE_ZROT ANGLE_DTOR(-5)
#define TWEAPON_SHOCKWAVE_ZROTMAX ANGLE_DTOR(-30)


#define TMOVE_NORMAL_BOWMAX 0.7
#define TMOVE_SUPER_BOWPOSITION 1.4
#define TMOVE_SUPER_BOWENDPOSITION 2.15
#define TMOVE_BOW_MAXVELOCITY (50*SCALING_FACTOR)
#define TMOVE_SUPERBOW_MAXVELOCITY TMOVE_BOW_MAXVELOCITY


#define TMOVE_CHRONOSCEPTER_CHARGE_TIME 1.0



#define TMOVE_LAST_NOTINWATER 1
#define TMOVE_LAST_UNDERWATER 2
#define TMOVE_LAST_READYFORFALL 3


typedef struct
{
 float MoveSpeed,
   TurnSpeed,
   ActualTurnSpeed,
   MoveCnt,
   YRotCnt,
   HeadXRot,
   HeadYRot,
   HeadZRot,
   HeadYPos,
   SpdChgXOffset,
   SpdChgX,
   RunTime,
   SideStepSpeed,
   HeadZRoll,
   HeadZRollCnt,
   HeadYPosLand,
   JumpUpForce,
   JumpLookAng,
   GunKickXRot,
   WeaponBarrelZRot,
   WeaponBarrelZRotInc,
   HeadYPosCFrame,
   JumpAngle,
   StartJumpAngle,
   DesiredJumpAngle,
   JumpU,
   ActualRotXPlayer,
   ActualRotYPlayer,
   RotXPlayer,
   RotYPlayer,
   RotZPlayer,
   MoveUpSpeed,
   OxygenTank,
   Oxygen,
   Time1,
   Time2,
   SideStepZRot,
   BurstForwardSpeed,
   ActualBurstForwardSpeed,
   ClimbSwingRotX,
   ClimbSwingRotY,
   ClimbSwingRotZ,
   ActualClimbSwingRotX,
   ActualClimbSwingRotY,
   ActualClimbSwingRotZ,
   CurrentDuckOffset,
   ClimbSideStepLookAng,
   BurstTimer,
   SelectWeaponTimer,
   LookUpDownSpeed,
   ActualLookUpDownSpeed,
   SwimBankAngle,
   ActualSwimBankAngle,
   WaterSfxTimer,
   WaterSfxTimerMax,
   BubblesSfxTimer,
   DeathRegionTimer,
   ShockwaveStarted,
   ChronoscepterStarted,
   PrevVelocityY,
   CombatTimer,
   DeathTimer,
   HitSoundTimer,
   BowStarted,
   TremorTimer,
   TremorTimerMax,
   TremorAngle,
   TremorShake,
   TremorZRot,
   AmmoUseCounter,
   MapButtonTimer,
   RealMapOffsetX,
   RealMapOffsetZ,
   MapOffsetX,
   MapOffsetZ,
   WeaponTimer,
   LookAtShover,
   InvincibleTimer;

 int MaxHealth ;
 int CheatGiven ;





 int BulletPool,
   ShotgunPool,
   EnergyPool ;

 int ExpTekBowAmmo,
   ExpShotgunPool ;

 int KnifeAmmo,
   TomahawkAmmo,
   TekBowAmmo,





   MiniGunAmmo,
   GrenadeLauncherAmmo,

   RocketAmmo,

   TechWeapon2Ammo,
   ChronoscepterAmmo;

 int ArmorAmount ;

 int KnifeFlag,
   TomahawkFlag,
   TekBowFlag,
   SemiAutomaticPistolFlag,
   RiotShotgunFlag,
   AutomaticShotgunFlag,
   AssaultRifleFlag,
   MachineGunFlag,
   MiniGunFlag,
   GrenadeLauncherFlag,
   TechWeapon1Flag,
   RocketFlag,
   ShockwaveFlag,
   TechWeapon2Flag,
   ChronoscepterFlag;

 int ArmorFlag ;
 int BackPackFlag ;

 int LastKeyTexture ;

 int Level2Keys,
   Level3Keys,
   Level4Keys,
   Level5Keys,
   Level6Keys,
   Level7Keys,
   Level8Keys ;

 int Level2Access,
   Level3Access,
   Level4Access,
   Level5Access,
   Level6Access,
   Level7Access,
   Level8Access ;

 int ChronoSceptorPieces ;

 int SpdChg,
   Jumped,
   DoubleJump,
   WeaponUsed,
   WeaponChanged,
   WeaponEmpty,
   MiniGunBarrelSFX,
   RunWalkToggle,
   SwimBurstToggle,
   CannotSwimUp,
   ClimbHand,
   ClimbOneHand,
   FiredParticle,
   FiredParticleType,
   FiredProjectileParticle,
   FiredProjectileParticleType,
   ClimbCameraWobble,
   ClimbWeaponRemove,
   JumpAllowed,
   ClimbSideStep,
   CannotJumpFromSurface,
   PrevOnGround,
   CurrentOnGround,
   JustWarped,
   JustEnteredDeathRegion,
   JustEnteredSaveRegion,
   JustEnteredLockRegion,
   JustEnteredTrainingRegion,
   OxygenOut,
   OnLadder,
   InAntiGrav,
   PrevAntiGrav,
   HitSoundTimerScream,
   CannotJumpFromCliffFace,
   BowFlashOccurred,
   FiredBullet1,
   FiredBullet2,
   FiredBullet3,
   FiredShotgunShell,
   MapToggle,
   MapScrolling,
   InLava,
   FireFirstMachineGunBullet,
   AllWeaponsAmmoGiven,
   WeaponTakeOffQuickly,
   JustEnteredPressurePlate,
   Active,
   InSun;

 u8 Mode,
   PrevMode,
   WeaponSelect,
   WeaponSelectIndex,
   WeaponCurrent,
   WeaponCurrentAnim,
   WeaponMode,
   DeathStage;

 s8 WeaponCount;

 int WeaponFired,
   hSFXBarrel,
   Bubbles,
   FeetOnBottomStatus,
   WeaponAtStartOfClimb,
   WeaponAtStartOfWaterDive,
   WeaponAtStartOfDuck,
   Tokens,
   Lives,
   WaterFlag,
   hSFXPrevShockwaveCharge,
   hSFXNextShockwaveCharge;

 float SpiritualTime;

 unsigned long CurrentCheckpoint;

 CVector3 vLastPosition,
     vTremorPos;
 CQuatern qRealAimFix,
     qAimFix;

 CGameObjectInstance *pShoverAI,
        *pModifyEnemy;

 unsigned char MusicID,
     AmbientSound;

 float InMenuTimer ;

 CCollisionInfo2 *pLastCI;

} CTMove;

CTMove *func_80052484 (void);

void CTMove__UpdateTurokInstance (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void func_80054CFC (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void func_80056D80 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void CTMove__GroundJumpMovement (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void func_80057134 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void func_800576EC (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
CVector3 CTMove__ControlSwimMovement (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos, struct CCollisionInfo2_t *pCollInfo, int Underwater);
void update_player_surface_swim (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void func_8005B644 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
CVector3 func_800558F0 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
CVector3 CTMove__ControlSideStep (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
CVector3 func_80056050 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
void func_8005D528 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
CVector3 func_8005D5CC (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
CVector3 func_8005D738 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
CVector3 func_8005D628 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
void CTMove__DoDucking (CTMove *pThis, CEngineApp *pApp);
void func_8005E7EC (CTMove *pThis, CTControl *D_800F9E44);
void CTMove__UpdateMap (CTMove *pThis, CEngineApp *pApp);
void func_8005ED10 (CTMove *pThis);
void func_8005ED68 (CTMove *pThis);
int func_80058AC4 (CTMove *pThis);

extern CTMove D_80128C20;
extern void func_800587B8 (CTMove *pThis, CVector3 *pvVec);
extern int func_80058708 (CTMove *pThis, int weapon);
extern int func_8005843C (CTMove *pThis, int weapon, int variation);
extern int func_80057DFC (CTMove *pThis, int weapon, int explosive) ;
extern int func_80058020(CTMove *pThis, int weapon, int explosive) ;
extern int func_800583D4 (CTMove *pThis) ;
extern void func_800587B0 (CTMove *pThis, int status);
extern void func_80057B58 (CTMove *pThis, int weapon, int amount) ;
extern void func_80057DC8 (CTMove *pThis, int *pAmt, int nAmt);
extern void func_80058B6C (CTMove *pThis, int ammo, int next);
extern void func_80059244 (CTMove *pThis, CEngineApp *pApp, float shake, float ang, int rotstyle);
extern void func_80059320 (CTMove *pThis, int wfired);
extern void CTMove__FireBullet (CTMove *pThis, int WFired);
void func_8005A670 (CTMove *pThis, int WFired);
extern void func_8005A9F8 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
extern void func_8005970C (CTMove *pThis, int nWeapon);
extern void func_800598B4 (CTMove *pThis, int nWeapon);
extern int func_80058644 (CTMove *pThis);
void func_8005AE80 (CTMove *pThis);
void func_8005AEDC (CTMove *pThis);

int func_8005AFB4 (CTMove *pThis);
void func_8005AFA8 (CTMove *pThis, float Timer);
void func_8005AF38 (CTMove *pThis);
void func_8005AFE8 (CTMove *pThis, int Direction);
void func_8005B044 (CTMove *pThis, CTControl *D_800F9E44);
void CTMove__UpdateSwimBurstToggle (CTMove *pThis, CTControl *D_800F9E44);
int func_8005863C (CTMove *pThis);
void CTMove__DoRotOffsets (CTMove *pThis, CEngineApp *pApp);
void CTMove__TiltJumping (CTMove *pThis);
void CTMove__TiltNotJumping (CTMove *pThis);
float CTMove__GetJumpAngle (CTMove *pThis);
void func_800573F0 (CTMove *pThis);
void func_80057410 (CTMove *pThis);
void func_80057428 (CTMove *pThis);
void func_80055768 (CTMove *pThis);
void func_8005C8BC (CTMove *pThis, CEngineApp *pApp);
void func_8005CB40 (CTMove *pThis, CEngineApp *pApp);
void func_8005CBDC (CTMove *pThis, CEngineApp *pApp);
void func_8005CCF0 (CTMove *pThis, CEngineApp *pApp, int DoSound);
void func_8005CD90 (CTMove *pThis, CEngineApp *pApp);
int func_8005CE10 (CTMove *pThis);
void func_8005CEBC (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void CTMove__UpdateClimbCameraRot (CTMove *pThis, CEngineApp *pApp);
int func_80058D60 (CTMove *pThis, int nType, int Reselect);
void func_80058E84 (CTMove *pThis, CEngineApp *pApp);
int func_80058E7C (CTMove *pThis);
CVector3 func_8005DDE8 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44, CVector3 vDesiredPos);
void func_80057560 (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
int func_8005E530 (CTMove *pThis, signed short *pWeaponList);
void func_8005E410 (CTMove *pThis);
int func_8005A634 (CTMove *pThis, int WFired);
float func_8005CAB0 (CTMove *pThis);
int func_8005E594 (CTMove *pThis);
int func_8005E618 (CTMove *pThis);
float func_8005E6A4 (CTMove *pThis);
void func_8005AE24 (CTMove *pThis);
int func_8005E728 (CTMove *pThis);
void func_8005E768 (CTMove *pThis, int nLives);
void func_8005278C (CTMove *pThis);
void func_80058EFC (CTMove *pThis, CVector3 vPos, float shake, float ang, float time);
void func_80058F78 (CTMove *pThis, CVector3 vPos, float time);
void func_8005901C (CTMove *pThis);
int func_8005ED4C (CTMove *pThis);
int func_8005ED5C (CTMove *pThis);
int CTMove__ModifyEnemy (CTMove *pThis, CEngineApp *pApp);
void CTMove__ChangeEnemy (CTMove *pThis, CEngineApp *pApp, int Direction);
void CTMove__MoveEnemy (CTMove *pThis, CEngineApp *pApp, CTControl *D_800F9E44);
void CTMove__ResetEnemy (CTMove *pThis);
void update_player_head_bob (CTMove *pThis);



#define __audio__ 



#define SWAP_U32(a) ( ((a) << 24) | (((a) << 8) & 0x00ff0000) | (((a) >> 8) & 0x0000ff00) | ((unsigned long)(a) >>24) )





#define SWAP_U16(a) ( ((a & 0xff) << 8) | ((unsigned short)(a) >> 8) )







#define AUDIOTRACE(x) 


#define SOUND_PLAY_MUSIC 
#define SOUND_PLAY_EFFECTS 
#define SOUND_USE_REVERB 

#define SEQUENCE_BUFFER_SIZE 16384

#define INITIAL_POS 0
#define UPDATE_POS 1

#define LOOPED_FLAG 1
#define ENVIRONMENT_LIFE 30
#define MAX_QUE_TIME 15
#define MAX_QUE 32
#define MAX_VOICES 16
#define MAX_VOICES_ALL MAX_VOICES+1
#define MIN_WORLD_VOL 0
#define MAX_WORLD_VOL 32000
#define MAX_PAN_LEFT 0
#define MAX_PAN_RIGHT 127
#define PAN_CENTER 64
#define TICKS_PER_MEASURE 1920

#define DUMMY_CHANNEL MAX_VOICES
#define DUMMY_VOICE_ID 99
#define DEBUG_TRACE 1

#define MAX_UPDATES 128

#define MAX_EVENTS 128

#define AUDIO_HEAP_SIZE 299008
#define EXTRA_SAMPLES 80
#define NUM_OUTPUT_BUFFERS 3
#define OUTPUT_RATE 22050
#define QUIT_MSG 10

#define DMA_BUFFER_LENGTH 0x800



#define NUM_ACMD_LISTS 2
#define MAX_RSP_CMDS 4096


#define NUM_DMA_BUFFERS 64


#define NUM_DMA_MESSAGES 64


#define FRAME_LAG 1




#define ENVIRONMENTAL_PRIORITY 100
#define LOOP_PRIORITY 100
#define DEFAULT_PRIORITY 50
#define DEFAULT_PITCH 0
#define DEFAULT_FXMIX 0
#define DEFAULT_PAN 64
#define DEFAULT_VOLUME 32000
#define DEFAULT_RADIUS 10
#define MAX_SEQ_LENGTH 20000

#define MAX_PITCH 1
#define MAX_SEQ_VOL 32000
#define AMBIENT_FXMIX 70
#define CATACOMBS_FXMIX 30
#define CAVE_FXMIX 60
#define CATACOMBS_LARGE_FXMIX 60
#define SEQ_FX_MIX 0


#define ELEMENT_HANDLE 0
#define CFX_HANDLE 1



#define MAX_SEQ 2
#define SEQ_FADE_SPEED 500
#define SEQ_FADE_UP (1 << 0)
#define SEQ_FADE_DOWN (1 << 1)
#define SEQ_FADE_DONE (1 << 2)
#define SEQ_LOAD_DONE (1 << 3)
#define SEQSTATE_IDLE (1 << 4)
#define SEQSTATE_FADE (1 << 5)
#define SEQSTATE_LOAD (1 << 6)
#define SEQSTATE_PLAY (1 << 7)
#define SEQSTATE_LOADING (1 << 8)


#define CUT_OFF 0
#define FADE_OUT 1


typedef struct {
    ALVoice voice;
    ALSound *sound;
    s16 priority;
    f32 pitch;
    s32 state;
    s16 vol;
    ALPan pan;
    u8 fxMix;
} ALSoundState;


typedef struct
{
    u32 outputRate;
    u32 framesPerField;
    u32 maxACMDSize;
} amConfig;






typedef struct
{
 void *ROMaddr;
 void *RAMaddr;
 signed long size;

} t_SeqInfo;


typedef struct
{
 ALBank *sfxBank;
 u8 *sfxBankPtr;
 ALSndPlayer Sndp;
 ALSndPlayer *NextPlayer;
 ALSndId idlist[16];
 signed short SoundCount;
} t_SoundPlayer;


struct CROMSoundElement_t;

typedef struct
{
 unsigned long StartTime;
 signed long Vol;
 signed long MaxVol;
 signed short FXmix;
 float Pitch;
 signed short Pan;
 void *pEnvSound;
 signed short Priority;
 signed short SfxNum;
 signed short CfxNum;
 float dist;
 signed long QuedVoice;
 CVector3 vPos;
 unsigned char RadioVolume,
        unused2;
} t_SndObject;





typedef struct
{
 float RawValue;
 float IncrValue;
} t_EnvClac;

typedef struct
{
 signed long CFXhandle;
 signed long PhysicalHandle;
 signed long VirtualHandle;
 t_SndObject theSFX;
 CROMEnvelope PitchEnv;
 t_EnvClac PitchCalc;
 CROMEnvelope VolEnv;
 t_EnvClac VolCalc;
 signed long delay;
 ALSndPlayer *SndPlayer;
 int ChannelFlags;
} t_Channel;

typedef struct s_WaitQue
{
 struct s_WaitQue *Prev;
 struct s_WaitQue *Next;
 t_Channel QuedChannel;
} t_WaitQue;

extern t_WaitQue WaitQueue;
extern t_WaitQue AvailQueue;

typedef struct
{
 CVector3 vPos;
 float YRot;
 float Radius;

} t_Ears;


typedef struct
{

 ALSynConfig SynthConfig;
 ALSndpConfig SPConfig;
 ALGlobals GlobalAudio;

 t_SoundPlayer SndPlayerList;
 signed short NumPlayers;
 t_Channel VoiceChannels[16 +1];
 t_WaitQue SFXWaitQue[32];

 signed short ChannelLock;
 t_Ears Ears;
 float VolScaleFactor;
 float PanScaleFactor;

 signed long sfx_timer;
 signed long sfx_counter;
 signed long cfx_counter;
} t_AudioWorld;

void func_8008B45C(t_Ears *EarLocation);
void func_8008B40C(float Radius);
signed short func_80089BF8(signed long VirtualHandle, CVector3 *vPos, int flags);
signed short func_80089FA0(signed short cfxnum, signed short sfxnum, signed short Priority, CVector3 *vPos, unsigned short Flags);
void func_8008A5C4(signed long VirtualHandle);
void func_8008A820(void);
void func_8008D300(ALSynConfig *c, OSPri priority, amConfig *amc);
int func_8008AD08(signed long VirtualHandle, signed long HandleType);
void update_spatial_sound(signed long channel, float X, float Y, float Z, int flags);
signed short func_8008A3B8(signed long VirtualHandle);
signed short CheckChannelStatus(signed short sfxnum, int Channel, signed short Priority);
void func_8008A0EC(int Channel, signed long VirtualHandle, CVector3 *vPos);
void func_8008A200();
signed long func_80089858(CROMSoundElement *pElement,
         void *pInstance, CVector3 *vPos,
         float Volume, float Pitch);
void func_8008AB2C(t_SoundPlayer *sndplayer, signed short i);
int func_8008AD54(void *pHandle);
int func_8008AC5C(signed long VirtualHandle, signed long HandleType);
void PlaySeq(int seqnum);
void StopSeq(int StopMode);
void func_8008B530();
void func_8008B490();
void func_80089E38(signed short Channel);
int func_80089EC4(signed short Channel);
int func_80089F10(signed short Channel);
void func_80089E70(signed short Channel);
void func_8008B654();
int LoadSeq(int nTune);
void func_8008B600(void *pThis, CCacheEntry **ppceTarget);

void func_8008A908(int CFXhandle, CVector3 *NewPos);
void func_8008A998(int CFXhandle, float NewPitch) ;
void func_8008AA5C(int CFXhandle, signed short NewVolume) ;
signed short GetSoundVolume(int CFXhandle) ;
void func_8008B854(float Music, float Sfx);
void func_8008A4DC(int nType);



void CAudioList__Construct(void) ;
void func_8008B8B8(CInstanceHdr *pInst, CVector3 vPos, float Value) ;
void func_8008B92C(void) ;




extern u64 audYieldBuf[];
extern u64 audioHeap[];
extern t_AudioWorld AW;
extern float __GlobalSFXscalar;
extern signed short __GlobalSEQvolume;
extern ALCSPlayer *seqp;





#define _INC_SFX 



#define MUSIC_UNDERWATER 100





#define __SFX_REMOVED__ -1
#define ELEMENT1 0
#define ELEMENT2 1
#define ELEMENT3 2
#define ELEMENT4 3
#define ELEMENT5 4
#define ELEMENT6 5
#define ELEMENT7 6
#define ELEMENT8 7
#define ELEMENT9 8
#define ELEMENT10 9
#define ELEMENT11 10
#define ELEMENT12 11
#define ELEMENT13 12
#define ELEMENT14 13
#define ELEMENT15 14
#define ELEMENT16 15
#define ELEMENT17 16
#define ELEMENT18 17
#define ELEMENT19 18
#define ELEMENT20 19
#define ELEMENT21 20
#define ELEMENT22 21
#define ELEMENT23 22
#define ELEMENT24 23
#define ELEMENT25 24
#define ELEMENT26 25
#define ELEMENT27 26
#define ELEMENT28 27
#define ELEMENT29 28
#define ELEMENT30 29
#define ELEMENT31 30
#define ELEMENT32 31
#define ELEMENT33 32
#define ELEMENT34 33
#define ELEMENT35 34
#define ELEMENT36 35
#define ELEMENT37 36
#define ELEMENT38 37
#define ELEMENT39 38
#define ELEMENT40 39
#define ELEMENT41 40
#define ELEMENT42 41
#define ELEMENT43 42
#define ELEMENT44 43
#define ELEMENT45 44
#define ELEMENT46 45
#define ELEMENT47 46
#define ELEMENT48 47
#define ELEMENT49 48
#define ELEMENT50 49
#define ELEMENT51 50
#define ELEMENT52 51
#define ELEMENT53 52
#define ELEMENT54 53
#define ELEMENT55 54
#define ELEMENT56 55
#define ELEMENT57 56
#define ELEMENT58 57
#define ELEMENT59 58
#define ELEMENT60 59
#define ELEMENT61 60
#define ELEMENT62 61
#define ELEMENT63 62
#define ELEMENT64 63
#define ELEMENT65 64
#define ELEMENT66 65
#define ELEMENT67 66
#define ELEMENT68 67
#define ELEMENT69 68
#define ELEMENT70 69
#define ELEMENT71 70
#define ELEMENT72 71
#define ELEMENT73 72
#define ELEMENT74 73
#define ELEMENT75 74
#define ELEMENT76 75
#define ELEMENT77 76
#define ELEMENT78 77
#define ELEMENT79 78
#define ELEMENT80 79
#define ELEMENT81 80
#define ELEMENT82 81
#define ELEMENT83 82
#define ELEMENT84 83
#define ELEMENT85 84
#define ELEMENT86 85
#define ELEMENT87 86
#define ELEMENT88 87
#define ELEMENT89 88
#define ELEMENT90 89
#define ELEMENT91 90
#define ELEMENT92 91
#define ELEMENT93 92
#define ELEMENT94 93
#define ELEMENT95 94
#define ELEMENT96 95
#define ELEMENT97 96
#define ELEMENT98 97
#define ELEMENT99 98
#define ELEMENT100 99
#define ELEMENT101 100
#define ELEMENT102 101
#define ELEMENT103 102
#define ELEMENT104 103
#define ELEMENT105 104
#define ELEMENT106 105
#define ELEMENT107 106
#define ELEMENT108 107
#define ELEMENT109 108
#define ELEMENT110 109
#define ELEMENT111 110
#define ELEMENT112 111
#define ELEMENT113 112
#define ELEMENT114 113
#define ELEMENT115 114
#define ELEMENT116 115
#define ELEMENT117 116
#define ELEMENT118 117
#define ELEMENT119 118
#define ELEMENT120 119
#define ELEMENT121 120
#define ELEMENT122 121
#define ELEMENT123 122
#define ELEMENT124 123
#define ELEMENT125 124
#define ELEMENT126 125
#define ELEMENT127 126
#define ELEMENT128 127
#define ELEMENT129 128
#define ELEMENT130 129
#define ELEMENT131 130
#define ELEMENT132 131
#define ELEMENT133 132
#define ELEMENT134 133
#define ELEMENT135 134
#define ELEMENT136 135
#define ELEMENT137 136
#define ELEMENT138 137
#define ELEMENT139 138
#define ELEMENT140 139
#define ELEMENT141 140
#define ELEMENT142 141
#define ELEMENT143 142
#define ELEMENT144 143
#define ELEMENT145 144
#define ELEMENT146 145
#define ELEMENT147 146
#define ELEMENT148 147
#define ELEMENT149 148
#define ELEMENT150 149
#define ELEMENT151 150
#define ELEMENT152 151
#define ELEMENT153 152
#define ELEMENT154 153
#define ELEMENT155 154
#define ELEMENT156 155
#define ELEMENT157 156
#define ELEMENT158 157
#define ELEMENT159 158
#define ELEMENT160 159
#define ELEMENT161 160
#define ELEMENT162 161
#define ELEMENT163 162
#define ELEMENT164 163
#define ELEMENT165 164
#define ELEMENT166 165
#define ELEMENT167 166
#define ELEMENT168 167
#define ELEMENT169 168
#define ELEMENT170 169
#define ELEMENT171 170
#define ELEMENT172 171
#define ELEMENT173 172
#define ELEMENT174 173
#define ELEMENT175 174
#define ELEMENT176 175
#define ELEMENT177 176
#define ELEMENT178 177
#define ELEMENT179 178
#define ELEMENT180 179
#define ELEMENT181 180
#define ELEMENT182 181
#define ELEMENT183 182
#define ELEMENT184 183
#define ELEMENT185 184
#define ELEMENT186 185
#define ELEMENT187 186
#define ELEMENT188 187
#define ELEMENT189 188
#define ELEMENT190 189
#define ELEMENT191 190
#define ELEMENT192 191
#define ELEMENT193 192
#define ELEMENT194 193
#define ELEMENT195 194
#define ELEMENT196 195
#define ELEMENT197 196
#define ELEMENT198 197
#define ELEMENT199 198
#define ELEMENT200 199
#define ELEMENT201 200
#define ELEMENT202 201
#define ELEMENT203 202
#define ELEMENT204 203
#define ELEMENT205 204
#define ELEMENT206 205
#define ELEMENT207 206
#define ELEMENT208 207
#define ELEMENT209 208
#define ELEMENT210 209
#define ELEMENT211 210
#define ELEMENT212 211
#define ELEMENT213 212
#define ELEMENT214 213
#define ELEMENT215 214
#define ELEMENT216 215
#define ELEMENT217 216
#define ELEMENT218 217
#define ELEMENT219 218
#define ELEMENT220 219
#define ELEMENT221 220
#define ELEMENT222 221
#define ELEMENT223 222
#define ELEMENT224 223
#define ELEMENT225 224
#define ELEMENT226 225
#define ELEMENT227 226
#define ELEMENT228 227
#define ELEMENT229 228
#define ELEMENT230 229
#define ELEMENT231 230
#define ELEMENT232 231
#define ELEMENT233 232
#define ELEMENT234 233
#define ELEMENT235 234
#define ELEMENT236 235
#define ELEMENT237 236
#define ELEMENT238 237
#define ELEMENT239 238
#define ELEMENT240 239
#define ELEMENT241 240
#define ELEMENT242 241
#define ELEMENT243 242
#define ELEMENT244 243
#define ELEMENT245 244
#define ELEMENT246 245
#define ELEMENT247 246
#define ELEMENT248 247
#define ELEMENT249 248
#define ELEMENT250 249




typedef struct CSoundSample_t
{
 int m_nSample;
 char *m_szDescription;
} CSoundSample;



extern CSoundSample sound_samples[];

#define SOUNDSAMPLE_DEFAULT 0
#define SOUNDSAMPLE_COUNT 250

enum SOUND_TYPES
{
 SOUND_MENU_OPTION_SELECT=0,
 SOUND_GAME_SAVED,
 SOUND_READY_PISTOL,
 SOUND_READY_SHOTGUN,
 SOUND_READY_TEK_WEAPON_1,
 SOUND_READY_TEK_WEAPON_2,
 SOUND_CHARGE_TEK_WEAPON_2,
 SOUND_READY_MISSILE_LAUNCHER,
 SOUND_READY_BFG,
 SOUND_KNIFE_SWISH_1,
 SOUND_KNIFE_SWISH_2,
 SOUND_KNIFE_SWISH_3,
 SOUND_BOW_STRETCH,
 SOUND_BOW_TWANG,
 SOUND_ARROW_FLY_NORMAL,
 SOUND_ARROW_FLY_TEK,
 SOUND_PISTOL_SHOT,
 SOUND_RIFLE_SHOT,
 SOUND_MACHINE_GUN_SHOT_1,
 SOUND_MACHINE_GUN_SHOT_2,
 SOUND_GRENADE_LAUNCH,
 SOUND_AUTO_SHOTGUN_SHOT,
 SOUND_RIOT_SHOTGUN_SHOT,
 SOUND_MINI_GUN_SHOT,
 SOUND_MINI_GUN_WHIR,
 SOUND_TEK_WEAPON_1,
 SOUND_TEK_WEAPON_2,
 SOUND_MISSILE_LAUNCH,
 SOUND_BFG_SHOT,
 SOUND_BLOW_GUN_SHOT,
 SOUND_HULK_BLASTER_FIRE,
 SOUND_CAMPAIGNERS_CONCUSSION,
 SOUND_CAMPAIGNERS_SCATTER_BLAST,
 SOUND_PENDULUM_SWOOSH_1,
 SOUND_PENDULUM_SWOOSH_2,
 SOUND_PENDULUM_SWOOSH_3,
 SOUND_PENDULUM_SWOOSH_4,
 SOUND_PENDULUM_SWOOSH_5,
 SOUND_METAL_SHELL_LAND,
 SOUND_SHOTGUN_SHELL_LAND,
 SOUND_INCOMING_PROJECTILE_1,
 SOUND_INCOMING_PROJECTILE_2,
 SOUND_INCOMING_PROJECTILE_3,
 SOUND_BULLET_RICOCHET_1,
 SOUND_BULLET_RICOCHET_2,
 SOUND_BULLET_RICOCHET_3,
 SOUND_BULLET_RICOCHET_4,
 SOUND_BULLET_IMPACT_1,
 SOUND_BULLET_IMPACT_2,
 SOUND_BULLET_IMPACT_3,
 SOUND_BULLET_IMPACT_4,
 SOUND_BULLET_IMPACT_5,
 SOUND_BULLET_IMPACT_6,
 SOUND_BULLET_IMPACT_7,
 SOUND_BULLET_IMPACT_8,
 SOUND_BULLET_IMPACT_9,
 SOUND_BULLET_IMPACT_10,
 SOUND_BULLET_IMPACT_13,
 SOUND_BULLET_IMPACT_14,
 SOUND_BULLET_IMPACT_15,
 SOUND_BODY_ARMOR_IMPACT_1,
 SOUND_BODY_ARMOR_IMPACT_2,
 SOUND_BODY_ARMOR_IMPACT_3,
 SOUND_BODY_ARMOR_IMPACT_4,
 SOUND_BODY_ARMOR_IMPACT_5,
 SOUND_EXPLOSION_1,
 SOUND_EXPLOSION_2,
 SOUND_EXPLOSION_3,
 SOUND_FIRE_RUMBLE,
 SOUND_FIRE_SPARK_1,
 SOUND_FIRE_SPARK_2,
 SOUND_FIRE_SPARK_3,
 SOUND_FIRE_SPARK_4,
 SOUND_FIRE_SPARK_5,
 SOUND_FIRE_SPARK_6,
 SOUND_FIRE_SPARK_7,
 SOUND_FIRE_SPARK_8,
 SOUND_TORCH_IGNIGHT,
 SOUND_ELECTRICAL_SPARK_1,
 SOUND_ELECTRICAL_SPARK_2,
 SOUND_ELECTRICAL_SPARK_3,
 SOUND_ELECTRICAL_SPARK_4,
 SOUND_ELECTRICAL_SPARK_5,
 SOUND_ELECTRICAL_SPARK_6,
 SOUND_PULLEY_SQUEAK_1,
 SOUND_PULLEY_SQUEAK_2,
 SOUND_PULLEY_SQUEAK_3,
 SOUND_PULLEY_SQUEAK_4,
 SOUND_PULLEY_SQUEAK_5,
 SOUND_ROPE_STRETCH_1,
 SOUND_ROPE_STRETCH_2,
 SOUND_ROPE_STRETCH_3,
 SOUND_ROPE_STRETCH_4,
 SOUND_ROPE_STRETCH_5,
 SOUND_STONEROCK_CRUMBLE_1,
 SOUND_STONEROCK_CRUMBLE_2,
 SOUND_STONEROCK_CRUMBLE_3,
 SOUND_STONEROCK_CRUMBLE_4,
 SOUND_STONEBOULDER_THUD ,
 SOUND_MUD_SLOSH_1,
 SOUND_MUD_SLOSH_2,
 SOUND_MUD_SLOSH_3,
 SOUND_DIRT_DEBRIS_1,
 SOUND_DIRT_DEBRIS_2,
 SOUND_DIRT_DEBRIS_3,
 SOUND_TREE_FALLING,
 SOUND_TREE_HIT_EARTH,
 SOUND_WATER_DRIP_1,
 SOUND_WATER_DRIP_2,
 SOUND_WATER_DRIP_3,
 SOUND_WATER_DRIP_4,
 SOUND_WATER_DRIP_5,
 SOUND_WATER_SPLASH_1,
 SOUND_WATER_SPLASH_2,
 SOUND_WATER_SPLASH_3,
 SOUND_WATER_SPLASH_4,
 SOUND_WATER_SPLASH_5,
 SOUND_UNDERWATER_SWIM_1,
 SOUND_UNDERWATER_SWIM_2,
 SOUND_UNDERWATER_SWIM_3,
 SOUND_UNDERWATER_SWIM_4,
 SOUND_UNDERWATER_SWIM_5,
 SOUND_BIRD_CALL_1,
 SOUND_BIRD_CALL_2,
 SOUND_BIRD_CALL_3,
 SOUND_BIRD_CALL_4,
 SOUND_BIRD_CALL_5,
 SOUND_BIRD_CALL_6,
 SOUND_BIRD_CALL_7,
 SOUND_BIRD_CALL_8,
 SOUND_CRICKET_CHIRP,
 SOUND_CICAADA_CHIRP,
 SOUND_LOCUST_CHIRP,
 SOUND_FROG_CHIRP_1,
 SOUND_FROG_CHIRP_2,
 SOUND_FROG_CHIRP_3,
 SOUND_FROG_CHIRP_4,
 SOUND_INSECT_BUZZ_1,
 SOUND_INSECT_BUZZ_2,
 SOUND_INSECT_BUZZ_3,
 SOUND_MONKEY_CHIPSCREAM_1,
 SOUND_MONKEY_CHIPSCREAM_2,
 SOUND_MONKEY_CHIPSCREAM_3,
 SOUND_MONKEY_CHIPSCREAM_4,
 SOUND_WILD_BOAR_SQUEAL_1,
 SOUND_WILD_BOAR_SQUEAL_2,
 SOUND_WILD_BOAR_SQUEAL_3,
 SOUND_WILD_BOAR_SQUEAL_4,
 SOUND_BIRD_FLUSHING,
 SOUND_BRUSH_RUSTLE_1,
 SOUND_BRUSH_RUSTLE_2,
 SOUND_BRUSH_RUSTLE_3,
 SOUND_BRUSH_RUSTLE_4,
 SOUND_WIND_BLOW_1,
 SOUND_WIND_BLOW_2,
 SOUND_WIND_BLOW_3,
 SOUND_WIND_BLOW_4,
 SOUND_WIND_BLOW_5,
 SOUND_RAIN_LIGHTLY,
 SOUND_RAIN_MEDIUM,
 SOUND_RAIN_HEAVY,
 SOUND_THUNDER_ROLL_1,
 SOUND_THUNDER_ROLL_2,
 SOUND_THUNDER_ROLL_3,
 SOUND_THUNDER_ROLL_4,
 SOUND_LIGHTNING_STRIKE_1,
 SOUND_LIGHTNING_STRIKE_2,
 SOUND_LIGHTNING_STRIKE_3,
 SOUND_RIVER_FLOW_LIGHTLY,
 SOUND_RIVER_FLOW_MEDIUM,
 SOUND_RIVER_FLOW_HEAVY,
 SOUND_WATERFALL_RUSH,
 SOUND_LAVA_FLOW,
 SOUND_GYSER_SPOUTING,
 SOUND_STALACTITES_BREAK,
 SOUND_OMINOUS_CAVE_GROWL_1,
 SOUND_OMINOUS_CAVE_GROWL_2,
 SOUND_OMINOUS_CAVE_GROWL_3,
 SOUND_GHOSTLY_CATACOMB_MOAN_1,
 SOUND_GHOSTLY_CATACOMB_MOAN_2,
 SOUND_GHOSTLY_CATACOMB_MOAN_3,
 SOUND_LIGHT_JUNGLE_FOOTFALL,
 SOUND_HEAVY_JUNGLE_FOOTFALL,
 SOUND_ROPE_BRIDGE_FOOTFALL,
 SOUND_CLIMB_CLIFF_FOOTFALL,
 SOUND_SWAMP_FOOTFALL,
 SOUND_WATER_FOOTFALL,
 SOUND_STONE_FOOTFALL,
 SOUND_METAL_FOOTFALL,
 SOUND_LARGE_THUD,
 SOUND_FALL_INTO_PIT,
 SOUND_STONE_SCRAPE_ON_STONE,
 SOUND_QUICKSAND_SWALLOW,
 SOUND_ELEVATOR_MECHANISM,
 SOUND_CEREMONIAL_SLAB_RISE,
 SOUND_CLAY_POT_SMASH,
 SOUND_ROCKS_SQUISH_IN_SWAMP,
 SOUND_DOORWAY_OPENCLOSE_1,
 SOUND_DOORWAY_OPENCLOSE_2,
 SOUND_ENERGY_SHIELD_HUM,
 SOUND_ENERGY_BLAST,
 SOUND_WARP_INOUT,
 SOUND_MACHINE_HUM,
 SOUND_POWER_HUM,
 SOUND_THERMAL_GOGGLES_ON,
 SOUND_THERMAL_GOGGLES_POWER,
 SOUND_HEALTH_PICKUP_1,
 SOUND_HEALTH_PICKUP_2,
 SOUND_HEALTH_PICKUP_3,
 SOUND_ULTRA_HEALTH_PICKUP,
 SOUND_HIT_POINT_PICKUP,
 SOUND_SPIRITUALITY_PICKUP,
 SOUND_SPIRITUALITY_DEATH_ATTACK,
 SOUND_ALL_MAP_PICKUP,
 SOUND_RAPTOR_SCREAM,
 SOUND_RAPTOR_ALERT,
 SOUND_RAPTOR_FOOTFALL,
 SOUND_RAPTOR_INJURY,
 SOUND_RAPTOR_ATTACK,
 SOUND_RAPTOR_DEATH,
 SOUND_RAPTOR_VIOLENT_DEATH,
 SOUND_RAPTOR_SNIFF,
 SOUND_TIGER_FOOTFALL,
 SOUND_TIGER_ROAR,
 SOUND_TIGER_ALERT,
 SOUND_TIGER_INJURY,
 SOUND_TIGER_ATTACK,
 SOUND_TIGER_DEATH,
 SOUND_TIGER_VIOLENT_DEATH,
 SOUND_TIGER_BREATHE,
 SOUND_DIMETRODON_FOOTFALL,
 SOUND_DIMETRODON_SCREAM,
 SOUND_DIMETRODON_ALERT,
 SOUND_DIMETRODON_INJURY,
 SOUND_DIMETRODON_DEATH,
 SOUND_DIMETRODON_VIOLENT_DEATH,
 SOUND_DIMETRODON_COUGHSNARL,
 SOUND_MOSCHOPS_FOOTFALL,
 SOUND_MOSCHOPS_SCREAM,
 SOUND_MOSCHOPS_ALERT,
 SOUND_MOSCHOPS_INJURY,
 SOUND_MOSCHOPS_ATTACK,
 SOUND_MOSCHOPS_DEATH,
 SOUND_MOSCHOPS_VIOLENT_DEATH,
 SOUND_MOSCHOPS_BREATHE,
 SOUND_PTERANODN_SCREAM,
 SOUND_PTERANODN_WING_FLAP,
 SOUND_PTERANODN_INJURY,
 SOUND_PTERANODN_DEATH,
 SOUND_PTERANODN_HISS,
 SOUND_TRICERATOPS_FOOTFALL,
 SOUND_TRICERATOPS_SCREAM,
 SOUND_TRICERATOPS_ALERT,
 SOUND_TRICERATOPS_INJURY,
 SOUND_DRAGONFLY_BUZZ,
 SOUND_DRAGONFLY_CLICKSCHATTER_1,
 SOUND_DRAGONFLY_CLICKSCHATTER_2,
 SOUND_DRAGONFLY_INJURY,
 SOUND_DRAGONFLY_DEATH,
 SOUND_DRAGONFLY_ATTACK,
 SOUND_BEETLE_FOOTFALL,
 SOUND_BEETLE_BUZZ,
 SOUND_BEETLE_CLICKSCHATTER_1,
 SOUND_BEETLE_CLICKSCHATTER_2,
 SOUND_BEETLE_INJURY,
 SOUND_BEETLE_DEATH,
 SOUND_BEETLE_ATTACK,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_1,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_2,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_3,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_4,
 SOUND_HUMAN_EFFORTINJURY_GRUNT_5,
 SOUND_HUMAN_ALERT_1,
 SOUND_HUMAN_ALERT_2,
 SOUND_HUMAN_ALERT_3,
 SOUND_HUMAN_DEATH_SCREAM_1,
 SOUND_HUMAN_DEATH_SCREAM_2,
 SOUND_HUMAN_DEATH_SCREAM_3,
 SOUND_HUMAN_VIOLENT_DEATH_1,
 SOUND_HUMAN_VIOLENT_DEATH_2,
 SOUND_HUMAN_VIOLENT_DEATH_3,
 SOUND_ANCIENT_WARRIOR_SCREAM,
 SOUND_ANCIENT_WARRIOR_ALERT,
 SOUND_ANCIENT_WARRIOR_ATTACK,
 SOUND_ANCIENT_WARRIOR_DEATH,
 SOUND_HIGH_PRIEST_TELEPORT,
 SOUND_HIGH_PRIEST_SPELL_ATTACK,
 SOUND_SUBTERRANEAN_SCREAM,
 SOUND_SUBTERRANEAN_EARTH_RUMBLE,
 SOUND_SUBTERRANEAN_ACID_ATTACK,
 SOUND_SUBTERRANEAN_ACID_IMPACT,
 SOUND_SUBTERRANEAN_DEATH,
 SOUND_SUBTERRANEAN_VIOLENT_DEATH,
 SOUND_LEAPER_FOOTFALL,
 SOUND_LEAPER_SCREAM,
 SOUND_LEAPER_ALERT,
 SOUND_LEAPER_INJURY,
 SOUND_LEAPER_ATTACK,
 SOUND_LEAPER_DEATH,
 SOUND_LEAPER_VIOLENT_DEATH,
 SOUND_LEAPER_CHITTER,
 SOUND_ALIEN_FOOTFALL,
 SOUND_ALIEN_SCREAM,
 SOUND_ALIEN_ALERT,
 SOUND_ALIEN_INJURY,
 SOUND_ALIEN_DEATH,
 SOUND_ALIEN_JETPACK_MALFUNCTION,
 SOUND_ALIEN_VIOLENT_DEATH,
 SOUND_HULK_FOOTFALL,
 SOUND_HULK_SCREAM,
 SOUND_HULK_ALERT,
 SOUND_HULK_INJURY,
 SOUND_HULK_ATTACK,
 SOUND_HULK_DEATH,
 SOUND_HULK_VIOLENT_DEATH,
 SOUND_HULK_BREATHE,
 SOUND_ROBOT_FOOTFALL,
 SOUND_ROBOT_SERVO_1,
 SOUND_ROBOT_SERVO_2,
 SOUND_ROBOT_SERVO_3,
 SOUND_ROBOT_SERVO_4,
 SOUND_ROBOT_VOICE_FX_1,
 SOUND_ROBOT_VOICE_FX_2,
 SOUND_ROBOT_VOICE_FX_3,
 SOUND_ROBOT_SHORT_1,
 SOUND_ROBOT_SHORT_2,
 SOUND_ROBOT_SHORT_3,
 SOUND_ROBOT_SHUTDOWN,
 SOUND_DROID_MOVE,
 SOUND_DROID_SERVO_1,
 SOUND_DROID_SERVO_2,
 SOUND_DROID_SERVO_3,
 SOUND_DROID_OBJECT_LOCATED,
 SOUND_SECURITY_DROID_MOVE,
 SOUND_SECURITY_DROID_LASER_FIRE,
 SOUND_SECURITY_DROID_LASER_LOCK_ON,
 SOUND_SECURITY_DROID_EXTINGUISH,
 SOUND_MANTIS_SCREAM_1,
 SOUND_MANTIS_SCREAM_2,
 SOUND_MANTIS_CHITTER,
 SOUND_MANTIS_INJURY,
 SOUND_MANTIS_ATTACK,
 SOUND_MANTIS_VIOLENT_DEATH,
 SOUND_TREX_FOOTFALL,
 SOUND_TREX_SCREAM,
 SOUND_TREX_SERVO_1,
 SOUND_TREX_SERVO_2,
 SOUND_TREX_SERVO_3,
 SOUND_TREX_SNIFF,
 SOUND_TREX_EYE_LASER_FIRE,
 SOUND_TREX_FIRE_BREATHE,
 SOUND_TREX_BITE_ATTACK,
 SOUND_TREX_VIOLENT_DEATH,
 SOUND_LONGHUNTER_TAUNT_1,
 SOUND_LONGHUNTER_TAUNT_2,
 SOUND_LONGHUNTER_TAUNT_3,
 SOUND_CAMPAIGNERS_TAUNT_1_PATHETIC,
 SOUND_CAMPAIGNERS_TAUNT_2_DIE,
 SOUND_CAMPAIGNERS_RAGE_UNIVERSE,
 SOUND_CAMPAIGNERS_ATTACK,
 SOUND_CAMPAIGNERS_SPELL,
 SOUND_CAMPAIGNERS_SHORTING_OUT_LAUGH,
 SOUND_CAMPAIGNERS_DEATH,
 SOUND_THROW_TOMAHAWK,
 SOUND_TOMAHAWK_GLOW,
 SOUND_TOMAHAWK_IMPACT_FLESH,
 SOUND_SHOCKWAVE_WEAPON_FIRE,
 SOUND_SHOCKWAVE_WEAPON_READY,
 SOUND_SHOCKWAVE_WEAPON_FRY,
 SOUND_RAPTOR_LASER_FIRE,
 SOUND_ROTATING_LIFT_SERVO,
 SOUND_PTERANODON_FLY_SWOOSH,
 SOUND_ROBOT_MALFUNCTION,
 SOUND_MANTIS_FIREBALL,
 SOUND_MANTIS_DEATH_RAIN,
 SOUND_FOOTFALL_ON_WOOD_PLANK,
 SOUND_TOUCAN_FLY_BY,
 SOUND_ANTELOPE_FLEE,
 SOUND_READY_GRENADE_LAUNCHER,
 SOUND_MINIGUN_STOP,
 SOUND_READY_PULSE_RIFLE,
 SOUND_READY_ASSAULT_RIFLE,
 SOUND_READY_MINI_GUN,
 SOUND_READY_AUTO_SHOTGUN,
 SOUND_RELOAD_MISSLE_LAUNCHER,
 SOUND_RELOAD_AUTO_SHOTGUN,
 SOUND_GENERIC_1,
    SOUND_GENERIC_2,
    SOUND_GENERIC_3,
    SOUND_GENERIC_4,
    SOUND_GENERIC_5,
    SOUND_GENERIC_6,
    SOUND_GENERIC_7,
 SOUND_GENERIC_8,
    SOUND_GENERIC_9,
    SOUND_GENERIC_10,
    SOUND_GENERIC_11,
    SOUND_GENERIC_12,
    SOUND_GENERIC_13,
    SOUND_GENERIC_14,
    SOUND_GENERIC_15,
    SOUND_GENERIC_16,
    SOUND_GENERIC_17,
    SOUND_GENERIC_18,
    SOUND_GENERIC_19,
    SOUND_GENERIC_20,
    SOUND_GENERIC_21,
    SOUND_GENERIC_22,
    SOUND_GENERIC_23,
    SOUND_GENERIC_24,
    SOUND_GENERIC_25,
    SOUND_GENERIC_26,
    SOUND_GENERIC_27,
    SOUND_GENERIC_28,
    SOUND_GENERIC_29,
    SOUND_GENERIC_30,
    SOUND_GENERIC_31,
    SOUND_GENERIC_32,
    SOUND_GENERIC_33,
    SOUND_GENERIC_34,
    SOUND_GENERIC_35,
    SOUND_GENERIC_36,
    SOUND_GENERIC_37,
    SOUND_GENERIC_38,
    SOUND_GENERIC_39,
    SOUND_GENERIC_40,
    SOUND_GENERIC_41,
    SOUND_GENERIC_42,
    SOUND_GENERIC_43,
    SOUND_GENERIC_44,
    SOUND_GENERIC_45,
    SOUND_GENERIC_46,
    SOUND_GENERIC_47,
    SOUND_GENERIC_48,
    SOUND_GENERIC_49,
    SOUND_GENERIC_50,
    SOUND_GENERIC_51,
    SOUND_GENERIC_52,
    SOUND_GENERIC_53,
    SOUND_GENERIC_54,
    SOUND_GENERIC_55,
    SOUND_GENERIC_56,
    SOUND_GENERIC_57,
    SOUND_GENERIC_58,
    SOUND_GENERIC_59,
    SOUND_GENERIC_60,
    SOUND_GENERIC_61,
    SOUND_GENERIC_62,
    SOUND_GENERIC_63,
    SOUND_GENERIC_64,
    SOUND_GENERIC_65,
    SOUND_GENERIC_66,
    SOUND_GENERIC_67,
    SOUND_GENERIC_68,
    SOUND_GENERIC_69,
    SOUND_GENERIC_70,
    SOUND_GENERIC_71,
    SOUND_GENERIC_72,
    SOUND_GENERIC_73,
    SOUND_GENERIC_74,
    SOUND_GENERIC_75,
    SOUND_GENERIC_76,
    SOUND_GENERIC_77,
    SOUND_GENERIC_78,
    SOUND_GENERIC_79,
    SOUND_GENERIC_80,
    SOUND_GENERIC_81,
    SOUND_GENERIC_82,
    SOUND_GENERIC_83,
    SOUND_GENERIC_84,
    SOUND_GENERIC_85,
    SOUND_GENERIC_86,
    SOUND_GENERIC_87,
    SOUND_GENERIC_88,
    SOUND_GENERIC_89,
    SOUND_GENERIC_90,
    SOUND_GENERIC_91,
    SOUND_GENERIC_92,
    SOUND_GENERIC_93,
    SOUND_GENERIC_94,
    SOUND_GENERIC_95,
    SOUND_GENERIC_96,
    SOUND_GENERIC_97,
    SOUND_GENERIC_98,
    SOUND_GENERIC_99,
    SOUND_GENERIC_100,
    SOUND_GENERIC_101,
    SOUND_GENERIC_102,
    SOUND_GENERIC_103,
    SOUND_GENERIC_104,
    SOUND_GENERIC_105,
    SOUND_GENERIC_106,
    SOUND_GENERIC_107,
    SOUND_GENERIC_108,
    SOUND_GENERIC_109,
    SOUND_GENERIC_110,
    SOUND_GENERIC_111,
    SOUND_GENERIC_112,
    SOUND_GENERIC_113,
    SOUND_GENERIC_114,
    SOUND_GENERIC_115,
    SOUND_GENERIC_116,
    SOUND_GENERIC_117,
    SOUND_GENERIC_118,
    SOUND_GENERIC_119,
    SOUND_GENERIC_120,
    SOUND_GENERIC_121,
    SOUND_GENERIC_122,
    SOUND_GENERIC_123,
    SOUND_GENERIC_124,
    SOUND_GENERIC_125,
    SOUND_GENERIC_126,
    SOUND_GENERIC_127,
    SOUND_GENERIC_128,
    SOUND_GENERIC_129,
    SOUND_GENERIC_130,
    SOUND_GENERIC_131,
    SOUND_GENERIC_132,
    SOUND_GENERIC_133,
    SOUND_GENERIC_134,
    SOUND_GENERIC_135,
    SOUND_GENERIC_136,
    SOUND_GENERIC_137,
    SOUND_GENERIC_138,
 SOUND_GENERIC_139,
 SOUND_GENERIC_140,
 SOUND_GENERIC_141,
 SOUND_GENERIC_142,
 SOUND_GENERIC_143,
 SOUND_GENERIC_144,
 SOUND_GENERIC_145,
 SOUND_GENERIC_146,
 SOUND_GENERIC_147,
 SOUND_GENERIC_148,
 SOUND_GENERIC_149,
 SOUND_GENERIC_150,
 SOUND_GENERIC_151,
 SOUND_GENERIC_152,
 SOUND_GENERIC_153,
 SOUND_GENERIC_154,
 SOUND_GENERIC_155,
 SOUND_GENERIC_156,
 SOUND_GENERIC_157,
 SOUND_GENERIC_158,
 SOUND_GENERIC_159,
 SOUND_GENERIC_160,
 SOUND_GENERIC_161,
 SOUND_GENERIC_162,
 SOUND_GENERIC_163,
 SOUND_GENERIC_164,
 SOUND_GENERIC_165,
 SOUND_GENERIC_166,
 SOUND_GENERIC_167,
 SOUND_GENERIC_168,
 SOUND_GENERIC_169,
 SOUND_GENERIC_170,
 SOUND_GENERIC_171,
 SOUND_GENERIC_172,
 SOUND_GENERIC_173,
 SOUND_GENERIC_174,
 SOUND_GENERIC_175,
 SOUND_GENERIC_176,
 SOUND_GENERIC_177,
 SOUND_GENERIC_178,
 SOUND_GENERIC_179,
 SOUND_GENERIC_180,
 SOUND_GENERIC_181,
 SOUND_GENERIC_182,
 SOUND_GENERIC_183,
 SOUND_GENERIC_184,
 SOUND_GENERIC_185,
 SOUND_GENERIC_186,
 SOUND_GENERIC_187,
 SOUND_GENERIC_188,
 SOUND_GENERIC_189,
 SOUND_GENERIC_190,
 SOUND_GENERIC_191,
 SOUND_GENERIC_192,
 SOUND_GENERIC_193,
 SOUND_GENERIC_194,
 SOUND_GENERIC_195,
 SOUND_GENERIC_196,
 SOUND_GENERIC_197,
 SOUND_GENERIC_198,
 SOUND_GENERIC_199,
 SOUND_GENERIC_200,
    SOUND_GENERIC_201,
    SOUND_GENERIC_202,
    SOUND_GENERIC_203,
    SOUND_GENERIC_204,
    SOUND_GENERIC_205,
    SOUND_GENERIC_206,
    SOUND_GENERIC_207,
    SOUND_GENERIC_208,
    SOUND_GENERIC_209,
    SOUND_GENERIC_210,
    SOUND_GENERIC_211,
    SOUND_GENERIC_212,
    SOUND_GENERIC_213,
    SOUND_GENERIC_214,
    SOUND_GENERIC_215,
    SOUND_GENERIC_216,
    SOUND_GENERIC_217,
    SOUND_GENERIC_218,
    SOUND_GENERIC_219,
    SOUND_GENERIC_220,
    SOUND_GENERIC_221,
    SOUND_GENERIC_222,
    SOUND_GENERIC_223,
    SOUND_GENERIC_224,
    SOUND_GENERIC_225,
    SOUND_GENERIC_226,
    SOUND_GENERIC_227,
    SOUND_GENERIC_228,
    SOUND_GENERIC_229,
    SOUND_GENERIC_230,
    SOUND_GENERIC_231,
    SOUND_GENERIC_232,
    SOUND_GENERIC_233,
    SOUND_GENERIC_234,
    SOUND_GENERIC_235,
    SOUND_GENERIC_236,
    SOUND_GENERIC_237,
    SOUND_GENERIC_238,
 SOUND_GENERIC_239,
 SOUND_GENERIC_240,
 SOUND_GENERIC_241,
 SOUND_GENERIC_242,
 SOUND_GENERIC_243,
 SOUND_GENERIC_244,
 SOUND_GENERIC_245,
 SOUND_GENERIC_246,
 SOUND_GENERIC_247,
 SOUND_GENERIC_248,
 SOUND_GENERIC_249,
 SOUND_GENERIC_250,
 SOUND_TYPES_TOTAL
};



extern char *sound_effects[];






#define _INC_REGTYPE 




#define REGMAT_GRASS 0
#define REGMAT_WATERSURFACE 1
#define REGMAT_STEEL 2
#define REGMAT_STONE 3
#define REGMAT_FLESH 4
#define REGMAT_ALIENFLESH 5
#define REGMAT_FLESHWATER 6
#define REGMAT_LAVA 7
#define REGMAT_TAR 8
#define REGMAT_FORCEFIELD 9

#define REGMAT_DEFAULT REGMAT_GRASS



#define PRE22_REGMAT_GRASS 0
#define PRE22_REGMAT_DIRT 1
#define PRE22_REGMAT_WATERSURFACE 2
#define PRE22_REGMAT_STEEL 3
#define PRE22_REGMAT_STONE 4
#define PRE22_REGMAT_WOOD 5
#define PRE22_REGMAT_FOLIAGE 6
#define PRE22_REGMAT_FLESH 7
#define PRE22_REGMAT_ALIENFLESH 8
#define PRE22_REGMAT_WATERFLOOR 9
#define PRE22_REGMAT_FLESHWATER 10
#define PRE22_REGMAT_LAVA 11
#define PRE22_REGMAT_TAR 12
#define PRE22_REGMAT_FORCEFIELD 13





#define REGFLAG_HASWATER (1 << 0)
#define REGFLAG_DOOR (1 << 1)
#define REGFLAG_OPENDOOR (1 << 2)
#define REGFLAG_CLIFF (1 << 3)
#define REGFLAG_CLIMBABLE (1 << 4)
#define REGFLAG_BRIDGE (1 << 5)
#define REGFLAG_CEILING (1 << 6)
#define REGFLAG_DUCK (1 << 7)
#define REGFLAG_DUCKENTRANCEEXIT (1 << 8)
#define REGFLAG_DONTDRAWONMAP (1 << 9)
#define REGFLAG_REGIONENTERED (1 << 10)
#define REGFLAG_RESTRICTEDAREA (1 << 12)
#define REGFLAG_RUNTIMECLIFF (1 << 13)
#define REGFLAG_FALLDEATH (1 << 14)
#define REGFLAG_RECURSE (1 << 15)


#define REGFLAG_PRESSUREPLATE (1 << 16)
#define REGFLAG_PRESSUREPLATENEEDSCOLLISION (1 << 17)
#define REGFLAG_WARPENTRANCE (1 << 18)
#define REGFLAG_INSTANTDEATH (1 << 19)
#define REGFLAG_SKY (1 << 20)
#define REGFLAG_WARPIFINAIR (1 << 21)
#define REGFLAG_LAVA (1 << 22)
#define REGFLAG_PRESSUREPLATESOUND (1 << 23)
#define REGFLAG_ANTIGRAV (1 << 24)
#define REGFLAG_LADDER (1 << 25)
#define REGFLAG_CHECKPOINT (1 << 26)
#define REGFLAG_SAVEPOINT (1 << 27)
#define REGFLAG_WARPRETURN (1 << 28)
#define REGFLAG_SHALLOWWATER (1 << 29)
#define REGFLAG_SUN (1 << 30)
#define REGFLAG_STOREWARPRETURN (1 << 31)




#define REGFLAG_PRE25_WARPENTRANCE (1 << 9)
#define REGFLAG_PRE25_INSTANTDEATH (1 << 10)
#define REGFLAG_PRE25_SKY (1 << 11)
#define REGFLAG_PRE25_WARPIFINAIR (1 << 15)
#define REGFLAG_PRE25_DONTDRAWONMAP (1 << 30)





#define REG_AMBIENTNONE 0
#define REG_AMBIENTJUNGLE 1
#define REG_AMBIENTWATER 2
#define REG_AMBIENTCAVES 3
#define REG_AMBIENTCATACOMBS 4
#define REG_AMBIENTLOSTLANDS 5
#define REG_AMBIENTCAMPAIGNERSLAIR 6
#define REG_AMBIENTCATACOMBLARGE 7
#define REG_AMBIENTCITY 8
#define REG_AMBIENTRUINS 9
#define REG_AMBIENTTREETOP 10
#define REG_AMBIENTWARP 11





#define REG_MAPCOLOR_WHITE 0
#define REG_MAPCOLOR_GREEN 1
#define REG_MAPCOLOR_BLUE 2
#define REG_MAPCOLOR_RED 3
#define REG_MAPCOLOR_PINK 4
#define REG_MAPCOLOR_PURPLE 5
#define REG_MAPCOLOR_BROWN 6
#define REG_MAPCOLOR_CYAN 7
#define REG_MAPCOLOR_YELLOW 8
#define REG_MAPCOLOR_ORANGE 9
#define REG_MAPCOLOR_BLACK 10






#define _INC_INTROCAM 







extern int SkipIntro ;
extern int IntroFirstRun ;





void func_80039C30(CCamera *pThis) ;

void func_80039E08(CCamera *pThis) ;
void CCamera__Code_LEGALSCREEN_LOGO(CCamera *pThis) ;

void func_80039E50(CCamera *pThis) ;
void func_80039E70(CCamera *pThis) ;

void func_8003A02C(CCamera *pThis) ;
void func_8003A0F0(CCamera *pThis) ;

void func_8003A1FC(CCamera *pThis) ;
void func_8003A270(CCamera *pThis) ;

void func_8003A43C(CCamera *pThis) ;
void CCamera__Code_INTRO_ZOOM_TO_LOGO(CCamera *pThis) ;

CQuatern func_8003A8D0(CGameObjectInstance *pThis) ;

void func_8003A98C(CCamera *pThis) ;
void func_8003A9C4(CCamera *pThis) ;

void func_8003AC1C(CCamera *pThis) ;
void func_8003AC70(CCamera *pThis) ;






#define _INC_CAMMODES 






enum CameraModes
{
 CAMERA_LEGALSCREEN_MODE,
 CAMERA_INTRO_ACCLAIM_LOGO_MODE,
 CAMERA_INTRO_IGGY_MODE,
 CAMERA_INTRO_TUROK_DRAWING_BOW_MODE,
 CAMERA_INTRO_ZOOM_TO_LOGO_MODE,

 CAMERA_GAME_INTRO_MODE,
 CAMERA_GAME_INTRO_KEY_MODE,

 CAMERA_TUROK_EYE_MODE,

 CAMERA_CINEMA_TUROK_DEATH_MODE,
 CAMERA_CINEMA_TUROK_FALL_DEATH_MODE,
 CAMERA_CINEMA_TUROK_WATER_DEATH_MODE,
 CAMERA_CINEMA_TUROK_RESURRECT_MODE,

 CAMERA_GALLERY_IDLE_MODE,

 CAMERA_CINEMA_LONGHUNTER_MODE,
 CAMERA_CINEMA_FIRST_HUMVEE_MODE,
 CAMERA_CINEMA_FINAL_HUMVEE_MODE,

 CAMERA_CINEMA_TUROK_KILL_MANTIS_MODE,
 CAMERA_CINEMA_MANTIS_KILL_TUROK_MODE,
 CAMERA_CINEMA_TUROK_KILL_TREX_MODE,
 CAMERA_CINEMA_TREX_KILL_TUROK_MODE,
 CAMERA_CINEMA_TUROK_KILL_LONGHUNTER_MODE,
 CAMERA_CINEMA_TUROK_KILL_CAMPAIGNER_MODE,
 CAMERA_CINEMA_CAMPAIGNER_KILL_TUROK_MODE,

 CAMERA_CINEMA_TUROK_PICKUP_KEY_MODE,

 CAMERA_CINEMA_END_SEQUENCE_MODE,
 CAMERA_CINEMA_END_SEQUENCE2_MODE,

 CAMERA_CINEMA_CREDIT_MODE,

 CAMERA_CINEMA_TUROK_VICTORY_MODE,

 CAMERA_END_MODE
} ;






#define CF_TUROK_LOADED (1<<0)
#define CF_TUROK_IN_WATER (1<<1)
#define CF_SOUND_PLAYED (1<<2)










#define _INC_MAP 





#define STATIC_SEGMENT 1
#define CFB_SEGMENT 2

#define SCREEN_HT 240
#define SCREEN_WD 320

#define IDLE_STACKSIZE 128
#define STACKSIZE 0x1000
#define MAIN_STACKSIZE 0xe000
#define AUDIO_STACKSIZE 0x4000






void CEngineApp__DrawMap(CEngineApp *pThis);
void func_80098488(CEngineApp *pThis);
void func_80096478(CEngineApp *pThis);
int CEngineApp__DrawingMap(CEngineApp *pThis) ;


enum MapStatus
{
 MAP_NULL,
 MAP_FADEUP,
 MAP_ON,
 MAP_FADEDOWN
} ;








#define _INC_ATTRACT 







void func_8004FF94() ;
int func_8004FF48(void) ;
int CAttractDemo__CheckForPlay() ;
int func_8004FE78() ;
int func_80050280(void) ;

int func_800AA800(void) ;
int func_800502B8(void) ;

void func_80050120() ;
void func_800501E0() ;
void CAttractDemo__EventDebug() ;

void func_8004FCF4(void) ;
void func_8004FD0C(void) ;






#define _INC_AISTAND 

void AI_Standard_Idle (CGameObjectInstance *pMe);
void AI_Standard_Agitated (CGameObjectInstance *pMe);
void AI_Standard_Attack (CGameObjectInstance *pMe, CGameObjectInstance *pDest);
void AI_Standard_Death (CGameObjectInstance *pMe);
void func_80078378 (CGameObjectInstance *pMe);
void func_80078040 (CGameObjectInstance *pMe);
void func_80076824 (CGameObjectInstance *pMe, float turnang, int MovementAllowed);
void AI_Standard_Follow (CGameObjectInstance *pMe, CGameObjectInstance *pLeader);
void AI_Standard_DeadBodyRiddle (CGameObjectInstance *pMe);
void func_8007924C (CGameObjectInstance *pMe, CGameObjectInstance *pDest);
void func_800784B0 (CGameObjectInstance *pMe);
void func_800783AC (CGameObjectInstance *pMe);
int func_800791F0 (CGameObjectInstance *pMe);
void AI_Standard_TeleportMoveSlow (CGameObjectInstance *pMe);
void AI_Standard_Sniper (CGameObjectInstance *pMe, CGameObjectInstance *pDest);
void func_80076B3C (CGameObjectInstance *pMe, CGameObjectInstance *pDest);
void func_80076FB4 (CGameObjectInstance *pMe, CGameObjectInstance *pDest);
void func_80077B34 (CGameObjectInstance *pMe, int waterFlag);
int func_80076A40 (CGameObjectInstance *pAI, float radiusFactor);

int func_80077904();
CVector3 func_80079B78();




void func_8007666C(CGameObjectInstance *pMe) ;
int func_80076488(CGameObjectInstance *pMe, float AngleRange) ;
int func_80076400(CGameObjectInstance *pMe) ;
void func_800763C0(CGameObjectInstance *pMe) ;







#define _INC_TREX 

enum TRexModes
{

 TREX_ON_ELEVATOR_IDLE_MODE,
 TREX_ON_ELEVATOR_RAGE_MODE,
 TREX_ON_ELEVATOR_LOOK_MODE,
 TREX_EXIT_ELEVATOR_MODE,


 TREX_IDLE_MODE,
 TREX_LOOK_MODE,

 TREX_TURN_LEFT90_MODE,
 TREX_TURN_RIGHT90_MODE,
 TREX_TURN180_MODE,


 TREX_RUN_MODE,
 TREX_RUN_TURN_LEFT90_MODE,
 TREX_RUN_TURN_RIGHT90_MODE,
 TREX_RUN_BITE_MODE,

 TREX_LIMP_MODE,
 TREX_LIMP_TURN_LEFT90_MODE,
 TREX_LIMP_TURN_RIGHT90_MODE,


 TREX_TAIL_SLAM_MODE,
 TREX_BITE_MODE,
 TREX_RAGE_MODE,


 TREX_BREATH_FIRE_MODE,
 TREX_BREATH_FIRE_IN_MODE,
 TREX_BREATH_FIRE_OUT_MODE,

 TREX_EYE_FIRE_MODE,
 TREX_EYE_FIRE_IN_MODE,
 TREX_EYE_FIRE_OUT_MODE,


 TREX_BITE_UP_MODE,
 TREX_FIRE_UP_MODE,


 TREX_CAVE_STOOP_MODE,
 TREX_CAVE_LOOK_MODE,
 TREX_CAVE_BITE_MODE,
 TREX_CAVE_OUT_MODE,

 TREX_CAVE_NOSE_HIT_MODE,
 TREX_CAVE_RAGE_MODE,
 TREX_CAVE_TAIL_SLAM_MODE,


 TREX_EXPLODE_LEFT_MODE,
 TREX_EXPLODE_RIGHT_MODE,
 TREX_EXPLODE_FRONT_MODE,
 TREX_EXPLODE_BACK_MODE,


 TREX_STUNNED_MODE,
 TREX_STUN_OUT_MODE,
 TREX_DEATH_MODE,

 TREX_EATTUROK_MODE,

 TREX_END_MODE
} ;




enum TRexActions
{
 TREX_ON_ELEVATOR_ACTION,
 TREX_EXIT_ELEVATOR_ACTION,
 TREX_ATTACK_ACTION,
 TREX_LEDGE_ATTACK_ACTION,
 TREX_CAVE_ATTACK_ACTION
} ;






#define TREXCMND_END_ATTACK 0
#define TREXCMND_REPEAT -1


#define TREXSCRIPT_TAIL_SLAM(n) TREX_TAIL_SLAM_MODE,n,
#define TREXSCRIPT_BITE(n) TREX_BITE_MODE,n,
#define TREXSCRIPT_RAGE(n) TREX_RAGE_MODE,n,
#define TREXSCRIPT_BREATH_FIRE(n) TREX_BREATH_FIRE_MODE,n,
#define TREXSCRIPT_EYE_FIRE(n) TREX_EYE_FIRE_MODE,n,


#define TREXSCRIPT_BITE_UP(n) TREX_BITE_UP_MODE,n,
#define TREXSCRIPT_FIRE_UP(n) TREX_FIRE_UP_MODE,n,


#define TREXSCRIPT_CAVE_LOOK(n) TREX_CAVE_LOOK_MODE,n,
#define TREXSCRIPT_BITE_LOOK(n) TREX_CAVE_BITE_MODE,n,



#define TREXSCRIPT_END_ATTACK TREXCMND_END_ATTACK,
#define TREXSCRIPT_REPEAT TREXCMND_REPEAT

#define DEFINE_TREXSCRIPT(name) INT16 name[] = {
#define END_TREXSCRIPT TREXSCRIPT_REPEAT} ;

typedef struct TRexStageInfo_t
{
 signed long HealthLimit ;

 float AnimSpeed ;
 signed short HitsBeforeExplode ;
 signed short CaveTailSlams ;

 signed short *pAttackScript ;
 signed short *pCloseAttackScript ;
 signed short *pRunAttackScript ;
 signed short *pTurnAttackScript ;
 signed short *pLedgeAttackScript ;
 signed short *pCaveAttackScript ;

} CTRexStageInfo ;



typedef struct CCaveInfo_t
{
 CVector3 m_Corner1 ;
 CVector3 m_Corner2 ;
 CVector3 m_vTargetPos ;
 CVector3 m_vLookPos ;
} CCaveInfo ;



typedef struct CTRex_t
{

 CBoss m_Boss ;


 signed short m_ScriptStage ;
 CTRexStageInfo *m_pStageInfo ;


 CBossScript m_AttackScript ;
 CBossScript m_CloseAttackScript ;
 CBossScript m_RunAttackScript ;
 CBossScript m_TurnAttackScript ;
 CBossScript m_LedgeAttackScript ;
 CBossScript m_CaveAttackScript ;

 signed short m_ExplosionHits ;

 float m_LookTime ;
 float m_RunTime ;
 float m_TurnTime ;

 float m_TargetDist ;
 float m_AtTargetDist ;

 CCaveInfo *m_pTurokInCave ;
 CCaveInfo *m_pTargetCave ;
 float m_TurokTimeInCave ;
 float m_TurokInCaveWaitTime ;

 signed long m_LaserSoundHandle ;
 CVector3 m_vLaserLastSoundPos ;

 signed long m_FireSoundHandle ;
 signed short m_FireSoundVolume ;

 CDamage *m_pDamage ;
} CTRex ;







extern CTRex D_80127760 ;






typedef void(*TRexSetupFunction)(CGameObjectInstance *pThis, CTRex *pTRex) ;

CBoss *func_800477A0(CGameObjectInstance *pThis) ;
void TRex_Update(CGameObjectInstance *pThis, CTRex *pTRex) ;
signed long TRex_SetupMode(CGameObjectInstance *pThis, signed long nNewMode) ;

int func_80049BE0(CGameObjectInstance *pThis, int nNode) ;

void TRex_StartFireSound(CGameObjectInstance *pThis, CTRex *pTRex) ;
void TRex_StopFireSound(CGameObjectInstance *pThis, CTRex *pTRex) ;







#define __BOSSFLGS_H__ 





enum BossLevels
{
 LONGHUNTER_BOSS_LEVEL = 1,
 MANTIS_BOSS_LEVEL,
 TREX_BOSS_LEVEL,
 CAMPAIGNER_BOSS_LEVEL
} ;


#define LONGHUNTER_BOSS_START_WARP_ID 2998
#define LONGHUNTER_BOSS_END_WARP_ID 2999
#define MANTIS_BOSS_WARP_ID 4999
#define TREX_BOSS_WARP_ID 8997
#define CAMPAIGNER_BOSS_HALL_WARP_ID 8998
#define CAMPAIGNER_BOSS_WARP_ID 8999


#define KILLED_LONGHUNTER_BOSS_WARP_ID 2997
#define KILLED_MANTIS_BOSS_WARP_ID 4998
#define KILLED_TREX_BOSS_WARP_ID 8998
#define KILLED_CAMPAIGNER_BOSS_WARP_ID 8999



#define BOSS_FLAG_RESET_LEVEL (1<<0)

#define BOSS_FLAG_LONGHUNTER_DEAD (1<<1)
#define BOSS_FLAG_HUMVEE1_DEAD (1<<2)
#define BOSS_FLAG_HUMVEE2_DEAD (1<<3)
#define BOSS_FLAG_LONGHUNTER_SWITCH_PRESSED (1<<4)
#define BOSS_FLAG_LONGHUNTER_FORCEFIELD_GONE (1<<5)
#define BOSS_FLAG_LONGHUNTER_GENERATED_KEY (1<<6)
#define BOSS_FLAG_LONGHUNTER_START_HUMVEE1 (1<<7)
#define BOSS_FLAG_LONGHUNTER_START_HUMVEE2 (1<<8)
#define BOSS_FLAG_LONGHUNTER_START_LONGHUNTER (1<<9)


#define BOSS_FLAG_MANTIS_DEAD (1<<10)
#define BOSS_FLAG_MANTIS_CACOON_OPEN (1<<11)
#define BOSS_FLAG_MANTIS_CRYSTAL_STARTED (1<<12)
#define BOSS_FLAG_MANTIS_CRYSTAL_DOWN (1<<13)

#define BOSS_FLAG_TREX_DEAD (1<<14)
#define BOSS_FLAG_TREX_ELEVATOR_RISEN (1<<15)
#define BOSS_FLAG_TREX_ELEVATOR_GONE (1<<16)

#define BOSS_FLAG_CAMPAIGNER_DEAD (1<<17)


#define LONGHUNTER_BOSS_FLAGS (BOSS_FLAG_LONGHUNTER_DEAD | BOSS_FLAG_HUMVEE1_DEAD | BOSS_FLAG_HUMVEE2_DEAD | BOSS_FLAG_LONGHUNTER_SWITCH_PRESSED | BOSS_FLAG_LONGHUNTER_FORCEFIELD_GONE | BOSS_FLAG_LONGHUNTER_GENERATED_KEY | BOSS_FLAG_LONGHUNTER_START_HUMVEE1 | BOSS_FLAG_LONGHUNTER_START_HUMVEE2 | BOSS_FLAG_LONGHUNTER_START_LONGHUNTER)

#define MANTIS_BOSS_FLAGS (BOSS_FLAG_MANTIS_DEAD | BOSS_FLAG_MANTIS_CACOON_OPEN | BOSS_FLAG_MANTIS_CRYSTAL_STARTED | BOSS_FLAG_MANTIS_CRYSTAL_DOWN)




#define TREX_BOSS_FLAGS (BOSS_FLAG_TREX_DEAD | BOSS_FLAG_TREX_ELEVATOR_RISEN | BOSS_FLAG_TREX_ELEVATOR_GONE)



#define CAMPAIGNER_BOSS_FLAGS BOSS_FLAG_CAMPAIGNER_DEAD



#define LONGHUNT_LEVEL_SWITCH1_ID 101
#define LONGHUNT_LEVEL_SWITCH2_ID 102
#define LONGHUNT_LEVEL_SWITCH3_ID 103
#define LONGHUNT_LEVEL_SWITCH4_ID 104
#define LONGHUNT_LEVEL_SWITCH5_ID 105
#define LONGHUNT_LEVEL_SWITCH6_ID 106
#define LONGHUNT_LEVEL_SWITCH7_ID 107
#define LONGHUNT_LEVEL_SWITCH8_ID 108
#define LONGHUNT_LEVEL_DAM_WALL1_ID 11
#define LONGHUNT_LEVEL_DAM_WALL2_ID 12
#define LONGHUNT_LEVEL_DAM_WALL3_ID 13
#define LONGHUNT_LEVEL_DAM_WALL4_ID 14
#define LONGHUNT_LEVEL_WATER1_ID 11
#define LONGHUNT_LEVEL_WATER2_ID 12
#define LONGHUNT_LEVEL_WATER3_ID 13
#define LONGHUNT_LEVEL_WATER4_ID 14
#define LONGHUNT_LEVEL_ELEVATOR_ID 100
#define LONGHUNT_LEVEL_FORCEFIELD_ID 150


#define MANTIS_LEVEL_WALL1_ID 1
#define MANTIS_LEVEL_WALL2_ID 2
#define MANTIS_LEVEL_WALL3_ID 3
#define MANTIS_LEVEL_WALL4_ID 4
#define MANTIS_LEVEL_COCOON_ID 100
#define MANTIS_LEVEL_PILLARS_ID 64
#define MANTIS_LEVEL_UP_WALLS_ID 50
#define MANTIS_LEVEL_CRYSTAL_ID 200



#define TREX_LEVEL_CRUSHERS_START_ID 50
#define TREX_LEVEL_PLATFORM1_ID 101
#define TREX_LEVEL_PLATFORM2_ID 102
#define TREX_LEVEL_PLATFORM3_ID 103
#define TREX_LEVEL_PLATFORM4_ID 104
#define TREX_LEVEL_PLATFORM5_ID 105




#define __WALLCOLL_H__ 








typedef struct CLine_t
{
 CVector3 m_vPt[2] ;
 CVector3 m_vDelta ;
 CVector3 m_vDir ;
 CVector3 m_vNormal ;
} CLine ;

void func_80098AA0(CLine *pThis, CVector3 *pvPt1, CVector3 *pvPt2) ;
void func_80098B20(CLine *pThis) ;

int func_80098BB8(CLine *pThis, CLine *pLine, float *pt) ;





#define CART_ROOT_nItems 11

#define CART_ROOT_isGraphicObjects 0
#define CART_ROOT_usObjectAttributes 1
#define CART_ROOT_usObjectTypes 2
#define CART_ROOT_isTextureSets 3
#define CART_ROOT_isParticleEffects 4
#define CART_ROOT_isSoundEffects 5
#define CART_ROOT_isLevels 6
#define CART_ROOT_isPersistantCounts 7
#define CART_ROOT_isWarpDests 8
#define CART_ROOT_isBinaries 9
#define CART_ROOT_usBinaryTypes 10



#define CART_GRAPHOBJ_nItems 4

#define CART_GRAPHOBJ_isObjectInfo 0
#define CART_GRAPHOBJ_isGeometry 1
#define CART_GRAPHOBJ_isAnims 2
#define CART_GRAPHOBJ_usStaticEvents 3



#define CART_OBJECTINFO_nItems 2

#define CART_OBJECTINFO_bounds 0
#define CART_OBJECTINFO_usAnimTypes 1



#define CART_GEOMETRY_nItems 2

#define CART_GEOMETRY_info 0
#define CART_GEOMETRY_isNodes 1



#define CART_NODE_nItems 3

#define CART_NODE_usChildNodeIndices 0
#define CART_NODE_usPartIndices 1
#define CART_NODE_isParts 2



#define CART_SECTION_nItems 3

#define CART_SECTION_section 0
#define CART_SECTION_usPStream 1
#define CART_SECTION_usVertices 2



#define CART_ANIM_nItems 7

#define CART_ANIM_usYRotations 0
#define CART_ANIM_usNodeAnimIndices 1
#define CART_ANIM_usInitialOrients 2
#define CART_ANIM_usTranslationSets 3
#define CART_ANIM_usRotationSets 4
#define CART_ANIM_isTransitionTable 5
#define CART_ANIM_usEvents 6


#define CART_TRANTABLE_nItems 2

#define CART_TRANTABLE_transition 0
#define CART_TRANTABLE_usTableEntries 1



#define CART_TEXTURESET_nItems 3

#define CART_TEXTURESET_format 0
#define CART_TEXTURESET_isBitmaps 1
#define CART_TEXTURESET_isPalettes 2



#define CART_PARTICLEEFFECTS_nItems 3

#define CART_PARTICLEEFFECTS_usTypes 0
#define CART_PARTICLEEFFECTS_usParticles 1
#define CART_PARTICLEEFFECTS_usImpacts 2



#define CART_SOUNDEFFECTS_nItems 2

#define CART_SOUNDEFFECTS_usTypes 0
#define CART_SOUNDEFFECTS_isSounds 1



#define CART_LEVEL_nItems 6

#define CART_LEVEL_level 0
#define CART_LEVEL_isCollision 1
#define CART_LEVEL_usInstances 2
#define CART_LEVEL_isGridBounds 3
#define CART_LEVEL_isGridSections 4
#define CART_LEVEL_isSkyTextureSet 5




#define CART_GRIDBOUNDS_nItems 5

#define CART_GRIDBOUNDS_usMinXs 0
#define CART_GRIDBOUNDS_usMaxXs 1
#define CART_GRIDBOUNDS_usMinZs 2
#define CART_GRIDBOUNDS_usMaxZs 3
#define CART_GRIDBOUNDS_usBounds 4



#define CART_GRIDSECTION_nItems 3

#define CART_GRIDSECTION_usEStaticInstances 0
#define CART_GRIDSECTION_usStaticInstances 1
#define CART_GRIDSECTION_usSimpleInstances 2



#define CART_COLLISION_nItems 4

#define CART_COLLISION_usRegionAttributes 0
#define CART_COLLISION_usCorners 1
#define CART_COLLISION_usRegions 2
#define CART_COLLISION_usBlockBounds 3



#define CART_PERSIST_nItems 3

#define CART_PERSIST_usPickupCounts 0
#define CART_PERSIST_usAnimCounts 1
#define CART_PERSIST_MaxRegionCount 2



#define CART_WARPDESTS_nItems 2

#define CART_WARPDESTS_usIDs 0
#define CART_WARPDESTS_usWarpDests 1






#define _INC_AIDOOR 








struct CParticle_t;



void func_8008DDA4(CGameObjectInstance *pThis);
void func_8008DF0C(CGameObjectInstance *pThis) ;
void func_8008DF58(CGameObjectInstance *pThis) ;
void func_8008E1D4(CGameObjectInstance *pThis) ;
void func_8008E314(CGameObjectInstance *pThis) ;
void func_8008E488(CGameObjectInstance *pThis) ;
void func_8008E4D4(CGameObjectInstance *pThis) ;

void func_8008E520(CGameObjectInstance *pThis) ;
void func_8008E660(CGameObjectInstance *pThis) ;
void func_8008E6BC(CGameObjectInstance *pThis) ;
void func_8008E800(CGameObjectInstance *pThis) ;
void func_8008E880(CGameObjectInstance *pThis) ;
void func_8008E9D8(CGameObjectInstance *pThis) ;


void func_8008EB08(CGameObjectInstance *pThis) ;
void GateAI_Advance(CGameObjectInstance *pThis) ;
void func_8008EC0C(CGameObjectInstance *pThis) ;
void func_8008EC80(CGameObjectInstance *pThis) ;
void func_8008ED7C(CGameObjectInstance *pThis) ;
void func_8008EE08(CGameObjectInstance *pThis) ;
void func_8008F090(CGameObjectInstance *pThis) ;
void func_8008F1E4(CGameObjectInstance *pThis) ;
void KeyFloorAI_Advance(CGameObjectInstance *pThis) ;
void func_8008F280(CGameObjectInstance *pThis) ;

void func_8008F948(CGameObjectInstance *pThis, int Open);
void func_8008FB0C(CGameObjectInstance *pThis) ;
void func_8008FB9C(CGameObjectInstance *pThis) ;
void func_8008FC3C(CGameObjectInstance *pThis) ;
void ConstantActionAI_MEvent_Go(CGameObjectInstance *pThis) ;
void StatueAI_MEvent_Go(CGameObjectInstance *pThis) ;
void func_8008FD20(CGameObjectInstance *pThis) ;
void func_8008FDA4(CGameObjectInstance *pThis) ;

void func_8008FE28(CGameObjectInstance *pThis);
void func_8008FEE4(CGameObjectInstance *pThis);
void func_8008FF34(CGameObjectInstance *pThis);
void func_80090064(CGameObjectInstance *pThis);
void func_800900E4(CGameObjectInstance *pThis);
void func_80090154(CGameObjectInstance *pThis);
void func_800901E0(CGameObjectInstance *pThis);
void func_80090330(CGameObjectInstance *pThis);
void func_80090738(CGameObjectInstance *pThis);
void func_800907CC(CGameObjectInstance *pThis);
void CrystalAI_MEvent_Start(CGameObjectInstance *pThis, int Sink);
int func_80090958(CGameObjectInstance *pThis, int nNode) ;
void func_80090988(CGameObjectInstance *pThis);
void func_80090A1C(CGameObjectInstance *pThis);
void func_80090A8C(CGameObjectInstance *pThis) ;


void func_8008FA88(CInstanceHdr *pThis, CVector3 vPos, int AllowEntry);

void func_8008DCA0(CInstanceHdr *pThis, struct CParticle_t *pParticle);
void func_8008DCD8(CInstanceHdr *pThis, struct CParticle_t *pParticle);
void func_8008DD60(CGameObjectInstance *pThis);





#define _INC_TURRET 

void CeilingTurret_TransformPos(CGameObjectInstance *pThis, CVector3 *pvPos, CVector3 *pvWorld) ;
void CeilingTurretAI_Advance(CGameObjectInstance *pThis) ;

void BunkerTurret_TransformPos(CGameObjectInstance *pThis, CVector3 *pvPos, CVector3 *pvWorld) ;
void BunkerTurretAI_Advance(CGameObjectInstance *pThis) ;







#define _INC_CAMPAIGNER 

enum CampaignerModes
{

 CAMPAIGNER_IN_HOLE_IDLE_MODE,
 CAMPAIGNER_IN_HOLE_ATTACK_MODE,


 CAMPAIGNER_TALK_MODE,
 CAMPAIGNER_RAGE_MODE,
 CAMPAIGNER_VICTORY_MODE,


 CAMPAIGNER_IDLE_MODE,
 CAMPAIGNER_TURN180_MODE,
 CAMPAIGNER_TURN_LEFT90_MODE,
 CAMPAIGNER_TURN_RIGHT90_MODE,


 CAMPAIGNER_WALK_MODE,
 CAMPAIGNER_WALK_TURN180_MODE,
 CAMPAIGNER_WALK_TURN_LEFT90_MODE,
 CAMPAIGNER_WALK_TURN_RIGHT90_MODE,


 CAMPAIGNER_LIMP_MODE,
 CAMPAIGNER_LIMP_TURN180_MODE,
 CAMPAIGNER_LIMP_TURN_LEFT90_MODE,
 CAMPAIGNER_LIMP_TURN_RIGHT90_MODE,


 CAMPAIGNER_RUN_MODE,
 CAMPAIGNER_RUN_TURN180_MODE,
 CAMPAIGNER_RUN_TURN_LEFT90_MODE,
 CAMPAIGNER_RUN_TURN_RIGHT90_MODE,


 CAMPAIGNER_RUN_WEAPON_OVERHEAD_SMASH_MODE,
 CAMPAIGNER_WEAPON_FOREARM_SLASH_MODE,
 CAMPAIGNER_WEAPON_BACKHAND_SLASH_MODE,
 CAMPAIGNER_WEAPON_OVERHEAD_SLASH_MODE,
 CAMPAIGNER_WEAPON_FOREARM_SLASH2_MODE,
 CAMPAIGNER_WEAPON_BACKHAND_SLASH2_MODE,
 CAMPAIGNER_WEAPON_OVERHEAD_SLASH2_MODE,


 CAMPAIGNER_ATTACK_BACKHAND_MODE,
 CAMPAIGNER_ATTACK_SWIPE_MODE,
 CAMPAIGNER_ATTACK_BLOW_MODE,


 CAMPAIGNER_MAGIC_ENERGY_BLAST_MODE,
 CAMPAIGNER_MAGIC_SUMMON_EXPLOSION_MODE,
 CAMPAIGNER_MAGIC_SUPER_BLAST_MODE,
 CAMPAIGNER_MAGIC_SCATTER_BLAST_MODE,


 CAMPAIGNER_TELEPORT_MODE,


 CAMPAIGNER_WEAPON_IDLE_MODE,
 CAMPAIGNER_WEAPON_TURN180_MODE,
 CAMPAIGNER_WEAPON_TURN_LEFT90_MODE,
 CAMPAIGNER_WEAPON_TURN_RIGHT90_MODE,
 CAMPAIGNER_WEAPON_LAUGH_MODE,
 CAMPAIGNER_WEAPON_ATTACK_MODE,


 CAMPAIGNER_EVADE_BACK_FLIP_MODE,
 CAMPAIGNER_EVADE_MEGA_JUMP_MODE,


 CAMPAIGNER_RIGHT_SHOULDER_FLINCH_MODE,
 CAMPAIGNER_LEFT_SHOULDER_FLINCH_MODE,
 CAMPAIGNER_CHEST_FLINCH_MODE,
 CAMPAIGNER_BACK_FLINCH_MODE,
 CAMPAIGNER_DAMAGE_SHORTING_OUT_MODE,
 CAMPAIGNER_KNEE_FALL_FLINCH_MODE,
 CAMPAIGNER_KNEE_GETUP_MODE,


 CAMPAIGNER_EXPLODE_FRONT_MODE,
 CAMPAIGNER_EXPLODE_BACK_MODE,
 CAMPAIGNER_EXPLODE_LEFT_MODE,
 CAMPAIGNER_EXPLODE_RIGHT_MODE,


 CAMPAIGNER_DEATH_MODE,
 CAMPAIGNER_KILL_TUROK_MODE,

 CAMPAIGNER_END_MODE
} ;

typedef struct CampaignerStageInfo_t
{
 signed long HealthLimit ;

 float AnimSpeed ;

 float RunAttackTime ;

 signed short EvadePercentage ;
 float EvadeSpacing ;

 signed short FlinchPercentage ;
 float FlinchSpacing ;

 signed short ExplodeFlinchPercentage ;
 float ExplodeFlinchSpacing ;

 signed short ShortOutPercentage ;
 float ShortOutSpacing ;

 signed short BlockWeaponsPercentage ;
} CCampaignerStageInfo ;



typedef struct CCampaigner_t
{

 CBoss m_Boss ;


 CCampaignerStageInfo *m_pStageInfo ;
 CSpecialFx m_SpecialFx ;

 signed short m_HoleNumber ;
 CVector3 m_vTeleportDest ;
 int m_Limp ;

 int m_TeleportToHole ;
 int m_Teleported ;
 int m_StartedFx ;

 float m_RunTime ;
 float m_RunAttackTime ;
 float m_ExplosionAngle ;

 float m_EvadeTime ;
 float m_FlinchTime ;
 float m_ExplodeFlinchTime ;
 float m_ShortOutTime ;

 CShield m_Shield ;

 signed long m_WeaponToTakeOff ;

 CDamage *m_pDamage ;

 float m_TauntTimer ;
 float m_PlayingSoundTimer ;

 signed long m_LastSound ;

 CBossScript m_RunAttackScript ;
} CCampaigner ;





extern CCampaigner CampaignerBoss ;






typedef void(*CampaignerSetupFunction)(CGameObjectInstance *pThis, CCampaigner *pCampaigner) ;

CBoss *Campaigner_Initialise(CGameObjectInstance *pThis) ;
void Campaigner_Update(CGameObjectInstance *pThis, CCampaigner *pCampaigner) ;
signed long func_8004DACC(CGameObjectInstance *pThis, signed long nNewMode) ;


int func_8004F808(CGameObjectInstance *pThis, int nNode) ;
int func_8004F884(CGameObjectInstance *pThis, int nNode) ;





#define _INC_HEDTRACK 

#define REVERSE_CONCAT (1<<0)

#define TURN_FLIP_DIR (1<<1)
#define TURN_AXIS_X (1<<2)
#define TURN_AXIS_Y (1<<3)
#define TURN_AXIS_Z (1<<4)

#define TILT_FLIP_DIR (1<<5)
#define TILT_AXIS_X (1<<6)
#define TILT_AXIS_Y (1<<7)
#define TILT_AXIS_Z (1<<8)






typedef struct CHeadTrackNodeInfo_t
{
 signed long Flags ;
} CHeadTrackNodeInfo ;


typedef struct CHeadTrackInfo_t
{
 float EyeHeight ;

 float TurnAngleOffset ;
 float MaxTurnAngle ;
 float TurnSpeed ;

 float MinTiltAngle ;
 float MaxTiltAngle ;
 float TiltSpeed ;

 signed short MinHeadNode ;
 signed short MaxHeadNode ;

 CHeadTrackNodeInfo *pNodeInfo ;

 float BigHeadScale ;
} CHeadTrackInfo ;





void func_80043FFC(CGameObjectInstance *pThis) ;






#define _INC_CINECAM 

float func_8003AD20(CGameObjectInstance *pThis) ;


void func_8003B1C4(CCamera *pThis) ;
void func_8003B2C4(CCamera *pThis) ;

void func_8003B3CC(CCamera *pThis) ;
void func_8003B564(CCamera *pThis) ;

void func_8003B710(CCamera *pThis) ;
void func_8003B7AC(CCamera *pThis) ;

void func_8003B8CC(CCamera *pThis) ;
void func_8003B988(CCamera *pThis) ;

void func_8003BBB8(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_LONGHUNTER(CCamera *pThis) ;

void func_8003BC3C(CCamera *pThis) ;
void func_8003BC90(CCamera *pThis) ;

void func_8003BCD0(CCamera *pThis) ;
void func_8003BD30(CCamera *pThis) ;

void func_8003BDA8(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_TUROK_KILL_MANTIS(CCamera *pThis) ;
void CCamera__Setup_CINEMATIC_MANTIS_KILL_TUROK(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_MANTIS_KILL_TUROK(CCamera *pThis) ;

void func_8003C264(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_TUROK_KILL_TREX(CCamera *pThis) ;
void CCamera__Setup_CINEMATIC_TREX_KILL_TUROK(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_TREX_KILL_TUROK(CCamera *pThis) ;

void func_8003CAC8(CCamera *pThis) ;
void func_8003CB14(CCamera *pThis) ;

void func_8003CCD8(CCamera *pThis) ;
void func_8003CE10(CCamera *pThis) ;
void CCamera__Setup_CINEMATIC_CAMPAIGNER_KILL_TUROK(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_CAMPAIGNER_KILL_TUROK(CCamera *pThis) ;


void func_8003D450(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_TUROK_PICKUP_KEY(CCamera *pThis) ;


void func_8003D90C(CCamera *pThis) ;
void CCamera__Code_CINEMATIC_END_SEQUENCE(CCamera *pThis) ;
void func_8003DF00(CCamera *pThis) ;
void func_8003DFCC(CCamera *pThis) ;

void func_8003EB14(CCamera *pThis) ;
void func_8003EB44(CCamera *pThis) ;





#define _INC_AUDIOCFX 


#define CheckProbability(Percent) (SOUND_RANDOM(100) < Percent)

#define AMBIENT_SOUND_RATE 30

#define AMB_RGN_JUNGLE 0
#define AMB_RGN_WATER 1
#define AMB_RGN_CAVES 2
#define AMB_RGN_CATACOMBS 3
#define AMB_RGN_LOSTLANDS 4
#define AMB_RGN_CAMPAINER 5
#define AMB_RGN_CATACOMBS_LARGE 6
#define AMB_RGN_CITY 7
#define AMB_RGN_RUINS 8
#define AMB_RGN_TREETOP 9
#define AMB_RGN_WARP 10

#define MAX_NUM_AMBIENT_SOUNDS 24


#define RANDOMIZE_VOL (1 << 0)
#define RANDOMIZE_PITCH (1 << 1)
#define RANDOMIZE_POS (1 << 2)
#define AMB_RANDOMIZE_FAR (1 << 3)
#define AMB_RANDOMIZE_NEAR (1 << 4)
#define AMB_SCENE_POSITION (1 << 5)
#define SMALLENEMY_PITCH (1 << 6)
#define BIGENEMY_PITCH (1 << 7)

typedef struct
{
 signed short SoundNum[24];
 int Probability;
 int TotalNum;

} t_AmbientSounds;



void func_8008C250(CROMSoundElement *pElement, signed long channel, int SndFlags);
void func_8008C470(CROMSoundElement *pElement, signed long channel);
void func_8008BA10(CROMSoundElement *pElement,
        void *pInstance, CVector3 *vPos,
        float Volume, int cfxnum, int cfxhandle, int SndFlags);
signed long func_8008BEA4(CROMSoundElement *pElement, int cfxnum, int cfxhandle, CVector3 *vPos);
void func_8008D274();
float func_8008B9B0(float x, signed long y);
void func_8008CBEC(t_SoundPlayer *sndplayer, signed short Channel);
void func_8008C97C(signed long channel);
void func_8008C6D0(signed long channel);
void func_8008C66C(signed long channel);
float func_8008CB48(float PitchCents);
void func_8008CFC0();
void func_8008BC74(int cfxnum, CVector3 *vPos, int SndFlags);
void func_8008C15C(int channel, int SndFlags);
void func_8008BB50(int SampleNum, int SndFlags);





#define _INC_SNDDEFS 




#define SOUNDEFFECT_LOOP (1 << 0)
#define PITCH_ENV_ENABLED (1 << 1)
#define VOL_ENV_ENABLED (1 << 2)
#define CH_FLAG_STARTED (1 << 3)
#define CH_FLAG_DELAYED_START (1 << 4)
#define CH_FLAG_ENV_UPDATE (1 << 5)
#define CH_SAVER (1 << 6)
#define CH_FLAG_ENV_FADEOUT (1 << 7)
#define CH_FLAG_RAND_PITCH (1 << 8)
#define FADE_IF_OBSTRUCTED (1 << 9)
#define UPDATE_NONENV (1 << 10)
#define ALWAYS_MAXVOL (1 << 11)
#define LINK_TO_ENV (1 << 12)



#define VOLUME_QUIET 0
#define VOLUME_NORMAL 1
#define VOLUME_LOUD 2






#define _INC_GFX16BIT 




#define F3DEX_GBI 







extern unsigned char Font0[] ;
extern unsigned char Font1[] ;
extern unsigned char Font2[] ;
extern unsigned char Font3[] ;
extern unsigned char Font4[] ;
extern unsigned char Font5[] ;
extern unsigned char Font6[] ;
extern unsigned char Font7[] ;
extern unsigned char Font8[] ;
extern unsigned char Font9[] ;
extern unsigned char Font0_4[] ;
extern unsigned char Font1_4[] ;
extern unsigned char Font2_4[] ;
extern unsigned char Font3_4[] ;
extern unsigned char Font4_4[] ;
extern unsigned char Font5_4[] ;
extern unsigned char Font6_4[] ;
extern unsigned char Font7_4[] ;
extern unsigned char Font8_4[] ;
extern unsigned char Font9_4[] ;
extern unsigned char FontMinus[] ;


extern unsigned char FontA[] ;
extern unsigned char FontB[] ;
extern unsigned char FontC[] ;
extern unsigned char FontD[] ;
extern unsigned char FontE[] ;
extern unsigned char FontF[] ;
extern unsigned char FontG[] ;
extern unsigned char FontH[] ;
extern unsigned char FontI[] ;
extern unsigned char FontJ[] ;
extern unsigned char FontK[] ;
extern unsigned char FontL[] ;
extern unsigned char FontM[] ;
extern unsigned char FontN[] ;
extern unsigned char FontO[] ;
extern unsigned char FontP[] ;
extern unsigned char FontQ[] ;
extern unsigned char FontR[] ;
extern unsigned char FontS[] ;
extern unsigned char FontT[] ;
extern unsigned char FontU[] ;
extern unsigned char FontV[] ;
extern unsigned char FontW[] ;
extern unsigned char FontX[] ;
extern unsigned char FontY[] ;
extern unsigned char FontZ[] ;
extern unsigned char FontCopyRight[] ;
extern unsigned char FontLittleC[] ;
extern unsigned char FontPeriod[] ;
extern unsigned char FontComma[] ;
extern unsigned char FontQuoteL[] ;
extern unsigned char FontQuoteR[] ;
extern unsigned char FontTrademark[] ;
extern unsigned char FontRamp[] ;






extern unsigned char SmallFont[] ;


extern unsigned char HealthOverlay[] ;
extern unsigned char ArmourOverlay[] ;
extern unsigned char TurokHeadOverlay[] ;
extern unsigned char LifeForceOverlay[] ;
extern unsigned char AirBarOverlay[] ;
extern unsigned char BossBarOverlay[] ;
extern unsigned char GradientOverlay[] ;
extern unsigned char BarGradient[] ;
extern unsigned char LensFlareOverlay[] ;
extern unsigned char SunFlareOverlay[] ;


extern unsigned char Key2Overlay[] ;
extern unsigned char Key3Overlay[] ;
extern unsigned char Key4Overlay[] ;
extern unsigned char Key5Overlay[] ;
extern unsigned char Key6Overlay[] ;
extern unsigned char Key7Overlay[] ;
extern unsigned char Key8Overlay[] ;
extern unsigned char ChronoOverlay[] ;



extern unsigned char WalkOverlay[] ;
extern unsigned char RunOverlay[] ;


extern unsigned char RokOverlay[] ;





extern unsigned char AmmoArrowOverlay[] ;
extern unsigned char AmmoExpArrowOverlay[] ;
extern unsigned char AmmoBulletOverlay[] ;
extern unsigned char AmmoShellOverlay[] ;
extern unsigned char AmmoExpShellOverlay[] ;
extern unsigned char AmmoEnergyOverlay[] ;
extern unsigned char AmmoArrowOverlay[] ;
extern unsigned char AmmoMinigunOverlay[] ;
extern unsigned char AmmoGrenadeOverlay[] ;
extern unsigned char AmmoRocketOverlay[] ;

extern unsigned char AmmoKamfOverlay[] ;


extern unsigned char KnifeWeapon[] ;
extern unsigned char TekBowWeapon[] ;
extern unsigned char PistolWeapon[] ;
extern unsigned char RifleWeapon[] ;
extern unsigned char ShotgunWeapon[] ;
extern unsigned char AutoShotgunWeapon[] ;
extern unsigned char GrenadeWeapon[] ;
extern unsigned char RocketWeapon[] ;
extern unsigned char MinigunWeapon[] ;
extern unsigned char LongHunterWeapon[] ;
extern unsigned char InfantryWeapon[] ;
extern unsigned char ShockWeapon[] ;
extern unsigned char FusionWeapon[] ;
extern unsigned char CronosceptorWeapon[] ;


extern unsigned char SlabOverlay[] ;
extern unsigned char PauseOverlay[] ;
extern unsigned char GameOverOverlay[] ;
extern unsigned char OptionsOverlay[] ;
extern unsigned char SliderOverlay[] ;
extern unsigned char BarOverlay[] ;






#define _INC_GALRECAM 

void func_8003EE90(CCamera *pThis) ;
void func_8003EEB0(CCamera *pThis) ;
void CCamera__Code_GALLERY_IDLE(CCamera *pThis) ;





#define _INC_PERSIST 



#define PERSISTANT_DATA_MAX_SIZE 7000



extern u32 CrashId ;
extern u32 CrashMode ;
extern u32 CrashFrame ;
extern CROMWarpPoint CrashWarp;
extern unsigned char persistant_data[];






#define _INC_HUMVEE 

enum HumveeModes
{
 HUMVEE_WAIT_FOR_START_MODE,
 HUMVEE_JUMP_INTO_ARENA_MODE,

 HUMVEE_IDLE_MODE,
 HUMVEE_RUN_MODE,
 HUMVEE_TURN_LEFT90_MODE,
 HUMVEE_TURN_RIGHT90_MODE,
 HUMVEE_TURN180_MODE,
 HUMVEE_STOP_MODE,

 HUMVEE_EXPLODE_LEFT_MODE,
 HUMVEE_EXPLODE_RIGHT_MODE,
 HUMVEE_DEATH_MODE,

 HUMVEE_END_MODE
} ;

typedef int(*BossFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;
typedef int(*BossBooleanFunction)(CGameObjectInstance *pThis, CBoss *pBoss) ;


typedef struct FireWeaponState_t
{
 CGameObjectInstance *pObject ;
 BossBooleanFunction pCanFireFunction ;
 BossFunction pFireFunction ;

 signed long ShotsLeft ;
 float SingleShotTime ;
 float FireShotsTime ;
} CFireWeaponState ;


typedef struct CFireWeaponInfo_t
{
 signed long TotalShots ;
 float SingleShotSpacing ;
 float FireShotsSpacing ;
} CFireWeaponInfo ;



typedef struct HumveeStageInfo_t
{
 signed long HealthLimit ;
 float AnimSpeed ;
 signed short HitsBeforeExplode ;

 CFireWeaponInfo FireRocketsInfo ;
 CFireWeaponInfo FireGunsInfo ;
} CHumveeStageInfo ;



typedef struct CHumvee_t
{

 CBoss m_Boss ;


 signed short m_ScriptStage ;
 CHumveeStageInfo *m_pStageInfo ;

 float m_DistFromCentre ;

 signed short m_TargetNumber ;

 signed short m_ExplosionHits ;

 float m_CollisionTime ;

 float m_WheelVel ;
 float m_WheelAngle ;

 float m_LightGlareTime ;


 signed long m_Sound ;
 signed long m_SoundHandle ;


 CFireWeaponState m_GunsState ;
 CFireWeaponState m_RocketsState ;

} CHumvee ;







extern CHumvee HumveeBossList[] ;






typedef void(*HumveeSetupFunction)(CGameObjectInstance *pThis, CHumvee *pHumvee) ;

CBoss *func_8004B850(CGameObjectInstance *pThis) ;
int Humvee_CanFire(CGameObjectInstance *pThis, CHumvee *pHumvee) ;

void Humvee_Update(CGameObjectInstance *pThis, CHumvee *pHumvee) ;
signed long Humvee_SetupMode(CGameObjectInstance *pThis, signed long nNewMode) ;

void func_8004D0BC(CInstanceHdr *pThis, CVector3 vPos, float Value) ;








#define __AIWEAP_H 




#define SCALING_MAX_VISIBLE_DISTANCE 100.0
#define SCALING_FAR_CLIP 1024.0

#define SCALING_NEAR_CLIP (((int)SCALING_FAR_CLIP) >> 6)

#define SCALING_FACTOR (SCALING_FAR_CLIP/SCALING_MAX_VISIBLE_DISTANCE)
#define SCALING_MINIMUM_OBJECT_SCALE 0.5
#define SCALING_SIMPLE_OBJECT_SCALE 0.35
#define SCALING_DETAIL_OBJECT_SCALE 0.2
#define SCALING_DEF_INSTANCE_SCALE 0.02
#define SCALING_PLAYERWEAPON_SCALE 0.03
#define SCALING_PLAYER_SCALE 0.02
#define SCALING_SIMPLE_SCALE 1.0






#define DEFAULT_FOG_THICKNESS 0.8
#define DEFAULT_FIELD_OF_VIEW 47.5
#define FIELD_OF_VIEW_ANGLE(fov,aspect) ((fov)*(aspect))

#define SCALING_MAX_DIST(farClip,fov) (farClip/cos((fov)*(3.14159265358979323846/180.0)/2.0))


void func_8007A58C (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_80079BA0 (CGameObjectInstance *pMe);
int func_8007A6FC (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007A870 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007A974 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int AI_Update_Weapon_SemiAutomaticPistol (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007B024 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007B1A0 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007B348 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007B568 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007B790 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007BA2C (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007BC28 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007C698 (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
int func_8007C84C (CGameObjectInstance *pMe, CTControl *D_800F9E44, CTMove *pCTMove, int waterFlag);
void func_8007A548 (CGameObjectInstance *pAI);
void func_8007CC14 (CTMove *pThis);






#define _INC_MANTIS 

enum MantisModes
{
 MANTIS_SLEEPING_FLOOR_MODE,
 MANTIS_BREAK_FLOOR_MODE,

 MANTIS_IDLE_FLOOR_MODE,
 MANTIS_LOOK_FLOOR_MODE,

 MANTIS_WALK_FLOOR_MODE,
 MANTIS_TURN_FLOOR_LEFT90_MODE,
 MANTIS_TURN_FLOOR_RIGHT90_MODE,

 MANTIS_JUMP_FLOOR_A_MODE,
 MANTIS_JUMP_FLOOR_B_MODE,
 MANTIS_JUMP_FLOOR_C_MODE,


 MANTIS_PHASE_FLOOR_MODE,
 MANTIS_BLAST_FLOOR_MODE,
 MANTIS_SPIT_FLOOR_MODE,
 MANTIS_SIDE_SWIPE_FLOOR_MODE,
 MANTIS_FORWARD_SWIPE_FLOOR_MODE,


 MANTIS_VICTORY_IDLE_FLOOR_MODE,
 MANTIS_RAGE_FLOOR_MODE,


 MANTIS_JUMP_FLOOR_TO_CEILING_MODE,

 MANTIS_IDLE_CEILING_MODE,
 MANTIS_RAIN_CEILING_MODE,
 MANTIS_SPIT_CEILING_MODE,

 MANTIS_WALK_CEILING_MODE,
 MANTIS_TURN_CEILING_LEFT90_MODE,
 MANTIS_TURN_CEILING_RIGHT90_MODE,

  MANTIS_JUMP_CEILING_TO_FLOOR_MODE,

 MANTIS_JUMP_FLOOR_TO_LEFT_WALL_A_MODE,
 MANTIS_JUMP_FLOOR_TO_LEFT_WALL_B_MODE,
 MANTIS_JUMP_FLOOR_TO_LEFT_WALL_C_MODE,

 MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_A_MODE,
 MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_B_MODE,
 MANTIS_JUMP_RIGHT_WALL_TO_LEFT_WALL_C_MODE,

 MANTIS_IDLE_LEFT_WALL_MODE,
 MANTIS_JUMP_LEFT_WALL_TO_FLOOR_MODE,
 MANTIS_JUMP_LEFT_WALL_TO_CEILING_MODE,
 MANTIS_SPIT_LEFT_WALL_MODE,
 MANTIS_SPIT_LEFT_WALL_LOOP_MODE,

 MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_A_MODE,
 MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_B_MODE,
 MANTIS_JUMP_FLOOR_TO_RIGHT_WALL_C_MODE,

 MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_A_MODE,
 MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_B_MODE,
 MANTIS_JUMP_LEFT_WALL_TO_RIGHT_WALL_C_MODE,

 MANTIS_IDLE_RIGHT_WALL_MODE,
 MANTIS_JUMP_RIGHT_WALL_TO_FLOOR_MODE,
 MANTIS_JUMP_RIGHT_WALL_TO_CEILING_MODE,
 MANTIS_SPIT_RIGHT_WALL_MODE,
 MANTIS_SPIT_RIGHT_WALL_LOOP_MODE,

 MANTIS_EXPLODE_FLOOR_BACK_MODE,
 MANTIS_EXPLODE_FLOOR_FRONT_MODE,
 MANTIS_EXPLODE_FLOOR_LEFT_MODE,
 MANTIS_EXPLODE_FLOOR_RIGHT_MODE,

 MANTIS_EXPLODE_CEILING_MODE,
 MANTIS_EXPLODE_LEFT_WALL_MODE,
 MANTIS_EXPLODE_RIGHT_WALL_MODE,

 MANTIS_DEATH_FLOOR_MODE,


 MANTIS_KILLTUROK_MODE,
 MANTIS_CINEMA1_MODE,
 MANTIS_CINEMA2_MODE,
 MANTIS_CINEMA3_MODE,
 MANTIS_CINEMA4_MODE,
 MANTIS_CINEMA5_MODE,

 MANTIS_END_MODE
} ;

typedef struct MantisStageInfo_t
{
 signed long HealthLimit ;

 float AnimSpeed ;
 float FlySpeed ;
 float MaxWalkTime ;
 signed long FlySpitSkips ;
 signed long HitsBeforeExplosion ;
 float *pAttackGlowFx ;

 signed short *pFloorAttackScript ;
 signed short *pFloorCloseAttackScript ;
 signed short *pCeilingAttackScript ;
 signed short *pLeftWallAttackScript ;
 signed short *pRightWallAttackScript ;
} CMantisStageInfo ;




typedef struct CMantis_t
{

 CBoss m_Boss ;

 signed short m_ScriptStage ;
 CMantisStageInfo *m_pStageInfo ;

 CBossScript m_FloorAttackScript ;
 CBossScript m_FloorCloseAttackScript ;
 CBossScript m_CeilingAttackScript ;
 CBossScript m_LeftWallAttackScript ;
 CBossScript m_RightWallAttackScript ;

 int m_WallBroken[4] ;
 signed short m_WallsToBreak ;
 signed short m_WallToAimFor ;
 signed short m_WallToAimForJumpPos ;

 CGameRegion *m_pWallCollisionRegion ;
 CVector3 m_vWallPos ;
 float m_WallCollapseTime ;

 int m_GotoFloor ;
 float m_FlyTargetY ;
 float m_FlySpeed ;
 float m_FlyTime ;
 float m_WallAngle ;

 float m_WalkTime ;

 signed short m_FlySpitTotal ;
 int m_FlinchGlow ;

 int m_ChoosePosition ;
 CSpecialFx m_SpecialFx ;
 CSpecialFx m_FlashSpecialFx ;

 signed long m_ExplosionHits ;

 int m_AcidHurtTurok ;
} CMantis ;


enum MantisActions
{
 MANTIS_ATTACK_ACTION,
 MANTIS_BREAK_WALL_ACTION,
 MANTIS_RAGE_ACTION,

 MANTIS_END_ACTION
} ;


typedef void(*MantisSetupFunction)(CGameObjectInstance *pThis, CMantis *pMantis) ;






extern CMantis D_80127480 ;






CBoss *func_800442AC(CGameObjectInstance *pThis) ;
void func_800444D8(CGameObjectInstance *pThis, CMantis *pMantis) ;
int func_80045E1C(CGameObjectInstance *pThis, CMantis *pMantis) ;

signed long Mantis_SetupMode(CGameObjectInstance *pThis, signed long nNewMode) ;

void Mantis_UpdateGlow(CGameObjectInstance *pThis, CMantis *pMantis) ;
void Mantis_StartGlow(CGameObjectInstance *pThis, CMantis *pMantis, signed short Count) ;
void func_800447B4(CGameObjectInstance *pThis, CMantis *pMantis, Gfx **ppDLP) ;
void func_80044890(CGameObjectInstance *pThis, CMantis *pMantis, Gfx **ppDLP) ;









#define VERSION_NUMBER 49







#define _INC_LONGHUNT 

enum LonghuntModes
{

 LONGHUNT_WAIT_FOR_START_MODE,
 LONGHUNT_SUMMON_HUMVEE_MODE,
 LONGHUNT_WAIT_FOR_HUMVEE_ENTRANCE_MODE,
 LONGHUNT_WAIT_FOR_HUMVEES_DEATH_MODE,


 LONGHUNT_STAND_IDLE_MODE,
 LONGHUNT_STAND_TURN180_MODE,
 LONGHUNT_STAND_TURN_LEFT90_MODE,
 LONGHUNT_STAND_TURN_RIGHT90_MODE,


 LONGHUNT_TAUNT1_MODE,


 LONGHUNT_WALK_MODE,
 LONGHUNT_WALK_TURN180_MODE,
 LONGHUNT_WALK_TURN_LEFT90_MODE,
 LONGHUNT_WALK_TURN_RIGHT90_MODE,


 LONGHUNT_RUN_MODE,
 LONGHUNT_RUN_TURN180_MODE,
 LONGHUNT_RUN_TURN_LEFT90_MODE,
 LONGHUNT_RUN_TURN_RIGHT90_MODE,


 LONGHUNT_EVADE_LEFT_MODE,
 LONGHUNT_EVADE_RIGHT_MODE,


 LONGHUNT_ROUNDHOUSE_MODE,
 LONGHUNT_JUMP_KICK_MODE,
 LONGHUNT_SWING_PUNCH_MODE,


 LONGHUNT_FIRE_GUN_MODE,
 LONGHUNT_THROW_GRENADE_MODE,
 LONGHUNT_RUN_FIRE_GUN_MODE,


 LONGHUNT_DEATH_MODE,

 LONGHUNT_END_MODE
} ;




enum LonghuntActions
{
 LONGHUNT_WAIT_FOR_HUMVEES_DEATH_ACTION,
 LONGHUNT_ATTACK_ACTION,
 LONGHUNT_VICTORY_ACTION,
 LONGHUNT_END_ACTION
} ;

typedef struct LonghuntStageInfo_t
{
 signed long HealthLimit ;

 float AnimSpeed ;

 float EvadeTime ;
 signed short EvadeSkips ;
 float NoEvadeTime ;

 signed short FlinchPercentage ;

 float RunAttackTime ;
 signed long GunFireTotal ;
} CLonghuntStageInfo ;



typedef struct CLonghunt_t
{

 CBoss m_Boss ;


 signed short m_ScriptStage ;
 CLonghuntStageInfo *m_pStageInfo ;

 int m_EvadeActive ;
 float m_EvadeTime ;
 signed short m_EvadeCount ;

 float m_RunTime ;
 float m_RunAttackTime ;
 float m_RunAngle ;

 float m_SoundTimer ;
} CLonghunt ;






extern CLonghunt D_80127960 ;






typedef void(*LonghuntSetupFunction)(CGameObjectInstance *pThis, CLonghunt *pLonghunt) ;

CBoss *func_80049C80(CGameObjectInstance *pThis) ;
void func_80049EB4(CGameObjectInstance *pThis, CLonghunt *pLonghunt) ;
signed long Longhunt_SetupMode(CGameObjectInstance *pThis, signed long nNewMode) ;

int func_8004B828(CGameObjectInstance *pThis, int nNode) ;






void qsort (
    void *base,
    unsigned num,
    unsigned width,
    int (*comp)(const void *, const void *),
  void (*swap)(const void *, const void *)
    );







#define _INC_CRDCAM 








void func_8003ECF0(CCamera *pThis);
void func_8003ED10(CCamera *pThis);



/* File-local reference macros needed by mapped bodies; numeric retail configuration remains in defs.h. */
#ifndef AI_ASSIST_RTURN_SPEED
#define AI_ASSIST_RTURN_SPEED			ANGLE_DTOR(10)
#endif
#ifndef AI_ASSIST_RUN_SPEED
#define AI_ASSIST_RUN_SPEED			ANGLE_DTOR(15)
#endif
#ifndef AI_ASSIST_TURN_SPEED
#define AI_ASSIST_TURN_SPEED			ANGLE_DTOR(2)
#endif
#ifndef AI_ASSIST_WALK_SPEED
#define AI_ASSIST_WALK_SPEED			ANGLE_DTOR(7.5)
#endif
#ifndef AI_ASSIST_WTURN_SPEED
#define AI_ASSIST_WTURN_SPEED			ANGLE_DTOR(4)
#endif
#ifndef CAMPAIGNER_DO_TELEPORT_DIST
#define	CAMPAIGNER_DO_TELEPORT_DIST		(60*SCALING_FACTOR)
#endif
#ifndef CAMPAIGNER_FACING_ANGLE
#define	CAMPAIGNER_FACING_ANGLE				ANGLE_DTOR(20)
#endif
#ifndef CAMPAIGNER_HEALTH
#define	CAMPAIGNER_HEALTH					3000
#endif
#ifndef CAMPAIGNER_TURN180_ANGLE
#define	CAMPAIGNER_TURN180_ANGLE			ANGLE_DTOR(150)
#endif
#ifndef CAMPAIGNER_TURN90_ANGLE
#define	CAMPAIGNER_TURN90_ANGLE				ANGLE_DTOR(20)
#endif
#ifndef CAMPAIGNER_WALK_FACING_ANGLE
#define	CAMPAIGNER_WALK_FACING_ANGLE		ANGLE_DTOR(25)
#endif
#ifndef CAMPAIGNER_WALK_TURN90_ANGLE
#define	CAMPAIGNER_WALK_TURN90_ANGLE		ANGLE_DTOR(35)
#endif
#ifndef CAMP_RIGHT_UPPER_LEG_GEOM_DAMAGE_FLAG
#define CAMP_RIGHT_UPPER_LEG_GEOM_DAMAGE_FLAG	(1<<8)
#endif
#ifndef CREDIT_SIZE
#define CREDIT_SIZE	21
#endif
#ifndef GR_MAX_XTILT
#define GR_MAX_XTILT				25
#endif
#ifndef GR_MAX_ZTILT
#define GR_MAX_ZTILT				25
#endif
#ifndef GR_ZTILT_FACTOR
#define GR_ZTILT_FACTOR			0.5
#endif
#ifndef HUMVEE_ARENA_RADIUS
#define	HUMVEE_ARENA_RADIUS			(170*SCALING_FACTOR)
#endif
#ifndef HUMVEE_TURN180_ANGLE
#define	HUMVEE_TURN180_ANGLE			ANGLE_DTOR(160)
#endif
#ifndef HUMVEE_TURN90_ANGLE
#define	HUMVEE_TURN90_ANGLE 			ANGLE_DTOR(90)
#endif
#ifndef HUMVEE_TURN_SPEED
#define	HUMVEE_TURN_SPEED 			ANGLE_DTOR(5)
#endif
#ifndef HUMVEE_TUROK_TARGET_OFFSET
#define	HUMVEE_TUROK_TARGET_OFFSET	(0*SCALING_FACTOR)
#endif
#ifndef LONGHUNT_HEALTH
#define	LONGHUNT_HEALTH									1000
#endif
#ifndef MANTIS_HEALTH
#define	MANTIS_HEALTH					3000
#endif
#ifndef PARTICLE_RAISE
#define PARTICLE_RAISE	(SCALING_FACTOR/3)
#endif
#ifndef TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE
#define	TMOVE_AUTOAIM_ANGLE_ASSAULTRIFLE				12
#endif
#ifndef TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN
#define	TMOVE_AUTOAIM_ANGLE_AUTOMATICSHOTGUN		3
#endif
#ifndef TMOVE_AUTOAIM_ANGLE_MINIGUN
#define	TMOVE_AUTOAIM_ANGLE_MINIGUN					3
#endif
#ifndef TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN
#define	TMOVE_AUTOAIM_ANGLE_RIOTSHOTGUN				12
#endif
#ifndef TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL
#define	TMOVE_AUTOAIM_ANGLE_SEMIAUTOMATICPISTOL	18
#endif
#ifndef TREX_HEALTH
#define TREX_HEALTH	6000
#endif

#define PLAY_ROM_DEMOS 1
extern signed short D_800BDE80[];
typedef struct CAttractBuffer_t
{
 unsigned long m_Value ;
 unsigned char *m_pData ;
 unsigned long m_CurrentBit ;
 signed long m_Frames ;
 void (*m_pReadFunction)(void *pThis) ;
 void (*m_pWriteFunction)(void *pThis) ;
 unsigned long (*m_pGetValueFunction)(void *pThis) ;
} CAttractBuffer ;
typedef struct CAttractDemo_t
{
 signed short *m_pCurrentDemo ;
 int m_DemoRequested ;
 volatile int m_DemoRecieved ;
 unsigned char m_DemoBuffer[(1024*2)] ;

 int m_Active ;
 int m_Record ;
 int m_Play ;
 int m_FirstFrame ;
 int m_Finished ;

 CAttractBuffer m_ButtonBuffer ;
 CAttractBuffer m_StickXBuffer ;
 CAttractBuffer m_StickYBuffer ;
 CAttractBuffer m_NextFieldsBuffer ;
 CAttractBuffer m_UpdatedBuffer ;

 signed long m_PlayRecordFrame ;
 signed long m_TotalFrames ;
 float m_TotalTime ;
 unsigned long m_Checksum ;
} CAttractDemo ;
CAttractDemo D_80128140 ;
int func_8004FCA0(int nDemo)
;
