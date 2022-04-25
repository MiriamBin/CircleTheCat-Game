#include "ResourcesManager.h"
#include <fstream>
#include <iostream>

ResourcesManager::ResourcesManager()
{
	if (!m_font.loadFromFile("resources/COMIC.ttf"))
		exit(EXIT_FAILURE);
	
	if (!m_catTexture.loadFromFile("resources/cat.png"))
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
