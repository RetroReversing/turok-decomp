# Scheduler boundary proposal — not applied

`func_8002BA48` currently covers 256 bytes. The adjacent 56-byte `pad_8002BB48`
contains two NOPs followed by the exact RA/S0–S7/FP restores and 0x58-byte stack
teardown corresponding to that function's prologue. It is not merely padding.

Read-only comparison of their unchanged concatenated bytes (312 bytes) matches
this C body exactly when compiled after the three real contiguous predecessors:
`osScRemoveClient` (136 bytes), `func_8002BA38` (8), `func_8002BA40` (8).
All three predecessor bodies independently pass the original byte/data judge.
The observed compiler procedure extent is 312 bytes at offset 152 in that unit.
The source archive's scheduler task loop supports this identity.

This proposal does not alter the app, build manifest or assembly targets. It is
not included in the 32 candidate count or 22,532-byte gain. A reviewed correction
through the app's normal join/boundary API, regeneration of the standalone layout,
and the full original-cartridge rebuild are required before promotion. Do not
change the target simply to remove a mismatch; preserve these original extents
and the correction evidence in the history.
