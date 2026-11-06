#include "common.h"

void osSendMesg(u8 *,s32,s32);
void scSendCommand(u8*a,s32 b){osSendMesg(a+0x78,b,1);osSendMesg(a+0x40,6,1);}
