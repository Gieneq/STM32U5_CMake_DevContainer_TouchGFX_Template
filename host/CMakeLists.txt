# Set minimum required version
cmake_minimum_required(VERSION 3.22)
cmake_policy(SET CMP0135 NEW)

# Define project name
project(Host_Tests)
enable_language(C CXX)
message("Building project: " ${CMAKE_PROJECT_NAME} " at: " ${CMAKE_SOURCE_DIR} ".")

# Set the toolchain for the host
# set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/host.cmake)
# message("Set toolchain " ${CMAKE_TOOLCHAIN_FILE} ".")

# Enable testing framework
enable_testing()
include(CTest)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

message("CMAKE_CXX_STANDARD: " ${CMAKE_CXX_STANDARD} ".")
message("CMAKE_C_STANDARD: " ${CMAKE_C_STANDARD} ".")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# Prevent GoogleTest from overriding compiler options
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# ================================
# 🟢 HOST TEST TARGET
# ================================

# Create an executable for host-side testing
add_executable(host_tests 
    tests/test_common.cpp
    tests/test_other.cpp
)

# Link Google Test & libs
target_link_libraries(host_tests
    GTest::gtest
    GTest::gtest_main
)

message("CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE} ">?")
message("buildDirectory: " ${buildDirectory} ".")
message("CMAKE_BUILD_DIRECTORY: " ${CMAKE_BUILD_DIRECTORY} ".")

include(GoogleTest)
gtest_discover_tests(host_tests)