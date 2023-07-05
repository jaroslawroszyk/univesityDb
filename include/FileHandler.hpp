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
    FileHandler(const std::string& filename, Mode mode);
    ~FileHandler();

    void writeToCsvFile(const Database& db);
    void readDbFromFile(Database& db);

private:
    std::ofstream fileStream;
    std::ifstream fileReadStream;
    std::string filename;
    Mode fileMode;
};
