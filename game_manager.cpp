#include "headers/game_manager.hpp"
#include "headers/figures.hpp"
#include "headers/game_figure.hpp"
#include <iostream>
#include <chrono>
#include <thread>


void GameManager::Start() {
    field = std::make_shared<Field>();

    GameFigure figure(GameManager::startX, GameManager::startY, Figures::PickOne());
    bool gameState = true;

    //game loop
    while(gameState) {
        figure.tryMove(Dir::down, field);

        Print(figure);
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }
}

void GameManager::Print(GameFigure figure) {
    //system("cls");
    figure.display();
    for(int r = 0; r < Field::h; ++r) {
        for(int w = 0; w < Field::w; ++w) {
            int Y = r - figure.getY(), X = w - figure.getX();

            if(0 <= X && X < 4 && 0 <= Y && Y < 4) 
                std::cout << figure.get(X, Y) << " ";
            else 
                std::cout << field->get(r, w) << " ";
        }
        std::cout << std::endl;
    }
}