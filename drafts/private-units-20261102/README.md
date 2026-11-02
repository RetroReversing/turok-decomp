# Private-unit source candidates — promotion progress

**10 of the 32 prepared candidates are now live matches and selected C.**
The complete original-cartridge rebuild passes at **2,329 selected C functions /
600,080 bytes (95.857587%)**. The saved app sources and headers agree with the
repository selection. The remaining **22 candidates /16,364 bytes** are still
read-only verified drafts, not counted in those totals.

The promoted entries are: `_Ldtob`, `__alSeqNextDelta`, `alAdpcmPull`, `alBnkfNew`, `alCSeqNew`, `alCSeqNextEvent`, `alEnvmixerPull`, `alSeqNew`, `alSeqNextEvent`, `func_80001D30`.

The table retains all 32 original candidates and their source/header provenance.
Only the entries listed above have completed live promotion and full rebuild.

## Why they are whole units

IDO 5.3 O3 assigns private parameter registers and clobber sets using the actual
caller/callee bodies. Its `.mdebug` procedure metadata retains private names and
explicit extents absent from `.symtab`. Separate or globalized helpers were not
equivalent compiler inputs. The required app changes are in
[decompdecomp PR #341](https://github.com/RetroReversing/decompdecomp/pull/341).
The compiler-context support merged in PR #341 and was installed before this batch. The live app freshly judged each selected entry and its real context bodies.

Keep a unit and its exact header together. Submit the entire C unit as source and
its linked header as private context through the normal prepared-pair API, choosing
only the indicated entry. The app must freshly verify every context body and
publish only that entry. Context functions already matched must not be counted
again. `func_800A42C4` and `func_800A262C` were previously set aside because of their
private register conventions; reconsider those statuses only with fresh proof.

All use IDO 5.3 and `-mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`, with the
per-row optimization below. The O2 boot candidate uses three real, already-matched
predecessors, each independently rejudged. All others use bounded private compiler
units. These are working profiles, not proven historical compiler identification.

| Entry | Bytes | Whole source unit | Exact private header | Optimization |
| --- | ---: | --- | --- | --- |
| `_Ldtob` | 1,356 | [unit-b78c6fd1a365.c](unit-b78c6fd1a365.c) | [context-7cad90904f73.h](context-7cad90904f73.h) | `-O3` |
| `__alSeqNextDelta` | 88 | [unit-f38d32cbdbb5.c](unit-f38d32cbdbb5.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `alAdpcmPull` | 1,184 | [unit-10aee841d882.c](unit-10aee841d882.c) | [context-284c503f5095.h](context-284c503f5095.h) | `-O3` |
| `alBnkfNew` | 260 | [unit-cd0e022796b8.c](unit-cd0e022796b8.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `alCSeqNew` | 276 | [unit-404823b5a46f.c](unit-404823b5a46f.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `alCSeqNextEvent` | 760 | [unit-404823b5a46f.c](unit-404823b5a46f.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `alEnvmixerPull` | 1,352 | [unit-66831061873c.c](unit-66831061873c.c) | [context-b82173d80911.h](context-b82173d80911.h) | `-O3` |
| `alSeqNew` | 216 | [unit-20ac5f929566.c](unit-20ac5f929566.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `alSeqNextEvent` | 388 | [unit-f38d32cbdbb5.c](unit-f38d32cbdbb5.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_80001D30` | 288 | [unit-e604cf64f4ef.c](unit-e604cf64f4ef.c) | [context-8d698fdff8b3.h](context-8d698fdff8b3.h) | `-O2` |
| `func_800A2170` | 236 | [unit-cd0e022796b8.c](unit-cd0e022796b8.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_800A2420` | 52 | [unit-6d8c0f362b83.c](unit-6d8c0f362b83.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800A245C` | 464 | [unit-6d8c0f362b83.c](unit-6d8c0f362b83.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800A262C` | 2,088 | [unit-6d8c0f362b83.c](unit-6d8c0f362b83.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800A2E5C` | 1,556 | [unit-6d8c0f362b83.c](unit-6d8c0f362b83.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800A35E0` | 124 | [unit-5b9e4e209ac8.c](unit-5b9e4e209ac8.c) | [context-43dfe752fe02.h](context-43dfe752fe02.h) | `-O3` |
| `func_800A366C` | 1,352 | [unit-5b9e4e209ac8.c](unit-5b9e4e209ac8.c) | [context-43dfe752fe02.h](context-43dfe752fe02.h) | `-O3` |
| `func_800A4200` | 196 | [unit-404823b5a46f.c](unit-404823b5a46f.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_800A42C4` | 88 | [unit-404823b5a46f.c](unit-404823b5a46f.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_800A7E80` | 1,604 | [unit-a58ec5aeddc1.c](unit-a58ec5aeddc1.c) | [context-7cad90904f73.h](context-7cad90904f73.h) | `-O3` |
| `func_800AB6AC` | 120 | [unit-f6a47d8d0db5.c](unit-f6a47d8d0db5.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800AB94C` | 2,072 | [unit-f6a47d8d0db5.c](unit-f6a47d8d0db5.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800AC16C` | 1,572 | [unit-f6a47d8d0db5.c](unit-f6a47d8d0db5.c) | [context-fd5986d17fa6.h](context-fd5986d17fa6.h) | `-O3` |
| `func_800AE5C0` | 300 | [unit-10aee841d882.c](unit-10aee841d882.c) | [context-284c503f5095.h](context-284c503f5095.h) | `-O3` |
| `func_800AF084` | 464 | [unit-66831061873c.c](unit-66831061873c.c) | [context-b82173d80911.h](context-b82173d80911.h) | `-O3` |
| `func_800AF254` | 664 | [unit-66831061873c.c](unit-66831061873c.c) | [context-b82173d80911.h](context-b82173d80911.h) | `-O3` |
| `func_800AF4EC` | 176 | [unit-66831061873c.c](unit-66831061873c.c) | [context-b82173d80911.h](context-b82173d80911.h) | `-O3` |
| `func_800B0F18` | 76 | [unit-f38d32cbdbb5.c](unit-f38d32cbdbb5.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_800B1398` | 80 | [unit-20ac5f929566.c](unit-20ac5f929566.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `func_800B13E8` | 48 | [unit-20ac5f929566.c](unit-20ac5f929566.c) | [context-497bbe7ab085.h](context-497bbe7ab085.h) | `-O3` |
| `gl_func_0006E224` | 1,648 | [unit-a58ec5aeddc1.c](unit-a58ec5aeddc1.c) | [context-7cad90904f73.h](context-7cad90904f73.h) | `-O3` |
| `gl_func_00073904` | 1,384 | [unit-b78c6fd1a365.c](unit-b78c6fd1a365.c) | [context-7cad90904f73.h](context-7cad90904f73.h) | `-O3` |

## Provenance and limitations

This is source-assisted work, not a ROM-only experiment. Inputs include the user's
archival Turok SDK/game source on disk (`turokfinal_cracked/turoksnd/abi` and
`tengine`), plus the locally available Chameleon Twist SDK reconstruction
(`chameleontwistret/chameleontwistv1.0-jp/src/audio`, `src/libc` and matching headers).
Later SDK bodies supply raw-wave patching, envelope-motion guards and sound-queue
corrections absent from the older archive. Real fixed-address call/data bindings
were checked against the ROM. No source padding, inline assembly, copied target
instructions, new target extents, or relaxed byte/data/compression gates are used.
Headers and units are deduplicated by their source-content hashes. They preserve
the exact candidate text; improving formatting or modernizing legacy declarations
may change this compiler's output. Some small inline definitions become unused
return stubs; the new reader distinguishes those proven unreferenced placeholders
from real private functions.

The reader regression audit recompiled and rejudged all 2,316 previously matched
main-program functions without losing a byte match. Focused parser/context/export
and relocation tests pass. The new selections still require normal live app
promotion, saved source/header auditing, repository sync and full cartridge proof.
