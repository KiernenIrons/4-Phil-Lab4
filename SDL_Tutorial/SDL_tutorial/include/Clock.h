#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <SDL2/SDL_timer.h>
typedef unsigned int uint32_t;


class Clock
{
private: 
    Uint32 m_start;

public:

    Clock();

    void start();
    float getElapsedTimeAsSeconds();
};

#endif 