#include "player.hpp"

//DrawTextPro(GetFontDefault(), "/", {200, 200}, {0, 0}, (float)rot, 40, 0, RED);

void drawCenteredText(std::string text, int size, int windowW, int windowH)
{
    int textW = MeasureText(text.c_str(), size);
    int textX = (windowW / 2) - (textW / 2);
    int textY = (windowH / 2) - (size / 2);
    DrawText(text.c_str(), textX, textY, 35, RED);
}

void drawTree(int x, int y)
{
    DrawText("|", x * 40 + 4, y * 40 + 10, 40, BROWN);
    DrawText("^", x * 40, y * 40, 40, GREEN);
    DrawText("^", x * 40, y * 40 + 10, 40, GREEN);
    DrawText("^", x * 40, y * 40 + 20, 40, GREEN);   
}

void drawTimeMachine(){
    DrawText("-", 500, 500, 40, BROWN);
    DrawText("-", 510, 500, 40, BROWN);

    DrawText("|", 500, 490, 40, BROWN);
    DrawText("|", 510, 490, 40, BROWN);

    DrawText("-", 500, 480, 40, BROWN);
    DrawText("-", 510, 480, 40, BROWN);
}

void drawTile(char tile, int x, int y){
    switch(tile){
        case '\0':
            break;
        case '^':
            drawTree(x, y);
            break;
    }
}

void drawPlayer(Player &player){
    DrawText("#", player.xPos * 40, player.yPos * 40, 40, {player.colR, player.colG, player.colG, 255});
}