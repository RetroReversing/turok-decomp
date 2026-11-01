#include "decompdecomp_sync_39a0d4f85f2596dbb92e.h"
#line 1 "func.c"
#line 931 "reference.c"
OSPiHandle *
func_800AFE00(void)
{
	u32 saveMask;

	/* Fill basic information */

	LeoDiskHandle.type = DEVICE_TYPE_64DD;
	LeoDiskHandle.baseAddress = PHYS_TO_K1(PI_DOM2_ADDR1);

	/* Get Domain parameters */

	LeoDiskHandle.latency = (u8)0x00000003;
	LeoDiskHandle.pulse = (u8)0x00000006;
	LeoDiskHandle.pageSize = (u8)0x00000006;
	LeoDiskHandle.relDuration = (u8)0x00000002;
	

	/* set up domain2 */

	IO_WRITE(PI_BSD_DOM2_LAT_REG, LeoDiskHandle.latency);
	IO_WRITE(PI_BSD_DOM2_PWD_REG, LeoDiskHandle.pulse);
	IO_WRITE(PI_BSD_DOM2_PGS_REG, LeoDiskHandle.pageSize);
	IO_WRITE(PI_BSD_DOM2_RLS_REG, LeoDiskHandle.relDuration);

	/* TODO LeoDiskHandle.speed = */

	bzero(&(LeoDiskHandle.transferInfo),
			sizeof(LeoDiskHandle.transferInfo));

	/* 
	 * Put the LeoDiskHandle onto PiTable
	 */

	saveMask = __osDisableInt();

	LeoDiskHandle.next = __osPiTable;
	__osPiTable = &LeoDiskHandle;
	__osDiskHandle = &LeoDiskHandle;

	__osRestoreInt(saveMask);


    	return(&LeoDiskHandle);

}
