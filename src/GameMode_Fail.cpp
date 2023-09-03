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
    state->vecSequence.clear();
    state->gameIndex = 0;
}

void GameMode_Fail::OnExit(olc::PixelGameEngine* pge)
{
}

Mode GameMode_Fail::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    pge->Clear(olc::DARK_BLUE);

    pge->DrawString({ 5, 15 }, std::to_string(state->vecSequence.size()));
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, pge->ScreenHeight() / 2}, "You have failed!");
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 10}, "Press <SPACE> To Try Again");
    // DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 20}, "Press <C> For Credits");

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::ShowSequence;

    return Mode::Fail;
}
