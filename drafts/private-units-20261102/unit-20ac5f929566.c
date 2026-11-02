static s32 func_800B0F18(ALSeq *); static u8 func_800B0F10(ALSeq *);static s16 func_800B13E8(ALSeq *);static s32 func_800B1398(ALSeq *);
#define IFF_FILE_HDR 0x4d546864
#define IFF_TRACK_HDR 0x4d54726b
void alSeqNew(ALSeq *seq, u8 *ptr, s32 len)
{
    /*
     * load the seqence pointed to by ptr
     */
    seq->base           = ptr;
    seq->len            = len;
    seq->lastStatus     = 0;
    seq->lastTicks      = 0;
    seq->curPtr         = ptr;
    
    if (func_800B1398(seq) != IFF_FILE_HDR) {
             
                                            
              
        return;
    }

    func_800B1398(seq);        /* skip the length field */

    if (func_800B13E8(seq) != 0) {
                     
                                             
              
        return;
    }

    if (func_800B13E8(seq) != 1) {
                     
                                              
              
        return;
    }

    seq->division = func_800B13E8(seq);
    if (seq->division & 0x8000) {
                     
                                         
              
        return;
    }
    
    seq->qnpt = 1.0/(f32)seq->division;

    if (func_800B1398(seq) != IFF_TRACK_HDR) {
                     
                                             
              
        return;
    }

    func_800B1398(seq);                /* skip the length field */

    seq->trackStart = seq->curPtr;
}

static s16 func_800B13E8(ALSeq *seq)
{
    s16 tmp;

    tmp  = *seq->curPtr++ << 8;
    tmp |= *seq->curPtr++;
    
    return tmp;
}

static s32 func_800B1398(ALSeq *seq)
{
    s32 tmp;

    tmp  = *seq->curPtr++ << 24;
    tmp |= *seq->curPtr++ << 16;
    tmp |= *seq->curPtr++ <<  8;
    tmp |= *seq->curPtr++;

    return tmp;
}

