#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern u8 D_80137C41; extern u8 D_80137C90[];
typedef struct {u8 data[8];} Row;
void func_8009F22C(u8 *arg0,u8 *arg1){
volatile s32 i=0; volatile u8 mask=0; Row row; Row * volatile p=(Row*)D_80137C90;
if(D_80137C41>0)do{
row=*p;
((volatile u8*)arg1)[3]=(row.data[2]&0xc0)>>4;
if(((volatile u8*)arg1)[3]==0){*(u16*)arg1=((u8*)&row)[5]<<8|((u8*)&row)[4];arg1[2]=((u8*)&row)[6];mask|=1<<i;}
i++;p++;arg1+=4;
}while(i<D_80137C41);
*arg0=mask;
}
