#pragma once
#include "Macros.h"


class Tile
{
public:
    Tile();
    Tile(bool isTarget);
    Tile(sf::Vector2f pos, bool isEdge);

    void draw(sf::RenderWindow& window) const;
    std::vector<Tile*> getNeighborList() const;
    void addNeighbor(Tile* Neighbor);
    sf::CircleShape getTile() const;
    bool contain(sf::Vector2f location) const;
    sf::Vector2f getPosition() const;

    void tileClicked();
    void tileUnclicked();
    void tileOccupied(bool set);

    bool isEdge() const;
    bool isTarget() const;
    bool isClicked() const;

    bool alreadyVisited() const;
    void setVisited(bool set);

    int getDistance() const;
    void setDistance(int dist);

    Tile* getPred() const;
    void setPred(Tile* pred);

private:
    sf::CircleShape m_tile;
    bool m_isEdge = false;
    bool m_clicked = false;
    std::vector<Tile*> m_neighbors;
    bool m_visited = false;
    bool m_isTarget = false;
    int m_distance = INT_MAX;
    Tile* m_pred = NULL;
};