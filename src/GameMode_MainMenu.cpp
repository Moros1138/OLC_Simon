#include "GameMode_MainMenu.h"
#include "Utils.h"

GameMode_MainMenu::GameMode_MainMenu()
{

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

        DrawStringCenter(pge, {pge->ScreenWidth() / 2, pge->ScreenHeight() / 2}, "OLC Simon");
        DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 10}, "Press <SPACE> To Play");
        DrawStringCenter(pge, {pge->ScreenWidth() / 2, (pge->ScreenHeight() / 2) + 20}, "Press <C> For Credits");

        if(pge->GetKey(olc::SPACE).bPressed)
            return Mode::Demo;

        if(pge->GetKey(olc::C).bPressed)
            return Mode::Credits;


    return Mode::MainMenu;
}
