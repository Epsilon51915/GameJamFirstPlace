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
#include "recipe.hpp"

enum Scenes
{
    SPLASH = 0,
    TITLE,
    CONTROLS,
    GAME,
    CREDIT
};

int main()
{
    raylib::Window window(800, 800, "GameJamFirstPlace");
    window.SetTargetFPS(60);
    window.SetState(FLAG_WINDOW_RESIZABLE);

    Scenes curScene = SPLASH;
    Game game;
    setupPlayer(game.player);
    setupWorld(game);

    std::vector<Recipe> recipes;
    initializeStarterRecipes(recipes);
    int craftSelection = 0;

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
                    drawCenteredText("Game Jam First Place Studio", 40, window.GetWidth(), window.GetHeight(), RED);
                } 
                break;

            case TITLE:
                window.BeginDrawing(); 
                {
                    window.ClearBackground(raylib::Color::DarkGray());
                    drawTitle();
                    if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = CONTROLS;
                    }
                } 
                break;

            case CONTROLS:
                window.ClearBackground(raylib::Color::White());
                drawTextAndBox("W/A/S/D", 40, 40, 20, WHITE);
                drawTextAndBox("Up/Down/Left/Right", 200, 40, 20, WHITE);

                drawTextAndBox("TAB", 40, 80, 20, WHITE);
                drawTextAndBox("View Inventory", 200, 80, 20, WHITE);
                if(raylib::Keyboard::IsKeyPressed(KEY_ENTER))
                    {
                        curScene = GAME;
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

                    if(raylib::Keyboard::IsKeyDown(KEY_TAB) && !game.player.isCrafting){
                        //drawInventory(game.player);
                        drawInventory(game.player);
                    }
                    if(game.player.isCrafting){
                        if(raylib::Keyboard::IsKeyPressed(KEY_SPACE)){
                            craft(recipes[craftSelection], game.player);
                        }
                        if(raylib::Keyboard::IsKeyPressed(KEY_D)){
                            if(craftSelection < recipes.size() - 1){
                                craftSelection++;
                            }
                        }
                        if(raylib::Keyboard::IsKeyPressed(KEY_A)){
                            if(craftSelection > 0){
                                craftSelection--;
                            }
                        }
                        if(raylib::Keyboard::IsKeyPressed(KEY_TAB)){
                            game.player.isCrafting = false;
                        }
                        if(raylib::Keyboard::IsKeyPressed(KEY_R)){
                            if(canAdvanceWorld(game.player, game.curWorldNum)){
                                game.curWorldNum++;
                                if(game.curWorldNum == 2){
                                    curScene = CREDIT;
                                }
                                setupWorld(game);
                            }
                        }
                    }

                    if(game.player.isCrafting){
                        drawCraftingMenu(game.player, recipes, craftSelection);
                        drawGoal(game.player, game.curWorldNum);
                    }
                } 
                if(!game.player.isCrafting){
                    movement(game.player, game.world);
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