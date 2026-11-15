#ifndef PLAYER_H
#define PLAYER_H

#include "tool.hpp"
/*
*
*   Inventory BS
*
*/
enum ItemType
{
    IRON = 0,
    WOOD,
    LEAF,
    SAP,
    STICK,
    VINE
};

struct Item
{
    ItemType type;
    int quantity;
};

struct Inventory
{
    int curSize = 0;
    Item items[10];
};

/*
*
*   Base Player Struct
*
*/

struct Player
{
    int health;
    int colR, colG, colB;
    char drawChar;
    int xPos;
    int yPos;
    Inventory inventory;
    bool isCrafting = false;
    Tool tool;
};

/*
*
*   Inventory Management Functions
*
*/

std::string getItemName(ItemType type){
    switch(type){
        case WOOD:
            return "Wood";
        case IRON:
            return "Iron";
        case LEAF:
            return "Leaf";
        case SAP:
            return "Sap";
        case STICK:
            return "Stick";
        default:
            return "NULL";
    }
}

// If the item is in the inventory, return true
bool lookForItem(const Player &player, const Item &item)
{
    for(int i = 0; i < player.inventory.curSize; i++)
    {
        if(player.inventory.items[i].type == item.type)
        {
            return true;
        }
    }
    return false;
}

// Change quantity of a specific item in the inventory
void editInventory(Player &player, const Item &item)
{
    int ind;
    for(int i = 0; i < player.inventory.curSize; i++)
    {
        if(player.inventory.items[i].type == item.type)
        {
            ind = i;
            break;
        }
    }
    player.inventory.items[ind].quantity += item.quantity;
}

// Add an item to the inventory that does not currently exist, IF there is space in the inventory (current max size is 10)
bool addItemToInventory(Player& player, Item item)
{
    if(player.inventory.curSize < 10)
    {
        player.inventory.items[player.inventory.curSize] = item;
        player.inventory.curSize++;
        return true;
    }
    return false;
}

int getItemIndex(Player &player, ItemType type){
    for(int i = 0; i < player.inventory.curSize; i++){
        if(player.inventory.items[i].type == type){
            return i;
        }
    }
    return -1;
}

// Display each inventory slot, including the quanitty of items in that slot, as well as what the item is.
void displayInventory(const Player& player)
{
    for(int i = 0; i < player.inventory.curSize; i++)
    {
        std::string itemType;
        switch(player.inventory.items[i].type)
        {
            case WOOD:
                itemType = "WOOD";
                break;
        }
        std::cout << "Inventory Slot #" << i+1 << ": " << player.inventory.items[i].quantity << " " << itemType << std::endl;
    }
}

#endif