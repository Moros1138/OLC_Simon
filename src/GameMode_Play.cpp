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
    if(state->gameIndex == state->vecSequence.size())
    {
        return Mode::ShowSequence;
    }
    
    for(int i = 0; i < state->vecButtons.size(); i++)
    {
        auto &button = state->vecButtons[i];
        button.active = false;

        if(pge->GetKey(button.key).bHeld)
        {
            button.active = true;
        }

        if(pge->GetKey(button.key).bReleased)
        {
            // check
            if(state->vecSequence[state->gameIndex] != i)
            {
                return Mode::Fail;
            }
            
            // if we make it here, we had a successful
            state->gameIndex++;
        }
    }
    
    // Render The Current State
    state->RenderField(pge);

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::MainMenu;

    return Mode::Play;
}
