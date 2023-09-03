#include "GameState.h"

GameState::GameState()
{
    vecButtons.reserve(4);
}

void GameState::RenderField(olc::PixelGameEngine* pge)
{
    olc::vi2d center = {
        (pge->ScreenWidth()  / 2) - 1,
        (pge->ScreenHeight() / 2) - 1
    };

    if(vecButtons.empty())
    {
        vecButtons.push_back({
            olc::vi2d{0, 0},
            center,
            olc::GREEN,
            olc::VERY_DARK_GREEN,
            olc::W
        });
        
        vecButtons.push_back({
            olc::vi2d{center.x + 1, 0},
            center,
            olc::RED,
            olc::VERY_DARK_RED,
            olc::E
        });
        
        vecButtons.push_back({
            olc::vi2d{0, center.y + 1},
            center,
            olc::YELLOW,
            olc::VERY_DARK_YELLOW,
            olc::S
        });
        
        vecButtons.push_back({
            olc::vi2d{center.x + 1, center.y + 1},
            center,
            olc::BLUE,
            olc::VERY_DARK_BLUE,
            olc::D
        });

    }

    for(auto &button : vecButtons)
    {
        pge->FillRect(button.pos, button.size, button.active ? button.activeColor : button.idleColor);
        pge->DrawRect(button.pos, button.size, button.active ? olc::WHITE : olc::VERY_DARK_GREY);
    }

    pge->DrawString(center + olc::vi2d{ -9, -9}, "W", olc::BLACK);
    pge->DrawString(center + olc::vi2d{ 11, -9}, "E", olc::BLACK);
    pge->DrawString(center + olc::vi2d{ -9, 11}, "S", olc::BLACK);
    pge->DrawString(center + olc::vi2d{ 11, 11}, "D", olc::BLACK);

    pge->DrawString(center + olc::vi2d{-10, -10}, "W");
    pge->DrawString(center + olc::vi2d{ 10, -10}, "E");
    pge->DrawString(center + olc::vi2d{-10,  10}, "S");
    pge->DrawString(center + olc::vi2d{ 10,  10}, "D");
}

