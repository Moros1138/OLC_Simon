#include "olcPixelGameEngine.h"
#include "olcSoundWaveEngine.h"
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

