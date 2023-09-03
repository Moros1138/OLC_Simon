#pragma once
#include "GameMode.h"

class GameMode_MainMenu : public GameMode
{
public:
    GameMode_MainMenu();
    void OnCreate(olc::PixelGameEngine* pge) override;
    void OnEnter(olc::PixelGameEngine* pge) override;
    void OnExit(olc::PixelGameEngine* pge) override;
    Mode OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime) override;
};