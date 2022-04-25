#pragma once
#include "Window.h"
#include "Board.h"
#include "ResourcesManager.h"
#include "Cat.h"
#include "Button.h"

class Controller
{
public:
    Controller();
    void run();
    void handleClick(const sf::Vector2f pos);
    void handleButtonClick(const sf::Vector2f pos);

private:
    Window m_window;
    Board m_board;
    Cat m_cat;
    Button m_reset;
    Button m_undo;
   // int m_clickCounter;

   // sf::Font m_font;

};