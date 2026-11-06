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
#line 62 "CONTREADDATA.C"
void
osContGetReadData(OSContPad *data)
{
	u8 			*ptr = (u8 *)(&__osContPifRam);
	__OSContReadFormat 	readformat;
	int 			i;

        for (i = 0; i < __osMaxControllers; i++, 
		ptr += sizeof(readformat), data++) {

                /* read read format for all the channel */

                readformat = *((__OSContReadFormat *)ptr);
#ifndef _HW_VERSION_1
                data->errno = (u8)((readformat.rxsize & CON_ERR_MASK) >> 4);
#else
                data->errno = (u8)(((readformat.txsize & CON_ERR_MASK) >> 4)
                | ((readformat.rxsize & CON_ERR_MASK) >> 6));
#endif
                if (data->errno)
                        continue;
                data->button = readformat.button;
                data->stick_x = readformat.stick_x;
                data->stick_y = readformat.stick_y;
        }
}

