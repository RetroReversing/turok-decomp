#include "decompdecomp_sync_298e88a300f0afd6412f.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
osPfsIsPlug(OSMesgQueue *queue, u8 *pattern)
{
	s32 ret = 0;
	OSMesg	dummy;
	u8 bitpattern;
	OSContStatus data[MAXCONTROLLERS];
	int channel;
	u8 bits = 0;
	int	crc_error_cnt = 3;

	/* Block to get resource token */
        __osSiGetAccess();

	do {
	  /* Set up request command format for all channels */

	  __osPfsRequestData(CONT_REQUEST);

	  ret = __osSiRawStartDma(OS_WRITE, &__osPfsPifRam);
	  (void)osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

	  /* trigger pifmacro */

	  ret = __osSiRawStartDma(OS_READ, &__osPfsPifRam);
	  (void)osRecvMesg(queue, &dummy, OS_MESG_BLOCK);

	  /* reformat the 64 bytes RAM data and save in data array */

	  __osPfsGetInitData(&bitpattern, &data[0]);

	  /* check crc error and loop if there is an error */

	  for (channel = 0; channel < __osMaxControllers; channel++) {
	    if ((data[channel].status & CONT_ADDR_CRC_ER) == 0) {
	      crc_error_cnt --;
	      break;
	    }
	  }
	  if (channel== __osMaxControllers) {
	    crc_error_cnt = 0;
	  }
	} while (crc_error_cnt > 0);

	/* loop through data array to check error bits */

	for (channel = 0; channel < __osMaxControllers; channel++) {
		if ((data[channel].errno == 0) && 
			((data[channel].status & CONT_CARD_ON) != 0))
				bits |= (1<<channel);
	}
	 __osSiRelAccess();

	*pattern = bits;
	return(ret);
}

