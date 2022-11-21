#pragma once
#include <memory>
#include <vector>
#include "field.hpp"
#include "figures.hpp"
#include "game_figure.hpp"

class GameManager {
public:
    void Start();
    void printLoop();
    void controlLoop();

private:
    static const int startX = 3, startY = 0, queueSize = 3;

    std::shared_ptr<Field> field;
    std::shared_ptr<GameFigure> figure;
    std::shared_ptr<std::vector<Figure>> queue;
    bool gameState;
    
    void fillQueue();
    std::shared_ptr<GameFigure> getNextFigure();

    void isFigureSet();

    void print();
    void printQueue();
    void printSeparator(int s = 20);
    void printGameOver();

    char interact();
    
    char symchar(bool a);
};