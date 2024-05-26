# ELF Parser

A command-line tool to parse and manipulate ELF binaries.

[![CI](https://github.com/diffstorm/elf-parser/actions/workflows/c-cpp.yml/badge.svg)](https://github.com/diffstorm/elf-parser/actions/workflows/c-cpp.yml)

## Features
- List sections in an ELF binary
- Read contents of a specific section
- Modify a section with given data
- Delete a section from the ELF binary

## Usage
```sh
./bin/elf-parser <command> <options>
```

### Commands
- `list <binary>` List all sections in the ELF binary
- `read <binary> <section>` Read the contents of a section
- `write <binary> <section> <data>` Modify a section with the given data
- `delete <binary> <section>` Delete a section from the ELF binary
- `version` Display the version information

## Dependencies
- [ELFIO](https://github.com/serge1/ELFIO)
- [fmt](https://github.com/fmtlib/fmt)

## Installation & Build
```sh
# Clone elf-parser
$ git clone https://github.com/diffstorm/elf-parser.git

# Clone ELFIO and copy headers
$ git clone https://github.com/serge1/ELFIO.git
$ cp -r ELFIO/elfio elf-parser/include/

# Install g++ and fmt library
$ sudo apt-get update
$ sudo apt install build-essential g++
$ sudo apt-get install -y libfmt-dev

# Build
$ make

# Run : list sections
$ ./bin/elf-parser list /usr/bin/xxd
Section:  (0 bytes)
Section: .interp (28 bytes)
Section: .note.gnu.property (48 bytes)
...
Section: .data (152 bytes)
Section: .bss (5216 bytes)
Section: .gnu_debuglink (52 bytes)
Section: .shstrtab (272 bytes)

# Run : read .data section
$ ./bin/elf-parser read /usr/bin/xxd .data
Reading section: .data
00000000: 00 00 00 00 00 00 00 00 08 50 00 00 00 00 00 00  .........P......
00000010: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00000020: 30 31 32 33 34 35 36 37 38 39 61 62 63 64 65 66  0123456789abcdef
00000030: 30 31 32 33 34 35 36 37 38 39 41 42 43 44 45 46  0123456789ABCDEF
00000040: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00000050: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00000060: 78 78 64 20 32 30 32 31 2d 31 30 2d 32 32 20 62  xxd 2021-10-22 b
00000070: 79 20 4a 75 65 72 67 65 6e 20 57 65 69 67 65 72  y Juergen Weiger
00000080: 74 20 65 74 20 61 6c 2e 00 00 00 00 00 00 00 00  t et al.........
00000090: 20 50 00 00 00 00 00 00                           P......

# Clean
make clean
```

## :snowman: Author
Eray Öztürk ([@diffstorm](https://github.com/diffstorm))

## LICENSE
This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.
