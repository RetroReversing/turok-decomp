#include "decompdecomp_sync_3c69852d878aa52af323.h"
#line 1 "func.c"
#line 931 "reference.c"
void
func_800A7460(void *arg)
{

    OSIoMesg		*mb;
    OSMesg		em, dummy;
    s32			ret;
    OSDevMgr		*dm;
    s32 		messageSend = 0;
	

    dm = (OSDevMgr *)arg;
    mb = NULL;
    ret = 0;
    while (1) {

	/* We assume that all messages in this queue are pointers to 
	 * I/O message blocks (OSIoMesg)
	 */
        (void)osRecvMesg(dm->cmdQueue, (OSMesg *)&mb, OS_MESG_BLOCK);

	if ((mb->piHandle != NULL) && 
			(mb->piHandle->type == DEVICE_TYPE_64DD) &&
			((mb->piHandle->transferInfo.cmdType == OS_READ) ||
			(mb->piHandle->transferInfo.cmdType == OS_WRITE))) {

		__OSBlockInfo *blockInfo;
		__OSTranxInfo *info;

		/* prepare for Disk Dma */
		info = &(mb->piHandle->transferInfo);
		blockInfo = &(info->block[info->blockNum]);
		info->sectorNum = -1;
		if (info->transferMode != LEO_SECTOR_MODE)
			blockInfo->dramAddr = (void *)
			   ((u32)blockInfo->dramAddr - blockInfo->sectorSize);
		if ((info->transferMode == LEO_TRACK_MODE) &&
		    (mb->piHandle->transferInfo.cmdType == OS_READ)){
			messageSend = 1;
		} else 
			messageSend = 0;
		
		/* Block to get resource token */
		(void)osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
		
		/* Leo Disk, turn off PI interrupt during DMA */

		__osResetGlobalIntMask(OS_IM_PI); 

		/* start sequencer */

		osEPiRawWriteIo(mb->piHandle, ASIC_BM_CTL, 
					(info->bmCtlShadow|START_BM));

readblock1:
	    	/* 
	     	* Listen on the Event Queue 
	     	*/
            	(void)osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);

            	/*
             	 * This signals an I/O completion (i.e., DMA request) from 
		 * device.  Device generates interrupt which is caught by 
		 * the exception  handler and sends us an event.
             	 */

		/*
		 * Handle disk over run case 
		 */

		/* Send I/O request message back to requestor */
            	osSendMesg(mb->hdr.retQueue, (OSMesg)mb, OS_MESG_NOBLOCK);
		if ((messageSend == 1)
			&& (mb->piHandle->transferInfo.block[0].errStatus == 0)) {

			messageSend = 0;

			goto readblock1;
	        }
                /* Return resource token */
                (void)osSendMesg(dm->acsQueue, (OSMesg)0, OS_MESG_NOBLOCK);
		
		/* 
	   	 * Yield the PI manager at the end of block1 DMA.
		 * So, command thread can issue seek command before
		 * PI manager serve next PI DMA.
		 */
		if (mb->piHandle->transferInfo.blockNum == 1)  
			osYieldThread();
	} else {

		switch (mb->hdr.type) {
		    case OS_MESG_TYPE_DMAREAD: {
			/* Block to get resource token */
			(void)osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
			ret = dm->dma(OS_READ, mb->devAddr, mb->dramAddr, 
			mb->size);
			break;
		    }
		    case OS_MESG_TYPE_DMAWRITE: {
			/* Block to get resource token */
			(void)osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
			ret = dm->dma(OS_WRITE, mb->devAddr, mb->dramAddr, 
			mb->size);
			break;
		    }
		    case OS_MESG_TYPE_EDMAREAD: {
			/* Block to get resource token */
			(void)osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
			ret = dm->edma(mb->piHandle, OS_READ, mb->devAddr, 
			mb->dramAddr, mb->size);
			break;
		    }
		    case OS_MESG_TYPE_EDMAWRITE: {
			/* Block to get resource token */
			(void)osRecvMesg(dm->acsQueue, &dummy, OS_MESG_BLOCK);
			ret = dm->edma(mb->piHandle, OS_WRITE, mb->devAddr, 
			mb->dramAddr, mb->size);
			break;
		    }
		    case OS_MESG_TYPE_LOOPBACK: {
			/* Special message type to loopback to caller */
			(void)osSendMesg(mb->hdr.retQueue, (OSMesg)mb, 
			OS_MESG_NOBLOCK);
			ret = -1;
			break;
		    }
		    default: {  /* NOT REACHED */
			ret = -1;
			break;
		    }
		}

		if (ret == 0) {
		    /* 
		     * Listen on the Event Queue 
		     */
		    (void)osRecvMesg(dm->evtQueue, &em, OS_MESG_BLOCK);

		    /*
		     * This signals an I/O completion (i.e., DMA request) 
		     * from device.  Device generates interrupt which 
		     * is caught by the exception handler and sends us 
		     * an event.
		     */

		    /* Send I/O request message back to requestor */
		    osSendMesg(mb->hdr.retQueue, (OSMesg)mb, 
			OS_MESG_NOBLOCK);

		    /* Return resource token */
		    (void)osSendMesg(dm->acsQueue, (OSMesg)0, OS_MESG_NOBLOCK);

		}  /* if */
	}
    }  /* while */

}
