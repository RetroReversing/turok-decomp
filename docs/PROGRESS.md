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
