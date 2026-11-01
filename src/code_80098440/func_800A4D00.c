#include "decompdecomp_sync_75c80384b4ddb0d7235c.h"
#line 1 "func.c"
#line 23 "reference.c"
s32
func_800A4D00(u32 frequency)
{

    register unsigned int  dacRate;
    register unsigned char bitRate;
    register float f;    

    /* Based on frequency, find the corresponding values for DAC rate and 
     * BIT rate registers. Also, return the closest frequency to caller.
     */

             
                                                                  
                                    
                                                                             
                                       
                                                     
                       
  
     
                                          
                                                                               
                                       
                                                       
                       
  
     
                                      
                                                                               
                                       
                                                       
                       
  
     
      

    f = ((float)osViClock / (float)frequency) + 0.5F;  /* Rounding up */
    dacRate = (unsigned int)f;

    if (dacRate < AI_MIN_DAC_RATE)
        return(-1);

    /* if bitRate is 0, abus clock stops */
    bitRate = (unsigned char)(dacRate / 66);  

    if (bitRate > AI_MAX_BIT_RATE)
        bitRate = AI_MAX_BIT_RATE;

    IO_WRITE(AI_DACRATE_REG, dacRate-1);
    IO_WRITE(AI_BITRATE_REG, bitRate-1);
    IO_WRITE(AI_CONTROL_REG, AI_CONTROL_DMA_ON);

    /* Return the closest frequency */
    return((s32)((s32)osViClock/(s32)dacRate));  

}
