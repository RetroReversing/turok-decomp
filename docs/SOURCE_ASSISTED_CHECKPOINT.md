# Source-assisted checkpoint

The user authorized publishing the combined source-assisted checkpoint on 24 October 2026.

User-authorized source-assisted Sol trial: 1,563 selected C functions, 243,836 matching bytes / 626,012 detected candidate-code bytes (38.950691%). Gain over the ROM-only baseline: 677 functions / 182,000 bytes. Original source and headers were reused; this is not a ROM-only decompilation result.

All 792 raw additions passed independent per-function checks; 115 candidates totaling 39,200 bytes were excluded for data layout. The final 1,563 C / 2,405 function export used 842 assembly functions and no fallback selections. Expanded image, normalized cartridge, and pair-swapped user ROM were byte-identical. Normalized SHA-1: 88916d5d2e2470f395ad8f4245d34138ef2d156a.

Private experiment and provenance: /Volumes/Data/Decomps/nintendo-64/turok-europe-ai/experiments/sol-source-assisted-30min-20261023. Verification completed 2026-10-23T23:27:35.640Z.

## Combined verified checkpoint

The 24 October combined selection contained 1,798 C functions and 363,040 matching bytes / 626,012 detected candidate-code bytes (57.99249855%). It combines the verified Astra Low 1,763-function baseline with all 35 distinct gains from the subsequent same-checkpoint trials. Sol High supplied 29 gains; Sol Low supplied five additional functions (2,088 bytes); Astra High supplied one additional function (1,364 bytes). Luna Low's sole match was already present; Luna High added none.

All six additions beyond Sol High passed fresh isolated checks in the merged workspace. The complete merged expanded image, normalized original cartridge, and reconstructed user input byte order were byte-identical. Export selected 1,798 C functions / 2,405 total, with 607 assembly functions and no automatic fallbacks. Cartridge SHA-1 remains 88916d5d2e2470f395ad8f4245d34138ef2d156a. This verifies code selection, not full decompilation or portability.

Private integration evidence: /Volumes/Data/Decomps/nintendo-64/turok-europe-ai/experiments/combined-verified-20261024 (merge-provenance.json, export-result.json, cartridge-verification.json, workspace/). C and headers copied into this checkout are byte-identical to that passing export. The user subsequently authorized pushing this combined checkpoint. Local binary inputs and research evidence remain private.

## Workspace consolidation

The main checkout is /Volumes/Data/Decomps/nintendo-64/turok-decomp. Private build inputs and the compact active analysis workspace are retained under ignored paths in this checkout. Per-run reports, score summaries and verification records are preserved in .local/evidence/; duplicate per-run workspaces have been removed. Historical absolute paths above identify where the experiments originally ran.


## Compiler and export repair: 28 October 2026

The live app had 1,959 green functions, but its global compiler had changed to IDO 5.3 -O1. Independent replay found that 1,433 needed the proven -O2 profile instead. The repair restores -O2 as the broad profile and retains individually verified range exceptions. Every green function was recompiled; one stale function-definition name was canonicalized. Saved open-candidate scores were recalculated with the repaired profiles without discarding their C or attempt history.

Six additional saved candidates passed fresh linked-byte checks, adding 1,432 bytes: func_800A2054, func_8001E890, func_800AD8CC, func_800145DC, func_8003433C and func_80034FD4. Four other saved candidates defined neighbouring functions as well as their target. Those extra bodies were replaced by declarations, preserving target bodies and line layout; all four still passed.

The first complete export exposed a separate integration problem. Standalone compiler-owned constant pools had preferred 16-byte ELF alignment, while their judge-proven original bases sometimes fell inside that alignment. The linker rounded those bases, changing relocation operands. The generated build now places these NOLOAD pools at their verified original addresses with SUBALIGN(1). Original data remains in the ROM-derived data objects; constants, target bytes, hashes and the linked-byte judge are unchanged. A real MIPS linker regression test verifies the exact constant address and encoded load operand. Non-contiguous data placements remain unsupported and must fall back to assembly.

A conservative intermediate build selected 1,940 C functions and used 25 explicit alignment fallbacks; it reproduced the cartridge exactly. With the constant-pool fix, the final export selected all **1,965 C functions / 396,464 bytes (63.3316933222% of 626,012 detected candidate-code bytes)** with **zero automatic fallbacks**. The expanded image and final cartridge passed the fixed comparisons. Original cartridge SHA-1 remains **88916d5d2e2470f395ad8f4245d34138ef2d156a**. The 2,407 export entries include two padding labels; these do not count as new functions recovered by this repair.

