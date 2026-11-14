cmake_minimum_required(VERSION 3.18)
project(gameJam LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Keep raylib-cpp subdirectories as they are libraries
add_subdirectory(raylib-cpp raylib)
# NOTE: Removed add_subdirectory(external/SimplexNoise) to avoid the executable conflict

# Automatically collect all source files in src/
file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS "src/*.hpp" "src/*.h")

# Define the executable, including the SimplexNoise source file directly
add_executable(gameJam 
    ${SOURCES}
    ${HEADERS}
    external/SimplexNoise/src/SimplexNoise.cpp
)

# Add include directories so your code can find headers
target_include_directories(gameJam PRIVATE 
    src
    external/SimplexNoise/src
)

# Link your libraries (SimplexNoise is no longer listed here because it's compiled directly)
target_link_libraries(gameJam PRIVATE 
    raylib 
    raylib_cpp 
    raygui
)