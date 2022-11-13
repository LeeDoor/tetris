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
    int _x = x, _y = y;
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
                b.get(4 - 1 - i, j) = value[i][j];
                break;

            case left:
                b.get(i, 4 - 1 - j) = value[i][j];
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
            int fX = _x + i, fY = _y + j;
            if(get(i, j) && (0 > fX || fX >= Field::w || 0 > fY || fY >= Field::h)) {
                //std::cout << "intersects " << fX << " " << fY << " : " << x << " " << y << std::endl;
                return true;
            }
            if(get(i, j) && field->get(fX, fY)) {
                return true;
            }
        }
    }
    return false;
}

void GameFigure::setToField(std::shared_ptr<Field> field) {
    for (int r = 0; r < 4; ++r) {
        for (int w = 0; w < 4; ++w) {
            if (get(w, r)) {
                field->get(w + getX(), r + getY()) = true;
            }
        }
    }
}