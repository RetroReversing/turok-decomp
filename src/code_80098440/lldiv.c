#include "common.h"

s64 func_8009D46C(s64, s64);
s64 __ll_mul(s64, s64);
typedef struct 
{
  s32 aa;
  s32 bb;
  s32 cc;
  s32 dd;
} ResultWords;
typedef struct 
{
  s64 quotient;
  s64 remainder;
} Division;
void lldiv(ResultWords * volatile destination, s64 dividend, s64 divisor)
{
  Division tmp;
 goto dummy_label_320923; dummy_label_320923: ;
  tmp.quotient = func_8009D46C(dividend, divisor);
  tmp.remainder = dividend - __ll_mul(divisor, tmp.quotient);
  if ((tmp.quotient < 0) && (tmp.remainder > 0))
  {
    tmp.quotient++;
    tmp.remainder -= divisor;
  }
  {
    ResultWords *out = destination;
    *out = *((ResultWords *) (&tmp));
  }
}
