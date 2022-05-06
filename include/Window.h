#pragma once
#include "Macros.h"
#include "Board.h"


class Controller;

class Window
{
public:
    Window();
    bool isOpen() const;
    sf::RenderWindow* getWindow();
 
private:
    sf::RenderWindow m_window;
};