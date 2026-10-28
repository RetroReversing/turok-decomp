#include "common.h"

extern void func_8003983C(void *, s32);
extern void func_80040228(s32, void *, f32, void *);
extern void func_8004826C(s32, s32);
extern void func_800479B4(void *, void *);
extern void func_8008A908(s32, s32);
extern u8 D_80109F10[];
extern u8 D_80112C18[];
extern s32 D_800F2AA8[];
extern s32 D_80119798;

void func_80049B68(s32 arg0, void *arg1) ;
                                       
                                         
                                            
                                      
                                     
 

s32 func_80049BE0(void *arg0, s32 arg1) ;
                                                                            
                
 

void func_80049544(s32 arg0, void *arg1) ;
                                          
                                                              
                                                                 
                                                                   
                                                             
 

void func_800479FC(void *arg0, void *arg1) {
    s32 a3 = *(s32 *)((u8 *)arg1 + 0x1F4);
    if (a3 != -1) {
        func_8008A908(a3, (s32)((u8 *)arg0 + 4));
        if (*(s16 *)((u8 *)arg1 + 0x1F8) == 0 || *(s16 *)((u8 *)arg0 + 0x1DC) <= 0) {
            func_800479B4(arg0, arg1);
            return;
        }
        if (D_80119798) *(s16 *)((u8 *)arg1 + 0x1F8) -= 0x1F40;
        else *(s16 *)((u8 *)arg1 + 0x1F8) -= 0x7D0;
        if (*(s16 *)((u8 *)arg1 + 0x1F8) < 0) *(s16 *)((u8 *)arg1 + 0x1F8) = 0;
    }
}
