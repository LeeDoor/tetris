#pragma once
#include <vector>
#include "figure.hpp"

class Figures {
public:
    static std::array<Figure, 5> figures;
    
    static Figure PickOne();
};