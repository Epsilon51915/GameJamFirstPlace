#ifndef WORLD_HPP
#define WORLD_HPP

enum TileType
{
    EMPTY_TILE = 0,
    MACHINE_TILE,
    TREE_TILE,
    IRON_TILE
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
    char past1[200][200];
    char past2[200][200];
    char past3[200][200];
    char past4[200][200];
    char past5[200][200];
};

#endif