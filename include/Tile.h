#pragma once
#include "Macros.h"

//class Window;

class Tile
{
public:
    Tile();
    Tile(sf::Vector2f pos, bool isEdge);
    void draw(sf::RenderWindow& window) const;
    void addNeighbor(Tile* Neighbor);
    std::vector<Tile*> getNeighborList();
    void color();
    bool isEdge();
    bool contain(sf::Vector2f location);

private:
    sf::CircleShape m_tile;
    bool m_isEdge = false;
    std::vector<Tile*> m_neighbors;
};