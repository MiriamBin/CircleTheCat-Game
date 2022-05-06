#pragma once
#include "Tile.h"
#include <queue>
#include "ResourcesManager.h"


class Controller;

class Board
{
public:
    Board();
    void drawBoard(sf::RenderWindow& window);
    bool handleClick(const sf::Vector2f location);
    bool shortestPath(Tile*& src);
    Tile* getTile(int index1, int index2);
    void createBoard();
    void updateLevel();
    void getLastTile();
    void initCurrBoard();

private:
    void setOccupideTiles();
    void createNeighborsList();
    void setNeighbor(int i, int j);
    void setText();
    void updateText();
    bool bfs(Tile* src);
    bool catCircled(Tile* src);

    std::vector< std::vector<Tile>> m_tiles;
    Tile m_target;
    std::vector<Tile*> m_clickedTiles;
    sf::RectangleShape m_boardBackground;
    sf::Text m_levelText;
    sf::Text m_clickText;
    int m_clickCounter;
    int m_level;
};