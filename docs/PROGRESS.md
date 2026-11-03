# ROM-only experiment: 23 October 2026

The first import discovered only 12 functions / 3,680 bytes. ROM-derived analysis of the bootstrap identified a compressed program at ROM offset `0x783690`, unpacked to RAM `0x80001300`.

The RNC method-1 header declared 462,217 packed bytes and 1,015,248 unpacked bytes. Executing the supplied ROM's decoder in a bounded MIPS emulator and independently implementing the format produced identical output. Packed CRC16: `f045`; unpacked CRC16: `a680`; unpacked SHA-256: `f0c9bd34991216298c760a683908458ed50435d052dd4e67af24374bfea5104d`.

The output ends at `0x800F90D0`, matching the bootstrap's BSS-clear boundary. Automatic RNC import then found 2,404 candidate functions. The initial KMC heuristic described the bootstrap; main-program instruction patterns suggested IDO. With explicit user acceptance, IDO 5.3 and 7.1 were installed from pinned, checksummed toolchain-registry artifacts.

Across 59 drafted functions in two samples, each IDO version matched 12. IDO 5.3 remains provisional. Working flags:

```text
-O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul
```

Automatic drafts, byte-pointer refinement, manual recovery, and a bounded mutation pass reached 419 exact C matches / 26,112 bytes. The three-minute mutation pass tried 16,208 variants over 20 functions, improving 13 and matching 10. All accepted results used the unchanged linked-byte judge.

For `func_8000EF70`, a 12-byte record type corrected pointer scaling (score 55 to 10); expressing a counter update as pre-increment produced score 0 under both IDO versions. The gameplay meaning of these fields is unproven.

At this checkpoint, 1,950 candidates / 592,616 bytes remain open and 35 / 7,284 bytes are classified as assembly. Tiny boundaries and assembly branches across splits need review. These are discovery statistics, not whole-game coverage.

The final standalone export included all 419 C selections, 2,405 exported functions total, and no fallback among those C selections. A startup function accounts for the difference between the export and analysis counts. Both the expanded-image comparison and the original-cartridge reconstruction passed, yielding the complete original normalized 8 MiB ROM byte for byte. Most of the game still uses assembly generated locally from the ROM.

## Verified 886-function checkpoint

After the 419-function checkpoint, Terra added 23 functions / 1,852 bytes. A 30-minute GPT-6.1 Sol low-effort continuation then retained another 444 functions / 33,872 bytes after full-build verification. The final total is 886 C functions / 61,836 bytes, 9.8778% of the fixed 626,012 detected-code bytes. The full original normalized 8,388,608-byte cartridge rebuilt byte for byte, SHA-1 `88916d5d2e2470f395ad8f4245d34138ef2d156a`.

The timed function judge initially accepted 891 functions. Five new jump-table candidates (820 bytes) failed the full expanded-image comparison and were excluded without source repairs after the deadline. Their original assembly remains in the build. Only the 886-function fully verified selection is published here. The sources retain provisional types and compiler-specific stack expressions and require readability/semantic review. Most code remains assembly; this is not a full decompilation.

This commit copies the exact C selections, shared context, and build files from the passing standalone export. No ROMs, generated disassembly/assets, databases, or proprietary compiler binaries are included.


## 30 October source-assisted checkpoint

