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

void setup(Game &game)
{
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            game.world.grid[i][j] = '\0';
        }
    }
}

int main()
{
    raylib::Window window(800, 800, "GameJamFirstPlace");
    window.SetTargetFPS(60);
    window.SetState(FLAG_WINDOW_RESIZABLE);

    Scenes curScene = SPLASH;
    Game game;
    setup(game);

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