/*
    ELF-Parser
    A command-line tool to parse and manipulate ELF binaries.
    Author               : Eray Ozturk | erayozturk1@gmail.com
    URL                  : github.com/diffstorm
    Date                 : 25/01/2019
*/

#include <iostream>
#include <fstream>
#include <string>
#include "ElfParser.h"
#include "Logger.h"

const std::string VERSION = "1.0.0";

void PrintUsage()
{
    fmt::print("Usage:\n");
    fmt::print("  elf-parser <command> <options>\n");
    fmt::print("Commands:\n");
    fmt::print("  list <binary> List all sections in the ELF binary\n");
    fmt::print("  read <binary> <section> Read the contents of a section\n");
    fmt::print("  write <binary> <section> <data> Modify a section with the given data\n");
    fmt::print("  delete <binary> <section> Delete a section from the ELF binary\n");
    fmt::print("  version Display the version information\n");
}

void PrintVersion()
{
    fmt::print("elf-parser version {}\n", VERSION);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        PrintUsage();
        return 1;
    }

    std::string command = argv[1];

    if(command == "version")
    {
        PrintVersion();
        return 0;
    }

    if(argc < 3)
    {
        PrintUsage();
        return 1;
    }

    std::string binary = argv[2];

    try
    {
        ElfParser parser(binary);

        if(command == "list")
        {
            parser.ListSections();
        }
        else if(command == "read" && argc == 4)
        {
            std::string section = argv[3];
            parser.ReadSection(section);
        }
        else if(command == "write" && argc == 5)
        {
            std::string section = argv[3];
            std::string data = argv[4];
            parser.ModifySection(section, data);
        }
        else if(command == "delete" && argc == 4)
        {
            std::string section = argv[3];
            parser.DeleteSection(section);
        }
        else
        {
            PrintUsage();
        }
    }
    catch(const std::exception &e)
    {
        Logger::Error(e.what());
        return 1;
    }

    return 0;
}
