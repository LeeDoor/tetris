#pragma once
#include <memory>
#include "field.hpp"
#include "figures.hpp"
#include "game_figure.hpp"

class GameManager {
public:
    void Start();

private:
    static const int startX = 3, startY = 0;

    std::shared_ptr<Field> field;
    
    void Print(GameFigure figure);
    void Interact(GameFigure& figure);
};