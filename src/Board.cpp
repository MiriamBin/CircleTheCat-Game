#include "Board.h"
#include <iostream>		//DEBUG
//#include "Window.h"


Board::Board()
	:m_clickCounter(0), m_level(1)
{	
	m_target = Tile(true);
	setText();
	srand(time(0));
	createBoard();
}

void Board::createBoard()
{
	m_clickCounter = 0;
	updateText();
	m_tiles.clear();
	int counter = 0;

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		std::vector<Tile> row;
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			bool isEdge = false, isOccupied = false;

			if (i == 0 || i == 10 || j == 0 || j == 10)
				isEdge = true;

			Tile tile(sf::Vector2f(120 + j * (DIAMETER + SPACE) + (i % 2) * (TILE_RADIUS + SPACE / 2), 45 + i * (DIAMETER + SPACE)), isEdge/*, isOccupied*/);

			row.push_back(tile);
		}
		m_tiles.push_back(row);
	}
	setOccupideTiles();
	createNeighborsList();
}

void Board::setOccupideTiles()
{
	for (int m = 0; m < (14 - 5 * (m_level - 1)); ++m)
	{
		int row = rand() % GRAPH_SIZE,
			col = rand() % GRAPH_SIZE;

		if (row == 5 && col == 5)
			continue;

		m_tiles[row][col].tileClicked();
	}
}

void Board::updateLevel()
{
	if (m_level == 3)
		m_level = 1;
	else
		++m_level;
}

void Board::setText()
{
	m_levelText.setFont(*ResourcesManager::instance().getFont());
	m_levelText.setCharacterSize(CHAR_SIZE);
	m_levelText.setPosition(950, 140);
	m_levelText.setColor(sf::Color(6, 79, 97));

	m_clickText.setFont(*ResourcesManager::instance().getFont());
	m_clickText.setCharacterSize(CHAR_SIZE);
	m_clickText.setPosition(950, 240);
	m_clickText.setColor(sf::Color(6, 79, 97));
}

void Board::updateText()
{
	m_levelText.setString("Level: " + std::to_string(m_level));
	m_clickText.setString("Click: " + std::to_string(m_clickCounter));
}

void Board::drawBoard(sf::RenderWindow& window)
{
	//window.clear(sf::Color(222, 249, 255));

	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			m_tiles[i][j].draw(window);
		}
	}
	window.draw(m_levelText);
	window.draw(m_clickText);
	this->m_clickText.setString("Steps: " + std::to_string(m_clickCounter));
	//window.display();
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

bool Board::handleClick(const sf::Vector2f pos)
{
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			if (m_tiles[i][j].contain(pos) && !m_tiles[i][j].isClicked())
			{
				m_clickedTiles.push_back(&m_tiles[i][j]);
				m_tiles[i][j].tileClicked();
				++m_clickCounter;
				return true;
			}
		}
	}
	return false;
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
	srand(time(0));

	if (!bfs(src))
	{
		if (catCircled(src))
		{
			return false;
		}
		else
		{
			Tile* tile = src->getNeighborList()[rand() % src->getNeighborList().size()];
			while (tile->isClicked())
			{
				tile = src->getNeighborList()[rand() % src->getNeighborList().size()];
			}
			src = tile;
			//src = list[rand() % list.size()];
			return true;
			
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

void Board::getLastTile()
{
	if (!m_clickedTiles.empty() && m_clickCounter > 0)
	{
		Tile* lastTile = m_clickedTiles[m_clickedTiles.size() - 1];
		lastTile->tileUnclicked();
		m_clickedTiles.pop_back();
		--m_clickCounter;
	}
}

Tile* Board::getTile(int index1, int index2)
{
	return &m_tiles[index1][index2];
}

void Board::initCurrBoard()
{
	auto size = m_clickedTiles.size();

	for (int i = 0; i < size; ++i)
	{
		getLastTile();
	}
	updateText();
}