#include "headers/field.hpp"
#include <algorithm>

#include <iostream>

Field::Field() {
    std::array<bool, Field::w> arr;
    arr.fill(false);
    field.fill(arr);
}

bool Field::get(int x, int y) {
    return field[y][x];
}