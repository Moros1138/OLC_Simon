#include "olcPixelGameEngine.h"

#include "GameState.h"
#include "GameMode.h"
#include "GameMode_MainMenu.h"
#include "GameMode_ShowSequence.h"
#include "GameMode_Play.h"
#include "GameMode_Fail.h"

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
        
        mapModes[Mode::Invalid]      = new GameMode(&state);
        mapModes[Mode::ShowSequence] = new GameMode_ShowSequence(&state);
        mapModes[Mode::Fail]         = new GameMode_Fail(&state);
        mapModes[Mode::MainMenu]     = new GameMode_MainMenu(&state);
        mapModes[Mode::Play]         = new GameMode_Play(&state);
        
        for(auto& mode : mapModes)
            mode.second->OnCreate(this);
        
        modeNext = Mode::ShowSequence;
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

