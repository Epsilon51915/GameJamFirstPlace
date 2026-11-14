#ifndef PLAYER_H
#define PLAYER_H

enum ItemType
{
    IRON = 0,
    WOOD,
    LEAF,
    SAP,
    STICK
};

struct Item
{
    ItemType type;
    int quantity;
};

struct Player
{
    int health;
    int colR, colG, colB;
    char drawChar;
    int xPos;
    int yPos;
    Item inventory[10];
};

#endif