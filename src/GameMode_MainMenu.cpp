#include "GameMode_MainMenu.h"
#include "Utils.h"

GameMode_MainMenu::GameMode_MainMenu(GameState* state)
{
    this->state = state;
}

void GameMode_MainMenu::OnCreate(olc::PixelGameEngine* pge)
{

}

void GameMode_MainMenu::OnEnter(olc::PixelGameEngine* pge)
{
}

void GameMode_MainMenu::OnExit(olc::PixelGameEngine* pge)
{
}

Mode GameMode_MainMenu::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    pge->Clear(olc::DARK_BLUE);

    pge->DrawString({ 5, 15 }, std::to_string(state->vecSequence.size()));
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, pge->ScreenHeight() / 2}, "OLC Simon");
    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 10}, "Press <SPACE> To Play");

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::ShowSequence;

    return Mode::MainMenu;
}
