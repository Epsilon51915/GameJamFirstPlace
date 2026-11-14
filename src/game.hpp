#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "world.hpp"

struct Game
{
    Player player;
    World world;
    int curWorldNum = 0;
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

#endif