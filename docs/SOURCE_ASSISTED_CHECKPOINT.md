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


## Runtime and SDK live-API continuation — 31 October 2026

Starting from `6ba4ada`, this source-assisted continuation recovered **ten previously unmatched functions / 656 bytes** through the running app. Existing target code and data, addresses, original-cartridge hashes and comparison gates were unchanged. The supplied game source and local SDK reference sources were consulted.

| Function | Bytes | Starting score | Final score | Repair |
| --- | ---: | ---: | ---: | --- |
| `func_8009DA4C` | 24 | 360 | 0 | Signed 64-bit to float conversion; MIPS III, 32-bit ABI, `-O1`. |
| `__ull_rshift` | 44 | 1031 | 0 | 64-bit logical right shift; MIPS III, 32-bit ABI, `-O2`. |
| `__ll_lshift` | 44 | 700 | 0 | 64-bit left shift; MIPS III, 32-bit ABI, `-O2`. |
| `__ll_mul` | 48 | 800 | 0 | 64-bit multiplication; MIPS III, 32-bit ABI, `-O2`. |
| `__ull_to_d` | 52 | 510 | 0 | Unsigned 64-bit to double conversion; MIPS III, 32-bit ABI, `-O1`. |
| `func_8009D430` | 60 | 980 | 0 | Second 64-bit unsigned-remainder helper; same profile. |
| `func_8009D38C` | 60 | 980 | 0 | 64-bit unsigned remainder; MIPS III, 32-bit ABI, `-O2`. |
| `osYieldThread` | 76 | 508 | 0 | SDK register local and runnable-state write before enqueue/yield; `-O1`. |
| `__osResetGlobalIntMask` | 88 | 324 | 0 | SDK register local and interrupt-mask expression after disabling interrupts; `-O1`. |
| `init_lpfilter` | 160 | 140 | 0 | Restore the typed, eight-byte-aligned coefficient union and original SDK locals/body. |

### What this establishes

The runtime targets contain `ld`, `dsrlv`/`dsllv`, `dmultu` and 64-bit floating-point conversions. Compiling their C as MIPS II generated helper calls instead. A verified working IDO 5.3 profile is `-O2 -mips3 -32 -G 0 -non_shared -Xcpluscomm` for the integer helpers; the two conversions match with the same profile at `-O1`. Under `-O2`, the signed conversion scored 100 and the unsigned conversion 260; switching those saved candidates to `-O1` made them exact. These observations identify useful per-function settings, not the original compiler release uniquely.

The two thread routines use IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. Correct register-local storage and statement order matter alongside the compiler profile. The filter retains its prior compiler settings; restoring the SDK record, aligned coefficient union and local declarations replaces an over-mutated untyped draft.

A separate source check found that `__osEnqueueThread` and the tiny pop-thread helper are explicitly handwritten in the reference SDK exception assembly. Their nearby commented C describes behavior; it does not promise that the published assembly is compiler output. They were not counted as C matches or reclassified in this session.

The app restarted during the run, interrupting some requests. Each recovery was checked against the starting inventory and final matched state; scratch score-zero attempts on functions already matched by compiler-profile application were not counted again. All ten are distinct new recoveries.


### Verified integration

With the separately documented O32 metadata fix in `83ae9c3`, the app repository-sync job accepted all ten additions. The full expanded image and original 8,388,608-byte cartridge rebuilt byte for byte, retaining SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. No new assembly fallback was introduced.

The standalone selection is **2,123 C functions / 484,004 bytes (77.315451% of the fixed 626,012 code bytes)**, a gain of **0.104790 percentage points**. The app has **2,124 saved matches / 484,784 bytes (77.440049%)**. Its older `func_800587B8` match remains outside standalone selection because of non-contiguous constant-pool placement. All selected C functions have matching persisted app sources and headers, and app revalidation has finished.


## Audio and game-source live-API continuation — 31 October 2026

Starting from `de70235`, ten distinct previously unmatched functions were recovered through the running app API, adding **1,988 bytes**. Original game and SDK sources on disk were consulted; this is a source-assisted result. Target bytes, addresses, hashes and comparison gates are unchanged.

| Function | Bytes | Starting score | Final score | Repair |
| --- | ---: | ---: | ---: | --- |
| `func_800A4C00` | 88 | 175 | 0 | Identify alCSPSetChlFXMix: compiler-profile application makes the saved candidate exact at -O3. |
| `func_800120DC` | 124 | 543 | 0 | Identify i3D_addPool: integer size argument and actual pool/node records. |
| `osGetTime` | 132 | 534 | 0 | SDK local lifetimes and register saved interrupt mask; -O1. |
| `__vsVol` | 136 | 215 | 0 | Typed voice/player/channel records and original volume multiplication order. |
| `func_8005EED0` | 136 | 210 | 0 | Identify AI_DoSound: four-argument ABI, integer return and -O3. |
| `alSynFreeVoice` | 176 | 335 | 0 | Original voice/free-parameter records, allocation-failure early return, clear voice after both branches; -O3. |
| `alAuxBusPull` | 216 | 280 | 0 | Original SDK audio-command macro and typed filter/bus records; -O3. |
| `__osCheckId` | 252 | 525 | 0 | Older SDK controller-pak body and original comparison operand order; -O1. |
| `alCSeqNewMarker` | 364 | 475 | 0 | Typed compact-sequence, marker and event records; original SDK body. |
| `alCSPNew` | 364 | 455 | 0 | Typed player/configuration/event/voice records and distinct SDK locals. |

The existing IDO 5.3 MIPS II profiles remain in use, with function-scoped optimization settings judged against retail bytes. These working settings do not uniquely prove the original compiler release. In particular, compiler-profile application matched the saved FX-mix candidate before the following scratch attempt; it is counted once.

