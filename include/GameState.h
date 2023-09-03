#pragma once
#include "olcPixelGameEngine.h"
#include "Button.h"
#include <vector>

struct GameState
{
    GameState();
    
    int  GetNext();
    void RenderField(olc::PixelGameEngine* pge);

    int gameIndex;
    std::vector<Button> vecButtons;
    std::vector<int> vecSequence;
};
