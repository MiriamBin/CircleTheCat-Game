#pragma once
#include "Tile.h"
#include "Macros.h"
#include "Board.h"
#include "ResourcesManager.h"

class Cat
{
public:
	Cat(Board* board);

	
private:
	Board* m_board;
	sf::RectangleShape m_cat;
	Tile* m_pos; // position
};
