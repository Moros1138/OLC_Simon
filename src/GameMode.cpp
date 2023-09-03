#include "GameMode.h"

GameMode::GameMode() : state(nullptr)
{
}

GameMode::GameMode(GameState* gameState) : state(state)
{
}

void GameMode::OnCreate(olc::PixelGameEngine* pge)
{
}

void GameMode::OnEnter(olc::PixelGameEngine* pge)
{
}

void GameMode::OnExit(olc::PixelGameEngine* pge)
{
}

Mode GameMode::OnUpdate(olc::PixelGameEngine *pge, float fElapsedTime)
{
    return Mode::Invalid;
}
