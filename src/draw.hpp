//DrawTextPro(GetFontDefault(), "/", {200, 200}, {0, 0}, (float)rot, 40, 0, RED);

void drawCenteredText(std::string text, int size, int windowW, int windowH)
{
    int textW = MeasureText(text.c_str(), size);
    int textX = (windowW / 2) - (textW / 2);
    int textY = (windowH / 2) - (size / 2);
    DrawText(text.c_str(), textX, textY, 35, RED);
}

void drawTree()
{
    DrawText("|", 404, 410, 40, BROWN);
    DrawText("^", 400, 400, 40, GREEN);
    DrawText("^", 400, 410, 40, GREEN);
    DrawText("^", 400, 420, 40, GREEN);    
}

void drawTimeMachine(){
    DrawText("-", 500, 500, 40, BROWN);
    DrawText("^", 510, 500, 40, BROWN);
    DrawText("-", 520, 500, 40, BROWN);

    DrawText("|", 500, 490, 40, BROWN);
    DrawText("O", 510, 490, 40, BROWN);
    DrawText("|", 520, 490, 40, BROWN);

    DrawText("-", 500, 480, 40, BROWN);
    DrawText("-", 510, 480, 40, BROWN);
    DrawText("-", 520, 480, 40, BROWN);
}