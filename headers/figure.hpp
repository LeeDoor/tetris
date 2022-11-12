#pragma once

#pragma once
#include <array>

class Figure {
protected:
    std::array<std::array<bool, 4>, 4> value;
public:
    Figure(Figure& figure);
    Figure(std::array<std::array<bool, 4>, 4> _value);

    bool& get(int x, int y);

    void display();
};