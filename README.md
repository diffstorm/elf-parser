# ELF Parser

A command-line tool to parse and manipulate ELF binaries.

## Features
- List sections in an ELF binary
- Read contents of a specific section
- Modify a section with given data
- Delete a section from the ELF binary

## Usage
```sh
./elf-parser <command> <options>
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
git clone https://github.com/diffstorm/elf-parser.git

# Clone ELFIO and copy headers
git clone https://github.com/serge1/ELFIO.git
cp -r ELFIO/elfio elf-parser/include/

# Install g++ and fmt library
sudo apt-get update
sudo apt install build-essential g++
sudo apt-get install -y libfmt-dev

# Build
make
```

## TODO
- Add hex presentation like xxd

## :snowman: Author
Eray Öztürk ([@diffstorm](https://github.com/diffstorm))

## LICENSE
This project is licensed under the [MIT License](LICENSE) - see the LICENSE file for details.