Restoring real types and bodies mattered alongside optimization: the pool constructor draft mistook its integer size for a pointer; the volume helper needed the original multiplication order; the sound wrapper needed the proper four-argument signature. The retail free-voice routine clears the voice after either release path, while the supplied source places that clear inside one branch, so source availability alone does not guarantee a match.

The standalone selection is **2,133 C functions / 485,992 bytes (77.633017% of 626,012 code bytes)**, up **0.317566 percentage points**. The app has **2,134 saved matches / 486,772 bytes (77.757615%)**. The older `func_800587B8` constant-pool export blocker remains; all ten new matches are selected in the standalone build. The repository sync passed the complete original-cartridge byte comparison, preserving SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`. Saved sources and their contexts were audited against the live matched state.


## Thread, message and runtime live-API continuation — 31 October 2026

Starting from `1337979`, the running app recovered **ten previously unmatched functions / 2,560 bytes**. This source-assisted session consulted the supplied source and local SDK reference sources. All candidates used the ordinary live API judging path; target bytes, addresses, hashes and comparison gates were preserved.

| Function | Bytes | Starting score | Final score | Repair |
| --- | ---: | ---: | ---: | --- |
| `__osSetTimerIntr` | 116 | 925 | 0 | Original timer body: u64 NewTime, u32 savedMask and count/compare sequence; MIPS II -O1. |
| `__ll_mod` | 156 | 3075 | 0 | Signed 64-bit modulo with sign adjustment; MIPS III / O32 -O1. |
| `__d_to_ull` | 160 | 1830 | 0 | Actual unsigned 64-bit return and native double conversion; MIPS III / O32 -O1. |
| `__voiceNeedsNoteKill` | 168 | 510 | 0 | Typed event/link records, original char result and cleanup flow; MIPS II -O3. |
| `osDestroyThread` | 248 | 798 | 0 | Original register locals and active-thread removal; MIPS II -O1. |
| `osCreateThread` | 324 | 1153 | 0 | Correct thread-context layout, register mask local and actual cleanup entry symbol; MIPS II -O1. |
| `osSendMesg` | 332 | 3400 | 0 | Original typed message queue and register locals; MIPS II -O1. |
| `osStartThread` | 336 | 1777 | 0 | Original thread states, queue selection and scheduling body; MIPS II -O1. |
| `osJamMesg` | 336 | 3656 | 0 | Original front-of-queue message body and register locals; MIPS II -O1. |
| `alSeqpNew` | 384 | 1507 | 0 | Original SDK player, configuration, event and voice records; original locals/body; MIPS II -O2. |

The timer, thread and messaging matches use IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. The two runtime helpers use `-O1 -mips3 -32 -G 0 -non_shared -Xcpluscomm`; the existing guarded O32 ELF metadata normalization remains necessary for standalone linking. The voice-kill routine requires the MIPS II profile at `-O3`, while the sequence-player constructor retains `-O2`. These are verified working function profiles, not unique identification of the original toolchain.

Thread creation initially scored 225 with the correct SDK body. Expressing the cleanup address as dispatch-entry-plus-offset emitted an extra address addition. The target itself proves the cleanup entry at `0x800A60C0`; referencing that entry directly yielded score zero. This changes source symbol spelling, not placement or target bytes.

Static helper experiments in the sequence readers remained unmatched. Their target call conventions and clobbers can depend on their original translation unit; adding extra static bodies did not produce an acceptable isolated match. They are not included in this result. The previous better standalone draft was rejudged after temporary profile experiments. The timer-services initializer improved as a draft but remains unmatched and is not counted.

The verified standalone selection is **2,143 C functions / 488,552 bytes (78.041954% of 626,012 code bytes)**, up **0.408938 percentage points**. The app has **2,144 persisted matches / 489,332 bytes (78.166553%)**. All ten new matches passed repository sync and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved matched sources and their contexts were audited, and revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains separate from these ten.


## Controller, timer and matrix live-API continuation — 31 October 2026

Starting from `06b61e3`, ten distinct previously unmatched functions were recovered through the running app API, adding **2,728 bytes**. This source-assisted session consulted local SDK reference sources. Target bytes, addresses, hashes and exact comparison gates were unchanged.

| Function | Bytes | Starting score | Final score | Repair |
| --- | ---: | ---: | ---: | --- |
| `__osTimerServicesInit` | 140 | 515 | 0 | Restore the original current-time global definition, not only an extern declaration; typed timer list; -O1. |
| `osContGetReadData` | 168 | 1272 | 0 | Original controller packet/pad records and body; -O1. |
| `guMtxL2F` | 180 | 1177 | 0 | Original matrix union, integer word unpacking and nested loops; existing -O2. |
| `osContStartReadData` | 196 | 1162 | 0 | Original PIF RAM record, resource-access sequence and loop; -O1. |
| `__osPackReadData` | 236 | 1531 | 0 | Original read-packet record and request-packing loops; -O1. |
| `guMtxF2L` | 256 | 1055 | 0 | Original matrix union and nested fixed-point packing loops; existing -O2. |
| `__osTimerInterrupt` | 376 | 3177 | 0 | Original typed 64-bit timer body and final-ROM branch; -O1. |
| `__osInsertTimer` | 392 | 2369 | 0 | Original 64-bit sorted-list insertion, comparison and locals; -O1. |
| `osCreatePiManager` | 392 | 2989 | 0 | Original device-manager record, body and local global definition; -O1. |
| `osCreateViManager` | 392 | 2827 | 0 | Original device-manager/message records and local global definitions; -O1. |

Eight SDK routines use IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. Both matrix converters retain that MIPS II profile at `-O2`. These are verified working settings, not unique identification of the original compiler release.

### Definitions versus extern declarations

The device-manager routines were not fixed by their original function bodies and typed records alone: the PI candidate scored 2,110 and the VI candidate 2,950 at `-O1`. Restoring the original global definitions produced exact code. The extern-only candidates emitted additional LUI address loads between global-field stores; the definitions recovered the target address-load grouping and scheduling. The timer-services initializer likewise went from score 515 to zero after restoring its current-time global definition. These observations do not uniquely establish the compiler/assembler mechanism; source-local definition and layout knowledge should be retained as a hypothesis rather than replacing every global with extern prematurely.

The controller drafts contained mutated loop indices and unnecessary volatile accesses. Original packet/pad/PIF RAM records and SDK loops matched directly at `-O1`. Both matrix converters matched their original typed nested loops without changing their existing compiler profile.

A source extraction encountered conditional compilation whose alternate branches contain different brace counts. The first timer-interrupt extraction omitted its final closing brace and did not compile. Restoring that closing brace from the original source, with the final-ROM branch selected, produced the exact match; no compiler failure is counted as progress.

The standalone selection is **2,153 C functions / 491,280 bytes (78.477729% of 626,012 code bytes)**, up **0.435774 percentage points**. The app has **2,154 persisted matches / 492,060 bytes (78.602327%)**. All ten new sources passed repository sync and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). The saved matched sources and required contexts were audited, and app revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains the separate app/repository gap.


## Controller setup and memory-pack live-API continuation — 31 October 2026

Starting from `8b143ff`, ten previously unmatched functions were recovered through the running app API, adding **5,304 bytes**. This source-assisted session consulted the authorized local SDK reference sources. Target bytes, addresses, hashes, and exact comparison gates were unchanged.

| Function | Bytes | Starting score | Final score |
| --- | ---: | ---: | ---: |
| `__osPackRequestData` | 244 | 1209 | 0 |
| `__osPfsGetNextPage` | 252 | 1015 | 0 |
| `osPfsNumFiles` | 324 | 3107 | 0 |
| `osPfsFreeBlocks` | 332 | 3598 | 0 |
| `osPfsFindFile` | 436 | 1181 | 0 |
| `osContInit` | 504 | 2410 | 0 |
| `__osPfsReleasePages` | 568 | 10246 | 0 |
| `osPfsDeleteFile` | 736 | 7006 | 0 |
| `osPfsFileState` | 752 | 9725 | 0 |
| `osPfsAllocateFile` | 1156 | 8067 | 0 |

All ten use IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. These are verified working settings, not a unique identification of the original compiler release.

Original SDK record types, union copies, locals, macros and function bodies recovered these routines directly. In particular, the inode's overlaid bank/page bytes and halfword restore the original aggregate-copy instruction and load order. The file and directory records retain the original sizes and field ordering. No arbitrary padding in the target or data relocation changes were introduced.

Controller initialization first reached score 20: every instruction matched except two unresolved compiler-generated unsigned division calls. The ROM already calls `func_8009D3C8` at those two sites. An explicitly declared unsigned 64-bit call to that existing helper in the microseconds-to-cycles macro resolved both relocations and passed the normal byte judge. No symbol addresses were guessed or renamed. The controller packet routine uses the non-prototype hardware branch from the SDK source.

Reference function bodies were retained with explicit source-line directives; selected hardware branches were extracted from their original conditional context. No broad permutation or random search was needed for this batch. The newly implemented app source-preparation feature is in a separate PR and was not installed or used to claim these results.

The standalone selection is **2,163 C functions / 496,584 bytes (79.324997% of 626,012 code bytes)**, up **0.847268 percentage points**. The app has **2,164 persisted matches / 497,364 bytes (79.449595%)**. All ten additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved matched sources and required headers were audited, with app revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains the separate app/repository gap.


## Controller Pak source-preparation API continuation — 31 October 2026

Starting from `9f2dbd6`, ten previously unmatched functions were recovered through the running app's authenticated source-preparation API, adding **6,080 bytes**. This source-assisted session used authorized local SDK references. No target bytes, addresses, hashes or comparison gates were changed.

| Function | Bytes | Starting score | Final score |
| --- | ---: | ---: | ---: |
| `__osPfsRequestData` | 252 | 1703 | 0 |
| `__osPackRamWriteData` | 380 | 3499 | 0 |
| `__osCheckPackId` | 408 | 970 | 0 |
| `osPfsIsPlug` | 416 | 2615 | 0 |
| `__osContRamWrite` | 560 | 2468 | 0 |
| `__osContRamRead` | 580 | 3597 | 0 |
| `__osPfsDeclearPage` | 612 | 5135 | 0 |
| `__osPfsRWInode` | 800 | 4463 | 0 |
| `osPfsReadWriteFile` | 1024 | 8782 | 0 |
| `__osRepairPackId` | 1048 | 3119 | 0 |

All ten retain IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. The original SDK packet, inode and pack-ID records, local declarations and selected hardware branches were restored rather than broadly permuting mutated drafts.

The pack-ID repair routine reached score 10 with only an unresolved `osGetCount` call. The target calls the existing `func_800A60D0`; a candidate-local macro alias to that target symbol produced an exact match. No global symbol identity was changed. The read/write-file candidate initially omitted its source-file `CHECK_IPAGE` macro, causing an implicit call and by-value struct argument expansion; restoring the original bounds-check macro produced the exact code. Missing constants/types and compiler failures were corrected and are not counted as progress.

The GUI manual-edit identity had an active claim in another game. That claim was left untouched. Prepared candidates and a private declarations header were submitted through the live source-preparation API, whose autopilot identity handles its own claims, ordinary byte/data judging and guarded header promotion. Short bounded rounds were continued until all ten were accepted. The project's previous machine-local source-preparation configuration was restored afterwards.

Application improvements from the prior batch are proposed separately in decompdecomp PR #209; this session did not install or restart the app, or attribute its matches to uninstalled code.

The standalone selection is **2,173 C functions / 502,664 bytes (80.296224% of 626,012 code bytes)**, up **0.971227 percentage points**. The app has **2,174 persisted matches / 503,444 bytes (80.420823%)**. All ten additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required contexts were audited, with app revalidation complete. The older `func_800587B8` non-contiguous constant-pool export blocker remains the separate app/repository gap.


## Checker, matrix and audio source-preparation continuation — 31 October 2026

Starting from `652c6bf`, ten previously unmatched functions were recovered through the authenticated live app API, adding **6,008 bytes**. This source-assisted session used authorized local SDK/game reference sources and headers. Target bytes, addresses, hashes and exact comparison gates were unchanged.

| Function | Bytes | Starting score | Final score | Optimization |
| --- | ---: | ---: | ---: | --- |
| `_allocatePVoice` | 232 | 685 | 0 | `-O3` |
| `alSndpNew` | 308 | 2401 | 0 | `-O3` |
| `_saveBuffer` | 392 | 4807 | 0 | `-O3` |
| `_loadBuffer` | 396 | 4226 | 0 | `-O3` |
| `corrupted_init` | 436 | 3060 | 0 | `-O1` |
| `corrupted` | 488 | 3953 | 0 | `-O1` |
| `guPerspectiveF` | 560 | 2290 | 0 | `-O2` |
| `guLookAtF` | 696 | 661 | 0 | `-O2` |
| `alSynNew` | 768 | 2122 | 0 | `-O2` |
| `osPfsChecker` | 1732 | 7666 | 0 | `-O1` |

All use IDO 5.3 with `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`, plus the optimization shown above. These are working verified profiles, not unique identification of the original compiler release.

### Repairs and limits

- The Controller Pak checker and corruption helpers matched with the original inode-cache records, distribution-map constants, union accesses and loops at `-O1`. The checker's final unresolved `__osGetId` call was mapped locally to the existing `func_800A8D94` shown by the target call site.
- Both floating-point matrix builders matched original SDK formulas and local ordering at `-O2`. Their remaining differences were unresolved math calls: the target identifies `func_8009E7A0`, `__sinf` and `__cosf`. Candidate-local aliases with correct floating-point prototypes resolved them. An alias without the correct declaration did not suffice.
- Physical-voice allocation and sound-player construction matched with original SDK types and `-O3`. Reverb buffer loading matched at its existing `-O3`; saving required `-O3` after its source/header repair. All command macros were retained from the SDK ABI header.
- Synthesizer initialization reached score 10 with only one allocation immediate different: the retail call requests **76 bytes**, whereas `sizeof(ALAuxBus)` in the reference headers produces **72 bytes**. The source now explicitly requests the ROM-observed `0x4c` extent. No unknown field or padding was invented, and existing field offsets were retained. This is an observed reference/retail allocation difference, not proof of the reason for it.

Prepared declarations were derived from selected local SDK headers (including the original audio-state array types); only preprocessing was used, with no reference build scripts executed. The live app's preparation path performed the ordinary compile/link/data judge and private-context promotion. Its previous machine-local preparation settings were restored. Unsuccessful bank-file compiler trials were also restored; the bank-file and event-queue routines remain unmatched and are not counted.

The standalone selection is **2,183 C functions / 508,672 bytes (81.255950% of 626,012 code bytes)**, up **0.959726 percentage points**. The app has **2,184 persisted matches / 509,452 bytes (81.380549%)**. All ten additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required contexts were audited, with app revalidation complete. The older `func_800587B8` non-contiguous constant-pool export blocker remains the separate app/repository gap.


## Effects, playback and math live-API continuation — 31 October 2026

Starting from `f545e93`, ten previously unmatched functions were recovered through the authenticated live app API, adding **5,688 bytes**. This source-assisted session used authorized local game/SDK reference sources and headers. Target bytes, addresses, hashes and exact comparison gates were unchanged.

| Function | Bytes | Starting score | Final score | Optimization |
| --- | ---: | ---: | ---: | --- |
| `_filterBuffer` | 184 | 845 | 0 | `-O3` |
| `__osLeoResume` | 236 | 1848 | 0 | `-O1` |
| `alEvtqPostEvent` | 292 | 710 | 0 | `-O3` |
| `__sinf` | 448 | 1445 | 0 | `-O2` |
| `alResamplePull` | 520 | 2848 | 0 | `-O3` |
| `_loadOutputBuffer` | 548 | 2960 | 0 | `-O3` |
| `alFxParamHdl` | 604 | 2060 | 0 | `-O3` |
| `alFxPull` | 832 | 1892 | 0 | `-O3` |
| `alRaw16Pull` | 940 | 16247 | 0 | `-O3` |
| `alFxNew` | 1084 | 8403 | 0 | `-O3` |

All use IDO 5.3 with `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`, plus the optimization shown above. These are verified working profiles, not unique identification of the original compiler release.

### Source and context findings

- Original SDK filter/delay/resampler records, private helper prototypes and ABI command macros recovered filtering, delay-buffer loading, resampling, raw playback and the effects mixer. The source-file `SWAP` macro was necessary; omitting it produces an unintended call. Raw playback and event posting matched after their repaired source/context was checked at `-O3`.
- The SDK effect initializer and parameter handler match a revision that includes a trailing `ALSetFXParam paramHdl` callback in `ALFx`; the game-source header lacks it. This documented SDK member explains the four-byte size discrepancy observed in the preceding batch without inventing padding. Target switch references and existing entry symbols identify the candidate-local parameter-table/callback aliases. No global symbols were renamed.
- The disk-interrupt resume routine matched original SDK message/thread records at `-O1`. Its event state is entry eight, offset `0x40`, in the existing table at `D_801369A0`; the base and entry were checked against the target instruction sequence.
- The sine routine matched the SDK polynomial/reduction implementation, original bit-exact coefficient unions and rounding macro at `-O2`. Its quiet-NaN reference uses the existing target symbol. Constant/data placement remains subject to standalone export and full-cartridge verification.

The ordinary app preparation/judging path performed context promotion and persisted the accepted sources. The previous machine-local preparation configuration was restored. ADPCM playback, envelope mixing and the main audio-frame routine improved without matching and remain separate app drafts (scores 12,966, 9,307 and 270 respectively); they are not included in coverage. The ADPCM and audio-frame drafts retain their measured `-O3` profile, while envelope mixing uses `-O2`. Source extraction and missing-declaration failures are not counted as progress.

App improvements are proposed separately in decompdecomp PR #212 (130 focused regression tests passed). This matching session did not install or restart the app, and does not attribute its matches to uninstalled code.

The standalone selection is **2,193 C functions / 514,360 bytes (82.164559% of 626,012 code bytes)**, up **0.908609 percentage points**. The app has **2,194 persisted matches / 515,140 bytes (82.289157%)**. All ten additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required contexts were audited, with app revalidation complete. The older `func_800587B8` non-contiguous constant-pool export blocker remains the separate app/repository gap.


## SDK I/O and controller live-API continuation — 31 October 2026

Starting from `b13e6f2`, ten new exact matches add **4,928 bytes**. This source-assisted batch used authorized local SDK reference source/types through the running app's authenticated source-preparation and compiler APIs. Original target bytes, addresses and comparison gates were preserved. Source identities below are supported by the reference bodies, target operations and call sites; address-based entry names remain unchanged. The second controller decoder uses a different ROM-proven buffer, so it is not assigned the first decoder's canonical name.

| Entry | SDK source identity / role | Bytes | Starting score | Final score | Optimization |
| --- | --- | ---: | ---: | ---: | --- |
| `func_8009EDC8` | `__osContGetInitData` | 208 | 1335 | 0 | `-O1` |
| `func_8009F22C` | `response decoder, second buffer` | 208 | 1718 | 0 | `-O1` |
| `func_800A4D00` | `osAiSetFrequency` | 352 | 2565 | 0 | `-O1` |
| `func_800A4FB0` | `osAiSetNextBuffer` | 168 | 1320 | 0 | `-O1` |
| `func_800A67D0` | `__osLeoInterrupt` | 1764 | 14646 | 0 | `-O1` |
| `func_800A6EB4` | `__osLeoAbnormalResume` | 232 | 3035 | 0 | `-O1` |
| `func_800A72A0` | `osPiRawStartDma` | 224 | 725 | 0 | `-O1` |
| `func_800A7380` | `osEPiRawStartDma` | 224 | 2322 | 0 | `-O1` |
| `func_800A7460` | `__osDevMgrMain` | 944 | 11016 | 0 | `-O1` |
| `func_800A8D94` | `__osGetId` | 604 | 2489 | 0 | `-O1` |

All ten use IDO 5.3 `-O1 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. These are verified working profiles, not a unique identification of the original compiler release. Several older drafts had been tested at `-O2`; optimization alone did not recover them.

