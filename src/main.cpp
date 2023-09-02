#include "olcPixelGameEngine.h"
#include <algorithm>
#include <random>
#define BAG_SIZE 100

constexpr int GreenButton  = 0;
constexpr int RedButton    = 1;
constexpr int YellowButton = 2;
constexpr int BlueButton   = 3;

struct SimonButton {
    
    SimonButton(olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key, double soundFreq)
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

    void Draw(olc::PixelGameEngine* pge)
    {
        olc::Pixel color = (active) ? activeColor : idleColor;
        
        pge->FillRect(pos, size, color);
        pge->DrawRect(pos, size, olc::GREY);

        Deactivate();
    }

    void Activate()
    {
        active = true;
    }

    void Deactivate()
    {
        active = false;
    }

    bool active = false;
    olc::Pixel activeColor;
    olc::Pixel idleColor;
    olc::vi2d pos;
    olc::vi2d size;
    olc::Key  key;
    
    double soundFreq;
    olc::sound::Wave sound;
};

class OLC_Simon : public olc::PixelGameEngine
{
public:
    OLC_Simon()
    {
        sAppName = "OLC Simon";
    }

public:

    bool OnUserCreate() override
    {
        return true;
    }

    // Called by olcConsoleGameEngine
    bool OnUserUpdate(float fElapsedTime) override
    {
        return !GetKey(olc::ESCAPE).bPressed;
    }
};

int main()
{
    OLC_Simon game;
    if(game.Construct(320, 180, 4, 4))
        game.Start();

    return 0;
}

