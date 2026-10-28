#include "common.h"

extern void func_8009DE90(float *);
void func_800A1F00(float m[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
  register float dx;
  register float new_var;
  register float dy;
  register float dz;
  register int i; register int j;
  func_8009DE90(&m[0][0]);
  dx = r - l;
  dy = t - b;
  m[0][0] = 2.0f / dx;
  dz = f - n;
  m[1][1] = 2.0f / dy;
  m[2][2] = (-2.0f) / dz;
  new_var = (-(t + b)) / dy;
  m[3][0] = (-(r + l)) / dx;
  m[3][1] = new_var;
  m[3][2] = (-(f + n)) / dz;
  m[3][3] = 1.0f;
  for (i = 0; i < 4; i++)
  {
    for(j=0;j<4;j++) m[i][j] *= scale;
  }

}
