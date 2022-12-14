#pragma once
#include "figure.hpp"
#include "direction.hpp"
#include "field.hpp"
#include <memory>

//figure which is currently now in the game
class GameFigure : public Figure {
private:
    int x, y;
public:
    GameFigure(int _x, int _y, Figure baseFigure);

    //returns current X coord
    int getX();
    //reutrns current Y coord
    int getY();

    //if its possible to move figure, moves and returns true
    //overwise doesnt move and returns false
    bool tryMove(Dir dir, std::shared_ptr<Field> field);

    //if its possible to rotate figure, rotates and returns true
    //overwise doesnt rotate and returns false
    //dir can only be left or right
    bool tryRotate(Dir dir, std::shared_ptr<Field> field);

    //checks, is this figure on this coords intersects with objects on field
    bool isIntersects(int _x, int _y, std::shared_ptr<Field> field);
    //if x & y not set, it uses its own x y values
    bool isIntersects(std::shared_ptr<Field> field);

    //if figure is already done, save its value to the field
    void setToField(std::shared_ptr<Field> field);
};