# Resolution of the final seven open functions

On 3 November 2026, both actual C functions were matched and the five original
hand-written assembly routines were freshly assembled and verified. The user
explicitly chose to preserve verified assembly rather than describe it as C.

| Entry | Resolution | Bytes |
| --- | --- | ---: |
| `func_8002BA48` | Exact scheduler C, with its reviewed original epilogue restored to the function extent | 312 |
| `Campaigner_Update` / `func_8004D6FC` | Exact original C compiled with its independently exact constructor as context | 976 |
| `__osEnqueueThread` | Verified original assembly | 72 |
| `func_800A5F34` / `__osPopThread` | Verified original assembly | 16 |
| `_bzero` | Verified original assembly | 156 |
| `_bcopy` | Verified original assembly | 772 |
| `func_80098E28` / `adpcmDecodeSignal` | Verified original assembly and referenced coefficient data | 240 |

See [the original assembly verification](ASSEMBLY_VERIFICATION.md) for provenance,
source hashes and assembler profiles. Assembly adds no selected-C coverage.

## Why the last C function resisted isolated compilation

The preserved original `campaign.o` contained the same 976-byte update and opening
instruction order as the retail game. Isolated source compiled with IDO 5.3 at
`-O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul` differed in the first
weapon-check block. A reordered-condition draft scored 775; it was not exact.
Boolean rewrites, caching, compiler-phase overrides and the bounded deep pass did
not recover the original scheduling.

Compiling the real, already-matched constructor before the update recovered the
original ordering. The constructor stores the update's address. Both bodies were
independently linked at their known retail addresses: 492 exact bytes for the
constructor and 976 for the update, including referenced-data checks. Controlled
reduction isolated the address-taking statement; this does not establish which
internal compiler pass causes the effect. Unused static/inline context did not
reproduce it. No dummy helper, invented alignment padding or target instructions
were added to the C.

The app change is [decompdecomp PR #384](https://github.com/RetroReversing/decompdecomp/pull/384).
It requires every public context body to be already matched and freshly exact,
with unchanged identities, extents and non-overlapping ROM slots. Only the update
is extracted into its selected slot. The constructor is not exported twice or
counted as a new match. A forward declaration in the C unit keeps the callback
reference valid when export uses its proper source name.

## Coverage audit correction — 4 November 2026

The later [audit of all 52 assembly-status entries](ASSEMBLY_ENTRY_AUDIT.md)
found eleven truncated C candidates followed by raw binary continuation blocks.
The zero-open result below is a statement about the detected queue, not complete
retail function discovery or whole-game matching. Those eleven entries must not
be described as confirmed original assembly. The five fresh assembly proofs
above remain valid.

## Persisted result and cartridge verification

The exact pair was promoted through the live app API. Its export-safe declaration
was saved through the app's freshly judged readable-source workflow. Normal
repository sync accepted the update with no skipped functions and verified the
complete cartridge build. The private preflight independently produced the same
original 8,388,608-byte cartridge, SHA-1
`88916d5d2e2470f395ad8f4245d34138ef2d156a`, including RNC compression.

The live project has **zero open functions**, **2,353 exact C matches /617,732
bytes (98.677342%)**, and **52 assembly entries /8,280 bytes**. The fixed candidate
code total remains 626,012 bytes. The standalone manifest includes one additional
padding entry: 2,406 entries, 2,353 selected C and 53 assembly fallbacks. Zero open
functions does not mean 100% C or that every assembly fallback has been rebuilt
from original assembly source. The five above have that additional proof.
