#include "decompdecomp_sync_dc9a7801c8a87a99fa9c.h"
#line 1 "func.c"
#line 2 "reference.c"
s32 _allocatePVoice(ALSynth *drvr, PVoice **pvoice, s16 priority)
{
    ALLink      *dl;
    PVoice      *pv;
    s32         stolen = 0;
    
    if ((dl = drvr->pLameList.next) != 0) { /* check the lame list first */
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);        
    } else if ((dl = drvr->pFreeList.next) != 0) { /* from the free list */
        *pvoice = (PVoice *) dl;
        alUnlink(dl);
        alLink(dl, &drvr->pAllocList);        
    } else { /* steal one */
        for (dl = drvr->pAllocList.next; dl != 0; dl = dl->next) {
            pv = (PVoice *)dl;

            /*
             * if it is lower priority and not already stolen, keep it
             * as a candidate for stealing
             */
            if ((pv->vvoice->priority <= priority) && (pv->offset == 0)) {
                *pvoice = pv;
                priority = pv->vvoice->priority;
                stolen = 1;
            }
        }
    }
    
    return stolen;
}

