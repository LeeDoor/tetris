#pragma once
#include <memory>
#include <vector>
#include "field.hpp"
#include "figures.hpp"
#include "game_figure.hpp"

//starts and manages the game
class GameManager {
public:
    //main game start function
    void Start();
    //function with screen update loop
    void printLoop();
    //function with user asking loop
    void controlLoop();

private:

    static const int 
        startX = 3, // start position of figure X
        startY = 0, // start position of figure Y
        queueSize = 3; // size of queue of figures

    //pointer on a field
    std::shared_ptr<Field> field; 
    //current moving figure
    std::shared_ptr<GameFigure> figure;
    //queue of figures
    std::shared_ptr<std::vector<Figure>> queue;
    //is game going now
    bool gameState;
    
    //creates queue and fills it with random figures 
    void fillQueue();
    //adds new figure to queue, returns and removes first element
    std::shared_ptr<GameFigure> getNextFigure();

    //checks is current figure now on its position
    void isFigureSet();

    //updates the field
    void print();
    //updates figure queue
    void printQueue();
    //prints a strip of @ symbols to separate different UI elements
    void printSeparator(int s = 20);
    //prints game over text
    void printGameOver();

    //reads symbol from console and applies moving/rotation according
    //to given symbol
    char interact();
    
    //converts bool to printable value
    char symchar(bool a);
};