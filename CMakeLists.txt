cmake_minimum_required(VERSION 3.10)

# Project name
project(StudentRegistration)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add all .cpp files in the src directory
file(GLOB SRC_FILES src/*.cpp)

# Include directories where headers are located
include_directories(src)

# Use mysql_config to get MySQL include and library paths
execute_process(
    COMMAND mysql_config --include
    OUTPUT_VARIABLE MYSQL_INCLUDE_DIR
    OUTPUT_STRIP_TRAILING_WHITESPACE
)
execute_process(
    COMMAND mysql_config --libs
    OUTPUT_VARIABLE MYSQL_LIBRARIES
    OUTPUT_STRIP_TRAILING_WHITESPACE
)

# Include MySQL headers
include_directories(${MYSQL_INCLUDE_DIR})

# Create the executable
add_executable(application ${SRC_FILES})

# Link MySQL client libraries
target_link_libraries(application ${MYSQL_LIBRARIES})
