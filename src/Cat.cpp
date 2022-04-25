#include "Cat.h"

Cat::Cat(Board* board)
	:m_board(board), m_pos(m_board->getTile(5,5))
{
	m_cat.setTexture(ResourcesManager::instance().getCatIcon());

	m_cat.setSize(sf::Vector2f(CAT_SIZE, CAT_SIZE));
	m_cat.setPosition(m_pos->getPosition());
}

