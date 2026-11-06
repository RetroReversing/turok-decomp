#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

void CMtxF__CopyPreMultScale(f32 *mfThis,f32 *mfSource,f32 Sx,f32 Sy,register f32 Sz)
{
mfThis[0]=mfSource[0]*Sx;
mfThis[1]=mfSource[1]*Sx;
mfThis[2]=mfSource[2]*Sx;
mfThis[4]=mfSource[4]*Sy;
mfThis[5]=mfSource[5]*Sy;
mfThis[6]=mfSource[6]*Sy;
mfThis[8]=mfSource[8]*Sz;
mfThis[9]=mfSource[9]*Sz;
mfThis[10]=mfSource[10]*Sz;
mfThis[12]=mfSource[12];
mfThis[13]=mfSource[13];
mfThis[14]=mfSource[14];
mfThis[3]=mfThis[7]=mfThis[11]=0.0f; mfThis[15]=1.0f;
}
