#include "Tile.h"
//#include "Window.h"


Tile::Tile()
{

}

//------------------------------- FOR DEBUG ---------------
void Tile::color()
{
	m_tile.setFillColor(sf::Color(50, 116, 150));
}
//----------------------------------------------------

Tile::Tile(sf::Vector2f pos, bool isEdge, bool isOccupied)
{
	m_tile.setRadius(30);
	m_tile.setPosition(pos);
	m_tile.setFillColor(sf::Color(120, 210, 227));
	
	m_isEdge = isEdge;
	
	if (isOccupied)
		tileClicked();
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

bool Tile::alreadyVisited()
{
	return m_visited;
}

void Tile::setVisited(bool set)
{
	m_visited = set;
}

int Tile::getDistance()
{
	return m_distance;
}

void Tile::setDistance(int dist)
{
	m_distance = dist;
}

void Tile::setPred(Tile* pred)
{
	m_pred = pred;
}

Tile* Tile::getPred()
{
	return m_pred;
}

sf::Vector2f Tile::getPosition()
{
	return m_tile.getPosition();
}

void Tile::tileClicked()
{
	m_clicked = true;
	m_tile.setFillColor(sf::Color(50, 116, 150));
}

void Tile::tileUnclicked()
{
	m_clicked = false;
	m_tile.setFillColor(sf::Color(120, 210, 227));
}
