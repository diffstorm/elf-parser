/*
    ELF-Parser
    A command-line tool to parse and manipulate ELF binaries.
    Author               : Eray Ozturk | erayozturk1@gmail.com
    URL                  : github.com/diffstorm
    Date                 : 25/01/2019
*/
#include "ElfParser.h"
#include "Logger.h"
#include <iostream>
#include <fstream>
#include <vector>

ElfParser::ElfParser(const std::string &binaryPath) : binaryPath(binaryPath)
{
    if(!reader.load(binaryPath))
    {
        throw std::runtime_error("Unable to load ELF binary: " + binaryPath);
    }
}

void ElfParser::ListSections() const
{
    for(const auto &section : reader.sections)
    {
        Logger::Info("Section: {} ({} bytes)", section->get_name(), section->get_size());
    }
}

void ElfParser::ReadSection(const std::string &sectionName) const
{
    const auto section = reader.sections[sectionName];

    if(!section)
    {
        throw std::runtime_error("Section not found: " + sectionName);
    }

    Logger::Info("Reading section: {}", sectionName);
    std::cout.write(section->get_data(), section->get_size());
    std::cout << std::endl;
}

void ElfParser::ModifySection(const std::string &sectionName, const std::string &data)
{
    auto section = reader.sections[sectionName];

    if(!section)
    {
        throw std::runtime_error("Section not found: " + sectionName);
    }

    if(section->get_size() < data.size())
    {
        throw std::runtime_error("Data is larger than section size");
    }

    std::ofstream outFile(binaryPath, std::ios::binary | std::ios::in | std::ios::out);
    outFile.seekp(section->get_offset());
    outFile.write(data.c_str(), data.size());
    Logger::Success("Section {} modified successfully", sectionName);
}

void ElfParser::DeleteSection(const std::string &sectionName)
{
    auto section = reader.sections[sectionName];

    if(!section)
    {
        throw std::runtime_error("Section not found: " + sectionName);
    }

    section->set_type(ELFIO::SHT_NULL);
    std::ofstream outFile(binaryPath, std::ios::binary | std::ios::out | std::ios::trunc);

    if(!reader.save(outFile))
    {
        throw std::runtime_error("Failed to save modified ELF binary");
    }

    Logger::Success(fmt::format("Section {} deleted successfully", sectionName));
}