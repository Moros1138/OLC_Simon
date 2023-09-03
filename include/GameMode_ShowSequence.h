#pragma once
#include "GameMode.h"

class GameMode_ShowSequence : public GameMode
{
public:
    GameMode_ShowSequence(GameState* state);
    void OnCreate(olc::PixelGameEngine* pge) override;
    void OnEnter(olc::PixelGameEngine* pge) override;
    void OnExit(olc::PixelGameEngine* pge) override;
    Mode OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime) override;
};