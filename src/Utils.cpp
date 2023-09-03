#include "Utils.h"

void DrawStringCenter(olc::PixelGameEngine* pge, olc::vi2d pos, const std::string text, olc::Pixel fgColor, olc::Pixel bgColor)
{
    olc::vi2d offset = {
        (text.size() / 2) * 8,
        4
    };
    
    pge->DrawString(pos - offset, text, bgColor);
    pge->DrawString(pos - offset, text, fgColor);
}