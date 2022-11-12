#include "headers/figures.hpp"
#include <ctime>
#include <cstdlib>

std::array<Figure, 5> Figures::
figures = std::array<Figure, 5>{
    Figure
    (
        std::array<std::array<bool, 4>, 4>{
            std::array<bool, 4>{0, 0, 0, 0},
            std::array<bool, 4>{0, 1, 1, 0},
            std::array<bool, 4>{0, 1, 1, 0},
            std::array<bool, 4>{0, 0, 0, 0}
        }
    ),
    Figure
    (
        std::array<std::array<bool, 4>, 4>{
            std::array<bool, 4>{0, 0, 1, 0},
            std::array<bool, 4>{0, 0, 1, 0},
            std::array<bool, 4>{0, 0, 1, 0},
            std::array<bool, 4>{0, 0, 1, 0}
        }
    ),
    Figure
    (
        std::array<std::array<bool, 4>, 4>{
            std::array<bool, 4>{0, 0, 0, 0},
            std::array<bool, 4>{0, 1, 1, 0},
            std::array<bool, 4>{1, 1, 0, 0},
            std::array<bool, 4>{0, 0, 0, 0}
        }
    ),
    Figure
    (
        std::array<std::array<bool, 4>, 4>{
            std::array<bool, 4>{0, 0, 0, 0},
            std::array<bool, 4>{1, 1, 0, 0},
            std::array<bool, 4>{0, 1, 1, 0},
            std::array<bool, 4>{0, 0, 0, 0}
        }
    ),
    Figure
    (
        std::array<std::array<bool, 4>, 4>{
            std::array<bool, 4>{0, 0, 0, 0},
            std::array<bool, 4>{0, 1, 0, 0},
            std::array<bool, 4>{1, 1, 1, 0},
            std::array<bool, 4>{0, 0, 0, 0}
        }
    ),
};

Figure Figures::PickOne() {
    std::srand(std::time(NULL));
    return figures[std::rand() % 5];
}