# Turok: Dinosaur Hunter - N64 decompilation

An **unfinished matching decompilation** of the European revision 0 release (`NTUP`), started from a user-supplied ROM with AI assistance. Existing Turok source, decompilation repositories, symbol maps, and source-derived analyses were not consulted.

## Current checkpoint

- **419 functions in C**, verified against the original machine code after linking.
- **26,112 matched bytes**, about **4.2% of the 626,012 bytes identified as candidate code**.
- **1,950 open candidates** and **35 candidates classified as assembly** in the analysis database.
- **2,405 functions in the standalone export**, including a startup function outside the 2,404-candidate analysis denominator.
- A full build with all 419 C selections reproduced the **original 8,388,608-byte cartridge byte for byte**, including its RNC-packed main program. Other functions remain in assembly regenerated from the user's ROM.

The build is a partial decompilation. An identical ROM does not mean that all of the game has been recovered as C. Candidate boundaries, types, and semantic names still need review; the detected-code figures are not whole-game coverage.

## Build

Use macOS or another platform supported by [RetroReversing/decompdecomp](https://github.com/RetroReversing/decompdecomp). Python 3.12+ and [uv](https://docs.astral.sh/uv/) are required. The tested tool revision is `af853d2f0da41ded2a9c9436ab2eb460f915b25b`, from [tool PR #2](https://github.com/RetroReversing/decompdecomp/pull/2).

Clone this project and install that tool revision into a local environment:

```sh
git clone https://github.com/RetroReversing/turok-decomp.git
cd turok-decomp
uv venv --python 3.12
uv pip install --python .venv/bin/python "decompnet @ git+https://github.com/RetroReversing/decompdecomp.git@af853d2f0da41ded2a9c9436ab2eb460f915b25b"
.venv/bin/decomp setup
```

For per-function comparisons on macOS, install LLVM/lld (`brew install llvm lld`) and add their `bin` directories to PATH, as documented by the tool.

Use **Compilers & tools** in decompdecomp to install **IDO 5.3** after accepting its license. IDO 7.1 was also compared, but is not required for this checkpoint. The tools are not included here. The compiler version remains provisional: both versions matched the small-function samples. `build.json` controls the actual C compiler; the KMC label retained in `splat.yaml` comes from the initial bootstrap split. See [the experiment notes](docs/PROGRESS.md).

Prepare your own European revision 0 ROM, then build:

```sh
.venv/bin/python tools/prepare.py "/path/to/your/Turok Europe ROM"
.venv/bin/python build.py
```

Preparation identifies byte order from the ROM magic; `.z64`, `.v64`, and `.n64` inputs are accepted regardless of filename extension. It checks the normalized cartridge hash, unpacks the main RNC method-1 block, verifies its checksums, and checks the expanded analysis-image hash. It does not download any ROM.

The first build regenerates assembly and assets using splat. The final comparison must report:

```text
cartridge verified: 88916d5d2e2470f395ad8f4245d34138ef2d156a
identical: build/game.z64 matches baserom.cartridge.z64 byte for byte (419 of 2405 functions in C)
```

The link can take several minutes. On Apple Silicon the tested IDO tools run natively; installing the optional period KMC tools may require Rosetta. Windows users should use the equivalent environment executables under `.venv/Scripts/` and the fork's platform setup instructions.

## Supported input

| Field | Value |
| --- | --- |
| Game code | `NTUP` |
| Region / revision | Europe / 0 |
| Normalized size | 8,388,608 bytes |
| Original normalized SHA-1 | `88916d5d2e2470f395ad8f4245d34138ef2d156a` |
| Original normalized SHA-256 | `9c9ea5dffe062ebc5038827a5b1d16100752561de6d904eec4186620bc351a0a` |
| Expanded analysis SHA-1 | `18af200e1b2492afff5f6dfa7989fe210dc62055` |

Keep both hashes fixed. `baserom.z64` is the expanded **analysis image**; `baserom.cartridge.z64` is the original normalized cartridge. `tools/prepare.py` generates both from your copy.

## Working on the decompilation

- Recovered C is under `src/<segment>/<address>.c`; type context is in `include/common.h`.
- Read the target under locally generated `asm/nonmatchings/`, propose a small C change, and compare it with `python build.py check FUNCTION_NAME` in the configured environment.
- `build.py check` records a match; run the complete build to verify that the selected C is included and the original cartridge still matches.
- `build.json` records selected C, original addresses, compiler settings, and compressed-code mappings. `objdiff.json` supports per-function inspection.
- Unknown names and types are deliberate. A byte match does not establish what a function means in gameplay.
- Keep ROMs, generated assembly/assets, compiler binaries, local databases, and build output out of commits.

The RNC build uses the original stream's coding decisions with literals supplied by newly linked output, then decodes the result and compares the complete cartridge. It rejects edits incompatible with the compression template; this is not a general compressor for mods.

The public walkthrough is being added to the [AI-assisted N64 tutorial](https://github.com/RetroReversing/retroReversing/pull/499). See [provenance and licensing](NOTICE.md) and [contributor instructions](AGENTS.md).
