#include "decompdecomp_sync_88507c151ce89be81e21.h"
#line 1 "func.c"
#line 1 "reference.c"
Acmd *_saveBuffer(ALFx *r, s16 *curr_ptr, s32 buff, s32 count, Acmd *p)
{
    Acmd	*ptr = p;
    s32		after_end, before_end;
    s16 	*updated_ptr, *delay_end;

                  
                                        
      

    delay_end = &r->base[r->length];
    if (curr_ptr < r->base)
	curr_ptr += r->length;
    updated_ptr = curr_ptr + count;

    if (updated_ptr > delay_end) {
	after_end = updated_ptr - delay_end;
	before_end = delay_end - curr_ptr;

	aSetBuffer(ptr++, 0, 0, buff, before_end<<1);
	aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
	aSetBuffer(ptr++, 0, 0, buff+(before_end<<1), after_end<<1);
	aSaveBuffer(ptr++, osVirtualToPhysical(r->base));
	aSetBuffer(ptr++, 0, 0, 0, count<<1);
    } else {
	aSetBuffer(ptr++, 0, 0, buff, count<<1);
	aSaveBuffer(ptr++, osVirtualToPhysical(curr_ptr));
    }

                  
                                                        
      
    return ptr;

}

