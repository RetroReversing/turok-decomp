#include "common.h"

extern void func_80095124(int code);
extern void func_800955BC(const char *s);
void func_80095124( int in_code );
void func_800955BC(const char *s);
void func_800955BC(const char *s){
  while( *s )
    func_80095124( *s++ );
}
