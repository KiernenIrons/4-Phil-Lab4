#include "Clock.h"

Clock::Clock()
{
    start();
}

void Clock::start()
{
    m_start = SDL_GetTicks();
}

float Clock::getElapsedTimeAsSeconds()
{
    return static_cast<float>(SDL_GetTicks() - m_start) / 1000.0f;
}