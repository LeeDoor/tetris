#include "headers/field.hpp"
#include <algorithm>

#include <iostream>

Field::Field() {
    std::array<bool, Field::w> arr;
    arr.fill(false);
    field.fill(arr);
}

std::array<bool, Field::w> Field::operator[](int i) {
    return field[i];
}