#include "decompdecomp_sync_90dd40fdfecb69e91017.h"
#line 1 "func.c"
#line 25 "reference.c"
s32
func_800A72A0(s32 direction, u32 devAddr, void *dramAddr, u32 size)
{
    register u32 stat;

             
                                   
                                                            
                                                  
            
     

                                       
                        
                                                    
            
     

                                         
                              
                                                  
            
     

                                            
                     
                                              
            
     

                                                      
                                                 
                                               
            
     
      

    stat = IO_READ(PI_STATUS_REG);
    while (stat & (PI_STATUS_IO_BUSY | PI_STATUS_DMA_BUSY)) {
        stat = IO_READ(PI_STATUS_REG);
    } 

    IO_WRITE(PI_DRAM_ADDR_REG, osVirtualToPhysical(dramAddr));
    IO_WRITE(PI_CART_ADDR_REG, K1_TO_PHYS((u32)osRomBase | devAddr));

    /* Note that actual programmed size of transfer = size - 1 */
    switch (direction) {
        case OS_READ: {				/* PI -> RDRAM */
            IO_WRITE(PI_WR_LEN_REG, size-1);
            break;
        }
        case OS_WRITE: {			/* PI <- RDRAM */
            IO_WRITE(PI_RD_LEN_REG, size-1);
            break;
        }
        default: {
            return(-1);
        }
    }

    return(0);

}
