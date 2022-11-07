#include "headers/game_manager.hpp"
#include <iostream>
void GameManager::Print() {
    system("cls");
    for(int r = 0; r < Field::h; ++r) {
        for(int w = 0; w < Field::w; ++w) {
            std::cout << field[r][w] << " ";
        }
        std::cout << std::endl;
    }
}