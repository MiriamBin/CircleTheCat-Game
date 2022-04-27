#include "ResourcesManager.h"
#include <fstream>
#include <iostream>

ResourcesManager::ResourcesManager()
{	
	if (!m_font.loadFromFile("resources/FONT.ttf")||
		!m_catTexture.loadFromFile("resources/cat.png")||
		!m_winTexture.loadFromFile("resources/win.png")||
		!m_loseTexture.loadFromFile("resources/lose.png"))
		exit(EXIT_FAILURE);
}

ResourcesManager& ResourcesManager::instance()
{
	static ResourcesManager inst;
	return inst;
}

const sf::Font* ResourcesManager::getFont() const
{
	return &m_font;
}

const sf::Texture* ResourcesManager::getCatIcon() const
{
	return &m_catTexture;
}

const sf::Texture* ResourcesManager::getWinImg() const
{
	return &m_winTexture;
}

const sf::Texture* ResourcesManager::getLoseImg() const
{
	return &m_loseTexture;
}