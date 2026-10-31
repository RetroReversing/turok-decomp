typedef signed int s32;typedef unsigned int u32;typedef unsigned short u16;
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state;} OSThread;
typedef void *OSMesg;
typedef struct {OSThread *mtqueue,*fullqueue;s32 validCount,first,msgCount;OSMesg *msg;} OSMesgQueue;
extern OSThread *D_800EF290,*D_800EF288;
u32 func_800A5750(void);void func_800A5770(u32);void func_800A5DEC(OSThread**);OSThread *func_800A5F34(OSThread**);void func_800A5F44(void);
void osStartThread(OSThread*);void __osEnqueueThread(OSThread**,OSThread*);
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
#define __osEnqueueAndYield func_800A5DEC
#define __osPopThread func_800A5F34
#define __osDispatchThread func_800A5F44
#define __osRunningThread D_800EF290
#define __osRunQueue D_800EF288
#define OS_STATE_WAITING 8
#define OS_STATE_RUNNABLE 2
#define OS_STATE_STOPPED 1
#define OS_MESG_BLOCK 1
#define OS_MESG_NOBLOCK 0
#define MQ_IS_FULL(mq) ((mq)->validCount >= (mq)->msgCount)

#define NULL ((void*)0)
typedef struct{OSMesgQueue *messageQueue;OSMesg message;}__OSEventState;
extern __OSEventState D_800EF2D0[];
#define __osEventStateTab D_800EF2D0
#define OS_EVENT_PI 8

extern __OSEventState D_801369A0[];
