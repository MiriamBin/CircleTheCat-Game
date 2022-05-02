#pragma once
#include "Tile.h"
#include <queue>
#include "ResourcesManager.h"
//#include "Macros.h"

class Controller;

class Board
{
public:
    Board();
    void drawBoard(sf::RenderWindow& window);
    void createNeighborsList();
    void setNeighbor(int i, int j);
    bool handleClick(const sf::Vector2f location);
    bool bfs(Tile* src);
    bool shortestPath(Tile*& src);
    bool catCircled(Tile* src);
    Tile* getTile(int index1, int index2);
    void getLastTile();
    void createBoard();
    void setOccupideTiles();
    void updateLevel();
    void initCurrBoard();

private:
    std::vector< std::vector<Tile>> m_tiles;
    Tile m_target;
    std::vector<Tile*> m_clickedTiles;
    sf::RectangleShape m_boardBackground;
    sf::Text m_levelText;
    sf::Text m_clickText;
    int m_clickCounter;
    int m_level;

    void updateText();
    void setText();

};