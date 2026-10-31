#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct ALLink {struct ALLink *next,*prev;} ALLink;
typedef struct {s16 type;union {struct {void *voice;} note;u32 words[3];}msg;} ALEvent;
typedef struct {ALLink node;s32 delta;ALEvent evt;} ALEventListItem;
typedef struct {ALLink freeList,allocList;s32 eventCount;} ALEventQueue;
typedef struct {u8 pad[0x48];ALEventQueue evtq;} ALSeqPlayer;
typedef void ALVoice;
typedef s32 ALMicroTime;
void alUnlink(ALLink*);void alLink(ALLink*,ALLink*);
#define TRUE 1
#define FALSE 0
#define AL_NOTE_END_EVT 5
#define VOICENEEDSNOTEKILL_DEBUG 0
#line 1033 "seqplayer.c"
char __voiceNeedsNoteKill (ALSeqPlayer *seqp, ALVoice *voice, ALMicroTime killTime)
{
    ALLink              *thisNode;
    ALLink              *nextNode;
    ALEventListItem     *thisItem;
    ALMicroTime		itemTime = 0;
    char		needsNoteKill = TRUE;

#if VOICENEEDSNOTEKILL_DEBUG
    alEvtqPrintAllocEvts (&seqp->evtq);
#endif

    thisNode = seqp->evtq.allocList.next;
    while (thisNode != 0)
    {
	nextNode = thisNode->next;
	thisItem = (ALEventListItem *)thisNode;
	itemTime += thisItem->delta;

	if (thisItem->evt.type == AL_NOTE_END_EVT)
	{
	    if (thisItem->evt.msg.note.voice == voice)
	    {
		if (itemTime > killTime)
		{
		    if ((ALEventListItem *)nextNode)
			((ALEventListItem *)nextNode)->delta += thisItem->delta;
		    alUnlink(thisNode);
		    alLink(thisNode, &seqp->evtq.freeList);
		}
		else
		    needsNoteKill = FALSE;
		break;
	    }
	}
	thisNode = nextNode;
    }

#if VOICENEEDSNOTEKILL_DEBUG 
    if (thisNode)
	osSyncPrintf("vox 0x%0x: end time %d  kill time %d\n\n", voice, itemTime, killTime);
    else
	osSyncPrintf("vox 0x%0x: not found\n\n", voice);

    alEvtqPrintAllocEvts (&seqp->evtq);
#endif

   return needsNoteKill;
}

