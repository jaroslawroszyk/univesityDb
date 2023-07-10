#pragma once
#include "Database.hpp"
#include <fstream>
#include <sstream>
#include <string_view>
#include <vector>

enum class Mode
{
    Read,
    Write
};

class FileHandler
{
public:
    FileHandler(const std::string&, Mode);
    ~FileHandler();

    auto writeToCsvFile(const Database&) -> void;
    auto readDbFromFile(Database&) -> void;

private:
    std::ofstream fileStream;
    std::ifstream fileReadStream;
    std::string filename;
    Mode fileMode;
};
