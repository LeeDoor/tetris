#include "headers/figure.hpp"


Figure::Figure(std::array<std::array<bool, 4>, 4> _value) {
    value = _value;
}

std::array<bool, 4> Figure::operator[](int i) {
    return value[i];
} 