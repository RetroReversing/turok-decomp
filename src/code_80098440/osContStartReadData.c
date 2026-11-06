#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void OSMesgQueue;typedef void *OSMesg;
typedef struct {u32 ramarray[15];u32 pifstatus;} PifRam;
typedef struct {u16 button;s8 stick_x,stick_y;u8 errno;} OSContPad;
typedef struct {u8 dummy,txsize,rxsize,cmd;u16 button;s8 stick_x,stick_y;} __OSContReadFormat;
extern PifRam D_80137C00;extern u8 D_80137C40,D_80137C41;
void __osPackReadData(void);void __osSiGetAccess(void);void __osSiRelAccess(void);s32 __osSiRawStartDma(s32,void*);s32 osRecvMesg(OSMesgQueue*,OSMesg*,s32);
#define __osContPifRam D_80137C00
#define __osContLastCmd D_80137C40
#define __osMaxControllers D_80137C41
#define __osSiGetAccess __osSiGetAccess
#define __osSiRelAccess __osSiRelAccess
#define __osSiRawStartDma __osSiRawStartDma
#define CONT_READ 1
#define OS_WRITE 1
#define OS_READ 0
#define PIFRAMSIZE 16
#define OS_MESG_BLOCK 1
#define CON_ERR_MASK 0xc0
#define CONT_FORMAT 1
#define FORMAT_END 0xfe
#line 26 "CONTREADDATA.C"
s32
osContStartReadData(OSMesgQueue *mq)
{
	s32	ret = 0;
	int i;

	/* Block to get resource token */
	__osSiGetAccess();

	if (CONT_READ != __osContLastCmd) {

		/* Set up request command format for all channels */

		__osPackReadData();
		ret = __osSiRawStartDma(OS_WRITE, &__osContPifRam);
		(void)osRecvMesg(mq, (OSMesg *)NULL, OS_MESG_BLOCK);
	}

	/* trigger pifmacro */

	for (i = 0; i < PIFRAMSIZE ; i++)
		__osContPifRam.ramarray[i] = 0xff;
	__osContPifRam.pifstatus = 0;
	ret = __osSiRawStartDma(OS_READ, &__osContPifRam);

	__osContLastCmd = CONT_READ;
	
	/* Return resource token */
	__osSiRelAccess();
	return(ret);
}

