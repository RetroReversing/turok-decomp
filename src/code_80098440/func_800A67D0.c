#include "decompdecomp_sync_34f37a459dd79299ba88.h"
#line 1 "func.c"
#line 940 "reference.c"
s32
func_800A67D0(void)
{
	volatile u32 stat;
	volatile u32 pi_stat;
	u32	bm_stat;
	__OSTranxInfo *info;
	__OSBlockInfo *blockInfo;

	if (osDiskExist == 0)
		return(0);

	info = &(__osDiskHandle->transferInfo);
	blockInfo = &(info->block[info->blockNum]);

	pi_stat = IO_READ(PI_STATUS_REG);

	/* TODO check for DMAing  PI is not disk */


 if (pi_stat & PI_STATUS_DMA_BUSY) {
  IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR | PI_STATUS_RESET);
  PIWait();
  stat=IO_READ(ASIC_STATUS);
  if(stat & LEO_STAT_MECHA_INT) {
   PIWait();
   IO_WRITE(ASIC_BM_CTL,info->bmCtlShadow|BM_MECHA_INT_RESET);
  }
  LeoAbort(LEO_SENSE_DATA_PHASE_ERROR);
 }

	PIWait();
	stat = IO_READ(ASIC_STATUS);
	if (stat & LEO_STAT_MECHA_INT) {

		/* mecha int */

		/* clear MECHA interrupt */
		PIWait();
		IO_WRITE(ASIC_BM_CTL,info->bmCtlShadow|BM_MECHA_INT_RESET);

		/* back to exceptasm, with send_mesg */
		blockInfo->errStatus = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
		return(0);
	}

	/* BM interrupt */

	if (stat & LEO_STAT_BM_ERROR) {

		/* BM stopped */

		blockInfo->errStatus = LEO_SENSE_WRITE_FAULT; 
		/* send message to PI */
		__osLeoResume();

		/* enable PI interrupt */

		IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
		__OSGlobalIntMask |= OS_IM_PI;
		return(1);

	}
		
	if (info->cmdType == OS_WRITE) {
		
		/* write operation */


		if ((stat & LEO_STAT_DATA_REQ) == 0) {


			if ((info->sectorNum + 1) != (s32)(USR_SECS_PER_BLK * 
						(s32)(info->transferMode))) {
				/* index error */

				LeoAbort(LEO_SENSE_NO_REFERENCE_POSITION_FOUND);
			}

			/* write operation is done */

			/* enable PI interrupt */

			IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
			__OSGlobalIntMask |= OS_IM_PI;

			blockInfo->errStatus = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
			__osLeoResume();
			return(1);
		} else {

			/* DMA Write one sector */

			/* update tranxInfo */
			blockInfo->dramAddr = (void *)
			((u32)blockInfo->dramAddr + blockInfo->sectorSize);
			info->sectorNum++;

			osEPiRawStartDma(__osDiskHandle, OS_WRITE, 
				ASIC_SECTOR_BUFF, blockInfo->dramAddr, 
				blockInfo->sectorSize);
			return(1);
		}
	} else if (info->cmdType == OS_READ) {
		if (info->transferMode == LEO_SECTOR_MODE){

			if (info->sectorNum > (s32)(blockInfo->C1ErrNum
				 + (USR_SECS_PER_BLK/5) )) {
				
				/* done with sector read */

				LeoAbort(LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION);
			}
			if ((stat & LEO_STAT_DATA_REQ) == 0) {
				LeoAbort(LEO_SENSE_UNRECOVERED_READ_ERROR);
			}
		} else {
			blockInfo->dramAddr = (void *)
		((u32)blockInfo->dramAddr + blockInfo->sectorSize);
		}

		bm_stat = IO_READ(ASIC_BM_STATUS);
	
		/* check BM status register */

		if (((bm_stat & LEO_BMST_C1_SINGLE) && 
			(bm_stat & LEO_BMST_C1_DOUBLE)) ||
			(bm_stat & LEO_BMST_MICRO_STATUS)) {

			/* C1 ERROR */

			if (blockInfo->C1ErrNum >= C1_ERROR_LIMIT) {
				if ((info->transferMode != LEO_SECTOR_MODE) ||
				    (info->sectorNum >= (USR_SECS_PER_BLK-2))){

					/* block mode or last user sector */

					LeoAbort(LEO_SENSE_UNRECOVERED_READ_ERROR);
				}
			} else {
				
				/* store err position */

				int errNum = (int)(blockInfo->C1ErrNum);
				blockInfo->C1ErrSector[errNum] =
				(u32)(info->sectorNum + 1);
			}
			blockInfo->C1ErrNum++;
		}

		/* check index error */

		if (stat & LEO_STAT_C2_XFER) {
			if ((info->sectorNum + 1) != 
				(USR_SECS_PER_BLK+C2_SECS_PER_BLK - 1)) {

				/* index not found */

				blockInfo->errStatus = LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
				__osLeoAbnormalResume();
			}

			/* end of read block */

			/* The message will be sent at sector 0 for block1 */

			if ((info->transferMode == LEO_TRACK_MODE) && 
				(info->blockNum == 0)) {

				/* renew  parameters for block1 */

				info->blockNum = 1;
				info->sectorNum = -1;
				info->block[1].dramAddr = (void *)
		((u32)info->block[1].dramAddr - info->block[1].sectorSize);
			} else {
				/* enable PI interrupt */

				IO_WRITE(PI_STATUS_REG, PI_STATUS_CLR_INTR);
				__OSGlobalIntMask |= OS_IM_PI;
			}


			/* read C2 Syndrome */

			osEPiRawStartDma(__osDiskHandle, OS_READ, 
				ASIC_C2_BUFF, blockInfo->C2Addr, 
				blockInfo->sectorSize * C2_SECS_PER_BLK);

			/* return back to exceptasm, no send_mesg */
			blockInfo->errStatus = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
			return(1);
		}

		/* 
		 * C1ErrNum is 0, but C2 Data is not 0.
		 * Note: At sector 0, we check index error for 
		 * previous block.
		 */

		if ((info->sectorNum == -1) && 
			(info->transferMode == LEO_TRACK_MODE) && 
			(info->blockNum == 1)) {

			__OSBlockInfo *bptr;

			bptr = &(info->block[0]);
			if (bptr->C1ErrNum == 0){
				if (*(int *)(bptr->C2Addr) | 
				    *(int *)((int *)(bptr->C2Addr) + 1) |
				    *(int *)((int *)(bptr->C2Addr) + 2) | 
				    *(int *)((int *)(bptr->C2Addr) + 3)) {
				        blockInfo->errStatus = LEO_SENSE_NO_REFERENCE_POSITION_FOUND;
					__osLeoAbnormalResume();
					return(1);
				}
			}
			
			/* send message to indicate block0 is done */
			
			blockInfo->errStatus = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
			__osLeoResume();	/* continue */
		}

		info->sectorNum++;
		if ((stat & LEO_STAT_DATA_REQ) != 0) {

			/* update tranxInfo */
			if (info->sectorNum >= USR_SECS_PER_BLK){
				LeoAbort(LEO_SENSE_NO_REFERENCE_POSITION_FOUND);
			}
				



			/* DMA Read one sector */

			osEPiRawStartDma(__osDiskHandle, OS_READ, 
				ASIC_SECTOR_BUFF, blockInfo->dramAddr, 
				blockInfo->sectorSize);

			/* return back to exceptasm, no send_mesg */
			blockInfo->errStatus = LEO_SENSE_NO_ADDITIONAL_SENSE_INFOMATION;
			return(1);
		}
		else if (info->sectorNum < USR_SECS_PER_BLK){
			LeoAbort(LEO_SENSE_NO_REFERENCE_POSITION_FOUND);
		}
		return(1);

	} else {

		/* Extra INT1 */

		LeoAbort(LEO_SENSE_DATA_PHASE_ERROR);
	}
}

