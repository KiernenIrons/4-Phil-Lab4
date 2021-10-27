#include "../include/Clock.h"

Clock::Clock()
{
    restart();
}

void Clock::start()
{
    m_start = SDL_GetTicks();
}

void Clock::restart()
{
    m_start = 0;
    start();
}

uint32_t Clock::getElapsedTimeAsSeconds()
{
    return SDL_GetTicks() / 1000.0f;
}