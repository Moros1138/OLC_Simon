#include "GameMode_Fail.h"
#include "Utils.h"

GameMode_Fail::GameMode_Fail(GameState* state)
{
    this->state = state;
}

void GameMode_Fail::OnCreate(olc::PixelGameEngine* pge)
{

}

void GameMode_Fail::OnEnter(olc::PixelGameEngine* pge)
{
}

void GameMode_Fail::OnExit(olc::PixelGameEngine* pge)
{
    state->vecSequence.clear();
    state->gameIndex = 0;
}

Mode GameMode_Fail::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    pge->Clear(olc::DARK_BLUE);

    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) - 32}, "OLC Simon");
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) }, "You remembered " + std::to_string(state->vecSequence.size() - 1) + " this time!");
    
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 32}, "Press <SPACE> To Try Again");
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 48}, "Press <ESC> to Quit");

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::ShowSequence;

    return Mode::Fail;
}
