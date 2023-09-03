#include "SimonButton.h"

SimonButton::SimonButton(int id, olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key)
    : id(id), pos(pos), size(size), activeColor(activeColor), idleColor(idleColor), key(key)
{
}

void SimonButton::Draw(olc::PixelGameEngine* pge)
{
    olc::Pixel color = (active) ? activeColor : idleColor;
    
    pge->FillRect(pos, size, color);
    pge->DrawRect(pos, size, (active) ? olc::WHITE : olc::GREY);
}


void SimonButton::Activate()
{
    active = true;
}

void SimonButton::Deactivate()
{
    active = false;
}

