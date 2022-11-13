#include "headers/game_figure.hpp"
#include <iostream>

GameFigure::GameFigure(int _x, int _y, Figure baseFigure) 
    : x(_x), y(_y), Figure(baseFigure) {}

int GameFigure::getX() {
    return x;
}

int GameFigure::getY() {
    return y;
}

bool GameFigure::tryMove(Dir dir, std::shared_ptr<Field> field) {
    int _x, _y;
    switch (dir)
    {
    case left:
        _x = x - 1;
        _y = y;
        break;
    
    case right:
        _x = x + 1;
        _y = y;
        break;

    case up:
        _x = x;
        _y = y - 1;
        break;

    case down:
        _x = x;
        _y = y + 1;
    }
    if(!isIntersects(_x, _y, field)) {
        x = _x;
        y = _y;
        return true;
    }
    return false;
}

bool GameFigure::tryRotate(Dir dir, std::shared_ptr<Field> field) {
    GameFigure b = *this;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            switch(dir) {
            case right:
                b.get(j, 4 - 1 - i) = value[i][j];
                break;

            case left:
                b.get(4 - 1 - j, i) = value[i][j];
                break;
            }
        }
    }
    if(!b.isIntersects(field)) {
        value = b.value;
        return true;
    }
    return false;
}

bool GameFigure::isIntersects(std::shared_ptr<Field> field) {
    return isIntersects(x, y, field);
}
bool GameFigure::isIntersects(int _x, int _y, std::shared_ptr<Field> field) {
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            int fX = x + i, fY = y + j;
            if(get(i, j) && (0 > fX || fX >= Field::w - 1 || 0 > fY || fY >= Field::h - 1)) {
                return true;
            }
            if(get(i, j) && field->get(fX, fY)) {
                return true;
            }
        }
    }
    return false;
}