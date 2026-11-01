#include "decompdecomp_sync_3085aca9193c7a1fa598.h"
#line 1 "func.c"
#line 1771 "reference.c"
ALSound *__lookupSoundQuick(ALSeqPlayer *seqp, u8 key, u8 vel, u8 chan)
{
    ALInstrument *inst = seqp->chanState[chan].instrument;
    s32 l = 1;
    s32 r = inst->soundCount;
    s32 i;
    ALKeyMap *keymap;

    assert(inst != NULL);       /* sct 10/31/95 - If inst is NULL, then the seqp probably wasn't setup correctly. */
    
    while (r >= l) {
        i = (l+r)/2;

        keymap = inst->soundArray[i-1]->keyMap;

        if ((key >= keymap->keyMin) && (key <= keymap->keyMax) &&
            (vel >= keymap->velocityMin) && (vel <= keymap->velocityMax)) {
            return inst->soundArray[i-1];
        } else if ((key < keymap->keyMin) ||
                   ((vel < keymap->velocityMin) && (key <= keymap->keyMax))) {
            r = i - 1;
        } else {
            l = i + 1;
        }
    }
    
    return 0;
}

