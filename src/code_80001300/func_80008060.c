#include "source_func_80008060.h"

#line 1 "reference.c"
void func_80008060(CEngineApp *pThis, CFrameData *pFData)
{
	OSScTask		*t;

	//rmonPrintf("pFData->m_DisplayListSize:%x\n", pFData->m_DisplayListSize);

	// build graphics task
	t = &pFData->m_Task;

	t->list.t.data_ptr			= (u64*) pFData->m_pDisplayList;		// task data pointer (fill in later)
	t->list.t.data_size			= pFData->m_DisplayListSize;			// task data size
	t->list.t.type					= M_GFXTASK;								// task type
	t->list.t.flags				= 0;											// task flags
	t->list.t.ucode_boot			= (u64*) D_800B2380;				// boot ucode pointer
	t->list.t.ucode_boot_size	= ((s32) RO_800B2450 - (s32) D_800B2380); // boot ucode size
   t->list.t.ucode_size      	= SP_UCODE_SIZE;							// task ucode size
   t->list.t.ucode_data_size 	= SP_UCODE_DATA_SIZE;					// task ucode data size
   t->list.t.dram_stack      	= D_8013A1E0;								// task dram stack pointer
   t->list.t.dram_stack_size	= SP_DRAM_STACK_SIZE8;					// task dram stack size
	t->list.t.yield_data_ptr	= (u64*) D_80130170;					// task yield buffer ptr
	t->list.t.yield_data_size	= OS_YIELD_DATA_SIZE;					// task yield buffer size
#ifdef USE_FIFO
	switch (D_800B6AFC)
	{
		case MICROCODE_HIGH_PRECISION:
			t->list.t.ucode				= (u64*) D_800B3840;	// task ucode pointer
			t->list.t.ucode_data			= (u64*) D_800F7E10;	// task ucode data pointer
			break;

		case MICROCODE_LOW_PRECISION:
			t->list.t.ucode				= (u64*) D_800B2450;	// task ucode pointer
			t->list.t.ucode_data			= (u64*) D_800F7610;	// task ucode data pointer
			break;

		default:
			ASSERT(FALSE);
			break;
	}

	t->list.t.output_buff     	= D_801E0000;								// task output buffer ptr (not always used)
	t->list.t.output_buff_size	= (u64*) ((int)D_801E0000 + (int)FIFO_SIZE);	// task output buffer size ptr
#else
	t->list.t.ucode				= (u64*) gspF3DEX_NoNTextStart;			// task ucode pointer
	t->list.t.ucode_data			= (u64*) gspF3DEX_NoNDataStart;			// task ucode data pointer
	t->list.t.output_buff		= NULL;										// task output buffer ptr (not always used)
	t->list.t.output_buff_size = 0;											// task output buffer size ptr
#endif

	t->next			= 0;									// next task (none)

	t->msgQ			= &D_800F9C20;					// reply to when finished
	t->msg			= (OSMesg) &pFData->m_Msg;     // reply with this message

	t->framebuffer = (void*) pFData->m_pFrameBuffer;

	if (pFData->m_DrawMap)
		t->flags			= OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP;
	else
		t->flags			= OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_LAST_TASK;

	if (pFData->m_DrawMap)
	{
		// set up line draw task
		t = &pFData->m_LineTask;

		t->list.t.data_ptr			= (u64*) pFData->m_pLineList;		// task data pointer (fill in later)
		t->list.t.data_size			= pFData->m_LineListSize;			// task data size
		t->list.t.type					= M_GFXTASK;								// task type
		t->list.t.flags				= 0;											// task flags
		t->list.t.ucode_boot			= (u64*) D_800B2380;				// boot ucode pointer
		t->list.t.ucode_boot_size	= ((s32) RO_800B2450 - (s32) D_800B2380); // boot ucode size
		t->list.t.ucode_size      	= SP_UCODE_SIZE;							// task ucode size
		t->list.t.ucode_data_size 	= SP_UCODE_DATA_SIZE;					// task ucode data size
		t->list.t.dram_stack      	= D_8013A1E0;								// task dram stack pointer
		t->list.t.dram_stack_size	= SP_DRAM_STACK_SIZE8;					// task dram stack size
		t->list.t.yield_data_ptr	= (u64*) D_80130170;					// task yield buffer ptr
		t->list.t.yield_data_size	= OS_YIELD_DATA_SIZE;					// task yield buffer size
#ifdef USE_FIFO
		t->list.t.ucode				= (u64*) D_800B4C00;	// task ucode pointer
		t->list.t.ucode_data			= (u64*) D_800F8610;	// task ucode data pointer
		t->list.t.output_buff     	= D_801E0000;								// task output buffer ptr (not always used)
		t->list.t.output_buff_size	= (u64*) ((int)D_801E0000 + (int)FIFO_SIZE);	// task output buffer size ptr
#else
		t->list.t.ucode				= (u64*) gspLine3DTextStart;			// task ucode pointer
		t->list.t.ucode_data			= (u64*) gspLine3DDataStart;			// task ucode data pointer
		t->list.t.output_buff		= NULL;										// task output buffer ptr (not always used)
		t->list.t.output_buff_size = 0;											// task output buffer size ptr
#endif

		t->next			= 0;									// next task (none)
		t->flags			= OS_SC_NEEDS_RSP | OS_SC_NEEDS_RDP | OS_SC_LAST_TASK;

		t->msgQ			= &D_800F9C20;					// reply to when finished
		t->msg			= (OSMesg) &pFData->m_Msg;     // reply with this message

		t->framebuffer = (void*) pFData->m_pFrameBuffer;
	}

	// dump whole cache because of dynamic data
	func_8009D1F0();

	func_8002BB80(&D_800F95E0, &pFData->m_Task);

	if (pFData->m_DrawMap)
		func_8002BB80(&D_800F95E0, &pFData->m_LineTask);

	func_80006E0C(pThis);
}
