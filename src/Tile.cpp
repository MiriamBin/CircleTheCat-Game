#include "Tile.h"
//#include "Window.h"


Tile::Tile()
{
}

Tile::Tile(sf::Vector2f pos, bool isEdge)
{
	m_tile.setRadius(30);
	m_tile.setPosition(pos);
	m_tile.setFillColor(sf::Color(120, 210, 227));
	m_isEdge = isEdge;
}

void Tile::draw(sf::RenderWindow& window) const
{
	window.draw(m_tile);
}

void Tile::addNeighbor(Tile* neighbor)
{
	m_neighbors.push_back(neighbor);
}

std::vector<Tile*> Tile::getNeighborList()
{
	return m_neighbors;
}

void Tile::color()
{
	m_tile.setFillColor(sf::Color(50, 116, 150));
}

bool Tile::isEdge()
{
	return m_isEdge;
}

sf::CircleShape Tile::getTile()
{
	return m_tile;
}

bool Tile::contain(sf::Vector2f location)
{
	return m_tile.getGlobalBounds().contains(location);
}

bool Tile::isClicked()
{
	return m_clicked;
}

void Tile::tileClicked()
{
	m_clicked = true;

	color();
}