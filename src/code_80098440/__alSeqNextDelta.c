#include "decompdecomp_sync_497bbe7ab0850f4faf27.h"
#line 1 "func.c"
static s32 func_800B0F18(ALSeq *); static u8 func_800B0F10(ALSeq *);static s16 func_800B13E8(ALSeq *);static s32 func_800B1398(ALSeq *);
#define IFF_FILE_HDR 0x4d546864
#define IFF_TRACK_HDR 0x4d54726b
void alSeqNextEvent(ALSeq *seq, ALEvent *event)
{
    u8          status;
    s16         delta;
    s32         len;
    s32         deltaTicks;
    s32         i;

             
                                                                     
                                            
                                
      
    
    deltaTicks = func_800B0F18(seq);   /* read the delta time */
    seq->lastTicks += deltaTicks;
    status = func_800B0F10(seq);
    
          
      
                                                                      
                     
       
                                               
                                     
                              
                                   
                       
         
                                  
               
     
      
    
    if (status == AL_MIDI_Meta) {
        u8 type = func_800B0F10(seq);
        
        if (type == AL_MIDI_META_TEMPO) {
            event->type = AL_TEMPO_EVT;
            event->msg.tempo.ticks = deltaTicks;
            event->msg.tempo.status = status;
            event->msg.tempo.type = type;
            event->msg.tempo.len  = func_800B0F10(seq);
            event->msg.tempo.byte1 = func_800B0F10(seq);
            event->msg.tempo.byte2 = func_800B0F10(seq);
            event->msg.tempo.byte3 = func_800B0F10(seq);
        } else if (type == AL_MIDI_META_EOT) {
            event->type = AL_SEQ_END_EVT;
            event->msg.end.ticks  = deltaTicks;
            event->msg.end.status = status;
            event->msg.end.type   = type;
            event->msg.end.len    = func_800B0F10(seq);
        } else {
             
                                              
                                  
                                       
                           
             
                                      
                   
                  
        }

        seq->lastStatus = 0;
        
    } else {
        event->type = AL_SEQ_MIDI_EVT;
        event->msg.midi.ticks = deltaTicks;
        if (status & 0x80) {
            event->msg.midi.status = status;
            event->msg.midi.byte1 = func_800B0F10(seq);
            seq->lastStatus = status;
        } else {
            /* running status */
            event->msg.midi.status = seq->lastStatus;
            event->msg.midi.byte1 = status;
        }
        
        if (((event->msg.midi.status & 0xf0) != AL_MIDI_ProgramChange) &&
            ((event->msg.midi.status & 0xf0) != AL_MIDI_ChannelPressure)) {
            event->msg.midi.byte2 = func_800B0F10(seq);
        } else {
            event->msg.midi.byte2 = 0;
        }
    }
}

char __alSeqNextDelta (ALSeq *seq, s32 *pDeltaTicks)
{
  u8 *	savedPtr;

  /* sct 1/16/96 - Put in safety check here to make sure we don't read past sequence data. */
  if (seq->curPtr >= seq->base + seq->len)
      return FALSE;

  savedPtr = seq->curPtr;
  *pDeltaTicks = func_800B0F18(seq);   /* read the delta time */
  seq->curPtr = savedPtr;

  return TRUE;
}
static u8 func_800B0F10(ALSeq *seq)
{
    return *seq->curPtr++;
}

static s32 func_800B0F18(ALSeq *seq)
{
    s32 value;
    s32 c;

    c = *seq->curPtr++;
    value = c;
    if ( c & 0x80 ) {
        value &= 0x7f;
        do {
            c = *seq->curPtr++;
            value = (value << 7) + (c & 0x7f);
        } while (c & 0x80);
    }
    return (value);
}