### What recovered the matches

- Original numeric volatile MMIO macros preserve the compiler's address materialization. Two symbolic alternatives emitted an extra address instruction or used a different base register. Linked bytes, rather than symbolic diff spelling, decided exactness. DMA routines retain busy-loop reloads and the target's register-local status variable.
- Controller response records retain the SDK's byte alignment and aggregate-copy shape. The two otherwise identical decoders reference their distinct observed buffers. The pack ID reader uses original `OSPfs` and `__OSPackId` layouts and the existing checksum/repair helpers.
- The enhanced DMA routine does not contain the reference revision's handle-timing reconfiguration block in retail. The device-manager function likewise lacks the newer disk-overrun block and its associated pointer recomputation. These removals follow the target control flow, not a blanket assumption that reference source is exact.
- The disk interrupt handler requires retail error values (75, 3, 6 and 17), an explicit DMA-busy recovery path, and the target's recipient for a recovery status store. Its polling waits test I/O-busy alone. The small abnormal-resume helper matches with the same polling condition and a volatile stack status local; the interrupt handler retains the ordinary cached BM-status local where the target reuses it.

The disk initializer improved to score 260 but remains unmatched and is excluded from coverage. Broad optimization probes and bounded deep searches did not produce these matches; source/context reconstruction did. Previous preparation settings were restored. No app installation/restart was performed by this session, and these manual live-API results are not attributed to the uninstalled changes in decompdecomp PR #214.

