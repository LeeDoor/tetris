#include "headers/game_manager.hpp"
#include "headers/figures.hpp"
#include "headers/game_figure.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void GameManager::fillQueue() {
    queue = std::make_shared<std::vector<Figure>>();
    for (int i = 0; i < GameManager::queueSize; ++i) {
        queue->push_back(Figures::PickOne());
    }
}
std::shared_ptr<GameFigure> GameManager::getNextFigure() {
    queue->push_back(Figures::PickOne());
    std::shared_ptr<GameFigure> res = std::make_shared<GameFigure>
        (GameManager::startX, GameManager::startY, queue->front());
    queue->erase(queue->begin());
    return res;
}

void GameManager::Start() {
    field = std::make_shared<Field>();
    fillQueue();
    figure = getNextFigure();
    gameState = true;
    std::thread printThread(&GameManager::printLoop, this);
    std::thread controlThread(&GameManager::controlLoop, this);
    printThread.join();

    printGameOver();

    controlThread.join();
}

void GameManager::printGameOver() {
    print();
    printSeparator();
    std::cout << "Game Over!"; // scores
}

void GameManager::printLoop() {
    while (gameState) {
        print();
        figure->tryMove(Dir::down, field);
        isFigureSet();
        if (figure->isIntersects(field)) {
            gameState = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(600));
    }
}

void GameManager::controlLoop() {

    while (gameState) {
        interact();
    }
}

void GameManager::isFigureSet() {
    if (figure->isIntersects(figure->getX(), figure->getY() + 1, field)) {
        figure->setToField(field);
        figure = getNextFigure();
        if (field->clearRows()) {
            print();
        }
    }
}

void GameManager::printQueue() {
    std::cout << "next: " << std::endl;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < queue->size(); ++j) {
            for (int l = 0; l < 4; ++l) {
                std::cout << symchar((*queue)[j].get(l, i)) << ' ';
            }
        }
        std::cout << std::endl;
    }
}

void GameManager::printSeparator(int s) {
    std::cout << std::endl << std::endl << std::endl;
    for (int i = 0; i < s; ++i) {
        std::cout << "@ ";
    }
    std::cout << std::endl << std::endl << std::endl;
}

void GameManager::print() {
    system("cls");
    //std::cout << "\t";
    //for(int i = 0; i < Field::w; ++i) std::cout << i << " ";
    //std::cout << std::endl << std::endl;
    printQueue();
    printSeparator();

    for(int r = 0; r < Field::h; ++r) {
        //std::cout << r << "\t";
        for(int w = 0; w < Field::w; ++w) {
            int Y = r - figure->getY(), X = w - figure->getX();

            if(0 <= X && X < 4 && 0 <= Y && Y < 4) 
                std::cout << symchar(figure->get(X, Y) || field->get(w, r)) << " ";
            else 
                std::cout << symchar(field->get(w, r)) << " ";
        }
        std::cout << "|" << std::endl;
    }
    //std::cout << "\t";
    for (int i = 0; i < Field::w; ++i) std::cout << "__";
}

char GameManager::interact() {
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

char GameManager::symchar(bool a) {
    return (a ? '*' : ' ');
}