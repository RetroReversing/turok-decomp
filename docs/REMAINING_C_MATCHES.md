# Matching the four remaining recovered C candidates

All four candidates passed the live app's ordinary exact linked byte/data judge on 4 November 2026. Source-assisted provenance applies: the archived source was consulted, while the retail ROM remained the byte authority. No target bytes, boundaries or expected cartridge hashes were changed in this session.

| Entry | Located routine | Bytes | What resolved the mismatch |
| --- | --- | ---: | --- |
| `func_80052BCC` | `CTMove__UpdateTurokInstance` | 7,932 | Reconstructed the retail condition that disables the map when the player is dead, without the extra cinema-mode test present in the archive. Resolved missing call/text symbols against the aligned retail instructions. |
| `func_80075254` | `AI_Advance` | 4,036 | Compiled the original agitation helper together with its caller using a function-only IDO 5.3 `-O3` profile. This reproduces retail inlining, stack layout and scheduling. The helper independently matches the existing 28-byte `func_80074DCC`; it supplies verified compiler context and is not a newly discovered function. |
| `func_800915C4` | `CPickup_Pickup` | 6,860 | Restored the archive's `WeaponPowerOrder` enum, text declarations and retail text addresses. The function body itself required no behavioral change. |
| `func_80096A74` | `DoDrawMap` | 6,604 | Restored the retail guard around the animated-enemy map pass: `GetApp()->m_dwCheatFlags & (1UL << 28)`. The archived source runs this pass unconditionally. Resolved vertex-array and remaining call addresses against the aligned retail instructions. The flag's original name is not established by this match. |

**Added: 25,432 exact C bytes across four entries.** All eleven formerly truncated C candidates are now matched at their full reviewed extents. The selected compiler/profile reproduces these bytes; it does not independently establish the identity of the historical compiler installation.

The live app now reports **2,364 exact C entries / 692,344 bytes**, **41 assembly-status entries / 8,180 bytes**, and **zero open entries**, against **700,524 detected bytes**: **98.8323% exact C by detected bytes**. Assembly evidence has several strengths; the 41 entries must not all be described as fresh verified assembly rebuilds. See [the assembly audit](ASSEMBLY_ENTRY_AUDIT.md).

This is not proof that every retail function has been discovered. The [raw-region audit](CODE_RECOVERY_AUDIT.md) still has additional review leads and an explicitly capped packed/assets interval. An exact cartridge build preserves unselected data and code, so cartridge equality and complete source reconstruction remain separate claims.

## Verification and synchronization

Each new source was promoted through the authenticated live source-preparation API with score zero and an exact verdict. All four saved source files were compared with their live accepted sources; saved-progress synchronization completed. Repository synchronization independently checked all four in the standalone build before performing its complete cartridge comparison. Required contexts and the function-only compiler profile travel with their accepted sources.

## Lessons

- Recover full boundaries before judging completion: a tiny prefix can hide a substantial C function.
- Compare control flow before spending CPU on permutations. Two archived routines differ behaviorally from the retail version, so permutations of the untouched archive cannot fix them.
- A missing declaration or symbol can dominate the score even when the generated instructions already align.
- Inlining needs the real helper body and the right optimization profile. Expanding its expression manually produced the right instruction count but different registers and stack layout; independently verified compiler context reproduced the retail bytes.
