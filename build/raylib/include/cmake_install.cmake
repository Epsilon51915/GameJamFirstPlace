# Install script for directory: /home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/AudioDevice.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/AudioStream.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/AutomationEventList.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/BoundingBox.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Camera2D.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Camera3D.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Color.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/FileData.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/FileText.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Font.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Functions.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Gamepad.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Image.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Keyboard.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Material.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Matrix.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Mesh.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/MeshUnmanaged.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Model.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/ModelAnimation.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Mouse.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Music.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Ray.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/RayCollision.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/RaylibException.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/raylib-cpp-utils.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/raylib-cpp.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/raylib.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/raymath.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Rectangle.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/RenderTexture.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/ShaderUnmanaged.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Shader.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Sound.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Text.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Texture.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/TextureUnmanaged.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Touch.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Vector2.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Vector3.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Vector4.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/VrStereoConfig.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Wave.hpp"
    "/home/kevin/Coding/GameJamFirstPlace/raylib-cpp/include/Window.hpp"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/home/kevin/Coding/GameJamFirstPlace/build/raylib/include/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
