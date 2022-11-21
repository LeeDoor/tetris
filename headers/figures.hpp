#pragma once
#include <vector>
#include "figure.hpp"

//class-array of preset figures
class Figures {
public:
    static const int figuresAmount = 7;

    static std::array < Figure, Figures::figuresAmount > figures;
    
    //returns random figure
    static Figure PickOne();
};