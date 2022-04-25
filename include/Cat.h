#pragma once
#include "Tile.h"
#include "Macros.h"
#include "ResourcesManager.h"

class Cat
{
public:
	Cat();

	
private:
	sf::RectangleShape m_cat;
	Tile* m_pos; // position
};
