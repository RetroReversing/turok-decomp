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
extern void func_80035724(void) ;
extern unsigned long D_800B6AF4;
extern Mtx D_8011A9E0[400 * 2] ;
extern CAnimationMtxs D_801271E0 ;
void func_80035724(void);
void func_80035724(void){
 D_801271E0.m_MtxsFree = 400 ;
 D_801271E0.m_pmFreeMtx = &D_8011A9E0[400 * D_800B6AF4] ;
 D_801271E0.m_MtxsRequested = 0 ;
}
