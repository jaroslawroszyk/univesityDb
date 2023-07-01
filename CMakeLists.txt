# # cmake_minimum_required(VERSION 3.23.2)
# # project(studentDb)

# # set(CMAKE_CXX_STANDARD 20)
# # set(FLAGS -Wall -Wextra -Werror -Wpedantic)

# # set(SOURCES
# # src/database.cpp 
# # src/student.cpp
# # src/PeselChecker.cpp)

# # set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

# # include_directories(${COMMON_INCLUDES})

# # add_library(project1_lib ${SRC_FILES} ${SOURCES})
# # add_executable(project1 ${PROJECT_SOURCE_DIR}/src/main.cpp)

# # target_link_libraries(project1 project1_lib ${FLAGS})

# # add_subdirectory(./googletest)
# # enable_testing()
# # include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# # file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/uts/ut.cpp)

# # add_executable(runUnitTests ${TEST_SRC_FILES})

# # file(GLOB TEST_SRC_FILES_2 ${PROJECT_SOURCE_DIR}/uts/pesel_tests.cpp)

# # add_executable(peselTests ${TEST_SRC_FILES_2})

# # target_link_libraries(runUnitTests gtest gtest_main project1_lib)
# # target_link_libraries(peselTests gtest gtest_main project1_lib)


# cmake_minimum_required(VERSION 3.23.2)
# project(studentDb)

# set(CMAKE_CXX_STANDARD 20)
# set(FLAGS -Wall -Wextra -Werror -Wpedantic)

# set(SOURCES
#     src/database.cpp 
#     src/student.cpp
#     src/PeselChecker.cpp
# )

# set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

# include_directories(${COMMON_INCLUDES})

# add_library(project1_lib ${SRC_FILES} ${SOURCES})
# add_executable(project1 ${PROJECT_SOURCE_DIR}/src/main.cpp)
# target_link_libraries(project1 project1_lib ${FLAGS})

# add_subdirectory(./googletest)
# enable_testing()
# include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/uts/*.cpp)  # Get all test files in the uts directory

# foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
#     # Extract the filename without extension
#     get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)

#     # Add a separate executable for each test file
#     add_executable(${TEST_NAME} ${TEST_SRC_FILE})
#     target_link_libraries(${TEST_NAME} gtest gtest_main project1_lib)

#     # Optionally, you can add additional libraries or flags specific to each test executable
#     # target_link_libraries(${TEST_NAME} additional_libraries)
#     # target_compile_options(${TEST_NAME} PRIVATE additional_flags)

#     # Add the test to CTest
#     add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
# endforeach()

cmake_minimum_required(VERSION 3.23.2)
project(studentDb)

set(CMAKE_CXX_STANDARD 20)
set(FLAGS -Wall -Wextra -Werror -Wpedantic)

set(SOURCES
  src/Database.cpp 
  src/Student.cpp
  src/PeselChecker.cpp
)

set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)

include_directories(${COMMON_INCLUDES})

add_library(project1_lib ${SOURCES})

add_executable(project1 src/main.cpp)
target_link_libraries(project1 project1_lib ${FLAGS})

add_subdirectory(googletest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/uts/*.cpp)

foreach(TEST_SRC_FILE ${TEST_SRC_FILES})
  get_filename_component(TEST_NAME ${TEST_SRC_FILE} NAME_WE)
  add_executable(${TEST_NAME} ${TEST_SRC_FILE})
  target_link_libraries(${TEST_NAME} gtest gtest_main project1_lib)
  add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endforeach()

add_custom_target(pesel_test DEPENDS ${TEST_SRC_FILES})
