#include "Utils.h"

void DrawStringCenter(olc::PixelGameEngine* pge, olc::vi2d pos, std::string text, const olc::Pixel fgColor, const olc::Pixel bgColor )
{
    int textSize = text.size();
    olc::vi2d offset = {
        (textSize / 2) * 8,
        4
    };
    
    pge->DrawString(pos - offset, text, bgColor);
    pge->DrawString(pos - offset, text, fgColor);
}
