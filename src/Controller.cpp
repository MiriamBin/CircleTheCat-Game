#include "Controller.h"

Controller::Controller()
{
}

void Controller::run()
{
    m_board.drawBoard(*m_window.getWindow());  // NEED TO CREATE DRAW FUNCTION
    while (m_window.isOpen())
    {
        m_window.windowEvent(*this, m_board);
    }

}

void Controller::handleClick(const sf::Vector2f pos)
{
   /* if (m_tile.contain(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))

    if (m_board.clicked())
    {
        m_board.
    }*/
}