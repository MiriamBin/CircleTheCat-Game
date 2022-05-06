#include "Window.h"


Window::Window()
	: m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Circle The Cat", sf::Style::Close | sf::Style::Titlebar)
{
    // set cute icon :)
    auto icon = sf::Image{};
    icon.loadFromFile("resources/cat.png");
    m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

bool Window::isOpen() const
{
    return m_window.isOpen();
}

sf::RenderWindow* Window::getWindow()
{
    return &m_window;
}