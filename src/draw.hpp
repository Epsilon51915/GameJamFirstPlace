#include "game.hpp"

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

void drawTimeMachine(int x, int y){
    DrawText("-", x * 40, y * 40, 40, BROWN);
    DrawText("-", x * 40 + 10, y * 40, 40, BROWN);

    DrawText("|", x * 40 + 5, y * 40 + 15, 40, BROWN);
    DrawText("|", x * 40 + 15, y * 40 + 15, 40, BROWN);

    DrawText("-", x * 40, y * 40 + 30, 40, BROWN);
    DrawText("-", x * 40 + 10, y * 40 + 30, 40, BROWN);
}

void drawTile(char tile, int x, int y){
    switch(tile){
        case '\0':
            DrawRectangle(x * 40, y * 40, 20, 20, {112, 31, 126, 100}); 
            break;
        case '^':
            drawTree(x, y);
            break;
        case 'T':
            drawTimeMachine(x, y);
            break;
    }
}

void drawPlayer(int row, int col){
    DrawText("#", col * 40, row * 40, 40, WHITE);
}

void drawWorld(Game &game)
{
    int col, line;
    col = 1;
    for(int i = (game.player.xPos - 9); i < (game.player.xPos + 8); i++)
    {
        line = 1;
        for(int j = game.player.yPos - 8; j < game.player.yPos + 7; j++)
        {
            if(i == game.player.xPos && j == game.player.yPos)
            {
                drawPlayer(line, col);
            }
            else
            {   
                drawTile(game.world.grid[i][j], col, line);
            }
            line++;
        }
        col++;
    }
}