The standalone selection is **2,203 C functions / 519,288 bytes (82.951765% of 626,012 code bytes)**, up **0.787205 percentage points**. The app has **2,204 persisted matches / 520,068 bytes (83.076363%)**. All ten additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required headers were audited. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.

## Ten-candidate SDK and typed-context continuation — 1 November 2026

Starting from `76331ba`, this source-assisted batch worked on ten main candidates through the running app's authenticated source-preparation, compilation and compiler-profile APIs. **Five became byte-identical / 2,600 bytes; five improved without matching.** Additional bounded reader/layout probes did not add matches. Local game and SDK source use was authorized. Original target bytes, addresses, hashes and exact comparison gates were unchanged.

| Entry | Located source identity | Bytes | Starting score | Final score | Optimization |
| --- | --- | ---: | ---: | ---: | --- |
| `func_8002DD90` | `CHashTable__GetNextAssoc` | 168 | 115 | 0 | `-O3` |
| `func_8009D620` | `osInitialize` | 672 | 6720 | 0 | `-O1` |
| `func_800AA810` | `__osViSwapContext` | 860 | 13320 | 0 | `-O1` |
| `func_800AFE00` | `osLeoDiskInit` | 236 | 260 | 0 | `-O1` |
| `_Litob` | SDK integer formatting | 664 | 7841 | 0 | `-O2` |

