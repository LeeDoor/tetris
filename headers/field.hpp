#pragma once
#include <array>

//class GameFigure;
class Field {
private:
    bool clearRow(int id);

public:
    static const int w = 10;
    static const int h = 20;

    std::array<std::array<bool, w>, h> field;

    Field();

    bool& get(int x, int y);
    bool clearRows();
};