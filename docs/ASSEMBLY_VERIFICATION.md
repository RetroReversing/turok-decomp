# Verification of the five formerly open assembly routines

The user approved verifying original assembly rather than reporting it as matching C.
All five were freshly assembled from existing original source on 3 November 2026,
then passed the ordinary linked code/data comparison at their unchanged retail
addresses. This is stronger than the earlier instruction-shape classifications.
They remain assembly fallbacks and do not increase the selected-C totals.

| Retail entry | Original routine | Bytes | Original file | Working assembler profile |
| --- | --- | ---: | --- | --- |
| `__osEnqueueThread` | `__osEnqueueThread` | 72 | `EXCEPTASM.S` | IDO 5.3 `-O1 -mips2 -G 0 -non_shared` |
| `func_800A5F34` | `__osPopThread` | 16 | `EXCEPTASM.S` | IDO 5.3 `-O2 -mips2 -G 0 -non_shared` |
| `_bzero` | `_bzero` | 156 | `BZERO.S` | IDO 5.3 `-O2 -mips2 -G 0 -non_shared` |
| `_bcopy` | `_bcopy` | 772 | `BCOPY.S` | IDO 5.3 `-O2 -mips2 -G 0 -non_shared` |
| `func_80098E28` | `adpcmDecodeSignal` | 240 | `adpcm.s` | IDO 5.3 `-O2 -mips2 -G 0 -non_shared` |

## Method and provenance

The SDK routines came from the locally supplied original `LIBULTRA/OS/EXCEPTASM.S`,
`LIBULTRA/LIBC/BZERO.S` and `LIBULTRA/LIBC/BCOPY.S`. The decoder is the actual
`adpcmDecodeSignal` definition in the game's `adpcm.s`, whose source identifies it
as an assembly conversion. The source, compiler objects and ROM data remain local.
No generated assembly or binaries are committed.

Preprocessing provided ordinary O32 register names and LEAF/END declarations,
selected the original N64 SDK thread layout (`T_NEXT=0`, `T_PRIORITY=4`, `T_QUEUE=8`),
selected big-endian assembly and disabled the optional SDK debug-only pop store.
The obsolete weak aliases were omitted from the private verification input; they
emit no instructions. Symbolic game calls and the two decoder coefficient tables
were bound to their already-known original entries. No target instructions were
copied into the reference source, and no target bytes/extents were modified.

The rebuilt source's linked bytes must equal every byte of each original target;
referenced emitted data, including the decoder coefficient tables, pass the same
data checks. The enqueue helper needs the O1 assembler profile; O2 was tested and
rejected. This is a measured matching profile, not proof of the historical flags.

## Original source SHA-256

- `EXCEPTASM.S`: `9676506e69df4af38ffa526634389495ae85985079515cf78c5a06230ea45e74`
- `BZERO.S`: `4d747dad3c357d5fde8d77bbe01285639865a24316a49f04f299761f974ebad9`
- `BCOPY.S`: `7b7b3796001b8afbce69e4816c20b533d89d0932c9d3f5fb9eb5ecab8d1e7099`
- `adpcm.s`: `64c6b5f54af3761c2eb17c6462c6d418d0a5309c9473505fad64ea6e57798fa1`

The app history records the proof and the explicit assembly classification.
`func_800A5F34` is `__osPopThread`: the near-match C draft had the same algorithm
but a different temporary register. That was not evidence of a missing C algorithm.
Keeping these routines as verified assembly accurately reflects how the game was built.
