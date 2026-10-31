#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void OSThread;typedef void OSMesgQueue;typedef void *OSMesg;typedef s32 OSPri;
typedef struct {s32 active;OSThread *thread;OSMesgQueue *cmdQueue,*evtQueue,*acsQueue;void(*dma)(void),(*edma)(void);} OSDevMgr;
typedef struct {struct {u16 type;u8 pri,status;OSMesgQueue *retQueue;}hdr;u8 rest[16];} OSIoMesg;
OSDevMgr D_800EF240={0};extern OSDevMgr D_800EF210;extern s32 D_800EF340;
extern u8 D_80136A30[],D_80136BE0[],D_80137BE0[],D_80137BF8[],D_80139F78[],D_80137CD0[],D_80137E80[],D_80138E80[],D_80138E98[];
OSIoMesg D_80138EB0,D_80138EC8;
u32 func_800A5750(void);void func_800A5770(u32);OSPri func_800A1920(OSThread*);void osSetThreadPri(OSThread*,OSPri);
void osSetEventMesg(s32,OSMesgQueue*,OSMesg);void osCreateMesgQueue(OSMesgQueue*,OSMesg*,s32);void osCreateThread(OSThread*,s32,void(*)(void*),void*,void*,OSPri);void osStartThread(OSThread*);
void __osTimerServicesInit(void);void func_800A7090(void);void func_800A71E0(void);void func_800A0F38(void*);void func_800A7460(void*);void func_800A72A0(void);void func_800A7380(void);
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
#define osGetThreadPri func_800A1920
#define __osViDevMgr D_800EF240
#define __osPiDevMgr D_800EF210
#define __osViInit func_800A7090
#define __osPiCreateAccessQueue func_800A71E0
#define __osPiAccessQueueEnabled D_800EF340
#define __osPiAccessQueue (*(OSMesgQueue*)D_80139F78)
#define viThread (*(OSThread*)D_80137CD0)
#define viThreadStack D_80137E80
#define viEventQueue (*(OSMesgQueue*)D_80138E80)
#define viEventBuf ((OSMesg*)D_80138E98)
#define viRetraceMsg D_80138EB0
#define viCounterMsg D_80138EC8
#define viMgrMain func_800A0F38
#define piThread (*(OSThread*)D_80136A30)
#define piThreadStack D_80136BE0
#define piEventQueue (*(OSMesgQueue*)D_80137BE0)
#define piEventBuf ((OSMesg*)D_80137BF8)
#define __osDevMgrMain func_800A7460
#define osPiRawStartDma func_800A72A0
#define osEPiRawStartDma func_800A7380
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

#define NUM_EV_MESG 5
#line 92 "VIMGR.C"
void
osCreateViManager(OSPri pri)
{
    u32		savedMask;
    OSPri	oldPri, myPri;

#ifdef _DEBUG
    if ((pri < OS_PRIORITY_IDLE) || (pri > OS_PRIORITY_MAX)) {
	__osError(ERR_OSCREATEVIMANAGER, 1, pri);
	return;
    }
#endif

    /* If VI Manager is already running, simply return */
    if (__osViDevMgr.active) 
        return;

#ifdef _ULTRA64
    /* Initialize timer services which use VI interrupt handler */
    __osTimerServicesInit();
#endif

    /* Create the input event queue */
    osCreateMesgQueue(&viEventQueue, viEventBuf, NUM_EV_MESG);

    viRetraceMsg.hdr.type     = OS_MESG_TYPE_VRETRACE;
    viRetraceMsg.hdr.pri      = OS_MESG_PRI_NORMAL;
    viRetraceMsg.hdr.retQueue = NULL;

    viCounterMsg.hdr.type     = OS_MESG_TYPE_COUNTER;
    viCounterMsg.hdr.pri      = OS_MESG_PRI_NORMAL;
    viCounterMsg.hdr.retQueue = NULL;

    /* Take over VI interrupt */
    osSetEventMesg(OS_EVENT_VI, &viEventQueue, (OSMesg)&viRetraceMsg);

    /* Take over COUNTER interrupt */
    osSetEventMesg(OS_EVENT_COUNTER, &viEventQueue, (OSMesg)&viCounterMsg);

    /*
     * Check the current thread priority against the VIM's priority.
     * If current is lower, temporarily increase it to same level as VIM
     */
    oldPri = -1;
    myPri = osGetThreadPri((OSThread *)NULL);
    if (myPri < pri) {
        oldPri = myPri;
        osSetThreadPri(NULL, pri);
    }

    /* Set global to tell that Video Interface Manager is on and active */
    savedMask = __osDisableInt();

    __osViDevMgr.active		= 1;
    __osViDevMgr.thread		= &viThread;
    __osViDevMgr.cmdQueue	= &viEventQueue;
    __osViDevMgr.evtQueue	= &viEventQueue;
    __osViDevMgr.acsQueue	= (OSMesgQueue *)NULL;
    __osViDevMgr.dma		= NULL;
    __osViDevMgr.edma		= NULL;

    /* Create VI manager thread with VI and CPU counter interrupts enabled */
    osCreateThread(&viThread, 0, viMgrMain, (void *)&__osViDevMgr,
		   viThreadStack+OS_VIM_STACKSIZE, (OSPri)pri);

    /* 
     * Initialize internal VI structures and set hardware registers to
     * enable vertical retrace.
     */
    __osViInit();

    osStartThread(&viThread);

    /* Restore original interrupt mask */
    __osRestoreInt(savedMask);

    /* Restore original thread priority */
    if (oldPri != -1)
        osSetThreadPri(NULL, oldPri);

}
