#pragma once

#pragma once
#include <array>

class Figure {
private:
    std::array<std::array<bool, 4>, 4> value;
public:
    Figure(std::array<std::array<bool, 4>, 4> _value);

    std::array<bool, 4> operator[](int i);
};