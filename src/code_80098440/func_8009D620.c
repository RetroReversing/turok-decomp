#include "decompdecomp_sync_afe3ade9227c5871be6a.h"
#line 1 "func.c"
#line 46 "reference.c"
void
func_8009D620(void)
{
	extern char D_8000031C[64];
	u32	pifdata;
	u32 	clock = 0;
	u32 data, stat;

	/*
	 * Turn on FS bit to flush denormalized  number to zero;
	 * enable "invalid operation" faulting to catch generation of NaNs.
	 */
                
	__osFinalrom = 1;
      
	__osSetSR(__osGetSR() | SR_CU1);
	__osSetFpcCsr(FPCSR_FS | FPCSR_EV);
	
                     
	/* send flag to PIF to enable NMI */

	while(__osSiRawReadIo(PIF_RAM_START+0x3c, &pifdata));
	while (__osSiRawWriteIo(PIF_RAM_START+0x3c, pifdata|8));
      

	*(__osExceptionVector *)UT_VEC =
		*(__osExceptionVector *)__osExceptionPreamble;
	*(__osExceptionVector *)XUT_VEC =
		*(__osExceptionVector *)__osExceptionPreamble;
	*(__osExceptionVector *)ECC_VEC =
		*(__osExceptionVector *)__osExceptionPreamble;
	*(__osExceptionVector *)E_VEC =
		*(__osExceptionVector *)__osExceptionPreamble;

	osWritebackDCache((void*)UT_VEC,
		      E_VEC - UT_VEC + sizeof(__osExceptionVector));
	osInvalICache((void*)UT_VEC,
		      E_VEC - UT_VEC + sizeof(__osExceptionVector));


	/* set TLB for the debug port */
	/* Global, 4K page, even-page only */
	osMapTLBRdb();
	/* *((vu32 *) RDB_WRITE_INTR_REG) = 0;
	*((vu32 *) RDB_READ_INTR_REG) = 0; */

	/* Get clock rate from rom hader */
	
	osPiRawReadIo((u32)RAMROM_CLOCKRATE_OFFSET, (u32 *)&clock);
	clock = clock & RAMROM_CLOCKRATE_MASK;
	if (clock)
		osClockRate = (u64) clock;

	osClockRate = func_8009D3C8(__ll_mul(osClockRate, 3), 4);

	/* zero out the NMI buffer if cold reset */
	if (osResetType == 0) {
	    bzero(D_8000031C, OS_APP_NMI_BUFSIZE);
	}

	/* set up Leo interrupt routine if disk exist */

	stat = IO_READ(PI_STATUS_REG);
	while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {
		stat = IO_READ(PI_STATUS_REG);
	}
	data = IO_READ(ASIC_STATUS);
	if ((data & 0xffff) == 0) {
		osDiskExist = 1;
		__osSetHWIntrRoutine((OSHWIntr)1, __osLeoInterrupt);
	} else
		osDiskExist = 0;
}

