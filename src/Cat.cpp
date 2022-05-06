#include "Cat.h"
#include <iostream>

Cat::Cat(Board* board)
	:m_board(board), m_pos(m_board->getTile(5,5)), m_catCircled(false), m_catOnEdge(false)
{
	m_cat.setTexture(ResourcesManager::instance().getCatIcon());
	m_cat.setSize(sf::Vector2f(CAT_SIZE, CAT_SIZE));

	initCat();
}

void Cat::goToNext()
{
	srand(time(0));
	m_steps.push_back(m_pos);
	m_pos->tileOccupied(false);

	if (firtsStep)
	{
		auto tile = m_pos->getNeighborList()[rand() % m_pos->getNeighborList().size()];
		while (tile->isClicked())
		{
			tile = m_pos->getNeighborList()[rand() % m_pos->getNeighborList().size()];
		}

		m_pos = tile;
		m_cat.setPosition(m_pos->getPosition()); // move the cat
		m_pos->tileOccupied(true);
		firtsStep = false;
	}

	else if (m_board->shortestPath(m_pos)) // if we have path - the cat isn't mukaf
	{
		m_cat.setPosition(m_pos->getPosition()); // move the cat
		m_pos->tileOccupied(true);

		if (m_pos->isTarget()) // if the cat isnt on the edge, continue 
			m_catOnEdge = true;  
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
		m_pos->tileOccupied(true);
		m_steps.pop_back();
	}
}

void Cat::initCat()
{
	m_steps.clear();
	m_pos = m_board->getTile(5, 5);
	m_pos->tileOccupied(true);
	m_steps.push_back(m_board->getTile(5, 5));
	m_cat.setPosition(m_pos->getPosition());
	m_catOnEdge = false;
	m_catCircled = false;
	firtsStep = true;
}

void Cat::backToStart()
{
	auto size = m_steps.size();

	for (int i = 0; i < size; ++i)
	{
		getLastStep();
	}
	m_catOnEdge = false;
	m_catCircled = false;
	firtsStep = true;
}

bool Cat::isCatCircled() const
{
	return m_catCircled;
}

bool Cat::isCatOnEdge() const
{
	return m_catOnEdge;
}
