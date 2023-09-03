#include "GameState.h"

GameState::GameState()
{
    vecButtons.reserve(4);
}

void GameState::RenderField(olc::PixelGameEngine* pge)
{
    if(vecButtons.empty())
    {
        olc::vi2d center = {
            (pge->ScreenWidth()  / 2) - 1,
            (pge->ScreenHeight() / 2) - 1
        };

        vecButtons.push_back({
            olc::vi2d{0, 0},
            center,
            olc::GREEN,
            olc::VERY_DARK_GREEN
        });
        
        vecButtons.push_back({
            olc::vi2d{center.x + 1, 0},
            center,
            olc::RED,
            olc::VERY_DARK_RED
        });
        
        vecButtons.push_back({
            olc::vi2d{0, center.y + 1},
            center,
            olc::YELLOW,
            olc::VERY_DARK_YELLOW
        });
        
        vecButtons.push_back({
            olc::vi2d{center.x + 1, center.y + 1},
            center,
            olc::BLUE,
            olc::VERY_DARK_BLUE
        });

    }

    for(auto &button : vecButtons)
    {
        pge->FillRect(button.pos, button.size, button.active ? button.activeColor : button.idleColor);
        pge->DrawRect(button.pos, button.size, button.active ? olc::WHITE : olc::VERY_DARK_GREY);
    }

    pge->DrawString({5, 5}, std::to_string(gameIndex) + " : " + std::to_string(vecSequence.size()));
}

