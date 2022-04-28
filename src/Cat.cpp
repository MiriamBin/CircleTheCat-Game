#include "Cat.h"
#include <iostream>

Cat::Cat(Board* board)
	:m_board(board), m_pos(m_board->getTile(5,5)), m_catCircled(false), m_catOnEdge(false)
{
	m_pos->tileOccupied(true);
	m_cat.setTexture(ResourcesManager::instance().getCatIcon());
	m_cat.setSize(sf::Vector2f(CAT_SIZE, CAT_SIZE));

	initCat();
	//m_cat.setOrigin(sf::Vector2f(CAT_SIZE, CAT_SIZE));
}

void Cat::goToNext()
{
	m_steps.push_back(m_pos);
	m_pos->tileOccupied(false);

	if (m_board->shortestPath(m_pos)) // if we have path - the cat isn't mukaf
	{
		m_cat.setPosition(m_pos->getPosition()); // move the cat
		m_pos->tileOccupied(true);

		if (m_pos->isTarget()) // if the cat isnt on the edge, continue 
			m_catOnEdge = true;  // here we need to reset the level
	}
	else
		m_catCircled = true;
}

void Cat::drawCat(sf::RenderWindow& window)
{
	window.draw(m_cat);  
}

void Cat::getLastStep()
{
	if (!m_steps.empty())
	{
		m_pos->tileOccupied(false);
		Tile* lastStep = m_steps[m_steps.size() - 1];
		m_pos = lastStep;
		m_cat.setPosition(m_pos->getPosition()); // move the cat
		m_steps.pop_back();
	}
}

void Cat::initCat()
{
	m_steps.clear();
	m_pos = m_board->getTile(5, 5);
	m_steps.push_back(m_board->getTile(5, 5));
	m_cat.setPosition(m_pos->getPosition());
	m_catOnEdge = false;
	m_catCircled = false;
}

bool Cat::isCatCircled()
{
	return m_catCircled;
}

bool Cat::isCatOnEdge()
{
	return m_catOnEdge;
}
