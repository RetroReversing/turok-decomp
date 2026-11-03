# Campaigner update — unmatched draft

`func_8004D6FC` / `Campaigner_Update` improves from score 1190 to 775 with a
reordering of pure nonvolatile guard predicates. The app accepted the improvement
through its ordinary attempt API; source and context are saved locally.

Use IDO 5.3 `-O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul`, with
`campaigner.h` as private context and `campaigner.c` as source. It is not a match
and is not selected in the cartridge build. The remaining differences are in the
first guarded weapon switch; linked constant and jump-table addresses resolve.

A five-minute app deep pass tested 185 variants (264 visited), retaining 775.
No exact result was accepted. Actual nearby source, formatting/guard nesting,
short-circuit predicate ordering, bounded compiler profiles, and equivalent
statement/control-flow forms were compared; unchanged trials need not be repeated.
