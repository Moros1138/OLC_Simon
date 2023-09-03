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
    state->x++;
}

void GameMode_ShowSequence::OnExit(olc::PixelGameEngine* pge)
{

}

Mode GameMode_ShowSequence::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    pge->Clear(olc::DARK_BLUE);

    pge->DrawString({ 5, 5 }, "Show Sequence");
    pge->DrawString({ 5, 15 }, std::to_string(state->x));

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::MainMenu;

    return Mode::ShowSequence;
}
