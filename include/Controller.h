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
    int m_level = 1;
    //bool m_resetBoard = false;
    bool m_win;
    bool m_lose;

    sf::RectangleShape m_winBackground;
    sf::RectangleShape m_loseBackground;
};