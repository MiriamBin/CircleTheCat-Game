#include "Tile.h"


Tile::Tile()
{}

Tile::Tile(bool isTarget)
{
	m_isTarget = isTarget;
}

Tile::Tile(sf::Vector2f pos, bool isEdge)
{
	m_tile.setRadius(TILE_RADIUS);
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

std::vector<Tile*> Tile::getNeighborList() const
{
	return m_neighbors;
}

bool Tile::isEdge() const
{
	return m_isEdge;
}

sf::CircleShape Tile::getTile() const
{
	return m_tile;
}

bool Tile::contain(sf::Vector2f location) const
{
	return m_tile.getGlobalBounds().contains(location);
}

bool Tile::isClicked() const
{
	return m_clicked;
}

bool Tile::alreadyVisited() const
{
	return m_visited;
}

void Tile::setVisited(bool set)
{
	m_visited = set;
}

int Tile::getDistance() const
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

Tile* Tile::getPred() const
{
	return m_pred;
}

sf::Vector2f Tile::getPosition() const
{
	return m_tile.getPosition();
}

void Tile::tileOccupied(bool set)
{
	m_clicked = set;
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

bool Tile::isTarget() const
{
	return m_isTarget;
}