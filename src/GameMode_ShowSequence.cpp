#include "GameMode_ShowSequence.h"
#include "Utils.h"

GameMode_ShowSequence::GameMode_ShowSequence(GameState* state)
{
    this->state = state;
}

void GameMode_ShowSequence::OnCreate(olc::PixelGameEngine* pge)
{
}

void GameMode_ShowSequence::OnEnter(olc::PixelGameEngine* pge)
{
    int temp = rand() % 4;

    // we do this to make sure we don't have repeats
    if(state->vecSequence.empty())
    {
        state->vecSequence.push_back(temp);
    }
    else
    {
        while(temp == state->vecSequence.back())
            temp = rand() % 4;
        
        state->vecSequence.push_back(temp);
    }
    
    state->gameIndex = 0;
    delayTracker     = 0.0f;
    delay            = 1.0f;
}

void GameMode_ShowSequence::OnExit(olc::PixelGameEngine* pge)
{
}

Mode GameMode_ShowSequence::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    delayTracker += fElapsedTime;
    
    if(delayTracker > delay)
    {
        delayTracker -= delay;
        
        if(state->gameIndex == state->vecSequence.size())
        {
            return Mode::Play;
        }

        for(auto &button : state->vecButtons)
            button.active = false;
        
        state->vecButtons[state->vecSequence[state->gameIndex]].active = true;
        state->gameIndex++;
    }

    // Render The Current State
    state->RenderField(pge);
    pge->DrawString({5, 15}, "Show Sequence");


    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::MainMenu;

    return Mode::ShowSequence;
}
