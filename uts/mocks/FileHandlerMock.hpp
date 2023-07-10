#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Database.hpp"
#include "FileHandler.hpp"

class FileHandlerMock : public FileHandler
{
public:
    FileHandlerMock(const std::string& filename, Mode mode) : FileHandler(filename, mode) {}

    MOCK_METHOD(void, writeToCsvFile, (const Database& db), ());
    MOCK_METHOD(void, readDbFromFile, (Database& db), ());
};