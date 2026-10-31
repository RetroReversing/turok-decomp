#include "decompdecomp_sync_298e88a300f0afd6412f.h"
#line 1 "func.c"
#line 70 "reference.c"
void
__osPfsRequestData(u8 cmd)
{
	u8 			*ptr;
	__OSContRequesFormat 	requestformat;
	int 			i;

	__osContLastCmd = cmd;

	/* clear pif ram */

	for (i = 0; i < PIFRAMSIZE ; i++)
		__osPfsPifRam.ramarray[i] = 0;
	__osPfsPifRam.pifstatus = CONT_FORMAT;

	ptr = (u8 *)(&__osPfsPifRam);

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

