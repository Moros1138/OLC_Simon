#include "olcPixelGameEngine.h"
#include "olcSoundWaveEngine.h"
#include "SimonButton.h"

#include <algorithm>
#include <random>

#define BAG_SIZE 100

constexpr int GreenButton  = 0;
constexpr int RedButton    = 1;
constexpr int YellowButton = 2;
constexpr int BlueButton   = 3;

class OLC_Simon : public olc::PixelGameEngine
{
public:
    OLC_Simon()
    {
        sAppName = "OLC Simon";
    }

public:
    
    std::vector<int> vecMemory;
    std::vector<SimonButton*> vecButtons;

	olc::sound::WaveEngine engine;
	olc::sound::Wave custom_wave;    
    
    bool OnUserCreate() override
    {
		engine.InitialiseAudio(44100, 1);

        // CREATE BUTTONS

        olc::vi2d centerScreen = {
            (ScreenWidth() / 2) - 1,
            (ScreenHeight() / 2) - 1
        };
        
        // prevent allocation fuckery
        vecButtons.reserve(4);

        vecButtons.push_back(new SimonButton({0, 0}, centerScreen, olc::GREEN, olc::DARK_GREEN, olc::W, 783.99));
        vecButtons.push_back(new SimonButton({ centerScreen.x, 0}, centerScreen, olc::RED, olc::DARK_RED, olc::E, 329.63));
        vecButtons.push_back(new SimonButton({ 0, centerScreen.y}, centerScreen, olc::YELLOW, olc::DARK_YELLOW, olc::S, 523.25));
        vecButtons.push_back(new SimonButton(centerScreen, centerScreen, olc::BLUE, olc::DARK_BLUE, olc::D, 392.0));
        
        // generate bag
        vecMemory.reserve(BAG_SIZE);
        
        for(int i = 0; i < BAG_SIZE; i++)
            vecMemory.push_back(0);

        std::random_device rd;
        std::mt19937 generator(rd());
        
        int counter = 100;
        
        while(counter > 0)
        {
            // bag of buttons
            std::vector<int> tempBag = { 1, 2, 3, 4 };
            
            // shuffle the bag, but ensure no repeats
            do
            {
                std::shuffle(tempBag.begin(), tempBag.end(), generator);
            } while(tempBag[0] == vecMemory[counter]);
            
            for(int &button : tempBag)
            {
                vecMemory[counter-1] = button;
                counter--;
            }
        }
                
        return true;
    }

    // Called by olcConsoleGameEngine
    bool OnUserUpdate(float fElapsedTime) override
    {
        // INPUT
        for(auto button : vecButtons)
        {
            if(GetKey(button->key).bHeld)
			    button->Activate();
            
            if(GetKey(button->key).bPressed)
                engine.PlayWaveform(&button->sound);
        }
                

        // RENDERING
        for(auto button : vecButtons)
            button->Draw(this);
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

