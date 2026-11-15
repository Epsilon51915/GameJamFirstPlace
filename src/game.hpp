#ifndef GAME_HPP
#define GAME_HPP
#include "AudioDevice.hpp"
#include "Keyboard.hpp"
#include "raylib-cpp.hpp"
#include "raylib.h"
#include <execution>
#include <iostream>
#include <vector>
#include <iostream>

#include "player.hpp"
#include "world.hpp"
#include "SimplexNoise.h"
#include <ctime>


raylib::AudioDevice audio;
raylib::Sound hitTree("assets/hitTree.wav");
raylib::Sound hitIron("assets/hitIron.wav");
raylib::Sound walk("assets/walk.wav");


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
    Tile tile;
    tile.c = build;
    tile.health = 100;
    if(build == '^')
    {
        tile.type = TREE_TILE;
    }
    else if(build == 'I')
    {
        tile.type = IRON_TILE;
    }
    else if(build == 'A')
    {
        tile.type = ALUMINUM_TILE;
    }
    int steps = 1;
    int vel = std::rand() % 8;
    while(steps > 0)
    {
        if(x < 1)
        {
            x = 1;
        }
        if(y < 1)
        {
            y = 1;
        }
        if(x > 198)
        {
            x = 198;
        }
        if(y > 198)
        {
            y = 198;
        }
        game.world.grid[x][y] = tile;
        game.world.grid[x+1][y] = tile;
        game.world.grid[x-1][y] = tile;
        game.world.grid[x][y+1] = tile;
        game.world.grid[x][y-1] = tile;
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
    Tile blank;
    blank.c = '\0';
    blank.health = 100;
    blank.type = EMPTY_TILE;
    srand(static_cast<unsigned int>(std::time(nullptr)));
    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            
            game.world.grid[i][j] = blank;
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
            if(random < 5){
                random = rand() % 2;
                if(random == 0){veinBuilder(game, x, y, '^');}
                else if(random == 1){veinBuilder(game, x, y, 'I');}
            }
            if(random >= 96 && game.curWorldNum == 1){
                veinBuilder(game, x, y, 'A');
            }
        }
    }

    Tile tile;
    tile.c = 'T';
    tile.health = 100;
    tile.type = MACHINE_TILE;
    Tile test;
    test.c = 'C';
    test.health = 100;
    test.type = CAMPFIRE_TILE;
    game.world.grid[105][105] = tile;
    game.world.grid[104][105] = blank;
    game.world.grid[106][105] = blank;
    game.world.grid[105][104] = blank;
    game.world.grid[105][106] = blank;
    game.world.grid[106][106] = blank;
    game.world.grid[104][104] = blank;
    game.world.grid[104][106] = blank;
    game.world.grid[106][104] = blank;
}

void setupPlayer(Player &player){
    player.xPos = 110;
    player.yPos = 110;
    player.health = 10;
    player.colR = 255;
    player.colG = 255;
    player.colB = 255;
    Tool defaultTool;
    defaultTool.mineLevel = 0;
    defaultTool.remainingDurability = 999999;
    player.axeTool = defaultTool;
    player.pickaxeTool = defaultTool;
}

void mineItem(Player &player, World &world){
    //std::cout<<it<<std::endl;
    int random = rand() % 100;
    
    switch(world.grid[player.xPos][player.yPos].c){
        case '^':
            world.grid[player.xPos][player.yPos].health--;
            Item wood;
            wood.type = ItemType::WOOD;
            wood.quantity = 1;

            if(random < 10){
                Item sap;
                sap.type = SAP;
                sap.quantity = 1;
                if(lookForItem(player, sap))
                {
                    editInventory(player, sap);
                }
                else
                {
                    if(!addItemToInventory(player, sap))
                    {
                        std::cout << "No space!" << std::endl;
                    }
                }
            }

            random = rand() % 100;
            if(random < 10){
                Item stick;
                stick.type = STICK;
                stick.quantity = 1;
                if(lookForItem(player, stick))
                {
                    editInventory(player, stick);
                }
                else
                {
                    if(!addItemToInventory(player, stick))
                    {
                        std::cout << "No space!" << std::endl;
                    }
                }
            }

            random = rand() % 100;
            if(random < 33){
                Item leaf;
                leaf.type = LEAF;
                leaf.quantity = 1;
                if(lookForItem(player, leaf))
                {
                    editInventory(player, leaf);
                }
                else
                {
                    if(!addItemToInventory(player, leaf))
                    {
                        std::cout << "No space!" << std::endl;
                    }
                }
            }

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
            hitTree.Play();
            break;
        case 'I':
            if(player.pickaxeTool.mineLevel < 1){
                break;
            }
            // Must do AFTER tool check, if tool check fails, don't lose health
            world.grid[player.xPos][player.yPos].health--;
            Item iron;
            iron.type = ItemType::IRON;
            iron.quantity = 1;
            if(lookForItem(player, iron))
            {
                std::cout<<"Found Item alread"<<std::endl;
                editInventory(player, iron);
            }
            else
            {
                std::cout<<"Trying to add item"<<std::endl;
                if(!addItemToInventory(player, iron))
                {
                    std::cout << "No space!" << std::endl;
                }
            }

            random = rand() % 100;

            if(random < 7){
                Item flint;
                flint.type = FLINT;
                flint.quantity = 1;
                if(lookForItem(player, flint))
                {
                    editInventory(player, flint);
                }
                else
                {
                    if(!addItemToInventory(player, flint))
                    {
                        std::cout << "No space!" << std::endl;
                    }
                }
            }
            hitIron.Play();
            break;
        case 'A':
            if(player.pickaxeTool.mineLevel < 2){
                break;
            }

            world.grid[player.xPos][player.yPos].health--;
            Item aluminum;
            aluminum.type = ItemType::ALUMINUM;
            aluminum.quantity = 1;
            if(lookForItem(player, aluminum))
            {
                std::cout<<"Found Item alread"<<std::endl;
                editInventory(player, aluminum);
            }
            else
            {
                std::cout<<"Trying to add item"<<std::endl;
                if(!addItemToInventory(player, aluminum))
                {
                    std::cout << "No space!" << std::endl;
                }
            }
            break;
    }
    if(world.grid[player.xPos][player.yPos].health == 0)
    {
        Tile blank;
        blank.c = '\0';
        blank.health = 100;
        blank.type = EMPTY_TILE;
        world.grid[player.xPos][player.yPos] = blank;
    }
}


