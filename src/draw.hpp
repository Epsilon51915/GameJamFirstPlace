#include "game.hpp"
#include "recipe.hpp"

//DrawTextPro(GetFontDefault(), "/", {200, 200}, {0, 0}, (float)rot, 40, 0, RED);

void drawTitle()
{
 DrawText(" /$$   /$$           /$$", 40, 40, 20, WHITE);                                                  
 DrawText("| $$  | $$          |__/                                                  ", 40, 60, 20, WHITE);
 DrawText("| $$  | $$ /$$$$$$$  /$$ /$$    /$$ /$$$$$$   /$$$$$$   /$$$$$$$  /$$$$$$ ", 40, 80, 20, WHITE);
 DrawText("| $$  | $$| $$__  $$| $$|  $$  /$$//$$__  $$ /$$__  $$ /$$_____/ /$$__  $$", 40, 100, 20, WHITE);
 DrawText("| $$  | $$| $$ \\ $$| $$\\  $$/$$/| $$$$$$$$| $$ \\__/|  $$$$$$ | $$$$$$$$", 40, 120, 20, WHITE);
 DrawText("| $$  | $$| $$  | $$| $$ \\  $$$/ | $$_____/| $$      \\____  $$| $$_____/", 40, 140, 20, WHITE);
 DrawText("|  $$$$$$/| $$  | $$| $$  \\  $/  |  $$$$$$$| $$       /$$$$$$$/|  $$$$$$$", 40, 160, 20, WHITE); 
 DrawText("\\______/ |__/  |__/|__/   \\_/   \\_______/|__/      |_______/ \\_______/", 40, 180, 20, WHITE); 
                                                                          
                                                                          
                                                                          
 DrawText("  /$$$$$$                                     ", 40, 300, 20, WHITE);                    
 DrawText(" /$$__  $$                                    ", 40, 320, 20, WHITE);       
 DrawText("| $$ \\__/    /$$$$$$    /$$$$$$/$$$$     /$$$$$$   ", 40, 340, 20, WHITE);       
 DrawText("| $$ /$$$$    |____  $$  | $$_  $$_  $$   /$$__  $$  ", 40, 360, 20, WHITE);       
 DrawText("| $$|_  $$     /$$$$$$$  | $$\\ $$\\ $$  | $$$$$$$$  ", 40, 380, 20, WHITE);       
 DrawText("| $$ \\ $$    /$$__  $$  | $$ | $$ | $$  | $$_____/  ", 40, 400, 20, WHITE);      
 DrawText("|  $$$$$$/  |  $$$$$$$  | $$ | $$ | $$  |  $$$$$$$  ", 40, 420, 20, WHITE);      
 DrawText("\\______/   \\_______/  |__/ |__/ |__/  \\_______/  ", 40, 440, 20, WHITE); 
}

void drawTextAndBox(std::string text, int xPos, int yPos, int size, Color color)
{
    DrawRectangle(xPos - 10, yPos, MeasureText(text.c_str(), size) + 20, size, BLACK);
    DrawText(text.c_str(), xPos, yPos, size, color);
}

void drawCenteredText(std::string text, int size, int windowW, int windowH, Color color)
{
    int textW = MeasureText(text.c_str(), size);
    int textX = (windowW / 2) - (textW / 2);
    int textY = (windowH / 2) - (size / 2);
    DrawText(text.c_str(), textX, textY, 35, color);
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

void drawIron(int x, int y){
    DrawText("I", x * 40, y * 40, 40, GRAY);
}

void drawTile(char tile, int x, int y){
    switch(tile){
        case '\0':
            DrawRectangle(x * 40, y * 40 + 12, 20, 20, {112, 31, 126, 100}); 
            break;
        case '^':
            drawTree(x, y);
            break;
        case 'T':
            drawTimeMachine(x, y);
            break;
        case 'I':
            drawIron(x, y);
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
    for(int i = (game.player.xPos - 9); i < (game.player.xPos + 10); i++)
    {
        line = 1;
        for(int j = game.player.yPos - 8; j < game.player.yPos + 11; j++)
        {
            if(i == game.player.xPos && j == game.player.yPos)
            {
                drawPlayer(line, col);
            }
            else
            {   
                drawTile(game.world.grid[i][j].c, col, line);
            }
            line++;
        }
        col++;
    }
}

void drawInventory(Player& player){
    for(int i = 0; i < player.inventory.curSize; i++)
    {
        drawTextAndBox(getItemName(player.inventory.items[i].type) + " x" + std::to_string(player.inventory.items[i].quantity), 65, 75 + 60 * i, 50, WHITE);
    }
}

void drawCraftingMenu(Player& player, std::vector<Recipe> recipes, int selection){
    drawInventory(player);
    Color color;
    if(canCraft(recipes[selection], player))
    {
        color = GREEN;
    }
    else
    {
        color = RED;
    }
    Recipe cur = recipes[selection];
    if(cur.isTool){
        drawCenteredText(cur.name, 50, 1000, 900, color);
    } else {
        drawCenteredText(getItemName(cur.resultItem.type), 50, 1000, 900, color);
    }
    for(int i = 0; i < cur.requirements.size(); i++){
        DrawText((getItemName(cur.requirements[i].type) + " x" + std::to_string(cur.requirements[i].quantity)).c_str(), 450, 500 + 40 * i, 30, color);
    }
}