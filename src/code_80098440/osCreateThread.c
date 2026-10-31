#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {u8 pad0[0x18];u64 a0;u8 pad1[0xb0];u64 sp,s8,ra;u8 pad2[16];u32 sr,pc,cause,badvaddr,rcp,fpcsr;} ThreadContext;
typedef struct OSThread {struct OSThread *next;s32 priority;struct OSThread **queue;struct OSThread *tlnext;u16 state,flags;s32 id,fp;ThreadContext context;} OSThread;
typedef s32 OSId;typedef s32 OSPri;typedef u32 OSIntMask;
u32 func_800A5750(void);void func_800A5770(u32);void func_800A60C0(void);
extern OSThread *D_800EF28C;
#define __osDisableInt func_800A5750
#define __osRestoreInt func_800A5770
#define __osCleanupThread func_800A60C0
#define __osActiveQueue D_800EF28C
#define ARGSAVE 16
#define OS_IM_ALL 0x3fff01
#define OS_IM_CPU 0xff01
#define SR_EXL 2
#define RCP_IMASK 0x3f0000
#define RCP_IMASKSHIFT 16
#define FPCSR_FS 0x1000000
#define FPCSR_EV 0x800
#define OS_STATE_STOPPED 1
#line 25 "CREATETHREAD.C"
void
osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg,
	       void *sp, OSPri p)
{
	register u32	saveMask;
	OSIntMask	mask;

#ifdef _DEBUG
	if ((u32)sp & 0x7) {
	    __osError(ERR_OSCREATETHREAD_SP, 1, sp);
	    return;
	}

	if ((p < OS_PRIORITY_IDLE) || (p > OS_PRIORITY_MAX)) {
	    __osError(ERR_OSCREATETHREAD_PRI, 1, p);
	    return;
	}
#endif
	/*
	 * The stack pointer is adjusted since the argument register(s)
	 * are stored into the *caller's* stack frame with the current
	 * calling convention.
	 *
	 * The SR_EXL bit is turned on to ensure interrupts are locked out
	 * for the dispatcher (see __osThreadDispatch).
	 *
	 * Initialize the return address to a procedure that will destroy
	 * the thread if the thread simply returns.
	 */

	t->id = id;
	t->priority = p;
	t->next = (OSThread *)NULL;
	t->queue = (OSThread **)NULL;
	t->context.pc = (u32)entry;
	t->context.a0 = (u64)arg;
	t->context.sp = (u64)sp - ARGSAVE;
	t->context.ra = (u64)__osCleanupThread;
	mask = OS_IM_ALL;
	t->context.sr = (mask & OS_IM_CPU)|SR_EXL;
	t->context.rcp = (mask & RCP_IMASK) >> RCP_IMASKSHIFT;
	t->context.fpcsr = FPCSR_FS | FPCSR_EV;
	t->fp = 0;
	t->state = OS_STATE_STOPPED;
	t->flags = 0;

	/*
	 * Put the thread onto a list of all active threads for the debugger.
	 */

	/* Disable interrupts */
	saveMask = __osDisableInt();

	t->tlnext = __osActiveQueue;
	__osActiveQueue = t;

	/* Restore interrupts */
	__osRestoreInt(saveMask);
}