All use IDO 5.3 with `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul` and the optimization above. These are verified working settings, not unique identification of the original compiler release. Address-based entry names remain unchanged.

### What recovered the matches

- The disk initializer needed the actual original handle definition in its private context, rather than only an `extern`. The target still lacks the reference revision's domain assignment, as established in the preceding batch. Original definition knowledge changed address setup/scheduling.
- OS initialization needed the original initialized clock-rate definition and an existing named NMI-buffer reference. The latter emitted the target's `addiu` address expression instead of the literal cast's `ori`. The exception-vector shape, hardware access widths and runtime multiplication/division calls were retained from verified target/source evidence.
- VI context swapping recovered the original mode/context records, scaling/state operations, volatile hardware writes and aggregate context copy. Its repaired source then matched at `-O1`; optimization alone had not recovered the old draft.
- Integer formatting needed the original formatter layout and digit-array definitions. Typed calls to the already located unsigned 64-bit division/remainder helpers resolved the remaining helper-call mismatch; the memory-copy call uses the existing target entry.
- The hash iterator matched the original association/table records, pointer outputs and loop structure. Replacing the raw-offset draft with these original declarations resolved register-allocation differences without padding or assembly changes.

### Improved drafts, excluded from coverage

| Entry | Starting score | Best score | Remaining evidence |
| --- | ---: | ---: | --- |
| `func_800A0F38` | 3545 | 600 | Video-manager body matches apart from unreachable NOPs; debug-flag probes did not fix it. |
| `func_8000BEF0` | 325 | 30 | Application-field context fixed address grouping; base-register choices still differ. |
| `func_80044BDC` | 360 | 300 | Resolved the wall-position array definition; load scheduling still differs. |
| `func_800AB6AC` | 655 | 315 | Original tempo-expression context and two iterative permutation improvements; byte-load/register differences remain. |
| `func_800181A0` | 557 | 437 | Corrected container-local layout; located `CGameObjectInstance__GetAnimType` as the source candidate, but original typed reconstruction is not exact. |

