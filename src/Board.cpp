#include "Board.h"
#include <iostream>	


Board::Board()
	:m_clickCounter(0), m_level(1)
{	
	m_boardBackground.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
	m_boardBackground.setTexture(ResourcesManager::instance().getBackground());

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

			Tile tile(sf::Vector2f(100 + j * (DIAMETER + SPACE) + (i % 2) * 
				(TILE_RADIUS + SPACE / 2), 60 + i * (DIAMETER + SPACE)), isEdge);

			row.push_back(tile);
		}
		m_tiles.push_back(row);
	}
	setOccupideTiles();
	createNeighborsList();
}

void Board::setOccupideTiles()
{
	auto num = (14 - 5 * (m_level - 1));

	for (int i = 0; i < num; ++i)
	{
		int row = rand() % GRAPH_SIZE,
			col = rand() % GRAPH_SIZE;

		if (row == GRAPH_SIZE/2 && col == GRAPH_SIZE/2)
			continue;

		if (m_tiles[row][col].isClicked())
			++num;
		else
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
	m_levelText.setPosition(1080, 140);
	m_levelText.setColor(sf::Color(6, 79, 97));

	m_clickText.setFont(*ResourcesManager::instance().getFont());
	m_clickText.setCharacterSize(CHAR_SIZE);
	m_clickText.setPosition(1080, 240);
	m_clickText.setColor(sf::Color(6, 79, 97));
}

void Board::updateText()
{
	m_levelText.setString("Level: " + std::to_string(m_level));
	m_clickText.setString("Click: " + std::to_string(m_clickCounter));
}

void Board::drawBoard(sf::RenderWindow& window)
{
	window.draw(m_boardBackground);

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
}

void Board::createNeighborsList()
{
	for (int i = 0; i < GRAPH_SIZE; i++)
	{
		for (int j = 0; j < GRAPH_SIZE; j++)
		{
			setNeighbor(i, j);

			if (m_tiles[i][j].isEdge())
			{
				m_target.addNeighbor(&m_tiles[i][j]);
				m_tiles[i][j].addNeighbor(&m_target);
			}
		}
	}
}

void Board::setNeighbor(int i, int j)
{
	for (int row = UP; row <= DOWN; ++row)
	{
		for (int col = RIGHT; col <= LEFT; col++)
		{
			if ((i + col) >= 0 && (i + col) < GRAPH_SIZE && (j + row) >= 0 && (j + row) < GRAPH_SIZE)
			{
				if ((i % 2 == 0 && col != IN_PLACE && row == DOWN) || 
					(i % 2 == 1 && col != IN_PLACE && row == UP) || 
					 row == IN_PLACE && col == IN_PLACE)
					continue;
				else
					m_tiles[i][j].addNeighbor(&m_tiles[i + col][j + row]);
			}
				
		}
	}
}

bool Board::handleClick(const sf::Vector2f pos)
{
	for (auto& row : m_tiles)
	{
		for (auto& tile : row)
		{
			if (tile.contain(pos) && !tile.isClicked())
			{
				m_clickedTiles.push_back(&tile);
				tile.tileClicked();
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

	for (auto& row : m_tiles)
	{
		for (auto& tile : row)
		{
			tile.setVisited(false);
			tile.setDistance(INT_MAX);
			tile.setPred(NULL);
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

		for (auto& neighbor : neighbors)
		{
			if (!neighbor->alreadyVisited() && !neighbor->isClicked())
			{
				neighbor->setVisited(true);
				neighbor->setDistance(u->getDistance() + 1);
				neighbor->setPred(u);
				queue.push(neighbor);

				// We stop BFS when we find destination.
				if (neighbor == &m_target)
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
			return true;
			
		}
	}

	std::vector<Tile*> path;
	Tile* step = &m_target;
	path.push_back(step);

	while (step->getPred()->getPred())
	{
		path.push_back(step->getPred());
		step = step->getPred();
	}

	src = step;
	return true;
}

bool Board::catCircled(Tile* src)
{
	for (auto& cat : src->getNeighborList())
	{
		if (!cat->isClicked())
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