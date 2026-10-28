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