These scores describe partial drafts, not recovered C selections. Bounded deep searches did not turn them into exact matches; one animation-type preflight failed before variants were tested. Some additional SDK/helper fragments enter with live saved/floating registers, so isolated ordinary-C prototypes are not sufficient evidence of their private ABI. No padding instructions, forced register assembly, target changes or weakened judgments were used.

Application changes are proposed in [decompdecomp PR #217](https://github.com/RetroReversing/decompdecomp/pull/217): target-supported I/O profile priorities, proven MMIO/local-storage candidates, existing byte-record aggregate-copy hypotheses and reference-discrepancy advisories. The 108 focused tests and lint pass after merging main. This session did not install/restart the app; these manual matches are not attributed to the uninstalled PR.

The standalone selection is **2,208 C functions / 521,888 bytes (83.367092% of 626,012 code bytes)**, up **0.415328 percentage points**. The app has **2,209 persisted matches / 522,668 bytes (83.491690%)**, **138 open** and **59 assembly candidates**. All five additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required headers were audited, and revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.

## Typed original-source and profile continuation — 1 November 2026

Ten main candidates were attempted through the installed app's authenticated API. Seven became exact
matches, covering **1,880 bytes**. One other draft improved from score 457 to 60; two did not improve.
Partial drafts are excluded from matching coverage.

| Address | Source identity | Bytes | Verified profile | Main change |
|---|---|---:|---|---|
| `8006905C` | `AI_SEvent_DamageNudge_Target` | 252 | IDO 5.3 `-O3` | Original switch and typed instance/particle pointers |
| `8002B2E8` | `CParticleSystem__RequestData` | 120 | IDO 5.3 `-O3` | Original cache/callback fields and particle-system layout |
| `80074A74` | `AI_DoTeleport` | 448 | IDO 5.3 `-O2` | By-value vector ABI, original locals and rotation helper |
| `8001DE20` | `CAnimInstanceHdr__CastYeThyRay` | 304 | IDO 5.3 `-O3` | Shared instance records and original vector aggregate copy |
| `800318D0` | `CScene__DrawParticles` | 152 | IDO 5.3 `-O3` | Correct graphics record and particle-draw prototype |
| `80072D08` | `AI_Make_Swim` | 272 | IDO 5.3 `-O3` | Original local arrays and typed rotation helper |
| `80079540` | `AI_Standard_Agitated` | 332 | IDO 5.3 `-O3` | Original local arrays copied from existing ROM objects |

All use `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`. Compiler identification remains
provisional. Local source identities guide reconstruction; address-based entry names remain intact.

Several original typed candidates performed worse at the existing `-O2` setting but matched under
`-O3`. Source preparation therefore needs to probe profiles even when its current-profile source
has not earned promotion. The app enhancement retains private source/header/profile evidence for
review; it does not bypass settings approval or count an unpromoted candidate as progress.

The agitated-animation function initially had identical instructions but failed the data judge:
compiler-generated anonymous-array padding overlapped the following ROM object. Copying the existing
named ROM array records removed that anonymous padding. The ordinary data judge remained intact.
The analogous swimming-retreat candidate improved to score 60 but remains unmatched.

`COnScreen__WriteSmallText` and the campaigner death handler still differ after typed-source and
profile probes. Failed probes were restored to their working profiles and best drafts. The swimming
retreat improvement retains its verified better `-O3` draft, but contributes no matching bytes.

These are manual source-assisted results from the installed app, not a claim that uninstalled PR #220
produced these matches. This work did not install or restart the app.

The standalone selection is **2,215 C functions / 523,768 bytes (83.667406% of 626,012 code bytes)**, up **0.300314 percentage points**. The app has **2,216 persisted matches / 524,548 bytes (83.792004%)**, **131 open** and **59 assembly candidates**. All seven additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required headers were audited, and revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.

## Typed records, retail branches and scheduler continuation — 1 November 2026

Ten main candidates were attempted through the live app's authenticated API. **Three exact matches /
1,392 bytes** were recovered; the other seven retain their starting best scores and working profiles.

| Address | Source identity | Bytes | Profile | What recovered it |
|---|---|---:|---|---|
| `8000BEF0` | `CLoad__Construct` (`loadsave.c:509`) | 316 | IDO 5.3 `-O2` | Original load/message-box record types, real string-pointer prototypes, and ROM-verified retail setup/error branches |
| `8001E21C` | `CGameRegion__InRegion` (`romstruc.c:5161`) | 220 | IDO 5.3 `-O3` | Original corner/vector records, loop and local declaration order |
| `8002BF28` | `__scHandleRSP` (`sched.c:400`) | 856 | IDO 5.3 `-O2` | Original scheduler/task records, unsigned timers, helper prototypes and original statement order |

All use `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`; compiler identification remains
provisional. The region candidate was not an improvement under `-O2`, but its prepared context matched
at `-O3`; that complete combination was then judged and promoted through the live API.

The load constructor's source is not retail-identical: the ROM calls setup twice and handles specific
error codes rather than the reference's broad nonzero-error condition. These differences were derived
from the target and verified by the ordinary byte judge. Original fields place the message box's active
flag and global message-box flag correctly; no target or data-comparison gate was changed.

The scheduler was an important identity correction. The historical nearest-neighbour inventory called
it `initAudio`; original RSP completion logic and its typed context now match exactly. Existing ROM
aliases for timing globals and integer-runtime helpers were retained. No new addresses were guessed.

### Seven candidates still unmatched

| Candidate | Retained score | Finding |
|---|---:|---|
| `800A5F34` | 10 | Queue-pop semantics; remaining temporary-register choice differs. Returning the popped pointer and IDO 7.1 did not recover a match. |
| `8002DA18` | 20 | Five arguments and inline attach/size/count operations suggest `CUnindexedSet__ConstructWithAllocatedBlock`, superseding the older `PreAllocate` lead. Original context/debug-profile probes did not improve it. |
| `800B0F18` | 20 | SDK `readVarLen`: matching control flow with remaining register differences. Word aliases, IDO 7.1 and explicit debug profiles did not settle them. |
| `800B13E8` | 20 | SDK `read16`: original source scored 30, leaving the better existing draft intact. Compiler/debug/context alternatives did not match. |
| `800A2420` | 25 | Compact-player `__setUsptFromTempo` lead. Target uses an incoming pointer in `a0` and float in `f12`, unlike the exposed ordinary-C signature. |
| `80072144` | 51 | `AI_Make_TeleportMoveSlow` and its original inline rotation helper tried; the typed candidate/profile was worse than the saved draft. |
| `800AF4EC` | 110 | SDK `_getVol`: ordinary float-first C shifts integer argument slots relative to the target's `f12` plus `a0/a1/a2` helper entry. Original static-helper/caller context needs investigation. |

Failed IDO 7.1 and debug-flag probes were restored. Notes on these experiments and ABI blockers were
saved in the live project so subsequent workers can avoid repeating them. None contributes matching
bytes. These are manual source-assisted results; they are separate from synthetic tests for PR #226,
which adds joint prepared-bundle approval, data diagnostics and bounded named-array hypotheses.

The standalone selection is **2,218 C functions / 525,160 bytes (83.889766% of 626,012 code bytes)**, up **0.222360 percentage points**. The app has **2,219 persisted matches / 525,940 bytes (84.014364%)**, **128 open** and **59 assembly candidates**. All three additions passed individual repository checks and the complete original-cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required headers were audited, and revalidation finished. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.


## Typed source, profiles and helper prototypes — 1 November 2026

Ten source-assisted candidates were tested through the running app's authenticated API and source-preparation jobs. **Five exact matches add 1,356 bytes**; the other five retain their starting best scores. These manual results do not measure the new, not-yet-installed source-lead UI in decompdecomp PR #230.

| Function | Bytes | Verified profile | Recovery |
|---|---:|---|---|
| `__alCSeqNextDelta` | 360 | IDO 5.3 `-O3` | Original compact-sequence layout, unsigned loop and delta-tick fields |
| `__lookupSoundQuick` | 252 | IDO 5.3 `-O3` | Original instrument, sound, key-map and channel records plus binary-search locals |
| `func_800181A0` | 212 | IDO 5.3 `-O3` | `CGameObjectInstance__GetAnimType`, original indexed/unindexed set helpers, locals and non-WIN32 macros |
| `func_800118EC` | 264 | IDO 5.3 `-O2` | `SaveCurrent`-derived retail overwrite handler, original filesystem records and void queue-helper prototypes |
| `func_8002A3B0` | 268 | IDO 5.3 `-O3` | `CParticle__CeilingCollision`, original records, by-value vectors and corrected helper prototypes |

All use `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`; compiler identification remains provisional. Profiles were verified for the complete source/context combination before promotion. The overwrite handler differs from the reference: retail records the extension byte, deletes the selected file and calls `SaveNew` instead of the reference write call. Existing ROM data symbols were used rather than inventing string placement or a complete application layout.

The particle candidate improved from 438 to 200 with typed source at `-O3`, then matched after material and sound helper prototypes were corrected together. The sound volume is a float, and the material helper returns an unsigned word. Incorrect prototypes can alter argument-register and instruction choices even for a zero argument; this session did not independently ablate those two corrections.

### Five candidates still unmatched

| Candidate | Retained score | Finding |
|---|---:|---|
| `alSeqNew` | 185 | Original sequence layout and reader declarations did not improve the draft; specialized reader/caller context remains a lead. |
| `alAudioFrame` | 270 | The bundled older SDK lacks the retained draft's newer timing logic. Replaying that older source and neighboring profiles did not help. |
| `__alSeqNextDelta` | 350 | Original saved-pointer restoration and sequence context did not improve it. |
| `func_800AB6AC` | 315 | Original `__handleMetaMsg` and inline tempo helper did not improve it; target argument order differs from the reference entry. |
| `func_80044BDC` | 300 | Original `Mantis_ClosestWall` body/context remained at 300; `-O3` worsened it to 1828, so `-O2` was restored and reverified. |

Failed-experiment notes are saved in the app. The working drafts and profiles remain intact; none of these misses contributes matching bytes.

Standalone selection is **2,223 C functions / 526,516 bytes (84.106375% of 626,012 candidate-code bytes)**, up **0.216609 percentage points**. The app has **2,224 persisted exact matches / 527,296 bytes (84.230973%)**, **123 open** and **59 assembly candidates**. All five additions passed individual repository checks and the complete original 8,388,608-byte cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). All selected sources and required saved app contexts were audited, with no revalidation pending. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.


