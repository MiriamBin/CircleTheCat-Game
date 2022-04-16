#pragma once
#include <SFML/Graphics.hpp>

class Window
{
public:
    Window();
    bool isOpen();
    sf::RenderWindow* getWindow();
 
private:
    sf::RenderWindow m_window;
   
};