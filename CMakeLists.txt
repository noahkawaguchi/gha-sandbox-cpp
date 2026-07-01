cmake_minimum_required(VERSION 3.25)
project(sandbox LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(ZLIB REQUIRED)

# Core library (shared between main executable and tests)
add_library(my_math_lib src/math.cpp)

# Linking to my_math_lib requires zlib and headers in src
target_link_libraries(my_math_lib PUBLIC ZLIB::ZLIB)
target_include_directories(my_math_lib PUBLIC src)

# Build the main executable
add_executable(sandbox src/main.cpp)
target_link_libraries(sandbox PRIVATE my_math_lib)

# Build tests
find_package(Catch2 3 REQUIRED)
add_executable(my_math_tests tests/test_math.cpp)
target_link_libraries(my_math_tests PRIVATE my_math_lib Catch2::Catch2WithMain)

# Integrate with CTest
include(CTest)
include(Catch)
catch_discover_tests(my_math_tests)
