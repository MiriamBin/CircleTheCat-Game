#include "Controller.h"
#include <iostream>


Controller::Controller()
    :m_cat(&m_board), m_win(false), m_lose(false)
{
    m_undo = Button(sf::Vector2f(1040, 400), sf::Vector2f(1040, 400), sf::Vector2f(150, 80), "UNDO", CHAR_SIZE);
    m_reset = Button(sf::Vector2f(1040, 550), sf::Vector2f(1040, 550), sf::Vector2f(150, 80), "RESET", CHAR_SIZE);

    m_winBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_winBackground.setTexture(ResourcesManager::instance().getWinImg());

    m_loseBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_loseBackground.setTexture(ResourcesManager::instance().getLoseImg());
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
        m_cat.drawCat(*m_window.getWindow());
        m_reset.printButton(*m_window.getWindow());
        m_undo.printButton(*m_window.getWindow());
        //------

        if (m_cat.isCatCircled())
        {
            m_win = true;
            m_window.getWindow()->draw(m_winBackground);
            
        }
        else if (m_cat.isCatOnEdge())
        {
            m_lose = true;
            m_window.getWindow()->draw(m_loseBackground);
        }
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_win)
        {
            m_board.updateLevel();
            m_win = false;
            m_board.createBoard();
            m_cat.initCat();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && m_lose)
        {
            m_lose = false;
            m_board.initCurrBoard();
            m_cat.initCat();
        }

        m_window.getWindow()->display();
    }
}

void Controller::handleClick(const sf::Vector2f pos)
{
    if (m_board.handleClick(pos))
    {
        m_cat.goToNext();
    }

    handleButtonClick(pos);
}

void Controller::handleButtonClick(const sf::Vector2f pos)
{
    if (m_reset.contain(pos))
    {
        m_board.createBoard();
        m_cat.initCat();
    }

    else if (m_undo.contain(pos))
    {
        m_board.getLastTile();
        m_cat.getLastStep();
    }
}

