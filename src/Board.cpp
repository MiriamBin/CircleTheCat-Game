#include "Board.h"
//#include "Window.h"


Board::Board()
{	
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		std::vector<Tile> row;
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			bool isEdge = false;
			if (i == 0 || i == 10 || j == 0 || j == 10)
				isEdge = true;

			Tile tile(sf::Vector2f(120 + j * (DIAMETER + SPACE) + (i % 2)* (TILE_RADIUS + SPACE/2), 45 + i * (DIAMETER + SPACE)), isEdge);

			row.push_back(tile);
		}
		m_tiles.push_back(row);
	}

	createNeighborsList();
	//colorForD();
}

void Board::drawBoard(sf::RenderWindow& window)
{
	window.clear(sf::Color(222, 249, 255));

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			m_tiles[i][j].draw(window);
		}
	}
	
	window.display();
}

void Board::createNeighborsList()
{
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			for (int k = -1; k <= 1; ++k)   // row
			{
				for (int l = -1; l <= 1; l++) // col
				{
					if((i + l) >= 0 && (i + l) < GRAPH_SIZE && (j + k) >= 0 && (j + k) < GRAPH_SIZE)
						if ((i % 2 == 0 && l != 0 && k == 1) || (i % 2 == 1 && l != 0 && k == -1) || k == 0 && l == 0)
							continue;
						else
							m_tiles[i][j].addNeighbor(&m_tiles[i + l][j + k]);
				}
			}
			if (m_tiles[i][j].isEdge())
			{
				m_target.addNeighbor(&m_tiles[i][j]);
				m_tiles[i][j].addNeighbor(&m_target);
			}
		}
	}
}
//
//void Board::colorForD()
//{
//	std::vector <Tile*> tmp = m_target.getNeighborList();
//
//	for (size_t i = 0; i < tmp.size(); i++)
//	{
//		tmp[i]->color();
//	}
//}

void Board::clorTile(const sf::Vector2f pos)
{
	for (size_t i = 0; i < GRAPH_SIZE; i++)
	{
		for (size_t j = 0; j < GRAPH_SIZE; j++)
		{
			/*if (m_tiles[i][j].getTile().getGlobalBounds().contains(pos))
			{
				m_tiles[i][j].color();
			}*/
		}
	}
}

//bool Board::clicked()
//{
//	return false;
//}
