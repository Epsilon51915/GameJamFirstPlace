#include <iostream>
#include "AudioDevice.hpp"
#include "Camera3D.hpp"
#include "Keyboard.hpp"
#include "Matrix.hpp"
#include "Model.hpp"
#include "RadiansDegrees.hpp"
#include "Vector3.hpp"
#include "Vector4.hpp"
#include "raylib-cpp.hpp"
#include "raylib.h"
#include <concepts>
#include <execution>
#include <iostream>
#include <limits>
#include <optional>
#include <memory>
#include <vector>
#include <iostream>
#include <map>

int main()
{
    raylib::Window window(800, 800, "As8");
    window.SetTargetFPS(60);
    window.SetState(FLAG_WINDOW_RESIZABLE);

    while(!window.ShouldClose()){
        window.BeginDrawing(); {
            window.ClearBackground(raylib::Color::Gray());
        } window.EndDrawing();
    }

    std::cout << "Hello GameJamFirstPlace!" << std::endl;

    return 0;
}