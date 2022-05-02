#include "Controller.h"
#include <iostream>


Controller::Controller()
    :m_cat(&m_board), m_win(false), m_lose(false)
{
    m_undo = Button(sf::Vector2f(1175, 650), sf::Vector2f(1175, 640), sf::Vector2f(200, 80), "UNDO", CHAR_SIZE);
    m_reset = Button(sf::Vector2f(1175, 750), sf::Vector2f(1175, 740), sf::Vector2f(200, 80), "RESET", CHAR_SIZE);

    m_winBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_winBackground.setTexture(ResourcesManager::instance().getWinImg());

    m_loseBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    m_loseBackground.setTexture(ResourcesManager::instance().getLoseImg());
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

        drawGame();
        setLoseOrWin();
        handleLoseOrWin();

        m_window.getWindow()->display();
    }
}

void Controller::handleClick(const sf::Vector2f pos)
{
    if ((!m_lose && !m_win) && m_board.handleClick(pos))
    {
        ResourcesManager::instance().playSound();
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

void Controller::drawGame()
{
    m_window.getWindow()->clear(sf::Color(222, 249, 255));
    m_board.drawBoard(*m_window.getWindow());
    m_cat.drawCat(*m_window.getWindow());
    m_reset.printButton(*m_window.getWindow());
    m_undo.printButton(*m_window.getWindow());
}

void Controller::setLoseOrWin()
{
    if (m_cat.isCatCircled()) //win
    {
        m_win = true;
        m_window.getWindow()->draw(m_winBackground);
    }

    else if (m_cat.isCatOnEdge()) //lose
    {
        m_lose = true;
        m_window.getWindow()->draw(m_loseBackground);
    }
}

void Controller::handleLoseOrWin()
{
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
        m_cat.backToStart();
    }
}