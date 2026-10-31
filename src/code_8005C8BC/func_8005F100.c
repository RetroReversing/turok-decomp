#include "common.h"

s32 func_8005F100(s32 soundId) {
    switch (soundId) {
    case 0:case 1:case 21:case 112:case 113:case 114:case 115:case 116:case 117:case 118:case 119:case 120:case 121:case 171:case 173:case 206:case 269:case 386:case 387:case 388:case 389:case 390:case 391:case 392:case 399:case 400:case 401:case 402:case 406:case 407:case 518:case 519:case 520:case 521:case 522:case 603:
        return 1;
    case 393:case 394:case 395:case 396:case 397:case 398:case 403:case 404:case 405:default:
        /* These IDs dispatch to empty entries or invalid cases. */
        return 0;
    }
}
