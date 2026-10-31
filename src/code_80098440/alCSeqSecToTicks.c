#include "common.h"

typedef struct {u8 pad[0x40];u32 division;} SeqFile;
typedef struct {SeqFile *base;} Seq;
u32 alCSeqSecToTicks(Seq *seq,f32 sec,u32 tempo)
{
 return (u32)(((sec * 1000000.0) * seq->base->division) / tempo);
}
