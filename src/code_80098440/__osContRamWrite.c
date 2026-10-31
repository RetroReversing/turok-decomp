#include "decompdecomp_sync_f42677841a62f7392683.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
__osContRamWrite(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, 
	         int force)
{
	s32	ret = 0;
	int i;
	u8 			*ptr = (u8 *)(&__osPfsPifRam);
	__OSContRamReadFormat 	ramreadformat;
	int retry = 2;

	if ((force != PFS_FORCE) && (address < PFS_LABEL_AREA) 
			&& (address != 0)){
		/* protect id area */
		return(0);
	}

	/* Block to get resource token */
	__osSiGetAccess();

	__osContLastCmd = CONT_RAM_WRITE;

	/* Set up request command format for all channels */

	__osPackRamWriteData(channel, address, buffer);
	ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
	(void)osRecvMesg(mq, (OSMesg *)NULL, OS_MESG_BLOCK);

	do { 	/* Retry if ADRS/DATA CRC error */
		/* trigger pifmacro */

		for (i = 0; i < PIFRAMSIZE ; i++)
			__osPfsPifRam.ramarray[i] = 0xff;
		__osPfsPifRam.pifstatus = 0;
		ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);

		(void)osRecvMesg(mq, (OSMesg *)NULL, OS_MESG_BLOCK);
		ptr = (u8 *)(&__osPfsPifRam);
		if (channel)
			for (i = 0; i < channel; i++)
				ptr++;

		ramreadformat = *((__OSContRamReadFormat *)ptr);
		ret = (s32)((ramreadformat.rxsize & CON_ERR_MASK) >> 4);
		if (ret == 0) {

			/* check data CRC */

			if (__osContDataCrc(buffer)!=ramreadformat.datacrc){

				/* reset status */

				if ((ret = __osPfsGetStatus(mq, channel)) != 0){
					__osSiRelAccess();
					return(ret);
				}
				ret = PFS_ERR_CONTRFAIL;
			}

		}
	} while ((ret == PFS_ERR_CONTRFAIL) && (retry-- >= 0));
	__osSiRelAccess();
	return(ret);
}

