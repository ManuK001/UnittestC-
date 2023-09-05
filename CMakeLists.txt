cmake_minimum_required(VERSION 3.10)
project(CalculatorTests)

# Locate GTest package
find_package(GTest REQUIRED)

# Include Google Test headers
include_directories(${GTEST_INCLUDE_DIRS})

# Add the test executable
add_executable(CalculatorTests calculator_tests.cpp)

# Link against Google Test
target_link_libraries(CalculatorTests ${GTEST_LIBRARIES} pthread)
