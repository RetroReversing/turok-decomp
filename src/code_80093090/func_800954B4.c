#include "common.h"

extern void func_80095124(int code);
extern void func_800954B4(int num);
extern void func_800955BC(const char *s);
void func_80095124( int in_code );
void func_800954B4(int num);
void func_800955BC(const char *s);
void func_800954B4(int num){
 char buffer[16],
    *pc;
 int current;
 if (num < 0)
 {
  func_80095124('-');
  current = -num;
 }
 else
 {
  current = num;
 }
 pc = &buffer[16 - 1];
 *pc = 0;
 do
 {
  *(--pc) = current%10 + '0';
  current /= 10;
 } while (current);
 func_800955BC(pc);
}
