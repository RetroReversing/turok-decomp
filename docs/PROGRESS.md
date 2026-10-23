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
