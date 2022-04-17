#include "Window.h"
//#include "Controller.h"
//#include "Macros.h"


Window::Window()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Circle The Cat", sf::Style::Close | sf::Style::Titlebar)
{
    m_window.clear(sf::Color(222, 249, 255));
    m_window.display();
}

bool Window::isOpen()
{
    return m_window.isOpen();
}

sf::RenderWindow* Window::getWindow()
{
    return &m_window;
}