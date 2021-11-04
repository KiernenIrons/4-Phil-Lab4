#pragma once

#include <vector>

class Factory
{
public:
    template<typename T>
    T* getAction()
    {
        return T();
    };
};