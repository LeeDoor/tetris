#pragma once
#include <array>

//class GameFigure;
class Field {
private:
    //clears a single id's row if it is full and returns true
    bool clearRow(int id);

public:
    static const int w = 10;
    static const int h = 20;

    std::array<std::array<bool, w>, h> field;

    Field();

    //gets value with (x;y) coords
    bool& get(int x, int y);
    //clears all filled rows and returns true if at least one line
    //is cleared
    bool clearRows();
};