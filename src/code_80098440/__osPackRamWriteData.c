#include "decompdecomp_sync_298e88a300f0afd6412f.h"
#line 1 "func.c"
#line 70 "reference.c"
       void
__osPackRamWriteData(int channel, u16 address, u8 *buffer)
{
	u8 			*ptr = (u8 *)(&__osPfsPifRam);
	__OSContRamReadFormat 	ramreadformat;
	int 			i;

	/* clear pif ram */

	for (i = 0; i < PIFRAMSIZE ; i++)
		__osPfsPifRam.ramarray[i] = 0;
	__osPfsPifRam.pifstatus = CONT_FORMAT;


	/* Setup ram read format */

	ramreadformat.dummy = 0xff;
        ramreadformat.txsize = 35;
        ramreadformat.rxsize = 1;
        ramreadformat.cmd = CONT_RAM_WRITE;
        ramreadformat.address = (u16)((address << 5) | __osContAddressCrc(address));
        ramreadformat.datacrc = 0xff;
        for (i = 0; i < BLOCKSIZE ; i++)
                ramreadformat.data[i] = *buffer++;

        /* setup ram read format */

	if (channel)
		for (i = 0; i < channel; i++)
			*ptr++ = 0;

        *((__OSContRamReadFormat *)ptr) = ramreadformat;

	ptr += sizeof(ramreadformat);
	*((u8 *)ptr) = FORMAT_END;
}