// REFACTOR WITH NEW TILE STUFF

bool checkCollisions(Player& player, World& world, char dir){
    char tile = world.grid[player.xPos][player.yPos].c;

    switch(tile){
        case '\0':
            return true;
        // add more case statements here for objects you want to not be collidable
        default: // any collidable object
            mineItem(player, world);
            if(dir == 'u'){
                player.yPos++;
            } else if(dir == 'd'){
                player.yPos--;
            } else if(dir == 'r'){
                player.xPos--;
            } else if(dir == 'l'){
                player.xPos++;
            }

            if(tile == 'T'){
                player.isCrafting = true;
            }
            return false;
    }
}

void movement(Player& player, World& world){
    if(raylib::Keyboard::IsKeyPressed(KEY_W) && player.yPos != 0){
        player.yPos--;
        if(checkCollisions(player, world, 'u'))
        {
            walk.Play();
        }
    } else if(raylib::Keyboard::IsKeyPressed(KEY_S) && player.yPos != 199){
        player.yPos++;
        if(checkCollisions(player, world, 'd'))
        {
            walk.Play();
        }
    } else if(raylib::Keyboard::IsKeyPressed(KEY_D) && player.xPos != 199){
        player.xPos++;
        if(checkCollisions(player, world, 'r'))
        {
            walk.Play();
        }
    } else if(raylib::Keyboard::IsKeyPressed(KEY_A) && player.xPos != 0){
        player.xPos--;
        if(checkCollisions(player, world, 'l'))
        {
            walk.Play();
        }
    } else if(raylib::Keyboard::IsKeyPressed(KEY_I))
    {
        displayInventory(player);
    }
}

void makeCampfire(World &world, Player &player)
{
    int playerX = player.xPos, playerY = player.yPos;
    if(world.grid[104][104].type == EMPTY_TILE && playerX != 104 && playerY != 104)
    {
        world.grid[104][104].type = CAMPFIRE_TILE;
        world.grid[104][104].c = 'C';
    }
    else if(world.grid[106][106].type == EMPTY_TILE && playerX != 106 && playerY != 106)
    {
        world.grid[106][106].type = CAMPFIRE_TILE;
        world.grid[106][106].c = 'C';
    }
    else if(world.grid[104][106].type == EMPTY_TILE && playerX != 104 && playerY != 106)
    {
        world.grid[104][106].type = CAMPFIRE_TILE;
        world.grid[104][106].c = 'C';
    }
    else if(world.grid[106][104].type == EMPTY_TILE && playerX != 106 && playerY != 104)
    {
        world.grid[106][104].type = CAMPFIRE_TILE;
        world.grid[106][104].c = 'C';
    }
}

bool canAdvanceWorld(Player& player, int worldNum){
    if(worldNum == 0){
        int index = getItemIndex(player, IRON);
        if(index == -1){
            return false;
        }
        if(player.inventory.items[index].quantity >= 200){
            return true;
        }
        return false;
    } else if(worldNum == 1){
        int index = getItemIndex(player, ALUMINUM);
        if(index == -1){
            return false;
        }
        if(player.inventory.items[index].quantity >= 100){
            return true;
        }
        return false;
    }
    return false;
}

#endif