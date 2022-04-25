#include "Controller.h"

Controller::Controller()
    :m_cat(&m_board)
{
   
}

void Controller::run()
{
    while (m_window.isOpen())
    {
        if (auto event = sf::Event{}; m_window.getWindow()->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.getWindow()->close();
                break;
            case sf::Event::MouseButtonReleased:
                handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                break;
            default:
                break;
            }
        }
        //---- need to move to new function ----
        m_window.getWindow()->clear(sf::Color(222, 249, 255));  
        m_board.drawBoard(*m_window.getWindow());
        m_cat.DrawCat(*m_window.getWindow());
        m_window.getWindow()->display();
        //------
    }
}

void Controller::handleClick(const sf::Vector2f pos)
{
    if (m_board.handleClick(pos))
    {
        m_cat.goToNext(); // make the cat move
    }
}