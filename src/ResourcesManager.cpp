#include "ResourcesManager.h"
#include <fstream>
#include <iostream>

ResourcesManager::ResourcesManager()
{	
	if (!m_font.loadFromFile("resources/FONT.ttf")||
		!m_catTexture.loadFromFile("resources/cat.png")||
		!m_winTexture.loadFromFile("resources/win.png")||
		!m_loseTexture.loadFromFile("resources/lose.png")||
		!m_button.loadFromFile("resources/button.png")||
		!m_background.loadFromFile("resources/background.png")||
		!m_soundBuffer.loadFromFile("resources/jump.wav"))
		exit(EXIT_FAILURE);

	m_Sound.setBuffer(m_soundBuffer);
	m_Sound.setVolume(5);
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

const sf::Texture* ResourcesManager::getButton() const
{
	return &m_button;
}

const sf::Texture* ResourcesManager::getBackground() const
{
	return &m_background;
}

void ResourcesManager::playSound()
{
	m_Sound.play();
}

const sf::SoundBuffer* ResourcesManager::getSoundBuffer() const
{
	return &(m_soundBuffer);
}
