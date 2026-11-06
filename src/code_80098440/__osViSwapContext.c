#include "decompdecomp_sync_03f15a71206faf055c35.h"
#line 1 "func.c"
#line 85 "reference.c"
void
__osViSwapContext(void)
{

    register OSViMode 		*vm;
    register __OSViContext	*vc;
    u32				origin;
    u32				hStart;
    u32				nomValue;
    u32				field = 0;

    /* 
     * In this routine, we don't bother to get the access token because we
     * assume that the user MUST complete the buffer swapping and mode setting 
     * by this time; otherwise, it's an error and garbage could be displayed on
     * the screen. We can but decide not to re-use the current context since
     * we want to let user know that we are experiencing graphics overrun.
     */

    vc = __osViNext;		/* We'll use the next VI context */
    vm = vc->modep;		/* Get pointer to the mode structure */

               
    /*
     * Here, we reset vIntr field to 2 (in vitbl.c) to get the retrace 
     * interrupt right after vertical sync and in the correct field
     */
    field = IO_READ(VI_CURRENT_REG) & 0x01;	/* Get current field */

    /* Calculate the actual origin of the frame buffer */
    origin = osVirtualToPhysical(vc->framep) + vm->fldRegs[field].origin;
      

    /* Calculate the X-scale (if any) and adjust the origin accordingly */
    if (vc->state & VI_STATE_X_SCALE) {
        vc->x.scale |= (vm->comRegs.xScale & 0xFFFFF000);
    }
    else {
        vc->x.scale = vm->comRegs.xScale;
    }

    /* Calculate the Y-scale (if any) */
    if (vc->state & VI_STATE_Y_SCALE) {
        nomValue = vm->fldRegs[field].yScale & 0x0FFF;
        vc->y.scale = (u32)(vc->y.factor * (f32)nomValue);
        vc->y.scale |= (vm->fldRegs[field].yScale & 0xFFFFF000);
    }
    else {
        vc->y.scale = vm->fldRegs[field].yScale;
    }

    hStart = vm->comRegs.hStart;

    /* Calculate the horizontal start (if black screen) */
    if (vc->state & VI_STATE_BLACK) {
        hStart = 0;
    }

    /* Repeat a line for the frame */
    if (vc->state & VI_STATE_REPEAT_LINE) {
        vc->y.scale = 0;
        origin = osVirtualToPhysical(vc->framep);
    }

    /* Fade between first 2 scan lines for the frame */
    if (vc->state & VI_STATE_FADE) {
        vc->y.scale = (u32)((vc->y.offset << 16) & 0x03FF0000);
        origin = osVirtualToPhysical(vc->framep);
    }

               
    /* Update the hardware registers */
    IO_WRITE(VI_ORIGIN_REG,	origin);

    IO_WRITE(VI_WIDTH_REG,	vm->comRegs.width);
    IO_WRITE(VI_BURST_REG,	vm->comRegs.burst);
    IO_WRITE(VI_V_SYNC_REG,	vm->comRegs.vSync);
    IO_WRITE(VI_H_SYNC_REG,	vm->comRegs.hSync);
    IO_WRITE(VI_LEAP_REG,	vm->comRegs.leap);

    IO_WRITE(VI_H_START_REG,	hStart);
    IO_WRITE(VI_V_START_REG,	vm->fldRegs[field].vStart);
    IO_WRITE(VI_V_BURST_REG,	vm->fldRegs[field].vBurst);
    IO_WRITE(VI_V_INTR_REG,	vm->fldRegs[field].vIntr);
    IO_WRITE(VI_X_SCALE_REG,	vc->x.scale);
    IO_WRITE(VI_Y_SCALE_REG,	vc->y.scale);
    IO_WRITE(VI_CONTROL_REG,	vc->control);	/* value set in osViSetMode */
      

    /*
     * Since this function is called by the VI manager thread (which runs
     * at a very high priority), we don't need to protect the 2 global VI
     * structures (i.e., __osViNext and __osViCurr).
     */
    /* 
     * Switch the two VI context "Next" and "Current" pointers
     */
    __osViNext = __osViCurr;
    __osViCurr = vc;

    /* 
     * Reset "Next" context to have same values as "Current" context at the 
     * beginning
     */
    *__osViNext = *__osViCurr;

}