## Particle records and aggregate calls — 1 November 2026

Ten source-assisted candidates were tested through the running app's authenticated API and source-preparation jobs. **Eight exact matches add 2,228 bytes**. Original particle/impact/collision records, original function bodies, by-value vector/quaternion calls and correctly typed material/sound helpers recovered the particle routines. The source line layout is preserved; target-supported aliases reuse the existing scene and particle-system objects. These are manual live-app results, separate from synthetic tests for the not-yet-installed PR #232.

| Address-based entry | Source identity | Bytes | Profile |
|---|---|---:|---|
| `80029C48` | `CParticle__EndLife` (`particle.c:2238`) | 260 | IDO 5.3 `-O3` |
| `8002A1A0` | `CParticle__EveryFrame` (`particle.c:2274`) | 260 | IDO 5.3 `-O3` |
| `8002A2A4` | `CParticle__SpawnCeilingCollision` (`particle.c:785`) | 268 | IDO 5.3 `-O3` |
| `8002A4BC` | `CParticle__SpawnGroundCollision` (`particle.c:761`) | 268 | IDO 5.3 `-O3` |
| `8002A5C8` | `CParticle__GroundCollision` (`particle.c:2166`) | 300 | IDO 5.3 `-O3` |
| `8002A800` | `CParticle__WaterSurfaceCollision` (`particle.c:2134`) | 240 | IDO 5.3 `-O3` |
| `8002A8F0` | `CParticle__SpawnWallCollision` (`particle.c:720`) | 328 | IDO 5.3 `-O3` |
| `8002AA38` | `CParticle__WallCollision` (`particle.c:2095`) | 304 | IDO 5.3 `-O3` |

