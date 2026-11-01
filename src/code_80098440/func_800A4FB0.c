#include "decompdecomp_sync_941ad0b0df6da4cdb7d6.h"
#line 1 "func.c"
#line 27 "reference.c"
s32
func_800A4FB0(void *bufPtr, u32 size)
{
    
    void *bPtr;
             
                                                               
                            
                                                  
            
     
                     
                                                
            
     
      

    /*  audio hardware bug: if end of buffer is at address bXX10 0000 0000 0000. */
    /*  then the next frame's addr will have 0x2000 added to it */
    bPtr = bufPtr;
    if(D_800EF270) /* last frame caused problems */
	bPtr = (void*)((u32)bufPtr - 0x2000);
    if ((((u32)bufPtr + size) & 0x3fff) == 0x2000)
	D_800EF270 = 1; /* this frame causes problem */
    else
	D_800EF270 = 0; /* this frame is harmless */

    if (func_800AD680())
        return(-1);

    /* Need to write address first and length second */
    IO_WRITE(AI_DRAM_ADDR_REG, osVirtualToPhysical(bPtr));
    IO_WRITE(AI_LEN_REG, size);

    return(0);

}
