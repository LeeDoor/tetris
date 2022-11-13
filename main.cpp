#include "headers/game_manager.hpp"
#include <iostream>
#include <memory>

class B {
public:
    B(int a) {}
};

int main(){
    GameManager a;
    a.Start();
    std::array<B, 2> arr = std::array<B, 2>{B(3), B(6)};
}