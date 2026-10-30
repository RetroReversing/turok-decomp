#include "common.h"

f64 _ldexpf(f64 arg0,s32 arg2) { if(arg2) arg0 *= (f64)(1 << arg2); return arg0; }
