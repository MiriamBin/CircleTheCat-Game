#pragma once
#include "Window.h"
#include "Board.h"
#include "ResourcesManager.h"
#include "Cat.h"

class Controller
{
public:
    Controller();
    void run();
    void handleClick(const sf::Vector2f pos);

private:
    Window m_window;
    Board m_board;
    Cat m_cat;
   // int m_clickCounter;

   // sf::Font m_font;

};