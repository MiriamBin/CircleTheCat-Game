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
                handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)); // NEED TO CREATE HANDLECLICK FUNCTION
                break;
            default:
                break;
            }
        }
        m_board.drawBoard(*m_window.getWindow());  // NEED TO CREATE DRAW FUNCTION
    }

}

void Controller::handleClick(const sf::Vector2f pos)
{
    if (m_board.clicked())
    {
        m_board.
    }
}