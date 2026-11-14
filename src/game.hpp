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

void veinBuilder(Game &game, int x, int y, char build)
{
    int steps = 1;
    int vel = std::rand() % 8;
    while(steps > 0)
    {
        if(x < 1)
        {
            x = 2;
            steps++;
        }
        if(y < 1)
        {
            y = 2;
            steps++;
        }
        if(x > 198)
        {
            x = 197;
            steps++;
        }
        if(y > 198)
        {
            y = 197;
            steps++;
        }
        game.world.grid[x][y] = build;
        game.world.grid[x+1][y] = build;
        game.world.grid[x-1][y] = build;
        game.world.grid[x][y+1] = build;
        game.world.grid[x][y-1] = build;
        switch(vel)
        {
            case 0:
                y--;
                break;
            case 1:
                y--;
                x++;
                break;
            case 2:
                x++;
                break;
            case 3:
                x++;
                y++;
                break;
            case 4:
                y++;
                break;
            case 5:
                y++;
                x--;
                break;
            case 6:
                x--;
                break;
            case 7:
                x--;
                y--;
                break;
        }
        
        
        steps--;
    }
}

void setupWorld(Game &game)
{
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            game.world.grid[i][j] = '\0';
        }
    }

    for(int x = 0; x < 200; x++)
    {
        for(int y = 0; y < 200; y++)
        {
            if(x >=108 && x <= 112 && y >= 108 && y <= 112)
            {
                continue;
            }
            int random = rand() % 100;
            if(random < 5)
            {
                random = rand() % 2;
                if(random == 0){veinBuilder(game, x, y, '^');}
                else if(random == 1){veinBuilder(game, x, y, 'I');}
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

void mineItem(Player &player, char it){
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
            mineItem(player, world.grid[player.xPos][player.yPos]);
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