"""Run with the decompdecomp Python: python -m unittest discover -s tools -p test_o32_abi.py."""
import importlib.util
import struct
import tempfile
import unittest
from pathlib import Path

spec = importlib.util.spec_from_file_location("project_build", Path(__file__).resolve().parents[1] / "build.py")
build = importlib.util.module_from_spec(spec)
spec.loader.exec_module(build)
PROFILE = {"toolchain": "ido-5.3", "flags": ["-mips3", "-32"]}


class O32TagTests(unittest.TestCase):
    def object(self, flags=0x20000000, endian=">", elfclass=1):
        data = bytearray(80)
        data[:6] = b"\x7fELF" + bytes([elfclass, 2 if endian == ">" else 1])
        struct.pack_into(endian + "H", data, 16, 1)
        struct.pack_into(endian + "H", data, 18, 8)
        struct.pack_into(endian + "I", data, 36, flags)
        data[52:] = bytes(range(28))  # sentinel section/relocation payload
        return bytes(data)

    def apply(self, data, profile=PROFILE):
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / "candidate.o"
            path.write_bytes(data)
            build.declare_o32_abi(path, profile)
            return path.read_bytes()

    def test_only_the_missing_abi_bit_changes(self):
        for endian in (">", "<"):
            before = self.object(endian=endian)
            expected = bytearray(before)
            struct.pack_into(endian + "I", expected, 36, 0x20001000)
            after = self.apply(before)
            self.assertEqual(after, expected)
            self.assertEqual(self.apply(after), after)

    def test_other_build_profiles_are_unchanged(self):
        before = self.object()
        for profile in ({"toolchain": "ido-5.3", "flags": ["-mips2"]},
                        {"toolchain": "ido-5.3", "flags": ["-mips3"]},
                        {"toolchain": "gcc-2.7.2-kmc", "flags": ["-mips3", "-32"]}):
            self.assertEqual(self.apply(before, profile), before)

    def test_other_abis_are_rejected_without_writing(self):
        for flags in (0x20000020, 0x20002000):
            with self.assertRaisesRegex(ValueError, "another MIPS ABI"):
                self.apply(self.object(flags))

    def test_wrong_elf_class_and_isa_are_rejected(self):
        for data in (self.object(elfclass=2), self.object(0x10000000)):
            with self.assertRaises(ValueError):
                self.apply(data)

    def test_conflicting_flags_are_rejected(self):
        with self.assertRaisesRegex(ValueError, "another MIPS ABI"):
            self.apply(self.object(), {**PROFILE, "flags": ["-mips3", "-32", "-n32"]})
