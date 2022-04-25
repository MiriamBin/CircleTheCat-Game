#include "Cat.h"

Cat::Cat()
{
	m_cat.setTexture(ResourcesManager::instance().getCatIcon());

	m_cat.setSize(sf::Vector2f(CAT_SIZE, CAT_SIZE));
	m_cat.setPosition();
}

