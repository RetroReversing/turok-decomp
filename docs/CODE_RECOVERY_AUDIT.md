# Reviewed code recovery and raw-region audit

## Scope and result — 4 November 2026

The eleven assembly-status fragments identified in [the assembly audit](ASSEMBLY_ENTRY_AUDIT.md) were reviewed and expanded through the live app's authenticated recovery API. Their original prefixes were unchanged. A private Splat run retained exactly the reviewed extents, with every instruction byte checked against the frozen expanded ROM. Recovery reopened these entries as C candidates; it did not infer matches.

Together the full extents cover **74,612 bytes**, replacing 100 bytes of fragments: **74,512 additional detected bytes**. The detected denominator therefore rises from 626,012 to **700,524 bytes**. The standalone build layout now assigns these tails to their code parents instead of overlapping raw binary segments. No cartridge bytes or expected hashes changed.

Original source/object evidence informed boundary review. The direct-flow scanner and demo corruption benchmark below did not consult game source to discover candidates.

| Entry | Reviewed full bytes |
| --- | ---: |
| `func_80016CE8` | 4,644 |
| `func_80022148` | 5,752 |
| `func_8002E4EC` | 4,760 |
| `func_80052BCC` | 7,932 |
| `func_80059994` | 3,232 |
| `func_8005B964` | 3,928 |
| `func_8006BC88` | 20,672 |
| `func_80075254` | 4,036 |
| `CPause__DrawBar` | 6,192 |
| `func_800915C4` | 6,860 |
| `func_80096A74` | 6,604 |

## Verified source-assisted matches after recovery

Seven full functions passed the live app's ordinary exact linked byte/data judge and were saved with their required private headers and function compiler settings:

| Entry | Located source routine | Matched bytes |
| --- | --- | ---: |
| `func_80016CE8` | `CGameObjectInstance__DoDraw` | 4,644 |
| `func_80022148` | `CGeometry__Decompress` | 5,752 |
| `func_8002E4EC` | `CScene__DrawSky` | 4,760 |
| `func_80059994` | `CTMove__FireBullet` | 3,232 |
| `func_8005B964` | `CTMove__ControlSwimMovement` | 3,928 |
| `func_8006BC88` | `AI_Single_Event` | 20,672 |
| `CPause__DrawBar` | `CPause__DrawBar` | 6,192 |

This adds **49,180 verified C bytes**. The app now has **2,360 matched entries / 666,912 bytes** out of **700,524 detected bytes (95.2019%)**, with four open C candidates and 41 assembly-status entries (8,180 bytes). The lower percentage than the earlier fragment-based result reflects the corrected denominator.

The four still-open recovered candidates are `func_80052BCC` (`CTMove__UpdateTurokInstance`), `func_80075254` (`AI_Advance`), `func_800915C4` (`CPickup_Pickup`) and `func_80096A74` (`DoDrawMap`). Their full boundaries are recovered; their C is not yet accepted. Prepared candidates still need declaration/symbol work or instruction-level matching. They must not be counted as finished assembly or matched C.

## Every raw interval was scanned

These are the **pre-recovery** raw intervals. Candidates are review leads, not proven independent functions or automatically imported code. Each interval was scanned independently so a busy interval could not hide results from the others.

| ROM start | ROM end (exclusive) | Bytes | Review leads | Candidate cap reached |
| --- | --- | ---: | ---: | --- |
| `0x1EC0` | `0x802000` | 8,388,928 | 128 | Yes |
| `0x809390` | `0x80A738` | 5,032 | 1 | No |
| `0x8179F0` | `0x818C0C` | 4,636 | 1 | No |
| `0x822E50` | `0x8265D0` | 14,208 | 7 | No |
| `0x826810` | `0x8277D0` | 4,032 | 1 | No |
| `0x829670` | `0x82A710` | 4,256 | 1 | No |
| `0x82F1F0` | `0x830484` | 4,756 | 1 | No |
| `0x8538D0` | `0x8557C8` | 7,928 | 1 | No |
| `0x85A6A0` | `0x85B334` | 3,220 | 1 | No |
| `0x85C670` | `0x85D5BC` | 3,916 | 1 | No |
| `0x862EA0` | `0x864330` | 5,264 | 1 | No |
| `0x86C990` | `0x871A48` | 20,664 | 1 | No |
| `0x875F60` | `0x876F18` | 4,024 | 1 | No |
| `0x886700` | `0x887F28` | 6,184 | 2 | No |
| `0x8922D0` | `0x893D90` | 6,848 | 1 | No |
| `0x897780` | `0x899140` | 6,592 | 1 | No |
| `0x8B69D0` | `0x8F9DD0` | 275,456 | 0 | No |

The first large interval includes the preserved packed cartridge and assets in the expanded analysis image. It reached the 128-candidate cap, so that interval remains incomplete; its byte size must not be interpreted as missing executable code. The final raw tail produced no CPU-code leads, which is not proof that it contains no code.

Ten further candidate starts lie outside the eleven recovered extents: `80008690`, `800237C0`, `80023824`, `8002383C`, `800239C0`, `80023FF8`, `80024594`, `80025B10`, `80028970`, and `800621A0`. Some contain unresolved indirect control flow. They require independent boundary/code-versus-data review and new-entry import support; this recovery endpoint only extends existing entries. Whole-game completion is therefore still unproven.

## Source-independent discovery benchmark

The complete demo ELF supplied 96 ground-truth functions. A deterministic size-spread sample of 24 functions was tested in three damaged layouts: entirely hidden, truncated to one instruction, and truncated while marked assembly. The audit received the ROM and damaged layout, without the withheld function symbols or source.

| Damage | Detected | Cases |
| --- | ---: | ---: |
| Hidden function | 24 | 24 |
| Truncated function | 24 | 24 |
| Truncated and misclassified assembly | 24 | 24 |

Across these 72 cases, no candidate started outside a ground-truth function body, and no search limit was reached. Detection includes a boundary warning or continuation lead; it does not establish exact function boundaries or a C match. This small, deliberately constructed benchmark is a regression check, not a guarantee for arbitrary retail games.

The live repository-sync job verified and published all seven new matches with no skipped candidates, together with verified updates to four already matched functions. The complete repository build passed the cartridge comparison. Saved progress was checked independently: all eleven full sizes and all seven accepted source files persisted, and progress synchronization finished.
