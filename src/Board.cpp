#include "Board.h"
#include <iostream>		//DEBUG
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

void Board::handleClick(const sf::Vector2f pos)
{
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			if (m_tiles[i][j].contain(pos) && !m_tiles[i][j].isClicked())
			{
				m_tiles[i][j].tileClicked();
				return;
			}
		}
	}
}

bool Board::bfs(Tile* src)
{
	std::queue<Tile*> queue;

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			m_tiles[i][j].setVisited(false);
			m_tiles[i][j].setDistance(INT_MAX);
			m_tiles[i][j].setPred(NULL);
		}
	}
	m_target.setVisited(false);
	m_target.setDistance(INT_MAX);
	m_target.setPred(NULL);

	src->setVisited(true);
	src->setDistance(0);
	queue.push(src);

	while (!queue.empty()) 
	{
		Tile* u = queue.front();
		std::vector<Tile*>neighbors = u->getNeighborList();
		queue.pop();

		for (int i = 0; i < neighbors.size(); i++)
		{
			if (!neighbors[i]->alreadyVisited() && !neighbors[i]->isClicked())
			{
				neighbors[i]->setVisited(true);
				neighbors[i]->setDistance(u->getDistance() + 1);
				neighbors[i]->setPred(u);
				queue.push(neighbors[i]);

				// We stop BFS when we find
				// destination.
				if (neighbors[i] == &m_target)
					return true;
			}
		}
	}
	return false;
}

bool Board::shortestPath(Tile*& src)
{
	if (!bfs(src))
	{
		if (catCircled(src))
		{
			std::cout << "you won";
			return false;
		}
		else
		{
			return true;
			//------------------ random moves ----------------
		}
	}

	std::vector<Tile*> path;
	Tile* crawl = &m_target;
	path.push_back(crawl);

	while (crawl->getPred()->getPred())
	{
		path.push_back(crawl->getPred());
		crawl = crawl->getPred();
	}

	src = crawl;
	return true;
}

bool Board::catCircled(Tile* src)
{
	for (int i = 0; i < src->getNeighborList().size(); i++)
	{
		if (!src->getNeighborList()[i]->isClicked())
			return false;
	}
	return true;
}