#!/usr/bin/env python3
# SPDX-License-Identifier: AGPL-3.0-only
"""Prepare ignored local build inputs from the user's ROM; never download game data."""
from __future__ import annotations

import argparse
import hashlib
import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]


def normalized(data: bytes) -> bytes:
    magic = data[:4]
    if magic == bytes.fromhex('80371240'):
        return data
    if magic == bytes.fromhex('37804012') and len(data) % 2 == 0:
        result = bytearray(data)
        result[0::2], result[1::2] = data[1::2], data[0::2]
        return bytes(result)
    if magic == bytes.fromhex('40123780') and len(data) % 4 == 0:
        result = bytearray(len(data))
        for offset in range(4):
            result[offset::4] = data[3 - offset::4]
        return bytes(result)
    raise ValueError('Unrecognized N64 ROM magic or invalid byte-order alignment.')


def prepare(path: Path) -> None:
    from decompnet.consoles.n64 import rnc

    config = json.loads((ROOT / 'build.json').read_text())
    target = config['cartridge']
    destinations = [ROOT / target['image'], ROOT / config['image']]
    if any(p.is_symlink() or p.resolve() == path.resolve()
           or (p.exists() and path.exists() and p.samefile(path)) for p in destinations):
        raise ValueError('Keep the input ROM separate from the generated baserom files; output symlinks are unsupported.')
    original = normalized(path.read_bytes())
    if hashlib.sha1(original).hexdigest() != target['sha1']:
        raise ValueError('This project needs the NTUP European revision 0 ROM; normalized SHA-1 differs.')
    analysis = bytearray(original)
    for block in target['blocks']:
        analysis += bytes(-len(analysis) % 16 + 0x2000)
        if len(analysis) != block['analysis']:
            raise ValueError('The saved compressed-code mapping does not match the expansion layout.')
        payload = rnc.unpack(original[block['rom']:])
        if len(payload) != block['size']:
            raise ValueError('The unpacked program size differs from the saved mapping.')
        analysis += payload
    analysis += bytes(-len(analysis) % 16)
    if hashlib.sha1(analysis).hexdigest() != config['sha1']:
        raise ValueError('The expanded image differs from the fixed analysis target.')
    # Verify every input before writing either file. Original ROM is read only.
    (ROOT / target['image']).write_bytes(original)
    (ROOT / config['image']).write_bytes(analysis)
    print(f"Prepared {target['image']} and {config['image']}; both fixed hashes verified.")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('rom', type=Path, help='your European revision 0 ROM in z64, v64, or n64 byte order')
    args = parser.parse_args()
    try:
        prepare(args.rom)
    except ImportError:
        print('Install the documented decompdecomp revision and run with its Python environment.', file=sys.stderr)
        return 1
    except (OSError, ValueError) as error:
        print(f'Preparation failed: {error}', file=sys.stderr)
        return 1
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
