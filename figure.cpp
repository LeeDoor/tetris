#include "headers/figure.hpp"
#include <iostream>

Figure::Figure(Figure& figure) {
    value = figure.value;
}
Figure::Figure(std::array<std::array<bool, 4>, 4> _value) {
    value = _value;
}

bool& Figure::get (int x, int y) {
    return value[y][x];
}

void Figure::display() {
    for(int i = 0; i < 4; ++ i) {
        for(int j = 0; j < 4; ++j) {
            std::cout << value[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}