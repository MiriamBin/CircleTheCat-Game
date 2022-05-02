#include "Window.h"


Window::Window()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Circle The Cat", sf::Style::Close | sf::Style::Titlebar)
{}


//------------------------------------------------ MAYBE NEED TO MOVE TO CONTROLLER
void Window::windowEvent(Controller& controller, Board& board)
{
    while (m_window.isOpen())
    {
        if (auto event = sf::Event{}; m_window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::MouseButtonReleased:
                board.handleClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                break;
            }
        }
        board.drawBoard(m_window);
    }
}

bool Window::isOpen()
{
    return m_window.isOpen();
}

sf::RenderWindow* Window::getWindow()
{
    return &m_window;
}