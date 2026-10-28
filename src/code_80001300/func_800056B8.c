#include "common.h"

extern void func_80005A0C(void*, int, int, int, int, unsigned int, unsigned int, unsigned int, int);
typedef struct { float x,y; } Pair; typedef struct { int x,y; } IPair; typedef struct { int x,y,z; } Triple; extern IPair D_800B6B48; extern Pair D_800B6B50,D_800B6B58,D_800B6B60,D_800B6B68; extern Triple D_800B6B70;
void func_800056B8(void *object,int code,int profileIndex,int option) {
    IPair p60;
    /* Select the code variant from object flags, then forward its indexed parameters. */ Pair p58,p50,p48,p40; Triple p34; 
    p60=D_800B6B48;
    p58=D_800B6B50;
    p50=D_800B6B58;
    p48=D_800B6B60;
    p40=D_800B6B68;
    p34=D_800B6B70;
    switch(code) {
    case 0xBB6: if(*(unsigned int*)((char*)object+0x18CC4)&2) code=0xBB5; break;
    case 0x1387: if(*(unsigned int*)((char*)object+0x18CC4)&0x400) code=0x1386; break;
    case 0x2325: if(*(unsigned int*)((char*)object+0x18CC4)&0x4000) code=0x2326; break;
    case 0x2327: if(*(unsigned int*)((char*)object+0x18CC4)&0x20000) code=0x2327; break;
    }
    func_80005A0C(object,code,((int*)&p60)[profileIndex],(int)((float*)&p58)[profileIndex],((int*)&p34)[profileIndex],(unsigned int)((float*)&p50)[profileIndex],(unsigned int)((float*)&p48)[profileIndex],(unsigned int)((float*)&p40)[profileIndex],option);
}
