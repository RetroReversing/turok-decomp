#include "decompdecomp_sync_3c69852d878aa52af323.h"
#line 1 "func.c"
#line 931 "reference.c"
       void
func_800A6EB4(void)
{
	__OSTranxInfo *info;
	volatile u32 pi_stat;


	info = &(__osDiskHandle->transferInfo);

	/* leoStop_sequencer */

	PIWait();
	IO_WRITE(ASIC_BM_CTL,info->bmCtlShadow|BM_RESET);
	PIWait();
	IO_WRITE(ASIC_BM_CTL,info->bmCtlShadow);

	/* send message to PI */
	__osLeoResume();

	/* enable PI interrupt */

	IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
	__OSGlobalIntMask |= OS_IM_PI;

}

