cmake_minimum_required(VERSION 3.16)

# Set the project name + our project version
project(Tutorial VERSION 1.0)


# Specify C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass the version number to the source code
configure_file(TutorialConfig.h.in TutorialConfig.h)


message(STATUS "foo include dir: ${PROJECT_BINARY_DIR}")


# Add the executable
add_executable(Tutorial tutorial.cpp)

# Since the configured file will be written into the binary tree, we must add that directory to the list of paths to search for include files.
target_include_directories(Tutorial PUBLIC "${PROJECT_BINARY_DIR}")
