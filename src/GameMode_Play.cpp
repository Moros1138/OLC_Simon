#include "GameMode_Play.h"
#include "Utils.h"

GameMode_Play::GameMode_Play(GameState* state)
{
    this->state = state;
}

void GameMode_Play::OnCreate(olc::PixelGameEngine* pge)
{
}

void GameMode_Play::OnEnter(olc::PixelGameEngine* pge)
{
    state->gameIndex = 0;
}

void GameMode_Play::OnExit(olc::PixelGameEngine* pge)
{
}

Mode GameMode_Play::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    for(auto &button : state->vecButtons)
        button.active = false;
    
    
    
    // Render The Current State
    state->RenderField(pge);

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::MainMenu;

    return Mode::Play;
}
