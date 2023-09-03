#pragma once

#include "olcPixelGameEngine.h"
#include "GameState.h"

enum Mode {
    Invalid = 0,
    MainMenu,
    ShowSequence,
    Play,
    Fail
};

class GameMode
{
public:    
    GameMode();
    GameMode(GameState* state);
    virtual void OnCreate(olc::PixelGameEngine* pge);
    virtual void OnEnter(olc::PixelGameEngine* pge);
    virtual void OnExit(olc::PixelGameEngine* pge);
    virtual Mode OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime);

    GameState* state;

};