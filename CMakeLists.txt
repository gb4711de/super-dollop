cmake_minimum_required(VERSION 3.10)
project(UnitConverter VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add compile options
add_compile_options(-Wall -Wextra -pedantic)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Source files
set(SOURCES
    src/main.cpp
    src/LengthConverter.cpp
    src/TemperatureConverter.cpp
)

# Create executable
add_executable(unit_converter ${SOURCES})

# Set output directory
set_target_properties(unit_converter PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin
)
