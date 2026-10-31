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

## Source-assisted SDK and handler recovery — 31 October 2026

This pass selects **15 additional C functions / 744 bytes**, bringing the selection to **2,054 C functions / 448,388 bytes (71.626103014% of the fixed 626,012-byte candidate-code total)**. There are **353 assembly entries among 2,407 build entries**. The gain is **0.118848 percentage points**; twelve new functions are only 16 bytes each. The complete 8,388,608-byte cartridge rebuilt byte for byte, SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. The final build used four compiler workers and a short temporary directory on the Data volume after earlier disk-space and interruption failures; compiler options and comparison gates were unchanged.

| Recovery | Functions | Bytes | Decisive change |
| --- | ---: | ---: | --- |
| `__cosf` | 1 | 360 | Restored the archived SDK body's local declarations and expression order, using ROM-addressed constants. This resolved floating-point register allocation differences. |
| `alSndpGetState` | 1 | 32 | Restored a typed, 48-byte sound-state record and array indexing instead of anonymous byte-pointer arithmetic. |
| `alCSeqGetLoc` | 1 | 160 | Restored typed sequence and marker records and the original 16-track loop; the compiler produced the retail unrolling. Recovered after the planned matching window, during build troubleshooting. |
| Identical event-handler stubs | 12 | 192 | A typed three-float argument plus an empty condition on the first parameter reproduced the three argument stores. Identical bodies do not establish unique handler names; address names are retained. |

The supplied local source archive was consulted. These are matching reconstructions, not proof of the original C spelling. Original target bytes, boundaries, compiler profiles and comparison gates were preserved. Each candidate passed independent compilation and linked-byte/data checks before selection.

An earlier live-app snapshot changed from **2,056 isolated matches / 459,016 bytes** to **2,070 / 459,600 bytes**, with **277 open** and **59 assembly** candidates, before the final SDK recovery. These are historical app measurements; background rechecks can change the live counts independently of the standalone selection. Background workers were active: six handler candidates were accepted directly during this pass, and the remaining six were already matched or claimed when acceptance was attempted. All three SDK functions were accepted directly through the normal app API. All fifteen independently verified sources are selected in the standalone build; the live increase should not be credited wholly to foreground work.

The requested matching window started at 08:47 UTC and targeted 09:47 UTC. Verification and integration continued later. This session was not measured as an uninterrupted hour of model computation and should not be used as a controlled model/cost benchmark. Private candidates, diagnostics, app acceptance and build logs remain under `.local/sol-hour-20261031/`.


## Thirty-minute source-assisted continuation — 31 October 2026

The matching window ran from **12:35:15 to 13:05:15 UTC**; final integration and cartridge verification continued afterwards. Relative to `df9d440`, this checkpoint adds **12 selected C functions / 7,280 bytes**, reaching **2,066 C functions / 455,668 bytes (72.789020019% of the fixed 626,012-byte candidate-code total)**. This is a gain of **1.162917 percentage points**. There are **341 assembly entries among 2,407 build entries**; these figures do not imply a complete decompilation.

### Six new recoveries or repairs

| Function | Bytes | What resolved the mismatch |
| --- | ---: | --- |
| `alSndpDeallocate` | 80 | Restored the SDK's typed, 48-byte sound-state record and array indexing. |
| `alEvtqNextEvent` | 140 | Restored typed queue links, the 16-byte event and the original control flow. |
| `func_8002DEF0` | 176 | Reconstructed `CHashTable__NewAssoc` with its inline allocation helper and pointer return. The final source needs no artificial scratch array. |
| `func_8002D950` | 40 | Restored the inline size helper followed by header-size subtraction. This reproduces the otherwise unexplained `addiu ..., 0` instruction. Its address name remains pending a separate symbol review. |
| `func_80039030` | 236 | Replaced a guessed angle increment with the exact retail constant `0.19198621771937624`. The previous draft's instructions matched but its owned constant differed from the ROM. |
| `func_80093D48` | 144 | Restored the typed `COptions__SetDefaults` source context, using the retail opacity value of 184. The archived body used 255. |

These six total **816 bytes**. Four were submitted and accepted through the app's normal attempt API: the SDK pair, the hash allocator and the inline-size routine. The angle-constant and options repairs are selected in the standalone checkout; this session did not promote their separate prepared contexts into the running app.

### Six existing app matches integrated into the standalone build

The live app already held exact instruction drafts for the following **6,464 bytes**. They are carried-over work, not six additional foreground discoveries:

| Function | Bytes |
| --- | ---: |
| `func_800036B0` (`CEngineApp__DrawGAME` candidate) | 1,736 |
| `func_8001EB64` | 844 |
| `func_80034BA0` | 828 |
| `func_8008CD1C` | 676 |
| `func_8008CFC0` | 692 |
| `func_80095AD0` (`printFaultData` candidate) | 1,688 |

Each source was independently recompiled and linked with the corrected private judge. Placement repairs keep shared ambient-audio tables at their verified ROM addresses and preserve the functions' private static state. Duplicate format strings were bound to their individual verified ROM copies. Shared data remains provided by the existing data assembly, rather than being duplicated inside each function's C object. Original targets, compiler profiles and comparison gates were unchanged.

`func_800587B8` remains deferred: it matches in isolation, but its constant pool cannot yet be exported at one proven section base. A separate six-minute local permutation search on particle drawing tested 342 variants, skipped 39 and retained no improvement; it is not counted as a recovery.

### Verification

The final build uses all **2,066 C selections** and rebuilds the complete **8,388,608-byte cartridge byte for byte**, SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. The earlier full build recompiled the existing selection; the final build compiled the changed objects, regenerated assembly runs and relinked the whole image using unchanged objects from that passing build. Four compiler workers and temporary storage on the Data volume were used. Private trials, acceptance results, placement evidence and build logs are under `.local/sol-halfhour-20261031-1235/`.


## Focused thirty-minute continuation — 31 October 2026

The previous checkpoint was committed and pushed as `4082329` before this pass. The allocated matching window was **13:25:30–13:55:30 UTC**; integration and final verification continued afterwards. This is source-assisted work using the authorized archive, existing app drafts and the ROM, rather than a controlled model/cost benchmark.

This checkpoint adds **11 selected C functions / 5,696 bytes**, moving from **2,066 / 455,668 bytes (72.789%)** to **2,077 / 461,364 bytes (73.698906730% of the fixed 626,012-byte candidate-code total)**. The gain is **0.909887 percentage points**. There are **330 assembly entries among 2,407 build entries**. These are standalone build figures, not a claim that the live app has accepted all eleven repairs.

| Recovery or repair | Functions | Code bytes | What resolved it |
| --- | ---: | ---: | --- |
| `AI_Standard_Idle`, `func_80076218` | 2 | 1,600 | Their instruction bodies and table values already matched. Representing the verified adjacent ROM word as a C datum established the correct end of the constant pool, instead of treating compiler padding as owned game data. |
| `func_80049BE0`, `func_8004F884`, `func_80057B58`, `func_80026DC0`, `func_8005F100`, `func_80071B18` | 6 | 1,848 | Existing instruction drafts had incorrect switch selectors. Reconstructed the C case labels from the retail jump tables, preserving the block bodies. Both instructions and owned data now match. |
| `func_800894B0` | 1 | 824 | Bound the typed audio initializer to verified retail globals and segment symbols. Distinct linker labels at the same address must remain distinct C symbols to reproduce register allocation. |
| `func_80008060` | 1 | 524 | Bound the graphics-task source to the retail microcode/runtime symbols and used the retail command FIFO size of **128 KiB**, versus 64 KiB in the supplied archive. |
| `ScanFileList` (`func_800113A8`) | 1 | 900 | Bound the Controller Pak file-state record correctly and restored the retail eight-byte copy on the invalid-pack path; the archived version used a formatting call. |

The first eight are repairs to existing drafts or their data ownership, not eight entirely new instruction-body discoveries. The constant-pool repair represents the actual neighbouring words (`D_800BE5EC = 1` and `D_800BE06C = 3`); it does not establish the original source spelling. The switch repairs change C selectors, not target jump-table bytes. Three verified linker aliases preserve distinct source labels at shared addresses. Original targets, compiler profiles, boundaries and comparison gates remain unchanged.

### Verification and remaining leads

