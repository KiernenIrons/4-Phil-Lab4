#pragma once

#include <vector>
#include <stack>
#include <iostream>
#include "Events.h"

class Command
{
public:
    void execute(gpp::Events* t_event, gpp::Events::Event t_T) {t_event->setCurrent(t_T);}
};