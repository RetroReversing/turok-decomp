#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void OSThread;typedef void OSMesgQueue;typedef void *OSMesg;typedef s32 OSPri;
typedef struct {s32 active;OSThread *thread;OSMesgQueue *cmdQueue,*evtQueue,*acsQueue;void(*dma)(void),(*edma)(void);} OSDevMgr;
typedef struct {struct {u16 type;u8 pri,status;OSMesgQueue *retQueue;}hdr;u8 rest[16];} OSIoMesg;
OSDevMgr D_800EF210={0};extern OSDevMgr D_800EF240;extern s32 D_800EF340;
extern u8 D_80136A30[],D_80136BE0[],D_80137BE0[],D_80137BF8[],D_80139F78[],D_80137CD0[],D_80137E80[],D_80138E80[],D_80138E98[];
extern OSIoMesg D_80138EB0,D_80138EC8;
u32 __osDisableInt(void);void __osRestoreInt(u32);OSPri osGetThreadPri(OSThread*);void osSetThreadPri(OSThread*,OSPri);
void osSetEventMesg(s32,OSMesgQueue*,OSMesg);void osCreateMesgQueue(OSMesgQueue*,OSMesg*,s32);void osCreateThread(OSThread*,s32,void(*)(void*),void*,void*,OSPri);void osStartThread(OSThread*);
void __osTimerServicesInit(void);void __osViInit(void);void __osPiCreateAccessQueue(void);void viMgrMain(void*);void __osDevMgrMain(void*);void osPiRawStartDma(void);void osEPiRawStartDma(void);
#define __osDisableInt __osDisableInt
#define __osRestoreInt __osRestoreInt
#define osGetThreadPri osGetThreadPri
#define __osViDevMgr D_800EF240
#define __osPiDevMgr D_800EF210
#define __osViInit __osViInit
#define __osPiCreateAccessQueue __osPiCreateAccessQueue
#define __osPiAccessQueueEnabled D_800EF340
#define __osPiAccessQueue (*(OSMesgQueue*)D_80139F78)
#define viThread (*(OSThread*)D_80137CD0)
#define viThreadStack D_80137E80
#define viEventQueue (*(OSMesgQueue*)D_80138E80)
#define viEventBuf ((OSMesg*)D_80138E98)
#define viRetraceMsg D_80138EB0
#define viCounterMsg D_80138EC8
#define viMgrMain viMgrMain
#define piThread (*(OSThread*)D_80136A30)
#define piThreadStack D_80136BE0
#define piEventQueue (*(OSMesgQueue*)D_80137BE0)
#define piEventBuf ((OSMesg*)D_80137BF8)
#define __osDevMgrMain __osDevMgrMain
#define osPiRawStartDma osPiRawStartDma
#define osEPiRawStartDma osEPiRawStartDma
#define OS_VIM_STACKSIZE 4096
#define OS_PIM_STACKSIZE 4096
#define OS_MESG_TYPE_VRETRACE 13
#define OS_MESG_TYPE_COUNTER 14
#define OS_MESG_PRI_NORMAL 0
#define OS_EVENT_VI 7
#define OS_EVENT_COUNTER 3
#define OS_EVENT_PI 8
#define PI_EVENT_MESG 0x22222222
#define _FINALROM 1
#define _ULTRA64 1

#define NUM_EV_MESG 1
#line 100 "PIMGR.C"
void
osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt)
{
    u32		savedMask;
    OSPri	oldPri, myPri;

#ifdef _DEBUG
    if ((pri < OS_PRIORITY_IDLE) || (pri > OS_PRIORITY_MAX)) {
	__osError(ERR_OSCREATEPIMANAGER, 1, pri);
	return;
    }
#endif

    /* If PI Manager is already running, simply return */
    if (__osPiDevMgr.active) 
        return;

    /* Create the input I/O command queue, wait queue, and access queue */
    osCreateMesgQueue(cmdQ, cmdBuf, cmdMsgCnt);
    osCreateMesgQueue(&piEventQueue, piEventBuf, NUM_EV_MESG);
    if (!__osPiAccessQueueEnabled)
        __osPiCreateAccessQueue();

    /* Take over PI interrupt */
    osSetEventMesg(OS_EVENT_PI, &piEventQueue, (OSMesg)PI_EVENT_MESG);

    /*
     * Check the current thread priority against the PIM's priority.
     * If current is lower, temporarily increase it to same level as PIM
     */
    oldPri = -1;
	myPri = osGetThreadPri((OSThread *)NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri((OSThread *)NULL, pri);
    }

    /* Set global to tell that Peripheral Interface Manager is on and active */
    savedMask = __osDisableInt();

    __osPiDevMgr.active		= 1;
    __osPiDevMgr.thread		= &piThread;
    __osPiDevMgr.cmdQueue	= cmdQ;
    __osPiDevMgr.evtQueue	= &piEventQueue;
    __osPiDevMgr.acsQueue	= &__osPiAccessQueue;
    __osPiDevMgr.dma		= osPiRawStartDma;
    __osPiDevMgr.edma		= osEPiRawStartDma;

    osCreateThread(&piThread, 0, __osDevMgrMain, (void *)&__osPiDevMgr,
		   piThreadStack+OS_PIM_STACKSIZE, (OSPri)pri);

    osStartThread(&piThread);

#ifndef _FINALROM
    osCreateThread(&ramromThread, 0, ramromMain, NULL,
		   ramromThreadStack+OS_PIM_RAMROM_STACKSIZE, (OSPri)pri - 1);
    osStartThread(&ramromThread);

#endif /* ifndef _FINALROM */

    /* Restore original interrupt mask */
    __osRestoreInt(savedMask);

    /* Restore original thread priority */
    if (oldPri != -1)
        osSetThreadPri((OSThread *)NULL, oldPri);

}
