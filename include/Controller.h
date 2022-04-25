#pragma once
#include "Window.h"
#include "Board.h"
#include "ResourcesManager.h"

class Controller
{
public:
    Controller();
    void run();
    void handleClick(const sf::Vector2f pos);

private:
    Window m_window;
    Board m_board;
   // int m_clickCounter;

   // sf::Font m_font;

};