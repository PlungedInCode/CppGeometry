cmake_minimum_required(VERSION 3.16)
project(Geometry)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Create the executable target
add_executable(Geometry)

# Get the list of source files in the src/ folder
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

# Add the source files to the target
target_sources(Geometry PRIVATE ${SOURCES})

# Link libraries
target_link_libraries(Geometry PRIVATE SimpleLogger)

# Add the subdirectory after creating the target
add_subdirectory(lib/SimpleLogger)