The six fresh matches are separate from the older live-app work incorporated into this checkout: the standalone selection rises from 1,798 to 1,965, but this repair did not newly discover all 167 functions. The app now permits source-assisted matching as well as polishing. Private reference headers correct the archive's debug PARTICLES_MAX_COUNT from 2 to the retail value 128; the original archive is read only. Provisional source-location notes and data-placement follow-ups guide the remaining work. This remains an unfinished, source-assisted decompilation.

App fixes were committed locally as cc9e2d2 in RetroReversing/decompdecomp. Private repair evidence and backups are under /Volumes/Data/Decomps/.turok-repair-20261028; ROMs, original reference headers, databases and evidence are not committed. No changes were pushed as part of this repair.


## Source-assisted integration: 30 October 2026

This checkpoint integrates the latest verified standalone selection: **2,036 C functions / 445,672 bytes**, **71.1922455161% of the fixed 626,012 candidate-code bytes**, with **371 assembly entries out of 2,407 build entries**. It replaces the earlier 1,965-C selection, 81 newly selected addresses and 10 older C selections replaced by assembly, a net increase of 71 selected functions. Some older selections are conservatively replaced by assembly where the latest export could not verify them; this is not a claim that all 71 were discovered in one session. Original source and headers were reused throughout this work.

The one-hour session ran **18:07:26–19:07:26 UTC on 30 October**. Its live baseline was 2,018 isolated matches / 427,808 bytes; the ending snapshot had **2,051 / 455,372 bytes**: **33 new exact matches / 27,564 bytes**. All 33 were read back and independently recompiled and linked with initialized-data checks. The app rose from **69.4291% to 73.9024%**, using 616,180 candidate C bytes; the fixed-total ending figure is 72.7417%. Two matches made before the timed baseline are excluded from the session gain. Other background workers were active, so their draft improvements are not attributed to this session.

The live checkpoint retains 296 open candidates and 59 assembly candidates. Its isolated-match count is distinct from the standalone C count. Fifteen isolated matches fall back during export:

- Replay mismatch: `func_800016A4`, `func_80026DC0`, `func_80039030`, `func_80049BE0`, `func_8004F884`, `func_80057B58`, `func_8005F100`, `func_80071B18`, `func_80076218`, `AI_Standard_Idle`.
- Unsupported owned-data placement: `func_800036B0`, `func_800587B8`, `func_8008CD1C`, `func_8008CFC0`, `func_80095AD0`.

The first and last data-placement entries were new in the one-hour session: **31 of its 33 matches are selected C here**. Assembly fallback preserves the target; it is not recovered C. Improved but unmatched drafts remain private and are not selected.

### Repairs that unlocked matches

- Restored graphics macros that declarations-only source preparation had mistaken for function bodies.
- Preserved file-owned globals and original inline wrappers, whose treatment changes IDO scheduling and address generation.
- Corrected particle-deletion arguments and SDK parameter types from source and ROM evidence.
- Recovered retail differences: 400 matrices per half, and crash-report build 50 dated January 20, 1997. An additional engine word is retained without inventing its gameplay meaning.

### Build and verification

The generated builder now handles one observed IDO discarded-inline prefix: an unreferenced `jr ra; nop` before the named function entry. It removes only that exact prefix, rebases supported internal references, and rejects unknown forms. It also omits `.rel.dyn` from binary extraction only when every entry is `R_MIPS_NONE`; real dynamic relocations remain an error. Neither change alters target bytes or comparison gates. Source and header line layout and whitespace are preserved from the passing export because formatting can affect period-compiler scheduling. Current compiler ranges and symbol names come from the verified app export; the broad IDO 5.3 -O2 profile remains unchanged.

Independent function replay used a private repaired decompdecomp library that preserves ELF relocation-table order when pairing HI16/LO16 relocations and ignores invalid special section indexes in function-symbol discovery. These verification-library changes are not installed into the running app by this commit. The checked-in standalone builder contains the export fixes needed by this selection.

The full expanded-image and reconstructed-cartridge comparisons passed. The original cartridge is **8,388,608 bytes**, SHA-1 **88916d5d2e2470f395ad8f4245d34138ef2d156a**. This remains an unfinished source-assisted decompilation, not a portable game or complete C recovery.

