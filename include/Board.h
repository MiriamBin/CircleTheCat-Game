#pragma once
#include "Tile.h"
#include <queue>

//#include "Macros.h"

class Controller;

class Board
{
public:
    Board();
    void drawBoard(sf::RenderWindow& window);
    void createNeighborsList();
    void clorTile(const sf::Vector2f pos);
    void handleClick(const sf::Vector2f location);
    bool bfs(Tile* src);
    bool shortestPath(Tile*& src);
    bool catCircled(Tile* src);
   // bool clicked();
   // void colorForD();
    

private:
    std::vector< std::vector<Tile>> m_tiles;
    Tile m_target;
};