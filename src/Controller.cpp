#include "Controller.h"
#include <iostream>


Controller::Controller()
    :m_cat(&m_board), m_level(1)
{
    m_undo = Button(sf::Vector2f(1040, 400), sf::Vector2f(1040, 400), sf::Vector2f(150, 80), "UNDO", CHAR_SIZE);
    m_reset = Button(sf::Vector2f(1040, 550), sf::Vector2f(1040, 550), sf::Vector2f(150, 80), "RESET", CHAR_SIZE);

 // Button::Button(sf::Vector2f buttonPos, sf::Vector2f textPos, sf::Vector2f buttonSize, std::string buttonName, int textSize)
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
        m_reset.printButton(*m_window.getWindow());
        m_undo.printButton(*m_window.getWindow());
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

    handleButtonClick(pos);
}

void Controller::handleButtonClick(const sf::Vector2f pos)
{
    if (m_reset.contain(pos))
    {
        //m_reset = true;
        m_board.resetBoard();
        std::cout << " RESET \n";
    }

    else if (m_undo.contain(pos))
    {
        m_board.getLastTile();
        m_cat.getLastStep();
        std::cout << " UNDO \n";
    }
}