Private evidence is under `.local/sol-hour-20261030/`: `RUN-REPORT.md`, `independent-new-matches.json`, `final-export-result.json`, `final-export.log`, and `commit-build.log`. ROMs, databases, generated assembly/assets, proprietary tools and private research evidence are excluded from the commit.


## Source naming and three-function repair: 30 October 2026

The follow-up audit inventoried 294 open functions and located 121 source-candidate entries, including tentative/conflicting identities. The [source symbol index](SOURCE_SYMBOLS.md) records every located candidate and its alternatives. Twenty-one address-based function names were changed in the standalone project using source and ROM evidence, with original addresses retained. Existing SDK canonical spellings remain unchanged. Ambiguous candidates were not promoted into conflicting canonical symbols. Identifier replacement preserves comments, string literals, whitespace and line counts. A duplicate provisional `void *` particle-system declaration was removed in two contexts in favour of the existing typed declaration, preserving line positions.

All three shortlisted functions now pass the corrected private byte/data judge and have also been accepted normally by the running app:

| Original symbol | Canonical source symbol | Bytes | Decisive repair |
| --- | --- | ---: | --- |
| `func_8002AB68` | `CParticle__Advance` | 1,148 | Reconstructed an inline magnitude helper with four bytes of unused local scratch storage and removed the main function's unused vector. This places the two magnitude spills at the retail stack offsets. |
| `func_8007791C` | `AI_Standard_Follow` | 536 | Restored the typed source context and the original helper signature `IsPlayerAlive()`. An otherwise identical `IsPlayerAlive(void)` reproduces the stack mismatch. |
| `alSeqNewMarker` | `alSeqNewMarker` | 288 | Restored the full event record and SDK body, added the retail marker `curTicks` updates, and preserved separate source lines for the zero assignments. |

These are matching reconstructions; the scratch/helper spelling is not proof of the exact original source text. Compiler profiles, original target bytes, boundaries and comparison gates were unchanged.

### Controlled compiler observations

Follow's helper was replayed in a two-by-two check: `()` versus `(void)`, each with a one-line or multiline body. Both `()` versions matched exactly; both `(void)` versions scored 14 under the typed source context. The decisive difference here is the C function signature, not line breaks. This corrects the initial interpretation during the repair.

For the sequence marker, the private replay of the adapted SDK body differed only in the ordering of two zero stores. Keeping `m->lastTicks = 0;` and `m->curTicks = 0;` on separate source lines produced an exact match. The supplied archive's older body omitted the `curTicks` updates. The later implementation in [n64decomp/libreultra](https://github.com/n64decomp/libreultra/blob/master/src/audio/seq.c) provides corroborating SDK revision evidence; the reconstruction starts from the supplied local archive and ROM-derived layout.

### App acceptance and standalone verification

Particle advance initially exposed the installed app's older HI16/LO16 relocation pairing issue. Expressing the verified retail cheat-flags address as `extern u32 D_801195EC` preserves the exact linked bytes and passes both judges. Particle advance and the sequence marker were accepted through the normal attempt API. Follow's verified private typed header, including its helper, was promoted through the app's normal source-preparation pass. Previous preparation settings were restored afterwards. No app restart was required.

The live app retains the address-based names for particle advance and follow; their canonical source names are applied in this standalone checkout. No direct live-database renames were performed. The source-symbol index distinguishes verified project names from tentative candidates rather than treating all 121 source leads as established identities.

The standalone selection is now **2,039 C functions / 447,644 candidate-code bytes (71.5072554520% of the fixed 626,012-byte total)**, with **368 assembly entries out of 2,407 entries**. This repair adds **three C functions / 1,972 bytes** over the 2,036-C checkpoint. The complete 8,388,608-byte cartridge rebuilt byte for byte, SHA-1 **88916d5d2e2470f395ad8f4245d34138ef2d156a**. A fresh splat extraction using the renamed symbol map also produced every function-assembly path required by the manifest.

The live snapshot has **2,056 isolated matches / 459,016 bytes, 291 open candidates and 59 assembly candidates**. These remain separate from the standalone C selection. Two background matches had arrived before this repair's baseline; they are not credited to these three fixes or newly selected in this checkout.

Before the decisive source repairs, separate five-minute app permutation passes tested 164 Follow and 102 marker candidates with no improvement. That result is retained in the evidence rather than attributed to the final manual repairs. All jobs started for this repair have completed.

Private candidates, diagnostics, normal app acceptance, rename planning and complete build/extraction logs are under `.local/three-stack-fixes-20261030/`. No ROMs, databases, reference objects or private research inputs are included in the tracked changes.
