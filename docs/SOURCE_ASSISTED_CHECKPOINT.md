# Source-assisted checkpoint

The user authorized publishing the combined source-assisted checkpoint on 24 October 2026.

User-authorized source-assisted Sol trial: 1,563 selected C functions, 243,836 matching bytes / 626,012 detected candidate-code bytes (38.950691%). Gain over the ROM-only baseline: 677 functions / 182,000 bytes. Original source and headers were reused; this is not a ROM-only decompilation result.

All 792 raw additions passed independent per-function checks; 115 candidates totaling 39,200 bytes were excluded for data layout. The final 1,563 C / 2,405 function export used 842 assembly functions and no fallback selections. Expanded image, normalized cartridge, and pair-swapped user ROM were byte-identical. Normalized SHA-1: 88916d5d2e2470f395ad8f4245d34138ef2d156a.

Private experiment and provenance: /Volumes/Data/Decomps/nintendo-64/turok-europe-ai/experiments/sol-source-assisted-30min-20261023. Verification completed 2026-10-23T23:27:35.640Z.

## Combined verified checkpoint

The current local selection contains 1,798 C functions and 363,040 matching bytes / 626,012 detected candidate-code bytes (57.99249855%). It combines the verified Astra Low 1,763-function baseline with all 35 distinct gains from the subsequent same-checkpoint trials. Sol High supplied 29 gains; Sol Low supplied five additional functions (2,088 bytes); Astra High supplied one additional function (1,364 bytes). Luna Low's sole match was already present; Luna High added none.

All six additions beyond Sol High passed fresh isolated checks in the merged workspace. The complete merged expanded image, normalized original cartridge, and reconstructed user input byte order were byte-identical. Export selected 1,798 C functions / 2,405 total, with 607 assembly functions and no automatic fallbacks. Cartridge SHA-1 remains 88916d5d2e2470f395ad8f4245d34138ef2d156a. This verifies code selection, not full decompilation or portability.

Private integration evidence: /Volumes/Data/Decomps/nintendo-64/turok-europe-ai/experiments/combined-verified-20261024 (merge-provenance.json, export-result.json, cartridge-verification.json, workspace/). C and headers copied into this checkout are byte-identical to that passing export. The user subsequently authorized pushing this combined checkpoint. Local binary inputs and research evidence remain private.

## Workspace consolidation

The main checkout is /Volumes/Data/Decomps/nintendo-64/turok-decomp. Private build inputs and the compact active analysis workspace are retained under ignored paths in this checkout. Per-run reports, score summaries and verification records are preserved in .local/evidence/; duplicate per-run workspaces have been removed. Historical absolute paths above identify where the experiments originally ran.
