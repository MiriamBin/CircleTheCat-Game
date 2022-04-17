#pragma once
//#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Board.h"

class Controller;

class Window
{
public:
    Window();
    //void windowEvent(Controller& controller, Board& board);
    bool isOpen();
    sf::RenderWindow* getWindow();
 
private:
    sf::RenderWindow m_window;
   
};