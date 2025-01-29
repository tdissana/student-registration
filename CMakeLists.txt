cmake_minimum_required(VERSION 3.10)
project(StudentRegistration)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all .cpp files in the src directory
file(GLOB SRC_FILES src/*.cpp)

# Include directories where headers are located
include_directories(src)

# Create the executable
add_executable(application ${SRC_FILES})
