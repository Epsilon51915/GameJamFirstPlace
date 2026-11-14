#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "world.hpp"
#include "SimplexNoise.h"
#include <ctime>

/*
*
*   Game Struct <Could be made into a class?>
*
*/
struct Game
{
    Player player;
    World world;
    int curWorldNum = 0;
};

/*
*
*   Setup Fcns
*
*/
void setupWorld(Game &game)
{
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int offset = std::rand() % 1000;
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            if(j >=109 && j <= 111 && i >= 109 && i <= 111)
            {
                game.world.grid[i][j] = '\0';
                continue;
            }
            float noise = SimplexNoise::noise((i + offset), (j + offset));
            if(noise < 0.5)
            {
                game.world.grid[i][j] = '\0';
            }
            else if(noise < 1)
            {
                game.world.grid[i][j] = '^';
            }
        }
    }
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

void mineItem(char it, Player& player, World &world){
    switch(it){
        case '^':
            Item wood;
            wood.type = WOOD;
            wood.quantity = 3;
            if(lookForItem(player, wood))
            {
                editInventory(player, wood);
            }
            else
            {
                if(!addItemToInventory(player, wood))
                {
                    std::cout << "No space!" << std::endl;
                }
            }
            break;
    }
}

void checkCollisions(Player& player, World& world, char dir){
    char tile = world.grid[player.xPos][player.yPos];

    switch(tile){
        case '\0':
            return;
        // add more case statements here for objects you want to not be collidable
        default: // any collidable object
            mineItem(world.grid[player.xPos][player.yPos], player, world);
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
    } else if(raylib::Keyboard::IsKeyPressed(KEY_I))
    {
        displayInventory(player);
    }
}

#endif