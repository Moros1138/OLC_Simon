#include "olcPixelGameEngine.h"
#include "olcSoundWaveEngine.h"

struct SimonButton {
    
    SimonButton(olc::vi2d pos, olc::vi2d size, olc::Pixel activeColor, olc::Pixel idleColor, olc::Key key, double soundFreq);
    void Draw(olc::PixelGameEngine* pge);    
    void Activate();
    void Deactivate();

    bool active = false;
    olc::Pixel activeColor;
    olc::Pixel idleColor;
    olc::vi2d pos;
    olc::vi2d size;
    olc::Key  key;
    
    double soundFreq;
    olc::sound::Wave sound;
};
