#pragma once
//#include <SFML/Graphics.hpp>
#include "Macros.h"
//class Controller;

class Window
{
public:
    Window();
    bool isOpen();
    sf::RenderWindow* getWindow();
 
private:
    sf::RenderWindow m_window;
   
};