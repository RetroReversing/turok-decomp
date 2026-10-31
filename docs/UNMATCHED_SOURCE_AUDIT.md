# Remaining Turok function source audit

Snapshot: **30 October 2026**. Read-only snapshot of the live app: **2,053 isolated matches, 294 open candidates and 59 assembly candidates**. Two more matches had arrived from background work since the earlier 2,051-match report. This audit did not submit candidates or change the running app. The tracked standalone checkpoint remains 2,036 selected C functions.

## Subsequent repair

All three shortlisted functions are now recovered: `func_8002AB68` as `CParticle__Advance`, `func_8007791C` as `AI_Standard_Follow`, and `alSeqNewMarker`. They were accepted by the live app and selected in the verified 2,039-C standalone build. The inventory below remains the original audit snapshot. See [repair evidence](SOURCE_ASSISTED_CHECKPOINT.md#source-naming-and-three-function-repair-30-october-2026) and the [source symbol index](SOURCE_SYMBOLS.md) for current names and unresolved alternatives.

## What this establishes

Every one of the **294 open candidates** was inventoried and its saved draft recompiled and evaluated with the corrected private judge. All compiled successfully; none replayed as an exact match. **121 have one or more located source candidates**, while **173 have no sufficiently supported implementation mapping yet. Candidate identity is explicitly provisional unless supported by a source alias; even an alias or matching call sequence does not prove retail-equivalent source.

The unresolved group is not evidence that those functions are absent from the source. It includes SDK/runtime/audio code, anonymous functions and duplicate tiny handlers. Several earlier broad object searches proposed misleading candidates; weak nearest neighbours have deliberately not been promoted to mappings. No open function is classified as a proven retail-source difference on this evidence alone.

| Replay result | Functions | Target bytes | Interpretation |
| --- | ---: | ---: | --- |
| Symbol/data relocation blocker | 44 | 54,880 | At least one symbol/section address cannot be reconciled; additional code differences can coexist. |
| Small instruction mismatch | 56 | 11,004 | At most 12 differing instruction rows; this is a diagnostic size bucket, not a proven root cause. |
| Larger mismatch; cause unproven | 194 | 93,252 | More differences; source identity, preparation, ABI, flags or retail edits still need investigation. |

The relocation group includes **9 drafts with unknown symbol names** and **35 with other owned-data/relocation problems**. These counts describe the first observed blockers, not mutually exclusive ultimate causes. Scores below are raw judge scores (lower is better), not percentages.

## Highest-value repair groups

| Target | Located reference | Evidence | Next repair |
| --- | --- | --- | --- |
| `func_8002AB68` | `particle.c:1975`, `CParticle__Advance` | Score 6; all six differences are stack size/offsets. | Recover local/inline storage layout and alignment. |
| `func_8007791C` | `aistand.c:1394`, `AI_Standard_Follow` | Score 7; all seven differences are stack placement. | Recover argument spills and local declaration/inline context. |
| `alSeqNewMarker` | `turoksnd/abi/seq.c:218` | Score 4; all four differences are stack offsets. | Reproduce event-record storage and local ordering. |
| `func_800272F4` | `particle.c:2587`, `CParticle__Draw` | Score 130; five rows differ, concentrated around a load and branch displacement. | Investigate load motion, alias information and expression scheduling. |
| `func_80019300` | `romstruc.c:8837`, `CGameObjectInstance__PreDraw` | Unknown `particle_glare_color`, conflicting BSS mapping, and owned constants. | Restore globals and separate data placement from instruction tuning. |
| `func_80032BD8` | `scene.c:1436`, `CScene__DecompressInstances` | Six owned-rodata address problems plus extensive code differences. | Check macro/inline context and constant pools before permutation. |

**Tiny event handlers:** twelve open 16-byte candidates have the same normalized object shape as archived event handlers in `ai.c`. Their saved drafts differ by a single argument-spill instruction. This suggests a shared signature/ABI issue worth testing, but the identical shapes do not establish which individual handler name belongs to each address. They remain unmapped individually.

**Library coverage:** the supplied tree has only a subset of libultra implementation sources (41 C files under `src/PR/libultra`). For example, the inspected tree contains declarations/calls for `osDestroyThread` and `osYieldThread`, but no implementation body was located. `__cosf` and `__sinf`, however, are present under the source spellings `fcos` and `fsin`, with explicit aliases. Missing SDK implementations must be distinguished from missing Turok gameplay source.

Recommended order: fix shared symbol/data-context errors; resolve stack-only and tiny ABI mismatches; then investigate larger source/retail differences after validating each identity. Blind permutation cannot recover an omitted SDK body or fix an incorrect source-to-ROM association.

## Complete open-function inventory

Paths below are relative to the supplied source archive. `tengine/` abbreviates `src/PR/tengine/`; `libultra/` abbreviates `src/PR/libultra/`. Locations are original source lines. “Tentative” is a research lead, not an accepted rename. Full competing candidates, object/call comparisons, replay diagnostics and recommended per-function actions are retained privately in `.local/source-audit-20261030/mapped-audit.json`.

| ROM function | Bytes | Source candidate and location | Mapping evidence | Replay result | Score |
| --- | ---: | --- | --- | --- | ---: |
| `func_8000134C` | 816 | `faultproc` — `tengine/tengine.c:430` | Tentative candidate | Symbol/data relocation blocker | 635 |
| `func_80001D30` | 288 | `CEngineApp__Idle` — `tengine/tengine.c:830` | Call-supported candidate | Small instruction mismatch | 400 |
| `func_800061C4` | 484 | Not located | Not located | Symbol/data relocation blocker | 3104 |
| `func_8000658C` | 484 | Not located | Not located | Symbol/data relocation blocker | 3469 |
| `func_80006770` | 484 | Not located | Not located | Larger mismatch; cause unproven | 662 |
| `func_80008060` | 524 | Not located | Not located | Symbol/data relocation blocker | 340 |
| `func_80009B24` | 392 | Not located | Not located | Larger mismatch; cause unproven | 1637 |
| `func_8000B28C` | 1688 | `CEngineApp__DrawGALLERY` — `tengine/tengine.c:1479` | Tentative candidate | Larger mismatch; cause unproven | 7022 |
| `func_8000BEF0` | 316 | Not located | Not located | Larger mismatch; cause unproven | 325 |
| `func_8000C04C` | 960 | `CCheatCode__Update` — `tengine/loadsave.c:3303` | Tentative candidate | Symbol/data relocation blocker | 9412 |
| `func_8000CCE4` | 308 | Not located | Not located | Larger mismatch; cause unproven | 710 |
| `func_8000CE50` | 372 | Not located | Not located | Symbol/data relocation blocker | 890 |
| `func_8000EC10` | 688 | Not located | Not located | Larger mismatch; cause unproven | 1517 |
| `func_8000F108` | 912 | `CCheatCode__Update` — `tengine/loadsave.c:3303` | Tentative candidate | Symbol/data relocation blocker | 6067 |
| `func_800113A8` | 900 | `ScanFileList` — `tengine/control.c:407` | Tentative candidate | Symbol/data relocation blocker | 500 |
| `func_800118EC` | 264 | Not located | Not located | Larger mismatch; cause unproven | 395 |
| `func_800119F4` | 248 | `SaveNew` — `tengine/control.c:575` | Call-supported candidate | Larger mismatch; cause unproven | 185 |
| `func_80011BD8` | 404 | Not located | Not located | Larger mismatch; cause unproven | 585 |
| `func_800120DC` | 124 | Not located | Not located | Larger mismatch; cause unproven | 543 |
| `func_80012F8C` | 160 | Not located | Not located | Larger mismatch; cause unproven | 1825 |
| `func_80013DC8` | 156 | Not located | Not located | Small instruction mismatch | 49 |
| `func_80013FD8` | 156 | `CVector3__ProjectCrease` — `tengine/graphu64.c:897` | Call-supported candidate | Small instruction mismatch | 180 |
| `func_800153B4` | 360 | Not located | Not located | Larger mismatch; cause unproven | 4158 |
| `func_80016730` | 588 | `CGameObjectInstance__GetModelIndex` — `tengine/romstruc.c:9762` | Tentative candidate | Symbol/data relocation blocker | 1202 |
| `func_800169E0` | 276 | Not located | Not located | Larger mismatch; cause unproven | 1227 |
| `func_80016AF4` | 500 | Not located | Not located | Larger mismatch; cause unproven | 1960 |
| `func_800181A0` | 212 | Not located | Not located | Larger mismatch; cause unproven | 557 |
| `func_800183C4` | 640 | Not located | Not located | Larger mismatch; cause unproven | 3418 |
| `func_80019300` | 2424 | `CGameObjectInstance__PreDraw` — `tengine/romstruc.c:8837` | Tentative candidate | Symbol/data relocation blocker | 1835 |
| `func_80019F64` | 2088 | `CGameObjectInstance__DrawShadow` — `tengine/romstruc.c:4555` | Tentative candidate | Symbol/data relocation blocker | 4393 |
| `func_8001B1C0` | 2148 | `CGameObjectInstance__AdvanceAccumulation` — `tengine/romstruc.c:3973` | Tentative candidate | Larger mismatch; cause unproven | 2485 |
| `func_8001BAAC` | 2204 | `CGameObjectInstance__Advance` — `tengine/romstruc.c:3578` | Tentative candidate | Symbol/data relocation blocker | 1834 |
| `func_8001C9D8` | 2152 | `CGameObjectInstance__Draw` — `tengine/romstruc.c:8446` | Tentative candidate | Symbol/data relocation blocker | 5047 |
| `func_8001DE20` | 304 | Not located | Not located | Larger mismatch; cause unproven | 483 |
| `func_8001E21C` | 220 | `CGameRegion__InRegion` — `tengine/romstruc.c:5161` | Tentative candidate | Larger mismatch; cause unproven | 70 |
| `func_8001F0AC` | 492 | Not located | Not located | Larger mismatch; cause unproven | 1810 |
| `func_8001F2B4` | 556 | Not located | Not located | Larger mismatch; cause unproven | 909 |
| `func_8001F4E0` | 792 | Not located | Not located | Larger mismatch; cause unproven | 4244 |
| `func_800203B0` | 592 | `CGameSimpleInstance__TakeFromROMSimpleInstance` — `tengine/romstruc.c:1229` | Call-supported candidate | Symbol/data relocation blocker | 1061 |
| `func_800207C0` | 316 | Not located | Not located | Larger mismatch; cause unproven | 885 |
| `func_80020CAC` | 296 | Not located | Not located | Larger mismatch; cause unproven | 1666 |
| `func_80020DD4` | 368 | Not located | Not located | Larger mismatch; cause unproven | 660 |
| `func_800272F4` | 3508 | `CParticle__Draw` — `tengine/particle.c:2587` | Tentative candidate | Small instruction mismatch | 130 |
| `func_800281F0` | 508 | Not located | Not located | Larger mismatch; cause unproven | 1839 |
| `func_8002864C` | 384 | `CParticleSystem__DeallocateParticle` — `tengine/particle.c:1180` | Call-supported candidate | Larger mismatch; cause unproven | 1820 |
| `func_80029C48` | 260 | Not located | Not located | Larger mismatch; cause unproven | 1113 |
| `func_8002A1A0` | 260 | Not located | Not located | Larger mismatch; cause unproven | 1209 |
| `func_8002A2A4` | 268 | Not located | Not located | Larger mismatch; cause unproven | 505 |
| `func_8002A3B0` | 268 | Not located | Not located | Larger mismatch; cause unproven | 438 |
| `func_8002A4BC` | 268 | Not located | Not located | Larger mismatch; cause unproven | 521 |
| `func_8002A5C8` | 300 | Not located | Not located | Larger mismatch; cause unproven | 789 |
| `func_8002A6F4` | 268 | Not located | Not located | Larger mismatch; cause unproven | 2826 |
| `func_8002A800` | 240 | Not located | Not located | Larger mismatch; cause unproven | 855 |
| `func_8002A8F0` | 328 | Not located | Not located | Larger mismatch; cause unproven | 779 |
| `func_8002AA38` | 304 | Not located | Not located | Larger mismatch; cause unproven | 1222 |
| `func_8002AB68` | 1148 | `CParticle__Advance` — `tengine/particle.c:1975` | Tentative candidate | Small instruction mismatch | 6 |
| `func_8002B2E8` | 120 | Not located | Not located | Larger mismatch; cause unproven | 1079 |
| `func_8002B5E0` | 584 | Not located | Not located | Larger mismatch; cause unproven | 3873 |
| `func_8002BA48` | 256 | Not located | Not located | Small instruction mismatch | 1200 |
| `func_8002BF28` | 856 | `initAudio` — `tengine/audio.c:112` | Tentative candidate | Small instruction mismatch | 35 |
| `func_8002C280` | 652 | Not located | Not located | Larger mismatch; cause unproven | 1603 |
| `func_8002C63C` | 356 | Not located | Not located | Larger mismatch; cause unproven | 590 |
| `__scSchedule` | 484 | `__scSchedule` — `tengine/sched.c:744` | Existing name/alias | Symbol/data relocation blocker | 4418 |
| `func_8002D1F8` | 500 | Not located | Not located | Larger mismatch; cause unproven | 3682 |
| `func_8002D4EC` | 280 | Not located | Not located | Larger mismatch; cause unproven | 848 |
| `func_8002D6BC` | 200 | Not located | Not located | Larger mismatch; cause unproven | 1340 |
| `func_8002D950` | 40 | Not located | Not located | Small instruction mismatch | 105 |
| `func_8002D978` | 96 | Not located | Not located | Small instruction mismatch | 15 |
| `func_8002DA18` | 116 | `CUnindexedSet__PreAllocate` — `tengine/cart.c:671` | Tentative candidate | Larger mismatch; cause unproven | 595 |
| `func_8002DA9C` | 124 | Not located | Not located | Small instruction mismatch | 15 |
| `func_8002DB18` | 108 | Not located | Not located | Small instruction mismatch | 180 |
| `func_8002DCCC` | 92 | Not located | Not located | Small instruction mismatch | 15 |
| `func_8002DD90` | 168 | Not located | Not located | Larger mismatch; cause unproven | 405 |
| `func_8002DEF0` | 176 | Not located | Not located | Small instruction mismatch | 22 |
| `func_8002FBD0` | 1292 | `CScene__GetGridSections` — `tengine/scene.c:3052` | Call-supported candidate | Symbol/data relocation blocker | 692 |
| `func_800318D0` | 152 | Not located | Not located | Larger mismatch; cause unproven | 80 |
| `func_80032BD8` | 2524 | `CScene__DecompressInstances` — `tengine/scene.c:1436` | Tentative candidate | Symbol/data relocation blocker | 6346 |
| `func_800337BC` | 908 | `CScene__DecompressCollision` — `tengine/scene.c:1203` | Tentative candidate | Larger mismatch; cause unproven | 9704 |
| `func_80033CDC` | 648 | Not located | Not located | Larger mismatch; cause unproven | 3025 |
| `func_80035438` | 668 | Not located | Not located | Larger mismatch; cause unproven | 3345 |
| `func_800398FC` | 668 | Not located | Not located | Larger mismatch; cause unproven | 5664 |
| `func_8003F804` | 436 | Not located | Not located | Symbol/data relocation blocker | 2630 |
| `func_80044BDC` | 708 | `Mantis_ClosestWall` — `tengine/mantis.c:1253` | Existing name/alias | Symbol/data relocation blocker | 360 |
| `func_800474F8` | 184 | `Mantis_Setup_DEATH` — `tengine/mantis.c:2969` | Tentative candidate | Larger mismatch; cause unproven | 775 |
| `func_80047AA0` | 1204 | `TRex_UpdateLaserSound` — `tengine/trex.c:1098` | Tentative candidate | Symbol/data relocation blocker | 1475 |
| `func_8004D218` | 492 | `Campaigner_Initialise` — `tengine/campaign.c:862` | Existing name/alias | Larger mismatch; cause unproven | 1160 |
| `func_8004D6FC` | 976 | `Campaigner_Update` — `tengine/campaign.c:1108` | Existing name/alias | Symbol/data relocation blocker | 1190 |
| `func_8004F74C` | 136 | `Campaigner_Code_DEATH` — `tengine/campaign.c:2484` | Tentative candidate | Small instruction mismatch | 235 |
| `func_8005EA80` | 656 | Not located | Not located | Larger mismatch; cause unproven | 5045 |
| `func_8005EED0` | 136 | Not located | Not located | Larger mismatch; cause unproven | 210 |
| `func_8005FD28` | 1108 | `AI_MEvent_PressurePlate` — `tengine/ai.c:2733` | Call-supported candidate | Symbol/data relocation blocker | 3954 |
| `func_80060464` | 840 | `AI_AimParticleAtPlayer` — `tengine/ai.c:7958` | Tentative candidate | Larger mismatch; cause unproven | 1861 |
| `func_800607AC` | 680 | `AI_SEvent_KnifeTomahawkBlood_Particles` — `tengine/ai.c:5707` | Tentative candidate | Symbol/data relocation blocker | 1255 |
| `func_80060AE4` | 2404 | `AI_KnifeTomahawkDamage` — `tengine/ai.c:5396` | Tentative candidate | Symbol/data relocation blocker | 4554 |
| `func_80061CC4` | 740 | `AI_MEvent_Damage` — `tengine/ai.c:3446` | Tentative candidate | Symbol/data relocation blocker | 1290 |
| `func_8006905C` | 252 | `AI_SEvent_DamageNudge_Target` — `tengine/ai.c:6010` | Call-supported candidate | Larger mismatch; cause unproven | 1055 |
| `func_80069EE0` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069EF0` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F00` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F10` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F20` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F30` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F40` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F64` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F74` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80069F84` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_8006A654` | 628 | Not located | Not located | Symbol/data relocation blocker | 1177 |
| `func_8006AB24` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_8006B1B4` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `func_80070DA8` | 624 | Not located | Not located | Larger mismatch; cause unproven | 635 |
| `func_80071058` | 1716 | `printFaultData` — `tengine/prfault.c:610` | Tentative candidate | Larger mismatch; cause unproven | 26789 |
| `func_80071F08` | 448 | Not located | Not located | Larger mismatch; cause unproven | 1410 |
| `func_80072144` | 248 | Not located | Not located | Small instruction mismatch | 51 |
| `func_8007223C` | 1444 | `AI_Make_Turn` — `tengine/ai.c:9254` | Tentative candidate | Symbol/data relocation blocker | 5799 |
| `func_800727E0` | 1076 | `AI_AssistSniperTurn` — `tengine/ai.c:9138` | Tentative candidate | Symbol/data relocation blocker | 9424 |
| `func_80072C14` | 244 | Not located | Not located | Larger mismatch; cause unproven | 457 |
| `func_80072D08` | 272 | Not located | Not located | Larger mismatch; cause unproven | 417 |
| `func_800731F8` | 1828 | `AI_Make_Walk` — `tengine/ai.c:8816` | Tentative candidate | Larger mismatch; cause unproven | 31850 |
| `func_8007391C` | 1724 | `AI_Make_Retreat` — `tengine/ai.c:8662` | Tentative candidate | Larger mismatch; cause unproven | 39614 |
| `func_80073FD8` | 1864 | `AI_Make_Run` — `tengine/ai.c:8453` | Tentative candidate | Larger mismatch; cause unproven | 31410 |
| `func_80074A74` | 448 | Not located | Not located | Small instruction mismatch | 60 |
| `func_80074E10` | 272 | Not located | Not located | Larger mismatch; cause unproven | 2162 |
| `func_80074F20` | 368 | Not located | Not located | Larger mismatch; cause unproven | 915 |
| `func_80075090` | 316 | Not located | Not located | Larger mismatch; cause unproven | 582 |
| `func_8007719C` | 460 | `AI_Standard_Sniper` — `tengine/aistand.c:1649` | Tentative candidate | Larger mismatch; cause unproven | 275 |
| `func_80077368` | 1436 | `AI_Standard_DeadBodyRiddle` — `tengine/aistand.c:1478` | Call-supported candidate | Symbol/data relocation blocker | 20957 |
| `func_8007791C` | 536 | `AI_Standard_Follow` — `tengine/aistand.c:1394` | Tentative candidate | Small instruction mismatch | 7 |
| `func_80077BFC` | 1092 | `AI_Standard_Death` — `tengine/aistand.c:924` | Call-supported candidate | Symbol/data relocation blocker | 5950 |
| `func_80079540` | 332 | Not located | Not located | Larger mismatch; cause unproven | 467 |
| `func_8007CDC0` | 388 | Not located | Not located | Larger mismatch; cause unproven | 805 |
| `func_80081210` | 668 | Not located | Not located | Larger mismatch; cause unproven | 209 |
| `func_80084E9C` | 2568 | `CPause__Update` — `tengine/pause.c:1059` | Tentative candidate | Larger mismatch; cause unproven | 52760 |
| `func_80087FC0` | 268 | Not located | Not located | Larger mismatch; cause unproven | 1710 |
| `func_80088124` | 1968 | `AI_Make_Run` — `tengine/ai.c:8453` | Tentative candidate | Symbol/data relocation blocker | 41770 |
| `func_800888D4` | 1596 | `CCheat__Draw` — `tengine/cheats.c:718` | Tentative candidate | Symbol/data relocation blocker | 1455 |
| `func_800894B0` | 824 | `initAudio` — `tengine/audio.c:112` | Call-supported candidate | Symbol/data relocation blocker | 590 |
| `func_80093D48` | 144 | Not located | Not located | Larger mismatch; cause unproven | 85 |
| `func_80098E28` | 240 | Not located | Not located | Larger mismatch; cause unproven | 7420 |
| `func_80099208` | 1340 | `CCollide__CanEnter` — `tengine/unicol.c:771` | Tentative candidate | Larger mismatch; cause unproven | 8356 |
| `func_80099744` | 2580 | `CCollide__IntersectPlane` — `tengine/unicol.c:383` | Tentative candidate | Symbol/data relocation blocker | 6080 |
| `func_8009A158` | 756 | Not located | Not located | Larger mismatch; cause unproven | 3866 |
| `func_8009A4D8` | 1936 | `CAnimInstanceHdr__Collision3` — `tengine/unicol.c:43` | Tentative candidate | Symbol/data relocation blocker | 4230 |
| `func_8009BD30` | 2196 | `CCollide__RegionCollision` — `tengine/regicol.c:15` | Tentative candidate | Larger mismatch; cause unproven | 42137 |
| `osGetTime` | 132 | `osGetTime` — `src/PR/spgame/spgame.c:78` | Existing name/alias | Larger mismatch; cause unproven | 649 |
| `__ull_rshift` | 44 | Not located | Not located | Larger mismatch; cause unproven | 1031 |
| `func_8009D38C` | 60 | Not located | Not located | Small instruction mismatch | 980 |
| `__ll_lshift` | 44 | Not located | Not located | Small instruction mismatch | 700 |
| `func_8009D430` | 60 | Not located | Not located | Small instruction mismatch | 980 |
| `__ll_mul` | 48 | Not located | Not located | Small instruction mismatch | 800 |
| `__ll_mod` | 156 | Not located | Not located | Larger mismatch; cause unproven | 3075 |
| `func_8009D620` | 672 | Not located | Not located | Larger mismatch; cause unproven | 8017 |
| `__d_to_ull` | 160 | Not located | Not located | Larger mismatch; cause unproven | 2275 |
| `func_8009DA4C` | 24 | Not located | Not located | Small instruction mismatch | 360 |
| `__ull_to_d` | 52 | Not located | Not located | Small instruction mismatch | 510 |
| `guMtxF2L` | 256 | `guMtxF2L` — `libultra/gu/mtxutil.c:15` | Existing name/alias | Larger mismatch; cause unproven | 1055 |
| `guMtxL2F` | 180 | `guMtxL2F` — `libultra/gu/mtxutil.c:34` | Existing name/alias | Larger mismatch; cause unproven | 1177 |
| `osCreateThread` | 324 | Not located | Not located | Larger mismatch; cause unproven | 1153 |
| `osStartThread` | 336 | Not located | Not located | Larger mismatch; cause unproven | 3415 |
| `osCreatePiManager` | 392 | Not located | Not located | Larger mismatch; cause unproven | 2989 |
| `__cosf` | 360 | `fcos` — `libultra/gu/cosf.c:69` | Explicit source alias | Small instruction mismatch | 25 |
| `__sinf` | 448 | `fsin` — `libultra/gu/sinf.c:69` | Explicit source alias | Larger mismatch; cause unproven | 1445 |
| `osContStartReadData` | 196 | Not located | Not located | Larger mismatch; cause unproven | 1162 |
| `osContGetReadData` | 168 | Not located | Not located | Larger mismatch; cause unproven | 1272 |
| `__osPackReadData` | 236 | Not located | Not located | Larger mismatch; cause unproven | 1531 |
| `osContInit` | 504 | Not located | Not located | Larger mismatch; cause unproven | 2831 |
| `func_8009EDC8` | 208 | Not located | Not located | Larger mismatch; cause unproven | 1335 |
| `__osPackRequestData` | 244 | Not located | Not located | Larger mismatch; cause unproven | 1528 |
| `osPfsIsPlug` | 416 | Not located | Not located | Larger mismatch; cause unproven | 6367 |
| `__osPfsRequestData` | 252 | Not located | Not located | Larger mismatch; cause unproven | 1963 |
| `func_8009F22C` | 208 | Not located | Not located | Larger mismatch; cause unproven | 2412 |
| `osPfsNumFiles` | 324 | Not located | Not located | Larger mismatch; cause unproven | 5657 |
| `osPfsFreeBlocks` | 332 | Not located | Not located | Larger mismatch; cause unproven | 4591 |
| `osPfsFileState` | 752 | Not located | Not located | Larger mismatch; cause unproven | 13402 |
| `osPfsDeleteFile` | 736 | Not located | Not located | Larger mismatch; cause unproven | 13218 |
| `__osPfsReleasePages` | 568 | Not located | Not located | Larger mismatch; cause unproven | 11878 |
| `__osPfsGetNextPage` | 252 | Not located | Not located | Larger mismatch; cause unproven | 2695 |
| `osPfsReadWriteFile` | 1024 | `CGameObjectInstance__GetAutoAimRotation` — `tengine/romstruc.c:7478` | Tentative candidate | Larger mismatch; cause unproven | 15876 |
| `osPfsAllocateFile` | 1156 | `AI_Standard_Flying` — `tengine/aistand.c:1796` | Tentative candidate | Larger mismatch; cause unproven | 26190 |
| `__osPfsDeclearPage` | 612 | Not located | Not located | Larger mismatch; cause unproven | 10785 |
| `__osClearPage` | 192 | Not located | Not located | Larger mismatch; cause unproven | 234 |
| `osCreateViManager` | 392 | Not located | Not located | Larger mismatch; cause unproven | 2827 |
| `func_800A0F38` | 460 | Not located | Not located | Larger mismatch; cause unproven | 7973 |
| `osSendMesg` | 332 | Not located | Not located | Larger mismatch; cause unproven | 3400 |
| `guLookAtF` | 696 | `guLookAtF` — `libultra/gu/lookat.c:15` | Existing name/alias | Larger mismatch; cause unproven | 661 |
| `guLookAt` | 120 | `guLookAt` — `libultra/gu/lookat.c:74` | Existing name/alias | Larger mismatch; cause unproven | 481 |
| `guPerspectiveF` | 560 | `guPerspectiveF` — `libultra/gu/perspective.c:17` | Existing name/alias | Larger mismatch; cause unproven | 2290 |
| `func_800A2170` | 236 | Not located | Not located | Larger mismatch; cause unproven | 1500 |
| `alBnkfNew` | 260 | `alBnkfNew` — `turoksnd/abi/bnkf.c:47` | Existing name/alias | Larger mismatch; cause unproven | 878 |
| `func_800A2420` | 52 | Not located | Not located | Small instruction mismatch | 25 |
| `func_800A245C` | 464 | Not located | Not located | Larger mismatch; cause unproven | 6188 |
| `func_800A2E5C` | 1556 | `CCheat__Draw` — `tengine/cheats.c:718` | Tentative candidate | Symbol/data relocation blocker | 22999 |
| `alCSPNew` | 364 | `alCSPNew` — `turoksnd/abi/csplayer.c:59` | Existing name/alias | Larger mismatch; cause unproven | 455 |
| `func_800A35E0` | 124 | Not located | Not located | Larger mismatch; cause unproven | 982 |
| `func_800A366C` | 1352 | `CGInst__Draw` — `tengine/cheats.c:960` | Tentative candidate | Symbol/data relocation blocker | 19242 |
| `alSndpNew` | 308 | `alSndpNew` — `turoksnd/abi/sndplayer.c:27` | Existing name/alias | Larger mismatch; cause unproven | 2401 |
| `alSndpSetFXMix` | 88 | `alSndpSetFXMix` — `turoksnd/abi/sndpsetfxmix.c:25` | Existing name/alias | Small instruction mismatch | 110 |
| `alSndpSetVol` | 88 | `alSndpSetVol` — `turoksnd/abi/sndpsetvol.c:25` | Existing name/alias | Small instruction mismatch | 150 |
| `alSndpGetState` | 32 | `alSndpGetState` — `turoksnd/abi/sndpgetstate.c:23` | Existing name/alias | Small instruction mismatch | 10 |
| `alSndpDeallocate` | 80 | `alSndpDeallocate` — `turoksnd/abi/sndpdeallocate.c:25` | Existing name/alias | Small instruction mismatch | 25 |
| `alCSeqGetLoc` | 160 | `alCSeqGetLoc` — `turoksnd/abi/cseq.c:314` | Existing name/alias | Larger mismatch; cause unproven | 160 |
| `alCSeqSetLoc` | 160 | `alCSeqSetLoc` — `turoksnd/abi/cseq.c:296` | Existing name/alias | Larger mismatch; cause unproven | 245 |
| `func_800A4200` | 196 | Not located | Not located | Larger mismatch; cause unproven | 1520 |
| `alCSeqNextEvent` | 760 | `alCSeqNextEvent` — `turoksnd/abi/cseq.c:63` | Existing name/alias | Larger mismatch; cause unproven | 5848 |
| `alCSeqNew` | 276 | `alCSeqNew` — `turoksnd/abi/cseq.c:31` | Existing name/alias | Larger mismatch; cause unproven | 988 |
| `alCSeqNewMarker` | 364 | `alCSeqNewMarker` — `turoksnd/abi/cseq.c:264` | Existing name/alias | Larger mismatch; cause unproven | 475 |
| `alCSeqSecToTicks` | 252 | `alCSeqSecToTicks` — `turoksnd/abi/cseq.c:252` | Existing name/alias | Small instruction mismatch | 45 |
| `__alCSeqNextDelta` | 360 | `__alCSeqNextDelta` — `turoksnd/abi/cseq.c:108` | Existing name/alias | Larger mismatch; cause unproven | 600 |
| `func_800A4C00` | 88 | Not located | Not located | Small instruction mismatch | 175 |
| `func_800A4D00` | 352 | Not located | Not located | Larger mismatch; cause unproven | 2565 |
| `func_800A4FB0` | 168 | Not located | Not located | Larger mismatch; cause unproven | 1320 |
| `alAudioFrame` | 664 | `alAudioFrame` — `turoksnd/abi/synthesizer.c:142` | Existing name/alias | Larger mismatch; cause unproven | 3866 |
| `alSynNew` | 768 | `alSynNew` — `turoksnd/abi/synthesizer.c:39` | Existing name/alias | Larger mismatch; cause unproven | 2122 |
| `__osEnqueueThread` | 72 | Not located | Not located | Larger mismatch; cause unproven | 660 |
| `func_800A5F34` | 16 | Not located | Not located | Small instruction mismatch | 10 |
| `__osTimerServicesInit` | 140 | Not located | Not located | Larger mismatch; cause unproven | 1675 |
| `__osTimerInterrupt` | 376 | Not located | Not located | Larger mismatch; cause unproven | 5007 |
| `__osSetTimerIntr` | 116 | Not located | Not located | Larger mismatch; cause unproven | 925 |
| `__osInsertTimer` | 392 | Not located | Not located | Larger mismatch; cause unproven | 4525 |
| `_bzero` | 156 | Not located | Not located | Larger mismatch; cause unproven | 1555 |
| `func_800A67D0` | 1764 | `printFaultData` — `tengine/prfault.c:610` | Tentative candidate | Larger mismatch; cause unproven | 30345 |
| `func_800A6EB4` | 232 | Not located | Not located | Larger mismatch; cause unproven | 3035 |
| `__osLeoResume` | 236 | Not located | Not located | Larger mismatch; cause unproven | 1853 |
| `func_800A7090` | 332 | Not located | Not located | Larger mismatch; cause unproven | 3305 |
| `func_800A72A0` | 224 | Not located | Not located | Larger mismatch; cause unproven | 1868 |
| `func_800A7380` | 224 | Not located | Not located | Larger mismatch; cause unproven | 2742 |
| `func_800A7460` | 944 | `PlayEnvironmentSound` — `tengine/audio.c:293` | Tentative candidate | Symbol/data relocation blocker | 15325 |
| `gl_func_0006E224` | 1648 | `CGeometry__SetRenderMode` — `tengine/geometry.c:251` | Tentative candidate | Symbol/data relocation blocker | 19253 |
| `func_800A7E80` | 1604 | `CGeometry__SetRenderMode` — `tengine/geometry.c:251` | Tentative candidate | Larger mismatch; cause unproven | 17150 |
| `__osRepairPackId` | 1048 | `Campaigner_Code_Movement` — `tengine/campaign.c:1799` | Tentative candidate | Larger mismatch; cause unproven | 3119 |
| `__osCheckPackId` | 408 | Not located | Not located | Larger mismatch; cause unproven | 970 |
| `func_800A8D94` | 604 | Not located | Not located | Larger mismatch; cause unproven | 2489 |
| `__osCheckId` | 252 | Not located | Not located | Larger mismatch; cause unproven | 525 |
| `__osPfsRWInode` | 800 | Not located | Not located | Larger mismatch; cause unproven | 4463 |
| `osPfsChecker` | 1732 | `AI_Make_Retreat` — `tengine/ai.c:8662` | Tentative candidate | Larger mismatch; cause unproven | 7666 |
| `corrupted_init` | 436 | Not located | Not located | Larger mismatch; cause unproven | 3060 |
| `corrupted` | 488 | Not located | Not located | Larger mismatch; cause unproven | 3953 |
| `__osContRamRead` | 580 | Not located | Not located | Larger mismatch; cause unproven | 3597 |
| `osPfsFindFile` | 436 | Not located | Not located | Larger mismatch; cause unproven | 1181 |
| `__osContRamWrite` | 560 | Not located | Not located | Larger mismatch; cause unproven | 2468 |
| `__osPackRamWriteData` | 380 | Not located | Not located | Larger mismatch; cause unproven | 5744 |
| `func_800AA810` | 860 | `CEngineApp__Warp` — `tengine/tengine.c:2355` | Tentative candidate | Larger mismatch; cause unproven | 15918 |
| `_bcopy` | 772 | Not located | Not located | Larger mismatch; cause unproven | 17775 |
| `func_800AAEA0` | 52 | Not located | Not located | Small instruction mismatch | 545 |
| `func_800AAF70` | 44 | Not located | Not located | Small instruction mismatch | 210 |
| `func_800AAFA0` | 44 | Not located | Not located | Small instruction mismatch | 190 |
| `osJamMesg` | 336 | Not located | Not located | Larger mismatch; cause unproven | 2777 |
| `__vsVol` | 136 | `__vsVol` — `turoksnd/abi/seqplayer.c:912` | Existing name/alias | Larger mismatch; cause unproven | 215 |
| `__voiceNeedsNoteKill` | 168 | `__voiceNeedsNoteKill` — `turoksnd/abi/seqplayer.c:1033` | Existing name/alias | Larger mismatch; cause unproven | 510 |
| `func_800AB6AC` | 120 | Not located | Not located | Larger mismatch; cause unproven | 655 |
| `__lookupSoundQuick` | 252 | `__lookupSoundQuick` — `turoksnd/abi/seqplayer.c:878` | Existing name/alias | Larger mismatch; cause unproven | 575 |
| `func_800AB94C` | 2072 | `CSave__DrawMemory` — `tengine/loadsave.c:1768` | Tentative candidate | Symbol/data relocation blocker | 48117 |
| `func_800AC16C` | 1572 | `CGameObjectInstance__CalculateOrientationMatrix` — `tengine/romstruc.c:2866` | Tentative candidate | Symbol/data relocation blocker | 9721 |
| `alSeqpNew` | 384 | `alSeqpNew` — `turoksnd/abi/seqplayer.c:56` | Existing name/alias | Larger mismatch; cause unproven | 1507 |
| `alEvtqPostEvent` | 292 | `alEvtqPostEvent` — `turoksnd/abi/event.c:74` | Existing name/alias | Larger mismatch; cause unproven | 710 |
| `alEvtqNextEvent` | 140 | `alEvtqNextEvent` — `turoksnd/abi/event.c:41` | Existing name/alias | Small instruction mismatch | 84 |
| `alSynFreeVoice` | 176 | `alSynFreeVoice` — `turoksnd/abi/synfreevoice.c:27` | Existing name/alias | Larger mismatch; cause unproven | 335 |
| `_allocatePVoice` | 232 | `_allocatePVoice` — `turoksnd/abi/synallocvoice.c:100` | Existing name/alias | Larger mismatch; cause unproven | 920 |
| `func_800AD680` | 48 | Not located | Not located | Small instruction mismatch | 290 |
| `alResampleNew` | 136 | `alResampleNew` — `turoksnd/abi/drvrNew.c:248` | Existing name/alias | Small instruction mismatch | 105 |
| `init_lpfilter` | 160 | `init_lpfilter` — `turoksnd/abi/drvrNew.c:92` | Existing name/alias | Larger mismatch; cause unproven | 140 |
| `alFxNew` | 1084 | `alFxNew` — `turoksnd/abi/drvrNew.c:115` | Existing name/alias | Symbol/data relocation blocker | 8403 |
| `alSynAllocFX` | 152 | `alSynAllocFX` — `turoksnd/abi/synallocfx.c:23` | Existing name/alias | Larger mismatch; cause unproven | 400 |
| `alMainBusPull` | 288 | `alMainBusPull` — `turoksnd/abi/mainbus.c:24` | Existing name/alias | Larger mismatch; cause unproven | 425 |
| `alRaw16Pull` | 940 | `alRaw16Pull` — `turoksnd/abi/load.c:210` | Existing name/alias | Larger mismatch; cause unproven | 16247 |
| `func_800AE5C0` | 300 | Not located | Not located | Larger mismatch; cause unproven | 4534 |
| `alAdpcmPull` | 1184 | `alAdpcmPull` — `turoksnd/abi/load.c:41` | Existing name/alias | Larger mismatch; cause unproven | 17859 |
| `alResamplePull` | 520 | `alResamplePull` — `turoksnd/abi/resample.c:34` | Existing name/alias | Larger mismatch; cause unproven | 3619 |
| `func_800AF084` | 464 | Not located | Not located | Larger mismatch; cause unproven | 6174 |
| `func_800AF254` | 664 | Not located | Not located | Symbol/data relocation blocker | 12682 |
| `func_800AF4EC` | 176 | Not located | Not located | Larger mismatch; cause unproven | 110 |
| `alEnvmixerPull` | 1352 | `alEnvmixerPull` — `turoksnd/abi/env.c:75` | Existing name/alias | Symbol/data relocation blocker | 19853 |
| `alAuxBusPull` | 216 | `alAuxBusPull` — `turoksnd/abi/auxbus.c:24` | Existing name/alias | Larger mismatch; cause unproven | 310 |
| `osDestroyThread` | 248 | Not located | Not located | Larger mismatch; cause unproven | 2677 |
| `func_800AFDD0` | 44 | Not located | Not located | Small instruction mismatch | 245 |
| `func_800AFE00` | 236 | Not located | Not located | Larger mismatch; cause unproven | 1515 |
| `__osResetGlobalIntMask` | 88 | Not located | Not located | Small instruction mismatch | 324 |
| `func_800AFF50` | 76 | Not located | Not located | Larger mismatch; cause unproven | 695 |
| `osYieldThread` | 76 | Not located | Not located | Larger mismatch; cause unproven | 508 |
| `_Litob` | 664 | Not located | Not located | Larger mismatch; cause unproven | 7841 |
| `gl_func_00073904` | 1384 | `CCamera__Code_CINEMATIC_TREX_KILL_TUROK` — `tengine/cinecam.c:1019` | Tentative candidate | Larger mismatch; cause unproven | 13499 |
| `_Ldtob` | 1356 | `CCamera__Code_CINEMATIC_TREX_KILL_TUROK` — `tengine/cinecam.c:1019` | Tentative candidate | Larger mismatch; cause unproven | 16707 |
| `func_800B0F18` | 76 | Not located | Not located | Small instruction mismatch | 20 |
| `alSeqNextEvent` | 388 | `alSeqNextEvent` — `turoksnd/abi/seq.c:93` | Existing name/alias | Larger mismatch; cause unproven | 3367 |
| `alSeqNewMarker` | 288 | `alSeqNewMarker` — `turoksnd/abi/seq.c:218` | Existing name/alias | Small instruction mismatch | 4 |
| `__alSeqNextDelta` | 88 | `__alSeqNextDelta` — `turoksnd/abi/seq.c:191` | Existing name/alias | Small instruction mismatch | 350 |
| `func_800B1398` | 80 | Not located | Not located | Larger mismatch; cause unproven | 420 |
| `func_800B13E8` | 48 | Not located | Not located | Small instruction mismatch | 20 |
| `alSeqNew` | 216 | `alSeqNew` — `turoksnd/abi/seq.c:36` | Existing name/alias | Larger mismatch; cause unproven | 338 |
| `_filterBuffer` | 184 | `_filterBuffer` — `turoksnd/abi/reverb.c:307` | Existing name/alias | Larger mismatch; cause unproven | 937 |
| `_saveBuffer` | 392 | `_saveBuffer` — `turoksnd/abi/reverb.c:271` | Existing name/alias | Larger mismatch; cause unproven | 4807 |
| `_loadBuffer` | 396 | `_loadBuffer` — `turoksnd/abi/reverb.c:234` | Existing name/alias | Larger mismatch; cause unproven | 4571 |
| `_loadOutputBuffer` | 548 | `_loadOutputBuffer` — `turoksnd/abi/reverb.c:184` | Existing name/alias | Larger mismatch; cause unproven | 2976 |
| `alFxParamHdl` | 604 | Not located | Not located | Larger mismatch; cause unproven | 2060 |
| `alFxPull` | 832 | `alFxPull` — `turoksnd/abi/reverb.c:57` | Existing name/alias | Larger mismatch; cause unproven | 1892 |

## Evidence and limits

The audit reads a consistent copy of the app database, the supplied original source and its accompanying engine object files. It combines existing aliases, source-body lookup, normalized object comparisons, neighbouring object-order anchors and distinctive direct-call sequences. These methods locate likely counterparts but do not establish that an archived object was built from the exact source revision shipped in retail. Source line layouts were preserved; compiler profiles, target boundaries, hashes and byte/data gates were not changed.

All 294 saved drafts were compiled with the snapshot compiler profiles and per-unit context. Replay used the preserved private fixes for ELF relocation-table-order pairing and special section indexes. No source preparation, permutations, full-ROM builds or app writes were performed for this audit. The earlier full-cartridge verification still applies to the committed checkpoint, not to these unmatched drafts.

The 15 isolated-match export fallbacks are a separate integration backlog, listed in [checkpoint provenance](SOURCE_ASSISTED_CHECKPOINT.md#source-assisted-integration-30-october-2026); they are not part of these 294 open functions. The 59 assembly-classified candidates also remain outside this audit.

Private reproducibility files: `snapshot.db`, `inventory.json`, `mapped-audit.json`, `replay.json`, logs and the mapping/replay scripts under `.local/source-audit-20261030/`. No ROM, reference-source copy, original object file or database is included in this report.
