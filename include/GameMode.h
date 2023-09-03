#pragma once

#include "olcPixelGameEngine.h"

enum Mode {
    Invalid = 0,
    MainMenu,
    Credits,
    Demo,
    Play,
    Fail
};

class GameMode
{
public:    
    GameMode();
    virtual void OnCreate(olc::PixelGameEngine* pge);
    virtual void OnEnter(olc::PixelGameEngine* pge);
    virtual void OnExit(olc::PixelGameEngine* pge);
    virtual Mode OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime);
};