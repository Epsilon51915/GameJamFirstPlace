#ifndef WORLD_HPP
#define WORLD_HPP

enum TileType
{
    EMPTY_TILE = 0,
    MACHINE_TILE,
    TREE_TILE,
    IRON_TILE,
    CAMPFIRE_TILE,
    ALUMINUM_TILE
};

struct Tile
{
    TileType type;
    char c;
    int health;
};

struct World
{
    Tile grid[200][200]; // \0 for void, I for iron, M for machine, 
};

#endif