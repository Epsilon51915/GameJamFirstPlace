cmake_minimum_required(VERSION 3.18)
project(as9 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(raylib-cpp raylib)
add_executable(gameJam 
    src/main.cpp
    src/player.hpp)
#include(../assets/includeable.cmake)

file(GLOB sources "src/*.cpp" "src/*.c")
target_link_libraries(gameJam PUBLIC raylib raylib_cpp raygui)
set_property(TARGET gameJam PROPERTY CXX_STANDARD 20)

#configure_file(../assets/audio/itemPickup.mp3 audio/itemPickup.mp3 COPYONLY)
#configure_file(../assets/audio/luckyPickup.mp3 audio/luckyPickup.mp3 COPYONLY)
#configure_file(../assets/audio/walk.mp3 audio/walk.mp3 COPYONLY)
