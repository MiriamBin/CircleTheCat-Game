#pragma once
#include "Tile.h"
#include "Macros.h"
#include "Board.h"
#include "ResourcesManager.h"

class Cat
{
public:
	Cat(Board* board);

	void drawCat(sf::RenderWindow& window);
	void goToNext();
	void getLastStep();
	void initCat();

	void backToStart();

	bool isCatCircled() const;
	bool isCatOnEdge() const;

private:
	Board* m_board;
	sf::RectangleShape m_cat;
	Tile* m_pos;
	std::vector<Tile*> m_steps;
	bool firtsStep = true;
	bool m_catOnEdge;
	bool m_catCircled;
};
