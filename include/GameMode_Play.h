#pragma once
#include "GameMode.h"

class GameMode_Play : public GameMode
{
public:
    GameMode_Play(GameState* state);
    void OnCreate(olc::PixelGameEngine* pge) override;
    void OnEnter(olc::PixelGameEngine* pge) override;
    void OnExit(olc::PixelGameEngine* pge) override;
    Mode OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime) override;

private:
    float delayTracker;
    float delay;
};