#pragma once

#include "olcPixelGameEngine.h"

struct Button {
    olc::vi2d pos;
    olc::vi2d size;
    olc::Pixel activeColor;
    olc::Pixel idleColor;
    olc::Key key;
    bool active = false;
    
    void Activate();
    void Deactivate();
};