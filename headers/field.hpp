#pragma once
#include <array>

class Field {
public:
    static const int w = 10;
    static const int h = 20;

    std::array<std::array<bool, w>, h> field;

    Field();

    std::array<bool, w> operator[](int i);
};