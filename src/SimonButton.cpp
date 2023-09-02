#include "SimonButton.h"

SimonButton::SimonButton(olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key, double soundFreq)
    : pos(pos), size(size), activeColor(activeColor), idleColor(idleColor), key(key), soundFreq(soundFreq)
{
    sound = olc::sound::Wave(1, sizeof(uint8_t), 44100, 22050);
    
    for (size_t i = 0; i < 22050; i++)
    {
        double dt = 1 / 44100.0;
        double t = double(i) * dt;
        sound.file.data()[i] = float(0.5 * sin(2.0 * soundFreq * 3.14159 * t));
    }
}

void SimonButton::Draw(olc::PixelGameEngine* pge)
{
    olc::Pixel color = (active) ? activeColor : idleColor;
    
    pge->FillRect(pos, size, color);
    pge->DrawRect(pos, size, olc::GREY);

    Deactivate();
}

void SimonButton::Activate()
{
    active = true;
}

void SimonButton::Deactivate()
{
    active = false;
}

