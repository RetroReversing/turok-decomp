#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

void osSendMesg(u8 *,s32,s32);
void scSendCommand(u8*sc,s32 pTask){osSendMesg(sc+0x78,pTask,1);osSendMesg(sc+0x40,6,1);}
