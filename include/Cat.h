#pragma once
#include "Tile.h"
#include "Macros.h"
#include "Board.h"
#include "ResourcesManager.h"

class Cat
{
public:
	Cat(Board* board);

	void goToNext();
	void DrawCat(sf::RenderWindow& window);
	void getLastStep();
	
private:
	Board* m_board;
	sf::RectangleShape m_cat;
	Tile* m_pos; // position
	std::vector<Tile*> m_steps;
};
