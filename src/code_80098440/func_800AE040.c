#include "common.h"

typedef struct { s32 x,y; } Pair;
typedef struct { s32 x,y,z; } Triple;
typedef struct Config { s32 id,count; u8 mode; char pad[3]; Triple *triple; Pair *pair; } Config;
typedef struct Obj { char p0[4]; void *fn; char p8[0x10]; s32 ptr; s32 x,y,z; Config *cfg; s32 size; char p30[8]; s32 a,b,c,d; } Obj;
extern void func_800AE214(void);
extern void func_800AE6EC(void);
extern void func_800B1500(void *, s32, s32, Obj *);
/* Configures or resets an object's position and selects its drawing callback. */
void func_800AE040(Obj *object, s32 operation, Config *config) {
    Config *currentConfig;
    Triple *position;
    if(operation != 4) {
      if(operation == 5) {
        object->cfg=config;
        object->d=config->id;
        object->a=0;
        switch(config->mode) {
        case 0:
          object->fn=func_800AE6EC;
          currentConfig=object->cfg;
          currentConfig->count=(currentConfig->count/9)*9;
          currentConfig=object->cfg;
          object->size=(currentConfig->pair->x<<4)*currentConfig->pair->y;
          position=currentConfig->triple;
          if(position) {
            object->x=position->x;
            object->y=currentConfig->triple->y;
            object->z=currentConfig->triple->z;
            func_800B1500((char*)currentConfig->triple+12,object->ptr,32,object);
            return;
          }
          object->z=0; object->y=0; object->x=0;
          break;
        case 1:
          object->fn=func_800AE214;
          currentConfig=object->cfg;
          position=currentConfig->triple;
          if(position) {
            object->x=position->x;
            object->y=currentConfig->triple->y;
            object->z=currentConfig->triple->z;
            return;
          }
          object->z=0; object->y=0; object->x=0;
          break;
        }
      }
    } else {
      currentConfig=object->cfg;
      object->b=0;
      object->c=1;
      object->a=0;
      if(currentConfig) {
        object->d=currentConfig->id;
        if(currentConfig->mode==0) {
          position=currentConfig->triple;
          if(position) object->z=position->z;
        } else if(currentConfig->mode==1) {
          position=currentConfig->triple;
          if(position) object->z=position->z;
        }
      }
    }
}
