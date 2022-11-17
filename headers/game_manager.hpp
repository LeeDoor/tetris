#pragma once
#include <memory>
#include "field.hpp"
#include "figures.hpp"
#include "game_figure.hpp"

class GameManager {
public:
    void Start();
    void printLoop();
    void controlLoop();

private:
    static const int startX = 3, startY = 0;

    std::shared_ptr<Field> field;
    std::shared_ptr<GameFigure> figure;
    bool gameState;
    

    void print(std::shared_ptr<GameFigure> figure);
    char interact(std::shared_ptr<GameFigure> figure);
};