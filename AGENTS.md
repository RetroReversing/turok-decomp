# Working on this decompilation

- Work from the user's own ROM and ROM-derived analysis. Do not consult existing Turok source, leaked code, decompilation repositories, symbol maps, or source-derived articles. Generic hardware/format documentation and tool code are allowed.
- The goal is C that compiles and links to the original bytes. Preserve original target hashes, addresses, comparison gates, and compression validation.
- Do not change build inputs, target assembly, compiler settings, function selection, or linker placement merely to force a match. Explain legitimate build fixes separately.
- IDO 5.3 is the provisional working compiler, not a proven identification of the original compiler release. Additional toolchains require license acceptance before installation.
- Prefer small source/header changes, with a per-function comparison and a full cartridge rebuild for accepted changes. Changes that still differ remain attempts, not matches.
- Function boundaries and inferred semantics require review. Keep address-based names until ROM-derived evidence supports a stronger name.
- Never commit ROMs, extracted binaries, generated assembly/assets, build output, compiler binaries, credentials or local databases.
- Report detected candidates, matching bytes, C selected in the build, assembly fallbacks, and original-cartridge verification separately. Never equate a byte-identical partial build with full decompilation.
