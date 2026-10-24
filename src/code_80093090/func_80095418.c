#include "common.h"

extern void func_80095418( unsigned long num );
extern void func_80095548(int code);
void func_80095418( unsigned long num );
void func_80095548( int num );
void func_80095418( unsigned long num ){
  int i;
  for(i = 0 ; i < 4; i++)
    func_80095548( num >> (8 * (3 - i)) );
}
