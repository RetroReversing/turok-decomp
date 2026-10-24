#include "common.h"

extern void func_80095464( unsigned short num );
extern void func_80095548(int code);
void func_80095464( unsigned short num );
void func_80095548( int num );
void func_80095464( unsigned short num ){
  int i;
  for(i = 0 ; i < 2; i++)
    func_80095548( num >> (8 * (1 - i)) );
}
