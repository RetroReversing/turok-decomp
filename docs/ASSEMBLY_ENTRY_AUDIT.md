# Audit of every assembly-status entry

Audited on **4 November 2026**, against Turok repository checkpoint `8a5bbce`
and a read-only view of the live app. This is a classification audit, not a new
matching session: no targets, statuses, extents, source selections or compiler
settings were changed.

## Follow-up recovery

The eleven fragments below have since been expanded and reopened through the live API. See [the code recovery audit](CODE_RECOVERY_AUDIT.md) for full extents, raw-region leads and discovery validation. The table below preserves the original audit checkpoint.

## Conclusion

**The 52 assembly-status entries are not all confirmed handwritten assembly.**
Eleven are truncated C candidates (100 bytes total). Ten have named archived C
object/source evidence; the eleventh has a likely C candidate. Their tiny current
extents end without returns, immediately before raw binary continuation blocks.
Treating them as completed assembly hides unfinished code analysis.

The other 41 entries have assembly source evidence, with different proof strengths:

| Evidence | Entries | Current entry bytes | What it establishes |
| --- | ---: | ---: | --- |
| Fresh original-assembly rebuild | 5 | 1,256 | Freshly assembled and linked code/data passed the ordinary exact-byte judge. |
| Archived assembly object corroboration | 35 | 5,592 | Entire current extent agrees with a corresponding archived assembly object region outside relocation fields; not a fresh linked/data proof. |
| Assembly source and instruction evidence | 1 | 1,332 | Privileged exception code and original assembly source; checked SDK revision differs. |
| Truncated C candidate — not confirmed assembly | 11 | 100 | Current boundary and assembly classification need review; these are not completed C matches. |

**Correction to completion claims:** 2,353 exact selected C entries cover 617,732
of the app’s 626,012 detected candidate bytes (98.677342%). Zero open entries does
not mean all retail functions were discovered or decompiled. The build preserves
unselected bytes verbatim, so an identical cartridge does not prove complete
source reconstruction. The eleven adjacent raw blocks alone total **82,976 bytes**;
this is raw storage, not a measured amount of additional C code. Other raw blocks
also need a code/data coverage audit before claiming whole-game completion.

## Each of the 52 entries

Addresses and byte sizes are the current app extents. Source names below describe
identified routines or regions; they do not rename the live app. Several entries
are internal labels or combined regions, rather than standalone functions.

- **Fresh:** ordinary exact linked code/data proof already recorded.
- **Object:** archived assembly object comparison plus located assembly source.
- **Source:** assembly is clear, but exact archived-version/source rebuild is unresolved.
- **Fragment:** incomplete candidate; do not count it as confirmed original assembly.

