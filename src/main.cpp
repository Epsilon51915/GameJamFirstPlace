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

void setupWorld(Game &game)
{
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            game.world.grid[i][j] = '\0';
        }
    }

    game.world.grid[100][100] = '^';
    game.world.grid[102][102] = '^';
    game.world.grid[103][100] = '^';
    game.world.grid[105][105] = 'T';
}

void setupPlayer(Player &player){
    player.xPos = 110;
    player.yPos = 110;
    player.health = 10;
    player.colR = 255;
    player.colG = 255;
    player.colB = 255;
}

void checkCollisions(Player& player, World& world, char dir){
    char tile = world.grid[player.xPos][player.yPos];

    switch(tile){
        case '\0':
            return;
        // add more case statements here for objects you want to not be collidable
        default: // any collidable object
            if(dir == 'u'){
                player.yPos++;
            } else if(dir == 'd'){
                player.yPos--;
            } else if(dir == 'r'){
                player.xPos--;
            } else if(dir == 'l'){
                player.xPos++;
            }
    }
}

void movement(Player& player, World& world){
    if(raylib::Keyboard::IsKeyPressed(KEY_W) && player.yPos != 0){
        player.yPos--;
        checkCollisions(player, world, 'u');
    } else if(raylib::Keyboard::IsKeyPressed(KEY_S) && player.yPos != 199){
        player.yPos++;
        checkCollisions(player, world, 'd');
    } else if(raylib::Keyboard::IsKeyPressed(KEY_D) && player.xPos != 199){
        player.xPos++;
        checkCollisions(player, world, 'r');
    } else if(raylib::Keyboard::IsKeyPressed(KEY_A) && player.xPos != 0){
        player.xPos--;
        checkCollisions(player, world, 'l');
    }
}

int main()
{
    raylib::Window window(800, 800, "GameJamFirstPlace");
    window.SetTargetFPS(60);
    window.SetState(FLAG_WINDOW_RESIZABLE);

    Scenes curScene = SPLASH;
    Game game;
    setupPlayer(game.player);
    setupWorld(game);

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
                    drawWorld(game);
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = CREDIT;
                    }
                } 
                movement(game.player, game.world);
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