# Working on this decompilation

- This branch contains user-authorized source-assisted reconstruction. Existing source on disk may be consulted for this branch. Keep source-assisted provenance separate from ROM-only results. The user authorized pushing this combined checkpoint. Keep local binaries, tools, databases, and evidence out of Git. Generic hardware/format documentation and tool code are allowed.
- The goal is C that compiles and links to the original bytes. Preserve original target hashes, addresses, comparison gates, and compression validation.
- Do not change build inputs, target assembly, compiler settings, function selection, or linker placement merely to force a match. Explain legitimate build fixes separately.
- IDO 5.3 is the provisional working compiler, not a proven identification of the original compiler release. Additional toolchains require license acceptance before installation.
- Prefer small source/header changes, with a per-function comparison and a full cartridge rebuild for accepted changes. Changes that still differ remain attempts, not matches.
- Function boundaries and inferred semantics require review. Keep address-based names until ROM-derived evidence supports a stronger name.
- Never commit ROMs, extracted binaries, generated assembly/assets, build output, compiler binaries, credentials or local databases.
- Report detected candidates, matching bytes, C selected in the build, assembly fallbacks, and original-cartridge verification separately. Never equate a byte-identical partial build with full decompilation.

- Keep the live decompdecomp Turok project and this standalone repository synchronized after every matching session. Promote verified sources and their required contexts through the app’s normal judging/promotion paths, preserve claims and history, and verify the repository build. Audit both directions for concurrent app matches. Flush verified progress to the app’s saved files and wait for any revalidation to finish; a temporary database count alone is not proof of a persisted sync. Report any remaining synchronization blockers explicitly; a repository-only recovery is not finished work. Commit and push only when authorized.

- Mutate the running app through its authenticated API/tools. Do not create another `RomNetwork` writer against its live database: separate progress caches can race the app’s autosave. Read-only database audits are allowed. Verify saved source files and context, not only match totals.

- When updating the app, preserve the tested ELF relocation-table-order HI16/LO16 fix. The repair source is in `/Volumes/Data/Codex/worktrees/decompdecomp-turok-sync-20261031` (`fix/turok-live-sync-relocations`). Recheck known multi-address relocation cases before replacing the working app bundle.

- Always commit and push Turok repository changes directly on `main`, as requested by the user. decompdecomp application changes belong on branches with pull requests.
