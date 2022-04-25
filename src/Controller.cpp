#include "Controller.h"

Controller::Controller()
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
        m_board.drawBoard(*m_window.getWindow());
    }
}

void Controller::handleClick(const sf::Vector2f pos)
{
    m_board.handleClick(pos);
}