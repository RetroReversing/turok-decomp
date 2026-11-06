#include "common.h"

extern void CMtxF__RotateY(void *, f32);
extern void CMtxF__PostMult(void *, void *, void *);
extern void CQuatern__ToMatrix(void *, void *);
extern f32 CGameRegion__GetEdgeAngle(void *);
extern void CGameRegion__GetCeilingRotation(void *, void *);
extern void CGameRegion__GetGroundRotation(void *, void *);
extern u8 D_80119FB0[], D_80119FF0[], D_8011A030[], D_8011A0D8[];

void *CParticle__GetAlignmentRotation(u8 *arg0, s32 mode) {
    u8 a[0x10], b[0x44];
    void *p;
    mode = *(s16 *)(arg0 + 0x16C);
    switch (mode + 6) {
        case 1:
            p = D_8011A030;
            break;
        case 3:
            CGameRegion__GetGroundRotation(a, *(void **)(arg0 + 0x14));
            CQuatern__ToMatrix(a, b);
            CMtxF__PostMult(D_8011A0D8, D_8011A030, b);
            p = D_8011A0D8;
            break;
        case 4:
            CGameRegion__GetCeilingRotation(a, *(void **)(arg0 + 0x14));
            CQuatern__ToMatrix(a, b);
            CMtxF__PostMult(D_8011A0D8, D_8011A030, b);
            p = D_8011A0D8;
            break;
        case 6:case 7:case 8:
            CMtxF__RotateY(D_8011A0D8, CGameRegion__GetEdgeAngle(*(void **)(arg0 + 0x14)));
            p = D_8011A0D8;
            break;
        case 0:
            p = D_80119FF0;
            break;
        default:
            p = D_80119FB0;
            break;
    }
    return p;
}
