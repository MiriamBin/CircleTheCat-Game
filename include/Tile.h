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
    sf::CircleShape getTile();
    bool contain(sf::Vector2f location);
    void tileClicked();
    bool isClicked();
    
    bool alreadyVisited();
    void setVisited(bool set);
    int getDistance();
    void setDistance(int dist);
    void setPred(Tile* pred);
    Tile* getPred();

private:
    sf::CircleShape m_tile;
    bool m_isEdge = false;
    bool m_clicked = false;
    std::vector<Tile*> m_neighbors;
    bool m_visited = false;
    int m_distance = INT_MAX;
    Tile* m_pred = NULL;
};