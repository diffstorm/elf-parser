/*
    ELF-Parser
    A command-line tool to parse and manipulate ELF binaries.
    Author               : Eray Ozturk | erayozturk1@gmail.com
    URL                  : github.com/diffstorm
    Date                 : 25/01/2019
*/
#pragma once

#include <string>
#include <elfio/elfio.hpp>

class ElfParser
{
public:
    explicit ElfParser(const std::string &binaryPath);
    void ListSections() const;
    void ReadSection(const std::string &sectionName) const;
    void ModifySection(const std::string &sectionName, const std::string &data);
    void DeleteSection(const std::string &sectionName);

private:
    ELFIO::elfio reader;
    std::string binaryPath;
};
