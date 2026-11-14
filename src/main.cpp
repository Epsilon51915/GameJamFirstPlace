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

#include "draw.hpp"
#include "game.hpp"

enum Scenes
{
    SPLASH = 0,
    TITLE,
    GAME,
    CREDIT
};

void drawCenteredText(std::string text, int size, int windowW, int windowH)
{
    int textW = MeasureText(text.c_str(), size);
    int textX = (windowW / 2) - (textW / 2);
    int textY = (windowH / 2) - (size / 2);
    DrawText(text.c_str(), textX, textY, 35, RED);
}



int main()
{
    raylib::Window window(800, 800, "GameJamFirstPlace");
    window.SetTargetFPS(60);
    window.SetState(FLAG_WINDOW_RESIZABLE);

    Scenes curScene = SPLASH;
    Game game;
    bool tree = true;
    while(!window.ShouldClose())
    {
        switch(curScene)
        {
            case SPLASH:
                window.BeginDrawing(); 
                {
                    window.ClearBackground(raylib::Color::White());
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = TITLE;
                    }
                    drawCenteredText("Game Jam First Place Co", 40, window.GetWidth(), window.GetHeight());
                } 
                break;

            case TITLE:
                window.BeginDrawing(); 
                {
                    window.ClearBackground(raylib::Color::DarkGray());
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = GAME;
                    }
                    if(raylib::Keyboard::IsKeyPressed(KEY_T))
                    {
                        tree = false;
                    }
                    if(tree)
                    {
                        drawTree();
                    }
                } 
                break;

            case GAME:
                window.BeginDrawing(); 
                {
                    window.ClearBackground(raylib::Color::Black());
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = CREDIT;
                    }
                } 
                break;

            case CREDIT:
                window.BeginDrawing(); 
                {
                    window.ClearBackground(raylib::Color::Blue());
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = GAME;
                    }
                } 
                break;
        }        
        window.EndDrawing();
    }
    return 0;
}