Each accepted candidate passed independent compilation and the corrected private linked-byte/data judge before selection. A full build recompiled all 2,076 selections after the first ten additions and reproduced the original cartridge. The final build retained those unchanged verified objects, compiled `ScanFileList`, regenerated assembly runs and relinked the complete image. All **2,077 selected C objects** are present in the final link. The expanded-image and reconstructed-cartridge comparisons pass: the complete **8,388,608-byte cartridge** is byte identical, SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`.

`func_800587B8` remains excluded despite an isolated match because its constant pool still lacks one proven exportable section base. Particle drawing improved in private trials but did not reach an exact match. Neither is counted as a recovery. The remaining mismatch work increasingly concerns compiler context, data layout and differences between the archive and retail revision; possession of source alone does not settle these.

Private candidates, jump-table proofs, symbol bindings, integration reports and build logs are under `.local/sol-focused-20261031-1325/`. Local binaries, databases, generated assembly/assets and proprietary research inputs remain excluded from Git.


## App/repository synchronization audit — 31 October 2026

The audit initially found 21 cartridge-verified repository selections still open in the app, including the three larger recoveries from the focused session. Initial promotion and matched-source repairs passed, but a saved-progress revalidation subsequently demoted many historical app matches. The repository's selected sources and byte-identical cartridge result were unaffected. Restoration was moved to the running app's authenticated API. Do not use a second engine writer against the live database: independent progress caches can race autosave. The standing project rule now requires checking saved files and contexts as well as database totals.

The API restoration tested 260 sources: 249 passed immediately. Ten further candidates exposed the installed app's older HI16/LO16 relocation pairing bug; one also needed its repository declarations. The corrected implementation preserves ELF relocation-table order rather than instruction order. All **11 remaining candidates pass code/data checks in an isolated replay** with that fix; nine focused relocation/data regression tests pass. After explicit restart approval, the tested relocation fix was installed. The working bundle preserves the previous installed app and its local customisations, replacing only `elfobj.py` and `rom/match.py`; its prepared copy is `/Volumes/Data/Codex/app-builds/turok-sync-minimal-20261031/decompdecomp.app`. All eleven candidates subsequently passed the live app judge; the sound-scene routine also received its verified repository declarations through the source-preparation API.

The current standalone selection remains **2,077 C functions / 461,364 bytes (73.699%)**. `func_800016A4` is excluded because its owned string data differs; `func_800587B8` is excluded because its constant pool still lacks one proven exportable section base. Neither may be copied into the build merely to equalize app and repository counts. Three remaining source-text differences are equivalent representations requiring contextual comparison: Follow keeps an inline helper in its app header; ambient sound uses named globals in the app; fault display uses literals where the standalone export binds the verified individual ROM copies.

Private synchronization reports, restoration logs and isolated replay evidence are under `.local/app-repo-sync-20261031/`. This synchronization changes no standalone C selections or target bytes.


### Completed persistence verification

The saved-file audit found 1,657 missing or outdated source files despite the manifest's matched records. With the app stopped, those files were materialized from its already-verified matched sources using read-only database access; saved headers were checked against the judged contexts. No database rows were edited by that recovery. The app was restarted and completed its normal saved-project revalidation: **2,078 matched functions, 291 best attempts, zero lost matches** (log completion **14:59:12 UTC**).

The final bidirectional audit finds **all 2,077 standalone C selections matched in the app**, with **zero missing saved sources/headers and zero saved-source/database discrepancies**. The app's one additional isolated match is `func_800587B8`; it remains excluded from the standalone build for the documented constant-pool placement reason. Three equivalent source representations remain as described above; these are not missing recoveries. The saved manifest is revision **396**, with all **2,078 matching C files** present.

The standalone cartridge was checked again after synchronization: all 2,077 selected C objects are in the link, the complete image remains byte identical, and SHA-1 remains `88916d5d2e2470f395ad8f4245d34138ef2d156a`. The app window was checked after restart and left open on Turok. App/database backups are under `/Volumes/Data/Codex/app-backups/turok-sync-20261031/`. Future checkpoints must pass both the live and saved-file audits, not merely report a database match count.


## Ten additional source-assisted matches — 31 October 2026

Starting from `401c373` (2,077 selected C functions / 461,364 bytes), this pass adds **10 selected C functions / 1,636 bytes**. The selection is **2,087 C functions / 463,000 bytes**, **73.960244%** of the fixed 626,012 candidate-code bytes, a gain of **0.261337 percentage points**. The other 320 build entries remain assembly. This is partial, source-assisted reconstruction, not a complete decompilation.

| Function | Bytes | IDO 5.3 optimization | Main repair |
| --- | ---: | --- | --- |
| `func_800016A4` | 444 | `-O2` | Typed eight-byte signature object copied into the local record, separating actual data from pool padding. |
| `func_80013DC8` | 156 | `-O3` | Archived vector clamp body and macros. |
| `func_8002D978` | 96 | `-O3` | Typed stream-set attach body and correct free prototype. |
| `func_8002DA9C` | 124 | `-O3` | Archived preallocation body, including inline setters' pointer locals. |
| `func_8002DCCC` | 92 | `-O3` | Typed indexed-set attach body. |
| `alSndpSetFXMix` | 88 | `-O3` | SDK event body and typed byte payload. |
| `alSndpSetVol` | 88 | `-O3` | SDK event body and typed short payload. |
| `alCSeqSetLoc` | 160 | `-O2` | Sequence/marker record layout and 16-track loop. |
| `alCSeqSecToTicks` | 252 | `-O2` | SDK expression with literal `1000000.0` and direct division-field access. |
| `alResampleNew` | 136 | `-O3` | Typed initializer and zero-store ordering. |

The authorized Turok and SDK source archives supplied the reference bodies. Seven functions require individually verified `-O3` profiles instead of the provisional broad `-O2` profile. Those exceptions cover only the seven functions' exact address ranges, and agree between the repository and app. Every previously selected C function retains its compiler profile. IDO 5.3 remains a working toolchain rather than proof of the original release. Four bounded app permutation searches under `-O2` found no improvements; they are not credited with these recoveries.

A separate standalone export fix accepts repeated unreferenced eight-byte `jr ra; nop` discarded-inline stubs before the sole function. The preallocation object contains two such stubs. Arbitrary instructions and relocations into discarded prefixes remain rejected; named prefixes remain intact. Synthetic MIPS-object checks cover these cases. Original function addresses, target bytes, cartridge hashes and comparison gates are unchanged.

The live app accepts all ten through its normal compile/link judge. A read-only audit finds all 2,087 selected functions matched in the app, with saved sources and headers present and saved source equal to the matched database source. Saved revision 408 contains 2,088 matches: the additional old `func_800587B8` is still excluded from standalone selection because its data placement is unresolved. Three pre-existing equivalent source/context representations remain documented differences. No extra writer was opened against the live database.

The complete expanded image and reconstructed 8,388,608-byte cartridge both pass their unchanged byte comparisons. Cartridge SHA-1 remains `88916d5d2e2470f395ad8f4245d34138ef2d156a`. All 2,087 C selections are retained with no new assembly fallback. Local ROMs, generated objects, databases and private evidence are excluded from Git.


## User optimization check — 31 October 2026

The user's live-app compiler check supplied ten additional exact matches / 14,728 bytes beyond `d9381c1`. Standalone integration selects 2,097 C functions / 477,728 bytes (76.313% of the fixed 626,012 candidate-code bytes). All ten passed standalone per-function checks with their saved app contexts and profiles. The 44 still-unmatched candidates with lower scores than the preceding checkpoint are preserved under `drafts/optimization-20261031`, with source, context, score and compiler profile; they are not selected C or credited as recovered bytes. These results precede the following live-API matching session and must not be attributed to that session.

The complete expanded image and reconstructed 8 MiB cartridge pass byte for byte, retaining SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. The particle draw routine uses an external reference to the original string to keep its numeric/jump-table pool contiguous; the live API verifies this equivalent representation at score zero without replacing its already-matched source.


## Ten-function live-API pass — 31 October 2026

After the user optimization checkpoint (`a7a06b6`), ten distinct unmatched functions were attempted directly through the running app's authenticated API. Candidate judging and history used `/api/function`, `/api/diff` and `/api/try`; no isolated analysis database or second live writer was used. Standalone checks were performed only to integrate accepted results into this repository.

| App function | Before score | After score | Result / repair |
| --- | ---: | ---: | --- |
| `guLookAt` | 5 | 0 | Correct SDK argument order. |
| `func_8002DB18` | 20 | 0 | Typed inline setters and their pointer locals. |
| `func_80019300` | 20 | 0 | Resolve glare color to target address `0x8011A0CC`. |
| `func_80013FD8` / `CVector3__ProjectCrease` | 50 | 0 | Return a structure, preserving IDO's hidden result-pointer ABI. |
| `alSynAllocFX` | 110 | 0 | Typed auxiliary-bus layout and SDK expressions. |
| `alMainBusPull` | 140 | 0 | SDK command macros, source indexing and original body layout. |
| `func_800B13E8` | 20 | 20 | Still differs in register allocation. |
| `func_800B0F18` | 20 | 20 | Still differs in register allocation. |
| `func_800A5F34` | 10 | 10 | One temporary-register choice still differs. |
| `func_8002DD90` | 155 | 115 | Correct pointer scaling; not matched. |

This pass adds **six exact matches / 3,248 selected C bytes**, not ten matches. Selection becomes **2,103 C functions / 480,976 bytes (76.831754% of 626,012)**. The unmatched iterator's best source is retained in the app and under `drafts/live-api-20261031`; worse trial candidates are not selected. The source-assisted reference archives were consulted. Existing compiler profiles were retained throughout these ten attempts.

The complete expanded image and reconstructed 8,388,608-byte original cartridge pass byte for byte, SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. All six additions remain selected C with no assembly fallback. The saved-app audit finds all 2,103 repository selections matched, saved sources and headers present, and no saved-source discrepancies; revalidation is finished. The app has 2,104 isolated matches, including the old unexported `func_800587B8`. No push was requested for these results.

## Ten additional live-API matches — 31 October 2026

Starting from `54dcc9c`, this source-assisted continuation recovered **ten previously unmatched functions / 2,372 bytes** through the running app's authenticated `/api/try` judge. Function targets, symbol addresses, cartridge hashes and comparison gates were retained. Source archives were consulted; these are not ROM-only results.

| Function | Bytes | Starting score | Final score | Repair |
| --- | ---: | ---: | ---: | --- |
| `func_8002FBD0` | 1,292 | 52 | 0 | Restore output argument/order consistency and reference the original grid/index tables separately. |
| `func_800119F4` | 248 | 185 | 0 | Restore the save-size calculation before filename updates; initialize the file number once. |
| `__osClearPage` | 192 | 234 | 0 | Consolidate the result local and restore declaration order for the original stack slots. |
| `func_800A7090` | 332 | 45 | 0 | Correct a byte offset previously scaled as an integer-pointer offset; use direct volatile video-register reads. |
| `func_800AAF70` | 44 | 210 | 0 | SDK-style register local and direct volatile hardware-address read. |
| `func_800AAFA0` | 44 | 190 | 0 | Same hardware-register repair. |
| `func_800AD680` | 48 | 230 | 0 | Same hardware-register repair. |
| `func_800AFDD0` | 44 | 245 | 0 | Same hardware-register repair. |
| `func_800AAEA0` | 52 | 545 | 0 | Restore the hardware status test and program-counter write. |
| `func_800AFF50` | 76 | 695 | 0 | Restore the status polling loop and device-address write. |

The six small hardware routines match with IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`; the video initializer already used that profile. A plain local or named external MMIO global can produce different register choices despite equivalent behaviour. The exact source, compiler and address-expression shape matter together. This does not prove which original IDO release built the cartridge. The three other additions retain their established profiles.

