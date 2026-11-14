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

#endif