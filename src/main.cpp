#include "olcPixelGameEngine.h"

#include "GameMode.h"
#include "GameMode_MainMenu.h"

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
        mapModes[Mode::Invalid]  = new GameMode();
        mapModes[Mode::Credits]  = new GameMode();
        mapModes[Mode::Demo]     = new GameMode();
        mapModes[Mode::Fail]     = new GameMode();
        mapModes[Mode::MainMenu] = new GameMode_MainMenu();
        mapModes[Mode::Play]     = new GameMode();
        
        for(auto& mode : mapModes)
            mode.second->OnCreate(this);
        
        modeNext = Mode::MainMenu;
        return true;
    }
    
    bool OnUserUpdate(float fElapsedTime) override
    {
        if(modeCurrent != modeNext)
        {
            mapModes[modeCurrent]->OnExit(this);
            modeCurrent = modeNext;
            mapModes[modeCurrent]->OnEnter(this);
            return true;
        }

        modeNext = mapModes[modeCurrent]->OnUpdate(this, fElapsedTime);

        return !GetKey(olc::ESCAPE).bPressed;
    }

private:
    std::map<Mode, GameMode*> mapModes;
    Mode modeCurrent = Mode::Invalid;
    Mode modeNext;
};

int main()
{
    OLC_Simon game;
    if(game.Construct(320, 180, 4, 4))
        game.Start();

    return 0;
}

