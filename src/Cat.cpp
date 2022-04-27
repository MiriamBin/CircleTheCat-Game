#include "Cat.h"
#include <iostream>

Cat::Cat(Board* board)
	:m_board(board), m_pos(m_board->getTile(5,5))
{
	m_steps.push_back(m_board->getTile(5, 5));

	m_cat.setTexture(ResourcesManager::instance().getCatIcon());
	m_cat.setSize(sf::Vector2f(CAT_SIZE, CAT_SIZE));
	m_cat.setPosition(m_pos->getPosition());
	//m_cat.setOrigin(sf::Vector2f(CAT_SIZE, CAT_SIZE));
}

void Cat::goToNext()
{
	m_steps.push_back(m_pos);

	if (m_board->shortestPath(m_pos)) // if we have path - the cat isn't mukaf
	{
		// ***need to change to something prettier ****
		if (!m_pos->isEdge()) // if the cat isnt on the edge, continue 
		{
		}

		else
			std::cout << " YOU LOSE" << '\n';  // here we need to reset the level
		
		m_cat.setPosition(m_pos->getPosition()); // move the cat
	}
	else
		std::cout << "you won"; 
}

void Cat::DrawCat(sf::RenderWindow& window)
{
	//window.clear(sf::Color(225, 247, 247));
	window.draw(m_cat);  
	//window.display();
}

void Cat::getLastStep()
{
	Tile* lastStep = m_steps[m_steps.size() - 1];
	m_pos = lastStep;
	m_cat.setPosition(m_pos->getPosition()); // move the cat
	m_steps.pop_back();
}
