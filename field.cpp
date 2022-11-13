#include "headers/field.hpp"
#include <algorithm>

Field::Field() {
    std::array<bool, Field::w> arr;
    arr.fill(false);
    field.fill(arr);
}

bool& Field::get(int x, int y) {
    return field[y][x];
}

bool Field::clearRows() {
    bool res = false;
    for (int i = 0; i < Field::h; ++i) {
        if (clearRow(i)) {
            res = true;
            for (int j = i; j > 0; --j) {
                swap(field[j], field[j - 1]);
            }
        }
    }
    return res;
}

bool Field::clearRow(int id) {
    for (int i = 0; i < Field::w; ++i) {
        if (!get(i, id))return false;
    }
    for (int i = 0; i < Field::w; ++i) {
        get(i, id) = false;
    }
    return true;
}