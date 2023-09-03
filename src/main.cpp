#include "olcPixelGameEngine.h"

#include "GameState.h"
#include "GameMode.h"
#include "GameMode_MainMenu.h"
#include "GameMode_ShowSequence.h"

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
        state.gameIndex = 0;
        state.vecSequence.reserve(100);
        
        state.x = 0;
        state.y = 0;
        state.z = 0;

        mapModes[Mode::Invalid]      = new GameMode(&state);
        mapModes[Mode::Credits]      = new GameMode(&state);
        mapModes[Mode::ShowSequence] = new GameMode_ShowSequence(&state);
        mapModes[Mode::Fail]         = new GameMode(&state);
        mapModes[Mode::MainMenu]     = new GameMode_MainMenu(&state);
        mapModes[Mode::Play]         = new GameMode(&state);
        
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
    GameState state;

};

int main()
{
    OLC_Simon game;
    if(game.Construct(320, 180, 4, 4))
        game.Start();

    return 0;
}

