#pragma once

#include "olcPixelGameEngine.h"


struct SimonButton {
    
    SimonButton(int id, olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key);
    void Draw(olc::PixelGameEngine* pge);    
    void Activate();
    void Deactivate();

    bool active = false;
    int id = -1;
    olc::Pixel activeColor;
    olc::Pixel idleColor;
    olc::vi2d pos;
    olc::vi2d size;
    olc::Key  key;
};
