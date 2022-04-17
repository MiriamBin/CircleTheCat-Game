#pragma once
#include "Tile.h"
//#include "Macros.h"

class Controller;

class Board
{
public:
    Board();
    void drawBoard(sf::RenderWindow& window);
    void createNeighborsList();

    void colorForD();

private:
    std::vector< std::vector<Tile>> m_tiles;
    Tile m_target;
};