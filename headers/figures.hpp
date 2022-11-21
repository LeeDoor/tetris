#pragma once
#include <vector>
#include "figure.hpp"

class Figures {
public:
    static const int figuresAmount = 7;

    static std::array < Figure, Figures::figuresAmount > figures;
    
    static Figure PickOne();
};