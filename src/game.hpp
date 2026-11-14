#include "player.hpp"
#include "world.hpp"

struct Game
{
    Player player;
    World world;
    int curWorldNum = 0;
};