Four two-minute app deep searches produced no new matches; two encountered internal database-lock errors. No partial score was counted as a match. A later app process restart retained all ten saved recoveries. All ten matched sources and required headers were audited against the saved project, rather than relying only on transient database counts.

The verified standalone selection is **2,113 C functions / 483,348 bytes (77.210660% of the fixed 626,012 code bytes)**, up **0.378906 percentage points**. The live app has **2,114 isolated matches / 484,128 bytes (77.335259%)**; its additional old `func_800587B8` remains outside the standalone C selection because of its unresolved data placement. The app repository-sync job accepted all ten additions, and the complete expanded image and reconstructed 8 MiB cartridge passed byte for byte. Cartridge SHA-1 remains `88916d5d2e2470f395ad8f4245d34138ef2d156a`. All ten remain selected C, with no new assembly fallback. The repository-sync report retains the single older constant-pool blocker separately.


## Legacy MIPS III O32 object metadata — 31 October 2026

The next live-API pass recovered runtime helpers whose original instructions use MIPS III while their callers use the game's O32 ABI. IDO 5.3 `-mips3 -32` emits ELF32 objects with flags `0x20000000` but no explicit O32 ABI tag. The pinned GNU linker guesses a 64-bit ABI and rejects mixing them with the game's MIPS II objects. A two-object relocation-link experiment reproduces this failure; adding only `EF_MIPS_ABI_O32` (`0x1000`) permits the link.

`build.py` now adds that missing metadata only for explicitly selected IDO 5.3/7.1 `-mips3 -32` profiles and ELF32 MIPS III relocatable objects without another ABI. It rejects conflicting ABI flags and preserves every instruction, section, relocation and other header byte. No linker mismatch checks or final cartridge comparisons are disabled. Five regression tests cover exact byte changes, endianness, idempotence, profile guards and rejected ABIs. This build-only change adds no selected C functions or claimed matching bytes; the ten recoveries remain subject to the following full cartridge rebuild.