| Retail address / current name | Bytes | Routine / source evidence | Grade | Reason and limitation |
| --- | ---: | --- | --- | --- |
| `0x80000640` / `func_80000640` | 200 | `Propack_UnpackM1` — `rnc1.s / rnc1.o` | **Object** | Register-preserving entry wrapper; explicit register saves and restores. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000708` / `func_80000708` | 436 | `pp_Unpack` — `rnc1.s / rnc1.o` | **Object** | Manual stack frames and shared decoder registers across helper calls. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x800008BC` / `func_800008BC` | 216 | `input_value` — `rnc1.s / rnc1.o` | **Object** | Internal decoder helper; persistent s0/t-register state, not an ordinary C ABI. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000994` / `func_80000994` | 52 | `input_bits` — `rnc1.s / rnc1.o` | **Object** | Bit-buffer helper with explicit temporary stack save around refill. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x800009C8` / `func_800009C8` | 60 | `input_bits3` — `rnc1.s / rnc1.o` | **Object** | Refill helper updates the caller’s shared bit-count/buffer registers. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000A04` / `func_80000A04` | 36 | `read_long` — `rnc1.s / rnc1.o` | **Object** | Byte-assembly loop with explicit register protocol and delay-slot decrement. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000A28` / `func_80000A28` | 384 | `make_huftable` — `rnc1.s / rnc1.o` | **Object** | Huffman-table helper uses the decoder’s shared registers and manual call saves. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000BA8` / `func_80000BA8` | 36 | `getrawREP` — `rnc1.s / rnc1.o` | **Object** | Internal literal-copy loop reads shared s3/s4/t0 registers. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000BD0` / `func_80000BD0` | 172 | `Propack_UnpackM2` — `rnc2.s / rnc2.o` | **Object** | Register-preserving entry wrapper for method 2. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80000C7C` / `func_80000C7C` | 1596 | `__PPUnpack` — `rnc2.s / rnc2.o` | **Object** | Method-2 decoder body, including internal branch labels and register protocol. Full current extent matches the corresponding archived object region, excluding declared relocation fields. |
| `0x80016CE8` / `func_80016CE8` | 8 | `CGameObjectInstance__DoDraw` — `romstruc.c` | **Fragment** | The first 32 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80022148` / `func_80022148` | 8 | `CGeometry__Decompress` — `geometry.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x8002E4EC` / `func_8002E4EC` | 4 | `CScene__DrawSky` — `scene.c` | **Fragment** | The first 32 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80052BCC` / `func_80052BCC` | 4 | `CTMove__UpdateTurokInstance` — `tmove.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80059994` / `func_80059994` | 12 | `CTMove__FireBullet` — `tmove.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x8005B964` / `func_8005B964` | 12 | `CTMove__ControlSwimMovement` — `tmove.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x8006BC88` / `func_8006BC88` | 8 | `AI_Single_Event` — `ai.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80075254` / `func_80075254` | 12 | `likely AI_Advance` — `ai.c` | **Fragment** | Closest examined archived candidate is AI_Advance: 29 of the first 32 normalized words agree; identity remains provisional. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x800859F8` / `CPause__DrawBar` | 8 | `CPause__DrawBar` — `pause.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x800915C4` / `func_800915C4` | 12 | `CPickup_Pickup` — `pickup.c` | **Fragment** | The first 128 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80096A74` / `func_80096A74` | 12 | `DoDrawMap` — `map.c` | **Fragment** | The first 32 bytes, extending beyond this truncated entry, match a unique named archived C object outside declared relocations; the corresponding C definition exists. No return in this tiny extent; continuation is in the adjacent raw binary block. Not evidence of handwritten assembly. |
| `0x80098C30` / `func_80098C30` | 272 | `adpcmDecode` — `adpcm.s / adpcm.o` | **Object** | Outer decoder saves s0–s7 explicitly and uses a second stack frame. The file explicitly identifies its assembly conversion; the complete current extent matches its archived object region outside relocations. |
| `0x80098D40` / `func_80098D40` | 52 | `adpcmReadBitsInitH` — `adpcm.s / adpcm.o` | **Object** | Initializes persistent t0/t1/t2 bit-reader state. The file explicitly identifies its assembly conversion; the complete current extent matches its archived object region outside relocations. |
| `0x80098D74` / `func_80098D74` | 60 | `adpcmReadBitsH` — `adpcm.s / adpcm.o` | **Object** | Consumes and reloads persistent t0/t1/t2 state. The file explicitly identifies its assembly conversion; the complete current extent matches its archived object region outside relocations. |
| `0x80098DB0` / `func_80098DB0` | 60 | `adpcmReadBitsInitD` — `adpcm.s / adpcm.o` | **Object** | Initializes persistent t3/t4/t5 state, outside the normal return ABI. The file explicitly identifies its assembly conversion; the complete current extent matches its archived object region outside relocations. |
| `0x80098DEC` / `func_80098DEC` | 60 | `adpcmReadBitsD` — `adpcm.s / adpcm.o` | **Object** | Consumes and reloads persistent t3/t4/t5 state. The file explicitly identifies its assembly conversion; the complete current extent matches its archived object region outside relocations. |
| `0x80098E28` / `func_80098E28` | 240 | `adpcmDecodeSignal` — `adpcm.s` | **Fresh** | Decoder uses explicit saved-register state and calls its assembly bit readers. Fresh linked code/data equality was verified on 3 November; see ASSEMBLY_VERIFICATION.md. |
| `0x8009D090` / `func_8009D090` | 12 | `__osGetFpcCsr` — `GETFPCCSR.S` | **Object** | Direct FCSR read through cfc1. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x8009D0A0` / `func_8009D0A0` | 16 | `__osSetFpcCsr` — `SETFPCCSR.S` | **Object** | Direct FCSR read/write through cfc1/ctc1. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x8009D1F0` / `func_8009D1F0` | 40 | `osWritebackDCacheAll` — `WRITEBACKDCACHEALL.S` | **Object** | Whole-cache maintenance loop emits cache instructions. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x8009D220` / `func_8009D220` | 160 | `osSetIntMask` — `SETINTMASK.S` | **Object** | Reads/writes CP0 Status and the hardware interrupt mask. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x8009E7A0` / `func_8009E7A0` | 8 | `sqrtf` — `SQRTF.S` | **Object** | Two-instruction sqrt.s leaf; the SDK source explicitly describes this assembly workaround for a compiler bug. Failure of C trials alone was insufficient evidence. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A16E0` / `func_800A16E0` | 116 | `osWritebackDCache` — `WRITEBACKDCACHE.S` | **Object** | Range/whole-cache paths contain cache 0x19 and cache 0x01. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A1760` / `func_800A1760` | 172 | `osInvalDCache` — `INVALDCACHE.S` | **Object** | Boundary and line loops contain cache 0x15, 0x11 and 0x01. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A5750` / `func_800A5750` | 32 | `__osDisableInt` — `INTERRUPT.S` | **Object** | mfc0/mtc0 directly clear Status interrupt-enable. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A5770` / `func_800A5770` | 28 | `__osRestoreInt` — `INTERRUPT.S` | **Object** | mfc0/mtc0 directly restore Status interrupt-enable. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A57D0` / `func_800A57D0` | 1332 | `__osExceptionPreamble + exception-handler region` — `EXCEPTASM.S` | **Source** | Kernel-register context saves, CP0 accesses and exception dispatch are unmistakably assembly; the SDK file defines these in assembly. The checked 2.0I object differs (263 normalized words in this region), so neither exact version nor an exact source rebuild is established. |
| `0x800A5D04` / `func_800A5D04` | 172 | `send_mesg, excluding its return pair` — `EXCEPTASM.S` | **Object** | Internal exception-message helper keeps ra in s2 and uses the exception handler’s register protocol. Its 172-byte prefix matches the 180-byte SDK body; the final 8 bytes are in the following entry. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A5DB0` / `pad_800A5DB0` | 60 | `send_mesg return + handle_CpU` — `EXCEPTASM.S` | **Object** | This is code, not padding: first the preceding helper’s jr s2/nop, then a 52-byte coprocessor-unusable handler. All 60 bytes match the corresponding contiguous SDK object region outside relocations. Boundaries/label need correction. |
| `0x800A5DEC` / `func_800A5DEC` | 256 | `__osEnqueueAndYield` — `EXCEPTASM.S` | **Object** | Saves a thread context, CP0 Status and floating registers, then transfers control to dispatch. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A5EEC` / `__osEnqueueThread` | 72 | `__osEnqueueThread` — `EXCEPTASM.S` | **Fresh** | SDK queue traversal/insertion routine is defined in assembly. Fresh linked code/data equality was verified on 3 November; see ASSEMBLY_VERIFICATION.md. |
| `0x800A5F34` / `func_800A5F34` | 16 | `__osPopThread` — `EXCEPTASM.S` | **Fresh** | SDK queue-pop routine is defined in assembly, even though its algorithm could be expressed in C. Fresh linked code/data equality was verified on 3 November; see ASSEMBLY_VERIFICATION.md. |
| `0x800A5F44` / `func_800A5F44` | 388 | `__osDispatchThread + __osCleanupThread` — `EXCEPTASM.S` | **Object** | Restores kernel/thread/FPU state and returns with eret. The 388-byte entry matches a 380-byte SDK dispatcher followed by an 8-byte cleanup stub outside relocations; it is not one ordinary C function. |
| `0x800A60D0` / `func_800A60D0` | 12 | `osGetCount` — `GETCOUNT.S` | **Object** | Direct CP0 Count read with mfc0. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A64E0` / `func_800A64E0` | 16 | `__osSetSR` — `SETSR.S` | **Object** | Direct CP0 Status write with mtc0 and hazard spacing. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A64F0` / `func_800A64F0` | 12 | `__osGetSR` — `GETSR.S` | **Object** | Direct CP0 Status read with mfc0. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A65A0` / `func_800A65A0` | 116 | `osInvalICache` — `INVALICACHE.S` | **Object** | Instruction-cache invalidation loops contain cache 0x10 and cache 0x00. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A6620` / `func_800A6620` | 88 | `osMapTLBRdb` — `MAPTLBRDB.S` | **Object** | Direct CP0 EntryHi/Index/PageMask/EntryLo updates and tlbwi. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800A66E0` / `_bzero` | 156 | `_bzero` — `BZERO.S` | **Fresh** | SDK optimized zeroing routine is defined in assembly. Fresh linked code/data equality was verified on 3 November; see ASSEMBLY_VERIFICATION.md. |
| `0x800AAB80` / `_bcopy` | 772 | `_bcopy` — `BCOPY.S` | **Fresh** | SDK overlap-safe copy routine is defined in assembly. Fresh linked code/data equality was verified on 3 November; see ASSEMBLY_VERIFICATION.md. |
| `0x800AD5C0` / `func_800AD5C0` | 184 | `__osProbeTLB` — `PROBETLB.S` | **Object** | Direct CP0 TLB access with tlbp/tlbr and hazard spacing. Current extent matches the corresponding SDK object region outside declared relocations. |
| `0x800AFDC0` / `func_800AFDC0` | 12 | `__osSetCompare` — `SETCOMPARE.S` | **Object** | Direct CP0 Compare write with mtc0. Current extent matches the corresponding SDK object region outside declared relocations. |

## The eleven incomplete C candidates

These are not merely difficult assembly-looking instructions. Most start with
normal compiler stack allocation/save sequences. `CPause__DrawBar` instead begins
with a floating constant setup. The export switches to an `.incbin` raw segment
before any of their full bodies are represented by the current app entry.

| Entry | Current bytes | Following raw block | Raw block bytes | Located C candidate |
| --- | ---: | --- | ---: | --- |
| `0x80016CE8` | 8 | `assets/8179F0.bin` | 4,636 | `CGameObjectInstance__DoDraw` in `romstruc.c` |
| `0x80022148` | 8 | `assets/822E50.bin` | 14,208 | `CGeometry__Decompress` in `geometry.c` |
| `0x8002E4EC` | 4 | `assets/82F1F0.bin` | 4,756 | `CScene__DrawSky` in `scene.c` |
| `0x80052BCC` | 4 | `assets/8538D0.bin` | 7,928 | `CTMove__UpdateTurokInstance` in `tmove.c` |
| `0x80059994` | 12 | `assets/85A6A0.bin` | 3,220 | `CTMove__FireBullet` in `tmove.c` |
| `0x8005B964` | 12 | `assets/85C670.bin` | 3,916 | `CTMove__ControlSwimMovement` in `tmove.c` |
| `0x8006BC88` | 8 | `assets/86C990.bin` | 20,664 | `AI_Single_Event` in `ai.c` |
| `0x80075254` | 12 | `assets/875F60.bin` | 4,024 | `likely AI_Advance` in `ai.c` |
| `0x800859F8` | 8 | `assets/886700.bin` | 6,184 | `CPause__DrawBar` in `pause.c` |
| `0x800915C4` | 12 | `assets/8922D0.bin` | 6,848 | `CPickup_Pickup` in `pickup.c` |
| `0x80096A74` | 12 | `assets/897780.bin` | 6,592 | `DoDrawMap` in `map.c` |

The prefixes establish source candidates, not matching reconstructions or complete
retail extents. Some raw blocks contain more than one routine and may include
padding/data. Do not use the next detected entry or the archived object’s size as
an unchecked new function boundary. Review control flow, branch/call targets,
source/object alignment and any jump-table/data boundaries, then recover and
verify the complete functions through the live app’s normal workflow.

## Method and reproducibility

1. Enumerated all 52 `status=asm` rows read-only, in retail address order; sizes
   sum to 8,280 bytes. The standalone manifest has one additional padding entry,
   so its 53 assembly fallbacks are not 53 live app functions.
2. Read current disassembly and classification metadata. Agent votes, exhausted
   compile budgets and disassembler “handwritten instruction” comments were not
   accepted as independent provenance or proof that no C compiler could emit code.
3. Inspected the supplied original RNC/ADPCM assembly, SDK assembly definitions,
   and preserved ELF objects. For RNC/ADPCM, compared every current region against
   the archived `.text` offset. For SDK routines, compared the corresponding
   symbols/contiguous regions in the supplied `libultra_rom.a` (2.0I).
4. Object comparison retained all ordinary instruction bits. Only declared MIPS
   R_MIPS_26 target fields and R_MIPS_HI16/LO16 immediate fields were excluded.
   This is relocation-normalized identity evidence, not final relocated-byte or
   referenced-data verification. No unsupported relocation was silently accepted.
5. For suspected C fragments, searched preserved objects for matching instruction
   prefixes extending into the adjacent raw blocks, checked the named C
   definitions, and recorded the match length. “Unique” means unique among the
   local objects scanned, not proof of uniqueness across every historical build.
6. Reused the five previously recorded fresh assembly proofs; did not describe
   the other archived-object checks as fresh source assembly rebuilds.

`send_mesg` and `__osDispatchThread` expose boundary issues even though their code
is assembly: the former’s return is in `pad_800A5DB0`; the latter entry also
contains `__osCleanupThread`. `pad_800A5DB0` is not non-code padding.

The 2.0I exception-handler region is not an exact retail match. This is compatible
with a version/configuration difference; assembly source and privileged context
operations establish its nature, but the exact original revision remains open.

### Evidence hashes

Source and object inputs remain private; no ROM, assembly source, object or SDK
binary is added to this repository. Filenames and SHA-256 identify the examined
inputs. SDK sources are the supplied `LIBULTRA` tree; game files are the supplied
`tengine` tree. The five fresh proof details are in
[ASSEMBLY_VERIFICATION.md](ASSEMBLY_VERIFICATION.md).

| Input | SHA-256 |
| --- | --- |
| `rnc1.s` | `e6613eeb0e30479dc323608a1df2d40a0486fbb346dedbc8c01de451fe5e3a8f` |
| `rnc1.o` | `4d9a715b985619b113bc051e98a80ce94af63c3ba8e2d6f683f8e66aeac0bf3d` |
| `rnc2.s` | `1d4a9e6d3db1f26ff594edf952d560759d448ab02a6f90be7a0cd60d24cb7ccb` |
| `rnc2.o` | `64897ce97c3edc7f750ea6a4efa18a89819b12032a1df06afe304171dd792921` |
| `adpcm.s` | `64c6b5f54af3761c2eb17c6462c6d418d0a5309c9473505fad64ea6e57798fa1` |
| `adpcm.o` | `0872f4bfd58addd32a7e6294abc3512483c8b839dac34aaf8fa2c988af0eef01` |
| `libultra_rom.a` | `5d3eaa04a93282e65245ceed8c93205544faa2ee3372fda6f8e7dd80af775d92` |

## Work remaining

1. Review the eleven truncated entries and all raw segments for omitted retail
   code; recover real function extents before running more matching attempts.
2. Replace their assembly-completion interpretation with incomplete-coverage
   reporting through an app change, preserving verification and progress history.
3. Reconcile the `send_mesg`/`handle_CpU` and dispatch/cleanup entry boundaries.
4. Freshly assemble/link the remaining source-backed regions where the supplied
   version permits it; keep version mismatches explicit.
5. Publish whole-image code/data coverage separately from matching coverage over
   detected candidates. Keep the existing cartridge byte-identity gate.