All use `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`; compiler identification remains provisional. Several original contexts first failed under `-O2`, but private `-O3` probes were exact and then freshly rejudged through normal promotion. The aggregate-return direction helper and by-value particle-creation arguments replace damaged drafts with unset temporaries; no comparison or data gate was weakened.

Repeated scratch source/header concatenation accumulated blank padding and exhausted some 20-second preparation rounds before compilation. Reconstructing those scratch inputs from the original bodies and declarations allowed fresh judgments. The separate tool PR fixes quadratic blank-line scans and reports this timeout explicitly. It does not retroactively account for these manual matches.

### Two candidates still unmatched

| Candidate | Retained score | Finding |
|---|---:|---|
| `alCSeqNew` | 988 | Original compact-sequence source/context scored 1054 at `-O2` and `-O3`, and 9407 at `-O1`. The target passes the sequence/track to its static reader in `t2`/`t3`, unlike an exposed external C declaration using ordinary argument registers. Original same-unit helper context remains a lead, not proof of a different algorithm. |
| `func_8002BA48` | 1200 | Original non-logging `__scMain` body and queue/client context did not improve at `-O2` or `-O3`; `-O1` scored 8221. Original compilation context remains unresolved. |

Both retain their starting best scores and `-O2` profiles; failed experiments are noted in the live project. Neither contributes matching bytes.

Standalone selection is **2,231 C functions / 528,744 bytes (84.462279% of 626,012 candidate-code bytes)**, up **0.355904 percentage points**. The app has **2,232 persisted exact matches / 529,524 bytes (84.586877%)**, **115 open** and **59 assembly candidates**. All eight additions passed individual repository checks and the complete original 8,388,608-byte cartridge comparison (SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`). Saved sources and required headers were audited in both directions with no revalidation pending. The older `func_800587B8` non-contiguous constant-pool export blocker remains the one app/repository difference.
