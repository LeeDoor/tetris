#include "headers/game_manager.hpp"
#include "headers/figures.hpp"
#include "headers/game_figure.hpp"
#include <iostream>
#include <chrono>
#include <thread>


void GameManager::Start() {
    field = std::make_shared<Field>();

    figure = std::make_shared<GameFigure>(GameManager::startX, GameManager::startY, Figures::PickOne());
    gameState = true;
    std::thread printThread(&GameManager::printLoop, this);
    std::thread controlThread(&GameManager::controlLoop, this);
    printThread.join();
}

void GameManager::printLoop() {
    while (gameState) {
        print(figure);
        figure->tryMove(Dir::down, field);

        if (figure->isIntersects(figure->getX(), figure->getY() + 1, field)) {
            figure->setToField(field);
            figure = std::make_shared<GameFigure>(GameManager::startX, GameManager::startY, Figures::PickOne());
            if (field->clearRows()) print(figure);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void GameManager::controlLoop() {

    while (gameState) {
        char inp = interact(figure);
    }
}

void GameManager::print(std::shared_ptr<GameFigure> figure) {
    system("cls");
    //std::cout << "\t";
    //for(int i = 0; i < Field::w; ++i) std::cout << i << " ";
    //std::cout << std::endl << std::endl;

    for(int r = 0; r < Field::h; ++r) {
        //std::cout << r << "\t";
        for(int w = 0; w < Field::w; ++w) {
            int Y = r - figure->getY(), X = w - figure->getX();

            if(0 <= X && X < 4 && 0 <= Y && Y < 4) 
                std::cout << (figure->get(X, Y) || field->get(w, r) ? "*" : " ") << " ";
            else 
                std::cout << (field->get(w, r) ? "*" : " ") << " ";
        }
        std::cout << "|" << std::endl;
    }
    //std::cout << "\t";
    for (int i = 0; i < Field::w; ++i) std::cout << "__";
}

char GameManager::interact(std::shared_ptr<GameFigure> figure) {
    char inp;
    std::cin.get(inp);
    
    switch (inp) {
        //moving figure
    case 'a':
        figure->tryMove(Dir::left, field);
        break;
    case 'd':
        figure->tryMove(Dir::right, field);
        break;
    case 's':
        figure->tryMove(Dir::down, field);
        break;

        // rotating
    case 'e':
        figure->tryRotate(Dir::right, field);
        break;
    case 'q':
        figure->tryRotate(Dir::left, field);
        break;
    }
    return inp;
}