#include "olcPixelGameEngine.h"
#include <algorithm>
#include <random>
#define BAG_SIZE 100

constexpr int GreenButton  = 0;
constexpr int RedButton    = 1;
constexpr int YellowButton = 2;
constexpr int BlueButton   = 3;

struct SimonButton {
    
    SimonButton(olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key)
        : pos(pos), size(size), activeColor(activeColor), idleColor(idleColor), key(key)
    {
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

