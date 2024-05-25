/*
    ELF-Parser
    A command-line tool to parse and manipulate ELF binaries.
    Author               : Eray Ozturk | erayozturk1@gmail.com
    URL                  : github.com/diffstorm
    Date                 : 25/01/2019
*/
#pragma once

#include <fmt/core.h>
#include <fmt/color.h>

class Logger
{
public:
    template <typename... Args>
    static void Info(const std::string &format, Args... args)
    {
        fmt::print(fmt::fg(fmt::color::green), format + "\n", args...);
    }

    template <typename... Args>
    static void Error(const std::string &format, Args... args)
    {
        fmt::print(fmt::fg(fmt::color::red), format + "\n", args...);
    }

    template <typename... Args>
    static void Success(const std::string &format, Args... args)
    {
        fmt::print(fmt::fg(fmt::color::blue), format + "\n", args...);
    }
};
