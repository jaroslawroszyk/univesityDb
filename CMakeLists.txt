cmake_minimum_required(VERSION 3.23.2)
project(studentDb)
set(CMAKE_CXX_STANDARD 20)

set(HEADERS
        include/database.hpp
        include/Gender.hpp
        include/PeselChecker.hpp
        include/student.hpp
        )

set(SOURCES
src/database.cpp 
src/student.cpp
src/PeselChecker.cpp)

set(FLAGS -Wall -Wextra -Werror -Wpedantic)

add_executable(${PROJECT_NAME} ${SOURCES} src/main.cpp src/database.cpp src/student.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC ${FLAGS})

find_package(GTest REQUIRED)

add_library(${MODULE_NAME} STATIC ${SOURCES} ${HEADERS}) 

add_executable(${PROJECT_NAME}-ut  ${SOURCES} uts/ut.cpp)
target_compile_options(${PROJECT_NAME}-ut PRIVATE ${FLAGS})
target_link_libraries(${PROJECT_NAME}-ut  GTest::gmock GTest::gmock_main
        GTest::gtest GTest::gtest_main
)