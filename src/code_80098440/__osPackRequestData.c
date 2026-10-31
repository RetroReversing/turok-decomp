#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void* OSMesg;
typedef struct{u32 a[6];}OSMesgQueue;
typedef struct{u32 a[8];}OSTimer;
typedef u64 OSTime;
typedef struct{u16 type;u8 status,errno;}OSContStatus;
typedef struct{u32 ramarray[15];u32 pifstatus;}OSPifRam;
typedef struct{u8 dummy,txsize,rxsize,cmd,typeh,typel,status,dummy1;}__OSContRequesFormat;
extern OSPifRam D_80137C00;extern u8 D_80137C40,D_80137C41;extern s32 D_800EF230;extern u64 D_800EE4D0;
extern OSMesgQueue D_80137C68;extern OSMesg D_80137C80;
u64 osGetTime(void);void osCreateMesgQueue(OSMesgQueue*,OSMesg*,s32);s32 osRecvMesg(OSMesgQueue*,OSMesg*,s32);
s32 osSetTimer(OSTimer*,u64,u64,OSMesgQueue*,OSMesg*);
s32 func_800A8590(s32,void*);void __osPackRequestData(u8);void func_8009EDC8(u8*,OSContStatus*);void func_800A84D0(void);
#define __osContPifRam D_80137C00
#define __osContLastCmd D_80137C40
#define __osMaxControllers D_80137C41
#define __osContinitialized D_800EF230
#define __osEepromTimerQ D_80137C68
#define __osEepromTimerMsg D_80137C80
#define __osSiRawStartDma func_800A8590
#define __osContGetInitData func_8009EDC8
#define __osSiCreateAccessQueue func_800A84D0
#define OS_USEC_TO_CYCLES(n) (((u64)(n)*D_800EE4D0)/1000000ULL)
#define MAXCONTROLLERS 4
#define CONT_REQUEST 0
#define OS_WRITE 1
#define OS_READ 0
#define OS_MESG_BLOCK 1
#define PIFRAMSIZE 16
#define CONT_FORMAT 1
#define FORMAT_END 0xfe
#line 110 "CONTROLLER.C"
void
__osPackRequestData(u8 cmd)
{
	u8 			*ptr;
	__OSContRequesFormat 	requestformat;
	int 			i;


	/* clear pif ram */

	for (i = 0; i < PIFRAMSIZE ; i++)
		__osContPifRam.ramarray[i] = 0;
	__osContPifRam.pifstatus = CONT_FORMAT;
 

	ptr = (u8 *)(&__osContPifRam);

	/* Setup request format for each channel */

	requestformat.dummy = 0xff;
	requestformat.txsize = 1;
	requestformat.rxsize = 3;
	requestformat.cmd = cmd;
	requestformat.typeh = 0xff;
	requestformat.typel = 0xff;
	requestformat.status = 0xff;
	requestformat.dummy1 = 0xff;

	for (i = 0; i < __osMaxControllers; i++) {

		/* setup request format for all the channel */

		*((__OSContRequesFormat *)ptr) = requestformat;
		ptr += sizeof(requestformat);
	}
	*((u8 *)ptr) = FORMAT_END;

}

