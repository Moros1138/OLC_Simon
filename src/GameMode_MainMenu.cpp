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

    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) - 32}, "OLC Simon");

    DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 16}, "Press <SPACE> To Play");
    // DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 32}, "Press <ESC> to Quit");

    if(pge->GetKey(olc::SPACE).bPressed)
        return Mode::ShowSequence;

    return Mode::MainMenu;
}
