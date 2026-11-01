#include "decompdecomp_sync_dee1aecaad6129c53e84.h"
#line 1 "func.c"
#line 17 "reference.c"
void
func_8009F22C(u8 *pattern, OSContStatus *data)
{
	u8 			*ptr;
	__OSContRequesFormat 	requestformat;
	int 			i;
	u8			bits = 0;


	ptr = (u8 *)(&__osContPifRam);

        for (i = 0; i < __osMaxControllers; i++, 
		ptr += sizeof(requestformat), data++) {

                /* read request format for all the channel */

                requestformat = *((__OSContRequesFormat *)ptr);
                     
                data->errno = (u8)((requestformat.rxsize & CON_ERR_MASK) >> 4);
     
                                                                               
                                                                
      
                if (data->errno)
                        continue;
                data->type =(u16)((requestformat.typel<<8)|requestformat.typeh);
                data->status = requestformat.status;
                bits |= (1<<i);
        }
        *pattern = bits;
}

