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
        Print(figure);
        Moving(figure);
        if (figure.isIntersects(figure.getX(), figure.getY() + 1, field)) {
            figure.setToField(field);
            figure = GameFigure(GameManager::startX, GameManager::startY, Figures::PickOne());
        }
    }
}

void GameManager::Print(GameFigure figure) {
    system("cls");
    //std::cout << "\t";
    //for(int i = 0; i < Field::w; ++i) std::cout << i << " ";
    //std::cout << std::endl << std::endl;

    for(int r = 0; r < Field::h; ++r) {
        //std::cout << r << "\t";
        for(int w = 0; w < Field::w; ++w) {
            int Y = r - figure.getY(), X = w - figure.getX();

            if(0 <= X && X < 4 && 0 <= Y && Y < 4) 
                std::cout << (figure.get(X, Y) || field->get(w, r) ? "*" : " ") << " ";
            else 
                std::cout << (field->get(w, r) ? "*" : " ") << " ";
        }
        std::cout << "|" << std::endl;
    }
    //std::cout << "\t";
    for (int i = 0; i < Field::w; ++i) std::cout << "__";
}

void GameManager::Moving(GameFigure& figure) {
    char inp;
    std::cin.get(inp);
    switch (inp) {
    case 'a':
        figure.tryMove(Dir::left, field);
        break;
    case 'd':
        figure.tryMove(Dir::right, field);
        break;
    case 's':
        figure.tryMove(Dir::down, field);
        figure.tryMove(Dir::down, field);
        break;
    default:
        figure.tryMove(Dir::down, field);
        break;
    }
}