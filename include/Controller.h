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

private:
    void handleClick(const sf::Vector2f pos);
    void handleButtonClick(const sf::Vector2f pos);
    void drawGame();
    void setLoseOrWin();
    void handleLoseOrWin();

    Window m_window;
    Board m_board;
    Cat m_cat;

    Button m_reset;
    Button m_undo;

    bool m_win;
    bool m_lose;

    sf::RectangleShape m_winBackground;
    sf::RectangleShape m_loseBackground;
};