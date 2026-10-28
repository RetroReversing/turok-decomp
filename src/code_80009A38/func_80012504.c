#include "common.h"

typedef float CMtxF2[4][4];
typedef long Mtx_t2[4][4];
typedef union 
{
  Mtx_t2 m;
  long long force_structure_alignment;
} Mtx2;
void func_80012504(CMtxF2 mfThis, Mtx2 *m, f32 Tx, f32 Ty, f32 Tz)
{
  /* Convert a float matrix to packed 16.16 N64 format, adding translation to its last row. */
  signed long firstFixed;
  signed long secondFixed;
  signed long *integerWords;
  signed long *fractionWords;
  float *row1;
  integerWords = (signed long *) (&m->m[0][0]);
  fractionWords = (signed long *) (&m->m[2][0]);
  firstFixed = (long) (mfThis[0][0] * 65536.0f);
  secondFixed = (long) (mfThis[0][1] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) (mfThis[0][2] * 65536.0f);
  row1 = mfThis[1];
  secondFixed = (long) (mfThis[0][3] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) (mfThis[1][0] * 65536.0f);
  secondFixed = (long) (row1[1] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) (mfThis[1][2] * 65536.0f);
  secondFixed = (long) (mfThis[1][3] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) (mfThis[2][0] * 65536.0f);
  secondFixed = (long) (mfThis[2][1] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) (mfThis[2][2] * 65536.0f);
  secondFixed = (long) (mfThis[2][3] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) ((mfThis[3][0] * 65536.0f) + (Tx * 65536.0f));
  secondFixed = (long) ((mfThis[3][1] * 65536.0f) + (Ty * 65536.0f));
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
  firstFixed = (long) ((mfThis[3][2] * 65536.0f) + (Tz * 65536.0f));
  secondFixed = (long) (mfThis[3][3] * 65536.0f);
  *(integerWords++) = (firstFixed & 0xffff0000) | ((secondFixed >> 16) & 0xffff);
  *(fractionWords++) = ((firstFixed << 16) & 0xffff0000) | (secondFixed & 0xffff);
}