The current standalone build selects **2,036 C functions / 445,672 bytes (71.192% of the fixed candidate-code total)** and reproduces the original cartridge byte for byte. The latest one-hour session added 33 isolated matches / 27,564 bytes; 31 are selected C, while two require further data-placement work. The live app has 2,051 isolated matches, a separate measurement from the standalone selection. See [source-assisted provenance](SOURCE_ASSISTED_CHECKPOINT.md#source-assisted-integration-30-october-2026) for denominators, fallbacks and verification details.


## Three-function repair and source names

Particle advance, standard follow and the sequence marker now match exactly: three additional selected C functions / 1,972 bytes. The full standalone selection is **2,039 C functions / 447,644 bytes (71.507% of the fixed candidate-code total)**. Twenty-one address-based functions receive source names; all 121 located source-candidate entries are indexed with confidence and conflicting alternatives. See [repair provenance](SOURCE_ASSISTED_CHECKPOINT.md#source-naming-and-three-function-repair-30-october-2026).


## 31 October SDK and handler recovery

Fifteen additional selected C functions / 744 bytes bring the full-cartridge-verified selection to **2,054 C functions / 448,388 bytes (71.626% of the fixed candidate-code total)**, a gain of 0.119 percentage points. Three SDK functions and twelve tiny handler stubs passed independent checks and the full original-cartridge build. See the source-assisted checkpoint document for provenance, timing and concurrent-worker attribution.


## Thirty-minute continuation, 31 October

The verified standalone selection is now **2,066 C functions / 455,668 bytes (72.789% of the fixed candidate-code total)**. This adds **12 C selections / 7,280 bytes**, or **1.163 percentage points**: six new recoveries or repairs and six existing app matches integrated with verified data placement. The complete original cartridge rebuild remains byte identical. The source-assisted checkpoint document separates new recoveries, carried-over work, app acceptance and verification.


## Focused thirty-minute continuation, 31 October

The standalone selection reaches **2,077 C functions / 461,364 bytes (73.699% of the fixed candidate-code total)**, adding **11 selections / 5,696 bytes**, or **0.910 percentage points**, over commit `4082329`. The pass repaired switch selectors and constant-pool boundaries in existing drafts and recovered the audio initializer, graphics-task routine and Controller Pak file listing. The complete original cartridge remains byte identical. See [the focused-session report](SOURCE_ASSISTED_CHECKPOINT.md#focused-thirty-minute-continuation--31-october-2026) for attribution, source differences and verification.


## Ten-match source-assisted continuation, 31 October

Ten additional selected C functions / 1,636 bytes bring the selection to **2,087 C functions / 463,000 bytes (73.960% of the fixed candidate-code total)**, up **0.261 percentage points**. The app has accepted and persisted all ten; all repository selections have saved app sources and headers. Seven narrowly scoped `-O3` profiles and source/type repairs account for the new matches. The complete original cartridge rebuild passes byte for byte, with no fallback among the ten additions. See [the ten-match report](SOURCE_ASSISTED_CHECKPOINT.md#ten-additional-source-assisted-matches--31-october-2026).


## User optimization-check checkpoint, 31 October

Ten user-discovered app matches add 14,728 selected C bytes: **2,097 C functions / 477,728 bytes (76.313%)**. All ten pass per-function checks and the complete original-cartridge rebuild. The 44 partially improved candidates are retained separately under `drafts/optimization-20261031` and excluded from coverage. See the source-assisted report for attribution and the particle constant-pool integration repair.


## Ten-function live-API pass, 31 October

Ten unmatched functions were tried through the live app API after `a7a06b6`: **six matched / 3,248 bytes**, one improved without matching, and three retained their previous near-match scores. Selection is **2,103 C functions / 480,976 bytes (76.832%)**, with a byte-identical full cartridge rebuild and saved app-project audit. See [the live-API report](SOURCE_ASSISTED_CHECKPOINT.md#ten-function-live-api-pass--31-october-2026) for individual results and source-assisted provenance.


## Ten additional live-API matches, 31 October

Ten previously unmatched functions add **2,372 selected C bytes**, bringing the full-cartridge-verified selection to **2,113 C functions / 483,348 bytes (77.211%)**. The live app has **2,114 saved matches / 484,128 bytes (77.335%)**; its older unexported constant-pool candidate accounts for the difference. All ten additions passed the app judge, saved-file audit, standalone checks and complete cartridge rebuild. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#ten-additional-live-api-matches--31-october-2026) for source and compiler repairs.


## Runtime and SDK continuation, 31 October

Ten further exact matches add **656 selected C bytes**, bringing the verified selection to **2,123 C functions / 484,004 bytes (77.315%)**. Seven runtime helpers need MIPS III with the O32 ABI; two thread routines need SDK register locals and `-O1`; the filter initializer matches with its original aligned record and local declarations. A guarded ELF ABI metadata fix permits the runtime objects to link without changing their code. All ten pass the complete original-cartridge comparison and are persisted in the app, which has 2,124 matches. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#runtime-and-sdk-live-api-continuation--31-october-2026).


## 31 October 2026 — ten audio and game-source matches

Ten additional live-API matches add **1,988 bytes**, bringing standalone selection to **2,133 C functions / 485,992 bytes (77.633%)**. Typed original SDK records, source-body repairs and verified per-function optimization settings recovered audio setup, volume, release, controller-pak checking, timekeeping, a memory-pool constructor and the sound wrapper. The full cartridge remains byte-identical. The app has 2,134 persisted matches; its older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#audio-and-game-source-live-api-continuation--31-october-2026).


## 31 October 2026 — ten thread, messaging and runtime matches

Ten more exact live-API matches add **2,560 bytes**, bringing standalone selection to **2,143 C functions / 488,552 bytes (78.042%)**. Original SDK types, register locals and `-O1` recovered timer, thread and message routines. Two runtime helpers needed MIPS III/O32, the voice-kill routine needed `-O3`, and the sequence-player constructor matched at `-O2`. The complete cartridge remains byte-identical; all ten are persisted in the app and selected in the repo. The older app-only constant-pool match remains the sole export gap. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#thread-message-and-runtime-live-api-continuation--31-october-2026).


## 31 October 2026 — ten controller, timer and matrix matches

Ten new live-API matches add **2,728 bytes**, bringing standalone selection to **2,153 C functions / 491,280 bytes (78.478%)**. Original SDK packet/pad/timer records and loops recovered controller and timer routines; both matrix converters matched at their existing `-O2` settings. Device managers and timer initialization needed their original global definitions, whose extern-only replacements emitted different address-load sequences. The complete cartridge remains byte-identical. All ten sources are persisted in the app and selected in the repo; the older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#controller-timer-and-matrix-live-api-continuation--31-october-2026).


## 31 October 2026 — ten controller setup and memory-pack matches

Ten new live-API matches add **5,304 bytes**, bringing standalone selection to **2,163 C functions / 496,584 bytes (79.325%)**. Original SDK directory, inode and controller records, function bodies and `-O1` recovered controller initialization and memory-pack file operations. Controller initialization also needed its existing ROM division helper explicitly identified at the call sites. The complete cartridge remains byte-identical. All ten sources and contexts are persisted in the app, with all ten selected in the repo. The older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#controller-setup-and-memory-pack-live-api-continuation--31-october-2026).


## 31 October 2026 — ten Controller Pak matches through source preparation

Ten new live-API matches add **6,080 bytes**, bringing standalone selection to **2,173 C functions / 502,664 bytes (80.296%)**. Original SDK record layouts, function bodies, macros and existing `-O1` settings recovered packet, RAM-transfer, inode, file-I/O and pack-ID routines. One candidate needed its missing bounds-check macro; another needed a call-site-supported alias for the count-register helper. The complete cartridge remains byte-identical. All ten sources and contexts are persisted in the app and selected in the repo; the older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#controller-pak-source-preparation-api-continuation--31-october-2026).


## 31 October 2026 — ten checker, matrix and audio matches

Ten new live-API matches add **6,008 bytes**, bringing standalone selection to **2,183 C functions / 508,672 bytes (81.256%)**. Original SDK declarations, bodies and verified per-function profiles recovered the Controller Pak checker, two corruption helpers, two matrix builders and five audio routines. Correct math-helper prototypes and target-supported aliases resolved remaining call differences. The synthesizer's retail allocation requests 76 bytes versus the reference header's 72-byte type; the source records that observed extent explicitly. The complete cartridge remains byte-identical. All ten sources and contexts are persisted in the app and selected in the repo; the older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#checker-matrix-and-audio-source-preparation-continuation--31-october-2026).


## 31 October 2026 — ten effects, playback and math matches

Ten new live-API matches add **5,688 bytes**, bringing standalone selection to **2,193 C functions / 514,360 bytes (82.165%)**. Original SDK types, helper declarations and ABI macros recovered effects, resampling, raw playback and event posting; the SDK revision's trailing effect callback explains the earlier four-byte allocation discrepancy. Disk resume and sine matched their original SDK implementations. Three improved audio drafts remain unmatched and are excluded from coverage. The complete cartridge remains byte-identical. All ten sources and contexts are persisted in the app and selected in the repo; the older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#effects-playback-and-math-live-api-continuation--31-october-2026).


## 31 October 2026 — ten SDK I/O and controller matches

Ten new source-assisted live-API matches add **4,928 bytes**, bringing standalone selection to **2,203 C functions / 519,288 bytes (82.952%)**. All ten match IDO 5.3 at `-O1` with the recorded common flags. Original SDK declarations, numeric volatile MMIO macros, response-record alignment and target-supported retail disk recovery changes recovered the functions. Whole-cartridge verification passed, and app source/header persistence was audited. The disk initializer remains a partial draft, excluded from coverage. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#sdk-io-and-controller-live-api-continuation--31-october-2026).


## 1 November 2026 — five matches from ten main candidates

The source-assisted live-API batch recovered **five exact matches / 2,600 bytes** and improved five other drafts. Standalone selection reaches **2,208 C functions / 521,888 bytes (83.367%)**, up **0.415 percentage points**. Original SDK object definitions, a symbolic NMI-buffer address, typed integer-runtime helpers, VI context records at `-O1`, and original hash records/loops recovered the matches. All five pass individual checks and the complete original-cartridge rebuild; app source/header persistence is audited. The five partial drafts remain excluded from coverage. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#ten-candidate-sdk-and-typed-context-continuation--1-november-2026).


## 1 November 2026 — seven typed-source matches from ten candidates

The source-assisted live-API batch recovered **seven exact matches / 1,880 bytes** and improved one other draft (score 457 to 60); two candidates did not improve. Standalone selection reaches **2,215 C functions / 523,768 bytes (83.667%)**, up **0.300 percentage points**. Original instance/vector/graphics records, callback types, local arrays and per-function `-O3` profiles recovered the matches. An instruction-identical draft still failed anonymous-array padding checks; referencing the existing named ROM arrays resolved it without changing the judge. All seven pass individual checks and the complete original-cartridge rebuild; app source/header persistence is audited. Partial drafts remain excluded from coverage. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#typed-original-source-and-profile-continuation--1-november-2026).


## 1 November 2026 — three typed-record matches from ten candidates

The source-assisted live-API batch recovered **three exact matches / 1,392 bytes**. Standalone selection reaches **2,218 C functions / 525,160 bytes (83.890%)**, up **0.222 percentage points**. The load constructor required its original records and verified retail error branches; the region test matched original declarations at `-O3`; the scheduler matched original records, timer widths and helper prototypes at `-O2`. All three pass individual checks and the complete original-cartridge rebuild; app source/header persistence is audited. The seven misses retain their starting best scores and working profiles, with failed-experiment notes saved. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#typed-records-retail-branches-and-scheduler-continuation--1-november-2026).


## 1 November 2026 — five typed-source and helper-prototype matches

Ten source-assisted live-API candidates yielded **five exact matches / 1,356 bytes**, reaching **2,223 C functions / 526,516 bytes (84.106%)**, up **0.217 percentage points**. Original records, verified `-O3` profiles, ROM-supported filesystem behavior and corrected material/sound helper prototypes recovered the matches. Five misses retain their starting best scores. Complete original-cartridge verification passed, and all selected sources and required app contexts were audited. The older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#typed-source-profiles-and-helper-prototypes--1-november-2026).


## 1 November 2026 — eight particle matches from ten candidates

Eight source-assisted live-API matches add **2,228 bytes**, reaching **2,231 C functions / 528,744 bytes (84.462%)**, up **0.356 percentage points**. Original particle records, vector/quaternion aggregate calling conventions and corrected helper declarations matched at `-O3`. The compact-sequence constructor and scheduler main loop retain their starting scores and `-O2` profiles. All eight pass individual checks and the complete original-cartridge rebuild; saved app sources and required contexts were audited. The older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#particle-records-and-aggregate-calls--1-november-2026).


## 1 November 2026 — eight cache, scheduler and intersection matches

Eight source-assisted live-API matches add **3,344 bytes**, reaching **2,239 C functions / 532,088 bytes (84.996%)**, up **0.534 percentage points**. Original typed records, local static cache scope, aggregate calls, 64-bit buffer size and timing-object definitions recovered the matches at verified per-function `-O2`/`-O3` profiles. The decompression draft improves 1340 to 780 but remains excluded from coverage; the bank initializer is unchanged. All eight pass individual checks and the complete original-cartridge rebuild; saved app sources/contexts were audited. The older constant-pool export blocker remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#cache-scheduler-and-local-static-context--1-november-2026).


## 1 November 2026 — ten animation, particle and static-instance matches

Ten source-assisted live-API matches add **4,424 bytes**, reaching **2,249 selected C functions /
536,512 bytes (85.703%)**, up **0.707 percentage points**. Original aggregate calls, SDK macros,
local static storage, a typed application-object view and retail switch-table evidence recovered
the batch. All ten pass individual checks and the full original-cartridge rebuild. Live app and
saved progress are synchronized; the older constant-pool export gap remains separate.
See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#animation-static-instances-and-object-identity--1-november-2026).


## 1 November 2026 — seven menu, memory and animation-context matches

Seven matches from ten live-API candidates add **2,756 bytes**, reaching **2,256 selected C functions /
539,268 bytes (86.143%)**, up **0.440 percentage points**. Original records, typed application access,
an unsigned flags word, an original inline animation predicate and target-confirmed retail behavior
recovered the batch. Three scheduling/boundary candidates remain unresolved. All seven passed the full
cartridge rebuild; live and saved app progress are synchronized. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#menus-memory-and-inline-animation-context--1-november-2026).


## Save errors, aggregate ABI and retail layout — 1 November 2026

Eight of ten investigated live-API candidates now match exactly, adding **3,940 bytes**.
The standalone selection is **2,264 C functions / 543,208 bytes (86.772778%)**, up
**0.629381 percentage points**, with **143 assembly entries** including padding. The live app has
**2,265 persisted exact matches / 543,988 bytes (86.897376%)**, **82 open** and **59 assembly candidates**.
The existing 780-byte constant-pool export blocker is unchanged. Full original-cartridge verification
and saved app/repository source/context audits pass. See [provenance and remaining near misses](SOURCE_ASSISTED_CHECKPOINT.md#save-errors-aggregate-abi-and-retail-layout--1-november-2026).


## Menus, legal screen and retail error handling — 1 November 2026

Seven of ten live-API candidates match exactly, adding **3,608 bytes** and **0.576347 percentage points**.
Standalone selection reaches **2,271 C functions / 546,816 bytes (87.349124%)**. Original typed contexts,
retail menu sound calls, a timer-offset correction, controller-pak error cases and a float helper
prototype recovered the batch at `-O2`. Three SDK ABI/register-allocation candidates remain unmatched.
Full original-cartridge verification and persisted app/repository audits pass; the older 780-byte
constant-pool export gap is unchanged. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#menus-legal-screen-and-retail-error-handling--1-november-2026).


## Scene, cinematics, sort and boss context — 2 November 2026

Six of ten live-API candidates match exactly, adding **4,252 bytes** and **0.679220 percentage points**.
Standalone selection reaches **2,277 C functions / 551,068 bytes (88.028345%)**. Actual records,
callback and helper bindings, original private-helper line numbering, float-argument prototypes and
ROM-confirmed retail branches recovered the batch. Four misses retain their previous bests.
Full original-cartridge verification and persisted app/repository audits pass; the older 780-byte
constant-pool export gap is unchanged. CPU changes in PR #293 separately reproduce four known
matches in controlled replays and are not counted as new coverage here.
See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#scene-cinematics-sort-and-boss-context--2-november-2026).


## Inline statement lines, original source lines and angle checks — 2 November 2026

Four of ten investigated live-API candidates match exactly, adding **3,428 bytes** and
**0.547593 percentage points**. Standalone selection reaches **2,281 C functions /
554,496 bytes (88.575938%)**. The app retains **2,282 persisted exact matches /
555,276 bytes (88.700536%)**, **65 open** and **59 assembly candidates**.
Full original-cartridge verification and saved source/context audits pass. The older 780-byte
constant-pool export gap remains separate. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#inline-statement-lines-original-source-lines-and-angle-checks--2-november-2026).


## Animation helpers, original declarations and retail cheats — 2 November 2026

Five of ten investigated functions match through the live API, adding **8,136 bytes** and
**1.299656 percentage points**. Standalone selection reaches **2,286 C functions /
562,632 bytes (89.875593%)**. The app retains **2,287 persisted exact matches /
563,412 bytes (90.000192%)**, **60 open** and **59 assembly candidates**.
Original inline helpers, local declaration order and ROM-confirmed retail differences recovered
these matches. The full original-cartridge build and saved source/context audit pass; the older
780-byte constant-pool export gap remains separate. CPU repair rules in app PR #301 have 179
focused tests and reproduce two historical matches without claiming extra coverage.
See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#animation-helpers-original-declarations-and-retail-cheats--2-november-2026).


## Same-file boss storage and retail map cinema state — 2 November 2026

Two of ten investigated candidates match, adding **1,148 bytes / 0.183383 percentage points**.
Standalone: **2,288 C functions / 563,780 bytes (90.058977%)**. App: **2,289 saved exact /
564,560 bytes (90.183575%)**, **58 open**, **59 assembly candidates**. The complete original
cartridge rebuild and source/context audit pass. Same-file boss storage removes redundant
address-high loads; a retail cinema map state completes the map routine. The older 780-byte
constant-pool gap remains. Eight misses and a corrected legal-screen source identity are recorded
in the [session report](SOURCE_ASSISTED_CHECKPOINT.md#same-file-boss-storage-and-retail-map-cinema-state--2-november-2026).
CPU application changes are in PRs #303/#307, with 211 focused tests and separately labelled historical replays.


## CPU context triage — 2 November 2026

Next ten candidates investigated; **0 new exact matches**, so coverage is unchanged at **90.058977%
selected C /90.183575% persisted app matches**. All ten have live app investigation notes. The saved
source/context/repository audit passes with the existing 780-byte export gap. See the
[session report](SOURCE_ASSISTED_CHECKPOINT.md#cpu-context-triage-and-next-ten-investigations--2-november-2026).
App PR312 adds measured context routing and bounded typed-field recovery; whole-unit ABI context remains open.


## Ten more verified matches — 2 November 2026

**Ten new matches /15,600 bytes /+2.491965 percentage points.** Selected C: **2,298 functions /
579,380 bytes (92.550942%)**. Persisted app: **2,299 functions /580,160 bytes (92.675540%)**.
There are 48 open candidates, 59 set aside as assembly and 109 assembly build entries. All ten are synced;
the saved source/header audit and full original-cartridge rebuild pass. Only the existing 780-byte
`func_800587B8` export gap remains. See [the session report](SOURCE_ASSISTED_CHECKPOINT.md#ten-more-verified-matches--2-november-2026)
for source identities, per-function flags and measured evidence. Correct source mappings, real inline
helpers and O3 on complete typed source recovered functions that earlier draft/permutation trials missed.


## Runtime C and compiler-context export — 2 November 2026

Live app and selected C now agree at **2,318 functions /593,452 bytes (94.798822%)**.
Nine new MIPS III/O32 O1 runtime recoveries add 576 bytes. The pending 816-byte fault
handler is finalized with independently verified real predecessor context. Earlier
legal-screen, cache, wall-collision and region-collision matches are exported, and
the old 780-byte constant-pool export gap is resolved. The full original cartridge
rebuild and saved source/header audit pass. See the [session report](SOURCE_ASSISTED_CHECKPOINT.md#runtime-arithmetic-and-verified-compiler-context--2-november-2026)
for separate discovery/export counts and the K&R argument-promotion finding.


## One-hour private-unit investigation — 2 November 2026

One newly accepted live match: `func_800A0F38`, **460 bytes**. The existing VI-manager
constructor (392 bytes), preserved as real context and independently rejudged,
restored six missing internal alignment NOPs at IDO 5.3 O1. The complete cartridge
rebuild passes. Live app and selected C agree at **2,319 functions /593,912 bytes
(94.872303%)**, with no app-only export gap. Existing concurrent source/context
polishes were also synchronized and verified; they are not additional matches.

Another **32 candidates /22,532 bytes** pass independent code/data judging and
matching-only normalization in read-only replay, but require the prepared app
update, normal live promotion and a complete cartridge rebuild. They are staged
under [drafts](../drafts/private-units-20261102/README.md), not counted in this
checkpoint. The restart was not performed without the pending user approval
required by the app's AGENTS.md. App support and measured compiler evidence are in
[PR #341](https://github.com/RetroReversing/decompdecomp/pull/341).

A separate scheduler boundary proposal identifies a split-off 56-byte epilogue;
it is documented but not applied or counted as a match. Original target bytes,
extents, judging and compression gates remain unchanged in this checkpoint.


## First ten private-unit promotions — 2 November 2026

Ten source-assisted candidates from the prepared 32 are now freshly verified
through the authenticated live app API and selected in the standalone build:
`_Ldtob`, `__alSeqNextDelta`, `alAdpcmPull`, `alBnkfNew`, `alCSeqNew`, `alCSeqNextEvent`, `alEnvmixerPull`, `alSeqNew`, `alSeqNextEvent`, `func_80001D30`.

They add **6,168 bytes**, taking both the persisted app and selected C to
**2,329 functions /600,080 bytes (95.857587%)**, up **0.985285 percentage points**.
There are **27 open** and **50 assembly** candidates. The standalone manifest has
2,407 entries including padding, with **78 assembly fallbacks**. Another 22 prepared
candidates /16,364 bytes remain outside the selected C totals.

The SDK units use IDO 5.3 O3; the 288-byte boot entry uses O2 and three real
already-matched predecessors. Common flags are `-mips2 -G 0 -non_shared
-Xcpluscomm -Wab,-r4300_mul`. Real private caller/callee bodies reproduce IDO's
private register conventions; independently exact context is not counted twice.
The boot predecessor context restores compiler alignment without inserted padding.

Each entry passed the unchanged linked code/data judge, the repository's individual
check and a fresh complete original-cartridge rebuild. SHA-1 remains
`88916d5d2e2470f395ad8f4245d34138ef2d156a`. Saved source/header, repository ownership
and both-direction match-selection audits pass. No target bytes or extents changed.
The compiler-context support is merged in decompdecomp PR #341; the documented
build dependency now includes that support. During the session another app update
interrupted one job; its claim expired normally before a fresh verified submission.


## All 32 private-unit candidates completed — 2 November 2026

The remaining **22 prepared source-assisted functions /16,364 bytes** now pass
fresh live-app judging and the complete repository build. Together with the
first ten, **all 32 candidates /22,532 bytes** are persisted and selected C.
Coverage is **2,351 functions /616,444 bytes (98.471595%)**, up **3.599292
percentage points** from the 2,319-function checkpoint. The final batch alone adds
2.614007 percentage points. There are **7 open** and **48 assembly** candidates;
the standalone manifest retains **56 assembly entries** among 2,407 entries
including padding labels. These are fixed candidate-code figures, not whole-game
coverage or a claim of complete C recovery.

The final batch covers private bank, MIDI/compressed-sequence, sound-player,
printf/long-double, envelope and ADPCM helpers. IDO 5.3 O3 uses real caller/callee
units to recover private register conventions. The boot entry from the first batch
uses O2 and three independently exact real predecessors. Common flags are
`-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`.
Two former assembly candidates (`func_800A262C` and `func_800A42C4`) were reopened
through the normal API and accepted with fresh exact proof. They were not
reclassified from a diff score alone.

Every real context body was independently matched at its known original entry;
only each selected entry was published and normalized for export. Context bodies
are not additional matches. Source/header/profile bundles remain together.
No target bytes, function extents, judging gates or compression checks changed.
All 32 promoted candidates are listed with their original source/header provenance
in [the promotion report](../drafts/private-units-20261102/README.md).

The complete **8,388,608-byte original cartridge** rebuild is byte identical,
including the RNC-packed main program; SHA-1 remains
`88916d5d2e2470f395ad8f4245d34138ef2d156a`. Saved sources/headers, selected C,
repository-owned files and both-direction match-selection audits pass, with no
app-only export gap and no progress save pending.


## Scheduler extent and original assembly verification — 3 November 2026

The 256-byte scheduler candidate omitted its original 56-byte epilogue. A reviewed
normal join API correction restored the unchanged 312-byte extent; regenerated
repository target bytes equal the live target. Actual C with three independently
exact predecessors freshly matched through the app API and passed the complete
original-cartridge rebuild. The former tail address is preserved as an internal
linker symbol. The layout correction is recorded in commit `64cbd9b`.

App and standalone selection now agree at **2,352 C entries /616,756 bytes
(98.521434%)** of the unchanged 626,012 candidate bytes. The standalone manifest
has 2,406 entries including padding, with 54 assembly fallbacks. The live project
has **one open** candidate and **52 assembly** candidates. No export gap remains;
saved C/header and repository ownership audits pass. Full cartridge SHA-1 remains
`88916d5d2e2470f395ad8f4245d34138ef2d156a`.

The user explicitly approved preserving verified original assembly rather than
calling it matching C. Five formerly open routines were assembled from original
source with installed IDO 5.3 and passed exact linked code/data checks: both thread
queue helpers (including `func_800A5F34` / `__osPopThread`), `_bcopy`, `_bzero`,
and `func_80098E28` / `adpcmDecodeSignal`. Their unchanged extents total 1,256
bytes. They remain assembly and add no selected-C coverage. See
[original-source assembly evidence](ASSEMBLY_VERIFICATION.md).

`Campaigner_Update` / `func_8004D6FC` remains unmatched. A pure nonvolatile guard
reordering improves its score 1190 → 775 through the ordinary live attempt API;
the data/constant address issues resolve, but the first block's instruction
ordering still differs. A five-minute deep CPU pass retained 775 after 185 tested
variants. Its [source/header draft](../drafts/remaining-20261103/README.md) is kept
out of the cartridge selection. This session does not claim the remaining C
function is complete.

## Final seven resolved — 3 November 2026

`Campaigner_Update` now matches all 976 bytes through the live app API using its
real, independently exact constructor as compiler context. Normal repository sync
accepted it with no skipped functions and passed the complete original-cartridge
build. The app now has **zero open functions**, **2,353 exact C matches /617,732
bytes (98.677342%)**, and 52 assembly entries. The standalone manifest has 2,353 C
and 53 assembly/padding fallbacks. The five formerly open original assembly
routines remain verified assembly, as explicitly requested; they are not C matches.

See [the final seven report](FINAL_OPEN_FUNCTIONS.md) for the compiler-context
finding, scope and cartridge verification. The previous 775-score draft is historical.
