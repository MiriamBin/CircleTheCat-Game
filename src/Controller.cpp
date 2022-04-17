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

