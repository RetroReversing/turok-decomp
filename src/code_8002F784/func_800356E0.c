#include "common.h"

typedef long Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;
typedef struct CAnimationMtxs_t
{
 signed short m_MtxsFree ;
 Mtx *m_pmFreeMtx ;
 signed long m_MtxsRequested ;
} CAnimationMtxs ;
extern Mtx *func_800356E0(signed long Size) ;
extern CAnimationMtxs D_801271E0 ;
Mtx *func_800356E0(signed long Size);
Mtx *func_800356E0(signed long Size){
 Mtx *pMtx = ((void*)0) ;
 D_801271E0.m_MtxsRequested += Size ;
 if (D_801271E0.m_MtxsFree >= Size)
 {
  pMtx = D_801271E0.m_pmFreeMtx ;
  D_801271E0.m_pmFreeMtx += Size ;
  D_801271E0.m_MtxsFree -= Size ;
 }
                      ;
 return pMtx ;
}
