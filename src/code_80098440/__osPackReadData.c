#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void OSMesgQueue;typedef void *OSMesg;
typedef struct {u32 ramarray[15];u32 pifstatus;} PifRam;
typedef struct {u16 button;s8 stick_x,stick_y;u8 errno;} OSContPad;
typedef struct {u8 dummy,txsize,rxsize,cmd;u16 button;s8 stick_x,stick_y;} __OSContReadFormat;
extern PifRam D_80137C00;extern u8 D_80137C40,D_80137C41;
void __osPackReadData(void);void func_800A8520(void);void func_800A8564(void);s32 func_800A8590(s32,void*);s32 osRecvMesg(OSMesgQueue*,OSMesg*,s32);
#define __osContPifRam D_80137C00
#define __osContLastCmd D_80137C40
#define __osMaxControllers D_80137C41
#define __osSiGetAccess func_800A8520
#define __osSiRelAccess func_800A8564
#define __osSiRawStartDma func_800A8590
#define CONT_READ 1
#define OS_WRITE 1
#define OS_READ 0
#define PIFRAMSIZE 16
#define OS_MESG_BLOCK 1
#define CON_ERR_MASK 0xc0
#define CONT_FORMAT 1
#define FORMAT_END 0xfe
#line 89 "CONTREADDATA.C"
       void
__osPackReadData(void)
{
	u8 			*ptr = (u8 *)(&__osContPifRam);
	__OSContReadFormat 	readformat;
	int 			i;

	/* clear pif ram */

	for (i = 0; i < PIFRAMSIZE ; i++)
		__osContPifRam.ramarray[i] = 0;
#ifndef _HW_VERSION_1
	__osContPifRam.pifstatus = CONT_FORMAT;
#else
	__osContPifRam.pifstatus = 0;
#endif 


	/* Setup read format for each channel */

	readformat.dummy = 0xff;
	readformat.txsize = 1;
	readformat.rxsize = 4;
	readformat.cmd = CONT_READ;
	readformat.button = 0xffff;
	readformat.stick_x = (s8)0xff;
	readformat.stick_y = (s8)0xff;

	for(i=0; i < __osMaxControllers; i++) {
		/* setup read format for connected channel */

		*((__OSContReadFormat *)ptr) = readformat;
		ptr += sizeof(readformat);
	}
#ifndef _HW_VERSION_1
	*((u8 *)ptr) = FORMAT_END;
#endif
}

